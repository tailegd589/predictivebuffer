#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/LevelEditorLayer.hpp>
#include <Geode/modify/GJBaseGameLayer.hpp>
#include <Geode/modify/PlayerObject.hpp>
#include <Geode/modify/PauseLayer.hpp>

using namespace geode::prelude;

// ── Config ────────────────────────────────────────────────────────────────────
struct Config {
    bool enabled      = true;
    int  normalTicks  = 2;
    int  waveTicks    = 2;
    bool spamGuard    = true;
    int  spamInterval = 20;
};
static Config g_cfg;

static void reload_config() {
    auto* mod = Mod::get();
    g_cfg.enabled      = mod->getSettingValue<bool>("enabled");
    g_cfg.normalTicks  = (int)mod->getSettingValue<int64_t>("normal-ticks");
    g_cfg.waveTicks    = (int)mod->getSettingValue<int64_t>("wave-ticks");
    g_cfg.spamGuard    = mod->getSettingValue<bool>("spam-guard");
    g_cfg.spamInterval = (int)mod->getSettingValue<int64_t>("spam-interval");
    log::info("[InputBuffer] Config -> {} (normal {} ticks | wave {} ticks)",
              g_cfg.enabled ? "ON" : "OFF", g_cfg.normalTicks, g_cfg.waveTicks);
}

// ── Pending input ─────────────────────────────────────────────────────────────
enum class EventKind { Press, Release };
struct PendingInput {
    EventKind    kind;
    PlayerButton button;
    int          frame0;
    int          fireTick;
    bool         isPlayer1;
    bool         wasWave;
};

// ── Buffer state per player ───────────────────────────────────────────────────
struct BufferState {
    std::vector<PendingInput> queue;
    static constexpr int SPAM_WINDOW = 3;
    int lastClicks[SPAM_WINDOW] = { -9999, -9999, -9999 };
    int clickHead = 0;
    bool isWave = false;   // tracked by PlayerObject::update

    bool is_spam(int tick, int interval) const {
        for (int i = 0; i < SPAM_WINDOW; i++)
            if (tick - lastClicks[i] > interval) return false;
        return true;
    }
    void record_click(int tick) {
        lastClicks[clickHead] = tick;
        clickHead = (clickHead + 1) % SPAM_WINDOW;
    }
};

static std::unordered_map<uintptr_t, BufferState> g_states;
static int  g_tick    = 0;
static bool g_inLevel = false;

static uintptr_t key(PlayerObject* p) { return reinterpret_cast<uintptr_t>(p); }
static BufferState& state_for(PlayerObject* p) { return g_states[key(p)]; }
static void clear_states() { g_states.clear(); }

// ── GJBaseGameLayer hook ───────────────────────────────────────────────────────
struct BufBaseGameLayer : geode::Modify<BufBaseGameLayer, GJBaseGameLayer> {
    void handleButton(bool push, int btn, bool isPlayer1) {
        if (!g_inLevel || !g_cfg.enabled) {
            GJBaseGameLayer::handleButton(push, btn, isPlayer1);
            return;
        }
        auto* player = isPlayer1 ? m_player1 : m_player2;
        if (!player) {
            GJBaseGameLayer::handleButton(push, btn, isPlayer1);
            return;
        }
        auto& st  = state_for(player);
        int limit = st.isWave ? g_cfg.waveTicks : g_cfg.normalTicks;

        if (limit <= 0) {
            GJBaseGameLayer::handleButton(push, btn, isPlayer1);
            return;
        }
        if (push && g_cfg.spamGuard && st.is_spam(g_tick, g_cfg.spamInterval)) {
            GJBaseGameLayer::handleButton(push, btn, isPlayer1);
            return;
        }
        if (push) st.record_click(g_tick);
        st.queue.push_back({
            push ? EventKind::Press : EventKind::Release,
            static_cast<PlayerButton>(btn),
            g_tick, g_tick + limit,
            isPlayer1, st.isWave
        });
    }
};

// ── PlayerObject hook ─────────────────────────────────────────────────────────
struct BufPlayerObject : geode::Modify<BufPlayerObject, PlayerObject> {
    void update(float dt) {
        // Track wave state here to avoid m_isWave field dependency
        if (g_inLevel) {
            auto& st  = state_for(this);
            // Use GameObjectType to detect wave: type 7 = wave
            st.isWave = (m_objectType == GameObjectType::Swing) ||
                        (m_objectType == GameObjectType::Wave);

            std::vector<PendingInput> remaining;
            for (auto& ev : st.queue) {
                if (g_tick >= ev.fireTick) {
                    if (auto* gl = m_gameLayer) {
                        log::debug("[InputBuffer] SAVED +{} ticks {}", 
                                   ev.fireTick - ev.frame0,
                                   ev.kind == EventKind::Press ? "PRESS" : "RELEASE");
                        gl->handleButton(ev.kind == EventKind::Press,
                                         (int)ev.button, ev.isPlayer1);
                    }
                } else {
                    remaining.push_back(ev);
                }
            }
            st.queue = std::move(remaining);
        }
        PlayerObject::update(dt);
        g_tick++;
    }
};

// ── PlayLayer hook ────────────────────────────────────────────────────────────
struct BufPlayLayer : geode::Modify<BufPlayLayer, PlayLayer> {
    bool init(GJGameLevel* level, bool useReplay, bool dontCreate) {
        if (!PlayLayer::init(level, useReplay, dontCreate)) return false;
        g_tick = 0; g_inLevel = true; clear_states();
        log::info("[InputBuffer] v4.7 port LOADED");
        return true;
    }
    void onQuit() {
        g_inLevel = false; clear_states();
        PlayLayer::onQuit();
    }
    void destroyPlayer(PlayerObject* p, GameObject* obj) {
        if (p) state_for(p).queue.clear();
        PlayLayer::destroyPlayer(p, obj);
    }
};

// ── LevelEditorLayer hook ─────────────────────────────────────────────────────
struct BufEditorLayer : geode::Modify<BufEditorLayer, LevelEditorLayer> {
    bool init(GJGameLevel* level, bool unk) {
        g_inLevel = false; clear_states();
        return LevelEditorLayer::init(level, unk);
    }
};

// ── PauseLayer hook ───────────────────────────────────────────────────────────
struct BufPauseLayer : geode::Modify<BufPauseLayer, PauseLayer> {
    void customSetup() {
        PauseLayer::customSetup();
        auto* lbl = CCLabelBMFont::create(
            fmt::format("Buffer: normal {:.2f}f | wave {:.2f}f",
                        g_cfg.normalTicks / 4.0f,
                        g_cfg.waveTicks   / 4.0f).c_str(),
            "chatFont.fnt");
        lbl->setScale(0.6f); lbl->setOpacity(180);
        auto ws = CCDirector::get()->getWinSize();
        lbl->setPosition({ ws.width / 2.f, 12.f });
        addChild(lbl, 10);
    }
};

// ── on_mod ────────────────────────────────────────────────────────────────────
$on_mod(Loaded) {
    reload_config();
    listenForSettingChanges<bool>   ("enabled",       [](bool)    { reload_config(); });
    listenForSettingChanges<int64_t>("normal-ticks",  [](int64_t) { reload_config(); });
    listenForSettingChanges<int64_t>("wave-ticks",    [](int64_t) { reload_config(); });
    listenForSettingChanges<bool>   ("spam-guard",    [](bool)    { reload_config(); });
    listenForSettingChanges<int64_t>("spam-interval", [](int64_t) { reload_config(); });
}
