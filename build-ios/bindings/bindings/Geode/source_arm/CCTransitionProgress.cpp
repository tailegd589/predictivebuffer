
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCTransitionProgress.hpp>
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

cocos2d::CCTransitionProgress::CCTransitionProgress() : cocos2d::CCTransitionProgress(geode::CutoffConstructor, sizeof(cocos2d::CCTransitionProgress)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCTransitionProgress::~CCTransitionProgress();

	using FunctionType = void(*)(cocos2d::CCTransitionProgress*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22de7c, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTransitionProgress::create(float p0, cocos2d::CCScene* p1) -> decltype(create(p0, p1)) {
	using FunctionType = decltype(create(p0, p1))(*)(float, cocos2d::CCScene*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22dec4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCTransitionProgress::onEnter() -> decltype(onEnter()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTransitionProgress::onEnter), this);
	using FunctionType = decltype(onEnter())(*)(cocos2d::CCTransitionProgress*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22df68, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTransitionProgress::onExit() -> decltype(onExit()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTransitionProgress::onExit), this);
	using FunctionType = decltype(onExit())(*)(cocos2d::CCTransitionProgress*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22e118, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTransitionProgress::progressTimerNodeWithRenderTexture(cocos2d::CCRenderTexture* p0) -> decltype(progressTimerNodeWithRenderTexture(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCRenderTexture*>::func(&cocos2d::CCTransitionProgress::progressTimerNodeWithRenderTexture), this);
	using FunctionType = decltype(progressTimerNodeWithRenderTexture(p0))(*)(cocos2d::CCTransitionProgress*, cocos2d::CCRenderTexture*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22e16c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCTransitionProgress::setupTransition() -> decltype(setupTransition()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTransitionProgress::setupTransition), this);
	using FunctionType = decltype(setupTransition())(*)(cocos2d::CCTransitionProgress*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22e154, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTransitionProgress::sceneOrder() -> decltype(sceneOrder()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTransitionProgress::sceneOrder), this);
	using FunctionType = decltype(sceneOrder())(*)(cocos2d::CCTransitionProgress*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22e14c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}
