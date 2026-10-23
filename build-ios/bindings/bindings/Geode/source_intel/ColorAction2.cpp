
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/ColorAction2.hpp>
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

ColorAction2::ColorAction2(cocos2d::ccColor3B fromColor, cocos2d::ccColor3B toColor, float duration, double unused, bool blending, int playerColor, float fromOpacity, float toOpacity) {
	using FunctionType = void(*)(ColorAction2*, cocos2d::ccColor3B, cocos2d::ccColor3B, float, double, bool, int, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4ed610, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this, fromColor, toColor, duration, unused, blending, playerColor, fromOpacity, toOpacity);
}

auto ColorAction2::resetAction() -> decltype(resetAction()) {
	using FunctionType = decltype(resetAction())(*)(ColorAction2*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4ed810, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto ColorAction2::step(float dt) -> decltype(step(dt)) {
	using FunctionType = decltype(step(dt))(*)(ColorAction2*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4ed710, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt);
}

auto ColorAction2::updateCustomColor(cocos2d::ccColor3B color1, cocos2d::ccColor3B color2) -> decltype(updateCustomColor(color1, color2)) {
	using FunctionType = decltype(updateCustomColor(color1, color2))(*)(ColorAction2*, cocos2d::ccColor3B, cocos2d::ccColor3B);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4ed830, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, color1, color2);
}
