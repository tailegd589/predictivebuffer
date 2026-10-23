
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCProfiler.hpp>
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

cocos2d::CCProfiler::~CCProfiler() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCProfiler*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x4ec3d0, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCProfiler(geode::CutoffConstructor, sizeof(cocos2d::CCProfiler));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCProfiler::sharedProfiler() -> decltype(sharedProfiler()) {
	using FunctionType = decltype(sharedProfiler())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4ec030, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCProfiler::createAndAddTimerWithName(char const* p0) -> decltype(createAndAddTimerWithName(p0)) {
	using FunctionType = decltype(createAndAddTimerWithName(p0))(*)(cocos2d::CCProfiler*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4ec120, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCProfiler::displayTimers() -> decltype(displayTimers()) {
	using FunctionType = decltype(displayTimers())(*)(cocos2d::CCProfiler*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4ec490, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCProfiler::init() -> decltype(init()) {
	using FunctionType = decltype(init())(*)(cocos2d::CCProfiler*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4ec0e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCProfiler::releaseAllTimers() -> decltype(releaseAllTimers()) {
	using FunctionType = decltype(releaseAllTimers())(*)(cocos2d::CCProfiler*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4ec3c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCProfiler::releaseTimer(char const* p0) -> decltype(releaseTimer(p0)) {
	using FunctionType = decltype(releaseTimer(p0))(*)(cocos2d::CCProfiler*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4ec2e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
