
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/EnhancedGameObject.hpp>
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

auto EnhancedGameObject::create(char const* frame) -> decltype(create(frame)) {
	using FunctionType = decltype(create(frame))(*)(char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e6420, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(frame);
}

auto EnhancedGameObject::customSetup() -> decltype(customSetup()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&EnhancedGameObject::customSetup), this);
	using FunctionType = decltype(customSetup())(*)(EnhancedGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4fb368, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto EnhancedGameObject::resetObject() -> decltype(resetObject()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&EnhancedGameObject::resetObject), this);
	using FunctionType = decltype(resetObject())(*)(EnhancedGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4facc4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto EnhancedGameObject::deactivateObject(bool deactivate) -> decltype(deactivateObject(deactivate)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&EnhancedGameObject::deactivateObject), this);
	using FunctionType = decltype(deactivateObject(deactivate))(*)(EnhancedGameObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4fc5a4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, deactivate);
}

auto EnhancedGameObject::customObjectSetup(gd::vector<gd::string>& values, gd::vector<void*>& exists) -> decltype(customObjectSetup(values, exists)) {
	auto self = addresser::thunkAdjust(Resolve<gd::vector<gd::string>&, gd::vector<void*>&>::func(&EnhancedGameObject::customObjectSetup), this);
	using FunctionType = decltype(customObjectSetup(values, exists))(*)(EnhancedGameObject*, gd::vector<gd::string>&, gd::vector<void*>&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4faf7c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, values, exists);
}

auto EnhancedGameObject::getSaveString(GJBaseGameLayer* layer) -> decltype(getSaveString(layer)) {
	auto self = addresser::thunkAdjust(Resolve<GJBaseGameLayer*>::func(&EnhancedGameObject::getSaveString), this);
	using FunctionType = decltype(getSaveString(layer))(*)(EnhancedGameObject*, GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4fc6f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, layer);
}

auto EnhancedGameObject::triggerActivated(float xPosition) -> decltype(triggerActivated(xPosition)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&EnhancedGameObject::triggerActivated), this);
	using FunctionType = decltype(triggerActivated(xPosition))(*)(EnhancedGameObject*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4fadf0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, xPosition);
}

auto EnhancedGameObject::restoreObject() -> decltype(restoreObject()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&EnhancedGameObject::restoreObject), this);
	using FunctionType = decltype(restoreObject())(*)(EnhancedGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4fad40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto EnhancedGameObject::animationTriggered() -> decltype(animationTriggered()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&EnhancedGameObject::animationTriggered), this);
	using FunctionType = decltype(animationTriggered())(*)(EnhancedGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4faeec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto EnhancedGameObject::activatedByPlayer(PlayerObject* player) -> decltype(activatedByPlayer(player)) {
	auto self = addresser::thunkAdjust(Resolve<PlayerObject*>::func(&EnhancedGameObject::activatedByPlayer), this);
	using FunctionType = decltype(activatedByPlayer(player))(*)(EnhancedGameObject*, PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4fadfc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, player);
}

auto EnhancedGameObject::hasBeenActivatedByPlayer(PlayerObject* player) -> decltype(hasBeenActivatedByPlayer(player)) {
	auto self = addresser::thunkAdjust(Resolve<PlayerObject*>::func(&EnhancedGameObject::hasBeenActivatedByPlayer), this);
	using FunctionType = decltype(hasBeenActivatedByPlayer(player))(*)(EnhancedGameObject*, PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4fae5c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, player);
}

auto EnhancedGameObject::hasBeenActivated() -> decltype(hasBeenActivated()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&EnhancedGameObject::hasBeenActivated), this);
	using FunctionType = decltype(hasBeenActivated())(*)(EnhancedGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4faecc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto EnhancedGameObject::saveActiveColors() -> decltype(saveActiveColors()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&EnhancedGameObject::saveActiveColors), this);
	using FunctionType = decltype(saveActiveColors())(*)(EnhancedGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4faf00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto EnhancedGameObject::canAllowMultiActivate() -> decltype(canAllowMultiActivate()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&EnhancedGameObject::canAllowMultiActivate), this);
	using FunctionType = decltype(canAllowMultiActivate())(*)(EnhancedGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4fab90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto EnhancedGameObject::getHasSyncedAnimation() -> decltype(getHasSyncedAnimation()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&EnhancedGameObject::getHasSyncedAnimation), this);
	using FunctionType = decltype(getHasSyncedAnimation())(*)(EnhancedGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1a1f68, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto EnhancedGameObject::getHasRotateAction() -> decltype(getHasRotateAction()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&EnhancedGameObject::getHasRotateAction), this);
	using FunctionType = decltype(getHasRotateAction())(*)(EnhancedGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1a1f70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto EnhancedGameObject::canMultiActivate(bool multiActivate) -> decltype(canMultiActivate(multiActivate)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&EnhancedGameObject::canMultiActivate), this);
	using FunctionType = decltype(canMultiActivate(multiActivate))(*)(EnhancedGameObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4fadd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, multiActivate);
}

auto EnhancedGameObject::powerOnObject(int state) -> decltype(powerOnObject(state)) {
	auto self = addresser::thunkAdjust(Resolve<int>::func(&EnhancedGameObject::powerOnObject), this);
	using FunctionType = decltype(powerOnObject(state))(*)(EnhancedGameObject*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4fad78, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, state);
}

auto EnhancedGameObject::powerOffObject() -> decltype(powerOffObject()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&EnhancedGameObject::powerOffObject), this);
	using FunctionType = decltype(powerOffObject())(*)(EnhancedGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4fad8c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto EnhancedGameObject::updateSyncedAnimation(float totalTime, int frameIndex) -> decltype(updateSyncedAnimation(totalTime, frameIndex)) {
	auto self = addresser::thunkAdjust(Resolve<float, int>::func(&EnhancedGameObject::updateSyncedAnimation), this);
	using FunctionType = decltype(updateSyncedAnimation(totalTime, frameIndex))(*)(EnhancedGameObject*, float, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x200828, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, totalTime, frameIndex);
}

auto EnhancedGameObject::updateAnimateOnTrigger(bool animate) -> decltype(updateAnimateOnTrigger(animate)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&EnhancedGameObject::updateAnimateOnTrigger), this);
	using FunctionType = decltype(updateAnimateOnTrigger(animate))(*)(EnhancedGameObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x201c64, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, animate);
}

auto EnhancedGameObject::createRotateAction(float angle, int clockwiseDirection) -> decltype(createRotateAction(angle, clockwiseDirection)) {
	using FunctionType = decltype(createRotateAction(angle, clockwiseDirection))(*)(EnhancedGameObject*, float, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4fb2f8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, angle, clockwiseDirection);
}

auto EnhancedGameObject::init(char const* frame) -> decltype(init(frame)) {
	using FunctionType = decltype(init(frame))(*)(EnhancedGameObject*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4fab50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, frame);
}

auto EnhancedGameObject::previewAnimateOnTrigger() -> decltype(previewAnimateOnTrigger()) {
	using FunctionType = decltype(previewAnimateOnTrigger())(*)(EnhancedGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x201d5c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto EnhancedGameObject::refreshRotateAction() -> decltype(refreshRotateAction()) {
	using FunctionType = decltype(refreshRotateAction())(*)(EnhancedGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4fdce0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto EnhancedGameObject::resetSyncedAnimation() -> decltype(resetSyncedAnimation()) {
	using FunctionType = decltype(resetSyncedAnimation())(*)(EnhancedGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x201d9c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto EnhancedGameObject::setupAnimationVariables() -> decltype(setupAnimationVariables()) {
	using FunctionType = decltype(setupAnimationVariables())(*)(EnhancedGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x201dcc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto EnhancedGameObject::triggerAnimation() -> decltype(triggerAnimation()) {
	using FunctionType = decltype(triggerAnimation())(*)(EnhancedGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x201c00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto EnhancedGameObject::updateRotateAction(float dt) -> decltype(updateRotateAction(dt)) {
	using FunctionType = decltype(updateRotateAction(dt))(*)(EnhancedGameObject*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4fdd54, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt);
}

auto EnhancedGameObject::updateState(int state) -> decltype(updateState(state)) {
	using FunctionType = decltype(updateState(state))(*)(EnhancedGameObject*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4fada4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, state);
}

auto EnhancedGameObject::updateUserCoin() -> decltype(updateUserCoin()) {
	using FunctionType = decltype(updateUserCoin())(*)(EnhancedGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4f2768, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto EnhancedGameObject::waitForAnimationTrigger() -> decltype(waitForAnimationTrigger()) {
	using FunctionType = decltype(waitForAnimationTrigger())(*)(EnhancedGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x201aa4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
