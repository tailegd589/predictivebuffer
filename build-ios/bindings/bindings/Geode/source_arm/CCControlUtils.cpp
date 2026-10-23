
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCControlUtils.hpp>
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

auto cocos2d::extension::CCControlUtils::addSpriteToTargetWithPosAndAnchor(char const* p0, cocos2d::CCNode* p1, cocos2d::CCPoint p2, cocos2d::CCPoint p3) -> decltype(addSpriteToTargetWithPosAndAnchor(p0, p1, p2, p3)) {
	using FunctionType = decltype(addSpriteToTargetWithPosAndAnchor(p0, p1, p2, p3))(*)(char const*, cocos2d::CCNode*, cocos2d::CCPoint, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x32d8b8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3);
}

auto cocos2d::extension::CCControlUtils::CCRectUnion(cocos2d::CCRect const& p0, cocos2d::CCRect const& p1) -> decltype(CCRectUnion(p0, p1)) {
	using FunctionType = decltype(CCRectUnion(p0, p1))(*)(cocos2d::CCRect const&, cocos2d::CCRect const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x32daf8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::extension::CCControlUtils::HSVfromRGB(cocos2d::extension::RGBA p0) -> decltype(HSVfromRGB(p0)) {
	using FunctionType = decltype(HSVfromRGB(p0))(*)(cocos2d::extension::RGBA);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x32d930, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::extension::CCControlUtils::RGBfromHSV(cocos2d::extension::HSV p0) -> decltype(RGBfromHSV(p0)) {
	using FunctionType = decltype(RGBfromHSV(p0))(*)(cocos2d::extension::HSV);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x32d9dc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}
