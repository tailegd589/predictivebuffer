
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCAutoreleasePool.hpp>
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

cocos2d::CCAutoreleasePool::CCAutoreleasePool() : cocos2d::CCAutoreleasePool(geode::CutoffConstructor, sizeof(cocos2d::CCAutoreleasePool)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCAutoreleasePool::~CCAutoreleasePool();

	using FunctionType = void(*)(cocos2d::CCAutoreleasePool*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x36f4d8, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCAutoreleasePool::~CCAutoreleasePool() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCAutoreleasePool*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x36f55c, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCAutoreleasePool(geode::CutoffConstructor, sizeof(cocos2d::CCAutoreleasePool));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCAutoreleasePool::addObject(cocos2d::CCObject* p0) -> decltype(addObject(p0)) {
	using FunctionType = decltype(addObject(p0))(*)(cocos2d::CCAutoreleasePool*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x36f634, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCAutoreleasePool::clear() -> decltype(clear()) {
	using FunctionType = decltype(clear())(*)(cocos2d::CCAutoreleasePool*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x36f6bc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCAutoreleasePool::removeObject(cocos2d::CCObject* p0) -> decltype(removeObject(p0)) {
	using FunctionType = decltype(removeObject(p0))(*)(cocos2d::CCAutoreleasePool*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x36f668, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
