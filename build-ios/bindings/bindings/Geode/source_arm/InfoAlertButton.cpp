
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/InfoAlertButton.hpp>
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

auto InfoAlertButton::create(gd::string title, gd::string desc, float spriteScale) -> decltype(create(title, desc, spriteScale)) {
	using FunctionType = decltype(create(title, desc, spriteScale))(*)(gd::string, gd::string, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c3724, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(title, desc, spriteScale);
}

auto InfoAlertButton::activate() -> decltype(activate()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&InfoAlertButton::activate), this);
	using FunctionType = decltype(activate())(*)(InfoAlertButton*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c39b4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto InfoAlertButton::init(gd::string title, gd::string desc, float spriteScale) -> decltype(init(title, desc, spriteScale)) {
	using FunctionType = decltype(init(title, desc, spriteScale))(*)(InfoAlertButton*, gd::string, gd::string, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c3910, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, title, desc, spriteScale);
}
