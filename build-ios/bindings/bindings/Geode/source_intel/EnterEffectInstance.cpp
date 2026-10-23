
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/EnterEffectInstance.hpp>
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

auto EnterEffectInstance::animateValue(int key, float value, float distance, float duration, int easingType, float easingRate, int easingBuffer) -> decltype(animateValue(key, value, distance, duration, easingType, easingRate, easingBuffer)) {
	using FunctionType = decltype(animateValue(key, value, distance, duration, easingType, easingRate, easingBuffer))(*)(EnterEffectInstance*, int, float, float, float, int, float, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5d3b20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key, value, distance, duration, easingType, easingRate, easingBuffer);
}

auto EnterEffectInstance::getValue(int key) -> decltype(getValue(key)) {
	using FunctionType = decltype(getValue(key))(*)(EnterEffectInstance*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5d4010, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto EnterEffectInstance::loadTransitions(EnterEffectObject* object, float time) -> decltype(loadTransitions(object, time)) {
	using FunctionType = decltype(loadTransitions(object, time))(*)(EnterEffectInstance*, EnterEffectObject*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5d3150, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, time);
}

auto EnterEffectInstance::loadValuesFromObject(EnterEffectObject* object) -> decltype(loadValuesFromObject(object)) {
	using FunctionType = decltype(loadValuesFromObject(object))(*)(EnterEffectInstance*, EnterEffectObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5d3040, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto EnterEffectInstance::setValue(int key, float value) -> decltype(setValue(key, value)) {
	using FunctionType = decltype(setValue(key, value))(*)(EnterEffectInstance*, int, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5d3cd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key, value);
}

auto EnterEffectInstance::updateTransitions(float dt, GJBaseGameLayer* layer) -> decltype(updateTransitions(dt, layer)) {
	using FunctionType = decltype(updateTransitions(dt, layer))(*)(EnterEffectInstance*, float, GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5d3e60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt, layer);
}
