
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GJBaseGameLayer.hpp>
#include <Geode/cocos/platform/mac/CCFileUtilsMac.h>

using namespace geode;
using namespace geode::modifier;

#if !defined(GEODE_WRAP_FUNCTION)
#define GEODE_WRAP_FUNCTION
template <class F>
static auto wrapFunction(uintptr_t address, tulip::hook::TulipConvention convention) {
	auto wrapped = geode::hook::createWrapper(reinterpret_cast<void*>(address), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(convention),
		.m_abstract = tulip::hook::AbstractFunction::from(F(nullptr)),
	});
	if (wrapped.isErr()) {
		throw std::runtime_error(wrapped.unwrapErr());
	}
	return wrapped.unwrap();
}
#endif

GJBaseGameLayer::GJBaseGameLayer() : GJBaseGameLayer(geode::CutoffConstructor, sizeof(GJBaseGameLayer)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	GJBaseGameLayer::~GJBaseGameLayer();

	using FunctionType = void(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xac9f4, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

GJBaseGameLayer::~GJBaseGameLayer() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(GJBaseGameLayer*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0xea680, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) GJBaseGameLayer(geode::CutoffConstructor, sizeof(GJBaseGameLayer));
		geode::DestructorLock::addLock(this);
	}
}

auto GJBaseGameLayer::convertToClosestDirection(float angle, float bound) -> decltype(convertToClosestDirection(angle, bound)) {
	using FunctionType = decltype(convertToClosestDirection(angle, bound))(*)(float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x10d79c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(angle, bound);
}

auto GJBaseGameLayer::gameEventToString(GJGameEvent event) -> decltype(gameEventToString(event)) {
	using FunctionType = decltype(gameEventToString(event))(*)(GJGameEvent);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11dec0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(event);
}

auto GJBaseGameLayer::update(float dt) -> decltype(update(dt)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&GJBaseGameLayer::update), this);
	using FunctionType = decltype(update(dt))(*)(GJBaseGameLayer*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1229e8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, dt);
}

auto GJBaseGameLayer::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJBaseGameLayer::init), this);
	using FunctionType = decltype(init())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xeb374, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJBaseGameLayer::visit() -> decltype(visit()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJBaseGameLayer::visit), this);
	using FunctionType = decltype(visit())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x131340, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJBaseGameLayer::opacityForObject(GameObject* object) -> decltype(opacityForObject(object)) {
	auto self = addresser::thunkAdjust(Resolve<GameObject*>::func(&GJBaseGameLayer::opacityForObject), this);
	using FunctionType = decltype(opacityForObject(object))(*)(GJBaseGameLayer*, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1227e8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, object);
}

auto GJBaseGameLayer::objectsCollided(int blockAID, int blockBID) -> decltype(objectsCollided(blockAID, blockBID)) {
	auto self = addresser::thunkAdjust(Resolve<int, int>::func(&GJBaseGameLayer::objectsCollided), this);
	using FunctionType = decltype(objectsCollided(blockAID, blockBID))(*)(GJBaseGameLayer*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1038ec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, blockAID, blockBID);
}

auto GJBaseGameLayer::updateColor(cocos2d::ccColor3B& color, float fadeTime, int colorID, bool blending, float opacity, cocos2d::ccHSVValue& copyHSV, int colorIDToCopy, bool copyOpacity, EffectGameObject* callerObject, int unk1, int unk2) -> decltype(updateColor(color, fadeTime, colorID, blending, opacity, copyHSV, colorIDToCopy, copyOpacity, callerObject, unk1, unk2)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::ccColor3B&, float, int, bool, float, cocos2d::ccHSVValue&, int, bool, EffectGameObject*, int, int>::func(&GJBaseGameLayer::updateColor), this);
	using FunctionType = decltype(updateColor(color, fadeTime, colorID, blending, opacity, copyHSV, colorIDToCopy, copyOpacity, callerObject, unk1, unk2))(*)(GJBaseGameLayer*, cocos2d::ccColor3B&, float, int, bool, float, cocos2d::ccHSVValue&, int, bool, EffectGameObject*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x111634, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, color, fadeTime, colorID, blending, opacity, copyHSV, colorIDToCopy, copyOpacity, callerObject, unk1, unk2);
}

auto GJBaseGameLayer::toggleGroupTriggered(int group, bool activate, gd::vector<int> const& remapKeys, int triggerID, int controlID) -> decltype(toggleGroupTriggered(group, activate, remapKeys, triggerID, controlID)) {
	auto self = addresser::thunkAdjust(Resolve<int, bool, gd::vector<int> const&, int, int>::func(&GJBaseGameLayer::toggleGroupTriggered), this);
	using FunctionType = decltype(toggleGroupTriggered(group, activate, remapKeys, triggerID, controlID))(*)(GJBaseGameLayer*, int, bool, gd::vector<int> const&, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11179c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, group, activate, remapKeys, triggerID, controlID);
}

auto GJBaseGameLayer::spawnGroup(int group, bool ordered, double delay, gd::vector<int> const& remapKeys, int triggerID, int controlID) -> decltype(spawnGroup(group, ordered, delay, remapKeys, triggerID, controlID)) {
	auto self = addresser::thunkAdjust(Resolve<int, bool, double, gd::vector<int> const&, int, int>::func(&GJBaseGameLayer::spawnGroup), this);
	using FunctionType = decltype(spawnGroup(group, ordered, delay, remapKeys, triggerID, controlID))(*)(GJBaseGameLayer*, int, bool, double, gd::vector<int> const&, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x104924, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, group, ordered, delay, remapKeys, triggerID, controlID);
}

auto GJBaseGameLayer::spawnObject(GameObject* object, double delay, gd::vector<int> const& remapKeys) -> decltype(spawnObject(object, delay, remapKeys)) {
	auto self = addresser::thunkAdjust(Resolve<GameObject*, double, gd::vector<int> const&>::func(&GJBaseGameLayer::spawnObject), this);
	using FunctionType = decltype(spawnObject(object, delay, remapKeys))(*)(GJBaseGameLayer*, GameObject*, double, gd::vector<int> const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x104da8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, object, delay, remapKeys);
}

auto GJBaseGameLayer::updateDebugDraw() -> decltype(updateDebugDraw()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJBaseGameLayer::updateDebugDraw), this);
	using FunctionType = decltype(updateDebugDraw())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xfa7c8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJBaseGameLayer::addToSection(GameObject* object) -> decltype(addToSection(object)) {
	auto self = addresser::thunkAdjust(Resolve<GameObject*>::func(&GJBaseGameLayer::addToSection), this);
	using FunctionType = decltype(addToSection(object))(*)(GJBaseGameLayer*, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11352c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, object);
}

auto GJBaseGameLayer::addToGroup(GameObject* object, int groupID, bool triggerGroup) -> decltype(addToGroup(object, groupID, triggerGroup)) {
	auto self = addresser::thunkAdjust(Resolve<GameObject*, int, bool>::func(&GJBaseGameLayer::addToGroup), this);
	using FunctionType = decltype(addToGroup(object, groupID, triggerGroup))(*)(GJBaseGameLayer*, GameObject*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x111cb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, object, groupID, triggerGroup);
}

auto GJBaseGameLayer::removeFromGroup(GameObject* object, int groupID) -> decltype(removeFromGroup(object, groupID)) {
	auto self = addresser::thunkAdjust(Resolve<GameObject*, int>::func(&GJBaseGameLayer::removeFromGroup), this);
	using FunctionType = decltype(removeFromGroup(object, groupID))(*)(GJBaseGameLayer*, GameObject*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x111f0c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, object, groupID);
}

auto GJBaseGameLayer::updateObjectSection(GameObject* object) -> decltype(updateObjectSection(object)) {
	auto self = addresser::thunkAdjust(Resolve<GameObject*>::func(&GJBaseGameLayer::updateObjectSection), this);
	using FunctionType = decltype(updateObjectSection(object))(*)(GJBaseGameLayer*, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x114ad0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, object);
}

auto GJBaseGameLayer::toggleGroundVisibility(bool visible) -> decltype(toggleGroundVisibility(visible)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&GJBaseGameLayer::toggleGroundVisibility), this);
	using FunctionType = decltype(toggleGroundVisibility(visible))(*)(GJBaseGameLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1209ac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, visible);
}

auto GJBaseGameLayer::toggleMGVisibility(bool visible) -> decltype(toggleMGVisibility(visible)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&GJBaseGameLayer::toggleMGVisibility), this);
	using FunctionType = decltype(toggleMGVisibility(visible))(*)(GJBaseGameLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1209b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, visible);
}

auto GJBaseGameLayer::toggleHideAttempts(bool hide) -> decltype(toggleHideAttempts(hide)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&GJBaseGameLayer::toggleHideAttempts), this);
	using FunctionType = decltype(toggleHideAttempts(hide))(*)(GJBaseGameLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1209b4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, hide);
}

auto GJBaseGameLayer::updateScreenRotation(float rotation, bool add, bool convert, float duration, int easingType, float easingRate, int uniqueID, int controlID) -> decltype(updateScreenRotation(rotation, add, convert, duration, easingType, easingRate, uniqueID, controlID)) {
	auto self = addresser::thunkAdjust(Resolve<float, bool, bool, float, int, float, int, int>::func(&GJBaseGameLayer::updateScreenRotation), this);
	using FunctionType = decltype(updateScreenRotation(rotation, add, convert, duration, easingType, easingRate, uniqueID, controlID))(*)(GJBaseGameLayer*, float, bool, bool, float, int, float, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x120af4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, rotation, add, convert, duration, easingType, easingRate, uniqueID, controlID);
}

auto GJBaseGameLayer::reverseDirection(EffectGameObject* object) -> decltype(reverseDirection(object)) {
	auto self = addresser::thunkAdjust(Resolve<EffectGameObject*>::func(&GJBaseGameLayer::reverseDirection), this);
	using FunctionType = decltype(reverseDirection(object))(*)(GJBaseGameLayer*, EffectGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x102950, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, object);
}

auto GJBaseGameLayer::rotateGameplay(RotateGameplayGameObject* object) -> decltype(rotateGameplay(object)) {
	auto self = addresser::thunkAdjust(Resolve<RotateGameplayGameObject*>::func(&GJBaseGameLayer::rotateGameplay), this);
	using FunctionType = decltype(rotateGameplay(object))(*)(GJBaseGameLayer*, RotateGameplayGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x102998, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, object);
}

auto GJBaseGameLayer::updateTimeWarp(float timeWarp) -> decltype(updateTimeWarp(timeWarp)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&GJBaseGameLayer::updateTimeWarp), this);
	using FunctionType = decltype(updateTimeWarp(timeWarp))(*)(GJBaseGameLayer*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x12110c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, timeWarp);
}

auto GJBaseGameLayer::applyTimeWarp(float timeWarp) -> decltype(applyTimeWarp(timeWarp)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&GJBaseGameLayer::applyTimeWarp), this);
	using FunctionType = decltype(applyTimeWarp(timeWarp))(*)(GJBaseGameLayer*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x121150, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, timeWarp);
}

auto GJBaseGameLayer::createCustomParticle(gd::string const& key, cocos2d::ParticleStruct const& particleStruct, int minimum, bool dontAdd) -> decltype(createCustomParticle(key, particleStruct, minimum, dontAdd)) {
	auto self = addresser::thunkAdjust(Resolve<gd::string const&, cocos2d::ParticleStruct const&, int, bool>::func(&GJBaseGameLayer::createCustomParticle), this);
	using FunctionType = decltype(createCustomParticle(key, particleStruct, minimum, dontAdd))(*)(GJBaseGameLayer*, gd::string const&, cocos2d::ParticleStruct const&, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x12cc08, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, key, particleStruct, minimum, dontAdd);
}

auto GJBaseGameLayer::claimCustomParticle(gd::string const& key, cocos2d::ParticleStruct const& particleStruct, int zLayer, int zOrder, int uiObject, bool dontAdd) -> decltype(claimCustomParticle(key, particleStruct, zLayer, zOrder, uiObject, dontAdd)) {
	auto self = addresser::thunkAdjust(Resolve<gd::string const&, cocos2d::ParticleStruct const&, int, int, int, bool>::func(&GJBaseGameLayer::claimCustomParticle), this);
	using FunctionType = decltype(claimCustomParticle(key, particleStruct, zLayer, zOrder, uiObject, dontAdd))(*)(GJBaseGameLayer*, gd::string const&, cocos2d::ParticleStruct const&, int, int, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x12cf90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, key, particleStruct, zLayer, zOrder, uiObject, dontAdd);
}

auto GJBaseGameLayer::unclaimCustomParticle(gd::string const& key, cocos2d::CCParticleSystemQuad* particle) -> decltype(unclaimCustomParticle(key, particle)) {
	auto self = addresser::thunkAdjust(Resolve<gd::string const&, cocos2d::CCParticleSystemQuad*>::func(&GJBaseGameLayer::unclaimCustomParticle), this);
	using FunctionType = decltype(unclaimCustomParticle(key, particle))(*)(GJBaseGameLayer*, gd::string const&, cocos2d::CCParticleSystemQuad*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x12d1d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, key, particle);
}

auto GJBaseGameLayer::activatedAudioTrigger(SFXTriggerGameObject* object) -> decltype(activatedAudioTrigger(object)) {
	auto self = addresser::thunkAdjust(Resolve<SFXTriggerGameObject*>::func(&GJBaseGameLayer::activatedAudioTrigger), this);
	using FunctionType = decltype(activatedAudioTrigger(object))(*)(GJBaseGameLayer*, SFXTriggerGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x12df0c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, object);
}

auto GJBaseGameLayer::checkpointActivated(CheckpointGameObject* object) -> decltype(checkpointActivated(object)) {
	auto self = addresser::thunkAdjust(Resolve<CheckpointGameObject*>::func(&GJBaseGameLayer::checkpointActivated), this);
	using FunctionType = decltype(checkpointActivated(object))(*)(GJBaseGameLayer*, CheckpointGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x13109c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, object);
}

auto GJBaseGameLayer::flipArt(bool flip) -> decltype(flipArt(flip)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&GJBaseGameLayer::flipArt), this);
	using FunctionType = decltype(flipArt(flip))(*)(GJBaseGameLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x131098, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, flip);
}

auto GJBaseGameLayer::addKeyframe(KeyframeGameObject* object) -> decltype(addKeyframe(object)) {
	auto self = addresser::thunkAdjust(Resolve<KeyframeGameObject*>::func(&GJBaseGameLayer::addKeyframe), this);
	using FunctionType = decltype(addKeyframe(object))(*)(GJBaseGameLayer*, KeyframeGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11e06c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, object);
}

auto GJBaseGameLayer::activateCustomRing(RingObject* object) -> decltype(activateCustomRing(object)) {
	using FunctionType = decltype(activateCustomRing(object))(*)(GJBaseGameLayer*, RingObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x10b030, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJBaseGameLayer::activatedAudioTrigger(SFXTriggerGameObject* object, float levelTime) -> decltype(activatedAudioTrigger(object, levelTime)) {
	using FunctionType = decltype(activatedAudioTrigger(object, levelTime))(*)(GJBaseGameLayer*, SFXTriggerGameObject*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x12df18, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, levelTime);
}

auto GJBaseGameLayer::activateEventTrigger(EventLinkTrigger* object, gd::vector<int> const& remapKeys) -> decltype(activateEventTrigger(object, remapKeys)) {
	using FunctionType = decltype(activateEventTrigger(object, remapKeys))(*)(GJBaseGameLayer*, EventLinkTrigger*, gd::vector<int> const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11da7c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, remapKeys);
}

auto GJBaseGameLayer::activateItemCompareTrigger(ItemTriggerGameObject* object, gd::vector<int> const& remapKeys) -> decltype(activateItemCompareTrigger(object, remapKeys)) {
	using FunctionType = decltype(activateItemCompareTrigger(object, remapKeys))(*)(GJBaseGameLayer*, ItemTriggerGameObject*, gd::vector<int> const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11f16c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, remapKeys);
}

auto GJBaseGameLayer::activateItemEditTrigger(ItemTriggerGameObject* object) -> decltype(activateItemEditTrigger(object)) {
	using FunctionType = decltype(activateItemEditTrigger(object))(*)(GJBaseGameLayer*, ItemTriggerGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11eb34, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJBaseGameLayer::activateObjectControlTrigger(ObjectControlGameObject* object) -> decltype(activateObjectControlTrigger(object)) {
	using FunctionType = decltype(activateObjectControlTrigger(object))(*)(GJBaseGameLayer*, ObjectControlGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x10216c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJBaseGameLayer::activatePersistentItemTrigger(ItemTriggerGameObject* object) -> decltype(activatePersistentItemTrigger(object)) {
	using FunctionType = decltype(activatePersistentItemTrigger(object))(*)(GJBaseGameLayer*, ItemTriggerGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11f6c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJBaseGameLayer::activatePlayerControlTrigger(PlayerControlGameObject* object) -> decltype(activatePlayerControlTrigger(object)) {
	using FunctionType = decltype(activatePlayerControlTrigger(object))(*)(GJBaseGameLayer*, PlayerControlGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x101fb8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJBaseGameLayer::activateResetTrigger(EffectGameObject* object) -> decltype(activateResetTrigger(object)) {
	using FunctionType = decltype(activateResetTrigger(object))(*)(GJBaseGameLayer*, EffectGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11e22c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJBaseGameLayer::activateSFXEditTrigger(SFXTriggerGameObject* object) -> decltype(activateSFXEditTrigger(object)) {
	using FunctionType = decltype(activateSFXEditTrigger(object))(*)(GJBaseGameLayer*, SFXTriggerGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x12a0b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJBaseGameLayer::activateSFXTrigger(SFXTriggerGameObject* object) -> decltype(activateSFXTrigger(object)) {
	using FunctionType = decltype(activateSFXTrigger(object))(*)(GJBaseGameLayer*, SFXTriggerGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x129db0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJBaseGameLayer::activateSongEditTrigger(SongTriggerGameObject* object) -> decltype(activateSongEditTrigger(object)) {
	using FunctionType = decltype(activateSongEditTrigger(object))(*)(GJBaseGameLayer*, SongTriggerGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x129c2c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJBaseGameLayer::activateSongTrigger(SongTriggerGameObject* object) -> decltype(activateSongTrigger(object)) {
	using FunctionType = decltype(activateSongTrigger(object))(*)(GJBaseGameLayer*, SongTriggerGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x129a28, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJBaseGameLayer::activateTimerTrigger(TimerTriggerGameObject* object, gd::vector<int> const& remapKeys) -> decltype(activateTimerTrigger(object, remapKeys)) {
	using FunctionType = decltype(activateTimerTrigger(object, remapKeys))(*)(GJBaseGameLayer*, TimerTriggerGameObject*, gd::vector<int> const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11fa14, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, remapKeys);
}

auto GJBaseGameLayer::addAreaEffect(EnterEffectObject* object, gd::vector<EnterEffectInstance>* instances, GJAreaActionType type) -> decltype(addAreaEffect(object, instances, type)) {
	using FunctionType = decltype(addAreaEffect(object, instances, type))(*)(GJBaseGameLayer*, EnterEffectObject*, gd::vector<EnterEffectInstance>*, GJAreaActionType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x114378, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, instances, type);
}

auto GJBaseGameLayer::addCustomEnterEffect(EnterEffectObject* object, bool enter) -> decltype(addCustomEnterEffect(object, enter)) {
	using FunctionType = decltype(addCustomEnterEffect(object, enter))(*)(GJBaseGameLayer*, EnterEffectObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xf726c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, enter);
}

auto GJBaseGameLayer::addGuideArt(GameObject* object) -> decltype(addGuideArt(object)) {
	using FunctionType = decltype(addGuideArt(object))(*)(GJBaseGameLayer*, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1301cc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJBaseGameLayer::addObjectCounter(LabelGameObject* object) -> decltype(addObjectCounter(object)) {
	using FunctionType = decltype(addObjectCounter(object))(*)(GJBaseGameLayer*, LabelGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11e8c4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJBaseGameLayer::addPickupTrigger(CountTriggerGameObject* object) -> decltype(addPickupTrigger(object)) {
	using FunctionType = decltype(addPickupTrigger(object))(*)(GJBaseGameLayer*, CountTriggerGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11e7fc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJBaseGameLayer::addPoints(int points) -> decltype(addPoints(points)) {
	using FunctionType = decltype(addPoints(points))(*)(GJBaseGameLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1268bc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, points);
}

auto GJBaseGameLayer::addProximityVolumeEffect(int channelID, int targetType, SFXTriggerGameObject* object) -> decltype(addProximityVolumeEffect(channelID, targetType, object)) {
	using FunctionType = decltype(addProximityVolumeEffect(channelID, targetType, object))(*)(GJBaseGameLayer*, int, int, SFXTriggerGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x12d578, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, channelID, targetType, object);
}

auto GJBaseGameLayer::addRemapTargets(gd::set<int>& targets) -> decltype(addRemapTargets(targets)) {
	using FunctionType = decltype(addRemapTargets(targets))(*)(GJBaseGameLayer*, gd::set<int>&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xf154c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, targets);
}

auto GJBaseGameLayer::addToGroupParents(GameObject* object) -> decltype(addToGroupParents(object)) {
	using FunctionType = decltype(addToGroupParents(object))(*)(GJBaseGameLayer*, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1125b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJBaseGameLayer::addToGroups(GameObject* object, bool duplicateTrigger) -> decltype(addToGroups(object, duplicateTrigger)) {
	using FunctionType = decltype(addToGroups(object, duplicateTrigger))(*)(GJBaseGameLayer*, GameObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x111c3c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, duplicateTrigger);
}

auto GJBaseGameLayer::addUIObject(GameObject* object) -> decltype(addUIObject(object)) {
	using FunctionType = decltype(addUIObject(object))(*)(GJBaseGameLayer*, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x113094, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJBaseGameLayer::animateInDualGroundNew(GameObject* object, float height, bool instant, float duration) -> decltype(animateInDualGroundNew(object, height, instant, duration)) {
	using FunctionType = decltype(animateInDualGroundNew(object, height, instant, duration))(*)(GJBaseGameLayer*, GameObject*, float, bool, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xfd840, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, height, instant, duration);
}

auto GJBaseGameLayer::animateInGroundNew(bool unk1, float unk2, bool unk3) -> decltype(animateInGroundNew(unk1, unk2, unk3)) {
	using FunctionType = decltype(animateInGroundNew(unk1, unk2, unk3))(*)(GJBaseGameLayer*, bool, float, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xfdf20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, unk1, unk2, unk3);
}

auto GJBaseGameLayer::animateOutGroundNew(bool instant) -> decltype(animateOutGroundNew(instant)) {
	using FunctionType = decltype(animateOutGroundNew(instant))(*)(GJBaseGameLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xfdac8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, instant);
}

auto GJBaseGameLayer::animatePortalY(float fromY, float toY, float duration, float easingRate) -> decltype(animatePortalY(fromY, toY, duration, easingRate)) {
	using FunctionType = decltype(animatePortalY(fromY, toY, duration, easingRate))(*)(GJBaseGameLayer*, float, float, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x12b268, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, fromY, toY, duration, easingRate);
}

auto GJBaseGameLayer::applyLevelSettings(GameObject* object) -> decltype(applyLevelSettings(object)) {
	using FunctionType = decltype(applyLevelSettings(object))(*)(GJBaseGameLayer*, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1288a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJBaseGameLayer::applyRemap(EffectGameObject* object, gd::vector<int> const& remapKeys, gd::unordered_map<int, int>& remap) -> decltype(applyRemap(object, remapKeys, remap)) {
	using FunctionType = decltype(applyRemap(object, remapKeys, remap))(*)(GJBaseGameLayer*, EffectGameObject*, gd::vector<int> const&, gd::unordered_map<int, int>&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x104fa4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, remapKeys, remap);
}

auto GJBaseGameLayer::applySFXEditTrigger(int channelID, int targetType, SFXTriggerGameObject* object) -> decltype(applySFXEditTrigger(channelID, targetType, object)) {
	using FunctionType = decltype(applySFXEditTrigger(channelID, targetType, object))(*)(GJBaseGameLayer*, int, int, SFXTriggerGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x12d45c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, channelID, targetType, object);
}

auto GJBaseGameLayer::applyShake(cocos2d::CCPoint& point) -> decltype(applyShake(point)) {
	using FunctionType = decltype(applyShake(point))(*)(GJBaseGameLayer*, cocos2d::CCPoint&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x12a6b8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, point);
}

auto GJBaseGameLayer::assignNewStickyGroups(cocos2d::CCArray* objects) -> decltype(assignNewStickyGroups(objects)) {
	using FunctionType = decltype(assignNewStickyGroups(objects))(*)(GJBaseGameLayer*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x112c84, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, objects);
}

auto GJBaseGameLayer::asyncBGLoaded(int background) -> decltype(asyncBGLoaded(background)) {
	using FunctionType = decltype(asyncBGLoaded(background))(*)(GJBaseGameLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xef434, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, background);
}

auto GJBaseGameLayer::asyncGLoaded(int ground) -> decltype(asyncGLoaded(ground)) {
	using FunctionType = decltype(asyncGLoaded(ground))(*)(GJBaseGameLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xef6f4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, ground);
}

auto GJBaseGameLayer::asyncMGLoaded(int middleground) -> decltype(asyncMGLoaded(middleground)) {
	using FunctionType = decltype(asyncMGLoaded(middleground))(*)(GJBaseGameLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xef988, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, middleground);
}

auto GJBaseGameLayer::atlasValue(int atlas) -> decltype(atlasValue(atlas)) {
	using FunctionType = decltype(atlasValue(atlas))(*)(GJBaseGameLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xf6e10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, atlas);
}

auto GJBaseGameLayer::bumpPlayer(PlayerObject* player, EffectGameObject* object) -> decltype(bumpPlayer(player, object)) {
	using FunctionType = decltype(bumpPlayer(player, object))(*)(GJBaseGameLayer*, PlayerObject*, EffectGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1004b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, player, object);
}

auto GJBaseGameLayer::buttonIDToButton(int id) -> decltype(buttonIDToButton(id)) {
	using FunctionType = decltype(buttonIDToButton(id))(*)(GJBaseGameLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x126c5c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GJBaseGameLayer::buttonIsRelevant(PlayerButtonCommand const& button) -> decltype(buttonIsRelevant(button)) {
	using FunctionType = decltype(buttonIsRelevant(button))(*)(GJBaseGameLayer*, PlayerButtonCommand const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11d85c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, button);
}

auto GJBaseGameLayer::calculateColorGroups() -> decltype(calculateColorGroups()) {
	using FunctionType = decltype(calculateColorGroups())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xf6b08, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::cameraMoveX(float value, float duration, float rate, bool unused) -> decltype(cameraMoveX(value, duration, rate, unused)) {
	using FunctionType = decltype(cameraMoveX(value, duration, rate, unused))(*)(GJBaseGameLayer*, float, float, float, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x12af54, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, value, duration, rate, unused);
}

auto GJBaseGameLayer::cameraMoveY(float value, float duration, float rate, bool force) -> decltype(cameraMoveY(value, duration, rate, force)) {
	using FunctionType = decltype(cameraMoveY(value, duration, rate, force))(*)(GJBaseGameLayer*, float, float, float, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x12aff0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, value, duration, rate, force);
}

auto GJBaseGameLayer::canBeActivatedByPlayer(PlayerObject* player, EffectGameObject* object) -> decltype(canBeActivatedByPlayer(player, object)) {
	using FunctionType = decltype(canBeActivatedByPlayer(player, object))(*)(GJBaseGameLayer*, PlayerObject*, EffectGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1000cc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, player, object);
}

auto GJBaseGameLayer::canProcessSFX(SFXTriggerState& state, gd::unordered_map<int, int>& stateIndices, gd::unordered_map<int, float>& times, gd::vector<SFXTriggerState>& states) -> decltype(canProcessSFX(state, stateIndices, times, states)) {
	using FunctionType = decltype(canProcessSFX(state, stateIndices, times, states))(*)(GJBaseGameLayer*, SFXTriggerState&, gd::unordered_map<int, int>&, gd::unordered_map<int, float>&, gd::vector<SFXTriggerState>&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x12e2f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, state, stateIndices, times, states);
}

auto GJBaseGameLayer::canTouchObject(GameObject* object) -> decltype(canTouchObject(object)) {
	using FunctionType = decltype(canTouchObject(object))(*)(GJBaseGameLayer*, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x10009c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJBaseGameLayer::checkCameraLimitAfterTeleport(PlayerObject* player, float yOffset) -> decltype(checkCameraLimitAfterTeleport(player, yOffset)) {
	using FunctionType = decltype(checkCameraLimitAfterTeleport(player, yOffset))(*)(GJBaseGameLayer*, PlayerObject*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xfa3bc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, player, yOffset);
}

auto GJBaseGameLayer::checkCollision(int blockAID, int blockBID) -> decltype(checkCollision(blockAID, blockBID)) {
	using FunctionType = decltype(checkCollision(blockAID, blockBID))(*)(GJBaseGameLayer*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1038bc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, blockAID, blockBID);
}

auto GJBaseGameLayer::checkCollisionBlocks(EffectGameObject* object, gd::vector<EffectGameObject*>* blocks, int blockCount) -> decltype(checkCollisionBlocks(object, blocks, blockCount)) {
	using FunctionType = decltype(checkCollisionBlocks(object, blocks, blockCount))(*)(GJBaseGameLayer*, EffectGameObject*, gd::vector<EffectGameObject*>*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x103718, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, blocks, blockCount);
}

auto GJBaseGameLayer::checkCollisions(PlayerObject* object, float dt, bool ignoreDamage) -> decltype(checkCollisions(object, dt, ignoreDamage)) {
	using FunctionType = decltype(checkCollisions(object, dt, ignoreDamage))(*)(GJBaseGameLayer*, PlayerObject*, float, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xfe188, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, dt, ignoreDamage);
}

auto GJBaseGameLayer::checkRepellPlayer() -> decltype(checkRepellPlayer()) {
	using FunctionType = decltype(checkRepellPlayer())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x124648, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::checkSpawnObjects() -> decltype(checkSpawnObjects()) {
	using FunctionType = decltype(checkSpawnObjects())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x104658, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::claimMoveAction(int groupID, bool ignoreStaticGroups) -> decltype(claimMoveAction(groupID, ignoreStaticGroups)) {
	using FunctionType = decltype(claimMoveAction(groupID, ignoreStaticGroups))(*)(GJBaseGameLayer*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11a694, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, groupID, ignoreStaticGroups);
}

auto GJBaseGameLayer::claimParticle(gd::string key, int zLayer) -> decltype(claimParticle(key, zLayer)) {
	using FunctionType = decltype(claimParticle(key, zLayer))(*)(GJBaseGameLayer*, gd::string, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x12c618, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key, zLayer);
}

auto GJBaseGameLayer::claimRotationAction(int targetID, int centerID, float& rotation, float& offset, bool ignoreStaticGroups, bool unused) -> decltype(claimRotationAction(targetID, centerID, rotation, offset, ignoreStaticGroups, unused)) {
	using FunctionType = decltype(claimRotationAction(targetID, centerID, rotation, offset, ignoreStaticGroups, unused))(*)(GJBaseGameLayer*, int, int, float&, float&, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11a52c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, targetID, centerID, rotation, offset, ignoreStaticGroups, unused);
}

auto GJBaseGameLayer::clearActivatedAudioTriggers() -> decltype(clearActivatedAudioTriggers()) {
	using FunctionType = decltype(clearActivatedAudioTriggers())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x12947c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::clearPickedUpItems() -> decltype(clearPickedUpItems()) {
	using FunctionType = decltype(clearPickedUpItems())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1019ec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::collectedObject(EffectGameObject* object) -> decltype(collectedObject(object)) {
	using FunctionType = decltype(collectedObject(object))(*)(GJBaseGameLayer*, EffectGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11e410, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJBaseGameLayer::collisionCheckObjects(PlayerObject* object, gd::vector<GameObject*>* objects, int objectCount, float dt) -> decltype(collisionCheckObjects(object, objects, objectCount, dt)) {
	using FunctionType = decltype(collisionCheckObjects(object, objects, objectCount, dt))(*)(GJBaseGameLayer*, PlayerObject*, gd::vector<GameObject*>*, int, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xff074, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, objects, objectCount, dt);
}

auto GJBaseGameLayer::controlAdvancedFollowCommand(AdvancedFollowTriggerObject* object, int controlID, GJActionCommand command) -> decltype(controlAdvancedFollowCommand(object, controlID, command)) {
	using FunctionType = decltype(controlAdvancedFollowCommand(object, controlID, command))(*)(GJBaseGameLayer*, AdvancedFollowTriggerObject*, int, GJActionCommand);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x10b894, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, controlID, command);
}

auto GJBaseGameLayer::controlAreaEffect(EnterEffectObject* object, gd::vector<EnterEffectInstance>* instances, GJActionCommand command) -> decltype(controlAreaEffect(object, instances, command)) {
	using FunctionType = decltype(controlAreaEffect(object, instances, command))(*)(GJBaseGameLayer*, EnterEffectObject*, gd::vector<EnterEffectInstance>*, GJActionCommand);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x10b7c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, instances, command);
}

auto GJBaseGameLayer::controlAreaEffectWithID(int uniqueID, int controlID, GJActionCommand command) -> decltype(controlAreaEffectWithID(uniqueID, controlID, command)) {
	using FunctionType = decltype(controlAreaEffectWithID(uniqueID, controlID, command))(*)(GJBaseGameLayer*, int, int, GJActionCommand);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x10c2c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, uniqueID, controlID, command);
}

auto GJBaseGameLayer::controlDynamicCommand(EffectGameObject* object, int controlID, gd::vector<DynamicObjectAction>& actions, GJActionCommand command) -> decltype(controlDynamicCommand(object, controlID, actions, command)) {
	using FunctionType = decltype(controlDynamicCommand(object, controlID, actions, command))(*)(GJBaseGameLayer*, EffectGameObject*, int, gd::vector<DynamicObjectAction>&, GJActionCommand);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x10dc34, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, controlID, actions, command);
}

auto GJBaseGameLayer::controlDynamicMoveCommand(EffectGameObject* object, int controlID, GJActionCommand command) -> decltype(controlDynamicMoveCommand(object, controlID, command)) {
	using FunctionType = decltype(controlDynamicMoveCommand(object, controlID, command))(*)(GJBaseGameLayer*, EffectGameObject*, int, GJActionCommand);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x10bedc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, controlID, command);
}

auto GJBaseGameLayer::controlDynamicRotateCommand(EffectGameObject* object, int controlID, GJActionCommand command) -> decltype(controlDynamicRotateCommand(object, controlID, command)) {
	using FunctionType = decltype(controlDynamicRotateCommand(object, controlID, command))(*)(GJBaseGameLayer*, EffectGameObject*, int, GJActionCommand);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x10bdb4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, controlID, command);
}

auto GJBaseGameLayer::controlEventLink(int uniqueID, int controlID, GJActionCommand command) -> decltype(controlEventLink(uniqueID, controlID, command)) {
	using FunctionType = decltype(controlEventLink(uniqueID, controlID, command))(*)(GJBaseGameLayer*, int, int, GJActionCommand);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x10bb7c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, uniqueID, controlID, command);
}

auto GJBaseGameLayer::controlGradientTrigger(GradientTriggerObject* object, GJActionCommand command) -> decltype(controlGradientTrigger(object, command)) {
	using FunctionType = decltype(controlGradientTrigger(object, command))(*)(GJBaseGameLayer*, GradientTriggerObject*, GJActionCommand);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x10bd58, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, command);
}

auto GJBaseGameLayer::controlTriggersInGroup(int group, GJActionCommand command) -> decltype(controlTriggersInGroup(group, command)) {
	using FunctionType = decltype(controlTriggersInGroup(group, command))(*)(GJBaseGameLayer*, int, GJActionCommand);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x10b0e4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, group, command);
}

auto GJBaseGameLayer::controlTriggersWithControlID(int controlID, GJActionCommand command) -> decltype(controlTriggersWithControlID(controlID, command)) {
	using FunctionType = decltype(controlTriggersWithControlID(controlID, command))(*)(GJBaseGameLayer*, int, GJActionCommand);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x10c004, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, controlID, command);
}

auto GJBaseGameLayer::countCollectedUserCoins() -> decltype(countCollectedUserCoins()) {
	using FunctionType = decltype(countCollectedUserCoins())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x10176c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::createBackground(int background) -> decltype(createBackground(background)) {
	using FunctionType = decltype(createBackground(background))(*)(GJBaseGameLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xef1e8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, background);
}

auto GJBaseGameLayer::createGroundLayer(int ground, int line) -> decltype(createGroundLayer(ground, line)) {
	using FunctionType = decltype(createGroundLayer(ground, line))(*)(GJBaseGameLayer*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xef71c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, ground, line);
}

auto GJBaseGameLayer::createMiddleground(int middleground) -> decltype(createMiddleground(middleground)) {
	using FunctionType = decltype(createMiddleground(middleground))(*)(GJBaseGameLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xef900, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, middleground);
}

auto GJBaseGameLayer::createNewKeyframeAnim() -> decltype(createNewKeyframeAnim()) {
	using FunctionType = decltype(createNewKeyframeAnim())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11e018, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::createParticle(int objectType, char const* plistName, int tag, cocos2d::tCCPositionType positionType) -> decltype(createParticle(objectType, plistName, tag, positionType)) {
	using FunctionType = decltype(createParticle(objectType, plistName, tag, positionType))(*)(GJBaseGameLayer*, int, char const*, int, cocos2d::tCCPositionType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x12c140, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, objectType, plistName, tag, positionType);
}

auto GJBaseGameLayer::createPlayer() -> decltype(createPlayer()) {
	using FunctionType = decltype(createPlayer())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xeeea0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::createPlayerCollisionBlock() -> decltype(createPlayerCollisionBlock()) {
	using FunctionType = decltype(createPlayerCollisionBlock())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x102b24, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::createTextLayers() -> decltype(createTextLayers()) {
	using FunctionType = decltype(createTextLayers())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xf82c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::damagingObjectsInRect(cocos2d::CCRect rect, bool enabledGroups) -> decltype(damagingObjectsInRect(rect, enabledGroups)) {
	using FunctionType = decltype(damagingObjectsInRect(rect, enabledGroups))(*)(GJBaseGameLayer*, cocos2d::CCRect, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xfb5d4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, rect, enabledGroups);
}

auto GJBaseGameLayer::destroyObject(GameObject* object) -> decltype(destroyObject(object)) {
	using FunctionType = decltype(destroyObject(object))(*)(GJBaseGameLayer*, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x100c28, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJBaseGameLayer::enterDualMode(GameObject* object, bool unused) -> decltype(enterDualMode(object, unused)) {
	using FunctionType = decltype(enterDualMode(object, unused))(*)(GJBaseGameLayer*, GameObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x101f4c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, unused);
}

auto GJBaseGameLayer::exitStaticCamera(bool exitX, bool exitY, float time, int easingType, float easingRate, bool smoothVelocity, float smoothVelocityMod, bool exitInstant) -> decltype(exitStaticCamera(exitX, exitY, time, easingType, easingRate, smoothVelocity, smoothVelocityMod, exitInstant)) {
	using FunctionType = decltype(exitStaticCamera(exitX, exitY, time, easingType, easingRate, smoothVelocity, smoothVelocityMod, exitInstant))(*)(GJBaseGameLayer*, bool, bool, float, int, float, bool, float, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x12b6b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, exitX, exitY, time, easingType, easingRate, smoothVelocity, smoothVelocityMod, exitInstant);
}

auto GJBaseGameLayer::flipFinished() -> decltype(flipFinished()) {
	using FunctionType = decltype(flipFinished())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x126858, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::flipGravity(PlayerObject* object, bool flip, bool noEffects) -> decltype(flipGravity(object, flip, noEffects)) {
	using FunctionType = decltype(flipGravity(object, flip, noEffects))(*)(GJBaseGameLayer*, PlayerObject*, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xfd41c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, flip, noEffects);
}

auto GJBaseGameLayer::flipObjects() -> decltype(flipObjects()) {
	using FunctionType = decltype(flipObjects())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x130fe0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::gameEventTriggered(GJGameEvent event, int material, int playerID) -> decltype(gameEventTriggered(event, material, playerID)) {
	using FunctionType = decltype(gameEventTriggered(event, material, playerID))(*)(GJBaseGameLayer*, GJGameEvent, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xfa490, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, event, material, playerID);
}

auto GJBaseGameLayer::generateEnterEasingBuffer(int easingType, float easingRate) -> decltype(generateEnterEasingBuffer(easingType, easingRate)) {
	using FunctionType = decltype(generateEnterEasingBuffer(easingType, easingRate))(*)(GJBaseGameLayer*, int, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xf7c70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, easingType, easingRate);
}

auto GJBaseGameLayer::generateEnterEasingBuffers(EnterEffectObject* object) -> decltype(generateEnterEasingBuffers(object)) {
	using FunctionType = decltype(generateEnterEasingBuffers(object))(*)(GJBaseGameLayer*, EnterEffectObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xf7be8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJBaseGameLayer::generatePickupAnimRandVal(GameObject* object, float& randomValue1, float& randomValue2) -> decltype(generatePickupAnimRandVal(object, randomValue1, randomValue2)) {
	using FunctionType = decltype(generatePickupAnimRandVal(object, randomValue1, randomValue2))(*)(GJBaseGameLayer*, GameObject*, float&, float&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x10137c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, randomValue1, randomValue2);
}

auto GJBaseGameLayer::generateSpawnRemap() -> decltype(generateSpawnRemap()) {
	using FunctionType = decltype(generateSpawnRemap())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xf1d44, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::generateTargetGroups() -> decltype(generateTargetGroups()) {
	using FunctionType = decltype(generateTargetGroups())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xf4354, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::generateVisibilityGroups() -> decltype(generateVisibilityGroups()) {
	using FunctionType = decltype(generateVisibilityGroups())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xf5d58, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::getActiveOrderSpawnObjects() -> decltype(getActiveOrderSpawnObjects()) {
	using FunctionType = decltype(getActiveOrderSpawnObjects())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1048d4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::getAreaObjectValue(EnterEffectInstance* instance, GameObject* object, cocos2d::CCPoint& position, bool& show) -> decltype(getAreaObjectValue(instance, object, position, show)) {
	using FunctionType = decltype(getAreaObjectValue(instance, object, position, show))(*)(GJBaseGameLayer*, EnterEffectInstance*, GameObject*, cocos2d::CCPoint&, bool&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x117708, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, instance, object, position, show);
}

auto GJBaseGameLayer::getBumpMod(PlayerObject* player, int type) -> decltype(getBumpMod(player, type)) {
	using FunctionType = decltype(getBumpMod(player, type))(*)(GJBaseGameLayer*, PlayerObject*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1022b8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, player, type);
}

auto GJBaseGameLayer::getCameraEdgeValue(int type) -> decltype(getCameraEdgeValue(type)) {
	using FunctionType = decltype(getCameraEdgeValue(type))(*)(GJBaseGameLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x120ea4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type);
}

auto GJBaseGameLayer::getCapacityString() -> decltype(getCapacityString()) {
	using FunctionType = decltype(getCapacityString())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xf7fb4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::getCenterGroupObject(int groupID, int defaultID) -> decltype(getCenterGroupObject(groupID, defaultID)) {
	using FunctionType = decltype(getCenterGroupObject(groupID, defaultID))(*)(GJBaseGameLayer*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x112260, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, groupID, defaultID);
}

auto GJBaseGameLayer::getCustomEnterEffects(int id, bool enter) -> decltype(getCustomEnterEffects(id, enter)) {
	using FunctionType = decltype(getCustomEnterEffects(id, enter))(*)(GJBaseGameLayer*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xf7acc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, enter);
}

auto GJBaseGameLayer::getEasedAreaValue(GameObject* object, EnterEffectInstance* instance, float value, bool show, int index) -> decltype(getEasedAreaValue(object, instance, value, show, index)) {
	using FunctionType = decltype(getEasedAreaValue(object, instance, value, show, index))(*)(GJBaseGameLayer*, GameObject*, EnterEffectInstance*, float, bool, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x117938, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, instance, value, show, index);
}

auto GJBaseGameLayer::getEnterEasingKey(int easingType, float easingRate) -> decltype(getEnterEasingKey(easingType, easingRate)) {
	using FunctionType = decltype(getEnterEasingKey(easingType, easingRate))(*)(GJBaseGameLayer*, int, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xf7c2c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, easingType, easingRate);
}

auto GJBaseGameLayer::getEnterEasingValue(float value, int easingType, float easingRate, int easingBuffer) -> decltype(getEnterEasingValue(value, easingType, easingRate, easingBuffer)) {
	using FunctionType = decltype(getEnterEasingValue(value, easingType, easingRate, easingBuffer))(*)(GJBaseGameLayer*, float, int, float, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xf7f54, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, value, easingType, easingRate, easingBuffer);
}

auto GJBaseGameLayer::getFollowSpeedVal(GameObject* object, int startSpeedRef, int startDirRef, float startDir, float startSpeed) -> decltype(getFollowSpeedVal(object, startSpeedRef, startDirRef, startDir, startSpeed)) {
	using FunctionType = decltype(getFollowSpeedVal(object, startSpeedRef, startDirRef, startDir, startSpeed))(*)(GJBaseGameLayer*, GameObject*, int, int, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11af7c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, startSpeedRef, startDirRef, startDir, startSpeed);
}

auto GJBaseGameLayer::getGroundHeight(PlayerObject* player, int type) -> decltype(getGroundHeight(player, type)) {
	using FunctionType = decltype(getGroundHeight(player, type))(*)(GJBaseGameLayer*, PlayerObject*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xfbcec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, player, type);
}

auto GJBaseGameLayer::getGroundHeightForMode(int type) -> decltype(getGroundHeightForMode(type)) {
	using FunctionType = decltype(getGroundHeightForMode(type))(*)(GJBaseGameLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xfbc78, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type);
}

auto GJBaseGameLayer::getGroup(int id) -> decltype(getGroup(id)) {
	using FunctionType = decltype(getGroup(id))(*)(GJBaseGameLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xf6d9c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GJBaseGameLayer::getGroupParent(int groupId) -> decltype(getGroupParent(groupId)) {
	using FunctionType = decltype(getGroupParent(groupId))(*)(GJBaseGameLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x112070, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, groupId);
}

auto GJBaseGameLayer::getGroupParentsString(GameObject* object) -> decltype(getGroupParentsString(object)) {
	using FunctionType = decltype(getGroupParentsString(object))(*)(GJBaseGameLayer*, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x112678, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJBaseGameLayer::getItemValue(int type, int id) -> decltype(getItemValue(type, id)) {
	using FunctionType = decltype(getItemValue(type, id))(*)(GJBaseGameLayer*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11ea08, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type, id);
}

auto GJBaseGameLayer::getMaxPortalY() -> decltype(getMaxPortalY()) {
	using FunctionType = decltype(getMaxPortalY())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xfe0e4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::getMinDistance(cocos2d::CCPoint position, cocos2d::CCArray* objects, float minNear, int mode) -> decltype(getMinDistance(position, objects, minNear, mode)) {
	using FunctionType = decltype(getMinDistance(position, objects, minNear, mode))(*)(GJBaseGameLayer*, cocos2d::CCPoint, cocos2d::CCArray*, float, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x12db24, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, position, objects, minNear, mode);
}

auto GJBaseGameLayer::getMinPortalY() -> decltype(getMinPortalY()) {
	using FunctionType = decltype(getMinPortalY())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xfe008, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::getModifiedDelta(float dt) -> decltype(getModifiedDelta(dt)) {
	using FunctionType = decltype(getModifiedDelta(dt))(*)(GJBaseGameLayer*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x122958, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt);
}

auto GJBaseGameLayer::getMoveTargetDelta(EffectGameObject* object, bool mainObject) -> decltype(getMoveTargetDelta(object, mainObject)) {
	using FunctionType = decltype(getMoveTargetDelta(object, mainObject))(*)(GJBaseGameLayer*, EffectGameObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1038f4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, mainObject);
}

auto GJBaseGameLayer::getOptimizedGroup(int groupID) -> decltype(getOptimizedGroup(groupID)) {
	using FunctionType = decltype(getOptimizedGroup(groupID))(*)(GJBaseGameLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x111db8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, groupID);
}

auto GJBaseGameLayer::getOtherPlayer(PlayerObject* player) -> decltype(getOtherPlayer(player)) {
	using FunctionType = decltype(getOtherPlayer(player))(*)(GJBaseGameLayer*, PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xfbdf4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, player);
}

auto GJBaseGameLayer::getParticleKey(int objectType, char const* plistName, int tag, cocos2d::tCCPositionType positionType) -> decltype(getParticleKey(objectType, plistName, tag, positionType)) {
	using FunctionType = decltype(getParticleKey(objectType, plistName, tag, positionType))(*)(GJBaseGameLayer*, int, char const*, int, cocos2d::tCCPositionType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x12bd04, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, objectType, plistName, tag, positionType);
}

auto GJBaseGameLayer::getParticleKey2(gd::string key) -> decltype(getParticleKey2(key)) {
	using FunctionType = decltype(getParticleKey2(key))(*)(GJBaseGameLayer*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x12c06c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GJBaseGameLayer::getPlayerButtonID(int button, bool player2) -> decltype(getPlayerButtonID(button, player2)) {
	using FunctionType = decltype(getPlayerButtonID(button, player2))(*)(GJBaseGameLayer*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x126c2c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, button, player2);
}

auto GJBaseGameLayer::getPlayTimerFullSeconds() -> decltype(getPlayTimerFullSeconds()) {
	using FunctionType = decltype(getPlayTimerFullSeconds())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1268b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::getPlayTimerMilli() -> decltype(getPlayTimerMilli()) {
	using FunctionType = decltype(getPlayTimerMilli())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x126894, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::getPortalTarget(TeleportPortalObject* object) -> decltype(getPortalTarget(object)) {
	using FunctionType = decltype(getPortalTarget(object))(*)(GJBaseGameLayer*, TeleportPortalObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xfa084, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJBaseGameLayer::getPortalTargetPos(TeleportPortalObject* object, GameObject* target, PlayerObject* player) -> decltype(getPortalTargetPos(object, target, player)) {
	using FunctionType = decltype(getPortalTargetPos(object, target, player))(*)(GJBaseGameLayer*, TeleportPortalObject*, GameObject*, PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xfa1a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, target, player);
}

auto GJBaseGameLayer::getRecordExtra() -> decltype(getRecordExtra()) {
	using FunctionType = decltype(getRecordExtra())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x127224, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::getRecordString(bool compress) -> decltype(getRecordString(compress)) {
	using FunctionType = decltype(getRecordString(compress))(*)(GJBaseGameLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x127374, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, compress);
}

auto GJBaseGameLayer::getRotateCommandTargets(EnhancedTriggerObject* object, GameObject*& centerObject, GameObject*& targetObject, GameObject*& rotateObject) -> decltype(getRotateCommandTargets(object, centerObject, targetObject, rotateObject)) {
	using FunctionType = decltype(getRotateCommandTargets(object, centerObject, targetObject, rotateObject))(*)(GJBaseGameLayer*, EnhancedTriggerObject*, GameObject*&, GameObject*&, GameObject*&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x10d318, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, centerObject, targetObject, rotateObject);
}

auto GJBaseGameLayer::getSavedPosition(int groupID, float delay) -> decltype(getSavedPosition(groupID, delay)) {
	using FunctionType = decltype(getSavedPosition(groupID, delay))(*)(GJBaseGameLayer*, int, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x103b14, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, groupID, delay);
}

auto GJBaseGameLayer::getScaledGroundHeight(float height) -> decltype(getScaledGroundHeight(height)) {
	using FunctionType = decltype(getScaledGroundHeight(height))(*)(GJBaseGameLayer*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x102afc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, height);
}

auto GJBaseGameLayer::getSingleGroupObject(int groupID) -> decltype(getSingleGroupObject(groupID)) {
	using FunctionType = decltype(getSingleGroupObject(groupID))(*)(GJBaseGameLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11215c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, groupID);
}

auto GJBaseGameLayer::getSpecialKey(int groupID, bool ignoreGroupParent, bool ignoreLinkedObjects) -> decltype(getSpecialKey(groupID, ignoreGroupParent, ignoreLinkedObjects)) {
	using FunctionType = decltype(getSpecialKey(groupID, ignoreGroupParent, ignoreLinkedObjects))(*)(GJBaseGameLayer*, int, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xf7904, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, groupID, ignoreGroupParent, ignoreLinkedObjects);
}

auto GJBaseGameLayer::getStaticGroup(int groupID) -> decltype(getStaticGroup(groupID)) {
	using FunctionType = decltype(getStaticGroup(groupID))(*)(GJBaseGameLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x111e2c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, groupID);
}

auto GJBaseGameLayer::getStickyGroup(int group) -> decltype(getStickyGroup(group)) {
	using FunctionType = decltype(getStickyGroup(group))(*)(GJBaseGameLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x112ab8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, group);
}

auto GJBaseGameLayer::getTargetFlyCameraY(GameObject* object) -> decltype(getTargetFlyCameraY(object)) {
	using FunctionType = decltype(getTargetFlyCameraY(object))(*)(GJBaseGameLayer*, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xfdbc4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJBaseGameLayer::getTargetGroup(int index, int uniqueID) -> decltype(getTargetGroup(index, uniqueID)) {
	using FunctionType = decltype(getTargetGroup(index, uniqueID))(*)(GJBaseGameLayer*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11303c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index, uniqueID);
}

auto GJBaseGameLayer::getTargetGroupOrigin(int index, int uniqueID) -> decltype(getTargetGroupOrigin(index, uniqueID)) {
	using FunctionType = decltype(getTargetGroupOrigin(index, uniqueID))(*)(GJBaseGameLayer*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x113068, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index, uniqueID);
}

auto GJBaseGameLayer::gravBumpPlayer(PlayerObject* player, EffectGameObject* object) -> decltype(gravBumpPlayer(player, object)) {
	using FunctionType = decltype(gravBumpPlayer(player, object))(*)(GJBaseGameLayer*, PlayerObject*, EffectGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1006dc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, player, object);
}

auto GJBaseGameLayer::groupStickyObjects(cocos2d::CCArray* objects) -> decltype(groupStickyObjects(objects)) {
	using FunctionType = decltype(groupStickyObjects(objects))(*)(GJBaseGameLayer*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x112ac4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, objects);
}

auto GJBaseGameLayer::handleButton(bool down, int button, bool isPlayer1) -> decltype(handleButton(down, button, isPlayer1)) {
	using FunctionType = decltype(handleButton(down, button, isPlayer1))(*)(GJBaseGameLayer*, bool, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11d578, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, down, button, isPlayer1);
}

auto GJBaseGameLayer::hasItem(int id) -> decltype(hasItem(id)) {
	using FunctionType = decltype(hasItem(id))(*)(GJBaseGameLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x101668, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GJBaseGameLayer::hasUniqueCoin(EffectGameObject* object) -> decltype(hasUniqueCoin(object)) {
	using FunctionType = decltype(hasUniqueCoin(object))(*)(GJBaseGameLayer*, EffectGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x100d0c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJBaseGameLayer::increaseBatchNodeCapacity() -> decltype(increaseBatchNodeCapacity()) {
	using FunctionType = decltype(increaseBatchNodeCapacity())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xf013c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::isFlipping() -> decltype(isFlipping()) {
	using FunctionType = decltype(isFlipping())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x12683c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::isPlayer2Button(int button) -> decltype(isPlayer2Button(button)) {
	using FunctionType = decltype(isPlayer2Button(button))(*)(GJBaseGameLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x126c20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, button);
}

auto GJBaseGameLayer::lightningFlash(cocos2d::CCPoint to, cocos2d::ccColor3B color) -> decltype(lightningFlash(to, color)) {
	using FunctionType = decltype(lightningFlash(to, color))(*)(GJBaseGameLayer*, cocos2d::CCPoint, cocos2d::ccColor3B);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1311b4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, to, color);
}

auto GJBaseGameLayer::lightningFlash(cocos2d::CCPoint from, cocos2d::CCPoint to, cocos2d::ccColor3B color, float lineWidth, float duration, int displacement, bool flash, float opacity) -> decltype(lightningFlash(from, to, color, lineWidth, duration, displacement, flash, opacity)) {
	using FunctionType = decltype(lightningFlash(from, to, color, lineWidth, duration, displacement, flash, opacity))(*)(GJBaseGameLayer*, cocos2d::CCPoint, cocos2d::CCPoint, cocos2d::ccColor3B, float, float, int, bool, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xfa244, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, from, to, color, lineWidth, duration, displacement, flash, opacity);
}

auto GJBaseGameLayer::loadGroupParentsFromString(GameObject* object, gd::string groupList) -> decltype(loadGroupParentsFromString(object, groupList)) {
	using FunctionType = decltype(loadGroupParentsFromString(object, groupList))(*)(GJBaseGameLayer*, GameObject*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1128f8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, groupList);
}

auto GJBaseGameLayer::loadLevelSettings() -> decltype(loadLevelSettings()) {
	using FunctionType = decltype(loadLevelSettings())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x12874c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::loadStartPosObject() -> decltype(loadStartPosObject()) {
	using FunctionType = decltype(loadStartPosObject())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1204b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::loadUpToPosition(float position, int order, int channel) -> decltype(loadUpToPosition(position, order, channel)) {
	using FunctionType = decltype(loadUpToPosition(position, order, channel))(*)(GJBaseGameLayer*, float, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x120650, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, position, order, channel);
}

auto GJBaseGameLayer::maxZOrderForShaderZ(int zLayer) -> decltype(maxZOrderForShaderZ(zLayer)) {
	using FunctionType = decltype(maxZOrderForShaderZ(zLayer))(*)(GJBaseGameLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x10e79c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, zLayer);
}

auto GJBaseGameLayer::minZOrderForShaderZ(int zLayer) -> decltype(minZOrderForShaderZ(zLayer)) {
	using FunctionType = decltype(minZOrderForShaderZ(zLayer))(*)(GJBaseGameLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1114b4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, zLayer);
}

auto GJBaseGameLayer::modifyGroupPhysics(AdvancedFollowEditObject* object, cocos2d::CCArray* group) -> decltype(modifyGroupPhysics(object, group)) {
	using FunctionType = decltype(modifyGroupPhysics(object, group))(*)(GJBaseGameLayer*, AdvancedFollowEditObject*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11b70c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, group);
}

auto GJBaseGameLayer::modifyObjectPhysics(AdvancedFollowEditObject* object, GameObjectPhysics& physics) -> decltype(modifyObjectPhysics(object, physics)) {
	using FunctionType = decltype(modifyObjectPhysics(object, physics))(*)(GJBaseGameLayer*, AdvancedFollowEditObject*, GameObjectPhysics&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11b84c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, physics);
}

auto GJBaseGameLayer::moveCameraToPos(cocos2d::CCPoint pos) -> decltype(moveCameraToPos(pos)) {
	using FunctionType = decltype(moveCameraToPos(pos))(*)(GJBaseGameLayer*, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x12ae2c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, pos);
}

auto GJBaseGameLayer::moveObject(GameObject* object, double dx, double dy, bool lockPlayerY) -> decltype(moveObject(object, dx, dy, lockPlayerY)) {
	using FunctionType = decltype(moveObject(object, dx, dy, lockPlayerY))(*)(GJBaseGameLayer*, GameObject*, double, double, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11af24, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, dx, dy, lockPlayerY);
}

auto GJBaseGameLayer::moveObjects(cocos2d::CCArray* objects, double dx, double dy, bool lockPlayerY) -> decltype(moveObjects(objects, dx, dy, lockPlayerY)) {
	using FunctionType = decltype(moveObjects(objects, dx, dy, lockPlayerY))(*)(GJBaseGameLayer*, cocos2d::CCArray*, double, double, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11acb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, objects, dx, dy, lockPlayerY);
}

auto GJBaseGameLayer::moveObjectsSilent(int groupId, double dx, double dy) -> decltype(moveObjectsSilent(groupId, dx, dy)) {
	using FunctionType = decltype(moveObjectsSilent(groupId, dx, dy))(*)(GJBaseGameLayer*, int, double, double);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x10d058, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, groupId, dx, dy);
}

auto GJBaseGameLayer::moveObjectToStaticGroup(GameObject* object) -> decltype(moveObjectToStaticGroup(object)) {
	using FunctionType = decltype(moveObjectToStaticGroup(object))(*)(GJBaseGameLayer*, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11d070, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJBaseGameLayer::objectIntersectsCircle(GameObject* object, GameObject* circle) -> decltype(objectIntersectsCircle(object, circle)) {
	using FunctionType = decltype(objectIntersectsCircle(object, circle))(*)(GJBaseGameLayer*, GameObject*, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xfbf74, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, circle);
}

auto GJBaseGameLayer::objectTypeToGameEvent(int type) -> decltype(objectTypeToGameEvent(type)) {
	using FunctionType = decltype(objectTypeToGameEvent(type))(*)(GJBaseGameLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xfd81c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type);
}

auto GJBaseGameLayer::optimizeMoveGroups() -> decltype(optimizeMoveGroups()) {
	using FunctionType = decltype(optimizeMoveGroups())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xf2284, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::orderSpawnObjects() -> decltype(orderSpawnObjects()) {
	using FunctionType = decltype(orderSpawnObjects())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x130134, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::parentForZLayer(int zLayer, bool blending, int parentMode, int uiObject) -> decltype(parentForZLayer(zLayer, blending, parentMode, uiObject)) {
	using FunctionType = decltype(parentForZLayer(zLayer, blending, parentMode, uiObject))(*)(GJBaseGameLayer*, int, bool, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xf86a8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, zLayer, blending, parentMode, uiObject);
}

auto GJBaseGameLayer::pauseAudio() -> decltype(pauseAudio()) {
	using FunctionType = decltype(pauseAudio())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x122888, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::performMathOperation(double operand1, double operand2, int operation) -> decltype(performMathOperation(operand1, operand2, operation)) {
	using FunctionType = decltype(performMathOperation(operand1, operand2, operation))(*)(GJBaseGameLayer*, double, double, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11ea90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, operand1, operand2, operation);
}

auto GJBaseGameLayer::performMathRounding(double value, int type) -> decltype(performMathRounding(value, type)) {
	using FunctionType = decltype(performMathRounding(value, type))(*)(GJBaseGameLayer*, double, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11eae0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, value, type);
}

auto GJBaseGameLayer::pickupItem(EffectGameObject* object) -> decltype(pickupItem(object)) {
	using FunctionType = decltype(pickupItem(object))(*)(GJBaseGameLayer*, EffectGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x100e40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJBaseGameLayer::playAnimationCommand(int id, int groupID) -> decltype(playAnimationCommand(id, groupID)) {
	using FunctionType = decltype(playAnimationCommand(id, groupID))(*)(GJBaseGameLayer*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1023a8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, groupID);
}

auto GJBaseGameLayer::playerCircleCollision(PlayerObject* player, GameObject* object) -> decltype(playerCircleCollision(player, object)) {
	using FunctionType = decltype(playerCircleCollision(player, object))(*)(GJBaseGameLayer*, PlayerObject*, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xfbe18, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, player, object);
}

auto GJBaseGameLayer::playerIntersectsCircle(PlayerObject* player, GameObject* object) -> decltype(playerIntersectsCircle(player, object)) {
	using FunctionType = decltype(playerIntersectsCircle(player, object))(*)(GJBaseGameLayer*, PlayerObject*, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xfbed0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, player, object);
}

auto GJBaseGameLayer::playerTouchedObject(PlayerObject* player, GameObject* object) -> decltype(playerTouchedObject(player, object)) {
	using FunctionType = decltype(playerTouchedObject(player, object))(*)(GJBaseGameLayer*, PlayerObject*, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1021c8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, player, object);
}

auto GJBaseGameLayer::playerTouchedRing(PlayerObject* player, RingObject* object) -> decltype(playerTouchedRing(player, object)) {
	using FunctionType = decltype(playerTouchedRing(player, object))(*)(GJBaseGameLayer*, PlayerObject*, RingObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x100904, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, player, object);
}

auto GJBaseGameLayer::playerTouchedTrigger(PlayerObject* player, EffectGameObject* object) -> decltype(playerTouchedTrigger(player, object)) {
	using FunctionType = decltype(playerTouchedTrigger(player, object))(*)(GJBaseGameLayer*, PlayerObject*, EffectGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1009c8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, player, object);
}

auto GJBaseGameLayer::playerWasTouchingObject(PlayerObject* player, GameObject* object) -> decltype(playerWasTouchingObject(player, object)) {
	using FunctionType = decltype(playerWasTouchingObject(player, object))(*)(GJBaseGameLayer*, PlayerObject*, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x102170, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, player, object);
}

auto GJBaseGameLayer::playerWillSwitchMode(PlayerObject* player, GameObject* object) -> decltype(playerWillSwitchMode(player, object)) {
	using FunctionType = decltype(playerWillSwitchMode(player, object))(*)(GJBaseGameLayer*, PlayerObject*, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xfd58c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, player, object);
}

auto GJBaseGameLayer::playExitDualEffect(PlayerObject* player) -> decltype(playExitDualEffect(player)) {
	using FunctionType = decltype(playExitDualEffect(player))(*)(GJBaseGameLayer*, PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x101a70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, player);
}

auto GJBaseGameLayer::playFlashEffect(float duration, int flashes, float unknown) -> decltype(playFlashEffect(duration, flashes, unknown)) {
	using FunctionType = decltype(playFlashEffect(duration, flashes, unknown))(*)(GJBaseGameLayer*, float, int, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1312a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, duration, flashes, unknown);
}

auto GJBaseGameLayer::playKeyframeAnimation(KeyframeAnimTriggerObject* object, gd::vector<int> const& remapKeys) -> decltype(playKeyframeAnimation(object, remapKeys)) {
	using FunctionType = decltype(playKeyframeAnimation(object, remapKeys))(*)(GJBaseGameLayer*, KeyframeAnimTriggerObject*, gd::vector<int> const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x102478, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, remapKeys);
}

auto GJBaseGameLayer::playSpeedParticle(float timeMod) -> decltype(playSpeedParticle(timeMod)) {
	using FunctionType = decltype(playSpeedParticle(timeMod))(*)(GJBaseGameLayer*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x12bb74, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, timeMod);
}

auto GJBaseGameLayer::positionForShaderTarget(int groupID) -> decltype(positionForShaderTarget(groupID)) {
	using FunctionType = decltype(positionForShaderTarget(groupID))(*)(GJBaseGameLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x111170, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, groupID);
}

auto GJBaseGameLayer::positionUIObjects() -> decltype(positionUIObjects()) {
	using FunctionType = decltype(positionUIObjects())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xf58d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::prepareSavePositionObjects() -> decltype(prepareSavePositionObjects()) {
	using FunctionType = decltype(prepareSavePositionObjects())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xf2b2c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::prepareTransformParent(bool rotateNode) -> decltype(prepareTransformParent(rotateNode)) {
	using FunctionType = decltype(prepareTransformParent(rotateNode))(*)(GJBaseGameLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x117f2c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, rotateNode);
}

auto GJBaseGameLayer::preResumeGame() -> decltype(preResumeGame()) {
	using FunctionType = decltype(preResumeGame())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x12287c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::preUpdateVisibility(float dt) -> decltype(preUpdateVisibility(dt)) {
	using FunctionType = decltype(preUpdateVisibility(dt))(*)(GJBaseGameLayer*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1211a4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt);
}

auto GJBaseGameLayer::processActivatedAudioTriggers(float levelTime) -> decltype(processActivatedAudioTriggers(levelTime)) {
	using FunctionType = decltype(processActivatedAudioTriggers(levelTime))(*)(GJBaseGameLayer*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x12ebc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, levelTime);
}

auto GJBaseGameLayer::processAdvancedFollowAction(AdvancedFollowInstance& instance, bool started, float dt) -> decltype(processAdvancedFollowAction(instance, started, dt)) {
	using FunctionType = decltype(processAdvancedFollowAction(instance, started, dt))(*)(GJBaseGameLayer*, AdvancedFollowInstance&, bool, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11b934, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, instance, started, dt);
}

auto GJBaseGameLayer::processAdvancedFollowActions(float dt) -> decltype(processAdvancedFollowActions(dt)) {
	using FunctionType = decltype(processAdvancedFollowActions(dt))(*)(GJBaseGameLayer*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x119fd4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt);
}

auto GJBaseGameLayer::processAreaActions(float dt, bool visibleFrame) -> decltype(processAreaActions(dt, visibleFrame)) {
	using FunctionType = decltype(processAreaActions(dt, visibleFrame))(*)(GJBaseGameLayer*, float, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1172c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt, visibleFrame);
}

auto GJBaseGameLayer::processAreaEffects(gd::vector<EnterEffectInstance>* effects, GJAreaActionType type, float dt, bool visibleFrame) -> decltype(processAreaEffects(effects, type, dt, visibleFrame)) {
	using FunctionType = decltype(processAreaEffects(effects, type, dt, visibleFrame))(*)(GJBaseGameLayer*, gd::vector<EnterEffectInstance>*, GJAreaActionType, float, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x114c54, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, effects, type, dt, visibleFrame);
}

auto GJBaseGameLayer::processAreaFadeGroupAction(cocos2d::CCArray* objects, EnterEffectInstance* instance, cocos2d::CCPoint position, bool targetGroups) -> decltype(processAreaFadeGroupAction(objects, instance, position, targetGroups)) {
	using FunctionType = decltype(processAreaFadeGroupAction(objects, instance, position, targetGroups))(*)(GJBaseGameLayer*, cocos2d::CCArray*, EnterEffectInstance*, cocos2d::CCPoint, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11682c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, objects, instance, position, targetGroups);
}

auto GJBaseGameLayer::processAreaMoveGroupAction(cocos2d::CCArray* objects, EnterEffectInstance* instance, cocos2d::CCPoint position, int outerMin, int outerMax, int middleMin, int middleMax, int startIndex, bool targetGroups, bool reset) -> decltype(processAreaMoveGroupAction(objects, instance, position, outerMin, outerMax, middleMin, middleMax, startIndex, targetGroups, reset)) {
	using FunctionType = decltype(processAreaMoveGroupAction(objects, instance, position, outerMin, outerMax, middleMin, middleMax, startIndex, targetGroups, reset))(*)(GJBaseGameLayer*, cocos2d::CCArray*, EnterEffectInstance*, cocos2d::CCPoint, int, int, int, int, int, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x116254, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, objects, instance, position, outerMin, outerMax, middleMin, middleMax, startIndex, targetGroups, reset);
}

auto GJBaseGameLayer::processAreaRotateGroupAction(cocos2d::CCArray* objects, EnterEffectInstance* instance, cocos2d::CCPoint position, int outerMin, int outerMax, int middleMin, int middleMax, int startIndex, bool targetGroups, bool reset) -> decltype(processAreaRotateGroupAction(objects, instance, position, outerMin, outerMax, middleMin, middleMax, startIndex, targetGroups, reset)) {
	using FunctionType = decltype(processAreaRotateGroupAction(objects, instance, position, outerMin, outerMax, middleMin, middleMax, startIndex, targetGroups, reset))(*)(GJBaseGameLayer*, cocos2d::CCArray*, EnterEffectInstance*, cocos2d::CCPoint, int, int, int, int, int, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x115f74, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, objects, instance, position, outerMin, outerMax, middleMin, middleMax, startIndex, targetGroups, reset);
}

auto GJBaseGameLayer::processAreaTintGroupAction(cocos2d::CCArray* objects, EnterEffectInstance* instance, cocos2d::CCPoint position, bool targetGroups) -> decltype(processAreaTintGroupAction(objects, instance, position, targetGroups)) {
	using FunctionType = decltype(processAreaTintGroupAction(objects, instance, position, targetGroups))(*)(GJBaseGameLayer*, cocos2d::CCArray*, EnterEffectInstance*, cocos2d::CCPoint, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x116a18, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, objects, instance, position, targetGroups);
}

auto GJBaseGameLayer::processAreaTransformGroupAction(cocos2d::CCArray* objects, EnterEffectInstance* instance, cocos2d::CCPoint position, int outerMin, int outerMax, int middleMin, int middleMax, int startIndex, bool targetGroups, bool reset) -> decltype(processAreaTransformGroupAction(objects, instance, position, outerMin, outerMax, middleMin, middleMax, startIndex, targetGroups, reset)) {
	using FunctionType = decltype(processAreaTransformGroupAction(objects, instance, position, outerMin, outerMax, middleMin, middleMax, startIndex, targetGroups, reset))(*)(GJBaseGameLayer*, cocos2d::CCArray*, EnterEffectInstance*, cocos2d::CCPoint, int, int, int, int, int, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x115b74, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, objects, instance, position, outerMin, outerMax, middleMin, middleMax, startIndex, targetGroups, reset);
}

auto GJBaseGameLayer::processAreaVisualActions(float dt) -> decltype(processAreaVisualActions(dt)) {
	using FunctionType = decltype(processAreaVisualActions(dt))(*)(GJBaseGameLayer*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1176bc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt);
}

auto GJBaseGameLayer::processCameraObject(GameObject* object, PlayerObject* player) -> decltype(processCameraObject(object, player)) {
	using FunctionType = decltype(processCameraObject(object, player))(*)(GJBaseGameLayer*, GameObject*, PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xfc0d4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, player);
}

auto GJBaseGameLayer::processCommands(float dt, bool isHalfTick, bool isLastTick) -> decltype(processCommands(dt, isHalfTick, isLastTick)) {
	using FunctionType = decltype(processCommands(dt, isHalfTick, isLastTick))(*)(GJBaseGameLayer*, float, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x124490, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt, isHalfTick, isLastTick);
}

auto GJBaseGameLayer::processDynamicObjectActions(int type, float dt) -> decltype(processDynamicObjectActions(type, dt)) {
	using FunctionType = decltype(processDynamicObjectActions(type, dt))(*)(GJBaseGameLayer*, int, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x118490, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type, dt);
}

auto GJBaseGameLayer::processFollowActions() -> decltype(processFollowActions()) {
	using FunctionType = decltype(processFollowActions())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11a19c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::processItems() -> decltype(processItems()) {
	using FunctionType = decltype(processItems())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1017d4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::processMoveActions() -> decltype(processMoveActions()) {
	using FunctionType = decltype(processMoveActions())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x119c0c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::processMoveActionsStep(float dt, bool visibleFrame) -> decltype(processMoveActionsStep(dt, visibleFrame)) {
	using FunctionType = decltype(processMoveActionsStep(dt, visibleFrame))(*)(GJBaseGameLayer*, float, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x118368, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt, visibleFrame);
}

auto GJBaseGameLayer::processOptionsTrigger(GameOptionsTrigger* object) -> decltype(processOptionsTrigger(object)) {
	using FunctionType = decltype(processOptionsTrigger(object))(*)(GJBaseGameLayer*, GameOptionsTrigger*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1119b4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJBaseGameLayer::processPlayerFollowActions(float dt) -> decltype(processPlayerFollowActions(dt)) {
	using FunctionType = decltype(processPlayerFollowActions(dt))(*)(GJBaseGameLayer*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x119d98, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt);
}

auto GJBaseGameLayer::processQueuedAudioTriggers() -> decltype(processQueuedAudioTriggers()) {
	using FunctionType = decltype(processQueuedAudioTriggers())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x12996c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::processQueuedButtons(float dt, bool clearInputQueue) -> decltype(processQueuedButtons(dt, clearInputQueue)) {
	using FunctionType = decltype(processQueuedButtons(dt, clearInputQueue))(*)(GJBaseGameLayer*, float, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11d44c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt, clearInputQueue);
}

auto GJBaseGameLayer::processReplayCheckpoint(int id) -> decltype(processReplayCheckpoint(id)) {
	using FunctionType = decltype(processReplayCheckpoint(id))(*)(GJBaseGameLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x126cec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GJBaseGameLayer::processRotationActions() -> decltype(processRotationActions()) {
	using FunctionType = decltype(processRotationActions())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x119470, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::processSFXObjects() -> decltype(processSFXObjects()) {
	using FunctionType = decltype(processSFXObjects())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xf68e8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::processSFXState(SFXTriggerState* state1, SFXTriggerState* state2, int type, float levelTime) -> decltype(processSFXState(state1, state2, type, levelTime)) {
	using FunctionType = decltype(processSFXState(state1, state2, type, levelTime))(*)(GJBaseGameLayer*, SFXTriggerState*, SFXTriggerState*, int, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x12e65c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, state1, state2, type, levelTime);
}

auto GJBaseGameLayer::processSongState(int musicID, float spawnDelay, float levelTime, int songOffset, float volume, float speed, gd::vector<SongTriggerState>* states, SongTriggerGameObject* object) -> decltype(processSongState(musicID, spawnDelay, levelTime, songOffset, volume, speed, states, object)) {
	using FunctionType = decltype(processSongState(musicID, spawnDelay, levelTime, songOffset, volume, speed, states, object))(*)(GJBaseGameLayer*, int, float, float, int, float, float, gd::vector<SongTriggerState>*, SongTriggerGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x12fcd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, musicID, spawnDelay, levelTime, songOffset, volume, speed, states, object);
}

auto GJBaseGameLayer::processStateObjects() -> decltype(processStateObjects()) {
	using FunctionType = decltype(processStateObjects())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1028b8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::processTransformActions(bool visibleFrame) -> decltype(processTransformActions(visibleFrame)) {
	using FunctionType = decltype(processTransformActions(visibleFrame))(*)(GJBaseGameLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x118960, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, visibleFrame);
}

auto GJBaseGameLayer::queueButton(int button, bool push, bool isPlayer2, double timestamp) -> decltype(queueButton(button, push, isPlayer2, timestamp)) {
	using FunctionType = decltype(queueButton(button, push, isPlayer2, timestamp))(*)(GJBaseGameLayer*, int, bool, bool, double);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11d2d8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, button, push, isPlayer2, timestamp);
}

auto GJBaseGameLayer::queueTimeWarp(float timeWarp) -> decltype(queueTimeWarp(timeWarp)) {
	using FunctionType = decltype(queueTimeWarp(timeWarp))(*)(GJBaseGameLayer*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x121104, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, timeWarp);
}

auto GJBaseGameLayer::reAddToStickyGroup(GameObject* object) -> decltype(reAddToStickyGroup(object)) {
	using FunctionType = decltype(reAddToStickyGroup(object))(*)(GJBaseGameLayer*, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x112e18, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJBaseGameLayer::recordAction(int button, bool down, bool player2) -> decltype(recordAction(button, down, player2)) {
	using FunctionType = decltype(recordAction(button, down, player2))(*)(GJBaseGameLayer*, int, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11deec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, button, down, player2);
}

auto GJBaseGameLayer::rectIntersectsCircle(cocos2d::CCRect rect, cocos2d::CCPoint center, float radius) -> decltype(rectIntersectsCircle(rect, center, radius)) {
	using FunctionType = decltype(rectIntersectsCircle(rect, center, radius))(*)(GJBaseGameLayer*, cocos2d::CCRect, cocos2d::CCPoint, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xfbae4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, rect, center, radius);
}

auto GJBaseGameLayer::refreshCounterLabels() -> decltype(refreshCounterLabels()) {
	using FunctionType = decltype(refreshCounterLabels())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x120068, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::refreshKeyframeAnims() -> decltype(refreshKeyframeAnims()) {
	using FunctionType = decltype(refreshKeyframeAnims())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xf6718, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::regenerateEnterEasingBuffers() -> decltype(regenerateEnterEasingBuffers()) {
	using FunctionType = decltype(regenerateEnterEasingBuffers())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xf1ea4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::registerSpawnRemap(gd::vector<ChanceObject>& spawnRemap) -> decltype(registerSpawnRemap(spawnRemap)) {
	using FunctionType = decltype(registerSpawnRemap(spawnRemap))(*)(GJBaseGameLayer*, gd::vector<ChanceObject>&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x10af04, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, spawnRemap);
}

auto GJBaseGameLayer::registerStateObject(EffectGameObject* object) -> decltype(registerStateObject(object)) {
	using FunctionType = decltype(registerStateObject(object))(*)(GJBaseGameLayer*, EffectGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x102864, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJBaseGameLayer::removeBackground() -> decltype(removeBackground()) {
	using FunctionType = decltype(removeBackground())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xef390, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::removeCustomEnterEffects(int id, bool enter) -> decltype(removeCustomEnterEffects(id, enter)) {
	using FunctionType = decltype(removeCustomEnterEffects(id, enter))(*)(GJBaseGameLayer*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xf75b4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, enter);
}

auto GJBaseGameLayer::removeFromGroupParents(GameObject* object) -> decltype(removeFromGroupParents(object)) {
	using FunctionType = decltype(removeFromGroupParents(object))(*)(GJBaseGameLayer*, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x112508, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJBaseGameLayer::removeFromGroups(GameObject* object) -> decltype(removeFromGroups(object)) {
	using FunctionType = decltype(removeFromGroups(object))(*)(GJBaseGameLayer*, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x111ea0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJBaseGameLayer::removeFromStickyGroup(GameObject* object) -> decltype(removeFromStickyGroup(object)) {
	using FunctionType = decltype(removeFromStickyGroup(object))(*)(GJBaseGameLayer*, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x112d8c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJBaseGameLayer::removeGroundLayer() -> decltype(removeGroundLayer()) {
	using FunctionType = decltype(removeGroundLayer())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xefa40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::removeGroupParent(int groupID) -> decltype(removeGroupParent(groupID)) {
	using FunctionType = decltype(removeGroupParent(groupID))(*)(GJBaseGameLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11207c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, groupID);
}

auto GJBaseGameLayer::removeKeyframe(KeyframeGameObject* object) -> decltype(removeKeyframe(object)) {
	using FunctionType = decltype(removeKeyframe(object))(*)(GJBaseGameLayer*, KeyframeGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11e1dc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJBaseGameLayer::removeMiddleground() -> decltype(removeMiddleground()) {
	using FunctionType = decltype(removeMiddleground())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xefa0c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::removeObjectFromSection(GameObject* object) -> decltype(removeObjectFromSection(object)) {
	using FunctionType = decltype(removeObjectFromSection(object))(*)(GJBaseGameLayer*, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x113250, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJBaseGameLayer::removePlayer2() -> decltype(removePlayer2()) {
	using FunctionType = decltype(removePlayer2())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x101ef0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::removeReleasedButtons() -> decltype(removeReleasedButtons()) {
	using FunctionType = decltype(removeReleasedButtons())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11d1a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::removeTemporaryParticles() -> decltype(removeTemporaryParticles()) {
	using FunctionType = decltype(removeTemporaryParticles())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x129538, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::reorderObjectSection(GameObject* object) -> decltype(reorderObjectSection(object)) {
	using FunctionType = decltype(reorderObjectSection(object))(*)(GJBaseGameLayer*, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x102f38, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJBaseGameLayer::reparentObject(cocos2d::CCNode* node, cocos2d::CCNode* parent) -> decltype(reparentObject(node, parent)) {
	using FunctionType = decltype(reparentObject(node, parent))(*)(GJBaseGameLayer*, cocos2d::CCNode*, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x111408, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, node, parent);
}

auto GJBaseGameLayer::resetActiveEnterEffects() -> decltype(resetActiveEnterEffects()) {
	using FunctionType = decltype(resetActiveEnterEffects())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xf6e4c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::resetAreaObjectValues(GameObject* object, bool update) -> decltype(resetAreaObjectValues(object, update)) {
	using FunctionType = decltype(resetAreaObjectValues(object, update))(*)(GJBaseGameLayer*, GameObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x115854, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, update);
}

auto GJBaseGameLayer::resetAudio() -> decltype(resetAudio()) {
	using FunctionType = decltype(resetAudio())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1228dc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::resetCamera() -> decltype(resetCamera()) {
	using FunctionType = decltype(resetCamera())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1295f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::resetGradientLayers() -> decltype(resetGradientLayers()) {
	using FunctionType = decltype(resetGradientLayers())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x10e5f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::resetGroupCounters(bool reset) -> decltype(resetGroupCounters(reset)) {
	using FunctionType = decltype(resetGroupCounters(reset))(*)(GJBaseGameLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1202f8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, reset);
}

auto GJBaseGameLayer::resetLevelVariables() -> decltype(resetLevelVariables()) {
	using FunctionType = decltype(resetLevelVariables())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x128b88, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::resetMoveOptimizedValue() -> decltype(resetMoveOptimizedValue()) {
	using FunctionType = decltype(resetMoveOptimizedValue())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11d030, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::resetPlayer() -> decltype(resetPlayer()) {
	using FunctionType = decltype(resetPlayer())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xfc15c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::resetRecord(int steps, bool noFullReset) -> decltype(resetRecord(steps, noFullReset)) {
	using FunctionType = decltype(resetRecord(steps, noFullReset))(*)(GJBaseGameLayer*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x126d7c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, steps, noFullReset);
}

auto GJBaseGameLayer::resetRecordFull() -> decltype(resetRecordFull()) {
	using FunctionType = decltype(resetRecordFull())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x126cf0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::resetSongTriggerValues() -> decltype(resetSongTriggerValues()) {
	using FunctionType = decltype(resetSongTriggerValues())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x120928, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::resetSpawnChannelIndex() -> decltype(resetSpawnChannelIndex()) {
	using FunctionType = decltype(resetSpawnChannelIndex())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1298a8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::resetStaticCamera(bool resetX, bool resetY) -> decltype(resetStaticCamera(resetX, resetY)) {
	using FunctionType = decltype(resetStaticCamera(resetX, resetY))(*)(GJBaseGameLayer*, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xfdf24, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, resetX, resetY);
}

auto GJBaseGameLayer::resetStoppedAreaObjects() -> decltype(resetStoppedAreaObjects()) {
	using FunctionType = decltype(resetStoppedAreaObjects())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x117600, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::restoreAllUIObjects() -> decltype(restoreAllUIObjects()) {
	using FunctionType = decltype(restoreAllUIObjects())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1133d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::restoreDefaultGameplayOffsetX() -> decltype(restoreDefaultGameplayOffsetX()) {
	using FunctionType = decltype(restoreDefaultGameplayOffsetX())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x120ffc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::restoreDefaultGameplayOffsetY() -> decltype(restoreDefaultGameplayOffsetY()) {
	using FunctionType = decltype(restoreDefaultGameplayOffsetY())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x121018, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::restoreRemap(EffectGameObject* object, gd::unordered_map<int, int>& remap) -> decltype(restoreRemap(object, remap)) {
	using FunctionType = decltype(restoreRemap(object, remap))(*)(GJBaseGameLayer*, EffectGameObject*, gd::unordered_map<int, int>&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x109338, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, remap);
}

auto GJBaseGameLayer::resumeAudio() -> decltype(resumeAudio()) {
	using FunctionType = decltype(resumeAudio())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1228b4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::rotateAreaObjects(GameObject* object, cocos2d::CCArray* objects, float rotation, bool reset) -> decltype(rotateAreaObjects(object, objects, rotation, reset)) {
	using FunctionType = decltype(rotateAreaObjects(object, objects, rotation, reset))(*)(GJBaseGameLayer*, GameObject*, cocos2d::CCArray*, float, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x117f90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, objects, rotation, reset);
}

auto GJBaseGameLayer::rotateObject(GameObject* object, float rotation) -> decltype(rotateObject(object, rotation)) {
	using FunctionType = decltype(rotateObject(object, rotation))(*)(GJBaseGameLayer*, GameObject*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11a7f4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, rotation);
}

auto GJBaseGameLayer::rotateObjects(cocos2d::CCArray* objects, float rotation, cocos2d::CCPoint position, cocos2d::CCPoint offset, bool finished, bool unused) -> decltype(rotateObjects(objects, rotation, position, offset, finished, unused)) {
	using FunctionType = decltype(rotateObjects(objects, rotation, position, offset, finished, unused))(*)(GJBaseGameLayer*, cocos2d::CCArray*, float, cocos2d::CCPoint, cocos2d::CCPoint, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11a870, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, objects, rotation, position, offset, finished, unused);
}

auto GJBaseGameLayer::setGroupParent(GameObject* object, int groupID) -> decltype(setGroupParent(object, groupID)) {
	using FunctionType = decltype(setGroupParent(object, groupID))(*)(GJBaseGameLayer*, GameObject*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1123c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, groupID);
}

auto GJBaseGameLayer::setStartPosObject(StartPosObject* startPos) -> decltype(setStartPosObject(startPos)) {
	using FunctionType = decltype(setStartPosObject(startPos))(*)(GJBaseGameLayer*, StartPosObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xfc3c8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, startPos);
}

auto GJBaseGameLayer::setupLayers() -> decltype(setupLayers()) {
	using FunctionType = decltype(setupLayers())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xec740, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::setupLevelStart(LevelSettingsObject* settings) -> decltype(setupLevelStart(settings)) {
	using FunctionType = decltype(setupLevelStart(settings))(*)(GJBaseGameLayer*, LevelSettingsObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xfc410, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, settings);
}

auto GJBaseGameLayer::setupReplay(gd::string inputs) -> decltype(setupReplay(inputs)) {
	using FunctionType = decltype(setupReplay(inputs))(*)(GJBaseGameLayer*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x127220, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, inputs);
}

auto GJBaseGameLayer::shakeCamera(float duration, float strength, float interval) -> decltype(shakeCamera(duration, strength, interval)) {
	using FunctionType = decltype(shakeCamera(duration, strength, interval))(*)(GJBaseGameLayer*, float, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x12a4c4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, duration, strength, interval);
}

auto GJBaseGameLayer::shouldExitHackedLevel() -> decltype(shouldExitHackedLevel()) {
	using FunctionType = decltype(shouldExitHackedLevel())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xeec54, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::shouldUseSubstepForButton(float dt) -> decltype(shouldUseSubstepForButton(dt)) {
	using FunctionType = decltype(shouldUseSubstepForButton(dt))(*)(GJBaseGameLayer*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11d790, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt);
}

auto GJBaseGameLayer::sortAllGroupsX() -> decltype(sortAllGroupsX()) {
	using FunctionType = decltype(sortAllGroupsX())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1121f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::sortGroups() -> decltype(sortGroups()) {
	using FunctionType = decltype(sortGroups())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xf1f80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::sortSectionVector() -> decltype(sortSectionVector()) {
	using FunctionType = decltype(sortSectionVector())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x114058, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::sortStickyGroups() -> decltype(sortStickyGroups()) {
	using FunctionType = decltype(sortStickyGroups())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xf4234, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::spawnGroupTriggered(int targetID, float delay, bool spawnOrdered, gd::vector<int> const& remapKeys, int uniqueID, int controlID) -> decltype(spawnGroupTriggered(targetID, delay, spawnOrdered, remapKeys, uniqueID, controlID)) {
	using FunctionType = decltype(spawnGroupTriggered(targetID, delay, spawnOrdered, remapKeys, uniqueID, controlID))(*)(GJBaseGameLayer*, int, float, bool, gd::vector<int> const&, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x104900, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, targetID, delay, spawnOrdered, remapKeys, uniqueID, controlID);
}

auto GJBaseGameLayer::spawnObjectsInOrder(cocos2d::CCArray* objects, double delay, gd::vector<int> const& remapKeys, int uniqueID, int controlID) -> decltype(spawnObjectsInOrder(objects, delay, remapKeys, uniqueID, controlID)) {
	using FunctionType = decltype(spawnObjectsInOrder(objects, delay, remapKeys, uniqueID, controlID))(*)(GJBaseGameLayer*, cocos2d::CCArray*, double, gd::vector<int> const&, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x104c54, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, objects, delay, remapKeys, uniqueID, controlID);
}

auto GJBaseGameLayer::spawnParticle(char const* plist, int zOrder, cocos2d::tCCPositionType positionType, cocos2d::CCPoint position) -> decltype(spawnParticle(plist, zOrder, positionType, position)) {
	using FunctionType = decltype(spawnParticle(plist, zOrder, positionType, position))(*)(GJBaseGameLayer*, char const*, int, cocos2d::tCCPositionType, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x12ba9c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, plist, zOrder, positionType, position);
}

auto GJBaseGameLayer::spawnParticleTrigger(SpawnParticleGameObject* object) -> decltype(spawnParticleTrigger(object)) {
	using FunctionType = decltype(spawnParticleTrigger(object))(*)(GJBaseGameLayer*, SpawnParticleGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x12b938, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJBaseGameLayer::spawnParticleTrigger(int particleID, cocos2d::CCPoint position, float rotation, float scale) -> decltype(spawnParticleTrigger(particleID, position, rotation, scale)) {
	using FunctionType = decltype(spawnParticleTrigger(particleID, position, rotation, scale))(*)(GJBaseGameLayer*, int, cocos2d::CCPoint, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x100f54, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, particleID, position, rotation, scale);
}

auto GJBaseGameLayer::spawnPlayer2() -> decltype(spawnPlayer2()) {
	using FunctionType = decltype(spawnPlayer2())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1019f4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::speedForShaderTarget(int groupID) -> decltype(speedForShaderTarget(groupID)) {
	using FunctionType = decltype(speedForShaderTarget(groupID))(*)(GJBaseGameLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11129c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, groupID);
}

auto GJBaseGameLayer::staticObjectsInRect(cocos2d::CCRect rect, bool enabledGroups) -> decltype(staticObjectsInRect(rect, enabledGroups)) {
	using FunctionType = decltype(staticObjectsInRect(rect, enabledGroups))(*)(GJBaseGameLayer*, cocos2d::CCRect, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xfb0b4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, rect, enabledGroups);
}

auto GJBaseGameLayer::stopAllGroundActions() -> decltype(stopAllGroundActions()) {
	using FunctionType = decltype(stopAllGroundActions())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xfdfe0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::stopCameraShake() -> decltype(stopCameraShake()) {
	using FunctionType = decltype(stopCameraShake())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x12a548, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::stopCustomEnterEffect(EnterEffectObject* object) -> decltype(stopCustomEnterEffect(object)) {
	using FunctionType = decltype(stopCustomEnterEffect(object))(*)(GJBaseGameLayer*, EnterEffectObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xf7938, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJBaseGameLayer::stopCustomEnterEffect(EnterEffectObject* object, bool enter) -> decltype(stopCustomEnterEffect(object, enter)) {
	using FunctionType = decltype(stopCustomEnterEffect(object, enter))(*)(GJBaseGameLayer*, EnterEffectObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xf798c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, enter);
}

auto GJBaseGameLayer::stopSFXTrigger(SFXTriggerGameObject* object) -> decltype(stopSFXTrigger(object)) {
	using FunctionType = decltype(stopSFXTrigger(object))(*)(GJBaseGameLayer*, SFXTriggerGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x10b9c4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJBaseGameLayer::swapBackground(int background) -> decltype(swapBackground(background)) {
	using FunctionType = decltype(swapBackground(background))(*)(GJBaseGameLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xef3c4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, background);
}

auto GJBaseGameLayer::swapGround(int ground) -> decltype(swapGround(ground)) {
	using FunctionType = decltype(swapGround(ground))(*)(GJBaseGameLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xef6a4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, ground);
}

auto GJBaseGameLayer::swapMiddleground(int middleground) -> decltype(swapMiddleground(middleground)) {
	using FunctionType = decltype(swapMiddleground(middleground))(*)(GJBaseGameLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xef7f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, middleground);
}

auto GJBaseGameLayer::switchToFlyMode(PlayerObject* player, GameObject* object, bool noPortal, int type) -> decltype(switchToFlyMode(player, object, noPortal, type)) {
	using FunctionType = decltype(switchToFlyMode(player, object, noPortal, type))(*)(GJBaseGameLayer*, PlayerObject*, GameObject*, bool, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xfcebc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, player, object, noPortal, type);
}

auto GJBaseGameLayer::switchToRobotMode(PlayerObject* player, GameObject* object, bool noPortal) -> decltype(switchToRobotMode(player, object, noPortal)) {
	using FunctionType = decltype(switchToRobotMode(player, object, noPortal))(*)(GJBaseGameLayer*, PlayerObject*, GameObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xfd0b4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, player, object, noPortal);
}

auto GJBaseGameLayer::switchToRollMode(PlayerObject* player, GameObject* object, bool noPortal) -> decltype(switchToRollMode(player, object, noPortal)) {
	using FunctionType = decltype(switchToRollMode(player, object, noPortal))(*)(GJBaseGameLayer*, PlayerObject*, GameObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xfd008, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, player, object, noPortal);
}

auto GJBaseGameLayer::switchToSpiderMode(PlayerObject* player, GameObject* object, bool noPortal) -> decltype(switchToSpiderMode(player, object, noPortal)) {
	using FunctionType = decltype(switchToSpiderMode(player, object, noPortal))(*)(GJBaseGameLayer*, PlayerObject*, GameObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xfd160, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, player, object, noPortal);
}

auto GJBaseGameLayer::syncBGTextures() -> decltype(syncBGTextures()) {
	using FunctionType = decltype(syncBGTextures())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x128a70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::teleportPlayer(TeleportPortalObject* object, PlayerObject* player) -> decltype(teleportPlayer(object, player)) {
	using FunctionType = decltype(teleportPlayer(object, player))(*)(GJBaseGameLayer*, TeleportPortalObject*, PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xf99d8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, player);
}

auto GJBaseGameLayer::testInstantCountTrigger(int itemID, int compareCount, int groupID, bool activateGroup, int triggerMode, gd::vector<int> const& remapKeys, int uniqueID, int controlID) -> decltype(testInstantCountTrigger(itemID, compareCount, groupID, activateGroup, triggerMode, remapKeys, uniqueID, controlID)) {
	using FunctionType = decltype(testInstantCountTrigger(itemID, compareCount, groupID, activateGroup, triggerMode, remapKeys, uniqueID, controlID))(*)(GJBaseGameLayer*, int, int, int, bool, int, gd::vector<int> const&, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11e350, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, itemID, compareCount, groupID, activateGroup, triggerMode, remapKeys, uniqueID, controlID);
}

auto GJBaseGameLayer::toggleAudioVisualizer(bool visible) -> decltype(toggleAudioVisualizer(visible)) {
	using FunctionType = decltype(toggleAudioVisualizer(visible))(*)(GJBaseGameLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xec5dc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, visible);
}

auto GJBaseGameLayer::toggleDualMode(GameObject* object, bool dual, PlayerObject* player, bool noEffects) -> decltype(toggleDualMode(object, dual, player, noEffects)) {
	using FunctionType = decltype(toggleDualMode(object, dual, player, noEffects))(*)(GJBaseGameLayer*, GameObject*, bool, PlayerObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xfcb94, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, dual, player, noEffects);
}

auto GJBaseGameLayer::toggleFlipped(bool flip, bool noEffects) -> decltype(toggleFlipped(flip, noEffects)) {
	using FunctionType = decltype(toggleFlipped(flip, noEffects))(*)(GJBaseGameLayer*, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x100308, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, flip, noEffects);
}

auto GJBaseGameLayer::toggleGroup(int id, bool activate) -> decltype(toggleGroup(id, activate)) {
	using FunctionType = decltype(toggleGroup(id, activate))(*)(GJBaseGameLayer*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11181c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, activate);
}

auto GJBaseGameLayer::toggleLockPlayer(bool disable, bool player2) -> decltype(toggleLockPlayer(disable, player2)) {
	using FunctionType = decltype(toggleLockPlayer(disable, player2))(*)(GJBaseGameLayer*, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x111c10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, disable, player2);
}

auto GJBaseGameLayer::togglePlayerStreakBlend(bool blend, bool force) -> decltype(togglePlayerStreakBlend(blend, force)) {
	using FunctionType = decltype(togglePlayerStreakBlend(blend, force))(*)(GJBaseGameLayer*, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x111b98, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, blend, force);
}

auto GJBaseGameLayer::togglePlayerVisibility(bool visible) -> decltype(togglePlayerVisibility(visible)) {
	using FunctionType = decltype(togglePlayerVisibility(visible))(*)(GJBaseGameLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x120964, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, visible);
}

auto GJBaseGameLayer::togglePlayerVisibility(bool visible, bool player1) -> decltype(togglePlayerVisibility(visible, player1)) {
	using FunctionType = decltype(togglePlayerVisibility(visible, player1))(*)(GJBaseGameLayer*, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x111be4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, visible, player1);
}

auto GJBaseGameLayer::transformAreaObjects(GameObject* object, cocos2d::CCArray* objects, float scaleX, float scaleY, bool reset) -> decltype(transformAreaObjects(object, objects, scaleX, scaleY, reset)) {
	using FunctionType = decltype(transformAreaObjects(object, objects, scaleX, scaleY, reset))(*)(GJBaseGameLayer*, GameObject*, cocos2d::CCArray*, float, float, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x117a40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, objects, scaleX, scaleY, reset);
}

auto GJBaseGameLayer::triggerAdvancedFollowCommand(AdvancedFollowTriggerObject* object) -> decltype(triggerAdvancedFollowCommand(object)) {
	using FunctionType = decltype(triggerAdvancedFollowCommand(object))(*)(GJBaseGameLayer*, AdvancedFollowTriggerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x10df1c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJBaseGameLayer::triggerAdvancedFollowEditCommand(AdvancedFollowEditObject* object) -> decltype(triggerAdvancedFollowEditCommand(object)) {
	using FunctionType = decltype(triggerAdvancedFollowEditCommand(object))(*)(GJBaseGameLayer*, AdvancedFollowEditObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11b100, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJBaseGameLayer::triggerAreaEffect(EnterEffectObject* object) -> decltype(triggerAreaEffect(object)) {
	using FunctionType = decltype(triggerAreaEffect(object))(*)(GJBaseGameLayer*, EnterEffectObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1142f4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJBaseGameLayer::triggerAreaEffectAnimation(EnterEffectObject* object) -> decltype(triggerAreaEffectAnimation(object)) {
	using FunctionType = decltype(triggerAreaEffectAnimation(object))(*)(GJBaseGameLayer*, EnterEffectObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1146c8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJBaseGameLayer::triggerDynamicMoveCommand(EffectGameObject* object) -> decltype(triggerDynamicMoveCommand(object)) {
	using FunctionType = decltype(triggerDynamicMoveCommand(object))(*)(GJBaseGameLayer*, EffectGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x10cf74, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJBaseGameLayer::triggerDynamicRotateCommand(EnhancedTriggerObject* object) -> decltype(triggerDynamicRotateCommand(object)) {
	using FunctionType = decltype(triggerDynamicRotateCommand(object))(*)(GJBaseGameLayer*, EnhancedTriggerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x10d9cc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJBaseGameLayer::triggerGradientCommand(GradientTriggerObject* object) -> decltype(triggerGradientCommand(object)) {
	using FunctionType = decltype(triggerGradientCommand(object))(*)(GJBaseGameLayer*, GradientTriggerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x10e12c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJBaseGameLayer::triggerGravityChange(EffectGameObject* object, int playerID) -> decltype(triggerGravityChange(object, playerID)) {
	using FunctionType = decltype(triggerGravityChange(object, playerID))(*)(GJBaseGameLayer*, EffectGameObject*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1115d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, playerID);
}

auto GJBaseGameLayer::triggerMoveCommand(EffectGameObject* object) -> decltype(triggerMoveCommand(object)) {
	using FunctionType = decltype(triggerMoveCommand(object))(*)(GJBaseGameLayer*, EffectGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x10cca4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJBaseGameLayer::triggerRotateCommand(EnhancedTriggerObject* object) -> decltype(triggerRotateCommand(object)) {
	using FunctionType = decltype(triggerRotateCommand(object))(*)(GJBaseGameLayer*, EnhancedTriggerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x10d7f8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJBaseGameLayer::triggerShaderCommand(ShaderGameObject* object) -> decltype(triggerShaderCommand(object)) {
	using FunctionType = decltype(triggerShaderCommand(object))(*)(GJBaseGameLayer*, ShaderGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x10f8e4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJBaseGameLayer::triggerTransformCommand(TransformTriggerGameObject* object) -> decltype(triggerTransformCommand(object)) {
	using FunctionType = decltype(triggerTransformCommand(object))(*)(GJBaseGameLayer*, TransformTriggerGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x10dd58, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJBaseGameLayer::tryGetGroupParent(int groupID) -> decltype(tryGetGroupParent(groupID)) {
	using FunctionType = decltype(tryGetGroupParent(groupID))(*)(GJBaseGameLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1122fc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, groupID);
}

auto GJBaseGameLayer::tryGetMainObject(int groupID) -> decltype(tryGetMainObject(groupID)) {
	using FunctionType = decltype(tryGetMainObject(groupID))(*)(GJBaseGameLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1027ac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, groupID);
}

auto GJBaseGameLayer::tryGetObject(int groupID) -> decltype(tryGetObject(groupID)) {
	using FunctionType = decltype(tryGetObject(groupID))(*)(GJBaseGameLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xfc288, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, groupID);
}

auto GJBaseGameLayer::tryResumeAudio() -> decltype(tryResumeAudio()) {
	using FunctionType = decltype(tryResumeAudio())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1228fc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::unclaimParticle(char const* key, cocos2d::CCParticleSystemQuad* particle) -> decltype(unclaimParticle(key, particle)) {
	using FunctionType = decltype(unclaimParticle(key, particle))(*)(GJBaseGameLayer*, char const*, cocos2d::CCParticleSystemQuad*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x12c930, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key, particle);
}

auto GJBaseGameLayer::ungroupStickyObjects(cocos2d::CCArray* objects) -> decltype(ungroupStickyObjects(objects)) {
	using FunctionType = decltype(ungroupStickyObjects(objects))(*)(GJBaseGameLayer*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x112bdc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, objects);
}

auto GJBaseGameLayer::unlinkAllEvents() -> decltype(unlinkAllEvents()) {
	using FunctionType = decltype(unlinkAllEvents())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11de88, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::updateActiveEnterEffect(EnterEffectObject* object) -> decltype(updateActiveEnterEffect(object)) {
	using FunctionType = decltype(updateActiveEnterEffect(object))(*)(GJBaseGameLayer*, EnterEffectObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xf6eb4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJBaseGameLayer::updateAllObjectSection() -> decltype(updateAllObjectSection()) {
	using FunctionType = decltype(updateAllObjectSection())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x128a08, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::updateAudioVisualizer() -> decltype(updateAudioVisualizer()) {
	using FunctionType = decltype(updateAudioVisualizer())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x12437c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::updateBGArtSpeed(float modX, float modY) -> decltype(updateBGArtSpeed(modX, modY)) {
	using FunctionType = decltype(updateBGArtSpeed(modX, modY))(*)(GJBaseGameLayer*, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x129418, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, modX, modY);
}

auto GJBaseGameLayer::updateCamera(float dt) -> decltype(updateCamera(dt)) {
	using FunctionType = decltype(updateCamera(dt))(*)(GJBaseGameLayer*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x124838, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt);
}

auto GJBaseGameLayer::updateCameraBGArt(cocos2d::CCPoint position, float zoom) -> decltype(updateCameraBGArt(position, zoom)) {
	using FunctionType = decltype(updateCameraBGArt(position, zoom))(*)(GJBaseGameLayer*, cocos2d::CCPoint, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x12a788, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, position, zoom);
}

auto GJBaseGameLayer::updateCameraEdge(int direction, int value) -> decltype(updateCameraEdge(direction, value)) {
	using FunctionType = decltype(updateCameraEdge(direction, value))(*)(GJBaseGameLayer*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x120e5c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, direction, value);
}

auto GJBaseGameLayer::updateCameraMode(EffectGameObject* obj, bool updateDual) -> decltype(updateCameraMode(obj, updateDual)) {
	using FunctionType = decltype(updateCameraMode(obj, updateDual))(*)(GJBaseGameLayer*, EffectGameObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xfd518, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, obj, updateDual);
}

auto GJBaseGameLayer::updateCameraOffsetX(float offsetX, float duration, int easingType, float easingRate, int uniqueID, int controlID) -> decltype(updateCameraOffsetX(offsetX, duration, easingType, easingRate, uniqueID, controlID)) {
	using FunctionType = decltype(updateCameraOffsetX(offsetX, duration, easingType, easingRate, uniqueID, controlID))(*)(GJBaseGameLayer*, float, float, int, float, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x120cc4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, offsetX, duration, easingType, easingRate, uniqueID, controlID);
}

auto GJBaseGameLayer::updateCameraOffsetY(float offsetY, float duration, int easingType, float easingRate, int uniqueID, int controlID) -> decltype(updateCameraOffsetY(offsetY, duration, easingType, easingRate, uniqueID, controlID)) {
	using FunctionType = decltype(updateCameraOffsetY(offsetY, duration, easingType, easingRate, uniqueID, controlID))(*)(GJBaseGameLayer*, float, float, int, float, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x120d90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, offsetY, duration, easingType, easingRate, uniqueID, controlID);
}

auto GJBaseGameLayer::updateCollisionBlocks() -> decltype(updateCollisionBlocks()) {
	using FunctionType = decltype(updateCollisionBlocks())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x102f6c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::updateCounters(int itemId, int value) -> decltype(updateCounters(itemId, value)) {
	using FunctionType = decltype(updateCounters(itemId, value))(*)(GJBaseGameLayer*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11e468, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, itemId, value);
}

auto GJBaseGameLayer::updateDualGround(PlayerObject* object, int mode, bool instant, float duration) -> decltype(updateDualGround(object, mode, instant, duration)) {
	using FunctionType = decltype(updateDualGround(object, mode, instant, duration))(*)(GJBaseGameLayer*, PlayerObject*, int, bool, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xfd20c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, mode, instant, duration);
}

auto GJBaseGameLayer::updateEnterEffects(float dt) -> decltype(updateEnterEffects(dt)) {
	using FunctionType = decltype(updateEnterEffects(dt))(*)(GJBaseGameLayer*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xf7b40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt);
}

auto GJBaseGameLayer::updateExtendedCollision(GameObject* object, bool extendedCollision) -> decltype(updateExtendedCollision(object, extendedCollision)) {
	using FunctionType = decltype(updateExtendedCollision(object, extendedCollision))(*)(GJBaseGameLayer*, GameObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x114004, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, extendedCollision);
}

auto GJBaseGameLayer::updateExtraGameLayers() -> decltype(updateExtraGameLayers()) {
	using FunctionType = decltype(updateExtraGameLayers())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1114d8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::updateGameplayOffsetX(int offsetX, bool staticOffset) -> decltype(updateGameplayOffsetX(offsetX, staticOffset)) {
	using FunctionType = decltype(updateGameplayOffsetX(offsetX, staticOffset))(*)(GJBaseGameLayer*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x12100c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, offsetX, staticOffset);
}

auto GJBaseGameLayer::updateGameplayOffsetY(int offsetY, bool staticOffset) -> decltype(updateGameplayOffsetY(offsetY, staticOffset)) {
	using FunctionType = decltype(updateGameplayOffsetY(offsetY, staticOffset))(*)(GJBaseGameLayer*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x121028, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, offsetY, staticOffset);
}

auto GJBaseGameLayer::updateGradientLayers() -> decltype(updateGradientLayers()) {
	using FunctionType = decltype(updateGradientLayers())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x10e7c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::updateGroundShadows() -> decltype(updateGroundShadows()) {
	using FunctionType = decltype(updateGroundShadows())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xefa88, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::updateGuideArt() -> decltype(updateGuideArt()) {
	using FunctionType = decltype(updateGuideArt())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1242a4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::updateInternalCamOffsetX(float offsetX, float duration, float easingRate) -> decltype(updateInternalCamOffsetX(offsetX, duration, easingRate)) {
	using FunctionType = decltype(updateInternalCamOffsetX(offsetX, duration, easingRate))(*)(GJBaseGameLayer*, float, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x12b0b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, offsetX, duration, easingRate);
}

auto GJBaseGameLayer::updateInternalCamOffsetY(float offsetY, float duration, float easingRate) -> decltype(updateInternalCamOffsetY(offsetY, duration, easingRate)) {
	using FunctionType = decltype(updateInternalCamOffsetY(offsetY, duration, easingRate))(*)(GJBaseGameLayer*, float, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x12b18c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, offsetY, duration, easingRate);
}

auto GJBaseGameLayer::updateKeyframeOrder(int keyframeGroup) -> decltype(updateKeyframeOrder(keyframeGroup)) {
	using FunctionType = decltype(updateKeyframeOrder(keyframeGroup))(*)(GJBaseGameLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11e10c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, keyframeGroup);
}

auto GJBaseGameLayer::updateLayerCapacity(gd::string capacityString) -> decltype(updateLayerCapacity(capacityString)) {
	using FunctionType = decltype(updateLayerCapacity(capacityString))(*)(GJBaseGameLayer*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xf02ac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, capacityString);
}

auto GJBaseGameLayer::updateLegacyLayerCapacity(int front, int frontBlend, int back, int backBlend) -> decltype(updateLegacyLayerCapacity(front, frontBlend, back, backBlend)) {
	using FunctionType = decltype(updateLegacyLayerCapacity(front, frontBlend, back, backBlend))(*)(GJBaseGameLayer*, int, int, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xf01d8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, front, frontBlend, back, backBlend);
}

auto GJBaseGameLayer::updateLevelColors() -> decltype(updateLevelColors()) {
	using FunctionType = decltype(updateLevelColors())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xef458, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::updateMaxGameplayY() -> decltype(updateMaxGameplayY()) {
	using FunctionType = decltype(updateMaxGameplayY())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x12890c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::updateMGArtSpeed(float modX, float modY) -> decltype(updateMGArtSpeed(modX, modY)) {
	using FunctionType = decltype(updateMGArtSpeed(modX, modY))(*)(GJBaseGameLayer*, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x12944c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, modX, modY);
}

auto GJBaseGameLayer::updateMGOffsetY(float offsetY, float duration, int easingType, float easingRate, int uniqueID, int controlID) -> decltype(updateMGOffsetY(offsetY, duration, easingType, easingRate, uniqueID, controlID)) {
	using FunctionType = decltype(updateMGOffsetY(offsetY, duration, easingType, easingRate, uniqueID, controlID))(*)(GJBaseGameLayer*, float, float, int, float, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x121034, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, offsetY, duration, easingType, easingRate, uniqueID, controlID);
}

auto GJBaseGameLayer::updateOBB2(cocos2d::CCRect rect) -> decltype(updateOBB2(rect)) {
	using FunctionType = decltype(updateOBB2(rect))(*)(GJBaseGameLayer*, cocos2d::CCRect);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xfba80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, rect);
}

auto GJBaseGameLayer::updateParticles(float dt) -> decltype(updateParticles(dt)) {
	using FunctionType = decltype(updateParticles(dt))(*)(GJBaseGameLayer*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x12d288, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt);
}

auto GJBaseGameLayer::updatePlatformerTime() -> decltype(updatePlatformerTime()) {
	using FunctionType = decltype(updatePlatformerTime())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1268d4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::updatePlayerCollisionBlocks() -> decltype(updatePlayerCollisionBlocks()) {
	using FunctionType = decltype(updatePlayerCollisionBlocks())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x102dd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::updateProximityVolumeEffects() -> decltype(updateProximityVolumeEffects()) {
	using FunctionType = decltype(updateProximityVolumeEffects())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x126778, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::updateQueuedLabels() -> decltype(updateQueuedLabels()) {
	using FunctionType = decltype(updateQueuedLabels())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11ffcc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::updateReplay() -> decltype(updateReplay()) {
	using FunctionType = decltype(updateReplay())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x12721c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::updateSavePositionObjects() -> decltype(updateSavePositionObjects()) {
	using FunctionType = decltype(updateSavePositionObjects())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x103f50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::updateShaderLayer(float dt) -> decltype(updateShaderLayer(dt)) {
	using FunctionType = decltype(updateShaderLayer(dt))(*)(GJBaseGameLayer*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11002c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt);
}

auto GJBaseGameLayer::updateSpecialGroupData() -> decltype(updateSpecialGroupData()) {
	using FunctionType = decltype(updateSpecialGroupData())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xf1cd8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::updateSpecialLabels() -> decltype(updateSpecialLabels()) {
	using FunctionType = decltype(updateSpecialLabels())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x126354, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::updateStaticCameraPos(cocos2d::CCPoint pos, bool staticX, bool staticY, bool followOrSmoothEase, float time, int easingType, float easingRate) -> decltype(updateStaticCameraPos(pos, staticX, staticY, followOrSmoothEase, time, easingType, easingRate)) {
	using FunctionType = decltype(updateStaticCameraPos(pos, staticX, staticY, followOrSmoothEase, time, easingType, easingRate))(*)(GJBaseGameLayer*, cocos2d::CCPoint, bool, bool, bool, float, int, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xfdc70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, pos, staticX, staticY, followOrSmoothEase, time, easingType, easingRate);
}

auto GJBaseGameLayer::updateStaticCameraPosToGroup(int centerID, bool updateX, bool updateY, bool followObject, float followEase, float duration, int easingType, float easingRate, bool smoothVelocity, float velocityMod) -> decltype(updateStaticCameraPosToGroup(centerID, updateX, updateY, followObject, followEase, duration, easingType, easingRate, smoothVelocity, velocityMod)) {
	using FunctionType = decltype(updateStaticCameraPosToGroup(centerID, updateX, updateY, followObject, followEase, duration, easingType, easingRate, smoothVelocity, velocityMod))(*)(GJBaseGameLayer*, int, bool, bool, bool, float, float, int, float, bool, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x12b340, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, centerID, updateX, updateY, followObject, followEase, duration, easingType, easingRate, smoothVelocity, velocityMod);
}

auto GJBaseGameLayer::updateTimeMod(float speed, bool players, bool noEffects) -> decltype(updateTimeMod(speed, players, noEffects)) {
	using FunctionType = decltype(updateTimeMod(speed, players, noEffects))(*)(GJBaseGameLayer*, float, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xfd3a8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, speed, players, noEffects);
}

auto GJBaseGameLayer::updateTimerLabels() -> decltype(updateTimerLabels()) {
	using FunctionType = decltype(updateTimerLabels())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x11fae4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::updateZoom(float zoom, float duration, int easing, float rate, int uniqueID, int controlID) -> decltype(updateZoom(zoom, duration, easing, rate, uniqueID, controlID)) {
	using FunctionType = decltype(updateZoom(zoom, duration, easing, rate, uniqueID, controlID))(*)(GJBaseGameLayer*, float, float, int, float, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1209b8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, zoom, duration, easing, rate, uniqueID, controlID);
}

auto GJBaseGameLayer::visitWithColorFlash() -> decltype(visitWithColorFlash()) {
	using FunctionType = decltype(visitWithColorFlash())(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1327f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBaseGameLayer::volumeForProximityEffect(SFXTriggerInstance& instance) -> decltype(volumeForProximityEffect(instance)) {
	using FunctionType = decltype(volumeForProximityEffect(instance))(*)(GJBaseGameLayer*, SFXTriggerInstance&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x12d794, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, instance);
}
