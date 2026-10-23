
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/PriceLabel.hpp>
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

auto PriceLabel::create(int price) -> decltype(create(price)) {
	using FunctionType = decltype(create(price))(*)(int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4bf7e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(price);
}

auto PriceLabel::init(int price) -> decltype(init(price)) {
	using FunctionType = decltype(init(price))(*)(PriceLabel*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4bf900, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, price);
}

auto PriceLabel::setColor(cocos2d::ccColor3B color) -> decltype(setColor(color)) {
	using FunctionType = decltype(setColor(color))(*)(PriceLabel*, cocos2d::ccColor3B);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4bfb40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, color);
}

auto PriceLabel::setOpacity(float opacity) -> decltype(setOpacity(opacity)) {
	using FunctionType = decltype(setOpacity(opacity))(*)(PriceLabel*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4bfb90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, opacity);
}

auto PriceLabel::setPrice(int price) -> decltype(setPrice(price)) {
	using FunctionType = decltype(setPrice(price))(*)(PriceLabel*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4bf9e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, price);
}
