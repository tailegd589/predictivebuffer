
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GJMapPack.hpp>
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

GJMapPack::~GJMapPack() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(GJMapPack*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x4aed00, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) GJMapPack(geode::CutoffConstructor, sizeof(GJMapPack));
		geode::DestructorLock::addLock(this);
	}
}

auto GJMapPack::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4aee64, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto GJMapPack::create(cocos2d::CCDictionary* dict) -> decltype(create(dict)) {
	using FunctionType = decltype(create(dict))(*)(cocos2d::CCDictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4859ec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(dict);
}

auto GJMapPack::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJMapPack::init), this);
	using FunctionType = decltype(init())(*)(GJMapPack*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4af280, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJMapPack::completedMaps() -> decltype(completedMaps()) {
	using FunctionType = decltype(completedMaps())(*)(GJMapPack*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4af2e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJMapPack::hasCompletedMapPack() -> decltype(hasCompletedMapPack()) {
	using FunctionType = decltype(hasCompletedMapPack())(*)(GJMapPack*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4af3a8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJMapPack::parsePackColors(gd::string textColorStr, gd::string barColorStr) -> decltype(parsePackColors(textColorStr, barColorStr)) {
	using FunctionType = decltype(parsePackColors(textColorStr, barColorStr))(*)(GJMapPack*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4af010, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, textColorStr, barColorStr);
}

auto GJMapPack::parsePackLevels(gd::string levelsStr) -> decltype(parsePackLevels(levelsStr)) {
	using FunctionType = decltype(parsePackLevels(levelsStr))(*)(GJMapPack*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4aef08, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, levelsStr);
}

auto GJMapPack::totalMaps() -> decltype(totalMaps()) {
	using FunctionType = decltype(totalMaps())(*)(GJMapPack*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4af2d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
