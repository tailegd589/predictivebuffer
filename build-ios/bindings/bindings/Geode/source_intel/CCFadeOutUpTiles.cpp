
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCFadeOutUpTiles.hpp>
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

auto cocos2d::CCFadeOutUpTiles::create(float p0, cocos2d::CCSize const& p1) -> decltype(create(p0, p1)) {
	using FunctionType = decltype(create(p0, p1))(*)(float, cocos2d::CCSize const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7b68e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCFadeOutUpTiles::testFunc(cocos2d::CCSize const& p0, float p1) -> decltype(testFunc(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCSize const&, float>::func(&cocos2d::CCFadeOutUpTiles::testFunc), this);
	using FunctionType = decltype(testFunc(p0, p1))(*)(cocos2d::CCFadeOutUpTiles*, cocos2d::CCSize const&, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7b69c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::CCFadeOutUpTiles::transformTile(cocos2d::CCPoint const& p0, float p1) -> decltype(transformTile(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCPoint const&, float>::func(&cocos2d::CCFadeOutUpTiles::transformTile), this);
	using FunctionType = decltype(transformTile(p0, p1))(*)(cocos2d::CCFadeOutUpTiles*, cocos2d::CCPoint const&, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7b6a40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}
