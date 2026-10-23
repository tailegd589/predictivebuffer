
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCGrabber.hpp>
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

cocos2d::CCGrabber::CCGrabber() : cocos2d::CCGrabber(geode::CutoffConstructor, sizeof(cocos2d::CCGrabber)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCGrabber::~CCGrabber();

	using FunctionType = void(*)(cocos2d::CCGrabber*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x522cc8, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCGrabber::~CCGrabber() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCGrabber*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x522e18, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCGrabber(geode::CutoffConstructor, sizeof(cocos2d::CCGrabber));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCGrabber::afterRender(cocos2d::CCTexture2D* p0) -> decltype(afterRender(p0)) {
	using FunctionType = decltype(afterRender(p0))(*)(cocos2d::CCGrabber*, cocos2d::CCTexture2D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x522de8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCGrabber::beforeRender(cocos2d::CCTexture2D* p0) -> decltype(beforeRender(p0)) {
	using FunctionType = decltype(beforeRender(p0))(*)(cocos2d::CCGrabber*, cocos2d::CCTexture2D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x522d90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCGrabber::grab(cocos2d::CCTexture2D* p0) -> decltype(grab(p0)) {
	using FunctionType = decltype(grab(p0))(*)(cocos2d::CCGrabber*, cocos2d::CCTexture2D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x522d20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
