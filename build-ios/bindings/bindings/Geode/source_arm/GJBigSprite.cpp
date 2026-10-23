
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GJBigSprite.hpp>
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

auto GJBigSprite::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x20bf60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto GJBigSprite::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJBigSprite::init), this);
	using FunctionType = decltype(init())(*)(GJBigSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x20d524, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJBigSprite::finishedLoadingSpriteAsync(cocos2d::CCObject* obj) -> decltype(finishedLoadingSpriteAsync(obj)) {
	using FunctionType = decltype(finishedLoadingSpriteAsync(obj))(*)(GJBigSprite*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x20d9c4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, obj);
}

auto GJBigSprite::loadSpriteAsync(gd::string filename, int index) -> decltype(loadSpriteAsync(filename, index)) {
	using FunctionType = decltype(loadSpriteAsync(filename, index))(*)(GJBigSprite*, gd::string, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x20d934, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, filename, index);
}

auto GJBigSprite::unloadAll() -> decltype(unloadAll()) {
	using FunctionType = decltype(unloadAll())(*)(GJBigSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x20c9d4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJBigSprite::unloadSprite(gd::string filename, int index) -> decltype(unloadSprite(filename, index)) {
	using FunctionType = decltype(unloadSprite(filename, index))(*)(GJBigSprite*, gd::string, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x20d8cc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, filename, index);
}

auto GJBigSprite::updateSpriteVisibility() -> decltype(updateSpriteVisibility()) {
	using FunctionType = decltype(updateSpriteVisibility())(*)(GJBigSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x20bff0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
