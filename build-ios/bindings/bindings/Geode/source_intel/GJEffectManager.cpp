
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GJEffectManager.hpp>
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

auto GJEffectManager::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2dd140, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto GJEffectManager::getMixedColor(cocos2d::ccColor3B color1, cocos2d::ccColor3B color2, float ratio) -> decltype(getMixedColor(color1, color2, ratio)) {
	using FunctionType = decltype(getMixedColor(color1, color2, ratio))(*)(cocos2d::ccColor3B, cocos2d::ccColor3B, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2edd30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(color1, color2, ratio);
}

auto GJEffectManager::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJEffectManager::init), this);
	using FunctionType = decltype(init())(*)(GJEffectManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2dd4b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJEffectManager::activeColorForIndex(int index) -> decltype(activeColorForIndex(index)) {
	using FunctionType = decltype(activeColorForIndex(index))(*)(GJEffectManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2de420, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index);
}

auto GJEffectManager::activeOpacityForIndex(int index) -> decltype(activeOpacityForIndex(index)) {
	using FunctionType = decltype(activeOpacityForIndex(index))(*)(GJEffectManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2de580, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index);
}

auto GJEffectManager::addAllInheritedColorActions(cocos2d::CCArray* actions) -> decltype(addAllInheritedColorActions(actions)) {
	using FunctionType = decltype(addAllInheritedColorActions(actions))(*)(GJEffectManager*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2df010, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, actions);
}

auto GJEffectManager::addCountToItem(int itemId, int value) -> decltype(addCountToItem(itemId, value)) {
	using FunctionType = decltype(addCountToItem(itemId, value))(*)(GJEffectManager*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2ea210, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, itemId, value);
}

auto GJEffectManager::addMoveCalculation(CCMoveCNode* node, cocos2d::CCPoint offset, GameObject* object) -> decltype(addMoveCalculation(node, offset, object)) {
	using FunctionType = decltype(addMoveCalculation(node, offset, object))(*)(GJEffectManager*, CCMoveCNode*, cocos2d::CCPoint, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e7510, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, node, offset, object);
}

auto GJEffectManager::calculateBaseActiveColors() -> decltype(calculateBaseActiveColors()) {
	using FunctionType = decltype(calculateBaseActiveColors())(*)(GJEffectManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2de770, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJEffectManager::calculateInheritedColor(int id, ColorAction* action) -> decltype(calculateInheritedColor(id, action)) {
	using FunctionType = decltype(calculateInheritedColor(id, action))(*)(GJEffectManager*, int, ColorAction*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2df150, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, action);
}

auto GJEffectManager::calculateLightBGColor(cocos2d::ccColor3B color) -> decltype(calculateLightBGColor(color)) {
	using FunctionType = decltype(calculateLightBGColor(color))(*)(GJEffectManager*, cocos2d::ccColor3B);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2edba0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, color);
}

auto GJEffectManager::checkCollision(int const& blockAID, int const& blockBID) -> decltype(checkCollision(blockAID, blockBID)) {
	using FunctionType = decltype(checkCollision(blockAID, blockBID))(*)(GJEffectManager*, int const&, int const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e00e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, blockAID, blockBID);
}

auto GJEffectManager::colorActionChanged(ColorAction* action) -> decltype(colorActionChanged(action)) {
	using FunctionType = decltype(colorActionChanged(action))(*)(GJEffectManager*, ColorAction*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2df640, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, action);
}

auto GJEffectManager::colorExists(int col) -> decltype(colorExists(col)) {
	using FunctionType = decltype(colorExists(col))(*)(GJEffectManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2df610, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, col);
}

auto GJEffectManager::colorForEffect(cocos2d::ccColor3B color, cocos2d::ccHSVValue hsv) -> decltype(colorForEffect(color, hsv)) {
	using FunctionType = decltype(colorForEffect(color, hsv))(*)(GJEffectManager*, cocos2d::ccColor3B, cocos2d::ccHSVValue);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e0050, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, color, hsv);
}

auto GJEffectManager::colorForGroupID(int id, cocos2d::ccColor3B const& color, bool mainColor) -> decltype(colorForGroupID(id, color, mainColor)) {
	using FunctionType = decltype(colorForGroupID(id, color, mainColor))(*)(GJEffectManager*, int, cocos2d::ccColor3B const&, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e8ec0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, color, mainColor);
}

auto GJEffectManager::colorForIndex(int index) -> decltype(colorForIndex(index)) {
	using FunctionType = decltype(colorForIndex(index))(*)(GJEffectManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2de2a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index);
}

auto GJEffectManager::colorForPulseEffect(cocos2d::ccColor3B const& color, PulseEffectAction* action) -> decltype(colorForPulseEffect(color, action)) {
	using FunctionType = decltype(colorForPulseEffect(color, action))(*)(GJEffectManager*, cocos2d::ccColor3B const&, PulseEffectAction*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2df3d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, color, action);
}

auto GJEffectManager::controlActionsForControlID(int id, GJActionCommand command) -> decltype(controlActionsForControlID(id, command)) {
	using FunctionType = decltype(controlActionsForControlID(id, command))(*)(GJEffectManager*, int, GJActionCommand);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e26b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, command);
}

auto GJEffectManager::controlActionsForTrigger(EffectGameObject* object, GJActionCommand command) -> decltype(controlActionsForTrigger(object, command)) {
	using FunctionType = decltype(controlActionsForTrigger(object, command))(*)(GJEffectManager*, EffectGameObject*, GJActionCommand);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e3630, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, command);
}

auto GJEffectManager::countForItem(int id) -> decltype(countForItem(id)) {
	using FunctionType = decltype(countForItem(id))(*)(GJEffectManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2ea0b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GJEffectManager::createFollowCommand(float xMod, float yMod, float duration, int targetID, int centerID, int uniqueID, int controlID) -> decltype(createFollowCommand(xMod, yMod, duration, targetID, centerID, uniqueID, controlID)) {
	using FunctionType = decltype(createFollowCommand(xMod, yMod, duration, targetID, centerID, uniqueID, controlID))(*)(GJEffectManager*, float, float, float, int, int, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e0cc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, xMod, yMod, duration, targetID, centerID, uniqueID, controlID);
}

auto GJEffectManager::createKeyframeCommand(int targetID, cocos2d::CCArray* group, GameObject* object, int uniqueID, int controlID, bool temporary, float posXMod, float posYMod, float rotMod, float scaleXMod, float scaleYMod, float timeMod, gd::vector<int> const& remapKeys) -> decltype(createKeyframeCommand(targetID, group, object, uniqueID, controlID, temporary, posXMod, posYMod, rotMod, scaleXMod, scaleYMod, timeMod, remapKeys)) {
	using FunctionType = decltype(createKeyframeCommand(targetID, group, object, uniqueID, controlID, temporary, posXMod, posYMod, rotMod, scaleXMod, scaleYMod, timeMod, remapKeys))(*)(GJEffectManager*, int, cocos2d::CCArray*, GameObject*, int, int, bool, float, float, float, float, float, float, gd::vector<int> const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e0f80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, targetID, group, object, uniqueID, controlID, temporary, posXMod, posYMod, rotMod, scaleXMod, scaleYMod, timeMod, remapKeys);
}

auto GJEffectManager::createMoveCommand(cocos2d::CCPoint pt, int groupID, float duration, int easingType, float easingRate, bool lockPlayerX, bool lockPlayerY, bool lockCameraX, bool lockCameraY, float moveModX, float moveModY, int uniqueID, int controlID) -> decltype(createMoveCommand(pt, groupID, duration, easingType, easingRate, lockPlayerX, lockPlayerY, lockCameraX, lockCameraY, moveModX, moveModY, uniqueID, controlID)) {
	using FunctionType = decltype(createMoveCommand(pt, groupID, duration, easingType, easingRate, lockPlayerX, lockPlayerY, lockCameraX, lockCameraY, moveModX, moveModY, uniqueID, controlID))(*)(GJEffectManager*, cocos2d::CCPoint, int, float, int, float, bool, bool, bool, bool, float, float, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e0910, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, pt, groupID, duration, easingType, easingRate, lockPlayerX, lockPlayerY, lockCameraX, lockCameraY, moveModX, moveModY, uniqueID, controlID);
}

auto GJEffectManager::createPlayerFollowCommand(float delay, float speed, int offset, float maxSpeed, float duration, int targetID, int uniqueID, int controlID) -> decltype(createPlayerFollowCommand(delay, speed, offset, maxSpeed, duration, targetID, uniqueID, controlID)) {
	using FunctionType = decltype(createPlayerFollowCommand(delay, speed, offset, maxSpeed, duration, targetID, uniqueID, controlID))(*)(GJEffectManager*, float, float, int, float, float, int, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e0da0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, delay, speed, offset, maxSpeed, duration, targetID, uniqueID, controlID);
}

auto GJEffectManager::createRotateCommand(float offset, float duration, int targetID, int centerID, int easingType, float easingRate, bool lockRotation, bool player1, bool player2, int uniqueID, int controlID) -> decltype(createRotateCommand(offset, duration, targetID, centerID, easingType, easingRate, lockRotation, player1, player2, uniqueID, controlID)) {
	using FunctionType = decltype(createRotateCommand(offset, duration, targetID, centerID, easingType, easingRate, lockRotation, player1, player2, uniqueID, controlID))(*)(GJEffectManager*, float, float, int, int, int, float, bool, bool, bool, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e0a70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, offset, duration, targetID, centerID, easingType, easingRate, lockRotation, player1, player2, uniqueID, controlID);
}

auto GJEffectManager::createTransformCommand(double scaleX, double scaleY, double property450, double property451, bool onlyMove, float duration, int targetID, int centerID, int easingType, float easingRate, bool p10, bool relativeRotation, int uniqueID, int controlID) -> decltype(createTransformCommand(scaleX, scaleY, property450, property451, onlyMove, duration, targetID, centerID, easingType, easingRate, p10, relativeRotation, uniqueID, controlID)) {
	using FunctionType = decltype(createTransformCommand(scaleX, scaleY, property450, property451, onlyMove, duration, targetID, centerID, easingType, easingRate, p10, relativeRotation, uniqueID, controlID))(*)(GJEffectManager*, double, double, double, double, bool, float, int, int, int, float, bool, bool, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e0b80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, scaleX, scaleY, property450, property451, onlyMove, duration, targetID, centerID, easingType, easingRate, p10, relativeRotation, uniqueID, controlID);
}

auto GJEffectManager::getAllColorActions() -> decltype(getAllColorActions()) {
	using FunctionType = decltype(getAllColorActions())(*)(GJEffectManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2de180, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJEffectManager::getAllColorSprites() -> decltype(getAllColorSprites()) {
	using FunctionType = decltype(getAllColorSprites())(*)(GJEffectManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2de1e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJEffectManager::getColorAction(int index) -> decltype(getColorAction(index)) {
	using FunctionType = decltype(getColorAction(index))(*)(GJEffectManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2de2c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index);
}

auto GJEffectManager::getColorSprite(int index) -> decltype(getColorSprite(index)) {
	using FunctionType = decltype(getColorSprite(index))(*)(GJEffectManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2de470, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index);
}

auto GJEffectManager::getLoadedMoveOffset(gd::unordered_map<int, std::pair<double, double>>& offsets) -> decltype(getLoadedMoveOffset(offsets)) {
	using FunctionType = decltype(getLoadedMoveOffset(offsets))(*)(GJEffectManager*, gd::unordered_map<int, std::pair<double, double>>&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e7ca0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, offsets);
}

auto GJEffectManager::getMoveCommandNode(GroupCommandObject2* command) -> decltype(getMoveCommandNode(command)) {
	using FunctionType = decltype(getMoveCommandNode(command))(*)(GJEffectManager*, GroupCommandObject2*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e2460, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, command);
}

auto GJEffectManager::getMoveCommandObject() -> decltype(getMoveCommandObject()) {
	using FunctionType = decltype(getMoveCommandObject())(*)(GJEffectManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e46e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJEffectManager::getOpacityActionForGroup(int id) -> decltype(getOpacityActionForGroup(id)) {
	using FunctionType = decltype(getOpacityActionForGroup(id))(*)(GJEffectManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e7e10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GJEffectManager::getPersistentState(gd::unordered_map<int, int>& counts, gd::unordered_map<int, TimerItem>& items) -> decltype(getPersistentState(counts, items)) {
	using FunctionType = decltype(getPersistentState(counts, items))(*)(GJEffectManager*, gd::unordered_map<int, int>&, gd::unordered_map<int, TimerItem>&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2ebef0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, counts, items);
}

auto GJEffectManager::getPersistentStateString() -> decltype(getPersistentStateString()) {
	using FunctionType = decltype(getPersistentStateString())(*)(GJEffectManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2eaa80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJEffectManager::getSaveString() -> decltype(getSaveString()) {
	using FunctionType = decltype(getSaveString())(*)(GJEffectManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2edf80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJEffectManager::getTempGroupCommand() -> decltype(getTempGroupCommand()) {
	using FunctionType = decltype(getTempGroupCommand())(*)(GJEffectManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e4890, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJEffectManager::handleObjectCollision(bool triggerOnExit, int blockAID, int blockBID) -> decltype(handleObjectCollision(triggerOnExit, blockAID, blockBID)) {
	using FunctionType = decltype(handleObjectCollision(triggerOnExit, blockAID, blockBID))(*)(GJEffectManager*, bool, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e0340, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, triggerOnExit, blockAID, blockBID);
}

auto GJEffectManager::hasActiveDualTouch() -> decltype(hasActiveDualTouch()) {
	using FunctionType = decltype(hasActiveDualTouch())(*)(GJEffectManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e98f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJEffectManager::hasBeenTriggered(int objectUniqueID, int playerUniqueID) -> decltype(hasBeenTriggered(objectUniqueID, playerUniqueID)) {
	using FunctionType = decltype(hasBeenTriggered(objectUniqueID, playerUniqueID))(*)(GJEffectManager*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e9750, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, objectUniqueID, playerUniqueID);
}

auto GJEffectManager::hasPulseEffectForGroupID(int id) -> decltype(hasPulseEffectForGroupID(id)) {
	using FunctionType = decltype(hasPulseEffectForGroupID(id))(*)(GJEffectManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e8d60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GJEffectManager::isGroupEnabled(int id) -> decltype(isGroupEnabled(id)) {
	using FunctionType = decltype(isGroupEnabled(id))(*)(GJEffectManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e97a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GJEffectManager::itemWasUsed(int id) -> decltype(itemWasUsed(id)) {
	using FunctionType = decltype(itemWasUsed(id))(*)(GJEffectManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2ec330, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GJEffectManager::keyForGroupIDColor(int id, cocos2d::ccColor3B const& color, bool mainColor) -> decltype(keyForGroupIDColor(id, color, mainColor)) {
	using FunctionType = decltype(keyForGroupIDColor(id, color, mainColor))(*)(GJEffectManager*, int, cocos2d::ccColor3B const&, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e8aa0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, color, mainColor);
}

auto GJEffectManager::loadFromState(EffectManagerState& state) -> decltype(loadFromState(state)) {
	using FunctionType = decltype(loadFromState(state))(*)(GJEffectManager*, EffectManagerState&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2eee70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, state);
}

auto GJEffectManager::loadPersistentStateString(gd::string state) -> decltype(loadPersistentStateString(state)) {
	using FunctionType = decltype(loadPersistentStateString(state))(*)(GJEffectManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2eb9d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, state);
}

auto GJEffectManager::objectsCollided(int blockAID, int blockBID) -> decltype(objectsCollided(blockAID, blockBID)) {
	using FunctionType = decltype(objectsCollided(blockAID, blockBID))(*)(GJEffectManager*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e0550, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, blockAID, blockBID);
}

auto GJEffectManager::opacityForIndex(int index) -> decltype(opacityForIndex(index)) {
	using FunctionType = decltype(opacityForIndex(index))(*)(GJEffectManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2de410, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index);
}

auto GJEffectManager::opacityModForGroup(int id) -> decltype(opacityModForGroup(id)) {
	using FunctionType = decltype(opacityModForGroup(id))(*)(GJEffectManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e81b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GJEffectManager::pauseTimer(int id) -> decltype(pauseTimer(id)) {
	using FunctionType = decltype(pauseTimer(id))(*)(GJEffectManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2ecac0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GJEffectManager::playerButton(bool down, bool player1) -> decltype(playerButton(down, player1)) {
	using FunctionType = decltype(playerButton(down, player1))(*)(GJEffectManager*, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e9930, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, down, player1);
}

auto GJEffectManager::playerDied() -> decltype(playerDied()) {
	using FunctionType = decltype(playerDied())(*)(GJEffectManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e9ca0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJEffectManager::postCollisionCheck() -> decltype(postCollisionCheck()) {
	using FunctionType = decltype(postCollisionCheck())(*)(GJEffectManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e0270, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJEffectManager::postMoveActions() -> decltype(postMoveActions()) {
	using FunctionType = decltype(postMoveActions())(*)(GJEffectManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e76d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJEffectManager::preCollisionCheck() -> decltype(preCollisionCheck()) {
	using FunctionType = decltype(preCollisionCheck())(*)(GJEffectManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e0250, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJEffectManager::prepareMoveActions(float dt, bool intermediate) -> decltype(prepareMoveActions(dt, intermediate)) {
	using FunctionType = decltype(prepareMoveActions(dt, intermediate))(*)(GJEffectManager*, float, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e55d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt, intermediate);
}

auto GJEffectManager::processColors() -> decltype(processColors()) {
	using FunctionType = decltype(processColors())(*)(GJEffectManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2de5e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJEffectManager::processCopyColorPulseActions() -> decltype(processCopyColorPulseActions()) {
	using FunctionType = decltype(processCopyColorPulseActions())(*)(GJEffectManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2deca0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJEffectManager::processInheritedColors() -> decltype(processInheritedColors()) {
	using FunctionType = decltype(processInheritedColors())(*)(GJEffectManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2de900, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJEffectManager::processMoveCalculations() -> decltype(processMoveCalculations()) {
	using FunctionType = decltype(processMoveCalculations())(*)(GJEffectManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e7b70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJEffectManager::processPulseActions() -> decltype(processPulseActions()) {
	using FunctionType = decltype(processPulseActions())(*)(GJEffectManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2de830, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJEffectManager::registerCollisionTrigger(int targetID, int blockAID, int blockBID, bool triggerOnExit, bool activateGroup, gd::vector<int> const& remapKeys, int uniqueID, int controlID) -> decltype(registerCollisionTrigger(targetID, blockAID, blockBID, triggerOnExit, activateGroup, remapKeys, uniqueID, controlID)) {
	using FunctionType = decltype(registerCollisionTrigger(targetID, blockAID, blockBID, triggerOnExit, activateGroup, remapKeys, uniqueID, controlID))(*)(GJEffectManager*, int, int, int, bool, bool, gd::vector<int> const&, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e0750, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, targetID, blockAID, blockBID, triggerOnExit, activateGroup, remapKeys, uniqueID, controlID);
}

auto GJEffectManager::registerRotationCommand(GroupCommandObject2* object, bool clear) -> decltype(registerRotationCommand(object, clear)) {
	using FunctionType = decltype(registerRotationCommand(object, clear))(*)(GJEffectManager*, GroupCommandObject2*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e4ef0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, clear);
}

auto GJEffectManager::removeAllPulseActions() -> decltype(removeAllPulseActions()) {
	using FunctionType = decltype(removeAllPulseActions())(*)(GJEffectManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2dfdc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJEffectManager::removeColorAction(int id) -> decltype(removeColorAction(id)) {
	using FunctionType = decltype(removeColorAction(id))(*)(GJEffectManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2df5b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GJEffectManager::removePersistentFromAllItems() -> decltype(removePersistentFromAllItems()) {
	using FunctionType = decltype(removePersistentFromAllItems())(*)(GJEffectManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2ec550, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJEffectManager::removePersistentFromAllTimers() -> decltype(removePersistentFromAllTimers()) {
	using FunctionType = decltype(removePersistentFromAllTimers())(*)(GJEffectManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2ec600, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJEffectManager::removeTriggeredID(int objectUniqueID, int playerUniqueID) -> decltype(removeTriggeredID(objectUniqueID, playerUniqueID)) {
	using FunctionType = decltype(removeTriggeredID(objectUniqueID, playerUniqueID))(*)(GJEffectManager*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e9670, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, objectUniqueID, playerUniqueID);
}

auto GJEffectManager::reset() -> decltype(reset()) {
	using FunctionType = decltype(reset())(*)(GJEffectManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2dd730, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJEffectManager::resetEffects() -> decltype(resetEffects()) {
	using FunctionType = decltype(resetEffects())(*)(GJEffectManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2dd850, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJEffectManager::resetMoveActions() -> decltype(resetMoveActions()) {
	using FunctionType = decltype(resetMoveActions())(*)(GJEffectManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2de080, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJEffectManager::resetTempGroupCommands(bool noRemove) -> decltype(resetTempGroupCommands(noRemove)) {
	using FunctionType = decltype(resetTempGroupCommands(noRemove))(*)(GJEffectManager*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e52b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, noRemove);
}

auto GJEffectManager::resetToggledGroups() -> decltype(resetToggledGroups()) {
	using FunctionType = decltype(resetToggledGroups())(*)(GJEffectManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2dfea0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJEffectManager::resetTriggeredIDs() -> decltype(resetTriggeredIDs()) {
	using FunctionType = decltype(resetTriggeredIDs())(*)(GJEffectManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e0010, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJEffectManager::resetUsedItemState() -> decltype(resetUsedItemState()) {
	using FunctionType = decltype(resetUsedItemState())(*)(GJEffectManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2ec260, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJEffectManager::resumeTimer(int id) -> decltype(resumeTimer(id)) {
	using FunctionType = decltype(resumeTimer(id))(*)(GJEffectManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2ecc60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GJEffectManager::runCountTrigger(int id, int targetCount, bool multiActivate, int targetID, bool activateGroup, gd::vector<int> const& remapKeys, int uniqueID, int controlID) -> decltype(runCountTrigger(id, targetCount, multiActivate, targetID, activateGroup, remapKeys, uniqueID, controlID)) {
	using FunctionType = decltype(runCountTrigger(id, targetCount, multiActivate, targetID, activateGroup, remapKeys, uniqueID, controlID))(*)(GJEffectManager*, int, int, bool, int, bool, gd::vector<int> const&, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e9e00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, targetCount, multiActivate, targetID, activateGroup, remapKeys, uniqueID, controlID);
}

auto GJEffectManager::runDeathTrigger(int targetID, bool activateGroup, gd::vector<int> const& remapKeys, int uniqueID, int controlID) -> decltype(runDeathTrigger(targetID, activateGroup, remapKeys, uniqueID, controlID)) {
	using FunctionType = decltype(runDeathTrigger(targetID, activateGroup, remapKeys, uniqueID, controlID))(*)(GJEffectManager*, int, bool, gd::vector<int> const&, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e9bc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, targetID, activateGroup, remapKeys, uniqueID, controlID);
}

auto GJEffectManager::runOpacityActionOnGroup(int targetID, float duration, float opacity, int uniqueID, int controlID) -> decltype(runOpacityActionOnGroup(targetID, duration, opacity, uniqueID, controlID)) {
	using FunctionType = decltype(runOpacityActionOnGroup(targetID, duration, opacity, uniqueID, controlID))(*)(GJEffectManager*, int, float, float, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e7f70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, targetID, duration, opacity, uniqueID, controlID);
}

auto GJEffectManager::runPulseEffect(int targetID, bool targetGroup, float fadeInDuration, float holdDuration, float fadeOutDuration, PulseEffectType effectType, cocos2d::ccColor3B targetColor, cocos2d::ccHSVValue targetHSV, int copyID, bool mainOnly, bool detailOnly, bool exclusive, bool legacyHSV, int uniqueID, int controlID) -> decltype(runPulseEffect(targetID, targetGroup, fadeInDuration, holdDuration, fadeOutDuration, effectType, targetColor, targetHSV, copyID, mainOnly, detailOnly, exclusive, legacyHSV, uniqueID, controlID)) {
	using FunctionType = decltype(runPulseEffect(targetID, targetGroup, fadeInDuration, holdDuration, fadeOutDuration, effectType, targetColor, targetHSV, copyID, mainOnly, detailOnly, exclusive, legacyHSV, uniqueID, controlID))(*)(GJEffectManager*, int, bool, float, float, float, PulseEffectType, cocos2d::ccColor3B, cocos2d::ccHSVValue, int, bool, bool, bool, bool, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e83e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, targetID, targetGroup, fadeInDuration, holdDuration, fadeOutDuration, effectType, targetColor, targetHSV, copyID, mainOnly, detailOnly, exclusive, legacyHSV, uniqueID, controlID);
}

auto GJEffectManager::runTimerTrigger(int id, double targetTime, bool multiActivate, int targetID, gd::vector<int> const& remapKeys, int uniqueID, int controlID) -> decltype(runTimerTrigger(id, targetTime, multiActivate, targetID, remapKeys, uniqueID, controlID)) {
	using FunctionType = decltype(runTimerTrigger(id, targetTime, multiActivate, targetID, remapKeys, uniqueID, controlID))(*)(GJEffectManager*, int, double, bool, int, gd::vector<int> const&, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2ece00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, targetTime, multiActivate, targetID, remapKeys, uniqueID, controlID);
}

auto GJEffectManager::runTouchTriggerCommand(int targetID, bool holdMode, TouchTriggerType touchType, TouchTriggerControl touchControl, bool dualMode, gd::vector<int> const& remapKeys, int uniqueID, int controlID) -> decltype(runTouchTriggerCommand(targetID, holdMode, touchType, touchControl, dualMode, remapKeys, uniqueID, controlID)) {
	using FunctionType = decltype(runTouchTriggerCommand(targetID, holdMode, touchType, touchControl, dualMode, remapKeys, uniqueID, controlID))(*)(GJEffectManager*, int, bool, TouchTriggerType, TouchTriggerControl, bool, gd::vector<int> const&, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e97e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, targetID, holdMode, touchType, touchControl, dualMode, remapKeys, uniqueID, controlID);
}

auto GJEffectManager::saveCompletedMove(int groupId, double dx, double dy) -> decltype(saveCompletedMove(groupId, dx, dy)) {
	using FunctionType = decltype(saveCompletedMove(groupId, dx, dy))(*)(GJEffectManager*, int, double, double);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e7ae0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, groupId, dx, dy);
}

auto GJEffectManager::saveToState(EffectManagerState& state) -> decltype(saveToState(state)) {
	using FunctionType = decltype(saveToState(state))(*)(GJEffectManager*, EffectManagerState&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2ee9a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, state);
}

auto GJEffectManager::setColorAction(ColorAction* action, int id) -> decltype(setColorAction(action, id)) {
	using FunctionType = decltype(setColorAction(action, id))(*)(GJEffectManager*, ColorAction*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2df540, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, action, id);
}

auto GJEffectManager::setFollowing(int targetID, int targetPosID, bool following) -> decltype(setFollowing(targetID, targetPosID, following)) {
	using FunctionType = decltype(setFollowing(targetID, targetPosID, following))(*)(GJEffectManager*, int, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2eddf0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, targetID, targetPosID, following);
}

auto GJEffectManager::setupFromString(gd::string str) -> decltype(setupFromString(str)) {
	using FunctionType = decltype(setupFromString(str))(*)(GJEffectManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2ee2b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, str);
}

auto GJEffectManager::shouldBlend(int id) -> decltype(shouldBlend(id)) {
	using FunctionType = decltype(shouldBlend(id))(*)(GJEffectManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2de5b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GJEffectManager::spawnGroup(int targetID, float delay, bool spawnOrdered, gd::vector<int> const& remapKeys, int uniqueID, int controlID) -> decltype(spawnGroup(targetID, delay, spawnOrdered, remapKeys, uniqueID, controlID)) {
	using FunctionType = decltype(spawnGroup(targetID, delay, spawnOrdered, remapKeys, uniqueID, controlID))(*)(GJEffectManager*, int, float, bool, gd::vector<int> const&, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e75b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, targetID, delay, spawnOrdered, remapKeys, uniqueID, controlID);
}

auto GJEffectManager::spawnObject(GameObject* object, float delay, gd::vector<int> const& remapKeys, int uniqueID, int controlID) -> decltype(spawnObject(object, delay, remapKeys, uniqueID, controlID)) {
	using FunctionType = decltype(spawnObject(object, delay, remapKeys, uniqueID, controlID))(*)(GJEffectManager*, GameObject*, float, gd::vector<int> const&, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e9110, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, delay, remapKeys, uniqueID, controlID);
}

auto GJEffectManager::startTimer(int id, double startTime, double targetTime, bool stopTime, bool active, bool dontOverride, float timeMod, bool ignoreTimewarp, int targetID, gd::vector<int> const& remapKeys, int uniqueID, int controlID) -> decltype(startTimer(id, startTime, targetTime, stopTime, active, dontOverride, timeMod, ignoreTimewarp, targetID, remapKeys, uniqueID, controlID)) {
	using FunctionType = decltype(startTimer(id, startTime, targetTime, stopTime, active, dontOverride, timeMod, ignoreTimewarp, targetID, remapKeys, uniqueID, controlID))(*)(GJEffectManager*, int, double, double, bool, bool, bool, float, bool, int, gd::vector<int> const&, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2ec670, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, startTime, targetTime, stopTime, active, dontOverride, timeMod, ignoreTimewarp, targetID, remapKeys, uniqueID, controlID);
}

auto GJEffectManager::storeTriggeredID(int objectUniqueID, int playerUniqueID) -> decltype(storeTriggeredID(objectUniqueID, playerUniqueID)) {
	using FunctionType = decltype(storeTriggeredID(objectUniqueID, playerUniqueID))(*)(GJEffectManager*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e95b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, objectUniqueID, playerUniqueID);
}

auto GJEffectManager::timeForItem(int id) -> decltype(timeForItem(id)) {
	using FunctionType = decltype(timeForItem(id))(*)(GJEffectManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2eda50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GJEffectManager::timerExists(int id) -> decltype(timerExists(id)) {
	using FunctionType = decltype(timerExists(id))(*)(GJEffectManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2ec980, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GJEffectManager::timerWasUsed(int id) -> decltype(timerWasUsed(id)) {
	using FunctionType = decltype(timerWasUsed(id))(*)(GJEffectManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2ec340, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GJEffectManager::toggleGroup(int id, bool activate) -> decltype(toggleGroup(id, activate)) {
	using FunctionType = decltype(toggleGroup(id, activate))(*)(GJEffectManager*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e0890, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, activate);
}

auto GJEffectManager::toggleItemPersistent(int id, bool persistent) -> decltype(toggleItemPersistent(id, persistent)) {
	using FunctionType = decltype(toggleItemPersistent(id, persistent))(*)(GJEffectManager*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2ec350, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, persistent);
}

auto GJEffectManager::toggleTimerPersistent(int id, bool persistent) -> decltype(toggleTimerPersistent(id, persistent)) {
	using FunctionType = decltype(toggleTimerPersistent(id, persistent))(*)(GJEffectManager*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2ec5c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, persistent);
}

auto GJEffectManager::transferPersistentItems() -> decltype(transferPersistentItems()) {
	using FunctionType = decltype(transferPersistentItems())(*)(GJEffectManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2dff70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJEffectManager::traverseInheritanceChain(InheritanceNode* node) -> decltype(traverseInheritanceChain(node)) {
	using FunctionType = decltype(traverseInheritanceChain(node))(*)(GJEffectManager*, InheritanceNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2df0b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, node);
}

auto GJEffectManager::tryGetMoveCommandNode(int id) -> decltype(tryGetMoveCommandNode(id)) {
	using FunctionType = decltype(tryGetMoveCommandNode(id))(*)(GJEffectManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e4d90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GJEffectManager::updateActiveOpacityEffects() -> decltype(updateActiveOpacityEffects()) {
	using FunctionType = decltype(updateActiveOpacityEffects())(*)(GJEffectManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e8340, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJEffectManager::updateColorAction(ColorAction* action) -> decltype(updateColorAction(action)) {
	using FunctionType = decltype(updateColorAction(action))(*)(GJEffectManager*, ColorAction*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e7dd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, action);
}

auto GJEffectManager::updateColorEffects(float dt) -> decltype(updateColorEffects(dt)) {
	using FunctionType = decltype(updateColorEffects(dt))(*)(GJEffectManager*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2df790, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt);
}

auto GJEffectManager::updateColors(cocos2d::ccColor3B color1, cocos2d::ccColor3B color2) -> decltype(updateColors(color1, color2)) {
	using FunctionType = decltype(updateColors(color1, color2))(*)(GJEffectManager*, cocos2d::ccColor3B, cocos2d::ccColor3B);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2de240, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, color1, color2);
}

auto GJEffectManager::updateCountForItem(int id, int count) -> decltype(updateCountForItem(id, count)) {
	using FunctionType = decltype(updateCountForItem(id, count))(*)(GJEffectManager*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2ea280, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, count);
}

auto GJEffectManager::updateEffects(float dt) -> decltype(updateEffects(dt)) {
	using FunctionType = decltype(updateEffects(dt))(*)(GJEffectManager*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2df670, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt);
}

auto GJEffectManager::updateOpacityAction(OpacityEffectAction* action) -> decltype(updateOpacityAction(action)) {
	using FunctionType = decltype(updateOpacityAction(action))(*)(GJEffectManager*, OpacityEffectAction*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e8300, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, action);
}

auto GJEffectManager::updateOpacityEffects(float dt) -> decltype(updateOpacityEffects(dt)) {
	using FunctionType = decltype(updateOpacityEffects(dt))(*)(GJEffectManager*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2dfcb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt);
}

auto GJEffectManager::updatePulseEffects(float dt) -> decltype(updatePulseEffects(dt)) {
	using FunctionType = decltype(updatePulseEffects(dt))(*)(GJEffectManager*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2df970, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt);
}

auto GJEffectManager::updateSpawnTriggers(float dt) -> decltype(updateSpawnTriggers(dt)) {
	using FunctionType = decltype(updateSpawnTriggers(dt))(*)(GJEffectManager*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e9230, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt);
}

auto GJEffectManager::updateTimer(int id, double time) -> decltype(updateTimer(id, time)) {
	using FunctionType = decltype(updateTimer(id, time))(*)(GJEffectManager*, int, double);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2ecf50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, time);
}

auto GJEffectManager::updateTimers(float dt, float timeWarp) -> decltype(updateTimers(dt, timeWarp)) {
	using FunctionType = decltype(updateTimers(dt, timeWarp))(*)(GJEffectManager*, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2ed130, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt, timeWarp);
}

auto GJEffectManager::wasFollowing(int targetID, int targetPosID) -> decltype(wasFollowing(targetID, targetPosID)) {
	using FunctionType = decltype(wasFollowing(targetID, targetPosID))(*)(GJEffectManager*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2ede30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, targetID, targetPosID);
}

auto GJEffectManager::wouldCreateLoop(InheritanceNode* node, int id) -> decltype(wouldCreateLoop(node, id)) {
	using FunctionType = decltype(wouldCreateLoop(node, id))(*)(GJEffectManager*, InheritanceNode*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2df080, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, node, id);
}
