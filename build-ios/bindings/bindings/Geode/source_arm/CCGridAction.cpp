
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCGridAction.hpp>
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

auto cocos2d::CCGridAction::create(float p0, cocos2d::CCSize const& p1) -> decltype(create(p0, p1)) {
	using FunctionType = decltype(create(p0, p1))(*)(float, cocos2d::CCSize const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b5dac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCGridAction::copyWithZone(cocos2d::CCZone* p0) -> decltype(copyWithZone(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCZone*>::func(&cocos2d::CCGridAction::copyWithZone), this);
	using FunctionType = decltype(copyWithZone(p0))(*)(cocos2d::CCGridAction*, cocos2d::CCZone*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b5fc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCGridAction::startWithTarget(cocos2d::CCNode* p0) -> decltype(startWithTarget(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*>::func(&cocos2d::CCGridAction::startWithTarget), this);
	using FunctionType = decltype(startWithTarget(p0))(*)(cocos2d::CCGridAction*, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b5ed0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCGridAction::reverse() -> decltype(reverse()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCGridAction::reverse), this);
	using FunctionType = decltype(reverse())(*)(cocos2d::CCGridAction*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b5fbc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCGridAction::initWithDuration(float p0, cocos2d::CCSize const& p1) -> decltype(initWithDuration(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<float, cocos2d::CCSize const&>::func(&cocos2d::CCGridAction::initWithDuration), this);
	using FunctionType = decltype(initWithDuration(p0, p1))(*)(cocos2d::CCGridAction*, float, cocos2d::CCSize const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b5e8c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::CCGridAction::getGrid() -> decltype(getGrid()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCGridAction::getGrid), this);
	using FunctionType = decltype(getGrid())(*)(cocos2d::CCGridAction*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b5fb4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}
