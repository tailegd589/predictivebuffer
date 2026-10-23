
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCMouseDispatcher.hpp>
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

cocos2d::CCMouseDispatcher::CCMouseDispatcher() : cocos2d::CCMouseDispatcher(geode::CutoffConstructor, sizeof(cocos2d::CCMouseDispatcher)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCMouseDispatcher::~CCMouseDispatcher();

	using FunctionType = void(*)(cocos2d::CCMouseDispatcher*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4be920, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCMouseDispatcher::~CCMouseDispatcher() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCMouseDispatcher*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x4be990, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCMouseDispatcher(geode::CutoffConstructor, sizeof(cocos2d::CCMouseDispatcher));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCMouseDispatcher::addDelegate(cocos2d::CCMouseDelegate* p0) -> decltype(addDelegate(p0)) {
	using FunctionType = decltype(addDelegate(p0))(*)(cocos2d::CCMouseDispatcher*, cocos2d::CCMouseDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4bebec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCMouseDispatcher::dispatchScrollMSG(float p0, float p1) -> decltype(dispatchScrollMSG(p0, p1)) {
	using FunctionType = decltype(dispatchScrollMSG(p0, p1))(*)(cocos2d::CCMouseDispatcher*, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4bec84, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCMouseDispatcher::forceAddDelegate(cocos2d::CCMouseDelegate* p0) -> decltype(forceAddDelegate(p0)) {
	using FunctionType = decltype(forceAddDelegate(p0))(*)(cocos2d::CCMouseDispatcher*, cocos2d::CCMouseDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4bec48, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCMouseDispatcher::forceRemoveDelegate(cocos2d::CCMouseDelegate* p0) -> decltype(forceRemoveDelegate(p0)) {
	using FunctionType = decltype(forceRemoveDelegate(p0))(*)(cocos2d::CCMouseDispatcher*, cocos2d::CCMouseDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4beb58, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCMouseDispatcher::removeDelegate(cocos2d::CCMouseDelegate* p0) -> decltype(removeDelegate(p0)) {
	using FunctionType = decltype(removeDelegate(p0))(*)(cocos2d::CCMouseDispatcher*, cocos2d::CCMouseDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4bea90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
