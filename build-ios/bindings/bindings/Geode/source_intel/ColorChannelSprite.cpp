
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/ColorChannelSprite.hpp>
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

auto ColorChannelSprite::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2d8ba0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto ColorChannelSprite::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&ColorChannelSprite::init), this);
	using FunctionType = decltype(init())(*)(ColorChannelSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2d8c40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto ColorChannelSprite::updateBlending(bool enabled) -> decltype(updateBlending(enabled)) {
	using FunctionType = decltype(updateBlending(enabled))(*)(ColorChannelSprite*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2d8f70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, enabled);
}

auto ColorChannelSprite::updateCopyLabel(int channelID, bool copyColorLoop) -> decltype(updateCopyLabel(channelID, copyColorLoop)) {
	using FunctionType = decltype(updateCopyLabel(channelID, copyColorLoop))(*)(ColorChannelSprite*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2d8c60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, channelID, copyColorLoop);
}

auto ColorChannelSprite::updateOpacity(float alpha) -> decltype(updateOpacity(alpha)) {
	using FunctionType = decltype(updateOpacity(alpha))(*)(ColorChannelSprite*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2d8e20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, alpha);
}

auto ColorChannelSprite::updateValues(ColorAction* action) -> decltype(updateValues(action)) {
	using FunctionType = decltype(updateValues(action))(*)(ColorChannelSprite*, ColorAction*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2d9080, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, action);
}
