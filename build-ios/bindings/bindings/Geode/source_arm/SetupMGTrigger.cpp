
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/SetupMGTrigger.hpp>
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

auto SetupMGTrigger::create(EffectGameObject* object, cocos2d::CCArray* objects) -> decltype(create(object, objects)) {
	using FunctionType = decltype(create(object, objects))(*)(EffectGameObject*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x45fed8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(object, objects);
}

auto SetupMGTrigger::determineStartValues() -> decltype(determineStartValues()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&SetupMGTrigger::determineStartValues), this);
	using FunctionType = decltype(determineStartValues())(*)(SetupMGTrigger*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x461744, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto SetupMGTrigger::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCObject*>::func(&SetupMGTrigger::onClose), this);
	using FunctionType = decltype(onClose(sender))(*)(SetupMGTrigger*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x461ebc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, sender);
}

auto SetupMGTrigger::textChanged(CCTextInputNode* node) -> decltype(textChanged(node)) {
	auto self = addresser::thunkAdjust(Resolve<CCTextInputNode*>::func(&SetupMGTrigger::textChanged), this);
	using FunctionType = decltype(textChanged(node))(*)(SetupMGTrigger*, CCTextInputNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x461cbc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, node);
}

auto SetupMGTrigger::valuePopupClosed(ConfigureValuePopup* popup, float value) -> decltype(valuePopupClosed(popup, value)) {
	auto self = addresser::thunkAdjust(Resolve<ConfigureValuePopup*, float>::func(&SetupMGTrigger::valuePopupClosed), this);
	using FunctionType = decltype(valuePopupClosed(popup, value))(*)(SetupMGTrigger*, ConfigureValuePopup*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4619d8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, popup, value);
}

auto SetupMGTrigger::init(EffectGameObject* object, cocos2d::CCArray* objects) -> decltype(init(object, objects)) {
	using FunctionType = decltype(init(object, objects))(*)(SetupMGTrigger*, EffectGameObject*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x460064, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, objects);
}

auto SetupMGTrigger::onEasing(cocos2d::CCObject* sender) -> decltype(onEasing(sender)) {
	using FunctionType = decltype(onEasing(sender))(*)(SetupMGTrigger*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4613c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupMGTrigger::onEasingRate(cocos2d::CCObject* sender) -> decltype(onEasingRate(sender)) {
	using FunctionType = decltype(onEasingRate(sender))(*)(SetupMGTrigger*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4610cc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupMGTrigger::posFromSliderValue(float value) -> decltype(posFromSliderValue(value)) {
	using FunctionType = decltype(posFromSliderValue(value))(*)(SetupMGTrigger*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4619b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, value);
}

auto SetupMGTrigger::sliderChanged(cocos2d::CCObject* sender) -> decltype(sliderChanged(sender)) {
	using FunctionType = decltype(sliderChanged(sender))(*)(SetupMGTrigger*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x460ed8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupMGTrigger::sliderValueFromPos(int pos) -> decltype(sliderValueFromPos(pos)) {
	using FunctionType = decltype(sliderValueFromPos(pos))(*)(SetupMGTrigger*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4614d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, pos);
}

auto SetupMGTrigger::sliderYChanged(cocos2d::CCObject* sender) -> decltype(sliderYChanged(sender)) {
	using FunctionType = decltype(sliderYChanged(sender))(*)(SetupMGTrigger*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x461478, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupMGTrigger::toggleEasingRateVisibility() -> decltype(toggleEasingRateVisibility()) {
	using FunctionType = decltype(toggleEasingRateVisibility())(*)(SetupMGTrigger*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x461320, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupMGTrigger::updateDuration() -> decltype(updateDuration()) {
	using FunctionType = decltype(updateDuration())(*)(SetupMGTrigger*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x461b74, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupMGTrigger::updateDurLabel(bool decimals) -> decltype(updateDurLabel(decimals)) {
	using FunctionType = decltype(updateDurLabel(decimals))(*)(SetupMGTrigger*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x460f68, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, decimals);
}

auto SetupMGTrigger::updateEasingLabel() -> decltype(updateEasingLabel()) {
	using FunctionType = decltype(updateEasingLabel())(*)(SetupMGTrigger*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x461654, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupMGTrigger::updateEasingRateLabel() -> decltype(updateEasingRateLabel()) {
	using FunctionType = decltype(updateEasingRateLabel())(*)(SetupMGTrigger*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4611d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupMGTrigger::updateMoveCommandEasing() -> decltype(updateMoveCommandEasing()) {
	using FunctionType = decltype(updateMoveCommandEasing())(*)(SetupMGTrigger*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x461b04, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupMGTrigger::updateMoveCommandEasingRate() -> decltype(updateMoveCommandEasingRate()) {
	using FunctionType = decltype(updateMoveCommandEasingRate())(*)(SetupMGTrigger*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x461a8c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupMGTrigger::updateMoveCommandPosY() -> decltype(updateMoveCommandPosY()) {
	using FunctionType = decltype(updateMoveCommandPosY())(*)(SetupMGTrigger*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x461be4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupMGTrigger::updateValueYLabel() -> decltype(updateValueYLabel()) {
	using FunctionType = decltype(updateValueYLabel())(*)(SetupMGTrigger*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x461524, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
