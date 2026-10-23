
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCScriptEngineManager.hpp>
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

cocos2d::CCScriptEngineManager::~CCScriptEngineManager() {
	// basically we destruct it once by calling the gd function,
	// then we release the lock because there are no other destructors after this
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCScriptEngineManager*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x2aa004, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);
	}
	else {
		geode::DestructorLock::removeLock(this);
	}
}

auto cocos2d::CCScriptEngineManager::purgeSharedManager() -> decltype(purgeSharedManager()) {
	using FunctionType = decltype(purgeSharedManager())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2aa0e8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCScriptEngineManager::sharedManager() -> decltype(sharedManager()) {
	using FunctionType = decltype(sharedManager())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a99d8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCScriptEngineManager::removeScriptEngine() -> decltype(removeScriptEngine()) {
	using FunctionType = decltype(removeScriptEngine())(*)(cocos2d::CCScriptEngineManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2aa040, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCScriptEngineManager::setScriptEngine(cocos2d::CCScriptEngineProtocol* engine) -> decltype(setScriptEngine(engine)) {
	using FunctionType = decltype(setScriptEngine(engine))(*)(cocos2d::CCScriptEngineManager*, cocos2d::CCScriptEngineProtocol*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2aa0b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, engine);
}
