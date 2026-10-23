
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/RetryLevelLayer.hpp>
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

RetryLevelLayer::~RetryLevelLayer() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(RetryLevelLayer*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x4f8210, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) RetryLevelLayer(geode::CutoffConstructor, sizeof(RetryLevelLayer));
		geode::DestructorLock::addLock(this);
	}
}

auto RetryLevelLayer::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4f8040, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto RetryLevelLayer::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&RetryLevelLayer::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(RetryLevelLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4f97b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto RetryLevelLayer::keyDown(cocos2d::enumKeyCodes key, double timestamp) -> decltype(keyDown(key, timestamp)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::enumKeyCodes, double>::func(&RetryLevelLayer::keyDown), this);
	using FunctionType = decltype(keyDown(key, timestamp))(*)(RetryLevelLayer*, cocos2d::enumKeyCodes, double);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4f96e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, key, timestamp);
}

auto RetryLevelLayer::customSetup() -> decltype(customSetup()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&RetryLevelLayer::customSetup), this);
	using FunctionType = decltype(customSetup())(*)(RetryLevelLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4f85e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto RetryLevelLayer::showLayer(bool instant) -> decltype(showLayer(instant)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&RetryLevelLayer::showLayer), this);
	using FunctionType = decltype(showLayer(instant))(*)(RetryLevelLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4f91a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, instant);
}

auto RetryLevelLayer::enterAnimFinished() -> decltype(enterAnimFinished()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&RetryLevelLayer::enterAnimFinished), this);
	using FunctionType = decltype(enterAnimFinished())(*)(RetryLevelLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4f92a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto RetryLevelLayer::rewardedVideoFinished() -> decltype(rewardedVideoFinished()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&RetryLevelLayer::rewardedVideoFinished), this);
	using FunctionType = decltype(rewardedVideoFinished())(*)(RetryLevelLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4f96c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto RetryLevelLayer::keyUp(cocos2d::enumKeyCodes key, double timestamp) -> decltype(keyUp(key, timestamp)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::enumKeyCodes, double>::func(&RetryLevelLayer::keyUp), this);
	using FunctionType = decltype(keyUp(key, timestamp))(*)(RetryLevelLayer*, cocos2d::enumKeyCodes, double);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4f9790, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, key, timestamp);
}

auto RetryLevelLayer::getEndText() -> decltype(getEndText()) {
	using FunctionType = decltype(getEndText())(*)(RetryLevelLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4f9150, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto RetryLevelLayer::onEveryplay(cocos2d::CCObject* sender) -> decltype(onEveryplay(sender)) {
	using FunctionType = decltype(onEveryplay(sender))(*)(RetryLevelLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4f92d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto RetryLevelLayer::onFullVersion(cocos2d::CCObject* sender) -> decltype(onFullVersion(sender)) {
	using FunctionType = decltype(onFullVersion(sender))(*)(RetryLevelLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4f92e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto RetryLevelLayer::onMenu(cocos2d::CCObject* sender) -> decltype(onMenu(sender)) {
	using FunctionType = decltype(onMenu(sender))(*)(RetryLevelLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4f90b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto RetryLevelLayer::onReplay(cocos2d::CCObject* sender) -> decltype(onReplay(sender)) {
	using FunctionType = decltype(onReplay(sender))(*)(RetryLevelLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4f9060, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto RetryLevelLayer::onRewardedVideo(cocos2d::CCObject* sender) -> decltype(onRewardedVideo(sender)) {
	using FunctionType = decltype(onRewardedVideo(sender))(*)(RetryLevelLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4f9300, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto RetryLevelLayer::setupLastProgress() -> decltype(setupLastProgress()) {
	using FunctionType = decltype(setupLastProgress())(*)(RetryLevelLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4f8cd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
