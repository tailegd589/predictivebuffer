
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCTransitionFadeTR.hpp>
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

cocos2d::CCTransitionFadeTR::CCTransitionFadeTR() : cocos2d::CCTransitionFadeTR(geode::CutoffConstructor, sizeof(cocos2d::CCTransitionFadeTR)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCTransitionFadeTR::~CCTransitionFadeTR();

	using FunctionType = void(*)(cocos2d::CCTransitionFadeTR*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd9a30, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCTransitionFadeTR::~CCTransitionFadeTR() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCTransitionFadeTR*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0xd9a90, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCTransitionFadeTR(geode::CutoffConstructor, sizeof(cocos2d::CCTransitionFadeTR));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCTransitionFadeTR::create(float p0, cocos2d::CCScene* p1) -> decltype(create(p0, p1)) {
	using FunctionType = decltype(create(p0, p1))(*)(float, cocos2d::CCScene*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd9b80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCTransitionFadeTR::onEnter() -> decltype(onEnter()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTransitionFadeTR::onEnter), this);
	using FunctionType = decltype(onEnter())(*)(cocos2d::CCTransitionFadeTR*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd9c20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTransitionFadeTR::sceneOrder() -> decltype(sceneOrder()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTransitionFadeTR::sceneOrder), this);
	using FunctionType = decltype(sceneOrder())(*)(cocos2d::CCTransitionFadeTR*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd9c10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTransitionFadeTR::actionWithSize(cocos2d::CCSize const& p0) -> decltype(actionWithSize(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCSize const&>::func(&cocos2d::CCTransitionFadeTR::actionWithSize), this);
	using FunctionType = decltype(actionWithSize(p0))(*)(cocos2d::CCTransitionFadeTR*, cocos2d::CCSize const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd9d20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCTransitionFadeTR::easeActionWithAction(cocos2d::CCActionInterval* p0) -> decltype(easeActionWithAction(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCActionInterval*>::func(&cocos2d::CCTransitionFadeTR::easeActionWithAction), this);
	using FunctionType = decltype(easeActionWithAction(p0))(*)(cocos2d::CCTransitionFadeTR*, cocos2d::CCActionInterval*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd9d40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}
