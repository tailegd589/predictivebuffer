
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCTime.hpp>
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

auto cocos2d::CCTime::gettimeofdayCocos2d(cocos2d::cc_timeval* p0, void* p1) -> decltype(gettimeofdayCocos2d(p0, p1)) {
	using FunctionType = decltype(gettimeofdayCocos2d(p0, p1))(*)(cocos2d::cc_timeval*, void*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3217c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCTime::timersubCocos2d(cocos2d::cc_timeval* p0, cocos2d::cc_timeval* p1) -> decltype(timersubCocos2d(p0, p1)) {
	using FunctionType = decltype(timersubCocos2d(p0, p1))(*)(cocos2d::cc_timeval*, cocos2d::cc_timeval*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3217e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}
