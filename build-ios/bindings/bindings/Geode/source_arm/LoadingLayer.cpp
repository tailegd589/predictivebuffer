
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/LoadingLayer.hpp>
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

LoadingLayer::~LoadingLayer() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(LoadingLayer*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x328258, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) LoadingLayer(geode::CutoffConstructor, sizeof(LoadingLayer));
		geode::DestructorLock::addLock(this);
	}
}

auto LoadingLayer::create(bool refresh) -> decltype(create(refresh)) {
	using FunctionType = decltype(create(refresh))(*)(bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3271fc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(refresh);
}

auto LoadingLayer::scene(bool refresh) -> decltype(scene(refresh)) {
	using FunctionType = decltype(scene(refresh))(*)(bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x327124, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(refresh);
}

auto LoadingLayer::getLoadingString() -> decltype(getLoadingString()) {
	using FunctionType = decltype(getLoadingString())(*)(LoadingLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x327a3c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LoadingLayer::init(bool refresh) -> decltype(init(refresh)) {
	using FunctionType = decltype(init(refresh))(*)(LoadingLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3272bc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, refresh);
}

auto LoadingLayer::loadAssets() -> decltype(loadAssets()) {
	using FunctionType = decltype(loadAssets())(*)(LoadingLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x327b18, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LoadingLayer::loadingFinished() -> decltype(loadingFinished()) {
	using FunctionType = decltype(loadingFinished())(*)(LoadingLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x328224, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LoadingLayer::updateProgress(int progress) -> decltype(updateProgress(progress)) {
	using FunctionType = decltype(updateProgress(progress))(*)(LoadingLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x327aac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, progress);
}
