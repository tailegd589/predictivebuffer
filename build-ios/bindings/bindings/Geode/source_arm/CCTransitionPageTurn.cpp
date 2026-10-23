
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCTransitionPageTurn.hpp>
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

cocos2d::CCTransitionPageTurn::CCTransitionPageTurn() : cocos2d::CCTransitionPageTurn(geode::CutoffConstructor, sizeof(cocos2d::CCTransitionPageTurn)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCTransitionPageTurn::~CCTransitionPageTurn();

	using FunctionType = void(*)(cocos2d::CCTransitionPageTurn*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x358ab4, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCTransitionPageTurn::~CCTransitionPageTurn() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCTransitionPageTurn*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x358af4, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCTransitionPageTurn(geode::CutoffConstructor, sizeof(cocos2d::CCTransitionPageTurn));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCTransitionPageTurn::create(float p0, cocos2d::CCScene* p1, bool p2) -> decltype(create(p0, p1, p2)) {
	using FunctionType = decltype(create(p0, p1, p2))(*)(float, cocos2d::CCScene*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x358b10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

auto cocos2d::CCTransitionPageTurn::initWithDuration(float p0, cocos2d::CCScene* p1, bool p2) -> decltype(initWithDuration(p0, p1, p2)) {
	auto self = addresser::thunkAdjust(Resolve<float, cocos2d::CCScene*, bool>::func(&cocos2d::CCTransitionPageTurn::initWithDuration), this);
	using FunctionType = decltype(initWithDuration(p0, p1, p2))(*)(cocos2d::CCTransitionPageTurn*, float, cocos2d::CCScene*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x358b94, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2);
}

auto cocos2d::CCTransitionPageTurn::onEnter() -> decltype(onEnter()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTransitionPageTurn::onEnter), this);
	using FunctionType = decltype(onEnter())(*)(cocos2d::CCTransitionPageTurn*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x358bbc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTransitionPageTurn::sceneOrder() -> decltype(sceneOrder()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTransitionPageTurn::sceneOrder), this);
	using FunctionType = decltype(sceneOrder())(*)(cocos2d::CCTransitionPageTurn*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x358bb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTransitionPageTurn::actionWithSize(cocos2d::CCSize const& p0) -> decltype(actionWithSize(p0)) {
	using FunctionType = decltype(actionWithSize(p0))(*)(cocos2d::CCTransitionPageTurn*, cocos2d::CCSize const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x358cd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
