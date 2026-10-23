
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GhostTrailEffect.hpp>
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

auto GhostTrailEffect::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5225d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto GhostTrailEffect::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GhostTrailEffect::init), this);
	using FunctionType = decltype(init())(*)(GhostTrailEffect*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5226a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GhostTrailEffect::draw() -> decltype(draw()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GhostTrailEffect::draw), this);
	using FunctionType = decltype(draw())(*)(GhostTrailEffect*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x522c08, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GhostTrailEffect::doBlendAdditive() -> decltype(doBlendAdditive()) {
	using FunctionType = decltype(doBlendAdditive())(*)(GhostTrailEffect*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x522bf8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GhostTrailEffect::runWithTarget(cocos2d::CCSprite* sprite, float snapshotInterval, float fadeInterval, float duration, float ghostScale, bool scaleTwice) -> decltype(runWithTarget(sprite, snapshotInterval, fadeInterval, duration, ghostScale, scaleTwice)) {
	using FunctionType = decltype(runWithTarget(sprite, snapshotInterval, fadeInterval, duration, ghostScale, scaleTwice))(*)(GhostTrailEffect*, cocos2d::CCSprite*, float, float, float, float, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5226fc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sprite, snapshotInterval, fadeInterval, duration, ghostScale, scaleTwice);
}

auto GhostTrailEffect::stopTrail() -> decltype(stopTrail()) {
	using FunctionType = decltype(stopTrail())(*)(GhostTrailEffect*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x522ba8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GhostTrailEffect::trailSnapshot(float dt) -> decltype(trailSnapshot(dt)) {
	using FunctionType = decltype(trailSnapshot(dt))(*)(GhostTrailEffect*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5227b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt);
}
