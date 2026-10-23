
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCEaseRateAction.hpp>
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

cocos2d::CCEaseRateAction::~CCEaseRateAction() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCEaseRateAction*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x514840, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCEaseRateAction(geode::CutoffConstructor, sizeof(cocos2d::CCEaseRateAction));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCEaseRateAction::create(cocos2d::CCActionInterval* pAction, float fRate) -> decltype(create(pAction, fRate)) {
	using FunctionType = decltype(create(pAction, fRate))(*)(cocos2d::CCActionInterval*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x514620, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(pAction, fRate);
}

auto cocos2d::CCEaseRateAction::copyWithZone(cocos2d::CCZone* pZone) -> decltype(copyWithZone(pZone)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCZone*>::func(&cocos2d::CCEaseRateAction::copyWithZone), this);
	using FunctionType = decltype(copyWithZone(pZone))(*)(cocos2d::CCEaseRateAction*, cocos2d::CCZone*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x514730, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, pZone);
}

auto cocos2d::CCEaseRateAction::reverse() -> decltype(reverse()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCEaseRateAction::reverse), this);
	using FunctionType = decltype(reverse())(*)(cocos2d::CCEaseRateAction*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x514900, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCEaseRateAction::initWithAction(cocos2d::CCActionInterval* pAction, float fRate) -> decltype(initWithAction(pAction, fRate)) {
	using FunctionType = decltype(initWithAction(pAction, fRate))(*)(cocos2d::CCEaseRateAction*, cocos2d::CCActionInterval*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5146e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, pAction, fRate);
}
