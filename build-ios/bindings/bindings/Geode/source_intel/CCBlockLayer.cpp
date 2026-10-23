
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/CCBlockLayer.hpp>
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

CCBlockLayer::~CCBlockLayer() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(CCBlockLayer*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x5179c0, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) CCBlockLayer(geode::CutoffConstructor, sizeof(CCBlockLayer));
		geode::DestructorLock::addLock(this);
	}
}

auto CCBlockLayer::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x517d40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto CCBlockLayer::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CCBlockLayer::init), this);
	using FunctionType = decltype(init())(*)(CCBlockLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x517e10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CCBlockLayer::draw() -> decltype(draw()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CCBlockLayer::draw), this);
	using FunctionType = decltype(draw())(*)(CCBlockLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5180c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CCBlockLayer::ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchBegan(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&CCBlockLayer::ccTouchBegan), this);
	using FunctionType = decltype(ccTouchBegan(touch, event))(*)(CCBlockLayer*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5180f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto CCBlockLayer::ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchMoved(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&CCBlockLayer::ccTouchMoved), this);
	using FunctionType = decltype(ccTouchMoved(touch, event))(*)(CCBlockLayer*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x518150, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto CCBlockLayer::ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchEnded(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&CCBlockLayer::ccTouchEnded), this);
	using FunctionType = decltype(ccTouchEnded(touch, event))(*)(CCBlockLayer*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x518110, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto CCBlockLayer::ccTouchCancelled(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchCancelled(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&CCBlockLayer::ccTouchCancelled), this);
	using FunctionType = decltype(ccTouchCancelled(touch, event))(*)(CCBlockLayer*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x518130, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto CCBlockLayer::registerWithTouchDispatcher() -> decltype(registerWithTouchDispatcher()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CCBlockLayer::registerWithTouchDispatcher), this);
	using FunctionType = decltype(registerWithTouchDispatcher())(*)(CCBlockLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x517f80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CCBlockLayer::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CCBlockLayer::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(CCBlockLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x517fc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CCBlockLayer::customSetup() -> decltype(customSetup()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CCBlockLayer::customSetup), this);
	using FunctionType = decltype(customSetup())(*)(CCBlockLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x517f20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CCBlockLayer::enterLayer() -> decltype(enterLayer()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CCBlockLayer::enterLayer), this);
	using FunctionType = decltype(enterLayer())(*)(CCBlockLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x517f50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CCBlockLayer::exitLayer() -> decltype(exitLayer()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CCBlockLayer::exitLayer), this);
	using FunctionType = decltype(exitLayer())(*)(CCBlockLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x517ff0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CCBlockLayer::showLayer(bool instant) -> decltype(showLayer(instant)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&CCBlockLayer::showLayer), this);
	using FunctionType = decltype(showLayer(instant))(*)(CCBlockLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x518030, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, instant);
}

auto CCBlockLayer::hideLayer(bool instant) -> decltype(hideLayer(instant)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&CCBlockLayer::hideLayer), this);
	using FunctionType = decltype(hideLayer(instant))(*)(CCBlockLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x518040, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, instant);
}

auto CCBlockLayer::layerVisible() -> decltype(layerVisible()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CCBlockLayer::layerVisible), this);
	using FunctionType = decltype(layerVisible())(*)(CCBlockLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x518060, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CCBlockLayer::layerHidden() -> decltype(layerHidden()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CCBlockLayer::layerHidden), this);
	using FunctionType = decltype(layerHidden())(*)(CCBlockLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x518080, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CCBlockLayer::enterAnimFinished() -> decltype(enterAnimFinished()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CCBlockLayer::enterAnimFinished), this);
	using FunctionType = decltype(enterAnimFinished())(*)(CCBlockLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x518050, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CCBlockLayer::disableUI() -> decltype(disableUI()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CCBlockLayer::disableUI), this);
	using FunctionType = decltype(disableUI())(*)(CCBlockLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x517f30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CCBlockLayer::enableUI() -> decltype(enableUI()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CCBlockLayer::enableUI), this);
	using FunctionType = decltype(enableUI())(*)(CCBlockLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x517f40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CCBlockLayer::decrementForcePrio() -> decltype(decrementForcePrio()) {
	using FunctionType = decltype(decrementForcePrio())(*)(CCBlockLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x518170, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CCBlockLayer::incrementForcePrio() -> decltype(incrementForcePrio()) {
	using FunctionType = decltype(incrementForcePrio())(*)(CCBlockLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x517ed0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
