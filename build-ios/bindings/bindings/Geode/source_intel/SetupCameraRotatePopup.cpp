
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/SetupCameraRotatePopup.hpp>
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

auto SetupCameraRotatePopup::create(EffectGameObject* object, cocos2d::CCArray* objects) -> decltype(create(object, objects)) {
	using FunctionType = decltype(create(object, objects))(*)(EffectGameObject*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4bc7a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(object, objects);
}

auto SetupCameraRotatePopup::determineStartValues() -> decltype(determineStartValues()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&SetupCameraRotatePopup::determineStartValues), this);
	using FunctionType = decltype(determineStartValues())(*)(SetupCameraRotatePopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4be0b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto SetupCameraRotatePopup::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCObject*>::func(&SetupCameraRotatePopup::onClose), this);
	using FunctionType = decltype(onClose(sender))(*)(SetupCameraRotatePopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4be8e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, sender);
}

auto SetupCameraRotatePopup::textChanged(CCTextInputNode* node) -> decltype(textChanged(node)) {
	auto self = addresser::thunkAdjust(Resolve<CCTextInputNode*>::func(&SetupCameraRotatePopup::textChanged), this);
	using FunctionType = decltype(textChanged(node))(*)(SetupCameraRotatePopup*, CCTextInputNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4be670, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, node);
}

auto SetupCameraRotatePopup::valuePopupClosed(ConfigureValuePopup* popup, float value) -> decltype(valuePopupClosed(popup, value)) {
	auto self = addresser::thunkAdjust(Resolve<ConfigureValuePopup*, float>::func(&SetupCameraRotatePopup::valuePopupClosed), this);
	using FunctionType = decltype(valuePopupClosed(popup, value))(*)(SetupCameraRotatePopup*, ConfigureValuePopup*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4be3a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, popup, value);
}

auto SetupCameraRotatePopup::init(EffectGameObject* object, cocos2d::CCArray* objects) -> decltype(init(object, objects)) {
	using FunctionType = decltype(init(object, objects))(*)(SetupCameraRotatePopup*, EffectGameObject*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4bc9e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, objects);
}

auto SetupCameraRotatePopup::onEasing(cocos2d::CCObject* sender) -> decltype(onEasing(sender)) {
	using FunctionType = decltype(onEasing(sender))(*)(SetupCameraRotatePopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4bdd50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupCameraRotatePopup::onEasingRate(cocos2d::CCObject* sender) -> decltype(onEasingRate(sender)) {
	using FunctionType = decltype(onEasingRate(sender))(*)(SetupCameraRotatePopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4bdab0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupCameraRotatePopup::sliderChanged(cocos2d::CCObject* sender) -> decltype(sliderChanged(sender)) {
	using FunctionType = decltype(sliderChanged(sender))(*)(SetupCameraRotatePopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4bd8c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupCameraRotatePopup::sliderDegreesChanged(cocos2d::CCObject* sender) -> decltype(sliderDegreesChanged(sender)) {
	using FunctionType = decltype(sliderDegreesChanged(sender))(*)(SetupCameraRotatePopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4bde10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupCameraRotatePopup::toggleEasingRateVisibility() -> decltype(toggleEasingRateVisibility()) {
	using FunctionType = decltype(toggleEasingRateVisibility())(*)(SetupCameraRotatePopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4bdca0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupCameraRotatePopup::updateCommandDegrees() -> decltype(updateCommandDegrees()) {
	using FunctionType = decltype(updateCommandDegrees())(*)(SetupCameraRotatePopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4be570, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupCameraRotatePopup::updateDegreesLabel() -> decltype(updateDegreesLabel()) {
	using FunctionType = decltype(updateDegreesLabel())(*)(SetupCameraRotatePopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4bdec0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupCameraRotatePopup::updateDuration() -> decltype(updateDuration()) {
	using FunctionType = decltype(updateDuration())(*)(SetupCameraRotatePopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4be5f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupCameraRotatePopup::updateDurLabel(bool decimals) -> decltype(updateDurLabel(decimals)) {
	using FunctionType = decltype(updateDurLabel(decimals))(*)(SetupCameraRotatePopup*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4bd960, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, decimals);
}

auto SetupCameraRotatePopup::updateEasingLabel() -> decltype(updateEasingLabel()) {
	using FunctionType = decltype(updateEasingLabel())(*)(SetupCameraRotatePopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4bdff0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupCameraRotatePopup::updateEasingRateLabel() -> decltype(updateEasingRateLabel()) {
	using FunctionType = decltype(updateEasingRateLabel())(*)(SetupCameraRotatePopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4bdb70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupCameraRotatePopup::updateMoveCommandEasing() -> decltype(updateMoveCommandEasing()) {
	using FunctionType = decltype(updateMoveCommandEasing())(*)(SetupCameraRotatePopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4be4f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupCameraRotatePopup::updateMoveCommandEasingRate() -> decltype(updateMoveCommandEasingRate()) {
	using FunctionType = decltype(updateMoveCommandEasingRate())(*)(SetupCameraRotatePopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4be450, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
