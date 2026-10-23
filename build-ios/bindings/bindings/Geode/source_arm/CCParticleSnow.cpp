
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCParticleSnow.hpp>
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

auto cocos2d::CCParticleSnow::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ec4e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCParticleSnow::createWithTotalParticles(unsigned int numberOfParticles) -> decltype(createWithTotalParticles(numberOfParticles)) {
	using FunctionType = decltype(createWithTotalParticles(numberOfParticles))(*)(unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ec570, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(numberOfParticles);
}

auto cocos2d::CCParticleSnow::initWithTotalParticles(unsigned int numberOfParticles) -> decltype(initWithTotalParticles(numberOfParticles)) {
	auto self = addresser::thunkAdjust(Resolve<unsigned int>::func(&cocos2d::CCParticleSnow::initWithTotalParticles), this);
	using FunctionType = decltype(initWithTotalParticles(numberOfParticles))(*)(cocos2d::CCParticleSnow*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ec604, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, numberOfParticles);
}
