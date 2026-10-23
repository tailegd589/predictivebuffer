
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/ButtonPage.hpp>
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

auto ButtonPage::create(cocos2d::CCArray* objects, cocos2d::CCPoint position, int rows, float spacing) -> decltype(create(objects, position, rows, spacing)) {
	using FunctionType = decltype(create(objects, position, rows, spacing))(*)(cocos2d::CCArray*, cocos2d::CCPoint, int, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50cf90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(objects, position, rows, spacing);
}

auto ButtonPage::init(cocos2d::CCArray* objects, cocos2d::CCPoint position, int rows, float spacing) -> decltype(init(objects, position, rows, spacing)) {
	using FunctionType = decltype(init(objects, position, rows, spacing))(*)(ButtonPage*, cocos2d::CCArray*, cocos2d::CCPoint, int, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50d13c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, objects, position, rows, spacing);
}
