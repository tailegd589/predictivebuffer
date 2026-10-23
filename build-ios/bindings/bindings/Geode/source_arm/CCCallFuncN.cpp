
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCCallFuncN.hpp>
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

auto cocos2d::CCCallFuncN::create(cocos2d::CCObject* pSelectorTarget, cocos2d::SEL_CallFuncN selector) -> decltype(create(pSelectorTarget, selector)) {
	using FunctionType = decltype(create(pSelectorTarget, selector))(*)(cocos2d::CCObject*, cocos2d::SEL_CallFuncN);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6b3bc4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(pSelectorTarget, selector);
}

auto cocos2d::CCCallFuncN::initWithTarget(cocos2d::CCObject* pSelectorTarget, cocos2d::SEL_CallFuncN selector) -> decltype(initWithTarget(pSelectorTarget, selector)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCObject*, cocos2d::SEL_CallFuncN>::func(&cocos2d::CCCallFuncN::initWithTarget), this);
	using FunctionType = decltype(initWithTarget(pSelectorTarget, selector))(*)(cocos2d::CCCallFuncN*, cocos2d::CCObject*, cocos2d::SEL_CallFuncN);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6b3cd4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, pSelectorTarget, selector);
}

auto cocos2d::CCCallFuncN::copyWithZone(cocos2d::CCZone* zone) -> decltype(copyWithZone(zone)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCZone*>::func(&cocos2d::CCCallFuncN::copyWithZone), this);
	using FunctionType = decltype(copyWithZone(zone))(*)(cocos2d::CCCallFuncN*, cocos2d::CCZone*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6b3d28, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, zone);
}

auto cocos2d::CCCallFuncN::execute() -> decltype(execute()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCCallFuncN::execute), this);
	using FunctionType = decltype(execute())(*)(cocos2d::CCCallFuncN*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6b3b50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}
