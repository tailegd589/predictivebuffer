
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCPoolManager.hpp>
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

cocos2d::CCPoolManager::CCPoolManager() {
	using FunctionType = void(*)(cocos2d::CCPoolManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x36f85c, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCPoolManager::~CCPoolManager() {
	// basically we destruct it once by calling the gd function,
	// then we release the lock because there are no other destructors after this
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCPoolManager*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x36f8b0, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);
	}
	else {
		geode::DestructorLock::removeLock(this);
	}
}

auto cocos2d::CCPoolManager::purgePoolManager() -> decltype(purgePoolManager()) {
	using FunctionType = decltype(purgePoolManager())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x36f828, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCPoolManager::sharedPoolManager() -> decltype(sharedPoolManager()) {
	using FunctionType = decltype(sharedPoolManager())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x36f730, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCPoolManager::addObject(cocos2d::CCObject* p0) -> decltype(addObject(p0)) {
	using FunctionType = decltype(addObject(p0))(*)(cocos2d::CCPoolManager*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x36fc28, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCPoolManager::finalize() -> decltype(finalize()) {
	using FunctionType = decltype(finalize())(*)(cocos2d::CCPoolManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x36f9a8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCPoolManager::getCurReleasePool() -> decltype(getCurReleasePool()) {
	using FunctionType = decltype(getCurReleasePool())(*)(cocos2d::CCPoolManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x36fc74, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCPoolManager::pop() -> decltype(pop()) {
	using FunctionType = decltype(pop())(*)(cocos2d::CCPoolManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x36fb20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCPoolManager::push() -> decltype(push()) {
	using FunctionType = decltype(push())(*)(cocos2d::CCPoolManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x36fa64, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCPoolManager::removeObject(cocos2d::CCObject* p0) -> decltype(removeObject(p0)) {
	using FunctionType = decltype(removeObject(p0))(*)(cocos2d::CCPoolManager*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x36fbd4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
