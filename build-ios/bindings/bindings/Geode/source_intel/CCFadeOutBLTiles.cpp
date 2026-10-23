
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCFadeOutBLTiles.hpp>
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

auto cocos2d::CCFadeOutBLTiles::create(float p0, cocos2d::CCSize const& p1) -> decltype(create(p0, p1)) {
	using FunctionType = decltype(create(p0, p1))(*)(float, cocos2d::CCSize const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7b6770, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCFadeOutBLTiles::testFunc(cocos2d::CCSize const& p0, float p1) -> decltype(testFunc(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCSize const&, float>::func(&cocos2d::CCFadeOutBLTiles::testFunc), this);
	using FunctionType = decltype(testFunc(p0, p1))(*)(cocos2d::CCFadeOutBLTiles*, cocos2d::CCSize const&, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7b6850, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}
