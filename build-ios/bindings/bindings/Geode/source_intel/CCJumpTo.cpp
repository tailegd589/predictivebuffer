
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCJumpTo.hpp>
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

auto cocos2d::CCJumpTo::create(float p0, cocos2d::CCPoint const& p1, float p2, int p3) -> decltype(create(p0, p1, p2, p3)) {
	using FunctionType = decltype(create(p0, p1, p2, p3))(*)(float, cocos2d::CCPoint const&, float, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3b94a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3);
}

auto cocos2d::CCJumpTo::copyWithZone(cocos2d::CCZone* pZone) -> decltype(copyWithZone(pZone)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCZone*>::func(&cocos2d::CCJumpTo::copyWithZone), this);
	using FunctionType = decltype(copyWithZone(pZone))(*)(cocos2d::CCJumpTo*, cocos2d::CCZone*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3b95c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, pZone);
}

auto cocos2d::CCJumpTo::startWithTarget(cocos2d::CCNode* pTarget) -> decltype(startWithTarget(pTarget)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*>::func(&cocos2d::CCJumpTo::startWithTarget), this);
	using FunctionType = decltype(startWithTarget(pTarget))(*)(cocos2d::CCJumpTo*, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3b9730, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, pTarget);
}
