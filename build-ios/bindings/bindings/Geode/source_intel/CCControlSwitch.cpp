
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCControlSwitch.hpp>
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

cocos2d::extension::CCControlSwitch::CCControlSwitch() : cocos2d::extension::CCControlSwitch(geode::CutoffConstructor, sizeof(cocos2d::extension::CCControlSwitch)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::extension::CCControlSwitch::~CCControlSwitch();

	using FunctionType = void(*)(cocos2d::extension::CCControlSwitch*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3a8340, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::extension::CCControlSwitch::~CCControlSwitch() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::extension::CCControlSwitch*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x3a83d0, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::extension::CCControlSwitch(geode::CutoffConstructor, sizeof(cocos2d::extension::CCControlSwitch));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::extension::CCControlSwitch::create(cocos2d::CCSprite* p0, cocos2d::CCSprite* p1, cocos2d::CCSprite* p2, cocos2d::CCSprite* p3) -> decltype(create(p0, p1, p2, p3)) {
	using FunctionType = decltype(create(p0, p1, p2, p3))(*)(cocos2d::CCSprite*, cocos2d::CCSprite*, cocos2d::CCSprite*, cocos2d::CCSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3a88c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3);
}

auto cocos2d::extension::CCControlSwitch::create(cocos2d::CCSprite* p0, cocos2d::CCSprite* p1, cocos2d::CCSprite* p2, cocos2d::CCSprite* p3, cocos2d::CCLabelTTF* p4, cocos2d::CCLabelTTF* p5) -> decltype(create(p0, p1, p2, p3, p4, p5)) {
	using FunctionType = decltype(create(p0, p1, p2, p3, p4, p5))(*)(cocos2d::CCSprite*, cocos2d::CCSprite*, cocos2d::CCSprite*, cocos2d::CCSprite*, cocos2d::CCLabelTTF*, cocos2d::CCLabelTTF*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3a89c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3, p4, p5);
}

auto cocos2d::extension::CCControlSwitch::setEnabled(bool p0) -> decltype(setEnabled(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::extension::CCControlSwitch::setEnabled), this);
	using FunctionType = decltype(setEnabled(p0))(*)(cocos2d::extension::CCControlSwitch*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3a8c00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::extension::CCControlSwitch::ccTouchBegan(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) -> decltype(ccTouchBegan(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&cocos2d::extension::CCControlSwitch::ccTouchBegan), this);
	using FunctionType = decltype(ccTouchBegan(p0, p1))(*)(cocos2d::extension::CCControlSwitch*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3a8c90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::extension::CCControlSwitch::ccTouchMoved(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) -> decltype(ccTouchMoved(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&cocos2d::extension::CCControlSwitch::ccTouchMoved), this);
	using FunctionType = decltype(ccTouchMoved(p0, p1))(*)(cocos2d::extension::CCControlSwitch*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3a8d80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::extension::CCControlSwitch::ccTouchEnded(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) -> decltype(ccTouchEnded(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&cocos2d::extension::CCControlSwitch::ccTouchEnded), this);
	using FunctionType = decltype(ccTouchEnded(p0, p1))(*)(cocos2d::extension::CCControlSwitch*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3a8e50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::extension::CCControlSwitch::ccTouchCancelled(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) -> decltype(ccTouchCancelled(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&cocos2d::extension::CCControlSwitch::ccTouchCancelled), this);
	using FunctionType = decltype(ccTouchCancelled(p0, p1))(*)(cocos2d::extension::CCControlSwitch*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3a8f80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::extension::CCControlSwitch::initWithMaskSprite(cocos2d::CCSprite* p0, cocos2d::CCSprite* p1, cocos2d::CCSprite* p2, cocos2d::CCSprite* p3) -> decltype(initWithMaskSprite(p0, p1, p2, p3)) {
	using FunctionType = decltype(initWithMaskSprite(p0, p1, p2, p3))(*)(cocos2d::extension::CCControlSwitch*, cocos2d::CCSprite*, cocos2d::CCSprite*, cocos2d::CCSprite*, cocos2d::CCSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3a86b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3);
}

auto cocos2d::extension::CCControlSwitch::initWithMaskSprite(cocos2d::CCSprite* p0, cocos2d::CCSprite* p1, cocos2d::CCSprite* p2, cocos2d::CCSprite* p3, cocos2d::CCLabelTTF* p4, cocos2d::CCLabelTTF* p5) -> decltype(initWithMaskSprite(p0, p1, p2, p3, p4, p5)) {
	using FunctionType = decltype(initWithMaskSprite(p0, p1, p2, p3, p4, p5))(*)(cocos2d::extension::CCControlSwitch*, cocos2d::CCSprite*, cocos2d::CCSprite*, cocos2d::CCSprite*, cocos2d::CCSprite*, cocos2d::CCLabelTTF*, cocos2d::CCLabelTTF*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3a86d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5);
}

auto cocos2d::extension::CCControlSwitch::locationFromTouch(cocos2d::CCTouch* p0) -> decltype(locationFromTouch(p0)) {
	using FunctionType = decltype(locationFromTouch(p0))(*)(cocos2d::extension::CCControlSwitch*, cocos2d::CCTouch*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3a8c40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCControlSwitch::setOn(bool p0) -> decltype(setOn(p0)) {
	using FunctionType = decltype(setOn(p0))(*)(cocos2d::extension::CCControlSwitch*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3a8ad0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::extension::CCControlSwitch::setOn(bool p0, bool p1) -> decltype(setOn(p0, p1)) {
	using FunctionType = decltype(setOn(p0, p1))(*)(cocos2d::extension::CCControlSwitch*, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3a8b40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}
