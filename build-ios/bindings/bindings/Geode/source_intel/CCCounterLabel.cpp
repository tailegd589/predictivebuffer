
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/CCCounterLabel.hpp>
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

auto CCCounterLabel::create(int count, char const* font, FormatterType type) -> decltype(create(count, font, type)) {
	using FunctionType = decltype(create(count, font, type))(*)(int, char const*, FormatterType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5115e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(count, font, type);
}

auto CCCounterLabel::calculateStepSize(int steps) -> decltype(calculateStepSize(steps)) {
	using FunctionType = decltype(calculateStepSize(steps))(*)(CCCounterLabel*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x511910, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, steps);
}

auto CCCounterLabel::disableCounter() -> decltype(disableCounter()) {
	using FunctionType = decltype(disableCounter())(*)(CCCounterLabel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x511860, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CCCounterLabel::enableCounter() -> decltype(enableCounter()) {
	using FunctionType = decltype(enableCounter())(*)(CCCounterLabel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5117a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CCCounterLabel::fastUpdateCounter() -> decltype(fastUpdateCounter()) {
	using FunctionType = decltype(fastUpdateCounter())(*)(CCCounterLabel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x511780, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CCCounterLabel::getTargetCount() -> decltype(getTargetCount()) {
	using FunctionType = decltype(getTargetCount())(*)(CCCounterLabel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x511960, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CCCounterLabel::init(int count, char const* font, FormatterType type) -> decltype(init(count, font, type)) {
	using FunctionType = decltype(init(count, font, type))(*)(CCCounterLabel*, int, char const*, FormatterType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x511700, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, count, font, type);
}

auto CCCounterLabel::setTargetCount(int count) -> decltype(setTargetCount(count)) {
	using FunctionType = decltype(setTargetCount(count))(*)(CCCounterLabel*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x511890, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, count);
}

auto CCCounterLabel::updateCounter(float dt) -> decltype(updateCounter(dt)) {
	using FunctionType = decltype(updateCounter(dt))(*)(CCCounterLabel*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5117e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt);
}

auto CCCounterLabel::updateString() -> decltype(updateString()) {
	using FunctionType = decltype(updateString())(*)(CCCounterLabel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x511970, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
