
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/BonusDropdown.hpp>
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

auto BonusDropdown::create(gd::string text, int price) -> decltype(create(text, price)) {
	using FunctionType = decltype(create(text, price))(*)(gd::string, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4933d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(text, price);
}

auto BonusDropdown::init(gd::string text, int price) -> decltype(init(text, price)) {
	using FunctionType = decltype(init(text, price))(*)(BonusDropdown*, gd::string, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4934b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, text, price);
}

auto BonusDropdown::show() -> decltype(show()) {
	using FunctionType = decltype(show())(*)(BonusDropdown*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x493750, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
