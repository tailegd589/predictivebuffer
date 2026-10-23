
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/Slider.hpp>
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

auto Slider::create(cocos2d::CCNode* target, cocos2d::SEL_MenuHandler handler) -> decltype(create(target, handler)) {
	using FunctionType = decltype(create(target, handler))(*)(cocos2d::CCNode*, cocos2d::SEL_MenuHandler);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3044d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(target, handler);
}

auto Slider::create(cocos2d::CCNode* target, cocos2d::SEL_MenuHandler handler, float scale) -> decltype(create(target, handler, scale)) {
	using FunctionType = decltype(create(target, handler, scale))(*)(cocos2d::CCNode*, cocos2d::SEL_MenuHandler, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3045f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(target, handler, scale);
}

auto Slider::create(cocos2d::CCNode* target, cocos2d::SEL_MenuHandler handler, char const* bar, char const* groove, char const* thumb, char const* thumbSel, float scale) -> decltype(create(target, handler, bar, groove, thumb, thumbSel, scale)) {
	using FunctionType = decltype(create(target, handler, bar, groove, thumb, thumbSel, scale))(*)(cocos2d::CCNode*, cocos2d::SEL_MenuHandler, char const*, char const*, char const*, char const*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x304710, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(target, handler, bar, groove, thumb, thumbSel, scale);
}

auto Slider::ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchBegan(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&Slider::ccTouchBegan), this);
	using FunctionType = decltype(ccTouchBegan(touch, event))(*)(Slider*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x304e50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto Slider::ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchMoved(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&Slider::ccTouchMoved), this);
	using FunctionType = decltype(ccTouchMoved(touch, event))(*)(Slider*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x304ed0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto Slider::ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchEnded(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&Slider::ccTouchEnded), this);
	using FunctionType = decltype(ccTouchEnded(touch, event))(*)(Slider*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x304e90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto Slider::disableSlider() -> decltype(disableSlider()) {
	using FunctionType = decltype(disableSlider())(*)(Slider*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3049e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto Slider::disableTouch() -> decltype(disableTouch()) {
	using FunctionType = decltype(disableTouch())(*)(Slider*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x304d10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto Slider::enableSlider() -> decltype(enableSlider()) {
	using FunctionType = decltype(enableSlider())(*)(Slider*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x304c70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto Slider::getLiveDragging() -> decltype(getLiveDragging()) {
	using FunctionType = decltype(getLiveDragging())(*)(Slider*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x304e10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto Slider::getThumb() -> decltype(getThumb()) {
	using FunctionType = decltype(getThumb())(*)(Slider*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x304d30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto Slider::getValue() -> decltype(getValue()) {
	using FunctionType = decltype(getValue())(*)(Slider*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x304d50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto Slider::hideGroove(bool visibility) -> decltype(hideGroove(visibility)) {
	using FunctionType = decltype(hideGroove(visibility))(*)(Slider*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x305120, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, visibility);
}

auto Slider::init(cocos2d::CCNode* target, cocos2d::SEL_MenuHandler handler, char const* bar, char const* groove, char const* thumb, char const* thumbSel, float scale) -> decltype(init(target, handler, bar, groove, thumb, thumbSel, scale)) {
	using FunctionType = decltype(init(target, handler, bar, groove, thumb, thumbSel, scale))(*)(Slider*, cocos2d::CCNode*, cocos2d::SEL_MenuHandler, char const*, char const*, char const*, char const*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x304830, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, target, handler, bar, groove, thumb, thumbSel, scale);
}

auto Slider::setBarVisibility(bool visibility) -> decltype(setBarVisibility(visibility)) {
	using FunctionType = decltype(setBarVisibility(visibility))(*)(Slider*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x304df0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, visibility);
}

auto Slider::setLiveDragging(bool activateThumb) -> decltype(setLiveDragging(activateThumb)) {
	using FunctionType = decltype(setLiveDragging(activateThumb))(*)(Slider*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x304e30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, activateThumb);
}

auto Slider::setMaxOffset(float offset) -> decltype(setMaxOffset(offset)) {
	using FunctionType = decltype(setMaxOffset(offset))(*)(Slider*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x305020, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, offset);
}

auto Slider::setRotated(bool rotated) -> decltype(setRotated(rotated)) {
	using FunctionType = decltype(setRotated(rotated))(*)(Slider*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x304f10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, rotated);
}

auto Slider::setValue(float val) -> decltype(setValue(val)) {
	using FunctionType = decltype(setValue(val))(*)(Slider*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x304b70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, val);
}

auto Slider::sliderBegan() -> decltype(sliderBegan()) {
	using FunctionType = decltype(sliderBegan())(*)(Slider*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x304010, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto Slider::sliderEnded() -> decltype(sliderEnded()) {
	using FunctionType = decltype(sliderEnded())(*)(Slider*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x304130, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto Slider::updateBar() -> decltype(updateBar()) {
	using FunctionType = decltype(updateBar())(*)(Slider*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x304380, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
