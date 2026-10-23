
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCTextureCache.hpp>
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

cocos2d::CCTextureCache::CCTextureCache() : cocos2d::CCTextureCache(geode::CutoffConstructor, sizeof(cocos2d::CCTextureCache)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCTextureCache::~CCTextureCache();

	using FunctionType = void(*)(cocos2d::CCTextureCache*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x516778, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCTextureCache::~CCTextureCache() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCTextureCache*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x516878, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCTextureCache(geode::CutoffConstructor, sizeof(cocos2d::CCTextureCache));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCTextureCache::purgeSharedTextureCache() -> decltype(purgeSharedTextureCache()) {
	using FunctionType = decltype(purgeSharedTextureCache())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51696c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCTextureCache::reloadAllTextures() -> decltype(reloadAllTextures()) {
	using FunctionType = decltype(reloadAllTextures())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x518df4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCTextureCache::sharedTextureCache() -> decltype(sharedTextureCache()) {
	using FunctionType = decltype(sharedTextureCache())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5166bc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCTextureCache::addETCImage(char const* p0) -> decltype(addETCImage(p0)) {
	using FunctionType = decltype(addETCImage(p0))(*)(cocos2d::CCTextureCache*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5183b4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTextureCache::addImage(char const* p0, bool p1) -> decltype(addImage(p0, p1)) {
	using FunctionType = decltype(addImage(p0, p1))(*)(cocos2d::CCTextureCache*, char const*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x517884, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCTextureCache::addImageAsync(char const* p0, cocos2d::CCObject* p1, cocos2d::SEL_MenuHandler p2, int p3, cocos2d::CCTexture2DPixelFormat p4) -> decltype(addImageAsync(p0, p1, p2, p3, p4)) {
	using FunctionType = decltype(addImageAsync(p0, p1, p2, p3, p4))(*)(cocos2d::CCTextureCache*, char const*, cocos2d::CCObject*, cocos2d::SEL_MenuHandler, int, cocos2d::CCTexture2DPixelFormat);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x516b58, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4);
}

auto cocos2d::CCTextureCache::addImageAsyncCallBack(float p0) -> decltype(addImageAsyncCallBack(p0)) {
	using FunctionType = decltype(addImageAsyncCallBack(p0))(*)(cocos2d::CCTextureCache*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5175c4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTextureCache::addPVRImage(char const* p0) -> decltype(addPVRImage(p0)) {
	using FunctionType = decltype(addPVRImage(p0))(*)(cocos2d::CCTextureCache*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x518054, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTextureCache::addUIImage(cocos2d::CCImage* p0, char const* p1) -> decltype(addUIImage(p0, p1)) {
	using FunctionType = decltype(addUIImage(p0, p1))(*)(cocos2d::CCTextureCache*, cocos2d::CCImage*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x518714, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCTextureCache::description() -> decltype(description()) {
	using FunctionType = decltype(description())(*)(cocos2d::CCTextureCache*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x516998, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTextureCache::dumpCachedTextureInfo() -> decltype(dumpCachedTextureInfo()) {
	using FunctionType = decltype(dumpCachedTextureInfo())(*)(cocos2d::CCTextureCache*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x518df8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTextureCache::prepareAsyncLoading() -> decltype(prepareAsyncLoading()) {
	using FunctionType = decltype(prepareAsyncLoading())(*)(cocos2d::CCTextureCache*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x516b24, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTextureCache::reloadTexture(char const* p0) -> decltype(reloadTexture(p0)) {
	using FunctionType = decltype(reloadTexture(p0))(*)(cocos2d::CCTextureCache*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5189a8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTextureCache::removeAllTextures() -> decltype(removeAllTextures()) {
	using FunctionType = decltype(removeAllTextures())(*)(cocos2d::CCTextureCache*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x518afc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTextureCache::removeTexture(cocos2d::CCTexture2D* p0) -> decltype(removeTexture(p0)) {
	using FunctionType = decltype(removeTexture(p0))(*)(cocos2d::CCTextureCache*, cocos2d::CCTexture2D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x518c94, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTextureCache::removeTextureForKey(char const* p0) -> decltype(removeTextureForKey(p0)) {
	using FunctionType = decltype(removeTextureForKey(p0))(*)(cocos2d::CCTextureCache*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x518ccc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTextureCache::removeUnusedTextures() -> decltype(removeUnusedTextures()) {
	using FunctionType = decltype(removeUnusedTextures())(*)(cocos2d::CCTextureCache*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x518b04, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTextureCache::snapshotTextures() -> decltype(snapshotTextures()) {
	using FunctionType = decltype(snapshotTextures())(*)(cocos2d::CCTextureCache*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5169c8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTextureCache::textureForKey(char const* p0) -> decltype(textureForKey(p0)) {
	using FunctionType = decltype(textureForKey(p0))(*)(cocos2d::CCTextureCache*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x518d5c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
