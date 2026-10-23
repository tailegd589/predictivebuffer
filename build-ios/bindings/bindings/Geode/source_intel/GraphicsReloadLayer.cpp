
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GraphicsReloadLayer.hpp>
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

auto GraphicsReloadLayer::create(cocos2d::TextureQuality quality, cocos2d::CCSize resolution, bool fullscreen, bool borderless, bool fix, bool changedResolution) -> decltype(create(quality, resolution, fullscreen, borderless, fix, changedResolution)) {
	using FunctionType = decltype(create(quality, resolution, fullscreen, borderless, fix, changedResolution))(*)(cocos2d::TextureQuality, cocos2d::CCSize, bool, bool, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7a4e60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(quality, resolution, fullscreen, borderless, fix, changedResolution);
}

auto GraphicsReloadLayer::scene(cocos2d::TextureQuality quality, cocos2d::CCSize resolution, bool fullscreen, bool borderless, bool fix, bool changedResolution) -> decltype(scene(quality, resolution, fullscreen, borderless, fix, changedResolution)) {
	using FunctionType = decltype(scene(quality, resolution, fullscreen, borderless, fix, changedResolution))(*)(cocos2d::TextureQuality, cocos2d::CCSize, bool, bool, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7a4de0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(quality, resolution, fullscreen, borderless, fix, changedResolution);
}

auto GraphicsReloadLayer::init(cocos2d::TextureQuality quality, cocos2d::CCSize resolution, bool fullscreen, bool borderless, bool fix, bool changedResolution) -> decltype(init(quality, resolution, fullscreen, borderless, fix, changedResolution)) {
	using FunctionType = decltype(init(quality, resolution, fullscreen, borderless, fix, changedResolution))(*)(GraphicsReloadLayer*, cocos2d::TextureQuality, cocos2d::CCSize, bool, bool, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7a4ff0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, quality, resolution, fullscreen, borderless, fix, changedResolution);
}

auto GraphicsReloadLayer::performReload() -> decltype(performReload()) {
	using FunctionType = decltype(performReload())(*)(GraphicsReloadLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7a50c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
