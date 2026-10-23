
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCKeyboardDispatcher.hpp>
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

cocos2d::CCKeyboardDispatcher::CCKeyboardDispatcher() : cocos2d::CCKeyboardDispatcher(geode::CutoffConstructor, sizeof(cocos2d::CCKeyboardDispatcher)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCKeyboardDispatcher::~CCKeyboardDispatcher();

	using FunctionType = void(*)(cocos2d::CCKeyboardDispatcher*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b0168, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCKeyboardDispatcher::~CCKeyboardDispatcher() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCKeyboardDispatcher*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x1b01e0, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCKeyboardDispatcher(geode::CutoffConstructor, sizeof(cocos2d::CCKeyboardDispatcher));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCKeyboardDispatcher::convertKeyCode(cocos2d::enumKeyCodes p0) -> decltype(convertKeyCode(p0)) {
	using FunctionType = decltype(convertKeyCode(p0))(*)(cocos2d::enumKeyCodes);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b07d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::CCKeyboardDispatcher::addDelegate(cocos2d::CCKeyboardDelegate* p0) -> decltype(addDelegate(p0)) {
	using FunctionType = decltype(addDelegate(p0))(*)(cocos2d::CCKeyboardDispatcher*, cocos2d::CCKeyboardDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b043c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCKeyboardDispatcher::dispatchKeyboardMSG(cocos2d::enumKeyCodes p0, bool p1, bool p2, double p3) -> decltype(dispatchKeyboardMSG(p0, p1, p2, p3)) {
	using FunctionType = decltype(dispatchKeyboardMSG(p0, p1, p2, p3))(*)(cocos2d::CCKeyboardDispatcher*, cocos2d::enumKeyCodes, bool, bool, double);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b04d4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3);
}

auto cocos2d::CCKeyboardDispatcher::forceAddDelegate(cocos2d::CCKeyboardDelegate* p0) -> decltype(forceAddDelegate(p0)) {
	using FunctionType = decltype(forceAddDelegate(p0))(*)(cocos2d::CCKeyboardDispatcher*, cocos2d::CCKeyboardDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b0498, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCKeyboardDispatcher::forceRemoveDelegate(cocos2d::CCKeyboardDelegate* p0) -> decltype(forceRemoveDelegate(p0)) {
	using FunctionType = decltype(forceRemoveDelegate(p0))(*)(cocos2d::CCKeyboardDispatcher*, cocos2d::CCKeyboardDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b03a8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCKeyboardDispatcher::keyToString(cocos2d::enumKeyCodes p0) -> decltype(keyToString(p0)) {
	using FunctionType = decltype(keyToString(p0))(*)(cocos2d::CCKeyboardDispatcher*, cocos2d::enumKeyCodes);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b0804, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCKeyboardDispatcher::removeDelegate(cocos2d::CCKeyboardDelegate* p0) -> decltype(removeDelegate(p0)) {
	using FunctionType = decltype(removeDelegate(p0))(*)(cocos2d::CCKeyboardDispatcher*, cocos2d::CCKeyboardDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b02e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCKeyboardDispatcher::updateModifierKeys(bool p0, bool p1, bool p2, bool p3) -> decltype(updateModifierKeys(p0, p1, p2, p3)) {
	using FunctionType = decltype(updateModifierKeys(p0, p1, p2, p3))(*)(cocos2d::CCKeyboardDispatcher*, bool, bool, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b07ec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3);
}
