
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCTouch.hpp>
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

auto cocos2d::CCTouch::getDelta() const  -> decltype(getDelta()) {
	using FunctionType = decltype(getDelta())(*)(cocos2d::CCTouch const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x596d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTouch::getLocation() const  -> decltype(getLocation()) {
	using FunctionType = decltype(getLocation())(*)(cocos2d::CCTouch const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x59640, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTouch::getLocationInView() const  -> decltype(getLocationInView()) {
	using FunctionType = decltype(getLocationInView())(*)(cocos2d::CCTouch const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x595e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTouch::getPreviousLocation() const  -> decltype(getPreviousLocation()) {
	using FunctionType = decltype(getPreviousLocation())(*)(cocos2d::CCTouch const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x59670, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTouch::getPreviousLocationInView() const  -> decltype(getPreviousLocationInView()) {
	using FunctionType = decltype(getPreviousLocationInView())(*)(cocos2d::CCTouch const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x59600, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTouch::getStartLocation() const  -> decltype(getStartLocation()) {
	using FunctionType = decltype(getStartLocation())(*)(cocos2d::CCTouch const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x596a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTouch::getStartLocationInView() const  -> decltype(getStartLocationInView()) {
	using FunctionType = decltype(getStartLocationInView())(*)(cocos2d::CCTouch const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x59620, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
