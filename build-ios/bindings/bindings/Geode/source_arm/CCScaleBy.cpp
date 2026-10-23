
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCScaleBy.hpp>
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

auto cocos2d::CCScaleBy::create(float duration, float s) -> decltype(create(duration, s)) {
	using FunctionType = decltype(create(duration, s))(*)(float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x33c8c8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(duration, s);
}

auto cocos2d::CCScaleBy::create(float duration, float sx, float sy) -> decltype(create(duration, sx, sy)) {
	using FunctionType = decltype(create(duration, sx, sy))(*)(float, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x33c960, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(duration, sx, sy);
}

auto cocos2d::CCScaleBy::copyWithZone(cocos2d::CCZone* pZone) -> decltype(copyWithZone(pZone)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCZone*>::func(&cocos2d::CCScaleBy::copyWithZone), this);
	using FunctionType = decltype(copyWithZone(pZone))(*)(cocos2d::CCScaleBy*, cocos2d::CCZone*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x33ca04, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, pZone);
}

auto cocos2d::CCScaleBy::startWithTarget(cocos2d::CCNode* pTarget) -> decltype(startWithTarget(pTarget)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*>::func(&cocos2d::CCScaleBy::startWithTarget), this);
	using FunctionType = decltype(startWithTarget(pTarget))(*)(cocos2d::CCScaleBy*, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x33caf4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, pTarget);
}

auto cocos2d::CCScaleBy::reverse() -> decltype(reverse()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCScaleBy::reverse), this);
	using FunctionType = decltype(reverse())(*)(cocos2d::CCScaleBy*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x33cb64, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}
