
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/SetupGravityModPopup.hpp>
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

auto SetupGravityModPopup::create(EffectGameObject* object, cocos2d::CCArray* objects, bool gravityTrigger) -> decltype(create(object, objects, gravityTrigger)) {
	using FunctionType = decltype(create(object, objects, gravityTrigger))(*)(EffectGameObject*, cocos2d::CCArray*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3575bc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(object, objects, gravityTrigger);
}

auto SetupGravityModPopup::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&SetupGravityModPopup::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(SetupGravityModPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x358910, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto SetupGravityModPopup::show() -> decltype(show()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&SetupGravityModPopup::show), this);
	using FunctionType = decltype(show())(*)(SetupGravityModPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3588c4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto SetupGravityModPopup::textInputClosed(CCTextInputNode* node) -> decltype(textInputClosed(node)) {
	auto self = addresser::thunkAdjust(Resolve<CCTextInputNode*>::func(&SetupGravityModPopup::textInputClosed), this);
	using FunctionType = decltype(textInputClosed(node))(*)(SetupGravityModPopup*, CCTextInputNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3587d8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, node);
}

auto SetupGravityModPopup::textChanged(CCTextInputNode* node) -> decltype(textChanged(node)) {
	auto self = addresser::thunkAdjust(Resolve<CCTextInputNode*>::func(&SetupGravityModPopup::textChanged), this);
	using FunctionType = decltype(textChanged(node))(*)(SetupGravityModPopup*, CCTextInputNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3587f4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, node);
}

auto SetupGravityModPopup::determineStartValues() -> decltype(determineStartValues()) {
	using FunctionType = decltype(determineStartValues())(*)(SetupGravityModPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x358280, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupGravityModPopup::init(EffectGameObject* object, cocos2d::CCArray* objects, bool gravityTrigger) -> decltype(init(object, objects, gravityTrigger)) {
	using FunctionType = decltype(init(object, objects, gravityTrigger))(*)(SetupGravityModPopup*, EffectGameObject*, cocos2d::CCArray*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3576f8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, objects, gravityTrigger);
}

auto SetupGravityModPopup::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	using FunctionType = decltype(onClose(sender))(*)(SetupGravityModPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x358380, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupGravityModPopup::onItemIDArrow(cocos2d::CCObject* sender) -> decltype(onItemIDArrow(sender)) {
	using FunctionType = decltype(onItemIDArrow(sender))(*)(SetupGravityModPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x358548, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupGravityModPopup::sliderChanged(cocos2d::CCObject* sender) -> decltype(sliderChanged(sender)) {
	using FunctionType = decltype(sliderChanged(sender))(*)(SetupGravityModPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3583dc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupGravityModPopup::updateItemID() -> decltype(updateItemID()) {
	using FunctionType = decltype(updateItemID())(*)(SetupGravityModPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x358758, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupGravityModPopup::updateTextInputLabel() -> decltype(updateTextInputLabel()) {
	using FunctionType = decltype(updateTextInputLabel())(*)(SetupGravityModPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3585e8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupGravityModPopup::updateValue() -> decltype(updateValue()) {
	using FunctionType = decltype(updateValue())(*)(SetupGravityModPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3586ec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupGravityModPopup::updateValueLabel() -> decltype(updateValueLabel()) {
	using FunctionType = decltype(updateValueLabel())(*)(SetupGravityModPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3584d8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
