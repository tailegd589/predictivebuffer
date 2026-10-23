
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCTileMapAtlas.hpp>
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

cocos2d::CCTileMapAtlas::CCTileMapAtlas() : cocos2d::CCTileMapAtlas(geode::CutoffConstructor, sizeof(cocos2d::CCTileMapAtlas)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCTileMapAtlas::~CCTileMapAtlas();

	using FunctionType = void(*)(cocos2d::CCTileMapAtlas*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22cd70, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCTileMapAtlas::~CCTileMapAtlas() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCTileMapAtlas*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x22cdc0, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCTileMapAtlas(geode::CutoffConstructor, sizeof(cocos2d::CCTileMapAtlas));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCTileMapAtlas::create(char const* p0, char const* p1, int p2, int p3) -> decltype(create(p0, p1, p2, p3)) {
	using FunctionType = decltype(create(p0, p1, p2, p3))(*)(char const*, char const*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22c8f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3);
}

auto cocos2d::CCTileMapAtlas::getTGAInfo() -> decltype(getTGAInfo()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTileMapAtlas::getTGAInfo), this);
	using FunctionType = decltype(getTGAInfo())(*)(cocos2d::CCTileMapAtlas*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22d640, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTileMapAtlas::setTGAInfo(cocos2d::sImageTGA* p0) -> decltype(setTGAInfo(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::sImageTGA*>::func(&cocos2d::CCTileMapAtlas::setTGAInfo), this);
	using FunctionType = decltype(setTGAInfo(p0))(*)(cocos2d::CCTileMapAtlas*, cocos2d::sImageTGA*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22d630, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCTileMapAtlas::updateAtlasValues() -> decltype(updateAtlasValues()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTileMapAtlas::updateAtlasValues), this);
	using FunctionType = decltype(updateAtlasValues())(*)(cocos2d::CCTileMapAtlas*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22d400, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTileMapAtlas::calculateItemsToRender() -> decltype(calculateItemsToRender()) {
	using FunctionType = decltype(calculateItemsToRender())(*)(cocos2d::CCTileMapAtlas*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22cc80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTileMapAtlas::initWithTileFile(char const* p0, char const* p1, int p2, int p3) -> decltype(initWithTileFile(p0, p1, p2, p3)) {
	using FunctionType = decltype(initWithTileFile(p0, p1, p2, p3))(*)(cocos2d::CCTileMapAtlas*, char const*, char const*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22ca00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3);
}

auto cocos2d::CCTileMapAtlas::loadTGAfile(char const* p0) -> decltype(loadTGAfile(p0)) {
	using FunctionType = decltype(loadTGAfile(p0))(*)(cocos2d::CCTileMapAtlas*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22cc00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTileMapAtlas::releaseMap() -> decltype(releaseMap()) {
	using FunctionType = decltype(releaseMap())(*)(cocos2d::CCTileMapAtlas*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22cf10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTileMapAtlas::setTile(cocos2d::ccColor3B const& p0, cocos2d::CCPoint const& p1) -> decltype(setTile(p0, p1)) {
	using FunctionType = decltype(setTile(p0, p1))(*)(cocos2d::CCTileMapAtlas*, cocos2d::ccColor3B const&, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22cf60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCTileMapAtlas::tileAt(cocos2d::CCPoint const& p0) -> decltype(tileAt(p0)) {
	using FunctionType = decltype(tileAt(p0))(*)(cocos2d::CCTileMapAtlas*, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22d3c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTileMapAtlas::updateAtlasValueAt(cocos2d::CCPoint const& p0, cocos2d::ccColor3B const& p1, unsigned int p2) -> decltype(updateAtlasValueAt(p0, p1, p2)) {
	using FunctionType = decltype(updateAtlasValueAt(p0, p1, p2))(*)(cocos2d::CCTileMapAtlas*, cocos2d::CCPoint const&, cocos2d::ccColor3B const&, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22d0d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}
