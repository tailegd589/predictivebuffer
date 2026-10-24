#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/LevelEditorLayer.hpp>
#include <Geode/modify/GJBaseGameLayer.hpp>
#include <Geode/modify/PlayerObject.hpp>
#include <Geode/modify/PauseLayer.hpp>

using namespace geode::prelude;

struct Config {
    bool enabled = true; int normalTicks = 2; int waveTicks = 2;
    bool spamGuard = true; int spamInterval = 20;
};
static Config g_cfg;

static void reload_config() {
    auto* m = Mod::get();
    g_cfg.enabled      = m->getSettingValue<bool>("enabled");
    g_cfg.normalTicks  = (int)m->getSettingValue<int64_t>("normal-ticks");
    g_cfg.waveTicks    = (int)m->getSettingValue<int64_t>("wave-ticks");
    g_cfg.spamGuard    = m->getSettingValue<bool>("spam-guard");
    g_cfg.spamInterval = (int)m->getSettingValue<int64_t>("spam-interval");
    log::info("[InputBuffer] Config -> {} (normal {} | wave {} ticks)",
              g_cfg.enabled?"ON":"OFF", g_cfg.normalTicks, g_cfg.waveTicks);
}

enum class EventKind { Press, Release };
struct PendingInput {
    EventKind kind; PlayerButton button;
    int frame0; int fireTick; bool isPlayer1;
};
struct BufferState {
    std::vector<PendingInput> queue;
    static constexpr int W = 3;
    int lastClicks[W] = {-9999,-9999,-9999}; int head = 0;
    bool isWave = false;
    bool is_spam(int t, int iv) const {
        for (int i = 0; i < W; i++) if (t - lastClicks[i] > iv) return false;
        return true;
    }
    void record(int t) { lastClicks[head] = t; head = (head+1) % W; }
};

static std::unordered_map<uintptr_t, BufferState> g_states;
static int  g_tick        = 0;
static bool g_inLevel     = false;
// FIX: prevent dispatch loop — when we fire a queued input,
// handleButton must pass it straight to the original
static bool g_dispatching = false;

static BufferState& bst(PlayerObject* p) {
    return g_states[reinterpret_cast<uintptr_t>(p)];
}
static void clear_states() { g_states.clear(); }

struct BufBaseGameLayer : geode::Modify<BufBaseGameLayer, GJBaseGameLayer> {
    void handleButton(bool push, int btn, bool isP1) {
        // Always pass through when dispatching from queue
        if (g_dispatching || !g_inLevel || !g_cfg.enabled) {
            GJBaseGameLayer::handleButton(push, btn, isP1);
            return;
        }
        auto* p = isP1 ? m_player1 : m_player2;
        if (!p) { GJBaseGameLayer::handleButton(push, btn, isP1); return; }

        auto& s  = bst(p);
        int  lim = s.isWave ? g_cfg.waveTicks : g_cfg.normalTicks;

        if (lim <= 0) { GJBaseGameLayer::handleButton(push, btn, isP1); return; }

        if (push && g_cfg.spamGuard && s.is_spam(g_tick, g_cfg.spamInterval)) {
            GJBaseGameLayer::handleButton(push, btn, isP1);
            return;
        }
        if (push) s.record(g_tick);
        s.queue.push_back({
            push ? EventKind::Press : EventKind::Release,
            static_cast<PlayerButton>(btn),
            g_tick, g_tick + lim, isP1
        });
    }
};

struct BufPlayerObject : geode::Modify<BufPlayerObject, PlayerObject> {
    void update(float dt) {
        if (g_inLevel && g_cfg.enabled) {
            auto& s = bst(this);
            std::vector<PendingInput> rem;
            for (auto& ev : s.queue) {
                if (g_tick >= ev.fireTick) {
                    if (auto* gl = m_gameLayer) {
                        log::debug("[InputBuffer] FIRE +{} ticks {}",
                                   ev.fireTick - ev.frame0,
                                   ev.kind == EventKind::Press ? "PRESS" : "RELEASE");
                        // Set flag so handleButton passes straight through
                        g_dispatching = true;
                        gl->handleButton(ev.kind == EventKind::Press,
                                         (int)ev.button, ev.isPlayer1);
                        g_dispatching = false;
                    }
                } else {
                    rem.push_back(ev);
                }
            }
            s.queue = std::move(rem);
        }
        PlayerObject::update(dt);
        // Only increment tick for player1 to avoid double-tick in dual mode
        if (this == (m_gameLayer ? m_gameLayer->m_player1 : nullptr)) {
            g_tick++;
        }
    }
};

struct BufPlayLayer : geode::Modify<BufPlayLayer, PlayLayer> {
    bool init(GJGameLevel* level, bool r, bool d) {
        if (!PlayLayer::init(level, r, d)) return false;
        g_tick = 0; g_inLevel = true; g_dispatching = false;
        clear_states();
        log::info("[InputBuffer] v4.7 iOS LOADED");
        return true;
    }
    void onQuit() {
        g_inLevel = false; g_dispatching = false;
        clear_states();
        PlayLayer::onQuit();
    }
    void destroyPlayer(PlayerObject* p, GameObject* o) {
        if (p) bst(p).queue.clear();
        PlayLayer::destroyPlayer(p, o);
    }
};

struct BufEditorLayer : geode::Modify<BufEditorLayer, LevelEditorLayer> {
    bool init(GJGameLevel* level, bool u) {
        g_inLevel = false; clear_states();
        return LevelEditorLayer::init(level, u);
    }
};

struct BufPauseLayer : geode::Modify<BufPauseLayer, PauseLayer> {
    void customSetup() {
        PauseLayer::customSetup();
        auto* lbl = CCLabelBMFont::create(
            fmt::format("Buffer: {:.2f}f | wave {:.2f}f",
                        g_cfg.normalTicks / 4.f,
                        g_cfg.waveTicks   / 4.f).c_str(),
            "chatFont.fnt");
        lbl->setScale(0.6f); lbl->setOpacity(180);
        auto ws = CCDirector::get()->getWinSize();
        lbl->setPosition({ws.width / 2.f, 12.f});
        addChild(lbl, 10);
    }
};

$on_mod(Loaded) {
    reload_config();
    listenForSettingChanges<bool>   ("enabled",      [](bool)   { reload_config(); });
    listenForSettingChanges<int64_t>("normal-ticks", [](int64_t){ reload_config(); });
    listenForSettingChanges<int64_t>("wave-ticks",   [](int64_t){ reload_config(); });
    listenForSettingChanges<bool>   ("spam-guard",   [](bool)   { reload_config(); });
    listenForSettingChanges<int64_t>("spam-interval",[](int64_t){ reload_config(); });
}
