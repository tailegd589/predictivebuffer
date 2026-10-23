
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GJGameState.hpp>
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

auto GJGameState::controlTweenAction(int uniqueID, int controlID, GJActionCommand command) -> decltype(controlTweenAction(uniqueID, controlID, command)) {
	using FunctionType = decltype(controlTweenAction(uniqueID, controlID, command))(*)(GJGameState*, int, int, GJActionCommand);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x10e120, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, uniqueID, controlID, command);
}

auto GJGameState::getGameObjectPhysics(GameObject* object) -> decltype(getGameObjectPhysics(object)) {
	using FunctionType = decltype(getGameObjectPhysics(object))(*)(GJGameState*, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x10e7c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GJGameState::processStateTriggers() -> decltype(processStateTriggers()) {
	using FunctionType = decltype(processStateTriggers())(*)(GJGameState*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x10e690, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJGameState::stopTweenAction(int action) -> decltype(stopTweenAction(action)) {
	using FunctionType = decltype(stopTweenAction(action))(*)(GJGameState*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x10e0f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, action);
}

auto GJGameState::tweenValue(float from, float to, int action, float duration, int easing, float rate, int uniqueID, int controlID) -> decltype(tweenValue(from, to, action, duration, easing, rate, uniqueID, controlID)) {
	using FunctionType = decltype(tweenValue(from, to, action, duration, easing, rate, uniqueID, controlID))(*)(GJGameState*, float, float, int, float, int, float, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x10e040, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, from, to, action, duration, easing, rate, uniqueID, controlID);
}

auto GJGameState::updateTweenAction(float value, int action) -> decltype(updateTweenAction(value, action)) {
	using FunctionType = decltype(updateTweenAction(value, action))(*)(GJGameState*, float, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x10e570, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, value, action);
}

auto GJGameState::updateTweenActions(float tweenValue) -> decltype(updateTweenActions(tweenValue)) {
	using FunctionType = decltype(updateTweenActions(tweenValue))(*)(GJGameState*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x10e290, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, tweenValue);
}
