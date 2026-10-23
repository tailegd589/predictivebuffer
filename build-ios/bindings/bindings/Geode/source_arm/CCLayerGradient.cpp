
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCLayerGradient.hpp>
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

auto cocos2d::CCLayerGradient::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x415124, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCLayerGradient::create(cocos2d::ccColor4B const& p0, cocos2d::ccColor4B const& p1) -> decltype(create(p0, p1)) {
	using FunctionType = decltype(create(p0, p1))(*)(cocos2d::ccColor4B const&, cocos2d::ccColor4B const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x414dcc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCLayerGradient::create(cocos2d::ccColor4B const& a1, cocos2d::ccColor4B const& a2, cocos2d::CCPoint const& a3) -> decltype(create(a1, a2, a3)) {
	using FunctionType = decltype(create(a1, a2, a3))(*)(cocos2d::ccColor4B const&, cocos2d::ccColor4B const&, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x414f74, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(a1, a2, a3);
}

auto cocos2d::CCLayerGradient::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLayerGradient::init), this);
	using FunctionType = decltype(init())(*)(cocos2d::CCLayerGradient*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4152b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLayerGradient::visit() -> decltype(visit()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLayerGradient::visit), this);
	using FunctionType = decltype(visit())(*)(cocos2d::CCLayerGradient*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x415730, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLayerGradient::updateColor() -> decltype(updateColor()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLayerGradient::updateColor), this);
	using FunctionType = decltype(updateColor())(*)(cocos2d::CCLayerGradient*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4153e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLayerGradient::initWithColor(cocos2d::ccColor4B const& p0, cocos2d::ccColor4B const& p1) -> decltype(initWithColor(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::ccColor4B const&, cocos2d::ccColor4B const&>::func(&cocos2d::CCLayerGradient::initWithColor), this);
	using FunctionType = decltype(initWithColor(p0, p1))(*)(cocos2d::CCLayerGradient*, cocos2d::ccColor4B const&, cocos2d::ccColor4B const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4152e8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::CCLayerGradient::initWithColor(cocos2d::ccColor4B const& p0, cocos2d::ccColor4B const& p1, cocos2d::CCPoint const& p2) -> decltype(initWithColor(p0, p1, p2)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::ccColor4B const&, cocos2d::ccColor4B const&, cocos2d::CCPoint const&>::func(&cocos2d::CCLayerGradient::initWithColor), this);
	using FunctionType = decltype(initWithColor(p0, p1, p2))(*)(cocos2d::CCLayerGradient*, cocos2d::ccColor4B const&, cocos2d::ccColor4B const&, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x415348, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2);
}

auto cocos2d::CCLayerGradient::getStartColor() -> decltype(getStartColor()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLayerGradient::getStartColor), this);
	using FunctionType = decltype(getStartColor())(*)(cocos2d::CCLayerGradient*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x415600, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLayerGradient::setStartColor(cocos2d::ccColor3B const& p0) -> decltype(setStartColor(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::ccColor3B const&>::func(&cocos2d::CCLayerGradient::setStartColor), this);
	using FunctionType = decltype(setStartColor(p0))(*)(cocos2d::CCLayerGradient*, cocos2d::ccColor3B const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x415608, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLayerGradient::getEndColor() -> decltype(getEndColor()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLayerGradient::getEndColor), this);
	using FunctionType = decltype(getEndColor())(*)(cocos2d::CCLayerGradient*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x415634, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLayerGradient::setEndColor(cocos2d::ccColor3B const& p0) -> decltype(setEndColor(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::ccColor3B const&>::func(&cocos2d::CCLayerGradient::setEndColor), this);
	using FunctionType = decltype(setEndColor(p0))(*)(cocos2d::CCLayerGradient*, cocos2d::ccColor3B const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x415614, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLayerGradient::getStartOpacity() -> decltype(getStartOpacity()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLayerGradient::getStartOpacity), this);
	using FunctionType = decltype(getStartOpacity())(*)(cocos2d::CCLayerGradient*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x41564c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLayerGradient::setStartOpacity(unsigned char p0) -> decltype(setStartOpacity(p0)) {
	auto self = addresser::thunkAdjust(Resolve<unsigned char>::func(&cocos2d::CCLayerGradient::setStartOpacity), this);
	using FunctionType = decltype(setStartOpacity(p0))(*)(cocos2d::CCLayerGradient*, unsigned char);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x41563c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLayerGradient::getEndOpacity() -> decltype(getEndOpacity()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLayerGradient::getEndOpacity), this);
	using FunctionType = decltype(getEndOpacity())(*)(cocos2d::CCLayerGradient*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x415664, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLayerGradient::setEndOpacity(unsigned char p0) -> decltype(setEndOpacity(p0)) {
	auto self = addresser::thunkAdjust(Resolve<unsigned char>::func(&cocos2d::CCLayerGradient::setEndOpacity), this);
	using FunctionType = decltype(setEndOpacity(p0))(*)(cocos2d::CCLayerGradient*, unsigned char);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x415654, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLayerGradient::getVector() -> decltype(getVector()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLayerGradient::getVector), this);
	using FunctionType = decltype(getVector())(*)(cocos2d::CCLayerGradient*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x41569c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLayerGradient::setVector(cocos2d::CCPoint const& p0) -> decltype(setVector(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCPoint const&>::func(&cocos2d::CCLayerGradient::setVector), this);
	using FunctionType = decltype(setVector(p0))(*)(cocos2d::CCLayerGradient*, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x41566c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLayerGradient::setCompressedInterpolation(bool p0) -> decltype(setCompressedInterpolation(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::CCLayerGradient::setCompressedInterpolation), this);
	using FunctionType = decltype(setCompressedInterpolation(p0))(*)(cocos2d::CCLayerGradient*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x415720, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLayerGradient::isCompressedInterpolation() -> decltype(isCompressedInterpolation()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLayerGradient::isCompressedInterpolation), this);
	using FunctionType = decltype(isCompressedInterpolation())(*)(cocos2d::CCLayerGradient*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x415718, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLayerGradient::setValues(cocos2d::ccColor3B const& p0, unsigned char p1, cocos2d::ccColor3B const& p2, unsigned char p3, cocos2d::CCPoint const& p4) -> decltype(setValues(p0, p1, p2, p3, p4)) {
	using FunctionType = decltype(setValues(p0, p1, p2, p3, p4))(*)(cocos2d::CCLayerGradient*, cocos2d::ccColor3B const&, unsigned char, cocos2d::ccColor3B const&, unsigned char, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4156a4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4);
}
