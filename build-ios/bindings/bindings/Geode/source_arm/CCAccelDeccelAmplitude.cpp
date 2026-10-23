
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCAccelDeccelAmplitude.hpp>
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

cocos2d::CCAccelDeccelAmplitude::~CCAccelDeccelAmplitude() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCAccelDeccelAmplitude*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x1b6408, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCAccelDeccelAmplitude(geode::CutoffConstructor, sizeof(cocos2d::CCAccelDeccelAmplitude));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCAccelDeccelAmplitude::create(cocos2d::CCAction* p0, float p1) -> decltype(create(p0, p1)) {
	using FunctionType = decltype(create(p0, p1))(*)(cocos2d::CCAction*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b62fc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCAccelDeccelAmplitude::startWithTarget(cocos2d::CCNode* p0) -> decltype(startWithTarget(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*>::func(&cocos2d::CCAccelDeccelAmplitude::startWithTarget), this);
	using FunctionType = decltype(startWithTarget(p0))(*)(cocos2d::CCAccelDeccelAmplitude*, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b64c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCAccelDeccelAmplitude::update(float p0) -> decltype(update(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCAccelDeccelAmplitude::update), this);
	using FunctionType = decltype(update(p0))(*)(cocos2d::CCAccelDeccelAmplitude*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b64f4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCAccelDeccelAmplitude::reverse() -> decltype(reverse()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCAccelDeccelAmplitude::reverse), this);
	using FunctionType = decltype(reverse())(*)(cocos2d::CCAccelDeccelAmplitude*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b6538, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCAccelDeccelAmplitude::initWithAction(cocos2d::CCAction* p0, float p1) -> decltype(initWithAction(p0, p1)) {
	using FunctionType = decltype(initWithAction(p0, p1))(*)(cocos2d::CCAccelDeccelAmplitude*, cocos2d::CCAction*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b63c4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}
