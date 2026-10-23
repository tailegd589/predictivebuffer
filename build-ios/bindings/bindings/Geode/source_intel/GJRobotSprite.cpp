
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GJRobotSprite.hpp>
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

auto GJRobotSprite::create(int frame) -> decltype(create(frame)) {
	using FunctionType = decltype(create(frame))(*)(int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5dbc50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(frame);
}

auto GJRobotSprite::setOpacity(unsigned char opacity) -> decltype(setOpacity(opacity)) {
	auto self = addresser::thunkAdjust(Resolve<unsigned char>::func(&GJRobotSprite::setOpacity), this);
	using FunctionType = decltype(setOpacity(opacity))(*)(GJRobotSprite*, unsigned char);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5dd010, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, opacity);
}

auto GJRobotSprite::hideSecondary() -> decltype(hideSecondary()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJRobotSprite::hideSecondary), this);
	using FunctionType = decltype(hideSecondary())(*)(GJRobotSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5dd120, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJRobotSprite::hideGlow() -> decltype(hideGlow()) {
	using FunctionType = decltype(hideGlow())(*)(GJRobotSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5dcc20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJRobotSprite::init(int frame) -> decltype(init(frame)) {
	using FunctionType = decltype(init(frame))(*)(GJRobotSprite*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5dbd90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, frame);
}

auto GJRobotSprite::init(int frame, gd::string animName) -> decltype(init(frame, animName)) {
	using FunctionType = decltype(init(frame, animName))(*)(GJRobotSprite*, int, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5dbe00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, frame, animName);
}

auto GJRobotSprite::showGlow() -> decltype(showGlow()) {
	using FunctionType = decltype(showGlow())(*)(GJRobotSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5dcc00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJRobotSprite::updateColor01(cocos2d::ccColor3B color) -> decltype(updateColor01(color)) {
	using FunctionType = decltype(updateColor01(color))(*)(GJRobotSprite*, cocos2d::ccColor3B);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5dcc40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, color);
}

auto GJRobotSprite::updateColor02(cocos2d::ccColor3B color) -> decltype(updateColor02(color)) {
	using FunctionType = decltype(updateColor02(color))(*)(GJRobotSprite*, cocos2d::ccColor3B);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5dcf70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, color);
}

auto GJRobotSprite::updateColors() -> decltype(updateColors()) {
	using FunctionType = decltype(updateColors())(*)(GJRobotSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5dcc60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJRobotSprite::updateFrame(int frame) -> decltype(updateFrame(frame)) {
	using FunctionType = decltype(updateFrame(frame))(*)(GJRobotSprite*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5dc3a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, frame);
}

auto GJRobotSprite::updateGlowColor(cocos2d::ccColor3B color, bool simple) -> decltype(updateGlowColor(color, simple)) {
	using FunctionType = decltype(updateGlowColor(color, simple))(*)(GJRobotSprite*, cocos2d::ccColor3B, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5dcf90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, color, simple);
}
