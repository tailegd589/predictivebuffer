
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCLiquid.hpp>
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

auto cocos2d::CCLiquid::create(float p0, cocos2d::CCSize const& p1, unsigned int p2, float p3) -> decltype(create(p0, p1, p2, p3)) {
	using FunctionType = decltype(create(p0, p1, p2, p3))(*)(float, cocos2d::CCSize const&, unsigned int, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x27ee60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3);
}

auto cocos2d::CCLiquid::copyWithZone(cocos2d::CCZone* p0) -> decltype(copyWithZone(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCZone*>::func(&cocos2d::CCLiquid::copyWithZone), this);
	using FunctionType = decltype(copyWithZone(p0))(*)(cocos2d::CCLiquid*, cocos2d::CCZone*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x27efa0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLiquid::update(float p0) -> decltype(update(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCLiquid::update), this);
	using FunctionType = decltype(update(p0))(*)(cocos2d::CCLiquid*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x27f0e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLiquid::initWithDuration(float p0, cocos2d::CCSize const& p1, unsigned int p2, float p3) -> decltype(initWithDuration(p0, p1, p2, p3)) {
	using FunctionType = decltype(initWithDuration(p0, p1, p2, p3))(*)(cocos2d::CCLiquid*, float, cocos2d::CCSize const&, unsigned int, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x27ef60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3);
}
