
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCShaderCache.hpp>
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

cocos2d::CCShaderCache::CCShaderCache() : cocos2d::CCShaderCache(geode::CutoffConstructor, sizeof(cocos2d::CCShaderCache)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCShaderCache::~CCShaderCache();

	using FunctionType = void(*)(cocos2d::CCShaderCache*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1af0a0, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCShaderCache::~CCShaderCache() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCShaderCache*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x1af0c4, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCShaderCache(geode::CutoffConstructor, sizeof(cocos2d::CCShaderCache));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCShaderCache::purgeSharedShaderCache() -> decltype(purgeSharedShaderCache()) {
	using FunctionType = decltype(purgeSharedShaderCache())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1af074, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCShaderCache::sharedShaderCache() -> decltype(sharedShaderCache()) {
	using FunctionType = decltype(sharedShaderCache())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1aef54, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCShaderCache::addProgram(cocos2d::CCGLProgram* p0, char const* p1) -> decltype(addProgram(p0, p1)) {
	using FunctionType = decltype(addProgram(p0, p1))(*)(cocos2d::CCShaderCache*, cocos2d::CCGLProgram*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1afff0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCShaderCache::init() -> decltype(init()) {
	using FunctionType = decltype(init())(*)(cocos2d::CCShaderCache*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1af024, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCShaderCache::loadDefaultShader(cocos2d::CCGLProgram* p0, int p1) -> decltype(loadDefaultShader(p0, p1)) {
	using FunctionType = decltype(loadDefaultShader(p0, p1))(*)(cocos2d::CCShaderCache*, cocos2d::CCGLProgram*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1af900, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCShaderCache::loadDefaultShaders() -> decltype(loadDefaultShaders()) {
	using FunctionType = decltype(loadDefaultShaders())(*)(cocos2d::CCShaderCache*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1af170, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCShaderCache::programForKey(char const* p0) -> decltype(programForKey(p0)) {
	using FunctionType = decltype(programForKey(p0))(*)(cocos2d::CCShaderCache*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1afeec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCShaderCache::reloadDefaultShaders() -> decltype(reloadDefaultShaders()) {
	using FunctionType = decltype(reloadDefaultShaders())(*)(cocos2d::CCShaderCache*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1afb44, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
