
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCStandardTouchHandler.hpp>
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

auto cocos2d::CCStandardTouchHandler::handlerWithDelegate(cocos2d::CCTouchDelegate* p0, int p1) -> decltype(handlerWithDelegate(p0, p1)) {
	using FunctionType = decltype(handlerWithDelegate(p0, p1))(*)(cocos2d::CCTouchDelegate*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x481470, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCStandardTouchHandler::initWithDelegate(cocos2d::CCTouchDelegate* p0, int p1) -> decltype(initWithDelegate(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouchDelegate*, int>::func(&cocos2d::CCStandardTouchHandler::initWithDelegate), this);
	using FunctionType = decltype(initWithDelegate(p0, p1))(*)(cocos2d::CCStandardTouchHandler*, cocos2d::CCTouchDelegate*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x481410, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}
