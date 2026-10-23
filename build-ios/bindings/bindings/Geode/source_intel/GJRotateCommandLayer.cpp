
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GJRotateCommandLayer.hpp>
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

auto GJRotateCommandLayer::create(EffectGameObject* object, cocos2d::CCArray* objects) -> decltype(create(object, objects)) {
	using FunctionType = decltype(create(object, objects))(*)(EffectGameObject*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x14c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(object, objects);
}

auto GJRotateCommandLayer::determineStartValues() -> decltype(determineStartValues()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJRotateCommandLayer::determineStartValues), this);
	using FunctionType = decltype(determineStartValues())(*)(GJRotateCommandLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3f70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJRotateCommandLayer::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCObject*>::func(&GJRotateCommandLayer::onClose), this);
	using FunctionType = decltype(onClose(sender))(*)(GJRotateCommandLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4f60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, sender);
}

auto GJRotateCommandLayer::textChanged(CCTextInputNode* node) -> decltype(textChanged(node)) {
	auto self = addresser::thunkAdjust(Resolve<CCTextInputNode*>::func(&GJRotateCommandLayer::textChanged), this);
	using FunctionType = decltype(textChanged(node))(*)(GJRotateCommandLayer*, CCTextInputNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x49c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, node);
}

auto GJRotateCommandLayer::valuePopupClosed(ConfigureValuePopup* popup, float value) -> decltype(valuePopupClosed(popup, value)) {
	auto self = addresser::thunkAdjust(Resolve<ConfigureValuePopup*, float>::func(&GJRotateCommandLayer::valuePopupClosed), this);
	using FunctionType = decltype(valuePopupClosed(popup, value))(*)(GJRotateCommandLayer*, ConfigureValuePopup*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4530, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, popup, value);
}

auto GJRotateCommandLayer::init(EffectGameObject* object, cocos2d::CCArray* objects) -> decltype(init(object, objects)) {
	using FunctionType = decltype(init(object, objects))(*)(GJRotateCommandLayer*, EffectGameObject*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1720, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, objects);
}

auto GJRotateCommandLayer::onEasing(cocos2d::CCObject* sender) -> decltype(onEasing(sender)) {
	using FunctionType = decltype(onEasing(sender))(*)(GJRotateCommandLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3520, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto GJRotateCommandLayer::onEasingRate(cocos2d::CCObject* sender) -> decltype(onEasingRate(sender)) {
	using FunctionType = decltype(onEasingRate(sender))(*)(GJRotateCommandLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3280, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto GJRotateCommandLayer::onFollowRotation(cocos2d::CCObject* sender) -> decltype(onFollowRotation(sender)) {
	using FunctionType = decltype(onFollowRotation(sender))(*)(GJRotateCommandLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto GJRotateCommandLayer::onLockRotation(cocos2d::CCObject* sender) -> decltype(onLockRotation(sender)) {
	using FunctionType = decltype(onLockRotation(sender))(*)(GJRotateCommandLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3740, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto GJRotateCommandLayer::onUpdateGroupID(cocos2d::CCObject* sender) -> decltype(onUpdateGroupID(sender)) {
	using FunctionType = decltype(onUpdateGroupID(sender))(*)(GJRotateCommandLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto GJRotateCommandLayer::onUpdateGroupID2(cocos2d::CCObject* sender) -> decltype(onUpdateGroupID2(sender)) {
	using FunctionType = decltype(onUpdateGroupID2(sender))(*)(GJRotateCommandLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3980, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto GJRotateCommandLayer::sliderChanged(cocos2d::CCObject* sender) -> decltype(sliderChanged(sender)) {
	using FunctionType = decltype(sliderChanged(sender))(*)(GJRotateCommandLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3090, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto GJRotateCommandLayer::sliderDegreesChanged(cocos2d::CCObject* sender) -> decltype(sliderDegreesChanged(sender)) {
	using FunctionType = decltype(sliderDegreesChanged(sender))(*)(GJRotateCommandLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x35e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto GJRotateCommandLayer::sliderTimesChanged(cocos2d::CCObject* sender) -> decltype(sliderTimesChanged(sender)) {
	using FunctionType = decltype(sliderTimesChanged(sender))(*)(GJRotateCommandLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3690, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto GJRotateCommandLayer::toggleEasingRateVisibility() -> decltype(toggleEasingRateVisibility()) {
	using FunctionType = decltype(toggleEasingRateVisibility())(*)(GJRotateCommandLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3470, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJRotateCommandLayer::updateCommandDegrees() -> decltype(updateCommandDegrees()) {
	using FunctionType = decltype(updateCommandDegrees())(*)(GJRotateCommandLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4800, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJRotateCommandLayer::updateCommandTimes() -> decltype(updateCommandTimes()) {
	using FunctionType = decltype(updateCommandTimes())(*)(GJRotateCommandLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4780, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJRotateCommandLayer::updateDegreesLabel() -> decltype(updateDegreesLabel()) {
	using FunctionType = decltype(updateDegreesLabel())(*)(GJRotateCommandLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3c70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJRotateCommandLayer::updateDuration() -> decltype(updateDuration()) {
	using FunctionType = decltype(updateDuration())(*)(GJRotateCommandLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4700, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJRotateCommandLayer::updateDurLabel(bool decimals) -> decltype(updateDurLabel(decimals)) {
	using FunctionType = decltype(updateDurLabel(decimals))(*)(GJRotateCommandLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3130, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, decimals);
}

auto GJRotateCommandLayer::updateEasingLabel() -> decltype(updateEasingLabel()) {
	using FunctionType = decltype(updateEasingLabel())(*)(GJRotateCommandLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3eb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJRotateCommandLayer::updateEasingRateLabel() -> decltype(updateEasingRateLabel()) {
	using FunctionType = decltype(updateEasingRateLabel())(*)(GJRotateCommandLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3340, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJRotateCommandLayer::updateMoveCommandEasing() -> decltype(updateMoveCommandEasing()) {
	using FunctionType = decltype(updateMoveCommandEasing())(*)(GJRotateCommandLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4680, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJRotateCommandLayer::updateMoveCommandEasingRate() -> decltype(updateMoveCommandEasingRate()) {
	using FunctionType = decltype(updateMoveCommandEasingRate())(*)(GJRotateCommandLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x45e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJRotateCommandLayer::updateTargetGroupID() -> decltype(updateTargetGroupID()) {
	using FunctionType = decltype(updateTargetGroupID())(*)(GJRotateCommandLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4880, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJRotateCommandLayer::updateTargetGroupID2() -> decltype(updateTargetGroupID2()) {
	using FunctionType = decltype(updateTargetGroupID2())(*)(GJRotateCommandLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4920, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJRotateCommandLayer::updateTextInputLabel() -> decltype(updateTextInputLabel()) {
	using FunctionType = decltype(updateTextInputLabel())(*)(GJRotateCommandLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3a30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJRotateCommandLayer::updateTextInputLabel2() -> decltype(updateTextInputLabel2()) {
	using FunctionType = decltype(updateTextInputLabel2())(*)(GJRotateCommandLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3b50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJRotateCommandLayer::updateTimesLabel() -> decltype(updateTimesLabel()) {
	using FunctionType = decltype(updateTimesLabel())(*)(GJRotateCommandLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3d90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
