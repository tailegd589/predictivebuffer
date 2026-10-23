
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCEaseExponentialIn.hpp>
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

auto cocos2d::CCEaseExponentialIn::create(cocos2d::CCActionInterval* p0) -> decltype(create(p0)) {
	using FunctionType = decltype(create(p0))(*)(cocos2d::CCActionInterval*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x515000, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::CCEaseExponentialIn::copyWithZone(cocos2d::CCZone* p0) -> decltype(copyWithZone(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCZone*>::func(&cocos2d::CCEaseExponentialIn::copyWithZone), this);
	using FunctionType = decltype(copyWithZone(p0))(*)(cocos2d::CCEaseExponentialIn*, cocos2d::CCZone*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5150a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCEaseExponentialIn::update(float p0) -> decltype(update(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCEaseExponentialIn::update), this);
	using FunctionType = decltype(update(p0))(*)(cocos2d::CCEaseExponentialIn*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5151a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCEaseExponentialIn::reverse() -> decltype(reverse()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCEaseExponentialIn::reverse), this);
	using FunctionType = decltype(reverse())(*)(cocos2d::CCEaseExponentialIn*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5151f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}
