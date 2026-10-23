
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/BitmapFontCache.hpp>
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

BitmapFontCache::~BitmapFontCache() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(BitmapFontCache*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x21ff40, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) BitmapFontCache(geode::CutoffConstructor, sizeof(BitmapFontCache));
		geode::DestructorLock::addLock(this);
	}
}

auto BitmapFontCache::purgeSharedFontCache() -> decltype(purgeSharedFontCache()) {
	using FunctionType = decltype(purgeSharedFontCache())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x21ff10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto BitmapFontCache::sharedFontCache() -> decltype(sharedFontCache()) {
	using FunctionType = decltype(sharedFontCache())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x21fe60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto BitmapFontCache::fontWithConfigFile(char const* font, float scale) -> decltype(fontWithConfigFile(font, scale)) {
	using FunctionType = decltype(fontWithConfigFile(font, scale))(*)(BitmapFontCache*, char const*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x220000, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, font, scale);
}

auto BitmapFontCache::init() -> decltype(init()) {
	using FunctionType = decltype(init())(*)(BitmapFontCache*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x21fee0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
