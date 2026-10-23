
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCGrid3D.hpp>
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

cocos2d::CCGrid3D::CCGrid3D() : cocos2d::CCGrid3D(geode::CutoffConstructor, sizeof(cocos2d::CCGrid3D)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCGrid3D::~CCGrid3D();

	using FunctionType = void(*)(cocos2d::CCGrid3D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e3d00, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCGrid3D::~CCGrid3D() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCGrid3D*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x4e3d60, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCGrid3D(geode::CutoffConstructor, sizeof(cocos2d::CCGrid3D));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCGrid3D::create(cocos2d::CCSize const& p0) -> decltype(create(p0)) {
	using FunctionType = decltype(create(p0))(*)(cocos2d::CCSize const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e3c50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::CCGrid3D::create(cocos2d::CCSize const& p0, cocos2d::CCTexture2D* p1, bool p2) -> decltype(create(p0, p1, p2)) {
	using FunctionType = decltype(create(p0, p1, p2))(*)(cocos2d::CCSize const&, cocos2d::CCTexture2D*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e3b30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

auto cocos2d::CCGrid3D::blit() -> decltype(blit()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCGrid3D::blit), this);
	using FunctionType = decltype(blit())(*)(cocos2d::CCGrid3D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e3e50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCGrid3D::reuse() -> decltype(reuse()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCGrid3D::reuse), this);
	using FunctionType = decltype(reuse())(*)(cocos2d::CCGrid3D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e45f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCGrid3D::calculateVertexPoints() -> decltype(calculateVertexPoints()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCGrid3D::calculateVertexPoints), this);
	using FunctionType = decltype(calculateVertexPoints())(*)(cocos2d::CCGrid3D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e3ef0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCGrid3D::originalVertex(cocos2d::CCPoint const& p0) -> decltype(originalVertex(p0)) {
	using FunctionType = decltype(originalVertex(p0))(*)(cocos2d::CCGrid3D*, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e4560, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCGrid3D::setVertex(cocos2d::CCPoint const& p0, cocos2d::ccVertex3F const& p1) -> decltype(setVertex(p0, p1)) {
	using FunctionType = decltype(setVertex(p0, p1))(*)(cocos2d::CCGrid3D*, cocos2d::CCPoint const&, cocos2d::ccVertex3F const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e45a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCGrid3D::vertex(cocos2d::CCPoint const& p0) -> decltype(vertex(p0)) {
	using FunctionType = decltype(vertex(p0))(*)(cocos2d::CCGrid3D*, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4e4520, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
