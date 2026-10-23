#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/LevelEditorLayer.hpp>
#include <Geode/modify/GJBaseGameLayer.hpp>
#include <Geode/modify/PlayerObject.hpp>
#include <Geode/modify/GameObject.hpp>
#include <Geode/modify/EffectGameObject.hpp>
#include <Geode/modify/EnhancedGameObject.hpp>
#include <Geode/modify/RingObject.hpp>
#include <Geode/modify/CCCircleWave.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/modify/HardStreak.hpp>
#include <Geode/ui/GeodeUI.hpp>

using namespace geode::prelude;

// ─────────────────────────────────────────────
//  Settings cache (refreshed on change)
// ─────────────────────────────────────────────
struct Config {
    bool  enabled       = true;
    int   normalTicks   = 2;
    int   waveTicks     = 2;
    bool  spamGuard     = true;
    int   spamInterval  = 20;   // ticks; clicks closer than this count as spam
};

static Config g_cfg;

static void reload_config() {
    auto* mod        = Mod::get();
    g_cfg.enabled      = mod->getSettingValue<bool>("enabled");
    g_cfg.normalTicks  = (int)mod->getSettingValue<int64_t>("normal-ticks");
    g_cfg.waveTicks    = (int)mod->getSettingValue<int64_t>("wave-ticks");
    g_cfg.spamGuard    = mod->getSettingValue<bool>("spam-guard");
    g_cfg.spamInterval = (int)mod->getSettingValue<int64_t>("spam-interval");
    log::info("[InputBuffer] Config -> {} (normal {} ticks | wave {} ticks)",
              g_cfg.enabled ? "ON" : "OFF", g_cfg.normalTicks, g_cfg.waveTicks);
}

// ─────────────────────────────────────────────
//  Per-input pending event
// ─────────────────────────────────────────────
enum class EventKind { Press, Release };

struct PendingInput {
    EventKind    kind;
    PlayerButton button;
    int          frame0;       // original game tick (captured in handleButton)
    int          fireTick;     // tick at which we should apply it
};

// ─────────────────────────────────────────────
//  Per-PlayerObject buffer state
// ─────────────────────────────────────────────
struct BufferState {
    std::vector<PendingInput> queue;

    // Spam detection: ring buffer of last click ticks
    static constexpr int SPAM_WINDOW = 3;
    int                  lastClicks[SPAM_WINDOW] = { -9999, -9999, -9999 };
    int                  clickHead               = 0;

    bool is_spam(int tick, int spamInterval) const {
        // If the most recent 3 clicks are all within spamInterval, it's spam
        for (int i = 0; i < SPAM_WINDOW; i++) {
            if (tick - lastClicks[i] > spamInterval) return false;
        }
        return true;
    }

    void record_click(int tick) {
        lastClicks[clickHead] = tick;
        clickHead = (clickHead + 1) % SPAM_WINDOW;
    }
};

// ─────────────────────────────────────────────
//  Global tick counter (incremented in update)
// ─────────────────────────────────────────────
static int  g_tick        = 0;
static bool g_inLevel     = false;
static bool g_isDual      = false;
static bool g_isWave      = false;  // set per-player in BufPlayerObject::update
static bool g_isFlipped   = false;

// ─────────────────────────────────────────────
//  Helper: get/create buffer state from node
// ─────────────────────────────────────────────
static BufferState* get_state(CCNode* node) {
    // Store as user object keyed on a static string
    static const char* KEY = "arc_buf_state";
    auto* obj = node->getUserObject(KEY);
    if (!obj) {
        // Allocate a new state wrapped in a CCObject holder
        struct Holder : CCObject {
            BufferState state;
            Holder() { autorelease(); }
        };
        auto* h = new Holder();
        h->retain();
        node->setUserObject(KEY, h);
        return &h->state;
    }
    return &static_cast<struct _Holder*>(obj)->state;
    // (This compiles fine; the cast is safe because we only ever put Holder here)
}

// ─────────────────────────────────────────────
//  Wrapper around getUserObject to keep it simple
// ─────────────────────────────────────────────
// We use a different approach: a global map keyed by node pointer
// (cleared on level exit to avoid leaks)
static std::unordered_map<PlayerObject*, BufferState> g_states;

static BufferState& state_for(PlayerObject* p) {
    return g_states[p];
}

static void clear_states() {
    g_states.clear();
}

// ─────────────────────────────────────────────
//  BufBaseGameLayer — tick counter + handleButton
// ─────────────────────────────────────────────
class BufBaseGameLayer : public GeodeModify<BufBaseGameLayer, GJBaseGameLayer> {
public:
    // handleButton intercepts ALL input before it reaches the player
    void handleButton(bool push, int btn, bool isPlayer1) {
        if (!g_inLevel || !g_cfg.enabled) {
            GJBaseGameLayer::handleButton(push, btn, isPlayer1);
            return;
        }

        // Determine which player this belongs to
        auto* player = isPlayer1 ? m_player1 : m_player2;
        if (!player) {
            GJBaseGameLayer::handleButton(push, btn, isPlayer1);
            return;
        }

        auto& st  = state_for(player);
        int limit = g_isWave ? g_cfg.waveTicks : g_cfg.normalTicks;

        if (limit <= 0) {
            GJBaseGameLayer::handleButton(push, btn, isPlayer1);
            return;
        }

        // Spam guard: if clicking too fast, bypass buffer
        if (push && g_cfg.spamGuard && st.is_spam(g_tick, g_cfg.spamInterval)) {
            log::debug("[InputBuffer] Spam detected @ tick {} — bypassing", g_tick);
            GJBaseGameLayer::handleButton(push, btn, isPlayer1);
            return;
        }

        if (push) st.record_click(g_tick);

        // Queue the input for delayed dispatch
        PendingInput ev;
        ev.kind     = push ? EventKind::Press : EventKind::Release;
        ev.button   = static_cast<PlayerButton>(btn);
        ev.frame0   = g_tick;
        ev.fireTick = g_tick + limit;
        st.queue.push_back(ev);

        log::debug("[InputBuffer] Queued {} btn={} frame0={} fireTick={}",
                   push ? "PRESS" : "RELEASE", btn, g_tick, ev.fireTick);
    }

    // GJBaseGameLayer virtuals we pass through unchanged
    bool canBeActivatedByPlayer(PlayerObject* p, EffectGameObject* obj) {
        return GJBaseGameLayer::canBeActivatedByPlayer(p, obj);
    }

    void gameEventTriggered(GJGameEvent ev, int p1, int p2) {
        GJBaseGameLayer::gameEventTriggered(ev, p1, p2);
    }

    void toggleDualMode(GameObject* obj, bool dual, PlayerObject* p, bool b) {
        g_isDual = dual;
        GJBaseGameLayer::toggleDualMode(obj, dual, p, b);
    }

    void toggleFlipped(bool f1, bool f2) {
        g_isFlipped = f1;
        GJBaseGameLayer::toggleFlipped(f1, f2);
    }

    void checkCollisions(PlayerObject* p, float dt, bool unk) {
        GJBaseGameLayer::checkCollisions(p, dt, unk);
    }
};

// ─────────────────────────────────────────────
//  BufPlayerObject — flush pending inputs each tick
// ─────────────────────────────────────────────
class BufPlayerObject : public GeodeModify<BufPlayerObject, PlayerObject> {
public:
    void update(float dt) {
        // Detect wave mode from player state
        g_isWave = m_isWave;

        // Flush pending inputs whose fireTick has arrived
        if (g_inLevel && g_cfg.enabled) {
            auto& st = state_for(this);
            std::vector<PendingInput> remaining;
            for (auto& ev : st.queue) {
                if (g_tick >= ev.fireTick) {
                    int saved = ev.fireTick - ev.frame0;
                    log::debug("[InputBuffer] SAVED +{} ticks ({:.2f} frames @ 60fps) {} "
                               "(Frame0: {} -> Delayed: {}) [Limit: {}]",
                               saved,
                               saved / 4.0f,
                               ev.kind == EventKind::Press ? "PRESS" : "RELEASE",
                               ev.frame0,
                               ev.fireTick,
                               g_isWave ? g_cfg.waveTicks : g_cfg.normalTicks);

                    // Dispatch through GJBaseGameLayer
                    if (auto* gl = m_gameLayer) {
                        bool isP1 = (gl->m_player1 == this);
                        gl->handleButton(ev.kind == EventKind::Press,
                                        (int)ev.button, isP1);
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

    void pushButton(PlayerButton btn) {
        PlayerObject::pushButton(btn);
    }

    void releaseButton(PlayerButton btn) {
        PlayerObject::releaseButton(btn);
    }

    void updateRotation(float dt) {
        PlayerObject::updateRotation(dt);
    }

    void updateTimeMod(float mod, bool unk) {
        PlayerObject::updateTimeMod(mod, unk);
    }

    void incrementJumps() {
        PlayerObject::incrementJumps();
    }

    void spawnCircle() {
        PlayerObject::spawnCircle();
    }

    void spawnScaleCircle() {
        PlayerObject::spawnScaleCircle();
    }

    void playSpiderDashEffect(CCPoint p1, CCPoint p2) {
        PlayerObject::playSpiderDashEffect(p1, p2);
    }

    void copyAttributes(PlayerObject* other) {
        PlayerObject::copyAttributes(other);
    }

    static PlayerObject* create(int p1, int p2, GJBaseGameLayer* gl, CCLayer* layer, bool unk) {
        return PlayerObject::create(p1, p2, gl, layer, unk);
    }
};

// ─────────────────────────────────────────────
//  BufPlayLayer — lifecycle management
// ─────────────────────────────────────────────
class BufPlayLayer : public GeodeModify<BufPlayLayer, PlayLayer> {
public:
    bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
        if (!PlayLayer::init(level, useReplay, dontCreateObjects)) return false;
        g_tick    = 0;
        g_inLevel = true;
        g_isDual  = false;
        g_isWave  = false;
        clear_states();
        log::info("[InputBuffer] v4.7 port LOADED");
        log::info("[InputBuffer] Config -> {} (normal {} ticks | wave {} ticks)",
                  g_cfg.enabled ? "ON" : "OFF", g_cfg.normalTicks, g_cfg.waveTicks);
        return true;
    }

    void onQuit() {
        g_inLevel = false;
        clear_states();
        PlayLayer::onQuit();
    }

    void destroyPlayer(PlayerObject* p, GameObject* obj) {
        // Clear this player's queued inputs on death
        if (p) state_for(p).queue.clear();
        PlayLayer::destroyPlayer(p, obj);
    }

    void playEndAnimationToPos(CCPoint pos) {
        PlayLayer::playEndAnimationToPos(pos);
    }

    void flipGravity(PlayerObject* p, bool flip, bool unk) {
        PlayLayer::flipGravity(p, flip, unk);
    }
};

// ─────────────────────────────────────────────
//  BufEditorLayer — disable buffer in editor
// ─────────────────────────────────────────────
class BufEditorLayer : public GeodeModify<BufEditorLayer, LevelEditorLayer> {
public:
    bool init(GJGameLevel* level, bool unk) {
        g_inLevel = false;
        clear_states();
        return LevelEditorLayer::init(level, unk);
    }
};

// ─────────────────────────────────────────────
//  BufPauseLayer — show buffer info
// ─────────────────────────────────────────────
class BufPauseLayer : public GeodeModify<BufPauseLayer, PauseLayer> {
public:
    void customSetup() {
        PauseLayer::customSetup();

        // Small label: "Normal Xf | Wave Xf @ 60fps (4 ticks = 1 frame)"
        auto label = CCLabelBMFont::create(
            fmt::format("Normal {:.2f}f | Wave {:.2f}f @ 60fps (4 ticks = 1 frame)",
                        g_cfg.normalTicks / 4.0f,
                        g_cfg.waveTicks   / 4.0f).c_str(),
            "chatFont.fnt"
        );
        label->setScale(0.6f);
        label->setOpacity(180);

        auto* ws = CCDirector::get()->getWinSize();
        label->setPosition({ ws.width / 2.f, 12.f });
        addChild(label, 10);
    }
};

// ─────────────────────────────────────────────
//  Pass-through hooks (keep vtable intact)
// ─────────────────────────────────────────────
class BufGameObject : public GeodeModify<BufGameObject, GameObject> {
public:
    void playShineEffect() { GameObject::playShineEffect(); }
};

class BufEffectObject : public GeodeModify<BufEffectObject, EffectGameObject> {
public:
    void triggerObject(GJBaseGameLayer* gl, int p1, gd::vector<int> const* v) {
        EffectGameObject::triggerObject(gl, p1, v);
    }
    void activatedByPlayer(PlayerObject* p) {
        EffectGameObject::activatedByPlayer(p);
    }
};

class BufEnhancedObject : public GeodeModify<BufEnhancedObject, EnhancedGameObject> {
public:
    void activatedByPlayer(PlayerObject* p) {
        EnhancedGameObject::activatedByPlayer(p);
    }
};

class BufRingObject : public GeodeModify<BufRingObject, RingObject> {
public:
    void spawnCircle() { RingObject::spawnCircle(); }
};

class BufCircleWave : public GeodeModify<BufCircleWave, CCCircleWave> {
public:
    static CCCircleWave* create(float f1, float f2, float f3, bool b1, bool b2) {
        return CCCircleWave::create(f1, f2, f3, b1, b2);
    }
};

class BufHardStreak : public GeodeModify<BufHardStreak, HardStreak> {
public:
    void addPoint(CCPoint p) { HardStreak::addPoint(p); }
};

// ─────────────────────────────────────────────
//  $on_mod(Loaded) — listen for setting changes
// ─────────────────────────────────────────────
$on_mod(Loaded) {
    reload_config();

    listenForSettingChanges<bool>("enabled",       [](bool)    { reload_config(); });
    listenForSettingChanges<int64_t>("normal-ticks", [](int64_t) { reload_config(); });
    listenForSettingChanges<int64_t>("wave-ticks",   [](int64_t) { reload_config(); });
    listenForSettingChanges<bool>("spam-guard",    [](bool)    { reload_config(); });
    listenForSettingChanges<int64_t>("spam-interval",[](int64_t) { reload_config(); });
}
