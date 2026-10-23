
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GJGameLoadingLayer.hpp>
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

auto GJGameLoadingLayer::create(GJGameLevel* level, bool editor) -> decltype(create(level, editor)) {
	using FunctionType = decltype(create(level, editor))(*)(GJGameLevel*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x165320, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(level, editor);
}

auto GJGameLoadingLayer::transitionToLoadingLayer(GJGameLevel* level, bool editor) -> decltype(transitionToLoadingLayer(level, editor)) {
	using FunctionType = decltype(transitionToLoadingLayer(level, editor))(*)(GJGameLevel*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x165200, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(level, editor);
}

auto GJGameLoadingLayer::onEnter() -> decltype(onEnter()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJGameLoadingLayer::onEnter), this);
	using FunctionType = decltype(onEnter())(*)(GJGameLoadingLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1657f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJGameLoadingLayer::onEnterTransitionDidFinish() -> decltype(onEnterTransitionDidFinish()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJGameLoadingLayer::onEnterTransitionDidFinish), this);
	using FunctionType = decltype(onEnterTransitionDidFinish())(*)(GJGameLoadingLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1657e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJGameLoadingLayer::gameLayerDidUnload() -> decltype(gameLayerDidUnload()) {
	using FunctionType = decltype(gameLayerDidUnload())(*)(GJGameLoadingLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x10faf0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJGameLoadingLayer::init(GJGameLevel* level, bool editor) -> decltype(init(level, editor)) {
	using FunctionType = decltype(init(level, editor))(*)(GJGameLoadingLayer*, GJGameLevel*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x165680, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, level, editor);
}

auto GJGameLoadingLayer::loadLevel() -> decltype(loadLevel()) {
	using FunctionType = decltype(loadLevel())(*)(GJGameLoadingLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x165780, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
