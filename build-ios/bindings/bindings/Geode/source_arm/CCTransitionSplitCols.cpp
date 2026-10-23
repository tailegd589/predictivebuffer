
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCTransitionSplitCols.hpp>
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

cocos2d::CCTransitionSplitCols::CCTransitionSplitCols() : cocos2d::CCTransitionSplitCols(geode::CutoffConstructor, sizeof(cocos2d::CCTransitionSplitCols)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCTransitionSplitCols::~CCTransitionSplitCols();

	using FunctionType = void(*)(cocos2d::CCTransitionSplitCols*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xbfd7c, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCTransitionSplitCols::~CCTransitionSplitCols() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCTransitionSplitCols*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0xbfdcc, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCTransitionSplitCols(geode::CutoffConstructor, sizeof(cocos2d::CCTransitionSplitCols));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCTransitionSplitCols::create(float p0, cocos2d::CCScene* p1) -> decltype(create(p0, p1)) {
	using FunctionType = decltype(create(p0, p1))(*)(float, cocos2d::CCScene*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xbfe90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCTransitionSplitCols::onEnter() -> decltype(onEnter()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTransitionSplitCols::onEnter), this);
	using FunctionType = decltype(onEnter())(*)(cocos2d::CCTransitionSplitCols*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xbff38, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTransitionSplitCols::action() -> decltype(action()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTransitionSplitCols::action), this);
	using FunctionType = decltype(action())(*)(cocos2d::CCTransitionSplitCols*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xc004c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTransitionSplitCols::easeActionWithAction(cocos2d::CCActionInterval* p0) -> decltype(easeActionWithAction(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCActionInterval*>::func(&cocos2d::CCTransitionSplitCols::easeActionWithAction), this);
	using FunctionType = decltype(easeActionWithAction(p0))(*)(cocos2d::CCTransitionSplitCols*, cocos2d::CCActionInterval*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xc0060, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}
