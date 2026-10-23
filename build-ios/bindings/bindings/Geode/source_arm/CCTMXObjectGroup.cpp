
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCTMXObjectGroup.hpp>
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

cocos2d::CCTMXObjectGroup::CCTMXObjectGroup() : cocos2d::CCTMXObjectGroup(geode::CutoffConstructor, sizeof(cocos2d::CCTMXObjectGroup)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCTMXObjectGroup::~CCTMXObjectGroup();

	using FunctionType = void(*)(cocos2d::CCTMXObjectGroup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4009d8, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCTMXObjectGroup::~CCTMXObjectGroup() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCTMXObjectGroup*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x400a8c, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCTMXObjectGroup(geode::CutoffConstructor, sizeof(cocos2d::CCTMXObjectGroup));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCTMXObjectGroup::getProperties() -> decltype(getProperties()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTMXObjectGroup::getProperties), this);
	using FunctionType = decltype(getProperties())(*)(cocos2d::CCTMXObjectGroup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x400e1c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTMXObjectGroup::setProperties(cocos2d::CCDictionary* p0) -> decltype(setProperties(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCDictionary*>::func(&cocos2d::CCTMXObjectGroup::setProperties), this);
	using FunctionType = decltype(setProperties(p0))(*)(cocos2d::CCTMXObjectGroup*, cocos2d::CCDictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x400e24, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCTMXObjectGroup::getObjects() -> decltype(getObjects()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTMXObjectGroup::getObjects), this);
	using FunctionType = decltype(getObjects())(*)(cocos2d::CCTMXObjectGroup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x400e60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTMXObjectGroup::setObjects(cocos2d::CCArray* p0) -> decltype(setObjects(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCArray*>::func(&cocos2d::CCTMXObjectGroup::setObjects), this);
	using FunctionType = decltype(setObjects(p0))(*)(cocos2d::CCTMXObjectGroup*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x400e68, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCTMXObjectGroup::objectNamed(char const* p0) -> decltype(objectNamed(p0)) {
	using FunctionType = decltype(objectNamed(p0))(*)(cocos2d::CCTMXObjectGroup*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x400bcc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTMXObjectGroup::propertyNamed(char const* p0) -> decltype(propertyNamed(p0)) {
	using FunctionType = decltype(propertyNamed(p0))(*)(cocos2d::CCTMXObjectGroup*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x400d18, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
