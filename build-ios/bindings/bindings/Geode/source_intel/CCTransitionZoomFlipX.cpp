
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCTransitionZoomFlipX.hpp>
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

cocos2d::CCTransitionZoomFlipX::CCTransitionZoomFlipX() : cocos2d::CCTransitionZoomFlipX(geode::CutoffConstructor, sizeof(cocos2d::CCTransitionZoomFlipX)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCTransitionZoomFlipX::~CCTransitionZoomFlipX();

	using FunctionType = void(*)(cocos2d::CCTransitionZoomFlipX*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd7b30, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCTransitionZoomFlipX::~CCTransitionZoomFlipX() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCTransitionZoomFlipX*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0xd7b70, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCTransitionZoomFlipX(geode::CutoffConstructor, sizeof(cocos2d::CCTransitionZoomFlipX));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCTransitionZoomFlipX::create(float p0, cocos2d::CCScene* p1) -> decltype(create(p0, p1)) {
	using FunctionType = decltype(create(p0, p1))(*)(float, cocos2d::CCScene*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd7ef0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCTransitionZoomFlipX::create(float p0, cocos2d::CCScene* p1, cocos2d::tOrientation p2) -> decltype(create(p0, p1, p2)) {
	using FunctionType = decltype(create(p0, p1, p2))(*)(float, cocos2d::CCScene*, cocos2d::tOrientation);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd7e70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

auto cocos2d::CCTransitionZoomFlipX::onEnter() -> decltype(onEnter()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTransitionZoomFlipX::onEnter), this);
	using FunctionType = decltype(onEnter())(*)(cocos2d::CCTransitionZoomFlipX*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd7c60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}
