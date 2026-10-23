
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/SetupCameraOffsetTrigger.hpp>
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

auto SetupCameraOffsetTrigger::create(CameraTriggerGameObject* object, cocos2d::CCArray* objects) -> decltype(create(object, objects)) {
	using FunctionType = decltype(create(object, objects))(*)(CameraTriggerGameObject*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x580e3c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(object, objects);
}

auto SetupCameraOffsetTrigger::determineStartValues() -> decltype(determineStartValues()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&SetupCameraOffsetTrigger::determineStartValues), this);
	using FunctionType = decltype(determineStartValues())(*)(SetupCameraOffsetTrigger*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x582bb4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto SetupCameraOffsetTrigger::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCObject*>::func(&SetupCameraOffsetTrigger::onClose), this);
	using FunctionType = decltype(onClose(sender))(*)(SetupCameraOffsetTrigger*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5835ec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, sender);
}

auto SetupCameraOffsetTrigger::textChanged(CCTextInputNode* node) -> decltype(textChanged(node)) {
	auto self = addresser::thunkAdjust(Resolve<CCTextInputNode*>::func(&SetupCameraOffsetTrigger::textChanged), this);
	using FunctionType = decltype(textChanged(node))(*)(SetupCameraOffsetTrigger*, CCTextInputNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x583384, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, node);
}

auto SetupCameraOffsetTrigger::valuePopupClosed(ConfigureValuePopup* popup, float value) -> decltype(valuePopupClosed(popup, value)) {
	auto self = addresser::thunkAdjust(Resolve<ConfigureValuePopup*, float>::func(&SetupCameraOffsetTrigger::valuePopupClosed), this);
	using FunctionType = decltype(valuePopupClosed(popup, value))(*)(SetupCameraOffsetTrigger*, ConfigureValuePopup*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x582fc8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, popup, value);
}

auto SetupCameraOffsetTrigger::init(CameraTriggerGameObject* object, cocos2d::CCArray* objects) -> decltype(init(object, objects)) {
	using FunctionType = decltype(init(object, objects))(*)(SetupCameraOffsetTrigger*, CameraTriggerGameObject*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x580fc8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, objects);
}

auto SetupCameraOffsetTrigger::onEasing(cocos2d::CCObject* sender) -> decltype(onEasing(sender)) {
	using FunctionType = decltype(onEasing(sender))(*)(SetupCameraOffsetTrigger*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5825d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupCameraOffsetTrigger::onEasingRate(cocos2d::CCObject* sender) -> decltype(onEasingRate(sender)) {
	using FunctionType = decltype(onEasingRate(sender))(*)(SetupCameraOffsetTrigger*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5822dc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupCameraOffsetTrigger::onTargetMode(cocos2d::CCObject* sender) -> decltype(onTargetMode(sender)) {
	using FunctionType = decltype(onTargetMode(sender))(*)(SetupCameraOffsetTrigger*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58278c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupCameraOffsetTrigger::posFromSliderValue(float value) -> decltype(posFromSliderValue(value)) {
	using FunctionType = decltype(posFromSliderValue(value))(*)(SetupCameraOffsetTrigger*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x582fa0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, value);
}

auto SetupCameraOffsetTrigger::sliderChanged(cocos2d::CCObject* sender) -> decltype(sliderChanged(sender)) {
	using FunctionType = decltype(sliderChanged(sender))(*)(SetupCameraOffsetTrigger*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5820e8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupCameraOffsetTrigger::sliderValueFromPos(int pos) -> decltype(sliderValueFromPos(pos)) {
	using FunctionType = decltype(sliderValueFromPos(pos))(*)(SetupCameraOffsetTrigger*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x582738, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, pos);
}

auto SetupCameraOffsetTrigger::sliderXChanged(cocos2d::CCObject* sender) -> decltype(sliderXChanged(sender)) {
	using FunctionType = decltype(sliderXChanged(sender))(*)(SetupCameraOffsetTrigger*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x582688, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupCameraOffsetTrigger::sliderYChanged(cocos2d::CCObject* sender) -> decltype(sliderYChanged(sender)) {
	using FunctionType = decltype(sliderYChanged(sender))(*)(SetupCameraOffsetTrigger*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5826e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupCameraOffsetTrigger::toggleEasingRateVisibility() -> decltype(toggleEasingRateVisibility()) {
	using FunctionType = decltype(toggleEasingRateVisibility())(*)(SetupCameraOffsetTrigger*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x582530, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupCameraOffsetTrigger::updateDuration() -> decltype(updateDuration()) {
	using FunctionType = decltype(updateDuration())(*)(SetupCameraOffsetTrigger*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x583164, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupCameraOffsetTrigger::updateDurLabel(bool decimals) -> decltype(updateDurLabel(decimals)) {
	using FunctionType = decltype(updateDurLabel(decimals))(*)(SetupCameraOffsetTrigger*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x582178, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, decimals);
}

auto SetupCameraOffsetTrigger::updateEasingLabel() -> decltype(updateEasingLabel()) {
	using FunctionType = decltype(updateEasingLabel())(*)(SetupCameraOffsetTrigger*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x582ac4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupCameraOffsetTrigger::updateEasingRateLabel() -> decltype(updateEasingRateLabel()) {
	using FunctionType = decltype(updateEasingRateLabel())(*)(SetupCameraOffsetTrigger*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5823e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupCameraOffsetTrigger::updateMoveCommandEasing() -> decltype(updateMoveCommandEasing()) {
	using FunctionType = decltype(updateMoveCommandEasing())(*)(SetupCameraOffsetTrigger*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5830f4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupCameraOffsetTrigger::updateMoveCommandEasingRate() -> decltype(updateMoveCommandEasingRate()) {
	using FunctionType = decltype(updateMoveCommandEasingRate())(*)(SetupCameraOffsetTrigger*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58307c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupCameraOffsetTrigger::updateMoveCommandPosX() -> decltype(updateMoveCommandPosX()) {
	using FunctionType = decltype(updateMoveCommandPosX())(*)(SetupCameraOffsetTrigger*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5831d4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupCameraOffsetTrigger::updateMoveCommandPosY() -> decltype(updateMoveCommandPosY()) {
	using FunctionType = decltype(updateMoveCommandPosY())(*)(SetupCameraOffsetTrigger*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5832ac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupCameraOffsetTrigger::updateValueXLabel() -> decltype(updateValueXLabel()) {
	using FunctionType = decltype(updateValueXLabel())(*)(SetupCameraOffsetTrigger*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x582864, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupCameraOffsetTrigger::updateValueYLabel() -> decltype(updateValueYLabel()) {
	using FunctionType = decltype(updateValueYLabel())(*)(SetupCameraOffsetTrigger*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x582994, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
