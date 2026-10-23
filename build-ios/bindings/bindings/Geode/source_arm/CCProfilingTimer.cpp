
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCProfilingTimer.hpp>
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

cocos2d::CCProfilingTimer::CCProfilingTimer() : cocos2d::CCProfilingTimer(geode::CutoffConstructor, sizeof(cocos2d::CCProfilingTimer)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCProfilingTimer::~CCProfilingTimer();

	using FunctionType = void(*)(cocos2d::CCProfilingTimer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x446990, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCProfilingTimer::~CCProfilingTimer() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCProfilingTimer*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x4469d0, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCProfilingTimer(geode::CutoffConstructor, sizeof(cocos2d::CCProfilingTimer));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCProfilingTimer::description() -> decltype(description()) {
	using FunctionType = decltype(description())(*)(cocos2d::CCProfilingTimer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x446aac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCProfilingTimer::initWithName(char const* p0) -> decltype(initWithName(p0)) {
	using FunctionType = decltype(initWithName(p0))(*)(cocos2d::CCProfilingTimer*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4467b8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCProfilingTimer::reset() -> decltype(reset()) {
	using FunctionType = decltype(reset())(*)(cocos2d::CCProfilingTimer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x446b30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
