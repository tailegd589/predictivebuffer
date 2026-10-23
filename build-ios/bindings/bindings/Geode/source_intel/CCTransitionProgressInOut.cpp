
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCTransitionProgressInOut.hpp>
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

auto cocos2d::CCTransitionProgressInOut::create(float p0, cocos2d::CCScene* p1) -> decltype(create(p0, p1)) {
	using FunctionType = decltype(create(p0, p1))(*)(float, cocos2d::CCScene*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x28dce0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCTransitionProgressInOut::progressTimerNodeWithRenderTexture(cocos2d::CCRenderTexture* p0) -> decltype(progressTimerNodeWithRenderTexture(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCRenderTexture*>::func(&cocos2d::CCTransitionProgressInOut::progressTimerNodeWithRenderTexture), this);
	using FunctionType = decltype(progressTimerNodeWithRenderTexture(p0))(*)(cocos2d::CCTransitionProgressInOut*, cocos2d::CCRenderTexture*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x28ddc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCTransitionProgressInOut::sceneOrder() -> decltype(sceneOrder()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTransitionProgressInOut::sceneOrder), this);
	using FunctionType = decltype(sceneOrder())(*)(cocos2d::CCTransitionProgressInOut*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x28dd80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTransitionProgressInOut::setupTransition() -> decltype(setupTransition()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTransitionProgressInOut::setupTransition), this);
	using FunctionType = decltype(setupTransition())(*)(cocos2d::CCTransitionProgressInOut*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x28dd90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}
