
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/StatsObject.hpp>
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

auto StatsObject::create(char const* key, int value) -> decltype(create(key, value)) {
	using FunctionType = decltype(create(key, value))(*)(char const*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1f909c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(key, value);
}

auto StatsObject::init(char const* key, int value) -> decltype(init(key, value)) {
	using FunctionType = decltype(init(key, value))(*)(StatsObject*, char const*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1f9124, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key, value);
}
