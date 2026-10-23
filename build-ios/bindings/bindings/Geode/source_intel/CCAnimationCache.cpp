
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCAnimationCache.hpp>
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

cocos2d::CCAnimationCache::CCAnimationCache() : cocos2d::CCAnimationCache(geode::CutoffConstructor, sizeof(cocos2d::CCAnimationCache)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCAnimationCache::~CCAnimationCache();

	using FunctionType = void(*)(cocos2d::CCAnimationCache*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x46d180, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCAnimationCache::~CCAnimationCache() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCAnimationCache*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x46d1b0, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCAnimationCache(geode::CutoffConstructor, sizeof(cocos2d::CCAnimationCache));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCAnimationCache::purgeSharedAnimationCache() -> decltype(purgeSharedAnimationCache()) {
	using FunctionType = decltype(purgeSharedAnimationCache())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x46d150, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCAnimationCache::sharedAnimationCache() -> decltype(sharedAnimationCache()) {
	using FunctionType = decltype(sharedAnimationCache())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x46d040, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCAnimationCache::addAnimation(cocos2d::CCAnimation* p0, const char* p1) -> decltype(addAnimation(p0, p1)) {
	using FunctionType = decltype(addAnimation(p0, p1))(*)(cocos2d::CCAnimationCache*, cocos2d::CCAnimation*, const char*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x46d270, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCAnimationCache::addAnimationsWithDictionary(cocos2d::CCDictionary* p0, const char* p1) -> decltype(addAnimationsWithDictionary(p0, p1)) {
	using FunctionType = decltype(addAnimationsWithDictionary(p0, p1))(*)(cocos2d::CCAnimationCache*, cocos2d::CCDictionary*, const char*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x46dbf0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCAnimationCache::addAnimationsWithFile(const char* p0) -> decltype(addAnimationsWithFile(p0)) {
	using FunctionType = decltype(addAnimationsWithFile(p0))(*)(cocos2d::CCAnimationCache*, const char*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x46de10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCAnimationCache::animationByName(const char* p0) -> decltype(animationByName(p0)) {
	using FunctionType = decltype(animationByName(p0))(*)(cocos2d::CCAnimationCache*, const char*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x46d440, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCAnimationCache::init() -> decltype(init()) {
	using FunctionType = decltype(init())(*)(cocos2d::CCAnimationCache*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x46d110, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCAnimationCache::parseVersion1(cocos2d::CCDictionary* p0) -> decltype(parseVersion1(p0)) {
	using FunctionType = decltype(parseVersion1(p0))(*)(cocos2d::CCAnimationCache*, cocos2d::CCDictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x46d520, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCAnimationCache::parseVersion2(cocos2d::CCDictionary* p0) -> decltype(parseVersion2(p0)) {
	using FunctionType = decltype(parseVersion2(p0))(*)(cocos2d::CCAnimationCache*, cocos2d::CCDictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x46d7c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCAnimationCache::removeAnimationByName(const char* p0) -> decltype(removeAnimationByName(p0)) {
	using FunctionType = decltype(removeAnimationByName(p0))(*)(cocos2d::CCAnimationCache*, const char*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x46d360, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
