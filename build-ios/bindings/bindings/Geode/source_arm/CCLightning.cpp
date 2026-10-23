
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCLightning.hpp>
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

cocos2d::CCLightning::CCLightning() : cocos2d::CCLightning(geode::CutoffConstructor, sizeof(cocos2d::CCLightning)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCLightning::~CCLightning();

	using FunctionType = void(*)(cocos2d::CCLightning*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x508aa8, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCLightning::~CCLightning() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCLightning*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x508bf8, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCLightning(geode::CutoffConstructor, sizeof(cocos2d::CCLightning));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCLightning::lightningWithStrikePoint(cocos2d::CCPoint p0) -> decltype(lightningWithStrikePoint(p0)) {
	using FunctionType = decltype(lightningWithStrikePoint(p0))(*)(cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x508cd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::CCLightning::lightningWithStrikePoint(cocos2d::CCPoint p0, cocos2d::CCPoint p1, float p2) -> decltype(lightningWithStrikePoint(p0, p1, p2)) {
	using FunctionType = decltype(lightningWithStrikePoint(p0, p1, p2))(*)(cocos2d::CCPoint, cocos2d::CCPoint, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x508e3c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

auto cocos2d::CCLightning::draw() -> decltype(draw()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLightning::draw), this);
	using FunctionType = decltype(draw())(*)(cocos2d::CCLightning*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5090ec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLightning::isOpacityModifyRGB() -> decltype(isOpacityModifyRGB()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLightning::isOpacityModifyRGB), this);
	using FunctionType = decltype(isOpacityModifyRGB())(*)(cocos2d::CCLightning*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x509364, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLightning::setOpacityModifyRGB(bool p0) -> decltype(setOpacityModifyRGB(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::CCLightning::setOpacityModifyRGB), this);
	using FunctionType = decltype(setOpacityModifyRGB(p0))(*)(cocos2d::CCLightning*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x509374, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLightning::getOpacity() -> decltype(getOpacity()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLightning::getOpacity), this);
	using FunctionType = decltype(getOpacity())(*)(cocos2d::CCLightning*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5092ec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLightning::getDisplayedOpacity() -> decltype(getDisplayedOpacity()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLightning::getDisplayedOpacity), this);
	using FunctionType = decltype(getDisplayedOpacity())(*)(cocos2d::CCLightning*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5092fc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLightning::setOpacity(unsigned char p0) -> decltype(setOpacity(p0)) {
	auto self = addresser::thunkAdjust(Resolve<unsigned char>::func(&cocos2d::CCLightning::setOpacity), this);
	using FunctionType = decltype(setOpacity(p0))(*)(cocos2d::CCLightning*, unsigned char);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x509318, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLightning::updateDisplayedOpacity(unsigned char p0) -> decltype(updateDisplayedOpacity(p0)) {
	auto self = addresser::thunkAdjust(Resolve<unsigned char>::func(&cocos2d::CCLightning::updateDisplayedOpacity), this);
	using FunctionType = decltype(updateDisplayedOpacity(p0))(*)(cocos2d::CCLightning*, unsigned char);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x509384, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLightning::isCascadeOpacityEnabled() -> decltype(isCascadeOpacityEnabled()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLightning::isCascadeOpacityEnabled), this);
	using FunctionType = decltype(isCascadeOpacityEnabled())(*)(cocos2d::CCLightning*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x509394, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLightning::setCascadeOpacityEnabled(bool p0) -> decltype(setCascadeOpacityEnabled(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::CCLightning::setCascadeOpacityEnabled), this);
	using FunctionType = decltype(setCascadeOpacityEnabled(p0))(*)(cocos2d::CCLightning*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5093a4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLightning::getColor() -> decltype(getColor()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLightning::getColor), this);
	using FunctionType = decltype(getColor())(*)(cocos2d::CCLightning*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x509328, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLightning::getDisplayedColor() -> decltype(getDisplayedColor()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLightning::getDisplayedColor), this);
	using FunctionType = decltype(getDisplayedColor())(*)(cocos2d::CCLightning*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5093b4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLightning::setColor(cocos2d::ccColor3B const& p0) -> decltype(setColor(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::ccColor3B const&>::func(&cocos2d::CCLightning::setColor), this);
	using FunctionType = decltype(setColor(p0))(*)(cocos2d::CCLightning*, cocos2d::ccColor3B const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x509338, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLightning::updateDisplayedColor(cocos2d::ccColor3B const& p0) -> decltype(updateDisplayedColor(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::ccColor3B const&>::func(&cocos2d::CCLightning::updateDisplayedColor), this);
	using FunctionType = decltype(updateDisplayedColor(p0))(*)(cocos2d::CCLightning*, cocos2d::ccColor3B const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5093c4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLightning::isCascadeColorEnabled() -> decltype(isCascadeColorEnabled()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLightning::isCascadeColorEnabled), this);
	using FunctionType = decltype(isCascadeColorEnabled())(*)(cocos2d::CCLightning*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5093ec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLightning::setCascadeColorEnabled(bool p0) -> decltype(setCascadeColorEnabled(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::CCLightning::setCascadeColorEnabled), this);
	using FunctionType = decltype(setCascadeColorEnabled(p0))(*)(cocos2d::CCLightning*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5093fc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLightning::initWithStrikePoint(cocos2d::CCPoint p0) -> decltype(initWithStrikePoint(p0)) {
	using FunctionType = decltype(initWithStrikePoint(p0))(*)(cocos2d::CCLightning*, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x508de8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCLightning::initWithStrikePoint(cocos2d::CCPoint p0, cocos2d::CCPoint p1, float p2) -> decltype(initWithStrikePoint(p0, p1, p2)) {
	using FunctionType = decltype(initWithStrikePoint(p0, p1, p2))(*)(cocos2d::CCLightning*, cocos2d::CCPoint, cocos2d::CCPoint, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x508f5c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto cocos2d::CCLightning::strike() -> decltype(strike()) {
	using FunctionType = decltype(strike())(*)(cocos2d::CCLightning*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x509080, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCLightning::strikeFinished() -> decltype(strikeFinished()) {
	using FunctionType = decltype(strikeFinished())(*)(cocos2d::CCLightning*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5092d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCLightning::strikeRandom() -> decltype(strikeRandom()) {
	using FunctionType = decltype(strikeRandom())(*)(cocos2d::CCLightning*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5091e8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCLightning::strikeWithSeed(uint64_t seed) -> decltype(strikeWithSeed(seed)) {
	using FunctionType = decltype(strikeWithSeed(seed))(*)(cocos2d::CCLightning*, uint64_t);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x509260, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, seed);
}
