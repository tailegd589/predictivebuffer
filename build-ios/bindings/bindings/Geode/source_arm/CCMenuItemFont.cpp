
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCMenuItemFont.hpp>
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

auto cocos2d::CCMenuItemFont::create(char const* p0) -> decltype(create(p0)) {
	using FunctionType = decltype(create(p0))(*)(char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3414d8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::CCMenuItemFont::create(char const* p0, cocos2d::CCObject* p1, cocos2d::SEL_MenuHandler p2) -> decltype(create(p0, p1, p2)) {
	using FunctionType = decltype(create(p0, p1, p2))(*)(char const*, cocos2d::CCObject*, cocos2d::SEL_MenuHandler);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3412ec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

auto cocos2d::CCMenuItemFont::fontName() -> decltype(fontName()) {
	using FunctionType = decltype(fontName())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3412d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCMenuItemFont::fontSize() -> decltype(fontSize()) {
	using FunctionType = decltype(fontSize())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x34124c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCMenuItemFont::setFontName(char const* p0) -> decltype(setFontName(p0)) {
	using FunctionType = decltype(setFontName(p0))(*)(char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x341258, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::CCMenuItemFont::setFontSize(unsigned int p0) -> decltype(setFontSize(p0)) {
	using FunctionType = decltype(setFontSize(p0))(*)(unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x341240, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::CCMenuItemFont::fontNameObj() -> decltype(fontNameObj()) {
	using FunctionType = decltype(fontNameObj())(*)(cocos2d::CCMenuItemFont*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3416e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCMenuItemFont::fontSizeObj() -> decltype(fontSizeObj()) {
	using FunctionType = decltype(fontSizeObj())(*)(cocos2d::CCMenuItemFont*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x34165c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCMenuItemFont::initWithString(char const* p0, cocos2d::CCObject* p1, cocos2d::SEL_MenuHandler p2) -> decltype(initWithString(p0, p1, p2)) {
	using FunctionType = decltype(initWithString(p0, p1, p2))(*)(cocos2d::CCMenuItemFont*, char const*, cocos2d::CCObject*, cocos2d::SEL_MenuHandler);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3413a8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto cocos2d::CCMenuItemFont::recreateLabel() -> decltype(recreateLabel()) {
	using FunctionType = decltype(recreateLabel())(*)(cocos2d::CCMenuItemFont*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x341578, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCMenuItemFont::setFontNameObj(char const* p0) -> decltype(setFontNameObj(p0)) {
	using FunctionType = decltype(setFontNameObj(p0))(*)(cocos2d::CCMenuItemFont*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x341664, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCMenuItemFont::setFontSizeObj(unsigned int p0) -> decltype(setFontSizeObj(p0)) {
	using FunctionType = decltype(setFontSizeObj(p0))(*)(cocos2d::CCMenuItemFont*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3415e8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
