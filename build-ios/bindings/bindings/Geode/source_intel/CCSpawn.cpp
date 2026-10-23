
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCSpawn.hpp>
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

cocos2d::CCSpawn::~CCSpawn() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCSpawn*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x3b75a0, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCSpawn(geode::CutoffConstructor, sizeof(cocos2d::CCSpawn));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCSpawn::create(cocos2d::CCArray* arrayOfActions) -> decltype(create(arrayOfActions)) {
	using FunctionType = decltype(create(arrayOfActions))(*)(cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3b6ef0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(arrayOfActions);
}

auto cocos2d::CCSpawn::createWithTwoActions(cocos2d::CCFiniteTimeAction* p0, cocos2d::CCFiniteTimeAction* p1) -> decltype(createWithTwoActions(p0, p1)) {
	using FunctionType = decltype(createWithTwoActions(p0, p1))(*)(cocos2d::CCFiniteTimeAction*, cocos2d::CCFiniteTimeAction*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3b6e60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCSpawn::createWithVariableList(cocos2d::CCFiniteTimeAction* p0, va_list p1) -> decltype(createWithVariableList(p0, p1)) {
	using FunctionType = decltype(createWithVariableList(p0, p1))(*)(cocos2d::CCFiniteTimeAction*, va_list);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3b6c10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCSpawn::copyWithZone(cocos2d::CCZone* p0) -> decltype(copyWithZone(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCZone*>::func(&cocos2d::CCSpawn::copyWithZone), this);
	using FunctionType = decltype(copyWithZone(p0))(*)(cocos2d::CCSpawn*, cocos2d::CCZone*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3b74a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCSpawn::update(float p0) -> decltype(update(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCSpawn::update), this);
	using FunctionType = decltype(update(p0))(*)(cocos2d::CCSpawn*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3b7700, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCSpawn::startWithTarget(cocos2d::CCNode* p0) -> decltype(startWithTarget(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*>::func(&cocos2d::CCSpawn::startWithTarget), this);
	using FunctionType = decltype(startWithTarget(p0))(*)(cocos2d::CCSpawn*, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3b7690, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCSpawn::stop() -> decltype(stop()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCSpawn::stop), this);
	using FunctionType = decltype(stop())(*)(cocos2d::CCSpawn*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3b76d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCSpawn::reverse() -> decltype(reverse()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCSpawn::reverse), this);
	using FunctionType = decltype(reverse())(*)(cocos2d::CCSpawn*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3b7750, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCSpawn::initWithTwoActions(cocos2d::CCFiniteTimeAction* p0, cocos2d::CCFiniteTimeAction* p1) -> decltype(initWithTwoActions(p0, p1)) {
	using FunctionType = decltype(initWithTwoActions(p0, p1))(*)(cocos2d::CCSpawn*, cocos2d::CCFiniteTimeAction*, cocos2d::CCFiniteTimeAction*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3b70c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}
