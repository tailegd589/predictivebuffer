
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCLayerMultiplex.hpp>
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

cocos2d::CCLayerMultiplex::CCLayerMultiplex() : cocos2d::CCLayerMultiplex(geode::CutoffConstructor, sizeof(cocos2d::CCLayerMultiplex)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCLayerMultiplex::~CCLayerMultiplex();

	using FunctionType = void(*)(cocos2d::CCLayerMultiplex*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b41b0, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCLayerMultiplex::~CCLayerMultiplex() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCLayerMultiplex*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x4b42f0, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCLayerMultiplex(geode::CutoffConstructor, sizeof(cocos2d::CCLayerMultiplex));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCLayerMultiplex::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b4810, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCLayerMultiplex::createWithArray(cocos2d::CCArray* p0) -> decltype(createWithArray(p0)) {
	using FunctionType = decltype(createWithArray(p0))(*)(cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b49c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::CCLayerMultiplex::createWithLayer(cocos2d::CCLayer* p0) -> decltype(createWithLayer(p0)) {
	using FunctionType = decltype(createWithLayer(p0))(*)(cocos2d::CCLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b4800, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::CCLayerMultiplex::addLayer(cocos2d::CCLayer* p0) -> decltype(addLayer(p0)) {
	using FunctionType = decltype(addLayer(p0))(*)(cocos2d::CCLayerMultiplex*, cocos2d::CCLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b4c10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCLayerMultiplex::initWithArray(cocos2d::CCArray* p0) -> decltype(initWithArray(p0)) {
	using FunctionType = decltype(initWithArray(p0))(*)(cocos2d::CCLayerMultiplex*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b4b50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCLayerMultiplex::initWithLayers(cocos2d::CCLayer* p0, va_list p1) -> decltype(initWithLayers(p0, p1)) {
	using FunctionType = decltype(initWithLayers(p0, p1))(*)(cocos2d::CCLayerMultiplex*, cocos2d::CCLayer*, va_list);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b46e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCLayerMultiplex::switchTo(unsigned int p0) -> decltype(switchTo(p0)) {
	using FunctionType = decltype(switchTo(p0))(*)(cocos2d::CCLayerMultiplex*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b4c30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCLayerMultiplex::switchToAndReleaseMe(unsigned int p0) -> decltype(switchToAndReleaseMe(p0)) {
	using FunctionType = decltype(switchToAndReleaseMe(p0))(*)(cocos2d::CCLayerMultiplex*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b4ca0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
