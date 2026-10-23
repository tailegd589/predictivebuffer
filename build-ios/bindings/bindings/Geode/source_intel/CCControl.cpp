
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCControl.hpp>
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

cocos2d::extension::CCControl::CCControl() : cocos2d::extension::CCControl(geode::CutoffConstructor, sizeof(cocos2d::extension::CCControl)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::extension::CCControl::~CCControl();

	using FunctionType = void(*)(cocos2d::extension::CCControl*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3512a0, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::extension::CCControl::~CCControl() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::extension::CCControl*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x3515c0, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::extension::CCControl(geode::CutoffConstructor, sizeof(cocos2d::extension::CCControl));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::extension::CCControl::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x351400, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::extension::CCControl::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::extension::CCControl::init), this);
	using FunctionType = decltype(init())(*)(cocos2d::extension::CCControl*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3514f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::extension::CCControl::onEnter() -> decltype(onEnter()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::extension::CCControl::onEnter), this);
	using FunctionType = decltype(onEnter())(*)(cocos2d::extension::CCControl*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x351960, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::extension::CCControl::onExit() -> decltype(onExit()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::extension::CCControl::onExit), this);
	using FunctionType = decltype(onExit())(*)(cocos2d::extension::CCControl*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x351970, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::extension::CCControl::registerWithTouchDispatcher() -> decltype(registerWithTouchDispatcher()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::extension::CCControl::registerWithTouchDispatcher), this);
	using FunctionType = decltype(registerWithTouchDispatcher())(*)(cocos2d::extension::CCControl*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x351910, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::extension::CCControl::setOpacityModifyRGB(bool p0) -> decltype(setOpacityModifyRGB(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::extension::CCControl::setOpacityModifyRGB), this);
	using FunctionType = decltype(setOpacityModifyRGB(p0))(*)(cocos2d::extension::CCControl*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x352440, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCControl::isOpacityModifyRGB() -> decltype(isOpacityModifyRGB()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::extension::CCControl::isOpacityModifyRGB), this);
	using FunctionType = decltype(isOpacityModifyRGB())(*)(cocos2d::extension::CCControl*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3525a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::extension::CCControl::setEnabled(bool p0) -> decltype(setEnabled(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::extension::CCControl::setEnabled), this);
	using FunctionType = decltype(setEnabled(p0))(*)(cocos2d::extension::CCControl*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x352690, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCControl::isEnabled() -> decltype(isEnabled()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::extension::CCControl::isEnabled), this);
	using FunctionType = decltype(isEnabled())(*)(cocos2d::extension::CCControl*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3526c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::extension::CCControl::setSelected(bool p0) -> decltype(setSelected(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::extension::CCControl::setSelected), this);
	using FunctionType = decltype(setSelected(p0))(*)(cocos2d::extension::CCControl*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3526d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCControl::isSelected() -> decltype(isSelected()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::extension::CCControl::isSelected), this);
	using FunctionType = decltype(isSelected())(*)(cocos2d::extension::CCControl*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3526f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::extension::CCControl::setHighlighted(bool p0) -> decltype(setHighlighted(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::extension::CCControl::setHighlighted), this);
	using FunctionType = decltype(setHighlighted(p0))(*)(cocos2d::extension::CCControl*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x352700, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCControl::isHighlighted() -> decltype(isHighlighted()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::extension::CCControl::isHighlighted), this);
	using FunctionType = decltype(isHighlighted())(*)(cocos2d::extension::CCControl*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x352720, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::extension::CCControl::needsLayout() -> decltype(needsLayout()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::extension::CCControl::needsLayout), this);
	using FunctionType = decltype(needsLayout())(*)(cocos2d::extension::CCControl*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x352680, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::extension::CCControl::sendActionsForControlEvents(unsigned int p0) -> decltype(sendActionsForControlEvents(p0)) {
	auto self = addresser::thunkAdjust(Resolve<unsigned int>::func(&cocos2d::extension::CCControl::sendActionsForControlEvents), this);
	using FunctionType = decltype(sendActionsForControlEvents(p0))(*)(cocos2d::extension::CCControl*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x351980, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCControl::addTargetWithActionForControlEvents(cocos2d::CCObject* p0, cocos2d::extension::SEL_CCControlHandler p1, unsigned int p2) -> decltype(addTargetWithActionForControlEvents(p0, p1, p2)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCObject*, cocos2d::extension::SEL_CCControlHandler, unsigned int>::func(&cocos2d::extension::CCControl::addTargetWithActionForControlEvents), this);
	using FunctionType = decltype(addTargetWithActionForControlEvents(p0, p1, p2))(*)(cocos2d::extension::CCControl*, cocos2d::CCObject*, cocos2d::extension::SEL_CCControlHandler, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x351c30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2);
}

auto cocos2d::extension::CCControl::removeTargetWithActionForControlEvents(cocos2d::CCObject* p0, cocos2d::extension::SEL_CCControlHandler p1, unsigned int p2) -> decltype(removeTargetWithActionForControlEvents(p0, p1, p2)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCObject*, cocos2d::extension::SEL_CCControlHandler, unsigned int>::func(&cocos2d::extension::CCControl::removeTargetWithActionForControlEvents), this);
	using FunctionType = decltype(removeTargetWithActionForControlEvents(p0, p1, p2))(*)(cocos2d::extension::CCControl*, cocos2d::CCObject*, cocos2d::extension::SEL_CCControlHandler, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3520f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2);
}

auto cocos2d::extension::CCControl::getTouchLocation(cocos2d::CCTouch* p0) -> decltype(getTouchLocation(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*>::func(&cocos2d::extension::CCControl::getTouchLocation), this);
	using FunctionType = decltype(getTouchLocation(p0))(*)(cocos2d::extension::CCControl*, cocos2d::CCTouch*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3525c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCControl::isTouchInside(cocos2d::CCTouch* p0) -> decltype(isTouchInside(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*>::func(&cocos2d::extension::CCControl::isTouchInside), this);
	using FunctionType = decltype(isTouchInside(p0))(*)(cocos2d::extension::CCControl*, cocos2d::CCTouch*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x352610, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCControl::addHandleOfControlEvent(int p0, cocos2d::extension::CCControlEvent p1) -> decltype(addHandleOfControlEvent(p0, p1)) {
	using FunctionType = decltype(addHandleOfControlEvent(p0, p1))(*)(cocos2d::extension::CCControl*, int, cocos2d::extension::CCControlEvent);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x352790, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::extension::CCControl::addTargetWithActionForControlEvent(cocos2d::CCObject* p0, cocos2d::extension::SEL_CCControlHandler p1, cocos2d::extension::CCControlEvent p2) -> decltype(addTargetWithActionForControlEvent(p0, p1, p2)) {
	using FunctionType = decltype(addTargetWithActionForControlEvent(p0, p1, p2))(*)(cocos2d::extension::CCControl*, cocos2d::CCObject*, cocos2d::extension::SEL_CCControlHandler, cocos2d::extension::CCControlEvent);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x352080, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto cocos2d::extension::CCControl::dispatchListforControlEvent(cocos2d::extension::CCControlEvent p0) -> decltype(dispatchListforControlEvent(p0)) {
	using FunctionType = decltype(dispatchListforControlEvent(p0))(*)(cocos2d::extension::CCControl*, cocos2d::extension::CCControlEvent);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x351b90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCControl::getHandleOfControlEvent(cocos2d::extension::CCControlEvent p0) -> decltype(getHandleOfControlEvent(p0)) {
	using FunctionType = decltype(getHandleOfControlEvent(p0))(*)(cocos2d::extension::CCControl*, cocos2d::extension::CCControlEvent);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x351be0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCControl::hasVisibleParents() -> decltype(hasVisibleParents()) {
	using FunctionType = decltype(hasVisibleParents())(*)(cocos2d::extension::CCControl*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x352730, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::extension::CCControl::removeHandleOfControlEvent(cocos2d::extension::CCControlEvent p0) -> decltype(removeHandleOfControlEvent(p0)) {
	using FunctionType = decltype(removeHandleOfControlEvent(p0))(*)(cocos2d::extension::CCControl*, cocos2d::extension::CCControlEvent);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x352860, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCControl::removeTargetWithActionForControlEvent(cocos2d::CCObject* p0, cocos2d::extension::SEL_CCControlHandler p1, cocos2d::extension::CCControlEvent p2) -> decltype(removeTargetWithActionForControlEvent(p0, p1, p2)) {
	using FunctionType = decltype(removeTargetWithActionForControlEvent(p0, p1, p2))(*)(cocos2d::extension::CCControl*, cocos2d::CCObject*, cocos2d::extension::SEL_CCControlHandler, cocos2d::extension::CCControlEvent);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3522a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}
