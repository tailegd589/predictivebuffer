
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/PlayerFireBoostSprite.hpp>
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

auto PlayerFireBoostSprite::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x374aa4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto PlayerFireBoostSprite::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&PlayerFireBoostSprite::init), this);
	using FunctionType = decltype(init())(*)(PlayerFireBoostSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3920f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto PlayerFireBoostSprite::animateFireIn() -> decltype(animateFireIn()) {
	using FunctionType = decltype(animateFireIn())(*)(PlayerFireBoostSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38cebc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerFireBoostSprite::animateFireOut() -> decltype(animateFireOut()) {
	using FunctionType = decltype(animateFireOut())(*)(PlayerFireBoostSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38cf3c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerFireBoostSprite::loopFireAnimation() -> decltype(loopFireAnimation()) {
	using FunctionType = decltype(loopFireAnimation())(*)(PlayerFireBoostSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38cbec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
