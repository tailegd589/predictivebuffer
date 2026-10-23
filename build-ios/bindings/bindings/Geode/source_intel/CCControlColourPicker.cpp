
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCControlColourPicker.hpp>
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

auto cocos2d::extension::CCControlColourPicker::colourPicker() -> decltype(colourPicker()) {
	using FunctionType = decltype(colourPicker())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x355d60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::extension::CCControlColourPicker::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::extension::CCControlColourPicker::init), this);
	using FunctionType = decltype(init())(*)(cocos2d::extension::CCControlColourPicker*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3556e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::extension::CCControlColourPicker::ccTouchBegan(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) -> decltype(ccTouchBegan(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&cocos2d::extension::CCControlColourPicker::ccTouchBegan), this);
	using FunctionType = decltype(ccTouchBegan(p0, p1))(*)(cocos2d::extension::CCControlColourPicker*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x355fe0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::extension::CCControlColourPicker::setColorValue(cocos2d::ccColor3B const& p0) -> decltype(setColorValue(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::ccColor3B const&>::func(&cocos2d::extension::CCControlColourPicker::setColorValue), this);
	using FunctionType = decltype(setColorValue(p0))(*)(cocos2d::extension::CCControlColourPicker*, cocos2d::ccColor3B const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x355e30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCControlColourPicker::colourSliderValueChanged(cocos2d::CCObject* p0, unsigned int p1) -> decltype(colourSliderValueChanged(p0, p1)) {
	using FunctionType = decltype(colourSliderValueChanged(p0, p1))(*)(cocos2d::extension::CCControlColourPicker*, cocos2d::CCObject*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x355b30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::extension::CCControlColourPicker::hueSliderValueChanged(cocos2d::CCObject* p0, unsigned int p1) -> decltype(hueSliderValueChanged(p0, p1)) {
	using FunctionType = decltype(hueSliderValueChanged(p0, p1))(*)(cocos2d::extension::CCControlColourPicker*, cocos2d::CCObject*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x355a00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::extension::CCControlColourPicker::updateControlPicker() -> decltype(updateControlPicker()) {
	using FunctionType = decltype(updateControlPicker())(*)(cocos2d::extension::CCControlColourPicker*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x355f80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::extension::CCControlColourPicker::updateHueAndControlPicker() -> decltype(updateHueAndControlPicker()) {
	using FunctionType = decltype(updateHueAndControlPicker())(*)(cocos2d::extension::CCControlColourPicker*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x355c10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
