
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCFadeIn.hpp>
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

auto cocos2d::CCFadeIn::create(float p0) -> decltype(create(p0)) {
	using FunctionType = decltype(create(p0))(*)(float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3bac60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::CCFadeIn::copyWithZone(cocos2d::CCZone* p0) -> decltype(copyWithZone(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCZone*>::func(&cocos2d::CCFadeIn::copyWithZone), this);
	using FunctionType = decltype(copyWithZone(p0))(*)(cocos2d::CCFadeIn*, cocos2d::CCZone*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3bad00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCFadeIn::update(float p0) -> decltype(update(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCFadeIn::update), this);
	using FunctionType = decltype(update(p0))(*)(cocos2d::CCFadeIn*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3badd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCFadeIn::reverse() -> decltype(reverse()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCFadeIn::reverse), this);
	using FunctionType = decltype(reverse())(*)(cocos2d::CCFadeIn*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3bae30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}
