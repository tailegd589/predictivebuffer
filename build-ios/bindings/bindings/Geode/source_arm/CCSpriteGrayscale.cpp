
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/CCSpriteGrayscale.hpp>
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

auto CCSpriteGrayscale::create(gd::string const& file) -> decltype(create(file)) {
	using FunctionType = decltype(create(file))(*)(gd::string const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51a6f4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(file);
}

auto CCSpriteGrayscale::create(gd::string const& file, cocos2d::CCRect const& rect) -> decltype(create(file, rect)) {
	using FunctionType = decltype(create(file, rect))(*)(gd::string const&, cocos2d::CCRect const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51a7c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(file, rect);
}

auto CCSpriteGrayscale::createWithSpriteFrame(cocos2d::CCSpriteFrame* frame) -> decltype(createWithSpriteFrame(frame)) {
	using FunctionType = decltype(createWithSpriteFrame(frame))(*)(cocos2d::CCSpriteFrame*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51aaac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(frame);
}

auto CCSpriteGrayscale::createWithSpriteFrameName(gd::string const& frameName) -> decltype(createWithSpriteFrameName(frameName)) {
	using FunctionType = decltype(createWithSpriteFrameName(frameName))(*)(gd::string const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51aba8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(frameName);
}

auto CCSpriteGrayscale::createWithTexture(cocos2d::CCTexture2D* texture) -> decltype(createWithTexture(texture)) {
	using FunctionType = decltype(createWithTexture(texture))(*)(cocos2d::CCTexture2D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51a8a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(texture);
}

auto CCSpriteGrayscale::createWithTexture(cocos2d::CCTexture2D* texture, cocos2d::CCRect const& rect, bool rotated) -> decltype(createWithTexture(texture, rect, rotated)) {
	using FunctionType = decltype(createWithTexture(texture, rect, rotated))(*)(cocos2d::CCTexture2D*, cocos2d::CCRect const&, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51a9b8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(texture, rect, rotated);
}

auto CCSpriteGrayscale::getShaderName() -> decltype(getShaderName()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CCSpriteGrayscale::getShaderName), this);
	using FunctionType = decltype(getShaderName())(*)(CCSpriteGrayscale*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51a6d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CCSpriteGrayscale::shaderBody() -> decltype(shaderBody()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CCSpriteGrayscale::shaderBody), this);
	using FunctionType = decltype(shaderBody())(*)(CCSpriteGrayscale*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51a590, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}
