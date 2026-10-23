
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCEaseElastic.hpp>
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

auto cocos2d::CCEaseElastic::create(cocos2d::CCActionInterval* pAction) -> decltype(create(pAction)) {
	using FunctionType = decltype(create(pAction))(*)(cocos2d::CCActionInterval*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x46c574, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(pAction);
}

auto cocos2d::CCEaseElastic::create(cocos2d::CCActionInterval* pAction, float fPeriod) -> decltype(create(pAction, fPeriod)) {
	using FunctionType = decltype(create(pAction, fPeriod))(*)(cocos2d::CCActionInterval*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x46c584, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(pAction, fPeriod);
}

auto cocos2d::CCEaseElastic::copyWithZone(cocos2d::CCZone* pZone) -> decltype(copyWithZone(pZone)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCZone*>::func(&cocos2d::CCEaseElastic::copyWithZone), this);
	using FunctionType = decltype(copyWithZone(pZone))(*)(cocos2d::CCEaseElastic*, cocos2d::CCZone*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x46c698, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, pZone);
}

auto cocos2d::CCEaseElastic::reverse() -> decltype(reverse()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCEaseElastic::reverse), this);
	using FunctionType = decltype(reverse())(*)(cocos2d::CCEaseElastic*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x46c790, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCEaseElastic::initWithAction(cocos2d::CCActionInterval* pAction, float fPeriod) -> decltype(initWithAction(pAction, fPeriod)) {
	using FunctionType = decltype(initWithAction(pAction, fPeriod))(*)(cocos2d::CCEaseElastic*, cocos2d::CCActionInterval*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x46c640, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, pAction, fPeriod);
}
