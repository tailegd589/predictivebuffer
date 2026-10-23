
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/CCCircleAlert.hpp>
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

auto CCCircleAlert::create(float duration, float startRadius, float endRadius) -> decltype(create(duration, startRadius, endRadius)) {
	using FunctionType = decltype(create(duration, startRadius, endRadius))(*)(float, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x178ca0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(duration, startRadius, endRadius);
}

auto CCCircleAlert::init(float duration, float startRadius, float endRadius) -> decltype(init(duration, startRadius, endRadius)) {
	using FunctionType = decltype(init(duration, startRadius, endRadius))(*)(CCCircleAlert*, float, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x178e50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, duration, startRadius, endRadius);
}
