
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/LoadingCircleSprite.hpp>
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

auto LoadingCircleSprite::create(float spinSpeed) -> decltype(create(spinSpeed)) {
	using FunctionType = decltype(create(spinSpeed))(*)(float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4bf520, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(spinSpeed);
}

auto LoadingCircleSprite::fadeInCircle(bool resetOpacity, float duration, float opacity) -> decltype(fadeInCircle(resetOpacity, duration, opacity)) {
	using FunctionType = decltype(fadeInCircle(resetOpacity, duration, opacity))(*)(LoadingCircleSprite*, bool, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4bf6c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, resetOpacity, duration, opacity);
}

auto LoadingCircleSprite::hideCircle() -> decltype(hideCircle()) {
	using FunctionType = decltype(hideCircle())(*)(LoadingCircleSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4bf740, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LoadingCircleSprite::init(float spinSpeed) -> decltype(init(spinSpeed)) {
	using FunctionType = decltype(init(spinSpeed))(*)(LoadingCircleSprite*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4bf600, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, spinSpeed);
}
