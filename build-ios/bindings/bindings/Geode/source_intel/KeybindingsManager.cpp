
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/KeybindingsManager.hpp>
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

auto KeybindingsManager::sharedState() -> decltype(sharedState()) {
	using FunctionType = decltype(sharedState())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e50f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto KeybindingsManager::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&KeybindingsManager::init), this);
	using FunctionType = decltype(init())(*)(KeybindingsManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e5280, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto KeybindingsManager::commandForKey(cocos2d::enumKeyCodes key, GJKeyGroup group, bool control, bool alt, bool shift) -> decltype(commandForKey(key, group, control, alt, shift)) {
	using FunctionType = decltype(commandForKey(key, group, control, alt, shift))(*)(KeybindingsManager*, cocos2d::enumKeyCodes, GJKeyGroup, bool, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e5290, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key, group, control, alt, shift);
}

auto KeybindingsManager::commandForKeyMods(cocos2d::enumKeyCodes key, GJKeyGroup group) -> decltype(commandForKeyMods(key, group)) {
	using FunctionType = decltype(commandForKeyMods(key, group))(*)(KeybindingsManager*, cocos2d::enumKeyCodes, GJKeyGroup);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e52b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key, group);
}

auto KeybindingsManager::commandForKeyNoMods(cocos2d::enumKeyCodes key, GJKeyGroup group) -> decltype(commandForKeyNoMods(key, group)) {
	using FunctionType = decltype(commandForKeyNoMods(key, group))(*)(KeybindingsManager*, cocos2d::enumKeyCodes, GJKeyGroup);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e52a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key, group);
}

auto KeybindingsManager::commandToKeyForGroup(GJKeyGroup group) -> decltype(commandToKeyForGroup(group)) {
	using FunctionType = decltype(commandToKeyForGroup(group))(*)(KeybindingsManager*, GJKeyGroup);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e54f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, group);
}

auto KeybindingsManager::dataLoaded(DS_Dictionary* dict) -> decltype(dataLoaded(dict)) {
	using FunctionType = decltype(dataLoaded(dict))(*)(KeybindingsManager*, DS_Dictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e5780, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dict);
}

auto KeybindingsManager::encodeDataTo(DS_Dictionary* dict) -> decltype(encodeDataTo(dict)) {
	using FunctionType = decltype(encodeDataTo(dict))(*)(KeybindingsManager*, DS_Dictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e5740, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dict);
}

auto KeybindingsManager::firstSetup() -> decltype(firstSetup()) {
	using FunctionType = decltype(firstSetup())(*)(KeybindingsManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e56b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto KeybindingsManager::groupForCommand(GJKeyCommand command) -> decltype(groupForCommand(command)) {
	using FunctionType = decltype(groupForCommand(command))(*)(KeybindingsManager*, GJKeyCommand);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e5310, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, command);
}

auto KeybindingsManager::keyForCommand(GJKeyCommand command) -> decltype(keyForCommand(command)) {
	using FunctionType = decltype(keyForCommand(command))(*)(KeybindingsManager*, GJKeyCommand);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e5300, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, command);
}

auto KeybindingsManager::keyToCommandForGroup(GJKeyGroup group) -> decltype(keyToCommandForGroup(group)) {
	using FunctionType = decltype(keyToCommandForGroup(group))(*)(KeybindingsManager*, GJKeyGroup);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e5330, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, group);
}
