
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCActionTween.hpp>
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

auto cocos2d::CCActionTween::create(float p0, char const* p1, float p2, float p3) -> decltype(create(p0, p1, p2, p3)) {
	using FunctionType = decltype(create(p0, p1, p2, p3))(*)(float, char const*, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7a5490, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3);
}

auto cocos2d::CCActionTween::create(float p0, int p1, float p2, float p3) -> decltype(create(p0, p1, p2, p3)) {
	using FunctionType = decltype(create(p0, p1, p2, p3))(*)(float, int, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7a5390, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3);
}

auto cocos2d::CCActionTween::update(float p0) -> decltype(update(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCActionTween::update), this);
	using FunctionType = decltype(update(p0))(*)(cocos2d::CCActionTween*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7a5640, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCActionTween::startWithTarget(cocos2d::CCNode* p0) -> decltype(startWithTarget(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*>::func(&cocos2d::CCActionTween::startWithTarget), this);
	using FunctionType = decltype(startWithTarget(p0))(*)(cocos2d::CCActionTween*, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7a55f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCActionTween::reverse() -> decltype(reverse()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCActionTween::reverse), this);
	using FunctionType = decltype(reverse())(*)(cocos2d::CCActionTween*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7a56b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCActionTween::initWithDuration(float p0, char const* p1, float p2, float p3) -> decltype(initWithDuration(p0, p1, p2, p3)) {
	using FunctionType = decltype(initWithDuration(p0, p1, p2, p3))(*)(cocos2d::CCActionTween*, float, char const*, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7a5590, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3);
}

auto cocos2d::CCActionTween::updateTargetValue(float p0) -> decltype(updateTargetValue(p0)) {
	using FunctionType = decltype(updateTargetValue(p0))(*)(cocos2d::CCActionTween*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7a5620, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
