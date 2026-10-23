
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/LevelSettingsObject.hpp>
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

auto LevelSettingsObject::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0xc35d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto LevelSettingsObject::objectFromDict(cocos2d::CCDictionary* dict) -> decltype(objectFromDict(dict)) {
	using FunctionType = decltype(objectFromDict(dict))(*)(cocos2d::CCDictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xe17cc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(dict);
}

auto LevelSettingsObject::objectFromString(gd::string const& str) -> decltype(objectFromString(str)) {
	using FunctionType = decltype(objectFromString(str))(*)(gd::string const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xc4fc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(str);
}

auto LevelSettingsObject::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&LevelSettingsObject::init), this);
	using FunctionType = decltype(init())(*)(LevelSettingsObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xe1654, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto LevelSettingsObject::getSaveString() -> decltype(getSaveString()) {
	using FunctionType = decltype(getSaveString())(*)(LevelSettingsObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xc8fa8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelSettingsObject::setupColorsFromLegacyMode(cocos2d::CCDictionary* dict) -> decltype(setupColorsFromLegacyMode(dict)) {
	using FunctionType = decltype(setupColorsFromLegacyMode(dict))(*)(LevelSettingsObject*, cocos2d::CCDictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xe2e84, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dict);
}

auto LevelSettingsObject::shouldUseYSection() -> decltype(shouldUseYSection()) {
	using FunctionType = decltype(shouldUseYSection())(*)(LevelSettingsObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xe17ac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
