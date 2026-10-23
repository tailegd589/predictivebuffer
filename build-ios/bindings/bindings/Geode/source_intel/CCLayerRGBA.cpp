
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCLayerRGBA.hpp>
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

cocos2d::CCLayerRGBA::CCLayerRGBA() : cocos2d::CCLayerRGBA(geode::CutoffConstructor, sizeof(cocos2d::CCLayerRGBA)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCLayerRGBA::~CCLayerRGBA();

	using FunctionType = void(*)(cocos2d::CCLayerRGBA*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b1510, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCLayerRGBA::~CCLayerRGBA() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCLayerRGBA*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x4b17b0, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCLayerRGBA(geode::CutoffConstructor, sizeof(cocos2d::CCLayerRGBA));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCLayerRGBA::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLayerRGBA::init), this);
	using FunctionType = decltype(init())(*)(cocos2d::CCLayerRGBA*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b1af0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLayerRGBA::setColor(cocos2d::ccColor3B const& p0) -> decltype(setColor(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::ccColor3B const&>::func(&cocos2d::CCLayerRGBA::setColor), this);
	using FunctionType = decltype(setColor(p0))(*)(cocos2d::CCLayerRGBA*, cocos2d::ccColor3B const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b1d30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLayerRGBA::getColor() -> decltype(getColor()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLayerRGBA::getColor), this);
	using FunctionType = decltype(getColor())(*)(cocos2d::CCLayerRGBA*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b1cf0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLayerRGBA::getDisplayedColor() -> decltype(getDisplayedColor()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLayerRGBA::getDisplayedColor), this);
	using FunctionType = decltype(getDisplayedColor())(*)(cocos2d::CCLayerRGBA*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b1d10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLayerRGBA::getDisplayedOpacity() -> decltype(getDisplayedOpacity()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLayerRGBA::getDisplayedOpacity), this);
	using FunctionType = decltype(getDisplayedOpacity())(*)(cocos2d::CCLayerRGBA*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b1b90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLayerRGBA::getOpacity() -> decltype(getOpacity()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLayerRGBA::getOpacity), this);
	using FunctionType = decltype(getOpacity())(*)(cocos2d::CCLayerRGBA*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b1b70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLayerRGBA::setOpacity(unsigned char p0) -> decltype(setOpacity(p0)) {
	auto self = addresser::thunkAdjust(Resolve<unsigned char>::func(&cocos2d::CCLayerRGBA::setOpacity), this);
	using FunctionType = decltype(setOpacity(p0))(*)(cocos2d::CCLayerRGBA*, unsigned char);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b1bb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLayerRGBA::isCascadeColorEnabled() -> decltype(isCascadeColorEnabled()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLayerRGBA::isCascadeColorEnabled), this);
	using FunctionType = decltype(isCascadeColorEnabled())(*)(cocos2d::CCLayerRGBA*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b2290, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLayerRGBA::setCascadeColorEnabled(bool p0) -> decltype(setCascadeColorEnabled(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::CCLayerRGBA::setCascadeColorEnabled), this);
	using FunctionType = decltype(setCascadeColorEnabled(p0))(*)(cocos2d::CCLayerRGBA*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b22b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLayerRGBA::updateDisplayedColor(cocos2d::ccColor3B const& p0) -> decltype(updateDisplayedColor(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::ccColor3B const&>::func(&cocos2d::CCLayerRGBA::updateDisplayedColor), this);
	using FunctionType = decltype(updateDisplayedColor(p0))(*)(cocos2d::CCLayerRGBA*, cocos2d::ccColor3B const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b2030, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLayerRGBA::isCascadeOpacityEnabled() -> decltype(isCascadeOpacityEnabled()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCLayerRGBA::isCascadeOpacityEnabled), this);
	using FunctionType = decltype(isCascadeOpacityEnabled())(*)(cocos2d::CCLayerRGBA*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b2250, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCLayerRGBA::setCascadeOpacityEnabled(bool p0) -> decltype(setCascadeOpacityEnabled(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::CCLayerRGBA::setCascadeOpacityEnabled), this);
	using FunctionType = decltype(setCascadeOpacityEnabled(p0))(*)(cocos2d::CCLayerRGBA*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b2270, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCLayerRGBA::updateDisplayedOpacity(unsigned char p0) -> decltype(updateDisplayedOpacity(p0)) {
	auto self = addresser::thunkAdjust(Resolve<unsigned char>::func(&cocos2d::CCLayerRGBA::updateDisplayedOpacity), this);
	using FunctionType = decltype(updateDisplayedOpacity(p0))(*)(cocos2d::CCLayerRGBA*, unsigned char);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b1eb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}
