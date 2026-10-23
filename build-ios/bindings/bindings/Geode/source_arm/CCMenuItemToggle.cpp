
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCMenuItemToggle.hpp>
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

cocos2d::CCMenuItemToggle::~CCMenuItemToggle() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCMenuItemToggle*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x342b3c, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCMenuItemToggle(geode::CutoffConstructor, sizeof(cocos2d::CCMenuItemToggle));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCMenuItemToggle::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x342834, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCMenuItemToggle::create(cocos2d::CCMenuItem* p0) -> decltype(create(p0)) {
	using FunctionType = decltype(create(p0))(*)(cocos2d::CCMenuItem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x342a0c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::CCMenuItemToggle::createWithTarget(cocos2d::CCObject* p0, cocos2d::SEL_MenuHandler p1, cocos2d::CCArray* p2) -> decltype(createWithTarget(p0, p1, p2)) {
	using FunctionType = decltype(createWithTarget(p0, p1, p2))(*)(cocos2d::CCObject*, cocos2d::SEL_MenuHandler, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x342510, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

auto cocos2d::CCMenuItemToggle::getSelectedIndex() -> decltype(getSelectedIndex()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCMenuItemToggle::getSelectedIndex), this);
	using FunctionType = decltype(getSelectedIndex())(*)(cocos2d::CCMenuItemToggle*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x342dbc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCMenuItemToggle::setSelectedIndex(unsigned int p0) -> decltype(setSelectedIndex(p0)) {
	auto self = addresser::thunkAdjust(Resolve<unsigned int>::func(&cocos2d::CCMenuItemToggle::setSelectedIndex), this);
	using FunctionType = decltype(setSelectedIndex(p0))(*)(cocos2d::CCMenuItemToggle*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x342cc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCMenuItemToggle::getSubItems() -> decltype(getSubItems()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCMenuItemToggle::getSubItems), this);
	using FunctionType = decltype(getSubItems())(*)(cocos2d::CCMenuItemToggle*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x342508, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCMenuItemToggle::setSubItems(cocos2d::CCArray* p0) -> decltype(setSubItems(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCArray*>::func(&cocos2d::CCMenuItemToggle::setSubItems), this);
	using FunctionType = decltype(setSubItems(p0))(*)(cocos2d::CCMenuItemToggle*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3424cc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCMenuItemToggle::activate() -> decltype(activate()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCMenuItemToggle::activate), this);
	using FunctionType = decltype(activate())(*)(cocos2d::CCMenuItemToggle*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x342e20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCMenuItemToggle::selected() -> decltype(selected()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCMenuItemToggle::selected), this);
	using FunctionType = decltype(selected())(*)(cocos2d::CCMenuItemToggle*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x342dc4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCMenuItemToggle::unselected() -> decltype(unselected()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCMenuItemToggle::unselected), this);
	using FunctionType = decltype(unselected())(*)(cocos2d::CCMenuItemToggle*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x342df4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCMenuItemToggle::setEnabled(bool p0) -> decltype(setEnabled(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::CCMenuItemToggle::setEnabled), this);
	using FunctionType = decltype(setEnabled(p0))(*)(cocos2d::CCMenuItemToggle*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x342ed0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCMenuItemToggle::addSubItem(cocos2d::CCMenuItem* p0) -> decltype(addSubItem(p0)) {
	using FunctionType = decltype(addSubItem(p0))(*)(cocos2d::CCMenuItemToggle*, cocos2d::CCMenuItem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x342b34, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCMenuItemToggle::initWithItem(cocos2d::CCMenuItem* p0) -> decltype(initWithItem(p0)) {
	using FunctionType = decltype(initWithItem(p0))(*)(cocos2d::CCMenuItemToggle*, cocos2d::CCMenuItem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x342940, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCMenuItemToggle::initWithTarget(cocos2d::CCObject* p0, cocos2d::SEL_MenuHandler p1, cocos2d::CCMenuItem* p2, va_list p3) -> decltype(initWithTarget(p0, p1, p2, p3)) {
	using FunctionType = decltype(initWithTarget(p0, p1, p2, p3))(*)(cocos2d::CCMenuItemToggle*, cocos2d::CCObject*, cocos2d::SEL_MenuHandler, cocos2d::CCMenuItem*, va_list);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x342768, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3);
}

auto cocos2d::CCMenuItemToggle::selectedItem() -> decltype(selectedItem()) {
	using FunctionType = decltype(selectedItem())(*)(cocos2d::CCMenuItemToggle*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x342f60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
