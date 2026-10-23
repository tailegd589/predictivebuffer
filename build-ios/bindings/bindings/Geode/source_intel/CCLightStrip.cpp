
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/CCLightStrip.hpp>
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

auto CCLightStrip::create(float width, float toWidth, float toHeight, float duration, float delay) -> decltype(create(width, toWidth, toHeight, duration, delay)) {
	using FunctionType = decltype(create(width, toWidth, toHeight, duration, delay))(*)(float, float, float, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x504040, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(width, toWidth, toHeight, duration, delay);
}

auto CCLightStrip::draw() -> decltype(draw()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CCLightStrip::draw), this);
	using FunctionType = decltype(draw())(*)(CCLightStrip*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x504650, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CCLightStrip::updateTweenAction(float value, char const* keyword) -> decltype(updateTweenAction(value, keyword)) {
	auto self = addresser::thunkAdjust(Resolve<float, char const*>::func(&CCLightStrip::updateTweenAction), this);
	using FunctionType = decltype(updateTweenAction(value, keyword))(*)(CCLightStrip*, float, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5047e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, value, keyword);
}

auto CCLightStrip::init(float width, float toWidth, float toHeight, float duration, float delay) -> decltype(init(width, toWidth, toHeight, duration, delay)) {
	using FunctionType = decltype(init(width, toWidth, toHeight, duration, delay))(*)(CCLightStrip*, float, float, float, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x504510, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, width, toWidth, toHeight, duration, delay);
}
