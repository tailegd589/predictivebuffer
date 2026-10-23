
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCRotateTo.hpp>
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

auto cocos2d::CCRotateTo::create(float p0, float p1) -> decltype(create(p0, p1)) {
	using FunctionType = decltype(create(p0, p1))(*)(float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3b7800, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCRotateTo::create(float fDuration, float fDeltaAngleX, float fDeltaAngleY) -> decltype(create(fDuration, fDeltaAngleX, fDeltaAngleY)) {
	using FunctionType = decltype(create(fDuration, fDeltaAngleX, fDeltaAngleY))(*)(float, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3b7900, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(fDuration, fDeltaAngleX, fDeltaAngleY);
}

auto cocos2d::CCRotateTo::initWithDuration(float fDuration, float fDeltaAngleX, float fDeltaAngleY) -> decltype(initWithDuration(fDuration, fDeltaAngleX, fDeltaAngleY)) {
	auto self = addresser::thunkAdjust(Resolve<float, float, float>::func(&cocos2d::CCRotateTo::initWithDuration), this);
	using FunctionType = decltype(initWithDuration(fDuration, fDeltaAngleX, fDeltaAngleY))(*)(cocos2d::CCRotateTo*, float, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3b79d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, fDuration, fDeltaAngleX, fDeltaAngleY);
}

auto cocos2d::CCRotateTo::copyWithZone(cocos2d::CCZone* p0) -> decltype(copyWithZone(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCZone*>::func(&cocos2d::CCRotateTo::copyWithZone), this);
	using FunctionType = decltype(copyWithZone(p0))(*)(cocos2d::CCRotateTo*, cocos2d::CCZone*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3b7a10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCRotateTo::update(float p0) -> decltype(update(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCRotateTo::update), this);
	using FunctionType = decltype(update(p0))(*)(cocos2d::CCRotateTo*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3b7c50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCRotateTo::startWithTarget(cocos2d::CCNode* p0) -> decltype(startWithTarget(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*>::func(&cocos2d::CCRotateTo::startWithTarget), this);
	using FunctionType = decltype(startWithTarget(p0))(*)(cocos2d::CCRotateTo*, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3b7b00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCRotateTo::initWithDuration(float p0, float p1) -> decltype(initWithDuration(p0, p1)) {
	using FunctionType = decltype(initWithDuration(p0, p1))(*)(cocos2d::CCRotateTo*, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3b78c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}
