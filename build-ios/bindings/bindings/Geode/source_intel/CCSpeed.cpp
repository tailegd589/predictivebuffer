
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCSpeed.hpp>
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

cocos2d::CCSpeed::~CCSpeed() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCSpeed*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x5f4450, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCSpeed(geode::CutoffConstructor, sizeof(cocos2d::CCSpeed));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCSpeed::create(cocos2d::CCActionInterval* p0, float p1) -> decltype(create(p0, p1)) {
	using FunctionType = decltype(create(p0, p1))(*)(cocos2d::CCActionInterval*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f4540, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCSpeed::copyWithZone(cocos2d::CCZone* p0) -> decltype(copyWithZone(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCZone*>::func(&cocos2d::CCSpeed::copyWithZone), this);
	using FunctionType = decltype(copyWithZone(p0))(*)(cocos2d::CCSpeed*, cocos2d::CCZone*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f4620, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCSpeed::isDone() -> decltype(isDone()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCSpeed::isDone), this);
	using FunctionType = decltype(isDone())(*)(cocos2d::CCSpeed*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f4830, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCSpeed::startWithTarget(cocos2d::CCNode* p0) -> decltype(startWithTarget(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*>::func(&cocos2d::CCSpeed::startWithTarget), this);
	using FunctionType = decltype(startWithTarget(p0))(*)(cocos2d::CCSpeed*, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f47c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCSpeed::stop() -> decltype(stop()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCSpeed::stop), this);
	using FunctionType = decltype(stop())(*)(cocos2d::CCSpeed*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f47e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCSpeed::step(float p0) -> decltype(step(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCSpeed::step), this);
	using FunctionType = decltype(step(p0))(*)(cocos2d::CCSpeed*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f4810, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCSpeed::reverse() -> decltype(reverse()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCSpeed::reverse), this);
	using FunctionType = decltype(reverse())(*)(cocos2d::CCSpeed*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f4840, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCSpeed::initWithAction(cocos2d::CCActionInterval* p0, float p1) -> decltype(initWithAction(p0, p1)) {
	using FunctionType = decltype(initWithAction(p0, p1))(*)(cocos2d::CCSpeed*, cocos2d::CCActionInterval*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f45e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCSpeed::setInnerAction(cocos2d::CCActionInterval* p0) -> decltype(setInnerAction(p0)) {
	using FunctionType = decltype(setInnerAction(p0))(*)(cocos2d::CCSpeed*, cocos2d::CCActionInterval*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f48f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
