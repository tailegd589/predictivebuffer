
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCLabelAtlas.hpp>
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

auto cocos2d::CCLabelAtlas::create(char const* p0, char const* p1) -> decltype(create(p0, p1)) {
	using FunctionType = decltype(create(p0, p1))(*)(char const*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6a0f40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCLabelAtlas::create(char const* p0, char const* p1, unsigned int p2, unsigned int p3, unsigned int p4) -> decltype(create(p0, p1, p2, p3, p4)) {
	using FunctionType = decltype(create(p0, p1, p2, p3, p4))(*)(char const*, char const*, unsigned int, unsigned int, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6a0d10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3, p4);
}

auto cocos2d::CCLabelAtlas::updateAtlasValues() -> decltype(updateAtlasValues()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLabelAtlas::updateAtlasValues), this);
	using FunctionType = decltype(updateAtlasValues())(*)(cocos2d::CCLabelAtlas*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6a14c4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLabelAtlas::setString(char const* p0) -> decltype(setString(p0)) {
	auto self = addresser::thunkAdjust(Resolve<char const*>::func(&cocos2d::CCLabelAtlas::setString), this);
	using FunctionType = decltype(setString(p0))(*)(cocos2d::CCLabelAtlas*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6a1714, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLabelAtlas::getString() -> decltype(getString()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLabelAtlas::getString), this);
	using FunctionType = decltype(getString())(*)(cocos2d::CCLabelAtlas*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6a17ec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLabelAtlas::initWithString(char const* p0, char const* p1) -> decltype(initWithString(p0, p1)) {
	using FunctionType = decltype(initWithString(p0, p1))(*)(cocos2d::CCLabelAtlas*, char const*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6a0fd4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCLabelAtlas::initWithString(char const* p0, char const* p1, unsigned int p2, unsigned int p3, unsigned int p4) -> decltype(initWithString(p0, p1, p2, p3, p4)) {
	using FunctionType = decltype(initWithString(p0, p1, p2, p3, p4))(*)(cocos2d::CCLabelAtlas*, char const*, char const*, unsigned int, unsigned int, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6a0e24, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4);
}

auto cocos2d::CCLabelAtlas::initWithString(char const* p0, cocos2d::CCTexture2D* p1, unsigned int p2, unsigned int p3, unsigned int p4) -> decltype(initWithString(p0, p1, p2, p3, p4)) {
	using FunctionType = decltype(initWithString(p0, p1, p2, p3, p4))(*)(cocos2d::CCLabelAtlas*, char const*, cocos2d::CCTexture2D*, unsigned int, unsigned int, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6a0ebc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4);
}
