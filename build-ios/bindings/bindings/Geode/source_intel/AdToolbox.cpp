
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/AdToolbox.hpp>
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

auto AdToolbox::cacheInterstitial() -> decltype(cacheInterstitial()) {
	using FunctionType = decltype(cacheInterstitial())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0xcb8e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto AdToolbox::cacheRewardedVideo() -> decltype(cacheRewardedVideo()) {
	using FunctionType = decltype(cacheRewardedVideo())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0xcb910, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto AdToolbox::disableBanner() -> decltype(disableBanner()) {
	using FunctionType = decltype(disableBanner())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0xcb8c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto AdToolbox::enableBanner() -> decltype(enableBanner()) {
	using FunctionType = decltype(enableBanner())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0xcb8b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto AdToolbox::enableBannerNoRefresh() -> decltype(enableBannerNoRefresh()) {
	using FunctionType = decltype(enableBannerNoRefresh())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0xcb8a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto AdToolbox::hasCachedInterstitial() -> decltype(hasCachedInterstitial()) {
	using FunctionType = decltype(hasCachedInterstitial())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0xcb8f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto AdToolbox::hasCachedRewardedVideo() -> decltype(hasCachedRewardedVideo()) {
	using FunctionType = decltype(hasCachedRewardedVideo())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0xcb920, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto AdToolbox::isShowingAd() -> decltype(isShowingAd()) {
	using FunctionType = decltype(isShowingAd())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0xcb940, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto AdToolbox::queueRefreshBanner() -> decltype(queueRefreshBanner()) {
	using FunctionType = decltype(queueRefreshBanner())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0xcb890, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto AdToolbox::setupAds() -> decltype(setupAds()) {
	using FunctionType = decltype(setupAds())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0xcb880, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto AdToolbox::showDebug() -> decltype(showDebug()) {
	using FunctionType = decltype(showDebug())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0xcb930, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto AdToolbox::showInterstitial() -> decltype(showInterstitial()) {
	using FunctionType = decltype(showInterstitial())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0xcb8d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto AdToolbox::showRewardedVideo() -> decltype(showRewardedVideo()) {
	using FunctionType = decltype(showRewardedVideo())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0xcb900, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}
