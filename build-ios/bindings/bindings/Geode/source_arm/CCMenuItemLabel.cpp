
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCMenuItemLabel.hpp>
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

cocos2d::CCMenuItemLabel::~CCMenuItemLabel() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCMenuItemLabel*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x340b2c, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCMenuItemLabel(geode::CutoffConstructor, sizeof(cocos2d::CCMenuItemLabel));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCMenuItemLabel::create(cocos2d::CCNode* p0) -> decltype(create(p0)) {
	using FunctionType = decltype(create(p0))(*)(cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3409fc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::CCMenuItemLabel::create(cocos2d::CCNode* p0, cocos2d::CCObject* p1, cocos2d::SEL_MenuHandler p2) -> decltype(create(p0, p1, p2)) {
	using FunctionType = decltype(create(p0, p1, p2))(*)(cocos2d::CCNode*, cocos2d::CCObject*, cocos2d::SEL_MenuHandler);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3407c8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

auto cocos2d::CCMenuItemLabel::getDisabledColor() -> decltype(getDisabledColor()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCMenuItemLabel::getDisabledColor), this);
	using FunctionType = decltype(getDisabledColor())(*)(cocos2d::CCMenuItemLabel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3406fc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCMenuItemLabel::setDisabledColor(cocos2d::ccColor3B const& p0) -> decltype(setDisabledColor(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::ccColor3B const&>::func(&cocos2d::CCMenuItemLabel::setDisabledColor), this);
	using FunctionType = decltype(setDisabledColor(p0))(*)(cocos2d::CCMenuItemLabel*, cocos2d::ccColor3B const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x340704, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCMenuItemLabel::getLabel() -> decltype(getLabel()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCMenuItemLabel::getLabel), this);
	using FunctionType = decltype(getLabel())(*)(cocos2d::CCMenuItemLabel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x340718, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCMenuItemLabel::setLabel(cocos2d::CCNode* p0) -> decltype(setLabel(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*>::func(&cocos2d::CCMenuItemLabel::setLabel), this);
	using FunctionType = decltype(setLabel(p0))(*)(cocos2d::CCMenuItemLabel*, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x340720, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCMenuItemLabel::activate() -> decltype(activate()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCMenuItemLabel::activate), this);
	using FunctionType = decltype(activate())(*)(cocos2d::CCMenuItemLabel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x340cb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCMenuItemLabel::selected() -> decltype(selected()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCMenuItemLabel::selected), this);
	using FunctionType = decltype(selected())(*)(cocos2d::CCMenuItemLabel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x340d54, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCMenuItemLabel::unselected() -> decltype(unselected()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCMenuItemLabel::unselected), this);
	using FunctionType = decltype(unselected())(*)(cocos2d::CCMenuItemLabel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x340dfc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCMenuItemLabel::setEnabled(bool p0) -> decltype(setEnabled(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::CCMenuItemLabel::setEnabled), this);
	using FunctionType = decltype(setEnabled(p0))(*)(cocos2d::CCMenuItemLabel*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x340e6c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCMenuItemLabel::initWithLabel(cocos2d::CCNode* p0, cocos2d::CCObject* p1, cocos2d::SEL_MenuHandler p2) -> decltype(initWithLabel(p0, p1, p2)) {
	using FunctionType = decltype(initWithLabel(p0, p1, p2))(*)(cocos2d::CCMenuItemLabel*, cocos2d::CCNode*, cocos2d::CCObject*, cocos2d::SEL_MenuHandler);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x34090c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto cocos2d::CCMenuItemLabel::setString(char const* p0) -> decltype(setString(p0)) {
	using FunctionType = decltype(setString(p0))(*)(cocos2d::CCMenuItemLabel*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x340c44, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
