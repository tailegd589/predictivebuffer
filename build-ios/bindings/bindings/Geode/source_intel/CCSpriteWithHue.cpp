
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/CCSpriteWithHue.hpp>
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

auto CCSpriteWithHue::create(gd::string const& file) -> decltype(create(file)) {
	using FunctionType = decltype(create(file))(*)(gd::string const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5efae0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(file);
}

auto CCSpriteWithHue::create(gd::string const& file, cocos2d::CCRect const& rect) -> decltype(create(file, rect)) {
	using FunctionType = decltype(create(file, rect))(*)(gd::string const&, cocos2d::CCRect const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5efba0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(file, rect);
}

auto CCSpriteWithHue::createWithSpriteFrame(cocos2d::CCSpriteFrame* frame) -> decltype(createWithSpriteFrame(frame)) {
	using FunctionType = decltype(createWithSpriteFrame(frame))(*)(cocos2d::CCSpriteFrame*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5efe40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(frame);
}

auto CCSpriteWithHue::createWithSpriteFrameName(gd::string const& frameName) -> decltype(createWithSpriteFrameName(frameName)) {
	using FunctionType = decltype(createWithSpriteFrameName(frameName))(*)(gd::string const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5eff20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(frameName);
}

auto CCSpriteWithHue::createWithTexture(cocos2d::CCTexture2D* texture) -> decltype(createWithTexture(texture)) {
	using FunctionType = decltype(createWithTexture(texture))(*)(cocos2d::CCTexture2D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5efc70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(texture);
}

auto CCSpriteWithHue::createWithTexture(cocos2d::CCTexture2D* texture, cocos2d::CCRect const& rect, bool rotated) -> decltype(createWithTexture(texture, rect, rotated)) {
	using FunctionType = decltype(createWithTexture(texture, rect, rotated))(*)(cocos2d::CCTexture2D*, cocos2d::CCRect const&, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5efd70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(texture, rect, rotated);
}

auto CCSpriteWithHue::draw() -> decltype(draw()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CCSpriteWithHue::draw), this);
	using FunctionType = decltype(draw())(*)(CCSpriteWithHue*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f08e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CCSpriteWithHue::initWithTexture(cocos2d::CCTexture2D* texture) -> decltype(initWithTexture(texture)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTexture2D*>::func(&CCSpriteWithHue::initWithTexture), this);
	using FunctionType = decltype(initWithTexture(texture))(*)(CCSpriteWithHue*, cocos2d::CCTexture2D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f01a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, texture);
}

auto CCSpriteWithHue::initWithTexture(cocos2d::CCTexture2D* texture, cocos2d::CCRect const& rect) -> decltype(initWithTexture(texture, rect)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTexture2D*, cocos2d::CCRect const&>::func(&CCSpriteWithHue::initWithTexture), this);
	using FunctionType = decltype(initWithTexture(texture, rect))(*)(CCSpriteWithHue*, cocos2d::CCTexture2D*, cocos2d::CCRect const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f0210, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, texture, rect);
}

auto CCSpriteWithHue::initWithTexture(cocos2d::CCTexture2D* texture, cocos2d::CCRect const& rect, bool rotated) -> decltype(initWithTexture(texture, rect, rotated)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTexture2D*, cocos2d::CCRect const&, bool>::func(&CCSpriteWithHue::initWithTexture), this);
	using FunctionType = decltype(initWithTexture(texture, rect, rotated))(*)(CCSpriteWithHue*, cocos2d::CCTexture2D*, cocos2d::CCRect const&, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5eff60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, texture, rect, rotated);
}

auto CCSpriteWithHue::initWithSpriteFrame(cocos2d::CCSpriteFrame* frame) -> decltype(initWithSpriteFrame(frame)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCSpriteFrame*>::func(&CCSpriteWithHue::initWithSpriteFrame), this);
	using FunctionType = decltype(initWithSpriteFrame(frame))(*)(CCSpriteWithHue*, cocos2d::CCSpriteFrame*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f0230, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, frame);
}

auto CCSpriteWithHue::getShaderName() -> decltype(getShaderName()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CCSpriteWithHue::getShaderName), this);
	using FunctionType = decltype(getShaderName())(*)(CCSpriteWithHue*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5efab0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CCSpriteWithHue::shaderBody() -> decltype(shaderBody()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CCSpriteWithHue::shaderBody), this);
	using FunctionType = decltype(shaderBody())(*)(CCSpriteWithHue*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f0370, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CCSpriteWithHue::updateColor() -> decltype(updateColor()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CCSpriteWithHue::updateColor), this);
	using FunctionType = decltype(updateColor())(*)(CCSpriteWithHue*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f0390, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CCSpriteWithHue::getAlpha() -> decltype(getAlpha()) {
	using FunctionType = decltype(getAlpha())(*)(CCSpriteWithHue*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f0810, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CCSpriteWithHue::getHue() -> decltype(getHue()) {
	using FunctionType = decltype(getHue())(*)(CCSpriteWithHue*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f0830, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CCSpriteWithHue::getUniformLocations() -> decltype(getUniformLocations()) {
	using FunctionType = decltype(getUniformLocations())(*)(CCSpriteWithHue*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f0300, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CCSpriteWithHue::initShader() -> decltype(initShader()) {
	using FunctionType = decltype(initShader())(*)(CCSpriteWithHue*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5effc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CCSpriteWithHue::setCustomLuminance(float r, float g, float b) -> decltype(setCustomLuminance(r, g, b)) {
	using FunctionType = decltype(setCustomLuminance(r, g, b))(*)(CCSpriteWithHue*, float, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f08c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, r, g, b);
}

auto CCSpriteWithHue::setEvenLuminance(float luminance) -> decltype(setEvenLuminance(luminance)) {
	using FunctionType = decltype(setEvenLuminance(luminance))(*)(CCSpriteWithHue*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f0890, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, luminance);
}

auto CCSpriteWithHue::setHue(float hue) -> decltype(setHue(hue)) {
	using FunctionType = decltype(setHue(hue))(*)(CCSpriteWithHue*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f02b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, hue);
}

auto CCSpriteWithHue::setHueDegrees(float degrees) -> decltype(setHueDegrees(degrees)) {
	using FunctionType = decltype(setHueDegrees(degrees))(*)(CCSpriteWithHue*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f0840, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, degrees);
}

auto CCSpriteWithHue::setLuminance(float luminance) -> decltype(setLuminance(luminance)) {
	using FunctionType = decltype(setLuminance(luminance))(*)(CCSpriteWithHue*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f02d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, luminance);
}

auto CCSpriteWithHue::setupDefaultSettings() -> decltype(setupDefaultSettings()) {
	using FunctionType = decltype(setupDefaultSettings())(*)(CCSpriteWithHue*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5effa0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CCSpriteWithHue::updateColorMatrix() -> decltype(updateColorMatrix()) {
	using FunctionType = decltype(updateColorMatrix())(*)(CCSpriteWithHue*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f03b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CCSpriteWithHue::updateHue(float unused) -> decltype(updateHue(unused)) {
	using FunctionType = decltype(updateHue(unused))(*)(CCSpriteWithHue*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f0280, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, unused);
}
