
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCMotionStreak.hpp>
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

cocos2d::CCMotionStreak::CCMotionStreak() : cocos2d::CCMotionStreak(geode::CutoffConstructor, sizeof(cocos2d::CCMotionStreak)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCMotionStreak::~CCMotionStreak();

	using FunctionType = void(*)(cocos2d::CCMotionStreak*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x576060, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCMotionStreak::~CCMotionStreak() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCMotionStreak*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x576200, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCMotionStreak(geode::CutoffConstructor, sizeof(cocos2d::CCMotionStreak));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCMotionStreak::create(float p0, float p1, float p2, cocos2d::ccColor3B const& p3, char const* p4) -> decltype(create(p0, p1, p2, p3, p4)) {
	using FunctionType = decltype(create(p0, p1, p2, p3, p4))(*)(float, float, float, cocos2d::ccColor3B const&, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x576320, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3, p4);
}

auto cocos2d::CCMotionStreak::create(float p0, float p1, float p2, cocos2d::ccColor3B const& p3, cocos2d::CCTexture2D* p4) -> decltype(create(p0, p1, p2, p3, p4)) {
	using FunctionType = decltype(create(p0, p1, p2, p3, p4))(*)(float, float, float, cocos2d::ccColor3B const&, cocos2d::CCTexture2D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5764e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3, p4);
}

auto cocos2d::CCMotionStreak::update(float p0) -> decltype(update(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCMotionStreak::update), this);
	using FunctionType = decltype(update(p0))(*)(cocos2d::CCMotionStreak*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x576a90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCMotionStreak::setPosition(cocos2d::CCPoint const& p0) -> decltype(setPosition(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCPoint const&>::func(&cocos2d::CCMotionStreak::setPosition), this);
	using FunctionType = decltype(setPosition(p0))(*)(cocos2d::CCMotionStreak*, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5767f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCMotionStreak::draw() -> decltype(draw()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCMotionStreak::draw), this);
	using FunctionType = decltype(draw())(*)(cocos2d::CCMotionStreak*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x577140, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCMotionStreak::getOpacity() -> decltype(getOpacity()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCMotionStreak::getOpacity), this);
	using FunctionType = decltype(getOpacity())(*)(cocos2d::CCMotionStreak*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5769a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCMotionStreak::setOpacity(unsigned char p0) -> decltype(setOpacity(p0)) {
	auto self = addresser::thunkAdjust(Resolve<unsigned char>::func(&cocos2d::CCMotionStreak::setOpacity), this);
	using FunctionType = decltype(setOpacity(p0))(*)(cocos2d::CCMotionStreak*, unsigned char);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x576980, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCMotionStreak::setOpacityModifyRGB(bool p0) -> decltype(setOpacityModifyRGB(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::CCMotionStreak::setOpacityModifyRGB), this);
	using FunctionType = decltype(setOpacityModifyRGB(p0))(*)(cocos2d::CCMotionStreak*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5769c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCMotionStreak::isOpacityModifyRGB() -> decltype(isOpacityModifyRGB()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCMotionStreak::isOpacityModifyRGB), this);
	using FunctionType = decltype(isOpacityModifyRGB())(*)(cocos2d::CCMotionStreak*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5769e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCMotionStreak::setBlendFunc(cocos2d::ccBlendFunc p0) -> decltype(setBlendFunc(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::ccBlendFunc>::func(&cocos2d::CCMotionStreak::setBlendFunc), this);
	using FunctionType = decltype(setBlendFunc(p0))(*)(cocos2d::CCMotionStreak*, cocos2d::ccBlendFunc);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x576940, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCMotionStreak::getBlendFunc() -> decltype(getBlendFunc()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCMotionStreak::getBlendFunc), this);
	using FunctionType = decltype(getBlendFunc())(*)(cocos2d::CCMotionStreak*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x576960, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCMotionStreak::getTexture() -> decltype(getTexture()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCMotionStreak::getTexture), this);
	using FunctionType = decltype(getTexture())(*)(cocos2d::CCMotionStreak*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x576890, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCMotionStreak::setTexture(cocos2d::CCTexture2D* p0) -> decltype(setTexture(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTexture2D*>::func(&cocos2d::CCMotionStreak::setTexture), this);
	using FunctionType = decltype(setTexture(p0))(*)(cocos2d::CCMotionStreak*, cocos2d::CCTexture2D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5768b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCMotionStreak::enableRepeatMode(float p0) -> decltype(enableRepeatMode(p0)) {
	using FunctionType = decltype(enableRepeatMode(p0))(*)(cocos2d::CCMotionStreak*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x576a00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCMotionStreak::initWithFade(float p0, float p1, float p2, cocos2d::ccColor3B const& p3, char const* p4) -> decltype(initWithFade(p0, p1, p2, p3, p4)) {
	using FunctionType = decltype(initWithFade(p0, p1, p2, p3, p4))(*)(cocos2d::CCMotionStreak*, float, float, float, cocos2d::ccColor3B const&, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x576470, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4);
}

auto cocos2d::CCMotionStreak::initWithFade(float p0, float p1, float p2, cocos2d::ccColor3B const& p3, cocos2d::CCTexture2D* p4) -> decltype(initWithFade(p0, p1, p2, p3, p4)) {
	using FunctionType = decltype(initWithFade(p0, p1, p2, p3, p4))(*)(cocos2d::CCMotionStreak*, float, float, float, cocos2d::ccColor3B const&, cocos2d::CCTexture2D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x576620, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4);
}

auto cocos2d::CCMotionStreak::reset() -> decltype(reset()) {
	using FunctionType = decltype(reset())(*)(cocos2d::CCMotionStreak*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x577120, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCMotionStreak::resumeStroke() -> decltype(resumeStroke()) {
	using FunctionType = decltype(resumeStroke())(*)(cocos2d::CCMotionStreak*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x576a80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCMotionStreak::setStroke(float p0) -> decltype(setStroke(p0)) {
	using FunctionType = decltype(setStroke(p0))(*)(cocos2d::CCMotionStreak*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x577110, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCMotionStreak::stopStroke() -> decltype(stopStroke()) {
	using FunctionType = decltype(stopStroke())(*)(cocos2d::CCMotionStreak*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x576a70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCMotionStreak::tintWithColor(cocos2d::ccColor3B p0) -> decltype(tintWithColor(p0)) {
	using FunctionType = decltype(tintWithColor(p0))(*)(cocos2d::CCMotionStreak*, cocos2d::ccColor3B);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x576810, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCMotionStreak::updateFade(float p0) -> decltype(updateFade(p0)) {
	using FunctionType = decltype(updateFade(p0))(*)(cocos2d::CCMotionStreak*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x576a50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
