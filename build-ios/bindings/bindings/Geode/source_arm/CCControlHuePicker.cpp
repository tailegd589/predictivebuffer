
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCControlHuePicker.hpp>
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

cocos2d::extension::CCControlHuePicker::CCControlHuePicker() : cocos2d::extension::CCControlHuePicker(geode::CutoffConstructor, sizeof(cocos2d::extension::CCControlHuePicker)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::extension::CCControlHuePicker::~CCControlHuePicker();

	using FunctionType = void(*)(cocos2d::extension::CCControlHuePicker*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e2a6c, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::extension::CCControlHuePicker::~CCControlHuePicker() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::extension::CCControlHuePicker*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x2e2b64, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::extension::CCControlHuePicker(geode::CutoffConstructor, sizeof(cocos2d::extension::CCControlHuePicker));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::extension::CCControlHuePicker::create(cocos2d::CCNode* p0, cocos2d::CCPoint p1) -> decltype(create(p0, p1)) {
	using FunctionType = decltype(create(p0, p1))(*)(cocos2d::CCNode*, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e2d58, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::extension::CCControlHuePicker::ccTouchBegan(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) -> decltype(ccTouchBegan(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&cocos2d::extension::CCControlHuePicker::ccTouchBegan), this);
	using FunctionType = decltype(ccTouchBegan(p0, p1))(*)(cocos2d::extension::CCControlHuePicker*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e32a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::extension::CCControlHuePicker::ccTouchMoved(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) -> decltype(ccTouchMoved(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&cocos2d::extension::CCControlHuePicker::ccTouchMoved), this);
	using FunctionType = decltype(ccTouchMoved(p0, p1))(*)(cocos2d::extension::CCControlHuePicker*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e33a4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::extension::CCControlHuePicker::setEnabled(bool p0) -> decltype(setEnabled(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::extension::CCControlHuePicker::setEnabled), this);
	using FunctionType = decltype(setEnabled(p0))(*)(cocos2d::extension::CCControlHuePicker*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e30d4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCControlHuePicker::initWithTargetAndPos(cocos2d::CCNode* p0, cocos2d::CCPoint p1) -> decltype(initWithTargetAndPos(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*, cocos2d::CCPoint>::func(&cocos2d::extension::CCControlHuePicker::initWithTargetAndPos), this);
	using FunctionType = decltype(initWithTargetAndPos(p0, p1))(*)(cocos2d::extension::CCControlHuePicker*, cocos2d::CCNode*, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e2e38, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::extension::CCControlHuePicker::setHue(float p0) -> decltype(setHue(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::extension::CCControlHuePicker::setHue), this);
	using FunctionType = decltype(setHue(p0))(*)(cocos2d::extension::CCControlHuePicker*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e2ff4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCControlHuePicker::setHuePercentage(float p0) -> decltype(setHuePercentage(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::extension::CCControlHuePicker::setHuePercentage), this);
	using FunctionType = decltype(setHuePercentage(p0))(*)(cocos2d::extension::CCControlHuePicker*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e3010, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCControlHuePicker::registerWithTouchDispatcher() -> decltype(registerWithTouchDispatcher()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::extension::CCControlHuePicker::registerWithTouchDispatcher), this);
	using FunctionType = decltype(registerWithTouchDispatcher())(*)(cocos2d::extension::CCControlHuePicker*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e2fbc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::extension::CCControlHuePicker::checkSliderPosition(cocos2d::CCPoint p0) -> decltype(checkSliderPosition(p0)) {
	using FunctionType = decltype(checkSliderPosition(p0))(*)(cocos2d::extension::CCControlHuePicker*, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e31bc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCControlHuePicker::updateSliderPosition(cocos2d::CCPoint p0) -> decltype(updateSliderPosition(p0)) {
	using FunctionType = decltype(updateSliderPosition(p0))(*)(cocos2d::extension::CCControlHuePicker*, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2e3124, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
