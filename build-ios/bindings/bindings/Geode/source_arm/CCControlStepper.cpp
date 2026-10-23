
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCControlStepper.hpp>
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

cocos2d::extension::CCControlStepper::CCControlStepper() : cocos2d::extension::CCControlStepper(geode::CutoffConstructor, sizeof(cocos2d::extension::CCControlStepper)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::extension::CCControlStepper::~CCControlStepper();

	using FunctionType = void(*)(cocos2d::extension::CCControlStepper*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3284f8, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::extension::CCControlStepper::~CCControlStepper() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::extension::CCControlStepper*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x32856c, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::extension::CCControlStepper(geode::CutoffConstructor, sizeof(cocos2d::extension::CCControlStepper));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::extension::CCControlStepper::create(cocos2d::CCSprite* p0, cocos2d::CCSprite* p1) -> decltype(create(p0, p1)) {
	using FunctionType = decltype(create(p0, p1))(*)(cocos2d::CCSprite*, cocos2d::CCSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x328a40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::extension::CCControlStepper::setWraps(bool p0) -> decltype(setWraps(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::extension::CCControlStepper::setWraps), this);
	using FunctionType = decltype(setWraps(p0))(*)(cocos2d::extension::CCControlStepper*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x328b34, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCControlStepper::setMinimumValue(double p0) -> decltype(setMinimumValue(p0)) {
	auto self = addresser::thunkAdjust(Resolve<double>::func(&cocos2d::extension::CCControlStepper::setMinimumValue), this);
	using FunctionType = decltype(setMinimumValue(p0))(*)(cocos2d::extension::CCControlStepper*, double);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x328bc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCControlStepper::setMaximumValue(double p0) -> decltype(setMaximumValue(p0)) {
	auto self = addresser::thunkAdjust(Resolve<double>::func(&cocos2d::extension::CCControlStepper::setMaximumValue), this);
	using FunctionType = decltype(setMaximumValue(p0))(*)(cocos2d::extension::CCControlStepper*, double);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x328bd4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCControlStepper::setValue(double p0) -> decltype(setValue(p0)) {
	auto self = addresser::thunkAdjust(Resolve<double>::func(&cocos2d::extension::CCControlStepper::setValue), this);
	using FunctionType = decltype(setValue(p0))(*)(cocos2d::extension::CCControlStepper*, double);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x328be8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCControlStepper::getValue() -> decltype(getValue()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::extension::CCControlStepper::getValue), this);
	using FunctionType = decltype(getValue())(*)(cocos2d::extension::CCControlStepper*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x328bf8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::extension::CCControlStepper::setStepValue(double p0) -> decltype(setStepValue(p0)) {
	auto self = addresser::thunkAdjust(Resolve<double>::func(&cocos2d::extension::CCControlStepper::setStepValue), this);
	using FunctionType = decltype(setStepValue(p0))(*)(cocos2d::extension::CCControlStepper*, double);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x328c00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCControlStepper::setValueWithSendingEvent(double p0, bool p1) -> decltype(setValueWithSendingEvent(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<double, bool>::func(&cocos2d::extension::CCControlStepper::setValueWithSendingEvent), this);
	using FunctionType = decltype(setValueWithSendingEvent(p0, p1))(*)(cocos2d::extension::CCControlStepper*, double, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x328c10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::extension::CCControlStepper::isContinuous() -> decltype(isContinuous()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::extension::CCControlStepper::isContinuous), this);
	using FunctionType = decltype(isContinuous())(*)(cocos2d::extension::CCControlStepper*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x328c08, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::extension::CCControlStepper::update(float p0) -> decltype(update(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::extension::CCControlStepper::update), this);
	using FunctionType = decltype(update(p0))(*)(cocos2d::extension::CCControlStepper*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x328d60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCControlStepper::ccTouchBegan(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) -> decltype(ccTouchBegan(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&cocos2d::extension::CCControlStepper::ccTouchBegan), this);
	using FunctionType = decltype(ccTouchBegan(p0, p1))(*)(cocos2d::extension::CCControlStepper*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x328ed0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::extension::CCControlStepper::ccTouchMoved(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) -> decltype(ccTouchMoved(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&cocos2d::extension::CCControlStepper::ccTouchMoved), this);
	using FunctionType = decltype(ccTouchMoved(p0, p1))(*)(cocos2d::extension::CCControlStepper*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x329078, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::extension::CCControlStepper::ccTouchEnded(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) -> decltype(ccTouchEnded(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&cocos2d::extension::CCControlStepper::ccTouchEnded), this);
	using FunctionType = decltype(ccTouchEnded(p0, p1))(*)(cocos2d::extension::CCControlStepper*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x329264, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::extension::CCControlStepper::initWithMinusSpriteAndPlusSprite(cocos2d::CCSprite* p0, cocos2d::CCSprite* p1) -> decltype(initWithMinusSpriteAndPlusSprite(p0, p1)) {
	using FunctionType = decltype(initWithMinusSpriteAndPlusSprite(p0, p1))(*)(cocos2d::extension::CCControlStepper*, cocos2d::CCSprite*, cocos2d::CCSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x328630, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::extension::CCControlStepper::startAutorepeat() -> decltype(startAutorepeat()) {
	using FunctionType = decltype(startAutorepeat())(*)(cocos2d::extension::CCControlStepper*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x328d24, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::extension::CCControlStepper::stopAutorepeat() -> decltype(stopAutorepeat()) {
	using FunctionType = decltype(stopAutorepeat())(*)(cocos2d::extension::CCControlStepper*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x328d54, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::extension::CCControlStepper::updateLayoutUsingTouchLocation(cocos2d::CCPoint p0) -> decltype(updateLayoutUsingTouchLocation(p0)) {
	using FunctionType = decltype(updateLayoutUsingTouchLocation(p0))(*)(cocos2d::extension::CCControlStepper*, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x328de4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
