
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/CCMenuItemToggler.hpp>
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

auto CCMenuItemToggler::create(cocos2d::CCNode* off, cocos2d::CCNode* on, cocos2d::CCObject* target, cocos2d::SEL_MenuHandler callback) -> decltype(create(off, on, target, callback)) {
	using FunctionType = decltype(create(off, on, target, callback))(*)(cocos2d::CCNode*, cocos2d::CCNode*, cocos2d::CCObject*, cocos2d::SEL_MenuHandler);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4cea8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(off, on, target, callback);
}

auto CCMenuItemToggler::activate() -> decltype(activate()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CCMenuItemToggler::activate), this);
	using FunctionType = decltype(activate())(*)(CCMenuItemToggler*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4d5d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CCMenuItemToggler::selected() -> decltype(selected()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CCMenuItemToggler::selected), this);
	using FunctionType = decltype(selected())(*)(CCMenuItemToggler*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4d590, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CCMenuItemToggler::unselected() -> decltype(unselected()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CCMenuItemToggler::unselected), this);
	using FunctionType = decltype(unselected())(*)(CCMenuItemToggler*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4d610, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CCMenuItemToggler::setEnabled(bool enabled) -> decltype(setEnabled(enabled)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&CCMenuItemToggler::setEnabled), this);
	using FunctionType = decltype(setEnabled(enabled))(*)(CCMenuItemToggler*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4d650, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, enabled);
}

auto CCMenuItemToggler::activeItem() -> decltype(activeItem()) {
	using FunctionType = decltype(activeItem())(*)(CCMenuItemToggler*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4d574, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CCMenuItemToggler::init(cocos2d::CCNode* off, cocos2d::CCNode* on, cocos2d::CCObject* target, cocos2d::SEL_MenuHandler callback) -> decltype(init(off, on, target, callback)) {
	using FunctionType = decltype(init(off, on, target, callback))(*)(CCMenuItemToggler*, cocos2d::CCNode*, cocos2d::CCNode*, cocos2d::CCObject*, cocos2d::SEL_MenuHandler);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4cf8c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, off, on, target, callback);
}

auto CCMenuItemToggler::normalTouch(cocos2d::CCObject* sender) -> decltype(normalTouch(sender)) {
	using FunctionType = decltype(normalTouch(sender))(*)(CCMenuItemToggler*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4d1e4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto CCMenuItemToggler::selectedTouch(cocos2d::CCObject* sender) -> decltype(selectedTouch(sender)) {
	using FunctionType = decltype(selectedTouch(sender))(*)(CCMenuItemToggler*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4d2c8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto CCMenuItemToggler::setSizeMult(float mult) -> decltype(setSizeMult(mult)) {
	using FunctionType = decltype(setSizeMult(mult))(*)(CCMenuItemToggler*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4d480, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, mult);
}

auto CCMenuItemToggler::toggle(bool on) -> decltype(toggle(on)) {
	using FunctionType = decltype(toggle(on))(*)(CCMenuItemToggler*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4d3a8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, on);
}
