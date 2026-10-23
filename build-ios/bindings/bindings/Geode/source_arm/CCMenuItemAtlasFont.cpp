
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCMenuItemAtlasFont.hpp>
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

auto cocos2d::CCMenuItemAtlasFont::create(char const* p0, char const* p1, int p2, int p3, char p4) -> decltype(create(p0, p1, p2, p3, p4)) {
	using FunctionType = decltype(create(p0, p1, p2, p3, p4))(*)(char const*, char const*, int, int, char);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x340f10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3, p4);
}

auto cocos2d::CCMenuItemAtlasFont::create(char const* p0, char const* p1, int p2, int p3, char p4, cocos2d::CCObject* p5, cocos2d::SEL_MenuHandler p6) -> decltype(create(p0, p1, p2, p3, p4, p5, p6)) {
	using FunctionType = decltype(create(p0, p1, p2, p3, p4, p5, p6))(*)(char const*, char const*, int, int, char, cocos2d::CCObject*, cocos2d::SEL_MenuHandler);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x340fd8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3, p4, p5, p6);
}

auto cocos2d::CCMenuItemAtlasFont::initWithString(char const* p0, char const* p1, int p2, int p3, char p4, cocos2d::CCObject* p5, cocos2d::SEL_MenuHandler p6) -> decltype(initWithString(p0, p1, p2, p3, p4, p5, p6)) {
	using FunctionType = decltype(initWithString(p0, p1, p2, p3, p4, p5, p6))(*)(cocos2d::CCMenuItemAtlasFont*, char const*, char const*, int, int, char, cocos2d::CCObject*, cocos2d::SEL_MenuHandler);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3410bc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5, p6);
}
