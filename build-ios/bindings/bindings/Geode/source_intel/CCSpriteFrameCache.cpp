
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCSpriteFrameCache.hpp>
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

cocos2d::CCSpriteFrameCache::~CCSpriteFrameCache() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCSpriteFrameCache*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x31c1b0, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCSpriteFrameCache(geode::CutoffConstructor, sizeof(cocos2d::CCSpriteFrameCache));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCSpriteFrameCache::purgeSharedSpriteFrameCache() -> decltype(purgeSharedSpriteFrameCache()) {
	using FunctionType = decltype(purgeSharedSpriteFrameCache())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x31c180, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache() -> decltype(sharedSpriteFrameCache()) {
	using FunctionType = decltype(sharedSpriteFrameCache())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x31c020, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCSpriteFrameCache::addSpriteFrame(cocos2d::CCSpriteFrame* pobFrame, char const* pszFrameName) -> decltype(addSpriteFrame(pobFrame, pszFrameName)) {
	using FunctionType = decltype(addSpriteFrame(pobFrame, pszFrameName))(*)(cocos2d::CCSpriteFrameCache*, cocos2d::CCSpriteFrame*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x31d270, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, pobFrame, pszFrameName);
}

auto cocos2d::CCSpriteFrameCache::addSpriteFramesWithDictionary(cocos2d::CCDictionary* p0, cocos2d::CCTexture2D* p1) -> decltype(addSpriteFramesWithDictionary(p0, p1)) {
	using FunctionType = decltype(addSpriteFramesWithDictionary(p0, p1))(*)(cocos2d::CCSpriteFrameCache*, cocos2d::CCDictionary*, cocos2d::CCTexture2D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x31c310, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCSpriteFrameCache::addSpriteFramesWithFile(char const* p0) -> decltype(addSpriteFramesWithFile(p0)) {
	using FunctionType = decltype(addSpriteFramesWithFile(p0))(*)(cocos2d::CCSpriteFrameCache*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x31cf10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCSpriteFrameCache::addSpriteFramesWithFile(char const* plist, char const* textureFilename) -> decltype(addSpriteFramesWithFile(plist, textureFilename)) {
	using FunctionType = decltype(addSpriteFramesWithFile(plist, textureFilename))(*)(cocos2d::CCSpriteFrameCache*, char const*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x31cea0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, plist, textureFilename);
}

auto cocos2d::CCSpriteFrameCache::addSpriteFramesWithFile(char const* plist, cocos2d::CCTexture2D* texture) -> decltype(addSpriteFramesWithFile(plist, texture)) {
	using FunctionType = decltype(addSpriteFramesWithFile(plist, texture))(*)(cocos2d::CCSpriteFrameCache*, char const*, cocos2d::CCTexture2D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x31ce60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, plist, texture);
}

auto cocos2d::CCSpriteFrameCache::init() -> decltype(init()) {
	using FunctionType = decltype(init())(*)(cocos2d::CCSpriteFrameCache*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x31c100, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCSpriteFrameCache::removeSpriteFrameByName(char const* name) -> decltype(removeSpriteFrameByName(name)) {
	using FunctionType = decltype(removeSpriteFrameByName(name))(*)(cocos2d::CCSpriteFrameCache*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x31d450, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, name);
}

auto cocos2d::CCSpriteFrameCache::removeSpriteFrames() -> decltype(removeSpriteFrames()) {
	using FunctionType = decltype(removeSpriteFrames())(*)(cocos2d::CCSpriteFrameCache*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x31d360, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCSpriteFrameCache::removeSpriteFramesFromDictionary(cocos2d::CCDictionary* p0) -> decltype(removeSpriteFramesFromDictionary(p0)) {
	using FunctionType = decltype(removeSpriteFramesFromDictionary(p0))(*)(cocos2d::CCSpriteFrameCache*, cocos2d::CCDictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x31d930, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCSpriteFrameCache::removeSpriteFramesFromFile(char const* p0) -> decltype(removeSpriteFramesFromFile(p0)) {
	using FunctionType = decltype(removeSpriteFramesFromFile(p0))(*)(cocos2d::CCSpriteFrameCache*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x31d760, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCSpriteFrameCache::removeSpriteFramesFromTexture(cocos2d::CCTexture2D* p0) -> decltype(removeSpriteFramesFromTexture(p0)) {
	using FunctionType = decltype(removeSpriteFramesFromTexture(p0))(*)(cocos2d::CCSpriteFrameCache*, cocos2d::CCTexture2D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x31db60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCSpriteFrameCache::removeUnusedSpriteFrames() -> decltype(removeUnusedSpriteFrames()) {
	using FunctionType = decltype(removeUnusedSpriteFrames())(*)(cocos2d::CCSpriteFrameCache*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x31d3a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCSpriteFrameCache::spriteFrameByName(char const* p0) -> decltype(spriteFrameByName(p0)) {
	using FunctionType = decltype(spriteFrameByName(p0))(*)(cocos2d::CCSpriteFrameCache*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x31de60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
