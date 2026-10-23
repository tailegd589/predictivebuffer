
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCCallFuncND.hpp>
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

auto cocos2d::CCCallFuncND::create(cocos2d::CCObject* p0, cocos2d::SEL_CallFuncND p1, void* p2) -> decltype(create(p0, p1, p2)) {
	using FunctionType = decltype(create(p0, p1, p2))(*)(cocos2d::CCObject*, cocos2d::SEL_CallFuncND, void*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7ad690, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

auto cocos2d::CCCallFuncND::initWithTarget(cocos2d::CCObject* p0, cocos2d::SEL_CallFuncND p1, void* p2) -> decltype(initWithTarget(p0, p1, p2)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCObject*, cocos2d::SEL_CallFuncND, void*>::func(&cocos2d::CCCallFuncND::initWithTarget), this);
	using FunctionType = decltype(initWithTarget(p0, p1, p2))(*)(cocos2d::CCCallFuncND*, cocos2d::CCObject*, cocos2d::SEL_CallFuncND, void*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7ad780, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2);
}

auto cocos2d::CCCallFuncND::copyWithZone(cocos2d::CCZone* p0) -> decltype(copyWithZone(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCZone*>::func(&cocos2d::CCCallFuncND::copyWithZone), this);
	using FunctionType = decltype(copyWithZone(p0))(*)(cocos2d::CCCallFuncND*, cocos2d::CCZone*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7ad7f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCCallFuncND::execute() -> decltype(execute()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCCallFuncND::execute), this);
	using FunctionType = decltype(execute())(*)(cocos2d::CCCallFuncND*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7ad910, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}
