
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/ObjectManager.hpp>
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

auto ObjectManager::instance() -> decltype(instance()) {
	using FunctionType = decltype(instance())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69d8e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto ObjectManager::replaceAllOccurencesOfString(cocos2d::CCString* target, cocos2d::CCString* replacement, cocos2d::CCDictionary* dict) -> decltype(replaceAllOccurencesOfString(target, replacement, dict)) {
	using FunctionType = decltype(replaceAllOccurencesOfString(target, replacement, dict))(*)(cocos2d::CCString*, cocos2d::CCString*, cocos2d::CCDictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69e67c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(target, replacement, dict);
}

auto ObjectManager::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&ObjectManager::init), this);
	using FunctionType = decltype(init())(*)(ObjectManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69d9a8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto ObjectManager::animLoaded(char const* anim) -> decltype(animLoaded(anim)) {
	using FunctionType = decltype(animLoaded(anim))(*)(ObjectManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69f3c8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, anim);
}

auto ObjectManager::getDefinition(char const* definitionKey) -> decltype(getDefinition(definitionKey)) {
	using FunctionType = decltype(getDefinition(definitionKey))(*)(ObjectManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69f1c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, definitionKey);
}

auto ObjectManager::getGlobalAnimCopy(char const* anim) -> decltype(getGlobalAnimCopy(anim)) {
	using FunctionType = decltype(getGlobalAnimCopy(anim))(*)(ObjectManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69e53c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, anim);
}

auto ObjectManager::loadCopiedAnimations() -> decltype(loadCopiedAnimations()) {
	using FunctionType = decltype(loadCopiedAnimations())(*)(ObjectManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69d9f8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto ObjectManager::loadCopiedSets() -> decltype(loadCopiedSets()) {
	using FunctionType = decltype(loadCopiedSets())(*)(ObjectManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69de64, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto ObjectManager::purgeObjectManager() -> decltype(purgeObjectManager()) {
	using FunctionType = decltype(purgeObjectManager())(*)(ObjectManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69d97c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto ObjectManager::setLoaded(char const* objectName) -> decltype(setLoaded(objectName)) {
	using FunctionType = decltype(setLoaded(objectName))(*)(ObjectManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69f2c4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, objectName);
}

auto ObjectManager::setup() -> decltype(setup()) {
	using FunctionType = decltype(setup())(*)(ObjectManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69e1b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
