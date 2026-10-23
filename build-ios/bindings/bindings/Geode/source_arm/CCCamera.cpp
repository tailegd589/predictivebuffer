
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCCamera.hpp>
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

cocos2d::CCCamera::CCCamera() : cocos2d::CCCamera(geode::CutoffConstructor, sizeof(cocos2d::CCCamera)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCCamera::~CCCamera();

	using FunctionType = void(*)(cocos2d::CCCamera*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b50c8, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCCamera::~CCCamera() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCCamera*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x4b5138, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCCamera(geode::CutoffConstructor, sizeof(cocos2d::CCCamera));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCCamera::getZEye() -> decltype(getZEye()) {
	using FunctionType = decltype(getZEye())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b51dc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCCamera::description() -> decltype(description()) {
	using FunctionType = decltype(description())(*)(cocos2d::CCCamera*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b5154, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCCamera::getCenterXYZ(float* p0, float* p1, float* p2) -> decltype(getCenterXYZ(p0, p1, p2)) {
	using FunctionType = decltype(getCenterXYZ(p0, p1, p2))(*)(cocos2d::CCCamera*, float*, float*, float*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b52bc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto cocos2d::CCCamera::getEyeXYZ(float* p0, float* p1, float* p2) -> decltype(getEyeXYZ(p0, p1, p2)) {
	using FunctionType = decltype(getEyeXYZ(p0, p1, p2))(*)(cocos2d::CCCamera*, float*, float*, float*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b52a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto cocos2d::CCCamera::getUpXYZ(float* p0, float* p1, float* p2) -> decltype(getUpXYZ(p0, p1, p2)) {
	using FunctionType = decltype(getUpXYZ(p0, p1, p2))(*)(cocos2d::CCCamera*, float*, float*, float*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b52d8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto cocos2d::CCCamera::init() -> decltype(init()) {
	using FunctionType = decltype(init())(*)(cocos2d::CCCamera*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b5080, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCCamera::locate() -> decltype(locate()) {
	using FunctionType = decltype(locate())(*)(cocos2d::CCCamera*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b51e4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCCamera::restore() -> decltype(restore()) {
	using FunctionType = decltype(restore())(*)(cocos2d::CCCamera*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b5194, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCCamera::setCenterXYZ(float p0, float p1, float p2) -> decltype(setCenterXYZ(p0, p1, p2)) {
	using FunctionType = decltype(setCenterXYZ(p0, p1, p2))(*)(cocos2d::CCCamera*, float, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b5278, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto cocos2d::CCCamera::setEyeXYZ(float p0, float p1, float p2) -> decltype(setEyeXYZ(p0, p1, p2)) {
	using FunctionType = decltype(setEyeXYZ(p0, p1, p2))(*)(cocos2d::CCCamera*, float, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b5264, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto cocos2d::CCCamera::setUpXYZ(float p0, float p1, float p2) -> decltype(setUpXYZ(p0, p1, p2)) {
	using FunctionType = decltype(setUpXYZ(p0, p1, p2))(*)(cocos2d::CCCamera*, float, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b528c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}
