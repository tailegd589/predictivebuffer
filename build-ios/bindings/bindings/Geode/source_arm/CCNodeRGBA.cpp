
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCNodeRGBA.hpp>
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

cocos2d::CCNodeRGBA::CCNodeRGBA() : cocos2d::CCNodeRGBA(geode::CutoffConstructor, sizeof(cocos2d::CCNodeRGBA)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCNodeRGBA::~CCNodeRGBA();

	using FunctionType = void(*)(cocos2d::CCNodeRGBA*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x217718, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCNodeRGBA::~CCNodeRGBA() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCNodeRGBA*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x217778, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCNodeRGBA(geode::CutoffConstructor, sizeof(cocos2d::CCNodeRGBA));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCNodeRGBA::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2177a8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCNodeRGBA::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCNodeRGBA::init), this);
	using FunctionType = decltype(init())(*)(cocos2d::CCNodeRGBA*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x217794, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCNodeRGBA::setColor(cocos2d::ccColor3B const& p0) -> decltype(setColor(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::ccColor3B const&>::func(&cocos2d::CCNodeRGBA::setColor), this);
	using FunctionType = decltype(setColor(p0))(*)(cocos2d::CCNodeRGBA*, cocos2d::ccColor3B const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x217b70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCNodeRGBA::getColor() -> decltype(getColor()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCNodeRGBA::getColor), this);
	using FunctionType = decltype(getColor())(*)(cocos2d::CCNodeRGBA*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x217b50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCNodeRGBA::getDisplayedColor() -> decltype(getDisplayedColor()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCNodeRGBA::getDisplayedColor), this);
	using FunctionType = decltype(getDisplayedColor())(*)(cocos2d::CCNodeRGBA*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x217b60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCNodeRGBA::getDisplayedOpacity() -> decltype(getDisplayedOpacity()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCNodeRGBA::getDisplayedOpacity), this);
	using FunctionType = decltype(getDisplayedOpacity())(*)(cocos2d::CCNodeRGBA*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x21781c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCNodeRGBA::getOpacity() -> decltype(getOpacity()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCNodeRGBA::getOpacity), this);
	using FunctionType = decltype(getOpacity())(*)(cocos2d::CCNodeRGBA*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x21780c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCNodeRGBA::setOpacity(unsigned char p0) -> decltype(setOpacity(p0)) {
	auto self = addresser::thunkAdjust(Resolve<unsigned char>::func(&cocos2d::CCNodeRGBA::setOpacity), this);
	using FunctionType = decltype(setOpacity(p0))(*)(cocos2d::CCNodeRGBA*, unsigned char);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x21782c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCNodeRGBA::isCascadeColorEnabled() -> decltype(isCascadeColorEnabled()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCNodeRGBA::isCascadeColorEnabled), this);
	using FunctionType = decltype(isCascadeColorEnabled())(*)(cocos2d::CCNodeRGBA*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x217e14, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCNodeRGBA::setCascadeColorEnabled(bool p0) -> decltype(setCascadeColorEnabled(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::CCNodeRGBA::setCascadeColorEnabled), this);
	using FunctionType = decltype(setCascadeColorEnabled(p0))(*)(cocos2d::CCNodeRGBA*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x217e24, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCNodeRGBA::updateDisplayedColor(cocos2d::ccColor3B const& p0) -> decltype(updateDisplayedColor(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::ccColor3B const&>::func(&cocos2d::CCNodeRGBA::updateDisplayedColor), this);
	using FunctionType = decltype(updateDisplayedColor(p0))(*)(cocos2d::CCNodeRGBA*, cocos2d::ccColor3B const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x217d04, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCNodeRGBA::isCascadeOpacityEnabled() -> decltype(isCascadeOpacityEnabled()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCNodeRGBA::isCascadeOpacityEnabled), this);
	using FunctionType = decltype(isCascadeOpacityEnabled())(*)(cocos2d::CCNodeRGBA*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x217b30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCNodeRGBA::setCascadeOpacityEnabled(bool p0) -> decltype(setCascadeOpacityEnabled(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::CCNodeRGBA::setCascadeOpacityEnabled), this);
	using FunctionType = decltype(setCascadeOpacityEnabled(p0))(*)(cocos2d::CCNodeRGBA*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x217b40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCNodeRGBA::updateDisplayedOpacity(unsigned char p0) -> decltype(updateDisplayedOpacity(p0)) {
	auto self = addresser::thunkAdjust(Resolve<unsigned char>::func(&cocos2d::CCNodeRGBA::updateDisplayedOpacity), this);
	using FunctionType = decltype(updateDisplayedOpacity(p0))(*)(cocos2d::CCNodeRGBA*, unsigned char);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x217998, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}
