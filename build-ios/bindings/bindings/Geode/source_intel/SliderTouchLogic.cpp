
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/SliderTouchLogic.hpp>
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

auto SliderTouchLogic::create(cocos2d::CCNode* target, cocos2d::SEL_MenuHandler selector, char const* thumb, char const* thumbSel, float scale) -> decltype(create(target, selector, thumb, thumbSel, scale)) {
	using FunctionType = decltype(create(target, selector, thumb, thumbSel, scale))(*)(cocos2d::CCNode*, cocos2d::SEL_MenuHandler, char const*, char const*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x303ac0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(target, selector, thumb, thumbSel, scale);
}

auto SliderTouchLogic::ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchBegan(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&SliderTouchLogic::ccTouchBegan), this);
	using FunctionType = decltype(ccTouchBegan(touch, event))(*)(SliderTouchLogic*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x303f70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto SliderTouchLogic::ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchMoved(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&SliderTouchLogic::ccTouchMoved), this);
	using FunctionType = decltype(ccTouchMoved(touch, event))(*)(SliderTouchLogic*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3041a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto SliderTouchLogic::ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchEnded(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&SliderTouchLogic::ccTouchEnded), this);
	using FunctionType = decltype(ccTouchEnded(touch, event))(*)(SliderTouchLogic*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3040e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto SliderTouchLogic::registerWithTouchDispatcher() -> decltype(registerWithTouchDispatcher()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&SliderTouchLogic::registerWithTouchDispatcher), this);
	using FunctionType = decltype(registerWithTouchDispatcher())(*)(SliderTouchLogic*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x304490, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto SliderTouchLogic::init(cocos2d::CCNode* target, cocos2d::SEL_MenuHandler selector, char const* thumb, char const* thumbSel, float scale) -> decltype(init(target, selector, thumb, thumbSel, scale)) {
	using FunctionType = decltype(init(target, selector, thumb, thumbSel, scale))(*)(SliderTouchLogic*, cocos2d::CCNode*, cocos2d::SEL_MenuHandler, char const*, char const*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x303c00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, target, selector, thumb, thumbSel, scale);
}

auto SliderTouchLogic::setMaxOffset(float offset) -> decltype(setMaxOffset(offset)) {
	using FunctionType = decltype(setMaxOffset(offset))(*)(SliderTouchLogic*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x303d90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, offset);
}

auto SliderTouchLogic::setRotated(bool rotated) -> decltype(setRotated(rotated)) {
	using FunctionType = decltype(setRotated(rotated))(*)(SliderTouchLogic*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x303e90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, rotated);
}
