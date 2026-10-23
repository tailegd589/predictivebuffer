
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/SpriteDescription.hpp>
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

SpriteDescription::~SpriteDescription() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(SpriteDescription*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x56d1f0, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) SpriteDescription(geode::CutoffConstructor, sizeof(SpriteDescription));
		geode::DestructorLock::addLock(this);
	}
}

auto SpriteDescription::createDescription(DS_Dictionary* dict) -> decltype(createDescription(dict)) {
	using FunctionType = decltype(createDescription(dict))(*)(DS_Dictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x56c9f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(dict);
}

auto SpriteDescription::createDescription(cocos2d::CCDictionary* dict) -> decltype(createDescription(dict)) {
	using FunctionType = decltype(createDescription(dict))(*)(cocos2d::CCDictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x56c280, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(dict);
}

auto SpriteDescription::initDescription(DS_Dictionary* dict) -> decltype(initDescription(dict)) {
	using FunctionType = decltype(initDescription(dict))(*)(SpriteDescription*, DS_Dictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x56cbb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dict);
}

auto SpriteDescription::initDescription(cocos2d::CCDictionary* dict) -> decltype(initDescription(dict)) {
	using FunctionType = decltype(initDescription(dict))(*)(SpriteDescription*, cocos2d::CCDictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x56ce30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dict);
}
