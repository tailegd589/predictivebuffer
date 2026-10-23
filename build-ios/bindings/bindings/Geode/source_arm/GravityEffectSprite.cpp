
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GravityEffectSprite.hpp>
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

auto GravityEffectSprite::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x9b920, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto GravityEffectSprite::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GravityEffectSprite::init), this);
	using FunctionType = decltype(init())(*)(GravityEffectSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xac4b8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GravityEffectSprite::draw() -> decltype(draw()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GravityEffectSprite::draw), this);
	using FunctionType = decltype(draw())(*)(GravityEffectSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xac6bc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GravityEffectSprite::updateSpritesColor(cocos2d::ccColor3B color) -> decltype(updateSpritesColor(color)) {
	using FunctionType = decltype(updateSpritesColor(color))(*)(GravityEffectSprite*, cocos2d::ccColor3B);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xa6ddc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, color);
}
