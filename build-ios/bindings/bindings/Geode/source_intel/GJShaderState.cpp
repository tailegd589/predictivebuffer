
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GJShaderState.hpp>
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

GJShaderState::GJShaderState() {
	using FunctionType = void(*)(GJShaderState*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xca5b0, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

auto GJShaderState::reset() -> decltype(reset()) {
	using FunctionType = decltype(reset())(*)(GJShaderState*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ca210, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJShaderState::stopTweenAction(int action) -> decltype(stopTweenAction(action)) {
	using FunctionType = decltype(stopTweenAction(action))(*)(GJShaderState*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3c9b30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, action);
}

auto GJShaderState::timesyncShaderAction(int action) -> decltype(timesyncShaderAction(action)) {
	using FunctionType = decltype(timesyncShaderAction(action))(*)(GJShaderState*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ca020, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, action);
}

auto GJShaderState::timesyncShaderActions() -> decltype(timesyncShaderActions()) {
	using FunctionType = decltype(timesyncShaderActions())(*)(GJShaderState*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3c9fe0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJShaderState::tweenValue(float fromValue, float toValue, int action, float duration, int easingType, float easingRate) -> decltype(tweenValue(fromValue, toValue, action, duration, easingType, easingRate)) {
	using FunctionType = decltype(tweenValue(fromValue, toValue, action, duration, easingType, easingRate))(*)(GJShaderState*, float, float, int, float, int, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3c9a40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, fromValue, toValue, action, duration, easingType, easingRate);
}

auto GJShaderState::updateTweenAction(float value, int actionID) -> decltype(updateTweenAction(value, actionID)) {
	using FunctionType = decltype(updateTweenAction(value, actionID))(*)(GJShaderState*, float, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3c9b50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, value, actionID);
}

auto GJShaderState::updateTweenActions(float tweenValue) -> decltype(updateTweenActions(tweenValue)) {
	using FunctionType = decltype(updateTweenActions(tweenValue))(*)(GJShaderState*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3c9f40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, tweenValue);
}
