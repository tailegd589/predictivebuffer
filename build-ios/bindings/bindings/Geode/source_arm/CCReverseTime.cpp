
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCReverseTime.hpp>
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

cocos2d::CCReverseTime::CCReverseTime() : cocos2d::CCReverseTime(geode::CutoffConstructor, sizeof(cocos2d::CCReverseTime)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCReverseTime::~CCReverseTime();

	using FunctionType = void(*)(cocos2d::CCReverseTime*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x33e0c8, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCReverseTime::~CCReverseTime() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCReverseTime*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x33e0f0, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCReverseTime(geode::CutoffConstructor, sizeof(cocos2d::CCReverseTime));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCReverseTime::create(cocos2d::CCFiniteTimeAction* p0) -> decltype(create(p0)) {
	using FunctionType = decltype(create(p0))(*)(cocos2d::CCFiniteTimeAction*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x33debc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::CCReverseTime::copyWithZone(cocos2d::CCZone* p0) -> decltype(copyWithZone(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCZone*>::func(&cocos2d::CCReverseTime::copyWithZone), this);
	using FunctionType = decltype(copyWithZone(p0))(*)(cocos2d::CCReverseTime*, cocos2d::CCZone*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x33dfc4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCReverseTime::startWithTarget(cocos2d::CCNode* p0) -> decltype(startWithTarget(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*>::func(&cocos2d::CCReverseTime::startWithTarget), this);
	using FunctionType = decltype(startWithTarget(p0))(*)(cocos2d::CCReverseTime*, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x33e1a8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCReverseTime::stop() -> decltype(stop()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCReverseTime::stop), this);
	using FunctionType = decltype(stop())(*)(cocos2d::CCReverseTime*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x33e1e8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCReverseTime::update(float p0) -> decltype(update(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCReverseTime::update), this);
	using FunctionType = decltype(update(p0))(*)(cocos2d::CCReverseTime*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x33e218, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCReverseTime::reverse() -> decltype(reverse()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCReverseTime::reverse), this);
	using FunctionType = decltype(reverse())(*)(cocos2d::CCReverseTime*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x33e238, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCReverseTime::initWithAction(cocos2d::CCFiniteTimeAction* p0) -> decltype(initWithAction(p0)) {
	using FunctionType = decltype(initWithAction(p0))(*)(cocos2d::CCReverseTime*, cocos2d::CCFiniteTimeAction*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x33df68, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
