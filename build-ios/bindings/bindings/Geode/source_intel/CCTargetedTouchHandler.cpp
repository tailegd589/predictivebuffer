
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCTargetedTouchHandler.hpp>
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

cocos2d::CCTargetedTouchHandler::~CCTargetedTouchHandler() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCTargetedTouchHandler*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x4816d0, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCTargetedTouchHandler(geode::CutoffConstructor, sizeof(cocos2d::CCTargetedTouchHandler));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCTargetedTouchHandler::handlerWithDelegate(cocos2d::CCTouchDelegate* p0, int p1, bool p2) -> decltype(handlerWithDelegate(p0, p1, p2)) {
	using FunctionType = decltype(handlerWithDelegate(p0, p1, p2))(*)(cocos2d::CCTouchDelegate*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x481550, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

auto cocos2d::CCTargetedTouchHandler::getClaimedTouches() -> decltype(getClaimedTouches()) {
	using FunctionType = decltype(getClaimedTouches())(*)(cocos2d::CCTargetedTouchHandler*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x481540, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTargetedTouchHandler::initWithDelegate(cocos2d::CCTouchDelegate* p0, int p1, bool p2) -> decltype(initWithDelegate(p0, p1, p2)) {
	using FunctionType = decltype(initWithDelegate(p0, p1, p2))(*)(cocos2d::CCTargetedTouchHandler*, cocos2d::CCTouchDelegate*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x481640, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto cocos2d::CCTargetedTouchHandler::isSwallowsTouches() -> decltype(isSwallowsTouches()) {
	using FunctionType = decltype(isSwallowsTouches())(*)(cocos2d::CCTargetedTouchHandler*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x481520, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTargetedTouchHandler::setSwallowsTouches(bool p0) -> decltype(setSwallowsTouches(p0)) {
	using FunctionType = decltype(setSwallowsTouches(p0))(*)(cocos2d::CCTargetedTouchHandler*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x481530, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
