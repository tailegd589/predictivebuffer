
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCTwirl.hpp>
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

auto cocos2d::CCTwirl::create(float p0, cocos2d::CCSize const& p1, cocos2d::CCPoint p2, unsigned int p3, float p4) -> decltype(create(p0, p1, p2, p3, p4)) {
	using FunctionType = decltype(create(p0, p1, p2, p3, p4))(*)(float, cocos2d::CCSize const&, cocos2d::CCPoint, unsigned int, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x221558, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3, p4);
}

auto cocos2d::CCTwirl::copyWithZone(cocos2d::CCZone* p0) -> decltype(copyWithZone(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCZone*>::func(&cocos2d::CCTwirl::copyWithZone), this);
	using FunctionType = decltype(copyWithZone(p0))(*)(cocos2d::CCTwirl*, cocos2d::CCZone*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2216f4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCTwirl::update(float p0) -> decltype(update(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCTwirl::update), this);
	using FunctionType = decltype(update(p0))(*)(cocos2d::CCTwirl*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x221854, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCTwirl::initWithDuration(float p0, cocos2d::CCSize const& p1, cocos2d::CCPoint p2, unsigned int p3, float p4) -> decltype(initWithDuration(p0, p1, p2, p3, p4)) {
	using FunctionType = decltype(initWithDuration(p0, p1, p2, p3, p4))(*)(cocos2d::CCTwirl*, float, cocos2d::CCSize const&, cocos2d::CCPoint, unsigned int, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x221688, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4);
}

auto cocos2d::CCTwirl::setPosition(cocos2d::CCPoint const& p0) -> decltype(setPosition(p0)) {
	using FunctionType = decltype(setPosition(p0))(*)(cocos2d::CCTwirl*, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2216ec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
