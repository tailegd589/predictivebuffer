
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCTMXTiledMap.hpp>
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

cocos2d::CCTMXTiledMap::CCTMXTiledMap() : cocos2d::CCTMXTiledMap(geode::CutoffConstructor, sizeof(cocos2d::CCTMXTiledMap)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCTMXTiledMap::~CCTMXTiledMap();

	using FunctionType = void(*)(cocos2d::CCTMXTiledMap*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x46ee50, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCTMXTiledMap::~CCTMXTiledMap() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCTMXTiledMap*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x46eebc, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCTMXTiledMap(geode::CutoffConstructor, sizeof(cocos2d::CCTMXTiledMap));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCTMXTiledMap::create(char const* p0) -> decltype(create(p0)) {
	using FunctionType = decltype(create(p0))(*)(char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x46e970, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::CCTMXTiledMap::createWithXML(char const* p0, char const* p1) -> decltype(createWithXML(p0, p1)) {
	using FunctionType = decltype(createWithXML(p0, p1))(*)(char const*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x46eb48, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCTMXTiledMap::getObjectGroups() -> decltype(getObjectGroups()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTMXTiledMap::getObjectGroups), this);
	using FunctionType = decltype(getObjectGroups())(*)(cocos2d::CCTMXTiledMap*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x46efbc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTMXTiledMap::setObjectGroups(cocos2d::CCArray* p0) -> decltype(setObjectGroups(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCArray*>::func(&cocos2d::CCTMXTiledMap::setObjectGroups), this);
	using FunctionType = decltype(setObjectGroups(p0))(*)(cocos2d::CCTMXTiledMap*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x46efc4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCTMXTiledMap::getProperties() -> decltype(getProperties()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTMXTiledMap::getProperties), this);
	using FunctionType = decltype(getProperties())(*)(cocos2d::CCTMXTiledMap*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x46f000, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTMXTiledMap::setProperties(cocos2d::CCDictionary* p0) -> decltype(setProperties(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCDictionary*>::func(&cocos2d::CCTMXTiledMap::setProperties), this);
	using FunctionType = decltype(setProperties(p0))(*)(cocos2d::CCTMXTiledMap*, cocos2d::CCDictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x46f008, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCTMXTiledMap::buildWithMapInfo(cocos2d::CCTMXMapInfo* p0) -> decltype(buildWithMapInfo(p0)) {
	using FunctionType = decltype(buildWithMapInfo(p0))(*)(cocos2d::CCTMXTiledMap*, cocos2d::CCTMXMapInfo*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x46eca0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTMXTiledMap::initWithTMXFile(char const* p0) -> decltype(initWithTMXFile(p0)) {
	using FunctionType = decltype(initWithTMXFile(p0))(*)(cocos2d::CCTMXTiledMap*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x46eadc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTMXTiledMap::initWithXML(char const* p0, char const* p1) -> decltype(initWithXML(p0, p1)) {
	using FunctionType = decltype(initWithXML(p0, p1))(*)(cocos2d::CCTMXTiledMap*, char const*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x46ec30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCTMXTiledMap::layerNamed(char const* p0) -> decltype(layerNamed(p0)) {
	using FunctionType = decltype(layerNamed(p0))(*)(cocos2d::CCTMXTiledMap*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x46f280, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTMXTiledMap::objectGroupNamed(char const* p0) -> decltype(objectGroupNamed(p0)) {
	using FunctionType = decltype(objectGroupNamed(p0))(*)(cocos2d::CCTMXTiledMap*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x46f334, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTMXTiledMap::parseLayer(cocos2d::CCTMXLayerInfo* p0, cocos2d::CCTMXMapInfo* p1) -> decltype(parseLayer(p0, p1)) {
	using FunctionType = decltype(parseLayer(p0, p1))(*)(cocos2d::CCTMXTiledMap*, cocos2d::CCTMXLayerInfo*, cocos2d::CCTMXMapInfo*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x46f044, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCTMXTiledMap::propertiesForGID(int p0) -> decltype(propertiesForGID(p0)) {
	using FunctionType = decltype(propertiesForGID(p0))(*)(cocos2d::CCTMXTiledMap*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x46f65c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTMXTiledMap::propertyNamed(char const* p0) -> decltype(propertyNamed(p0)) {
	using FunctionType = decltype(propertyNamed(p0))(*)(cocos2d::CCTMXTiledMap*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x46f558, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTMXTiledMap::tilesetForLayer(cocos2d::CCTMXLayerInfo* p0, cocos2d::CCTMXMapInfo* p1) -> decltype(tilesetForLayer(p0, p1)) {
	using FunctionType = decltype(tilesetForLayer(p0, p1))(*)(cocos2d::CCTMXTiledMap*, cocos2d::CCTMXLayerInfo*, cocos2d::CCTMXMapInfo*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x46f170, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}
