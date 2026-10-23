
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCAnimate.hpp>
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

cocos2d::CCAnimate::CCAnimate() : cocos2d::CCAnimate(geode::CutoffConstructor, sizeof(cocos2d::CCAnimate)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCAnimate::~CCAnimate();

	using FunctionType = void(*)(cocos2d::CCAnimate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x33e694, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCAnimate::~CCAnimate() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCAnimate*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x33e700, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCAnimate(geode::CutoffConstructor, sizeof(cocos2d::CCAnimate));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCAnimate::create(cocos2d::CCAnimation* p0) -> decltype(create(p0)) {
	using FunctionType = decltype(create(p0))(*)(cocos2d::CCAnimation*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x33e250, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::CCAnimate::copyWithZone(cocos2d::CCZone* p0) -> decltype(copyWithZone(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCZone*>::func(&cocos2d::CCAnimate::copyWithZone), this);
	using FunctionType = decltype(copyWithZone(p0))(*)(cocos2d::CCAnimate*, cocos2d::CCZone*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x33e58c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCAnimate::update(float p0) -> decltype(update(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCAnimate::update), this);
	using FunctionType = decltype(update(p0))(*)(cocos2d::CCAnimate*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x33e83c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCAnimate::startWithTarget(cocos2d::CCNode* p0) -> decltype(startWithTarget(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*>::func(&cocos2d::CCAnimate::startWithTarget), this);
	using FunctionType = decltype(startWithTarget(p0))(*)(cocos2d::CCAnimate*, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x33e784, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCAnimate::stop() -> decltype(stop()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCAnimate::stop), this);
	using FunctionType = decltype(stop())(*)(cocos2d::CCAnimate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x33e7f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCAnimate::reverse() -> decltype(reverse()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCAnimate::reverse), this);
	using FunctionType = decltype(reverse())(*)(cocos2d::CCAnimate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x33ea50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCAnimate::initWithAnimation(cocos2d::CCAnimation* p0) -> decltype(initWithAnimation(p0)) {
	using FunctionType = decltype(initWithAnimation(p0))(*)(cocos2d::CCAnimate*, cocos2d::CCAnimation*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x33e360, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
