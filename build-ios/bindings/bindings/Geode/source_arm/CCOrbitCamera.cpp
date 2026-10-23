
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCOrbitCamera.hpp>
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

auto cocos2d::CCOrbitCamera::create(float p0, float p1, float p2, float p3, float p4, float p5, float p6) -> decltype(create(p0, p1, p2, p3, p4, p5, p6)) {
	using FunctionType = decltype(create(p0, p1, p2, p3, p4, p5, p6))(*)(float, float, float, float, float, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2f204c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3, p4, p5, p6);
}

auto cocos2d::CCOrbitCamera::copyWithZone(cocos2d::CCZone* p0) -> decltype(copyWithZone(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCZone*>::func(&cocos2d::CCOrbitCamera::copyWithZone), this);
	using FunctionType = decltype(copyWithZone(p0))(*)(cocos2d::CCOrbitCamera*, cocos2d::CCZone*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2f21c4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCOrbitCamera::update(float p0) -> decltype(update(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCOrbitCamera::update), this);
	using FunctionType = decltype(update(p0))(*)(cocos2d::CCOrbitCamera*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2f2568, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCOrbitCamera::startWithTarget(cocos2d::CCNode* p0) -> decltype(startWithTarget(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*>::func(&cocos2d::CCOrbitCamera::startWithTarget), this);
	using FunctionType = decltype(startWithTarget(p0))(*)(cocos2d::CCOrbitCamera*, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2f22e4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCOrbitCamera::initWithDuration(float p0, float p1, float p2, float p3, float p4, float p5, float p6) -> decltype(initWithDuration(p0, p1, p2, p3, p4, p5, p6)) {
	using FunctionType = decltype(initWithDuration(p0, p1, p2, p3, p4, p5, p6))(*)(cocos2d::CCOrbitCamera*, float, float, float, float, float, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2f2148, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5, p6);
}

auto cocos2d::CCOrbitCamera::sphericalRadius(float* p0, float* p1, float* p2) -> decltype(sphericalRadius(p0, p1, p2)) {
	using FunctionType = decltype(sphericalRadius(p0, p1, p2))(*)(cocos2d::CCOrbitCamera*, float*, float*, float*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2f2464, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}
