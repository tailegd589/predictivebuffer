
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCBMFontConfiguration.hpp>
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

cocos2d::CCBMFontConfiguration::CCBMFontConfiguration() : cocos2d::CCBMFontConfiguration(geode::CutoffConstructor, sizeof(cocos2d::CCBMFontConfiguration)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCBMFontConfiguration::~CCBMFontConfiguration();

	using FunctionType = void(*)(cocos2d::CCBMFontConfiguration*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5d5c70, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCBMFontConfiguration::~CCBMFontConfiguration() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCBMFontConfiguration*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x5d5cc0, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCBMFontConfiguration(geode::CutoffConstructor, sizeof(cocos2d::CCBMFontConfiguration));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCBMFontConfiguration::create(char const* p0) -> decltype(create(p0)) {
	using FunctionType = decltype(create(p0))(*)(char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5d4e70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::CCBMFontConfiguration::description() -> decltype(description()) {
	using FunctionType = decltype(description())(*)(cocos2d::CCBMFontConfiguration*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5d6020, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCBMFontConfiguration::initWithFNTfile(char const* p0) -> decltype(initWithFNTfile(p0)) {
	using FunctionType = decltype(initWithFNTfile(p0))(*)(cocos2d::CCBMFontConfiguration*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5d4f90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCBMFontConfiguration::parseCharacterDefinition(gd::string p0, cocos2d::_BMFontDef* p1) -> decltype(parseCharacterDefinition(p0, p1)) {
	using FunctionType = decltype(parseCharacterDefinition(p0, p1))(*)(cocos2d::CCBMFontConfiguration*, gd::string, cocos2d::_BMFontDef*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5d6bd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCBMFontConfiguration::parseCommonArguments(gd::string p0) -> decltype(parseCommonArguments(p0)) {
	using FunctionType = decltype(parseCommonArguments(p0))(*)(cocos2d::CCBMFontConfiguration*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5d6270, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCBMFontConfiguration::parseConfigFile(char const* p0) -> decltype(parseConfigFile(p0)) {
	using FunctionType = decltype(parseConfigFile(p0))(*)(cocos2d::CCBMFontConfiguration*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5d4fc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCBMFontConfiguration::parseImageFileName(gd::string p0, char const* p1) -> decltype(parseImageFileName(p0, p1)) {
	using FunctionType = decltype(parseImageFileName(p0, p1))(*)(cocos2d::CCBMFontConfiguration*, gd::string, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5d6960, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCBMFontConfiguration::parseInfoArguments(gd::string p0) -> decltype(parseInfoArguments(p0)) {
	using FunctionType = decltype(parseInfoArguments(p0))(*)(cocos2d::CCBMFontConfiguration*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5d6080, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCBMFontConfiguration::parseKerningEntry(gd::string p0) -> decltype(parseKerningEntry(p0)) {
	using FunctionType = decltype(parseKerningEntry(p0))(*)(cocos2d::CCBMFontConfiguration*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5d7ac0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCBMFontConfiguration::purgeFontDefDictionary() -> decltype(purgeFontDefDictionary()) {
	using FunctionType = decltype(purgeFontDefDictionary())(*)(cocos2d::CCBMFontConfiguration*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5d5d50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCBMFontConfiguration::purgeKerningDictionary() -> decltype(purgeKerningDictionary()) {
	using FunctionType = decltype(purgeKerningDictionary())(*)(cocos2d::CCBMFontConfiguration*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5d5eb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
