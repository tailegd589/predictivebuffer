
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
	static auto func = wrapFunction<FunctionType>(base::get() + 0xdd490, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto LevelSettingsObject::objectFromDict(cocos2d::CCDictionary* dict) -> decltype(objectFromDict(dict)) {
	using FunctionType = decltype(objectFromDict(dict))(*)(cocos2d::CCDictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x102fe0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(dict);
}

auto LevelSettingsObject::objectFromString(gd::string const& str) -> decltype(objectFromString(str)) {
	using FunctionType = decltype(objectFromString(str))(*)(gd::string const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xdf2c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(str);
}

auto LevelSettingsObject::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&LevelSettingsObject::init), this);
	using FunctionType = decltype(init())(*)(LevelSettingsObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x102e30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto LevelSettingsObject::getSaveString() -> decltype(getSaveString()) {
	using FunctionType = decltype(getSaveString())(*)(LevelSettingsObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xe3820, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LevelSettingsObject::setupColorsFromLegacyMode(cocos2d::CCDictionary* dict) -> decltype(setupColorsFromLegacyMode(dict)) {
	using FunctionType = decltype(setupColorsFromLegacyMode(dict))(*)(LevelSettingsObject*, cocos2d::CCDictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1047e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dict);
}

auto LevelSettingsObject::shouldUseYSection() -> decltype(shouldUseYSection()) {
	using FunctionType = decltype(shouldUseYSection())(*)(LevelSettingsObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x102fc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
