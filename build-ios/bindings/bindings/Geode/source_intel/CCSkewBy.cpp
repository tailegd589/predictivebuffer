
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCSkewBy.hpp>
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

auto cocos2d::CCSkewBy::create(float t, float sx, float sy) -> decltype(create(t, sx, sy)) {
	using FunctionType = decltype(create(t, sx, sy))(*)(float, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3b8ca0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(t, sx, sy);
}

auto cocos2d::CCSkewBy::startWithTarget(cocos2d::CCNode* pTarget) -> decltype(startWithTarget(pTarget)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*>::func(&cocos2d::CCSkewBy::startWithTarget), this);
	using FunctionType = decltype(startWithTarget(pTarget))(*)(cocos2d::CCSkewBy*, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3b8dd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, pTarget);
}

auto cocos2d::CCSkewBy::reverse() -> decltype(reverse()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCSkewBy::reverse), this);
	using FunctionType = decltype(reverse())(*)(cocos2d::CCSkewBy*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3b8ee0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCSkewBy::initWithDuration(float t, float deltaSkewX, float deltaSkewY) -> decltype(initWithDuration(t, deltaSkewX, deltaSkewY)) {
	auto self = addresser::thunkAdjust(Resolve<float, float, float>::func(&cocos2d::CCSkewBy::initWithDuration), this);
	using FunctionType = decltype(initWithDuration(t, deltaSkewX, deltaSkewY))(*)(cocos2d::CCSkewBy*, float, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3b8d80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, t, deltaSkewX, deltaSkewY);
}
