
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCTiledGrid3DAction.hpp>
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

auto cocos2d::CCTiledGrid3DAction::create(float p0, cocos2d::CCSize const& p1) -> decltype(create(p0, p1)) {
	using FunctionType = decltype(create(p0, p1))(*)(float, cocos2d::CCSize const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x20a3b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCTiledGrid3DAction::getGrid() -> decltype(getGrid()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTiledGrid3DAction::getGrid), this);
	using FunctionType = decltype(getGrid())(*)(cocos2d::CCTiledGrid3DAction*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x20a310, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTiledGrid3DAction::originalTile(cocos2d::CCPoint const& p0) -> decltype(originalTile(p0)) {
	using FunctionType = decltype(originalTile(p0))(*)(cocos2d::CCTiledGrid3DAction*, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x20a350, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTiledGrid3DAction::setTile(cocos2d::CCPoint const& p0, cocos2d::ccQuad3 const& p1) -> decltype(setTile(p0, p1)) {
	using FunctionType = decltype(setTile(p0, p1))(*)(cocos2d::CCTiledGrid3DAction*, cocos2d::CCPoint const&, cocos2d::ccQuad3 const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x20a380, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCTiledGrid3DAction::tile(cocos2d::CCPoint const& p0) -> decltype(tile(p0)) {
	using FunctionType = decltype(tile(p0))(*)(cocos2d::CCTiledGrid3DAction*, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x20a320, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
