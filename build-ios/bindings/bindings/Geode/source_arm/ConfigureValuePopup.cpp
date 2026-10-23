
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/ConfigureValuePopup.hpp>
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

auto ConfigureValuePopup::create(ConfigureValuePopupDelegate* delegate, float value, float minimum, float maximum, gd::string title, gd::string description, int type) -> decltype(create(delegate, value, minimum, maximum, title, description, type)) {
	using FunctionType = decltype(create(delegate, value, minimum, maximum, title, description, type))(*)(ConfigureValuePopupDelegate*, float, float, float, gd::string, gd::string, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x547d5c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(delegate, value, minimum, maximum, title, description, type);
}

auto ConfigureValuePopup::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&ConfigureValuePopup::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(ConfigureValuePopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x548f24, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto ConfigureValuePopup::textInputClosed(CCTextInputNode* node) -> decltype(textInputClosed(node)) {
	auto self = addresser::thunkAdjust(Resolve<CCTextInputNode*>::func(&ConfigureValuePopup::textInputClosed), this);
	using FunctionType = decltype(textInputClosed(node))(*)(ConfigureValuePopup*, CCTextInputNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x548da4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, node);
}

auto ConfigureValuePopup::textChanged(CCTextInputNode* node) -> decltype(textChanged(node)) {
	auto self = addresser::thunkAdjust(Resolve<CCTextInputNode*>::func(&ConfigureValuePopup::textChanged), this);
	using FunctionType = decltype(textChanged(node))(*)(ConfigureValuePopup*, CCTextInputNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x548dc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, node);
}

auto ConfigureValuePopup::addInfoAlertButton(gd::string title, gd::string description) -> decltype(addInfoAlertButton(title, description)) {
	using FunctionType = decltype(addInfoAlertButton(title, description))(*)(ConfigureValuePopup*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x548bf8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, title, description);
}

auto ConfigureValuePopup::init(ConfigureValuePopupDelegate* delegate, float value, float minimum, float maximum, gd::string title, gd::string description, int type) -> decltype(init(delegate, value, minimum, maximum, title, description, type)) {
	using FunctionType = decltype(init(delegate, value, minimum, maximum, title, description, type))(*)(ConfigureValuePopup*, ConfigureValuePopupDelegate*, float, float, float, gd::string, gd::string, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x547f90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, delegate, value, minimum, maximum, title, description, type);
}

auto ConfigureValuePopup::onArrow(cocos2d::CCObject* sender) -> decltype(onArrow(sender)) {
	using FunctionType = decltype(onArrow(sender))(*)(ConfigureValuePopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x548a48, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto ConfigureValuePopup::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	using FunctionType = decltype(onClose(sender))(*)(ConfigureValuePopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x548984, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto ConfigureValuePopup::sliderChanged(cocos2d::CCObject* sender) -> decltype(sliderChanged(sender)) {
	using FunctionType = decltype(sliderChanged(sender))(*)(ConfigureValuePopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x548a04, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto ConfigureValuePopup::updateTextInputLabel() -> decltype(updateTextInputLabel()) {
	using FunctionType = decltype(updateTextInputLabel())(*)(ConfigureValuePopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x548ab4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
