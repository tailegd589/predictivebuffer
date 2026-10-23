
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/PulseEffectAction.hpp>
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

auto PulseEffectAction::isFinished() -> decltype(isFinished()) {
	using FunctionType = decltype(isFinished())(*)(PulseEffectAction*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2d9490, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PulseEffectAction::step(float delta) -> decltype(step(delta)) {
	using FunctionType = decltype(step(delta))(*)(PulseEffectAction*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2d93b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, delta);
}

auto PulseEffectAction::valueForDelta(float currentTime, float fadeInTime, float holdTime, float fadeOutTime) -> decltype(valueForDelta(currentTime, fadeInTime, holdTime, fadeOutTime)) {
	using FunctionType = decltype(valueForDelta(currentTime, fadeInTime, holdTime, fadeOutTime))(*)(PulseEffectAction*, float, float, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2d9430, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, currentTime, fadeInTime, holdTime, fadeOutTime);
}
