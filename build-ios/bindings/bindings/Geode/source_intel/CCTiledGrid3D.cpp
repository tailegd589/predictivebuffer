
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCTiledGrid3D.hpp>
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

cocos2d::CCTiledGrid3D::CCTiledGrid3D() : cocos2d::CCTiledGrid3D(geode::CutoffConstructor, sizeof(cocos2d::CCTiledGrid3D)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCTiledGrid3D::~CCTiledGrid3D();

	using FunctionType = void(*)(cocos2d::CCTiledGrid3D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e46c0, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCTiledGrid3D::~CCTiledGrid3D() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCTiledGrid3D*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x4e4720, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCTiledGrid3D(geode::CutoffConstructor, sizeof(cocos2d::CCTiledGrid3D));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCTiledGrid3D::create(cocos2d::CCSize const& p0) -> decltype(create(p0)) {
	using FunctionType = decltype(create(p0))(*)(cocos2d::CCSize const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e48d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::CCTiledGrid3D::create(cocos2d::CCSize const& p0, cocos2d::CCTexture2D* p1, bool p2) -> decltype(create(p0, p1, p2)) {
	using FunctionType = decltype(create(p0, p1, p2))(*)(cocos2d::CCSize const&, cocos2d::CCTexture2D*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e4810, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

auto cocos2d::CCTiledGrid3D::blit() -> decltype(blit()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTiledGrid3D::blit), this);
	using FunctionType = decltype(blit())(*)(cocos2d::CCTiledGrid3D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e4980, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTiledGrid3D::reuse() -> decltype(reuse()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTiledGrid3D::reuse), this);
	using FunctionType = decltype(reuse())(*)(cocos2d::CCTiledGrid3D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e5040, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTiledGrid3D::calculateVertexPoints() -> decltype(calculateVertexPoints()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTiledGrid3D::calculateVertexPoints), this);
	using FunctionType = decltype(calculateVertexPoints())(*)(cocos2d::CCTiledGrid3D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e4a20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTiledGrid3D::originalTile(cocos2d::CCPoint const& p0) -> decltype(originalTile(p0)) {
	using FunctionType = decltype(originalTile(p0))(*)(cocos2d::CCTiledGrid3D*, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e4fa0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTiledGrid3D::setTile(cocos2d::CCPoint const& p0, cocos2d::ccQuad3 const& p1) -> decltype(setTile(p0, p1)) {
	using FunctionType = decltype(setTile(p0, p1))(*)(cocos2d::CCTiledGrid3D*, cocos2d::CCPoint const&, cocos2d::ccQuad3 const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e4f50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCTiledGrid3D::tile(cocos2d::CCPoint const& p0) -> decltype(tile(p0)) {
	using FunctionType = decltype(tile(p0))(*)(cocos2d::CCTiledGrid3D*, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e4ff0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
