
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/AnimatedShopKeeper.hpp>
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

auto AnimatedShopKeeper::create(ShopType type) -> decltype(create(type)) {
	using FunctionType = decltype(create(type))(*)(ShopType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x324770, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(type);
}

auto AnimatedShopKeeper::animationFinished(char const* key) -> decltype(animationFinished(key)) {
	auto self = addresser::thunkAdjust(Resolve<char const*>::func(&AnimatedShopKeeper::animationFinished), this);
	using FunctionType = decltype(animationFinished(key))(*)(AnimatedShopKeeper*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x328770, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, key);
}

auto AnimatedShopKeeper::init(ShopType type) -> decltype(init(type)) {
	using FunctionType = decltype(init(type))(*)(AnimatedShopKeeper*, ShopType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3286c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type);
}

auto AnimatedShopKeeper::playReactAnimation() -> decltype(playReactAnimation()) {
	using FunctionType = decltype(playReactAnimation())(*)(AnimatedShopKeeper*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x327410, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto AnimatedShopKeeper::startAnimating() -> decltype(startAnimating()) {
	using FunctionType = decltype(startAnimating())(*)(AnimatedShopKeeper*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3248e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
