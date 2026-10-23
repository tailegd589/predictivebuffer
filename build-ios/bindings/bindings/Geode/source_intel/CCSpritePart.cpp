
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/CCSpritePart.hpp>
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

auto CCSpritePart::create(cocos2d::CCTexture2D* texture) -> decltype(create(texture)) {
	using FunctionType = decltype(create(texture))(*)(cocos2d::CCTexture2D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3745c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(texture);
}

auto CCSpritePart::createWithSpriteFrameName(char const* frame) -> decltype(createWithSpriteFrameName(frame)) {
	using FunctionType = decltype(createWithSpriteFrameName(frame))(*)(char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x374440, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(frame);
}

auto CCSpritePart::setVisible(bool visible) -> decltype(setVisible(visible)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&CCSpritePart::setVisible), this);
	using FunctionType = decltype(setVisible(visible))(*)(CCSpritePart*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x375900, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, visible);
}

auto CCSpritePart::frameChanged(gd::string frame) -> decltype(frameChanged(frame)) {
	using FunctionType = decltype(frameChanged(frame))(*)(CCSpritePart*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3747f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, frame);
}

auto CCSpritePart::getBeingUsed() -> decltype(getBeingUsed()) {
	using FunctionType = decltype(getBeingUsed())(*)(CCSpritePart*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3758f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CCSpritePart::hideInactive() -> decltype(hideInactive()) {
	using FunctionType = decltype(hideInactive())(*)(CCSpritePart*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x374f80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CCSpritePart::markAsNotBeingUsed() -> decltype(markAsNotBeingUsed()) {
	using FunctionType = decltype(markAsNotBeingUsed())(*)(CCSpritePart*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x374f70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CCSpritePart::resetTextureRect() -> decltype(resetTextureRect()) {
	using FunctionType = decltype(resetTextureRect())(*)(CCSpritePart*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x374c80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CCSpritePart::setBeingUsed(bool beingUsed) -> decltype(setBeingUsed(beingUsed)) {
	using FunctionType = decltype(setBeingUsed(beingUsed))(*)(CCSpritePart*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x374910, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, beingUsed);
}

auto CCSpritePart::updateDisplayFrame(gd::string frame) -> decltype(updateDisplayFrame(frame)) {
	using FunctionType = decltype(updateDisplayFrame(frame))(*)(CCSpritePart*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x374ca0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, frame);
}
