
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCMenuItem.hpp>
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

cocos2d::CCMenuItem::~CCMenuItem() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCMenuItem*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x3be830, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCMenuItem(geode::CutoffConstructor, sizeof(cocos2d::CCMenuItem));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCMenuItem::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3be620, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCMenuItem::create(cocos2d::CCObject* p0, cocos2d::SEL_MenuHandler p1) -> decltype(create(p0, p1)) {
	using FunctionType = decltype(create(p0, p1))(*)(cocos2d::CCObject*, cocos2d::SEL_MenuHandler);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3be6e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCMenuItem::activate() -> decltype(activate()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCMenuItem::activate), this);
	using FunctionType = decltype(activate())(*)(cocos2d::CCMenuItem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3be9f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCMenuItem::selected() -> decltype(selected()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCMenuItem::selected), this);
	using FunctionType = decltype(selected())(*)(cocos2d::CCMenuItem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3be960, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCMenuItem::unselected() -> decltype(unselected()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCMenuItem::unselected), this);
	using FunctionType = decltype(unselected())(*)(cocos2d::CCMenuItem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3be970, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCMenuItem::registerScriptTapHandler(int p0) -> decltype(registerScriptTapHandler(p0)) {
	auto self = addresser::thunkAdjust(Resolve<int>::func(&cocos2d::CCMenuItem::registerScriptTapHandler), this);
	using FunctionType = decltype(registerScriptTapHandler(p0))(*)(cocos2d::CCMenuItem*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3be980, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCMenuItem::unregisterScriptTapHandler() -> decltype(unregisterScriptTapHandler()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCMenuItem::unregisterScriptTapHandler), this);
	using FunctionType = decltype(unregisterScriptTapHandler())(*)(cocos2d::CCMenuItem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3be9b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCMenuItem::isEnabled() -> decltype(isEnabled()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCMenuItem::isEnabled), this);
	using FunctionType = decltype(isEnabled())(*)(cocos2d::CCMenuItem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3bea70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCMenuItem::setEnabled(bool p0) -> decltype(setEnabled(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::CCMenuItem::setEnabled), this);
	using FunctionType = decltype(setEnabled(p0))(*)(cocos2d::CCMenuItem*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3bea60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCMenuItem::isSelected() -> decltype(isSelected()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCMenuItem::isSelected), this);
	using FunctionType = decltype(isSelected())(*)(cocos2d::CCMenuItem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3bead0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCMenuItem::initWithTarget(cocos2d::CCObject* p0, cocos2d::SEL_MenuHandler p1) -> decltype(initWithTarget(p0, p1)) {
	using FunctionType = decltype(initWithTarget(p0, p1))(*)(cocos2d::CCMenuItem*, cocos2d::CCObject*, cocos2d::SEL_MenuHandler);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3be7b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCMenuItem::rect() -> decltype(rect()) {
	using FunctionType = decltype(rect())(*)(cocos2d::CCMenuItem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3bea80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCMenuItem::setTarget(cocos2d::CCObject* rec, cocos2d::SEL_MenuHandler selector) -> decltype(setTarget(rec, selector)) {
	using FunctionType = decltype(setTarget(rec, selector))(*)(cocos2d::CCMenuItem*, cocos2d::CCObject*, cocos2d::SEL_MenuHandler);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3beae0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, rec, selector);
}
