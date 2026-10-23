
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCTransitionFade.hpp>
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

cocos2d::CCTransitionFade::CCTransitionFade() : cocos2d::CCTransitionFade(geode::CutoffConstructor, sizeof(cocos2d::CCTransitionFade)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCTransitionFade::~CCTransitionFade();

	using FunctionType = void(*)(cocos2d::CCTransitionFade*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xbf120, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCTransitionFade::~CCTransitionFade() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCTransitionFade*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0xbf160, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCTransitionFade(geode::CutoffConstructor, sizeof(cocos2d::CCTransitionFade));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCTransitionFade::create(float p0, cocos2d::CCScene* p1) -> decltype(create(p0, p1)) {
	using FunctionType = decltype(create(p0, p1))(*)(float, cocos2d::CCScene*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xbf2c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCTransitionFade::create(float p0, cocos2d::CCScene* p1, cocos2d::ccColor3B const& p2) -> decltype(create(p0, p1, p2)) {
	using FunctionType = decltype(create(p0, p1, p2))(*)(float, cocos2d::CCScene*, cocos2d::ccColor3B const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xbf224, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

auto cocos2d::CCTransitionFade::onEnter() -> decltype(onEnter()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTransitionFade::onEnter), this);
	using FunctionType = decltype(onEnter())(*)(cocos2d::CCTransitionFade*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xbf3ac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTransitionFade::onExit() -> decltype(onExit()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTransitionFade::onExit), this);
	using FunctionType = decltype(onExit())(*)(cocos2d::CCTransitionFade*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xbf4e8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTransitionFade::initWithDuration(float p0, cocos2d::CCScene* p1) -> decltype(initWithDuration(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<float, cocos2d::CCScene*>::func(&cocos2d::CCTransitionFade::initWithDuration), this);
	using FunctionType = decltype(initWithDuration(p0, p1))(*)(cocos2d::CCTransitionFade*, float, cocos2d::CCScene*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xbf384, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::CCTransitionFade::initWithDuration(float p0, cocos2d::CCScene* p1, cocos2d::ccColor3B const& p2) -> decltype(initWithDuration(p0, p1, p2)) {
	auto self = addresser::thunkAdjust(Resolve<float, cocos2d::CCScene*, cocos2d::ccColor3B const&>::func(&cocos2d::CCTransitionFade::initWithDuration), this);
	using FunctionType = decltype(initWithDuration(p0, p1, p2))(*)(cocos2d::CCTransitionFade*, float, cocos2d::CCScene*, cocos2d::ccColor3B const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xbf340, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2);
}
