
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/TextStyleSection.hpp>
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

auto TextStyleSection::create(int start, int end, TextStyleType type) -> decltype(create(start, end, type)) {
	using FunctionType = decltype(create(start, end, type))(*)(int, int, TextStyleType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3eebc4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(start, end, type);
}

auto TextStyleSection::createColoredSection(cocos2d::ccColor3B color, int start, int end) -> decltype(createColoredSection(color, start, end)) {
	using FunctionType = decltype(createColoredSection(color, start, end))(*)(cocos2d::ccColor3B, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ee888, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(color, start, end);
}

auto TextStyleSection::createDelaySection(int start, float delay) -> decltype(createDelaySection(start, delay)) {
	using FunctionType = decltype(createDelaySection(start, delay))(*)(int, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3eea18, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(start, delay);
}

auto TextStyleSection::createInstantSection(int start, int end, float duration) -> decltype(createInstantSection(start, end, duration)) {
	using FunctionType = decltype(createInstantSection(start, end, duration))(*)(int, int, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ee90c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(start, end, duration);
}

auto TextStyleSection::createShakeSection(int start, int end, int intensity, int perSecond) -> decltype(createShakeSection(start, end, intensity, perSecond)) {
	using FunctionType = decltype(createShakeSection(start, end, intensity, perSecond))(*)(int, int, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ee990, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(start, end, intensity, perSecond);
}

auto TextStyleSection::init(int start, int end, TextStyleType type) -> decltype(init(start, end, type)) {
	using FunctionType = decltype(init(start, end, type))(*)(TextStyleSection*, int, int, TextStyleType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3eec38, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, start, end, type);
}
