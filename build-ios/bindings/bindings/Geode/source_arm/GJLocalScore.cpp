
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GJLocalScore.hpp>
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

auto GJLocalScore::create(int points, int type) -> decltype(create(points, type)) {
	using FunctionType = decltype(create(points, type))(*)(int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4af3f4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(points, type);
}

auto GJLocalScore::init(int points, int type) -> decltype(init(points, type)) {
	using FunctionType = decltype(init(points, type))(*)(GJLocalScore*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4af464, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, points, type);
}
