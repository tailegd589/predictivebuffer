
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GJScaleControl.hpp>
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

auto GJScaleControl::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0xa46c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto GJScaleControl::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJScaleControl::init), this);
	using FunctionType = decltype(init())(*)(GJScaleControl*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x46d70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJScaleControl::ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchBegan(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&GJScaleControl::ccTouchBegan), this);
	using FunctionType = decltype(ccTouchBegan(touch, event))(*)(GJScaleControl*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x473a8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto GJScaleControl::ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchMoved(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&GJScaleControl::ccTouchMoved), this);
	using FunctionType = decltype(ccTouchMoved(touch, event))(*)(GJScaleControl*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x47534, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto GJScaleControl::ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchEnded(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&GJScaleControl::ccTouchEnded), this);
	using FunctionType = decltype(ccTouchEnded(touch, event))(*)(GJScaleControl*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4796c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto GJScaleControl::ccTouchCancelled(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchCancelled(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&GJScaleControl::ccTouchCancelled), this);
	using FunctionType = decltype(ccTouchCancelled(touch, event))(*)(GJScaleControl*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x47aa4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto GJScaleControl::finishTouch() -> decltype(finishTouch()) {
	using FunctionType = decltype(finishTouch())(*)(GJScaleControl*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37138, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJScaleControl::loadValues(GameObject* object, cocos2d::CCArray* objects, gd::unordered_map<int, GameObjectEditorState>& editorStates) -> decltype(loadValues(object, objects, editorStates)) {
	using FunctionType = decltype(loadValues(object, objects, editorStates))(*)(GJScaleControl*, GameObject*, cocos2d::CCArray*, gd::unordered_map<int, GameObjectEditorState>&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x372a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, objects, editorStates);
}

auto GJScaleControl::onToggleLockScale(cocos2d::CCObject* sender) -> decltype(onToggleLockScale(sender)) {
	using FunctionType = decltype(onToggleLockScale(sender))(*)(GJScaleControl*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x47154, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto GJScaleControl::scaleFromValue(float value) -> decltype(scaleFromValue(value)) {
	using FunctionType = decltype(scaleFromValue(value))(*)(GJScaleControl*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4732c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, value);
}

auto GJScaleControl::skewFromValue(float value) -> decltype(skewFromValue(value)) {
	using FunctionType = decltype(skewFromValue(value))(*)(GJScaleControl*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x47368, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, value);
}

auto GJScaleControl::sliderChanged(cocos2d::CCObject* sender) -> decltype(sliderChanged(sender)) {
	using FunctionType = decltype(sliderChanged(sender))(*)(GJScaleControl*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x471c4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto GJScaleControl::updateLabelX(float value) -> decltype(updateLabelX(value)) {
	using FunctionType = decltype(updateLabelX(value))(*)(GJScaleControl*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x471f4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, value);
}

auto GJScaleControl::updateLabelXY(float value) -> decltype(updateLabelXY(value)) {
	using FunctionType = decltype(updateLabelXY(value))(*)(GJScaleControl*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x472c4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, value);
}

auto GJScaleControl::updateLabelY(float value) -> decltype(updateLabelY(value)) {
	using FunctionType = decltype(updateLabelY(value))(*)(GJScaleControl*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4725c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, value);
}

auto GJScaleControl::valueFromScale(float scale) -> decltype(valueFromScale(scale)) {
	using FunctionType = decltype(valueFromScale(scale))(*)(GJScaleControl*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x47380, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, scale);
}

auto GJScaleControl::valueFromSkew(float value) -> decltype(valueFromSkew(value)) {
	using FunctionType = decltype(valueFromSkew(value))(*)(GJScaleControl*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x471cc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, value);
}
