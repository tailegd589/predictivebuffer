
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCRepeat.hpp>
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

cocos2d::CCRepeat::~CCRepeat() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCRepeat*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x3b6550, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCRepeat(geode::CutoffConstructor, sizeof(cocos2d::CCRepeat));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCRepeat::create(cocos2d::CCFiniteTimeAction* pAction, unsigned int times) -> decltype(create(pAction, times)) {
	using FunctionType = decltype(create(pAction, times))(*)(cocos2d::CCFiniteTimeAction*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3b6260, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(pAction, times);
}

auto cocos2d::CCRepeat::copyWithZone(cocos2d::CCZone* pZone) -> decltype(copyWithZone(pZone)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCZone*>::func(&cocos2d::CCRepeat::copyWithZone), this);
	using FunctionType = decltype(copyWithZone(pZone))(*)(cocos2d::CCRepeat*, cocos2d::CCZone*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3b63f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, pZone);
}

auto cocos2d::CCRepeat::update(float dt) -> decltype(update(dt)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCRepeat::update), this);
	using FunctionType = decltype(update(dt))(*)(cocos2d::CCRepeat*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3b6690, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, dt);
}

auto cocos2d::CCRepeat::isDone() -> decltype(isDone()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCRepeat::isDone), this);
	using FunctionType = decltype(isDone())(*)(cocos2d::CCRepeat*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3b67b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCRepeat::startWithTarget(cocos2d::CCNode* pTarget) -> decltype(startWithTarget(pTarget)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*>::func(&cocos2d::CCRepeat::startWithTarget), this);
	using FunctionType = decltype(startWithTarget(pTarget))(*)(cocos2d::CCRepeat*, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3b6610, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, pTarget);
}

auto cocos2d::CCRepeat::stop() -> decltype(stop()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCRepeat::stop), this);
	using FunctionType = decltype(stop())(*)(cocos2d::CCRepeat*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3b6660, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCRepeat::reverse() -> decltype(reverse()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCRepeat::reverse), this);
	using FunctionType = decltype(reverse())(*)(cocos2d::CCRepeat*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3b67c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCRepeat::initWithAction(cocos2d::CCFiniteTimeAction* pAction, unsigned int times) -> decltype(initWithAction(pAction, times)) {
	using FunctionType = decltype(initWithAction(pAction, times))(*)(cocos2d::CCRepeat*, cocos2d::CCFiniteTimeAction*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3b6360, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, pAction, times);
}
