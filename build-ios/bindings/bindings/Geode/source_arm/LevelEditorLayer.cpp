
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/LevelEditorLayer.hpp>
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

LevelEditorLayer::LevelEditorLayer() : LevelEditorLayer(geode::CutoffConstructor, sizeof(LevelEditorLayer)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	LevelEditorLayer::~LevelEditorLayer();

	using FunctionType = void(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xe3860, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::create(GJGameLevel* level, bool noUI) -> decltype(create(level, noUI)) {
	using FunctionType = decltype(create(level, noUI))(*)(GJGameLevel*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xc1344, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(level, noUI);
}

auto LevelEditorLayer::scene(GJGameLevel* level, bool noUI) -> decltype(scene(level, noUI)) {
	using FunctionType = decltype(scene(level, noUI))(*)(GJGameLevel*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xc1294, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(level, noUI);
}

auto LevelEditorLayer::updateObjectLabel(GameObject* object) -> decltype(updateObjectLabel(object)) {
	using FunctionType = decltype(updateObjectLabel(object))(*)(GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xcde90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(object);
}

auto LevelEditorLayer::draw() -> decltype(draw()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&LevelEditorLayer::draw), this);
	using FunctionType = decltype(draw())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xdf7c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto LevelEditorLayer::postUpdate(float dt) -> decltype(postUpdate(dt)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&LevelEditorLayer::postUpdate), this);
	using FunctionType = decltype(postUpdate(dt))(*)(LevelEditorLayer*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd6144, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, dt);
}

auto LevelEditorLayer::updateVisibility(float dt) -> decltype(updateVisibility(dt)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&LevelEditorLayer::updateVisibility), this);
	using FunctionType = decltype(updateVisibility(dt))(*)(LevelEditorLayer*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xcea74, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, dt);
}

auto LevelEditorLayer::playerTookDamage(PlayerObject* player) -> decltype(playerTookDamage(player)) {
	auto self = addresser::thunkAdjust(Resolve<PlayerObject*>::func(&LevelEditorLayer::playerTookDamage), this);
	using FunctionType = decltype(playerTookDamage(player))(*)(LevelEditorLayer*, PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd6130, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, player);
}

auto LevelEditorLayer::updateColor(cocos2d::ccColor3B& color, float fadeTime, int colorID, bool blending, float opacity, cocos2d::ccHSVValue& copyHSV, int colorIDToCopy, bool copyOpacity, EffectGameObject* callerObject, int unk1, int unk2) -> decltype(updateColor(color, fadeTime, colorID, blending, opacity, copyHSV, colorIDToCopy, copyOpacity, callerObject, unk1, unk2)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::ccColor3B&, float, int, bool, float, cocos2d::ccHSVValue&, int, bool, EffectGameObject*, int, int>::func(&LevelEditorLayer::updateColor), this);
	using FunctionType = decltype(updateColor(color, fadeTime, colorID, blending, opacity, copyHSV, colorIDToCopy, copyOpacity, callerObject, unk1, unk2))(*)(LevelEditorLayer*, cocos2d::ccColor3B&, float, int, bool, float, cocos2d::ccHSVValue&, int, bool, EffectGameObject*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd3628, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, color, fadeTime, colorID, blending, opacity, copyHSV, colorIDToCopy, copyOpacity, callerObject, unk1, unk2);
}

auto LevelEditorLayer::updateDebugDraw() -> decltype(updateDebugDraw()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&LevelEditorLayer::updateDebugDraw), this);
	using FunctionType = decltype(updateDebugDraw())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xddfe0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto LevelEditorLayer::addToGroup(GameObject* object, int groupID, bool triggerGroup) -> decltype(addToGroup(object, groupID, triggerGroup)) {
	auto self = addresser::thunkAdjust(Resolve<GameObject*, int, bool>::func(&LevelEditorLayer::addToGroup), this);
	using FunctionType = decltype(addToGroup(object, groupID, triggerGroup))(*)(LevelEditorLayer*, GameObject*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd3dd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, object, groupID, triggerGroup);
}

auto LevelEditorLayer::removeFromGroup(GameObject* object, int groupID) -> decltype(removeFromGroup(object, groupID)) {
	auto self = addresser::thunkAdjust(Resolve<GameObject*, int>::func(&LevelEditorLayer::removeFromGroup), this);
	using FunctionType = decltype(removeFromGroup(object, groupID))(*)(LevelEditorLayer*, GameObject*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd3e88, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, object, groupID);
}

auto LevelEditorLayer::updateObjectSection(GameObject* object) -> decltype(updateObjectSection(object)) {
	auto self = addresser::thunkAdjust(Resolve<GameObject*>::func(&LevelEditorLayer::updateObjectSection), this);
	using FunctionType = decltype(updateObjectSection(object))(*)(LevelEditorLayer*, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd4dd8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, object);
}

auto LevelEditorLayer::updateDisabledObjectsLastPos(cocos2d::CCArray* objects) -> decltype(updateDisabledObjectsLastPos(objects)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCArray*>::func(&LevelEditorLayer::updateDisabledObjectsLastPos), this);
	using FunctionType = decltype(updateDisabledObjectsLastPos(objects))(*)(LevelEditorLayer*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd4ee4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, objects);
}

auto LevelEditorLayer::timeForPos(cocos2d::CCPoint position, int order, int channel, bool songTriggers, int id) -> decltype(timeForPos(position, order, channel, songTriggers, id)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCPoint, int, int, bool, int>::func(&LevelEditorLayer::timeForPos), this);
	using FunctionType = decltype(timeForPos(position, order, channel, songTriggers, id))(*)(LevelEditorLayer*, cocos2d::CCPoint, int, int, bool, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd38c8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, position, order, channel, songTriggers, id);
}

auto LevelEditorLayer::posForTime(float time) -> decltype(posForTime(time)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&LevelEditorLayer::posForTime), this);
	using FunctionType = decltype(posForTime(time))(*)(LevelEditorLayer*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd3954, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, time);
}

auto LevelEditorLayer::resetSPTriggered() -> decltype(resetSPTriggered()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&LevelEditorLayer::resetSPTriggered), this);
	using FunctionType = decltype(resetSPTriggered())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd3994, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto LevelEditorLayer::didRotateGameplay() -> decltype(didRotateGameplay()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&LevelEditorLayer::didRotateGameplay), this);
	using FunctionType = decltype(didRotateGameplay())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd4bd8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto LevelEditorLayer::manualUpdateObjectColors(GameObject* object) -> decltype(manualUpdateObjectColors(object)) {
	auto self = addresser::thunkAdjust(Resolve<GameObject*>::func(&LevelEditorLayer::manualUpdateObjectColors), this);
	using FunctionType = decltype(manualUpdateObjectColors(object))(*)(LevelEditorLayer*, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xcf5c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, object);
}

auto LevelEditorLayer::claimCustomParticle(gd::string const& key, cocos2d::ParticleStruct const& particleStruct, int zLayer, int zOrder, int uiObject, bool dontAdd) -> decltype(claimCustomParticle(key, particleStruct, zLayer, zOrder, uiObject, dontAdd)) {
	auto self = addresser::thunkAdjust(Resolve<gd::string const&, cocos2d::ParticleStruct const&, int, int, int, bool>::func(&LevelEditorLayer::claimCustomParticle), this);
	using FunctionType = decltype(claimCustomParticle(key, particleStruct, zLayer, zOrder, uiObject, dontAdd))(*)(LevelEditorLayer*, gd::string const&, cocos2d::ParticleStruct const&, int, int, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd6fe8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, key, particleStruct, zLayer, zOrder, uiObject, dontAdd);
}

auto LevelEditorLayer::unclaimCustomParticle(gd::string const& key, cocos2d::CCParticleSystemQuad* particle) -> decltype(unclaimCustomParticle(key, particle)) {
	auto self = addresser::thunkAdjust(Resolve<gd::string const&, cocos2d::CCParticleSystemQuad*>::func(&LevelEditorLayer::unclaimCustomParticle), this);
	using FunctionType = decltype(unclaimCustomParticle(key, particle))(*)(LevelEditorLayer*, gd::string const&, cocos2d::CCParticleSystemQuad*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd70b8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, key, particle);
}

auto LevelEditorLayer::activatedAudioTrigger(SFXTriggerGameObject* object) -> decltype(activatedAudioTrigger(object)) {
	auto self = addresser::thunkAdjust(Resolve<SFXTriggerGameObject*>::func(&LevelEditorLayer::activatedAudioTrigger), this);
	using FunctionType = decltype(activatedAudioTrigger(object))(*)(LevelEditorLayer*, SFXTriggerGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd606c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, object);
}

auto LevelEditorLayer::checkpointActivated(CheckpointGameObject* object) -> decltype(checkpointActivated(object)) {
	auto self = addresser::thunkAdjust(Resolve<CheckpointGameObject*>::func(&LevelEditorLayer::checkpointActivated), this);
	using FunctionType = decltype(checkpointActivated(object))(*)(LevelEditorLayer*, CheckpointGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd6084, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, object);
}

auto LevelEditorLayer::addKeyframe(KeyframeGameObject* object) -> decltype(addKeyframe(object)) {
	auto self = addresser::thunkAdjust(Resolve<KeyframeGameObject*>::func(&LevelEditorLayer::addKeyframe), this);
	using FunctionType = decltype(addKeyframe(object))(*)(LevelEditorLayer*, KeyframeGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd70f8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, object);
}

auto LevelEditorLayer::levelSettingsUpdated() -> decltype(levelSettingsUpdated()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&LevelEditorLayer::levelSettingsUpdated), this);
	using FunctionType = decltype(levelSettingsUpdated())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xc4c10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto LevelEditorLayer::activateTriggerEffect(EffectGameObject* object, float currentTime, float playTime, float boundTime, bool active) -> decltype(activateTriggerEffect(object, currentTime, playTime, boundTime, active)) {
	using FunctionType = decltype(activateTriggerEffect(object, currentTime, playTime, boundTime, active))(*)(LevelEditorLayer*, EffectGameObject*, float, float, float, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd2940, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, currentTime, playTime, boundTime, active);
}

auto LevelEditorLayer::addDelayedSpawn(EffectGameObject* object, float delay) -> decltype(addDelayedSpawn(object, delay)) {
	using FunctionType = decltype(addDelayedSpawn(object, delay))(*)(LevelEditorLayer*, EffectGameObject*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd3278, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, delay);
}

auto LevelEditorLayer::addExclusionList(const gd::unordered_set<int>& excludes, gd::unordered_set<int>& groups) -> decltype(addExclusionList(excludes, groups)) {
	using FunctionType = decltype(addExclusionList(excludes, groups))(*)(LevelEditorLayer*, const gd::unordered_set<int>&, gd::unordered_set<int>&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xcfe0c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, excludes, groups);
}

auto LevelEditorLayer::addObjectFromVector(gd::vector<gd::string>& values, gd::vector<void*>& exists) -> decltype(addObjectFromVector(values, exists)) {
	using FunctionType = decltype(addObjectFromVector(values, exists))(*)(LevelEditorLayer*, gd::vector<gd::string>&, gd::vector<void*>&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xc4fdc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, values, exists);
}

auto LevelEditorLayer::addObjectsAtPosition(cocos2d::CCPoint position, cocos2d::CCArray* objects, cocos2d::CCArray* result) -> decltype(addObjectsAtPosition(position, objects, result)) {
	using FunctionType = decltype(addObjectsAtPosition(position, objects, result))(*)(LevelEditorLayer*, cocos2d::CCPoint, cocos2d::CCArray*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xc7708, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, position, objects, result);
}

auto LevelEditorLayer::addObjectsInRect(cocos2d::CCRect rect, bool ignoreGroups, cocos2d::CCArray* objects, cocos2d::CCArray* result) -> decltype(addObjectsInRect(rect, ignoreGroups, objects, result)) {
	using FunctionType = decltype(addObjectsInRect(rect, ignoreGroups, objects, result))(*)(LevelEditorLayer*, cocos2d::CCRect, bool, cocos2d::CCArray*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xc78b8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, rect, ignoreGroups, objects, result);
}

auto LevelEditorLayer::addObjectToGroup(GameObject* object, int group) -> decltype(addObjectToGroup(object, group)) {
	using FunctionType = decltype(addObjectToGroup(object, group))(*)(LevelEditorLayer*, GameObject*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd3d60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, group);
}

auto LevelEditorLayer::addPlayer2Point(cocos2d::CCPoint point, bool newGroup) -> decltype(addPlayer2Point(point, newGroup)) {
	using FunctionType = decltype(addPlayer2Point(point, newGroup))(*)(LevelEditorLayer*, cocos2d::CCPoint, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd642c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, point, newGroup);
}

auto LevelEditorLayer::addPlayerCollisionBlock() -> decltype(addPlayerCollisionBlock()) {
	using FunctionType = decltype(addPlayerCollisionBlock())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd4abc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::addPlayerPoint(cocos2d::CCPoint point) -> decltype(addPlayerPoint(point)) {
	using FunctionType = decltype(addPlayerPoint(point))(*)(LevelEditorLayer*, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd63c8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, point);
}

auto LevelEditorLayer::addSpecial(GameObject* object) -> decltype(addSpecial(object)) {
	using FunctionType = decltype(addSpecial(object))(*)(LevelEditorLayer*, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xc58b8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto LevelEditorLayer::addToRedoList(UndoObject* object) -> decltype(addToRedoList(object)) {
	using FunctionType = decltype(addToRedoList(object))(*)(LevelEditorLayer*, UndoObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xc83ac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto LevelEditorLayer::addTouchPoint(cocos2d::CCPoint point) -> decltype(addTouchPoint(point)) {
	using FunctionType = decltype(addTouchPoint(point))(*)(LevelEditorLayer*, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd4c6c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, point);
}

auto LevelEditorLayer::addToUndoList(UndoObject* object, bool keepRedo) -> decltype(addToUndoList(object, keepRedo)) {
	using FunctionType = decltype(addToUndoList(object, keepRedo))(*)(LevelEditorLayer*, UndoObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xc5764, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, keepRedo);
}

auto LevelEditorLayer::addTriggersWithGroupID(gd::unordered_set<int>& sourceIDs, cocos2d::CCArray* triggers, gd::unordered_map<int, int>& remap, int objectID) -> decltype(addTriggersWithGroupID(sourceIDs, triggers, remap, objectID)) {
	using FunctionType = decltype(addTriggersWithGroupID(sourceIDs, triggers, remap, objectID))(*)(LevelEditorLayer*, gd::unordered_set<int>&, cocos2d::CCArray*, gd::unordered_map<int, int>&, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd1b6c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sourceIDs, triggers, remap, objectID);
}

auto LevelEditorLayer::addTriggersWithTargetGroupID(gd::unordered_set<int>& sourceIDs, gd::unordered_set<int>& targetIDs, cocos2d::CCArray* triggers, gd::unordered_map<int, int>& remap, int objectID) -> decltype(addTriggersWithTargetGroupID(sourceIDs, targetIDs, triggers, remap, objectID)) {
	using FunctionType = decltype(addTriggersWithTargetGroupID(sourceIDs, targetIDs, triggers, remap, objectID))(*)(LevelEditorLayer*, gd::unordered_set<int>&, gd::unordered_set<int>&, cocos2d::CCArray*, gd::unordered_map<int, int>&, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd17f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sourceIDs, targetIDs, triggers, remap, objectID);
}

auto LevelEditorLayer::applyAttributeState(GameObject* dest, GameObject* src) -> decltype(applyAttributeState(dest, src)) {
	using FunctionType = decltype(applyAttributeState(dest, src))(*)(LevelEditorLayer*, GameObject*, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd69f4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dest, src);
}

auto LevelEditorLayer::applyGroupState(GameObject* dest, GameObject* src) -> decltype(applyGroupState(dest, src)) {
	using FunctionType = decltype(applyGroupState(dest, src))(*)(LevelEditorLayer*, GameObject*, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd67cc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dest, src);
}

auto LevelEditorLayer::breakApartTextObject(TextGameObject* object) -> decltype(breakApartTextObject(object)) {
	using FunctionType = decltype(breakApartTextObject(object))(*)(LevelEditorLayer*, TextGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd46f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto LevelEditorLayer::canPasteState() -> decltype(canPasteState()) {
	using FunctionType = decltype(canPasteState())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd65b8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::clearPlayerPoints() -> decltype(clearPlayerPoints()) {
	using FunctionType = decltype(clearPlayerPoints())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd57f4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::clearTouchPoints() -> decltype(clearTouchPoints()) {
	using FunctionType = decltype(clearTouchPoints())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd585c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::copyObjectState(GameObject* object) -> decltype(copyObjectState(object)) {
	using FunctionType = decltype(copyObjectState(object))(*)(LevelEditorLayer*, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd65c8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto LevelEditorLayer::copyParticleState(ParticleGameObject* object) -> decltype(copyParticleState(object)) {
	using FunctionType = decltype(copyParticleState(object))(*)(LevelEditorLayer*, ParticleGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd6bb8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto LevelEditorLayer::createObject(int key, cocos2d::CCPoint position, bool noUndo) -> decltype(createObject(key, position, noUndo)) {
	using FunctionType = decltype(createObject(key, position, noUndo))(*)(LevelEditorLayer*, int, cocos2d::CCPoint, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xc5e74, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key, position, noUndo);
}

auto LevelEditorLayer::createObjectsFromSetup(gd::string& setup) -> decltype(createObjectsFromSetup(setup)) {
	using FunctionType = decltype(createObjectsFromSetup(setup))(*)(LevelEditorLayer*, gd::string&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xc2f4c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, setup);
}

auto LevelEditorLayer::createObjectsFromString(gd::string const& str, bool noUndo, bool noLimit) -> decltype(createObjectsFromString(str, noUndo, noLimit)) {
	using FunctionType = decltype(createObjectsFromString(str, noUndo, noLimit))(*)(LevelEditorLayer*, gd::string const&, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xc5090, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, str, noUndo, noLimit);
}

auto LevelEditorLayer::dirtifyTriggers() -> decltype(dirtifyTriggers()) {
	using FunctionType = decltype(dirtifyTriggers())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd4cd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::duplicateKeyframeAnimation(int keyframeGroup) -> decltype(duplicateKeyframeAnimation(keyframeGroup)) {
	using FunctionType = decltype(duplicateKeyframeAnimation(keyframeGroup))(*)(LevelEditorLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd710c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, keyframeGroup);
}

auto LevelEditorLayer::fastUpdateDisabledGroups() -> decltype(fastUpdateDisabledGroups()) {
	using FunctionType = decltype(fastUpdateDisabledGroups())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd38b4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::findGameObject(int uniqueID) -> decltype(findGameObject(uniqueID)) {
	using FunctionType = decltype(findGameObject(uniqueID))(*)(LevelEditorLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xc7abc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, uniqueID);
}

auto LevelEditorLayer::findStartPosObject() -> decltype(findStartPosObject()) {
	using FunctionType = decltype(findStartPosObject())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd4ce8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::forceShowSelectedObjects(bool show) -> decltype(forceShowSelectedObjects(show)) {
	using FunctionType = decltype(forceShowSelectedObjects(show))(*)(LevelEditorLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xce9c4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, show);
}

auto LevelEditorLayer::fullUpdateDisabledGroups() -> decltype(fullUpdateDisabledGroups()) {
	using FunctionType = decltype(fullUpdateDisabledGroups())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd38b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::getAllObjects() -> decltype(getAllObjects()) {
	using FunctionType = decltype(getAllObjects())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xc7ab4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::getDelayedSpawnNode() -> decltype(getDelayedSpawnNode()) {
	using FunctionType = decltype(getDelayedSpawnNode())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd3504, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::getGridPos(cocos2d::CCPoint position) -> decltype(getGridPos(position)) {
	using FunctionType = decltype(getGridPos(position))(*)(LevelEditorLayer*, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xc6530, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, position);
}

auto LevelEditorLayer::getLastObjectX() -> decltype(getLastObjectX()) {
	using FunctionType = decltype(getLastObjectX())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd39d4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::getLevelString() -> decltype(getLevelString()) {
	using FunctionType = decltype(getLevelString())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xc8c34, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::getLockedLayers() -> decltype(getLockedLayers()) {
	using FunctionType = decltype(getLockedLayers())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xccfb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::getNextColorChannel() -> decltype(getNextColorChannel()) {
	using FunctionType = decltype(getNextColorChannel())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd1260, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::getNextFreeAreaEffectID(const gd::unordered_set<int>& exclude) -> decltype(getNextFreeAreaEffectID(exclude)) {
	using FunctionType = decltype(getNextFreeAreaEffectID(exclude))(*)(LevelEditorLayer*, const gd::unordered_set<int>&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd09d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, exclude);
}

auto LevelEditorLayer::getNextFreeBlockID(const gd::unordered_set<int>& exclude) -> decltype(getNextFreeBlockID(exclude)) {
	using FunctionType = decltype(getNextFreeBlockID(exclude))(*)(LevelEditorLayer*, const gd::unordered_set<int>&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd00b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, exclude);
}

auto LevelEditorLayer::getNextFreeEditorLayer(const gd::unordered_set<int>& exclude) -> decltype(getNextFreeEditorLayer(exclude)) {
	using FunctionType = decltype(getNextFreeEditorLayer(exclude))(*)(LevelEditorLayer*, const gd::unordered_set<int>&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd053c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, exclude);
}

auto LevelEditorLayer::getNextFreeEnterChannel(const gd::unordered_set<int>& exclude) -> decltype(getNextFreeEnterChannel(exclude)) {
	using FunctionType = decltype(getNextFreeEnterChannel(exclude))(*)(LevelEditorLayer*, const gd::unordered_set<int>&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd077c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, exclude);
}

auto LevelEditorLayer::getNextFreeGradientID(const gd::unordered_set<int>& exclude) -> decltype(getNextFreeGradientID(exclude)) {
	using FunctionType = decltype(getNextFreeGradientID(exclude))(*)(LevelEditorLayer*, const gd::unordered_set<int>&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd1040, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, exclude);
}

auto LevelEditorLayer::getNextFreeGroupID(const gd::unordered_set<int>& exclude) -> decltype(getNextFreeGroupID(exclude)) {
	using FunctionType = decltype(getNextFreeGroupID(exclude))(*)(LevelEditorLayer*, const gd::unordered_set<int>&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xcfaf8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, exclude);
}

auto LevelEditorLayer::getNextFreeItemID(const gd::unordered_set<int>& exclude) -> decltype(getNextFreeItemID(exclude)) {
	using FunctionType = decltype(getNextFreeItemID(exclude))(*)(LevelEditorLayer*, const gd::unordered_set<int>&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xcfe48, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, exclude);
}

auto LevelEditorLayer::getNextFreeOrderChannel(const gd::unordered_set<int>& exclude) -> decltype(getNextFreeOrderChannel(exclude)) {
	using FunctionType = decltype(getNextFreeOrderChannel(exclude))(*)(LevelEditorLayer*, const gd::unordered_set<int>&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd02dc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, exclude);
}

auto LevelEditorLayer::getNextFreeSFXGroupID(const gd::unordered_set<int>& exclude) -> decltype(getNextFreeSFXGroupID(exclude)) {
	using FunctionType = decltype(getNextFreeSFXGroupID(exclude))(*)(LevelEditorLayer*, const gd::unordered_set<int>&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd0e18, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, exclude);
}

auto LevelEditorLayer::getNextFreeSFXID(const gd::unordered_set<int>& exclude) -> decltype(getNextFreeSFXID(exclude)) {
	using FunctionType = decltype(getNextFreeSFXID(exclude))(*)(LevelEditorLayer*, const gd::unordered_set<int>&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd0bf0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, exclude);
}

auto LevelEditorLayer::getObjectRect(GameObject* object, bool forceSize, bool dontCalculate) -> decltype(getObjectRect(object, forceSize, dontCalculate)) {
	using FunctionType = decltype(getObjectRect(object, forceSize, dontCalculate))(*)(LevelEditorLayer*, GameObject*, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xc7010, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, forceSize, dontCalculate);
}

auto LevelEditorLayer::getRelativeOffset(GameObject* object) -> decltype(getRelativeOffset(object)) {
	using FunctionType = decltype(getRelativeOffset(object))(*)(LevelEditorLayer*, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xc7874, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto LevelEditorLayer::getSavedEditorPosition(int index) -> decltype(getSavedEditorPosition(index)) {
	using FunctionType = decltype(getSavedEditorPosition(index))(*)(LevelEditorLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xcda3c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index);
}

auto LevelEditorLayer::getSavedEditorPositions() -> decltype(getSavedEditorPositions()) {
	using FunctionType = decltype(getSavedEditorPositions())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xcda64, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::getSectionCount() -> decltype(getSectionCount()) {
	using FunctionType = decltype(getSectionCount())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xcddb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::getSelectedEditorOrder() -> decltype(getSelectedEditorOrder()) {
	using FunctionType = decltype(getSelectedEditorOrder())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd2290, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::getSelectedEffectPos() -> decltype(getSelectedEffectPos()) {
	using FunctionType = decltype(getSelectedEffectPos())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd22c8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::getSelectedOrderChannel() -> decltype(getSelectedOrderChannel()) {
	using FunctionType = decltype(getSelectedOrderChannel())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd2258, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::getSFXIDs() -> decltype(getSFXIDs()) {
	using FunctionType = decltype(getSFXIDs())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xcd66c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::getSongIDs(bool& multipleSongs) -> decltype(getSongIDs(multipleSongs)) {
	using FunctionType = decltype(getSongIDs(multipleSongs))(*)(LevelEditorLayer*, bool&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xcd214, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, multipleSongs);
}

auto LevelEditorLayer::getTriggerGroup(int id) -> decltype(getTriggerGroup(id)) {
	using FunctionType = decltype(getTriggerGroup(id))(*)(LevelEditorLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd371c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto LevelEditorLayer::handleAction(bool undo, cocos2d::CCArray* undoObjects) -> decltype(handleAction(undo, undoObjects)) {
	using FunctionType = decltype(handleAction(undo, undoObjects))(*)(LevelEditorLayer*, bool, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xc8444, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, undo, undoObjects);
}

auto LevelEditorLayer::hasAction(bool redo) -> decltype(hasAction(redo)) {
	using FunctionType = decltype(hasAction(redo))(*)(LevelEditorLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xc8414, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, redo);
}

auto LevelEditorLayer::init(GJGameLevel* level, bool noUI) -> decltype(init(level, noUI)) {
	using FunctionType = decltype(init(level, noUI))(*)(LevelEditorLayer*, GJGameLevel*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xc13d8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, level, noUI);
}

auto LevelEditorLayer::isLayerLocked(int layer) -> decltype(isLayerLocked(layer)) {
	using FunctionType = decltype(isLayerLocked(layer))(*)(LevelEditorLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xcde14, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, layer);
}

auto LevelEditorLayer::objectAtPosition(cocos2d::CCPoint position) -> decltype(objectAtPosition(position)) {
	using FunctionType = decltype(objectAtPosition(position))(*)(LevelEditorLayer*, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xc6d04, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, position);
}

auto LevelEditorLayer::objectMoved(GameObject* object) -> decltype(objectMoved(object)) {
	using FunctionType = decltype(objectMoved(object))(*)(LevelEditorLayer*, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xce53c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto LevelEditorLayer::objectsAtPosition(cocos2d::CCPoint position) -> decltype(objectsAtPosition(position)) {
	using FunctionType = decltype(objectsAtPosition(position))(*)(LevelEditorLayer*, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xc73f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, position);
}

auto LevelEditorLayer::objectsInRect(cocos2d::CCRect rect, bool ignoreGroups) -> decltype(objectsInRect(rect, ignoreGroups)) {
	using FunctionType = decltype(objectsInRect(rect, ignoreGroups))(*)(LevelEditorLayer*, cocos2d::CCRect, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xc6790, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, rect, ignoreGroups);
}

auto LevelEditorLayer::onPausePlaytest() -> decltype(onPausePlaytest()) {
	using FunctionType = decltype(onPausePlaytest())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd5868, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::onPlaytest() -> decltype(onPlaytest()) {
	using FunctionType = decltype(onPlaytest())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd5074, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::onResumePlaytest() -> decltype(onResumePlaytest()) {
	using FunctionType = decltype(onResumePlaytest())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd5a0c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::onStopPlaytest() -> decltype(onStopPlaytest()) {
	using FunctionType = decltype(onStopPlaytest())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd5b3c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::pasteAttributeState(GameObject* object, cocos2d::CCArray* objects) -> decltype(pasteAttributeState(object, objects)) {
	using FunctionType = decltype(pasteAttributeState(object, objects))(*)(LevelEditorLayer*, GameObject*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd691c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, objects);
}

auto LevelEditorLayer::pasteColorState(GameObject* object, cocos2d::CCArray* objects) -> decltype(pasteColorState(object, objects)) {
	using FunctionType = decltype(pasteColorState(object, objects))(*)(LevelEditorLayer*, GameObject*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd6884, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, objects);
}

auto LevelEditorLayer::pasteGroupState(GameObject* object, cocos2d::CCArray* objects) -> decltype(pasteGroupState(object, objects)) {
	using FunctionType = decltype(pasteGroupState(object, objects))(*)(LevelEditorLayer*, GameObject*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd6a24, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, objects);
}

auto LevelEditorLayer::pasteParticleState(ParticleGameObject* object, cocos2d::CCArray* objects) -> decltype(pasteParticleState(object, objects)) {
	using FunctionType = decltype(pasteParticleState(object, objects))(*)(LevelEditorLayer*, ParticleGameObject*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd6d88, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, objects);
}

auto LevelEditorLayer::processLoadedMoveActions() -> decltype(processLoadedMoveActions()) {
	using FunctionType = decltype(processLoadedMoveActions())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd3a74, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::quickUpdateAllPositions() -> decltype(quickUpdateAllPositions()) {
	using FunctionType = decltype(quickUpdateAllPositions())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd4dfc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::recreateGroups() -> decltype(recreateGroups()) {
	using FunctionType = decltype(recreateGroups())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd3f10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::redoLastAction() -> decltype(redoLastAction()) {
	using FunctionType = decltype(redoLastAction())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xc8c1c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::refreshSpecial(GameObject* object) -> decltype(refreshSpecial(object)) {
	using FunctionType = decltype(refreshSpecial(object))(*)(LevelEditorLayer*, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xce74c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto LevelEditorLayer::removeAllObjects() -> decltype(removeAllObjects()) {
	using FunctionType = decltype(removeAllObjects())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xc7fe0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::removeAllObjectsOfType(int objectID) -> decltype(removeAllObjectsOfType(objectID)) {
	using FunctionType = decltype(removeAllObjectsOfType(objectID))(*)(LevelEditorLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xc80e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, objectID);
}

auto LevelEditorLayer::removeObject(GameObject* object, bool noUndo) -> decltype(removeObject(object, noUndo)) {
	using FunctionType = decltype(removeObject(object, noUndo))(*)(LevelEditorLayer*, GameObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xc7b04, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, noUndo);
}

auto LevelEditorLayer::removePlayerCollisionBlock() -> decltype(removePlayerCollisionBlock()) {
	using FunctionType = decltype(removePlayerCollisionBlock())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xc2f08, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::removeSpecial(GameObject* object) -> decltype(removeSpecial(object)) {
	using FunctionType = decltype(removeSpecial(object))(*)(LevelEditorLayer*, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xc7bd4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto LevelEditorLayer::resetDelayedSpawnNodes() -> decltype(resetDelayedSpawnNodes()) {
	using FunctionType = decltype(resetDelayedSpawnNodes())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd2470, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::resetEffectTriggerOptim(GameObject* object, cocos2d::CCArray* objects) -> decltype(resetEffectTriggerOptim(object, objects)) {
	using FunctionType = decltype(resetEffectTriggerOptim(object, objects))(*)(LevelEditorLayer*, GameObject*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd49f4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, objects);
}

auto LevelEditorLayer::resetMovingObjects() -> decltype(resetMovingObjects()) {
	using FunctionType = decltype(resetMovingObjects())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd4164, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::resetObjectVector() -> decltype(resetObjectVector()) {
	using FunctionType = decltype(resetObjectVector())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd38b8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::resetPlayback() -> decltype(resetPlayback()) {
	using FunctionType = decltype(resetPlayback())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd2304, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::resetToggledGroups() -> decltype(resetToggledGroups()) {
	using FunctionType = decltype(resetToggledGroups())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd1ef4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::resetToggledGroupsAndObjects() -> decltype(resetToggledGroupsAndObjects()) {
	using FunctionType = decltype(resetToggledGroupsAndObjects())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd3784, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::resetUnusedColorChannels() -> decltype(resetUnusedColorChannels()) {
	using FunctionType = decltype(resetUnusedColorChannels())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd153c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::reverseKeyframeAnimationOrder(int keyframeGroup) -> decltype(reverseKeyframeAnimationOrder(keyframeGroup)) {
	using FunctionType = decltype(reverseKeyframeAnimationOrder(keyframeGroup))(*)(LevelEditorLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd71ec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, keyframeGroup);
}

auto LevelEditorLayer::reverseObjectChanged(EffectGameObject* object) -> decltype(reverseObjectChanged(object)) {
	using FunctionType = decltype(reverseObjectChanged(object))(*)(LevelEditorLayer*, EffectGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd381c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto LevelEditorLayer::rotationForSlopeNearObject(GameObject* object) -> decltype(rotationForSlopeNearObject(object)) {
	using FunctionType = decltype(rotationForSlopeNearObject(object))(*)(LevelEditorLayer*, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xc65fc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto LevelEditorLayer::runColorEffect(EffectGameObject* object, int colorID, float delay, float interval, bool instant) -> decltype(runColorEffect(object, colorID, delay, interval, instant)) {
	using FunctionType = decltype(runColorEffect(object, colorID, delay, interval, instant))(*)(LevelEditorLayer*, EffectGameObject*, int, float, float, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd305c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, colorID, delay, interval, instant);
}

auto LevelEditorLayer::saveEditorPosition(cocos2d::CCPoint& position, int index) -> decltype(saveEditorPosition(position, index)) {
	using FunctionType = decltype(saveEditorPosition(position, index))(*)(LevelEditorLayer*, cocos2d::CCPoint&, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xcda24, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, position, index);
}

auto LevelEditorLayer::shouldBlend(int colorID) -> decltype(shouldBlend(colorID)) {
	using FunctionType = decltype(shouldBlend(colorID))(*)(LevelEditorLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xc4bcc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, colorID);
}

auto LevelEditorLayer::sortBatchnodeChildren(float unused) -> decltype(sortBatchnodeChildren(unused)) {
	using FunctionType = decltype(sortBatchnodeChildren(unused))(*)(LevelEditorLayer*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xce8bc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, unused);
}

auto LevelEditorLayer::spawnGroupPreview(int groupID, float xPos, float delay, float currentTime, float playTime, float boundTime, bool ordered, bool active) -> decltype(spawnGroupPreview(groupID, xPos, delay, currentTime, playTime, boundTime, ordered, active)) {
	using FunctionType = decltype(spawnGroupPreview(groupID, xPos, delay, currentTime, playTime, boundTime, ordered, active))(*)(LevelEditorLayer*, int, float, float, float, float, float, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd2588, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, groupID, xPos, delay, currentTime, playTime, boundTime, ordered, active);
}

auto LevelEditorLayer::stopPlayback() -> decltype(stopPlayback()) {
	using FunctionType = decltype(stopPlayback())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd4a9c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::stopTriggersInGroup(int id, float delay) -> decltype(stopTriggersInGroup(id, delay)) {
	using FunctionType = decltype(stopTriggersInGroup(id, delay))(*)(LevelEditorLayer*, int, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd32d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, delay);
}

auto LevelEditorLayer::timeObjectChanged() -> decltype(timeObjectChanged()) {
	using FunctionType = decltype(timeObjectChanged())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd38a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::toggleBackground(bool visible) -> decltype(toggleBackground(visible)) {
	using FunctionType = decltype(toggleBackground(visible))(*)(LevelEditorLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd2060, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, visible);
}

auto LevelEditorLayer::toggleGrid(bool visible) -> decltype(toggleGrid(visible)) {
	using FunctionType = decltype(toggleGrid(visible))(*)(LevelEditorLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd2078, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, visible);
}

auto LevelEditorLayer::toggleGround(bool enable) -> decltype(toggleGround(enable)) {
	using FunctionType = decltype(toggleGround(enable))(*)(LevelEditorLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xc4990, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, enable);
}

auto LevelEditorLayer::toggleGroupPreview(int id, bool enable) -> decltype(toggleGroupPreview(id, enable)) {
	using FunctionType = decltype(toggleGroupPreview(id, enable))(*)(LevelEditorLayer*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd3164, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, enable);
}

auto LevelEditorLayer::toggleLockActiveLayer() -> decltype(toggleLockActiveLayer()) {
	using FunctionType = decltype(toggleLockActiveLayer())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xcddc4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::transferDefaultColors(GJEffectManager* src, GJEffectManager* dest) -> decltype(transferDefaultColors(src, dest)) {
	using FunctionType = decltype(transferDefaultColors(src, dest))(*)(LevelEditorLayer*, GJEffectManager*, GJEffectManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd2088, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, src, dest);
}

auto LevelEditorLayer::triggerFollowCommand(EffectGameObject* object) -> decltype(triggerFollowCommand(object)) {
	using FunctionType = decltype(triggerFollowCommand(object))(*)(LevelEditorLayer*, EffectGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd4b7c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto LevelEditorLayer::triggerPlayerFollowCommand(EffectGameObject* object) -> decltype(triggerPlayerFollowCommand(object)) {
	using FunctionType = decltype(triggerPlayerFollowCommand(object))(*)(LevelEditorLayer*, EffectGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd4ba8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto LevelEditorLayer::triggerRotateCommand(EffectGameObject* object) -> decltype(triggerRotateCommand(object)) {
	using FunctionType = decltype(triggerRotateCommand(object))(*)(LevelEditorLayer*, EffectGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd4b10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto LevelEditorLayer::tryUpdateSpeedObject(EffectGameObject* object, bool noPreview) -> decltype(tryUpdateSpeedObject(object, noPreview)) {
	using FunctionType = decltype(tryUpdateSpeedObject(object, noPreview))(*)(LevelEditorLayer*, EffectGameObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xce370, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, noPreview);
}

auto LevelEditorLayer::typeExistsAtPosition(int objectID, cocos2d::CCPoint position, bool flipX, bool flipY, float rotation) -> decltype(typeExistsAtPosition(objectID, position, flipX, flipY, rotation)) {
	using FunctionType = decltype(typeExistsAtPosition(objectID, position, flipX, flipY, rotation))(*)(LevelEditorLayer*, int, cocos2d::CCPoint, bool, bool, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xc6150, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, objectID, position, flipX, flipY, rotation);
}

auto LevelEditorLayer::undoLastAction() -> decltype(undoLastAction()) {
	using FunctionType = decltype(undoLastAction())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xc8c28, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::unlockAllLayers() -> decltype(unlockAllLayers()) {
	using FunctionType = decltype(unlockAllLayers())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xcde58, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::updateAnimateOnTriggerObjects(bool animate) -> decltype(updateAnimateOnTriggerObjects(animate)) {
	using FunctionType = decltype(updateAnimateOnTriggerObjects(animate))(*)(LevelEditorLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xc4908, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, animate);
}

auto LevelEditorLayer::updateArt(float dt) -> decltype(updateArt(dt)) {
	using FunctionType = decltype(updateArt(dt))(*)(LevelEditorLayer*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xc49ac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt);
}

auto LevelEditorLayer::updateBlendValues() -> decltype(updateBlendValues()) {
	using FunctionType = decltype(updateBlendValues())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd2f54, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::updateEditor(float dt) -> decltype(updateEditor(dt)) {
	using FunctionType = decltype(updateEditor(dt))(*)(LevelEditorLayer*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xc36ac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt);
}

auto LevelEditorLayer::updateEditorMode() -> decltype(updateEditorMode()) {
	using FunctionType = decltype(updateEditorMode())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xc45dc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::updateGameObjects() -> decltype(updateGameObjects()) {
	using FunctionType = decltype(updateGameObjects())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xc3acc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::updateGridLayer() -> decltype(updateGridLayer()) {
	using FunctionType = decltype(updateGridLayer())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xce90c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::updateGridLayerParent() -> decltype(updateGridLayerParent()) {
	using FunctionType = decltype(updateGridLayerParent())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xc4b14, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::updateKeyframeObjects() -> decltype(updateKeyframeObjects()) {
	using FunctionType = decltype(updateKeyframeObjects())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xcf544, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::updateKeyframeVisibility(bool visible) -> decltype(updateKeyframeVisibility(visible)) {
	using FunctionType = decltype(updateKeyframeVisibility(visible))(*)(LevelEditorLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd7224, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, visible);
}

auto LevelEditorLayer::updateLevelFont(int index) -> decltype(updateLevelFont(index)) {
	using FunctionType = decltype(updateLevelFont(index))(*)(LevelEditorLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd4208, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index);
}

auto LevelEditorLayer::updateObjectColors(cocos2d::CCArray* gameObjects) -> decltype(updateObjectColors(gameObjects)) {
	using FunctionType = decltype(updateObjectColors(gameObjects))(*)(LevelEditorLayer*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xcf5f8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, gameObjects);
}

auto LevelEditorLayer::updateOptions() -> decltype(updateOptions()) {
	using FunctionType = decltype(updateOptions())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xc2618, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::updatePreviewAnim() -> decltype(updatePreviewAnim()) {
	using FunctionType = decltype(updatePreviewAnim())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd6f04, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::updatePreviewParticle(ParticleGameObject* object) -> decltype(updatePreviewParticle(object)) {
	using FunctionType = decltype(updatePreviewParticle(object))(*)(LevelEditorLayer*, ParticleGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xce26c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto LevelEditorLayer::updatePreviewParticles() -> decltype(updatePreviewParticles()) {
	using FunctionType = decltype(updatePreviewParticles())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd1f34, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::updateToggledGroups() -> decltype(updateToggledGroups()) {
	using FunctionType = decltype(updateToggledGroups())(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd2e3c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelEditorLayer::validGroup(GameObject* object, bool checkLockedLayers) -> decltype(validGroup(object, checkLockedLayers)) {
	using FunctionType = decltype(validGroup(object, checkLockedLayers))(*)(LevelEditorLayer*, GameObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xc6548, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, checkLockedLayers);
}
