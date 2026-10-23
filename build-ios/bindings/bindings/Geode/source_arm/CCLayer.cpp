
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCLayer.hpp>
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

cocos2d::CCLayer::CCLayer() : cocos2d::CCLayer(geode::CutoffConstructor, sizeof(cocos2d::CCLayer)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCLayer::~CCLayer();

	using FunctionType = void(*)(cocos2d::CCLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x412074, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCLayer::~CCLayer() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCLayer*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x4121cc, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCLayer(geode::CutoffConstructor, sizeof(cocos2d::CCLayer));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCLayer::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x412490, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCLayer::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLayer::init), this);
	using FunctionType = decltype(init())(*)(cocos2d::CCLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x412434, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLayer::onEnter() -> decltype(onEnter()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLayer::onEnter), this);
	using FunctionType = decltype(onEnter())(*)(cocos2d::CCLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x412ce0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLayer::onEnterTransitionDidFinish() -> decltype(onEnterTransitionDidFinish()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLayer::onEnterTransitionDidFinish), this);
	using FunctionType = decltype(onEnterTransitionDidFinish())(*)(cocos2d::CCLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x412f04, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLayer::onExit() -> decltype(onExit()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLayer::onExit), this);
	using FunctionType = decltype(onExit())(*)(cocos2d::CCLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x412df0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLayer::registerWithTouchDispatcher() -> decltype(registerWithTouchDispatcher()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLayer::registerWithTouchDispatcher), this);
	using FunctionType = decltype(registerWithTouchDispatcher())(*)(cocos2d::CCLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4125a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLayer::registerScriptTouchHandler(int p0, bool p1, int p2, bool p3) -> decltype(registerScriptTouchHandler(p0, p1, p2, p3)) {
	auto self = addresser::thunkAdjust(Resolve<int, bool, int, bool>::func(&cocos2d::CCLayer::registerScriptTouchHandler), this);
	using FunctionType = decltype(registerScriptTouchHandler(p0, p1, p2, p3))(*)(cocos2d::CCLayer*, int, bool, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x412620, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2, p3);
}

auto cocos2d::CCLayer::unregisterScriptTouchHandler() -> decltype(unregisterScriptTouchHandler()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLayer::unregisterScriptTouchHandler), this);
	using FunctionType = decltype(unregisterScriptTouchHandler())(*)(cocos2d::CCLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x412680, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLayer::isTouchEnabled() -> decltype(isTouchEnabled()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLayer::isTouchEnabled), this);
	using FunctionType = decltype(isTouchEnabled())(*)(cocos2d::CCLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x41273c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLayer::setTouchEnabled(bool p0) -> decltype(setTouchEnabled(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::CCLayer::setTouchEnabled), this);
	using FunctionType = decltype(setTouchEnabled(p0))(*)(cocos2d::CCLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x412744, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLayer::setTouchMode(cocos2d::ccTouchesMode p0) -> decltype(setTouchMode(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::ccTouchesMode>::func(&cocos2d::CCLayer::setTouchMode), this);
	using FunctionType = decltype(setTouchMode(p0))(*)(cocos2d::CCLayer*, cocos2d::ccTouchesMode);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4127a4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLayer::getTouchMode() -> decltype(getTouchMode()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLayer::getTouchMode), this);
	using FunctionType = decltype(getTouchMode())(*)(cocos2d::CCLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x412864, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLayer::setTouchPriority(int p0) -> decltype(setTouchPriority(p0)) {
	auto self = addresser::thunkAdjust(Resolve<int>::func(&cocos2d::CCLayer::setTouchPriority), this);
	using FunctionType = decltype(setTouchPriority(p0))(*)(cocos2d::CCLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x412800, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLayer::getTouchPriority() -> decltype(getTouchPriority()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLayer::getTouchPriority), this);
	using FunctionType = decltype(getTouchPriority())(*)(cocos2d::CCLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x41285c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLayer::isAccelerometerEnabled() -> decltype(isAccelerometerEnabled()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLayer::isAccelerometerEnabled), this);
	using FunctionType = decltype(isAccelerometerEnabled())(*)(cocos2d::CCLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x41286c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLayer::setAccelerometerEnabled(bool p0) -> decltype(setAccelerometerEnabled(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::CCLayer::setAccelerometerEnabled), this);
	using FunctionType = decltype(setAccelerometerEnabled(p0))(*)(cocos2d::CCLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x412874, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLayer::setAccelerometerInterval(double p0) -> decltype(setAccelerometerInterval(p0)) {
	auto self = addresser::thunkAdjust(Resolve<double>::func(&cocos2d::CCLayer::setAccelerometerInterval), this);
	using FunctionType = decltype(setAccelerometerInterval(p0))(*)(cocos2d::CCLayer*, double);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4128b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLayer::isKeypadEnabled() -> decltype(isKeypadEnabled()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLayer::isKeypadEnabled), this);
	using FunctionType = decltype(isKeypadEnabled())(*)(cocos2d::CCLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4129ac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLayer::setKeypadEnabled(bool p0) -> decltype(setKeypadEnabled(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::CCLayer::setKeypadEnabled), this);
	using FunctionType = decltype(setKeypadEnabled(p0))(*)(cocos2d::CCLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4129b4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLayer::isKeyboardEnabled() -> decltype(isKeyboardEnabled()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLayer::isKeyboardEnabled), this);
	using FunctionType = decltype(isKeyboardEnabled())(*)(cocos2d::CCLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x412a2c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLayer::setKeyboardEnabled(bool p0) -> decltype(setKeyboardEnabled(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::CCLayer::setKeyboardEnabled), this);
	using FunctionType = decltype(setKeyboardEnabled(p0))(*)(cocos2d::CCLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x412a34, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLayer::isMouseEnabled() -> decltype(isMouseEnabled()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLayer::isMouseEnabled), this);
	using FunctionType = decltype(isMouseEnabled())(*)(cocos2d::CCLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x412aa0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLayer::setMouseEnabled(bool p0) -> decltype(setMouseEnabled(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::CCLayer::setMouseEnabled), this);
	using FunctionType = decltype(setMouseEnabled(p0))(*)(cocos2d::CCLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x412aa8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLayer::ccTouchBegan(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) -> decltype(ccTouchBegan(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&cocos2d::CCLayer::ccTouchBegan), this);
	using FunctionType = decltype(ccTouchBegan(p0, p1))(*)(cocos2d::CCLayer*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x412f40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::CCLayer::ccTouchMoved(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) -> decltype(ccTouchMoved(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&cocos2d::CCLayer::ccTouchMoved), this);
	using FunctionType = decltype(ccTouchMoved(p0, p1))(*)(cocos2d::CCLayer*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x412ff0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::CCLayer::ccTouchEnded(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) -> decltype(ccTouchEnded(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&cocos2d::CCLayer::ccTouchEnded), this);
	using FunctionType = decltype(ccTouchEnded(p0, p1))(*)(cocos2d::CCLayer*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x413080, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::CCLayer::ccTouchCancelled(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) -> decltype(ccTouchCancelled(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&cocos2d::CCLayer::ccTouchCancelled), this);
	using FunctionType = decltype(ccTouchCancelled(p0, p1))(*)(cocos2d::CCLayer*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x413110, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::CCLayer::ccTouchesBegan(cocos2d::CCSet* p0, cocos2d::CCEvent* p1) -> decltype(ccTouchesBegan(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCSet*, cocos2d::CCEvent*>::func(&cocos2d::CCLayer::ccTouchesBegan), this);
	using FunctionType = decltype(ccTouchesBegan(p0, p1))(*)(cocos2d::CCLayer*, cocos2d::CCSet*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4131a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::CCLayer::ccTouchesMoved(cocos2d::CCSet* p0, cocos2d::CCEvent* p1) -> decltype(ccTouchesMoved(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCSet*, cocos2d::CCEvent*>::func(&cocos2d::CCLayer::ccTouchesMoved), this);
	using FunctionType = decltype(ccTouchesMoved(p0, p1))(*)(cocos2d::CCLayer*, cocos2d::CCSet*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x413230, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::CCLayer::ccTouchesEnded(cocos2d::CCSet* p0, cocos2d::CCEvent* p1) -> decltype(ccTouchesEnded(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCSet*, cocos2d::CCEvent*>::func(&cocos2d::CCLayer::ccTouchesEnded), this);
	using FunctionType = decltype(ccTouchesEnded(p0, p1))(*)(cocos2d::CCLayer*, cocos2d::CCSet*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4132c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::CCLayer::ccTouchesCancelled(cocos2d::CCSet* p0, cocos2d::CCEvent* p1) -> decltype(ccTouchesCancelled(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCSet*, cocos2d::CCEvent*>::func(&cocos2d::CCLayer::ccTouchesCancelled), this);
	using FunctionType = decltype(ccTouchesCancelled(p0, p1))(*)(cocos2d::CCLayer*, cocos2d::CCSet*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x413350, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::CCLayer::setPreviousPriority(int p0) -> decltype(setPreviousPriority(p0)) {
	auto self = addresser::thunkAdjust(Resolve<int>::func(&cocos2d::CCLayer::setPreviousPriority), this);
	using FunctionType = decltype(setPreviousPriority(p0))(*)(cocos2d::CCLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x600c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLayer::getPreviousPriority() -> decltype(getPreviousPriority()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLayer::getPreviousPriority), this);
	using FunctionType = decltype(getPreviousPriority())(*)(cocos2d::CCLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6014, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLayer::didAccelerate(cocos2d::CCAcceleration* p0) -> decltype(didAccelerate(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCAcceleration*>::func(&cocos2d::CCLayer::didAccelerate), this);
	using FunctionType = decltype(didAccelerate(p0))(*)(cocos2d::CCLayer*, cocos2d::CCAcceleration*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4128e8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLayer::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLayer::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(cocos2d::CCLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x412b50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLayer::keyMenuClicked() -> decltype(keyMenuClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLayer::keyMenuClicked), this);
	using FunctionType = decltype(keyMenuClicked())(*)(cocos2d::CCLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x412bf0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLayer::keyDown(cocos2d::enumKeyCodes p0, double p1) -> decltype(keyDown(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::enumKeyCodes, double>::func(&cocos2d::CCLayer::keyDown), this);
	using FunctionType = decltype(keyDown(p0, p1))(*)(cocos2d::CCLayer*, cocos2d::enumKeyCodes, double);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x412c70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::CCLayer::excuteScriptTouchHandler(int p0, cocos2d::CCSet* p1) -> decltype(excuteScriptTouchHandler(p0, p1)) {
	using FunctionType = decltype(excuteScriptTouchHandler(p0, p1))(*)(cocos2d::CCLayer*, int, cocos2d::CCSet*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4126f4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCLayer::excuteScriptTouchHandler(int p0, cocos2d::CCTouch* p1) -> decltype(excuteScriptTouchHandler(p0, p1)) {
	using FunctionType = decltype(excuteScriptTouchHandler(p0, p1))(*)(cocos2d::CCLayer*, int, cocos2d::CCTouch*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4126ac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCLayer::registerScriptAccelerateHandler(int p0) -> decltype(registerScriptAccelerateHandler(p0)) {
	using FunctionType = decltype(registerScriptAccelerateHandler(p0))(*)(cocos2d::CCLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x412970, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCLayer::registerScriptKeypadHandler(int p0) -> decltype(registerScriptKeypadHandler(p0)) {
	using FunctionType = decltype(registerScriptKeypadHandler(p0))(*)(cocos2d::CCLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x412b14, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCLayer::unregisterScriptAccelerateHandler() -> decltype(unregisterScriptAccelerateHandler()) {
	using FunctionType = decltype(unregisterScriptAccelerateHandler())(*)(cocos2d::CCLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x412278, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCLayer::unregisterScriptKeypadHandler() -> decltype(unregisterScriptKeypadHandler()) {
	using FunctionType = decltype(unregisterScriptKeypadHandler())(*)(cocos2d::CCLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x41224c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
