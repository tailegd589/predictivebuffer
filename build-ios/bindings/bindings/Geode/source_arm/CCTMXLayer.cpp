
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCTMXLayer.hpp>
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

cocos2d::CCTMXLayer::CCTMXLayer() : cocos2d::CCTMXLayer(geode::CutoffConstructor, sizeof(cocos2d::CCTMXLayer)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCTMXLayer::~CCTMXLayer();

	using FunctionType = void(*)(cocos2d::CCTMXLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1fef98, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCTMXLayer::~CCTMXLayer() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCTMXLayer*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x1ff018, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCTMXLayer(geode::CutoffConstructor, sizeof(cocos2d::CCTMXLayer));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCTMXLayer::create(cocos2d::CCTMXTilesetInfo* p0, cocos2d::CCTMXLayerInfo* p1, cocos2d::CCTMXMapInfo* p2) -> decltype(create(p0, p1, p2)) {
	using FunctionType = decltype(create(p0, p1, p2))(*)(cocos2d::CCTMXTilesetInfo*, cocos2d::CCTMXLayerInfo*, cocos2d::CCTMXMapInfo*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1feb28, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

auto cocos2d::CCTMXLayer::getTileSet() -> decltype(getTileSet()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTMXLayer::getTileSet), this);
	using FunctionType = decltype(getTileSet())(*)(cocos2d::CCTMXLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1ff0cc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTMXLayer::setTileSet(cocos2d::CCTMXTilesetInfo* p0) -> decltype(setTileSet(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTMXTilesetInfo*>::func(&cocos2d::CCTMXLayer::setTileSet), this);
	using FunctionType = decltype(setTileSet(p0))(*)(cocos2d::CCTMXLayer*, cocos2d::CCTMXTilesetInfo*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1ff0d4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCTMXLayer::getProperties() -> decltype(getProperties()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTMXLayer::getProperties), this);
	using FunctionType = decltype(getProperties())(*)(cocos2d::CCTMXLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x200780, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTMXLayer::setProperties(cocos2d::CCDictionary* p0) -> decltype(setProperties(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCDictionary*>::func(&cocos2d::CCTMXLayer::setProperties), this);
	using FunctionType = decltype(setProperties(p0))(*)(cocos2d::CCTMXLayer*, cocos2d::CCDictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x200788, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCTMXLayer::addChild(cocos2d::CCNode* p0, int p1, int p2) -> decltype(addChild(p0, p1, p2)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*, int, int>::func(&cocos2d::CCTMXLayer::addChild), this);
	using FunctionType = decltype(addChild(p0, p1, p2))(*)(cocos2d::CCTMXLayer*, cocos2d::CCNode*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x200638, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2);
}

auto cocos2d::CCTMXLayer::removeChild(cocos2d::CCNode* p0, bool p1) -> decltype(removeChild(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*, bool>::func(&cocos2d::CCTMXLayer::removeChild), this);
	using FunctionType = decltype(removeChild(p0, p1))(*)(cocos2d::CCTMXLayer*, cocos2d::CCNode*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x20063c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::CCTMXLayer::appendTileForGID(unsigned int p0, cocos2d::CCPoint const& p1) -> decltype(appendTileForGID(p0, p1)) {
	using FunctionType = decltype(appendTileForGID(p0, p1))(*)(cocos2d::CCTMXLayer*, unsigned int, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1ff524, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCTMXLayer::atlasIndexForExistantZ(unsigned int p0) -> decltype(atlasIndexForExistantZ(p0)) {
	using FunctionType = decltype(atlasIndexForExistantZ(p0))(*)(cocos2d::CCTMXLayer*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1fff48, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTMXLayer::atlasIndexForNewZ(int p0) -> decltype(atlasIndexForNewZ(p0)) {
	using FunctionType = decltype(atlasIndexForNewZ(p0))(*)(cocos2d::CCTMXLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x200194, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTMXLayer::calculateLayerOffset(cocos2d::CCPoint const& p0) -> decltype(calculateLayerOffset(p0)) {
	using FunctionType = decltype(calculateLayerOffset(p0))(*)(cocos2d::CCTMXLayer*, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1feec4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTMXLayer::initWithTilesetInfo(cocos2d::CCTMXTilesetInfo* p0, cocos2d::CCTMXLayerInfo* p1, cocos2d::CCTMXMapInfo* p2) -> decltype(initWithTilesetInfo(p0, p1, p2)) {
	using FunctionType = decltype(initWithTilesetInfo(p0, p1, p2))(*)(cocos2d::CCTMXLayer*, cocos2d::CCTMXTilesetInfo*, cocos2d::CCTMXLayerInfo*, cocos2d::CCTMXMapInfo*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1fec84, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto cocos2d::CCTMXLayer::insertTileForGID(unsigned int p0, cocos2d::CCPoint const& p1) -> decltype(insertTileForGID(p0, p1)) {
	using FunctionType = decltype(insertTileForGID(p0, p1))(*)(cocos2d::CCTMXLayer*, unsigned int, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1fffcc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCTMXLayer::parseInternalProperties() -> decltype(parseInternalProperties()) {
	using FunctionType = decltype(parseInternalProperties())(*)(cocos2d::CCTMXLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1ff3fc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTMXLayer::positionAt(cocos2d::CCPoint const& p0) -> decltype(positionAt(p0)) {
	using FunctionType = decltype(positionAt(p0))(*)(cocos2d::CCTMXLayer*, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1ffa08, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTMXLayer::positionForHexAt(cocos2d::CCPoint const& p0) -> decltype(positionForHexAt(p0)) {
	using FunctionType = decltype(positionForHexAt(p0))(*)(cocos2d::CCTMXLayer*, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x200728, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTMXLayer::positionForIsoAt(cocos2d::CCPoint const& p0) -> decltype(positionForIsoAt(p0)) {
	using FunctionType = decltype(positionForIsoAt(p0))(*)(cocos2d::CCTMXLayer*, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2006d4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTMXLayer::positionForOrthoAt(cocos2d::CCPoint const& p0) -> decltype(positionForOrthoAt(p0)) {
	using FunctionType = decltype(positionForOrthoAt(p0))(*)(cocos2d::CCTMXLayer*, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2006a8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTMXLayer::propertyNamed(char const* p0) -> decltype(propertyNamed(p0)) {
	using FunctionType = decltype(propertyNamed(p0))(*)(cocos2d::CCTMXLayer*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1ff654, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTMXLayer::releaseMap() -> decltype(releaseMap()) {
	using FunctionType = decltype(releaseMap())(*)(cocos2d::CCTMXLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1ff110, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTMXLayer::removeTileAt(cocos2d::CCPoint const& p0) -> decltype(removeTileAt(p0)) {
	using FunctionType = decltype(removeTileAt(p0))(*)(cocos2d::CCTMXLayer*, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x20050c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTMXLayer::reusedTileWithRect(cocos2d::CCRect p0) -> decltype(reusedTileWithRect(p0)) {
	using FunctionType = decltype(reusedTileWithRect(p0))(*)(cocos2d::CCTMXLayer*, cocos2d::CCRect);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1ffbf0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTMXLayer::setTileGID(unsigned int p0, cocos2d::CCPoint const& p1) -> decltype(setTileGID(p0, p1)) {
	using FunctionType = decltype(setTileGID(p0, p1))(*)(cocos2d::CCTMXLayer*, unsigned int, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x20030c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCTMXLayer::setTileGID(unsigned int p0, cocos2d::CCPoint const& p1, cocos2d::ccTMXTileFlags p2) -> decltype(setTileGID(p0, p1, p2)) {
	using FunctionType = decltype(setTileGID(p0, p1, p2))(*)(cocos2d::CCTMXLayer*, unsigned int, cocos2d::CCPoint const&, cocos2d::ccTMXTileFlags);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x200314, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto cocos2d::CCTMXLayer::setupTiles() -> decltype(setupTiles()) {
	using FunctionType = decltype(setupTiles())(*)(cocos2d::CCTMXLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1ff14c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTMXLayer::setupTileSprite(cocos2d::CCSprite* p0, cocos2d::CCPoint p1, unsigned int p2) -> decltype(setupTileSprite(p0, p1, p2)) {
	using FunctionType = decltype(setupTileSprite(p0, p1, p2))(*)(cocos2d::CCTMXLayer*, cocos2d::CCSprite*, cocos2d::CCPoint, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1ff758, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto cocos2d::CCTMXLayer::tileAt(cocos2d::CCPoint const& p0) -> decltype(tileAt(p0)) {
	using FunctionType = decltype(tileAt(p0))(*)(cocos2d::CCTMXLayer*, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1ffcbc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTMXLayer::tileGIDAt(cocos2d::CCPoint const& p0) -> decltype(tileGIDAt(p0)) {
	using FunctionType = decltype(tileGIDAt(p0))(*)(cocos2d::CCTMXLayer*, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1fff28, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTMXLayer::tileGIDAt(cocos2d::CCPoint const& p0, cocos2d::ccTMXTileFlags* p1) -> decltype(tileGIDAt(p0, p1)) {
	using FunctionType = decltype(tileGIDAt(p0, p1))(*)(cocos2d::CCTMXLayer*, cocos2d::CCPoint const&, cocos2d::ccTMXTileFlags*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1fffa0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCTMXLayer::updateTileForGID(unsigned int p0, cocos2d::CCPoint const& p1) -> decltype(updateTileForGID(p0, p1)) {
	using FunctionType = decltype(updateTileForGID(p0, p1))(*)(cocos2d::CCTMXLayer*, unsigned int, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2001d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCTMXLayer::vertexZForPos(cocos2d::CCPoint const& p0) -> decltype(vertexZForPos(p0)) {
	using FunctionType = decltype(vertexZForPos(p0))(*)(cocos2d::CCTMXLayer*, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1ffb80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
