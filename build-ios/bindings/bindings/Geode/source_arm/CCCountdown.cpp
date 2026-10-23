
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/CCCountdown.hpp>
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

auto CCCountdown::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cb4e4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto CCCountdown::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CCCountdown::init), this);
	using FunctionType = decltype(init())(*)(CCCountdown*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cb588, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CCCountdown::setOpacity(unsigned char opacity) -> decltype(setOpacity(opacity)) {
	auto self = addresser::thunkAdjust(Resolve<unsigned char>::func(&CCCountdown::setOpacity), this);
	using FunctionType = decltype(setOpacity(opacity))(*)(CCCountdown*, unsigned char);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cb93c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, opacity);
}

auto CCCountdown::lapFinished() -> decltype(lapFinished()) {
	using FunctionType = decltype(lapFinished())(*)(CCCountdown*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cb814, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CCCountdown::startTimerWithSeconds(float seconds, cocos2d::SEL_CallFunc selector, cocos2d::CCNode* target) -> decltype(startTimerWithSeconds(seconds, selector, target)) {
	using FunctionType = decltype(startTimerWithSeconds(seconds, selector, target))(*)(CCCountdown*, float, cocos2d::SEL_CallFunc, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cb7a8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, seconds, selector, target);
}
