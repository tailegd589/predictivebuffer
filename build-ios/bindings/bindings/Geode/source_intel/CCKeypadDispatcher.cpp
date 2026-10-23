
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCKeypadDispatcher.hpp>
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

cocos2d::CCKeypadDispatcher::CCKeypadDispatcher() : cocos2d::CCKeypadDispatcher(geode::CutoffConstructor, sizeof(cocos2d::CCKeypadDispatcher)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCKeypadDispatcher::~CCKeypadDispatcher();

	using FunctionType = void(*)(cocos2d::CCKeypadDispatcher*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f9420, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCKeypadDispatcher::~CCKeypadDispatcher() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCKeypadDispatcher*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x5f9490, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCKeypadDispatcher(geode::CutoffConstructor, sizeof(cocos2d::CCKeypadDispatcher));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCKeypadDispatcher::addDelegate(cocos2d::CCKeypadDelegate* p0) -> decltype(addDelegate(p0)) {
	using FunctionType = decltype(addDelegate(p0))(*)(cocos2d::CCKeypadDispatcher*, cocos2d::CCKeypadDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f96f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCKeypadDispatcher::dispatchKeypadMSG(cocos2d::ccKeypadMSGType p0) -> decltype(dispatchKeypadMSG(p0)) {
	using FunctionType = decltype(dispatchKeypadMSG(p0))(*)(cocos2d::CCKeypadDispatcher*, cocos2d::ccKeypadMSGType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f9770, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCKeypadDispatcher::forceAddDelegate(cocos2d::CCKeypadDelegate* p0) -> decltype(forceAddDelegate(p0)) {
	using FunctionType = decltype(forceAddDelegate(p0))(*)(cocos2d::CCKeypadDispatcher*, cocos2d::CCKeypadDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f9740, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCKeypadDispatcher::forceRemoveDelegate(cocos2d::CCKeypadDelegate* p0) -> decltype(forceRemoveDelegate(p0)) {
	using FunctionType = decltype(forceRemoveDelegate(p0))(*)(cocos2d::CCKeypadDispatcher*, cocos2d::CCKeypadDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f9660, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCKeypadDispatcher::removeDelegate(cocos2d::CCKeypadDelegate* p0) -> decltype(removeDelegate(p0)) {
	using FunctionType = decltype(removeDelegate(p0))(*)(cocos2d::CCKeypadDispatcher*, cocos2d::CCKeypadDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f95b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
