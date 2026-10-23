
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/SliderThumb.hpp>
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

auto SliderThumb::create(cocos2d::CCNode* target, cocos2d::SEL_MenuHandler selector, char const* normalFrame, char const* selectedFrame) -> decltype(create(target, selector, normalFrame, selectedFrame)) {
	using FunctionType = decltype(create(target, selector, normalFrame, selectedFrame))(*)(cocos2d::CCNode*, cocos2d::SEL_MenuHandler, char const*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x294200, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(target, selector, normalFrame, selectedFrame);
}

auto SliderThumb::getValue() -> decltype(getValue()) {
	using FunctionType = decltype(getValue())(*)(SliderThumb*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2943f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SliderThumb::init(cocos2d::CCNode* target, cocos2d::SEL_MenuHandler selector, char const* normalFrame, char const* selectedFrame) -> decltype(init(target, selector, normalFrame, selectedFrame)) {
	using FunctionType = decltype(init(target, selector, normalFrame, selectedFrame))(*)(SliderThumb*, cocos2d::CCNode*, cocos2d::SEL_MenuHandler, char const*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2942f8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, target, selector, normalFrame, selectedFrame);
}

auto SliderThumb::setMaxOffset(float offset) -> decltype(setMaxOffset(offset)) {
	using FunctionType = decltype(setMaxOffset(offset))(*)(SliderThumb*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x294584, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, offset);
}

auto SliderThumb::setRotated(bool rotated) -> decltype(setRotated(rotated)) {
	using FunctionType = decltype(setRotated(rotated))(*)(SliderThumb*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x294324, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, rotated);
}

auto SliderThumb::setValue(float value) -> decltype(setValue(value)) {
	using FunctionType = decltype(setValue(value))(*)(SliderThumb*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x294474, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, value);
}
