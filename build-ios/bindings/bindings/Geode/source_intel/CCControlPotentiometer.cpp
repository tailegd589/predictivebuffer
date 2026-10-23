
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCControlPotentiometer.hpp>
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

cocos2d::extension::CCControlPotentiometer::CCControlPotentiometer() : cocos2d::extension::CCControlPotentiometer(geode::CutoffConstructor, sizeof(cocos2d::extension::CCControlPotentiometer)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::extension::CCControlPotentiometer::~CCControlPotentiometer();

	using FunctionType = void(*)(cocos2d::extension::CCControlPotentiometer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x35a5f0, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::extension::CCControlPotentiometer::~CCControlPotentiometer() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::extension::CCControlPotentiometer*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x35a6a0, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::extension::CCControlPotentiometer(geode::CutoffConstructor, sizeof(cocos2d::extension::CCControlPotentiometer));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::extension::CCControlPotentiometer::create(char const* p0, char const* p1, char const* p2) -> decltype(create(p0, p1, p2)) {
	using FunctionType = decltype(create(p0, p1, p2))(*)(char const*, char const*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x35a9d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

auto cocos2d::extension::CCControlPotentiometer::setEnabled(bool p0) -> decltype(setEnabled(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::extension::CCControlPotentiometer::setEnabled), this);
	using FunctionType = decltype(setEnabled(p0))(*)(cocos2d::extension::CCControlPotentiometer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x35ad10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCControlPotentiometer::isTouchInside(cocos2d::CCTouch* p0) -> decltype(isTouchInside(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*>::func(&cocos2d::extension::CCControlPotentiometer::isTouchInside), this);
	using FunctionType = decltype(isTouchInside(p0))(*)(cocos2d::extension::CCControlPotentiometer*, cocos2d::CCTouch*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x35aee0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCControlPotentiometer::ccTouchBegan(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) -> decltype(ccTouchBegan(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&cocos2d::extension::CCControlPotentiometer::ccTouchBegan), this);
	using FunctionType = decltype(ccTouchBegan(p0, p1))(*)(cocos2d::extension::CCControlPotentiometer*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x35b010, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::extension::CCControlPotentiometer::ccTouchMoved(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) -> decltype(ccTouchMoved(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&cocos2d::extension::CCControlPotentiometer::ccTouchMoved), this);
	using FunctionType = decltype(ccTouchMoved(p0, p1))(*)(cocos2d::extension::CCControlPotentiometer*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x35b1d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::extension::CCControlPotentiometer::ccTouchEnded(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) -> decltype(ccTouchEnded(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&cocos2d::extension::CCControlPotentiometer::ccTouchEnded), this);
	using FunctionType = decltype(ccTouchEnded(p0, p1))(*)(cocos2d::extension::CCControlPotentiometer*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x35b430, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::extension::CCControlPotentiometer::angleInDegreesBetweenLineFromPoint_toPoint_toLineFromPoint_toPoint(cocos2d::CCPoint p0, cocos2d::CCPoint p1, cocos2d::CCPoint p2, cocos2d::CCPoint p3) -> decltype(angleInDegreesBetweenLineFromPoint_toPoint_toLineFromPoint_toPoint(p0, p1, p2, p3)) {
	using FunctionType = decltype(angleInDegreesBetweenLineFromPoint_toPoint_toLineFromPoint_toPoint(p0, p1, p2, p3))(*)(cocos2d::extension::CCControlPotentiometer*, cocos2d::CCPoint, cocos2d::CCPoint, cocos2d::CCPoint, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x35b520, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3);
}

auto cocos2d::extension::CCControlPotentiometer::distanceBetweenPointAndPoint(cocos2d::CCPoint p0, cocos2d::CCPoint p1) -> decltype(distanceBetweenPointAndPoint(p0, p1)) {
	using FunctionType = decltype(distanceBetweenPointAndPoint(p0, p1))(*)(cocos2d::extension::CCControlPotentiometer*, cocos2d::CCPoint, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x35afe0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::extension::CCControlPotentiometer::getMaximumValue() -> decltype(getMaximumValue()) {
	using FunctionType = decltype(getMaximumValue())(*)(cocos2d::extension::CCControlPotentiometer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x35aed0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::extension::CCControlPotentiometer::getMinimumValue() -> decltype(getMinimumValue()) {
	using FunctionType = decltype(getMinimumValue())(*)(cocos2d::extension::CCControlPotentiometer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x35ae10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::extension::CCControlPotentiometer::getValue() -> decltype(getValue()) {
	using FunctionType = decltype(getValue())(*)(cocos2d::extension::CCControlPotentiometer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x35ad60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::extension::CCControlPotentiometer::initWithTrackSprite_ProgressTimer_ThumbSprite(cocos2d::CCSprite* p0, cocos2d::CCProgressTimer* p1, cocos2d::CCSprite* p2) -> decltype(initWithTrackSprite_ProgressTimer_ThumbSprite(p0, p1, p2)) {
	using FunctionType = decltype(initWithTrackSprite_ProgressTimer_ThumbSprite(p0, p1, p2))(*)(cocos2d::extension::CCControlPotentiometer*, cocos2d::CCSprite*, cocos2d::CCProgressTimer*, cocos2d::CCSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x35ab10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto cocos2d::extension::CCControlPotentiometer::potentiometerBegan(cocos2d::CCPoint p0) -> decltype(potentiometerBegan(p0)) {
	using FunctionType = decltype(potentiometerBegan(p0))(*)(cocos2d::extension::CCControlPotentiometer*, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x35b0c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCControlPotentiometer::potentiometerEnded(cocos2d::CCPoint p0) -> decltype(potentiometerEnded(p0)) {
	using FunctionType = decltype(potentiometerEnded(p0))(*)(cocos2d::extension::CCControlPotentiometer*, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x35b480, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCControlPotentiometer::potentiometerMoved(cocos2d::CCPoint p0) -> decltype(potentiometerMoved(p0)) {
	using FunctionType = decltype(potentiometerMoved(p0))(*)(cocos2d::extension::CCControlPotentiometer*, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x35b220, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCControlPotentiometer::setMaximumValue(float p0) -> decltype(setMaximumValue(p0)) {
	using FunctionType = decltype(setMaximumValue(p0))(*)(cocos2d::extension::CCControlPotentiometer*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x35ae20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCControlPotentiometer::setMinimumValue(float p0) -> decltype(setMinimumValue(p0)) {
	using FunctionType = decltype(setMinimumValue(p0))(*)(cocos2d::extension::CCControlPotentiometer*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x35ad70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCControlPotentiometer::setValue(float p0) -> decltype(setValue(p0)) {
	using FunctionType = decltype(setValue(p0))(*)(cocos2d::extension::CCControlPotentiometer*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x35ac80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
