
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCMenuItemImage.hpp>
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

auto cocos2d::CCMenuItemImage::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x341df4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCMenuItemImage::create(char const* p0, char const* p1) -> decltype(create(p0, p1)) {
	using FunctionType = decltype(create(p0, p1))(*)(char const*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x342168, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCMenuItemImage::create(char const* p0, char const* p1, char const* p2) -> decltype(create(p0, p1, p2)) {
	using FunctionType = decltype(create(p0, p1, p2))(*)(char const*, char const*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x342388, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

auto cocos2d::CCMenuItemImage::create(char const* p0, char const* p1, cocos2d::CCObject* p2, cocos2d::SEL_MenuHandler p3) -> decltype(create(p0, p1, p2, p3)) {
	using FunctionType = decltype(create(p0, p1, p2, p3))(*)(char const*, char const*, cocos2d::CCObject*, cocos2d::SEL_MenuHandler);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3422d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3);
}

auto cocos2d::CCMenuItemImage::create(char const* p0, char const* p1, char const* p2, cocos2d::CCObject* p3, cocos2d::SEL_MenuHandler p4) -> decltype(create(p0, p1, p2, p3, p4)) {
	using FunctionType = decltype(create(p0, p1, p2, p3, p4))(*)(char const*, char const*, char const*, cocos2d::CCObject*, cocos2d::SEL_MenuHandler);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x34220c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3, p4);
}

auto cocos2d::CCMenuItemImage::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCMenuItemImage::init), this);
	using FunctionType = decltype(init())(*)(cocos2d::CCMenuItemImage*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x341f30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCMenuItemImage::initWithNormalImage(char const* p0, char const* p1, char const* p2, cocos2d::CCObject* p3, cocos2d::SEL_MenuHandler p4) -> decltype(initWithNormalImage(p0, p1, p2, p3, p4)) {
	using FunctionType = decltype(initWithNormalImage(p0, p1, p2, p3, p4))(*)(cocos2d::CCMenuItemImage*, char const*, char const*, char const*, cocos2d::CCObject*, cocos2d::SEL_MenuHandler);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x342018, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4);
}

auto cocos2d::CCMenuItemImage::setDisabledSpriteFrame(cocos2d::CCSpriteFrame* p0) -> decltype(setDisabledSpriteFrame(p0)) {
	using FunctionType = decltype(setDisabledSpriteFrame(p0))(*)(cocos2d::CCMenuItemImage*, cocos2d::CCSpriteFrame*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x342498, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCMenuItemImage::setNormalSpriteFrame(cocos2d::CCSpriteFrame* p0) -> decltype(setNormalSpriteFrame(p0)) {
	using FunctionType = decltype(setNormalSpriteFrame(p0))(*)(cocos2d::CCMenuItemImage*, cocos2d::CCSpriteFrame*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x342430, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCMenuItemImage::setSelectedSpriteFrame(cocos2d::CCSpriteFrame* p0) -> decltype(setSelectedSpriteFrame(p0)) {
	using FunctionType = decltype(setSelectedSpriteFrame(p0))(*)(cocos2d::CCMenuItemImage*, cocos2d::CCSpriteFrame*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x342464, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
