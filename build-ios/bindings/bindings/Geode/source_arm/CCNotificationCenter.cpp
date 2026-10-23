
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCNotificationCenter.hpp>
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

cocos2d::CCNotificationCenter::CCNotificationCenter() : cocos2d::CCNotificationCenter(geode::CutoffConstructor, sizeof(cocos2d::CCNotificationCenter)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCNotificationCenter::~CCNotificationCenter();

	using FunctionType = void(*)(cocos2d::CCNotificationCenter*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x228bc0, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCNotificationCenter::~CCNotificationCenter() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCNotificationCenter*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x228c70, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCNotificationCenter(geode::CutoffConstructor, sizeof(cocos2d::CCNotificationCenter));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCNotificationCenter::purgeNotificationCenter() -> decltype(purgeNotificationCenter()) {
	using FunctionType = decltype(purgeNotificationCenter())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x228db4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCNotificationCenter::sharedNotificationCenter() -> decltype(sharedNotificationCenter()) {
	using FunctionType = decltype(sharedNotificationCenter())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x228d1c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCNotificationCenter::addObserver(cocos2d::CCObject* p0, cocos2d::SEL_CallFuncO p1, char const* p2, cocos2d::CCObject* p3) -> decltype(addObserver(p0, p1, p2, p3)) {
	using FunctionType = decltype(addObserver(p0, p1, p2, p3))(*)(cocos2d::CCNotificationCenter*, cocos2d::CCObject*, cocos2d::SEL_CallFuncO, char const*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x228ea0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3);
}

auto cocos2d::CCNotificationCenter::getObserverHandlerByName(char const* p0) -> decltype(getObserverHandlerByName(p0)) {
	using FunctionType = decltype(getObserverHandlerByName(p0))(*)(cocos2d::CCNotificationCenter*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x229490, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCNotificationCenter::observerExisted(cocos2d::CCObject* p0, char const* p1) -> decltype(observerExisted(p0, p1)) {
	using FunctionType = decltype(observerExisted(p0, p1))(*)(cocos2d::CCNotificationCenter*, cocos2d::CCObject*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x228de0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCNotificationCenter::postNotification(char const* p0) -> decltype(postNotification(p0)) {
	using FunctionType = decltype(postNotification(p0))(*)(cocos2d::CCNotificationCenter*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x229488, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCNotificationCenter::postNotification(char const* p0, cocos2d::CCObject* p1) -> decltype(postNotification(p0, p1)) {
	using FunctionType = decltype(postNotification(p0, p1))(*)(cocos2d::CCNotificationCenter*, char const*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x229300, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCNotificationCenter::registerScriptObserver(cocos2d::CCObject* p0, int p1, char const* p2) -> decltype(registerScriptObserver(p0, p1, p2)) {
	using FunctionType = decltype(registerScriptObserver(p0, p1, p2))(*)(cocos2d::CCNotificationCenter*, cocos2d::CCObject*, int, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22912c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto cocos2d::CCNotificationCenter::removeAllObservers(cocos2d::CCObject* p0) -> decltype(removeAllObservers(p0)) {
	using FunctionType = decltype(removeAllObservers(p0))(*)(cocos2d::CCNotificationCenter*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x229084, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCNotificationCenter::removeObserver(cocos2d::CCObject* p0, char const* p1) -> decltype(removeObserver(p0, p1)) {
	using FunctionType = decltype(removeObserver(p0, p1))(*)(cocos2d::CCNotificationCenter*, cocos2d::CCObject*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x228fc4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCNotificationCenter::unregisterScriptObserver(cocos2d::CCObject* p0, char const* p1) -> decltype(unregisterScriptObserver(p0, p1)) {
	using FunctionType = decltype(unregisterScriptObserver(p0, p1))(*)(cocos2d::CCNotificationCenter*, cocos2d::CCObject*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22924c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}
