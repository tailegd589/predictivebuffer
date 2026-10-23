
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCParticleSystemQuad.hpp>
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

cocos2d::CCParticleSystemQuad::CCParticleSystemQuad() : cocos2d::CCParticleSystemQuad(geode::CutoffConstructor, sizeof(cocos2d::CCParticleSystemQuad)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCParticleSystemQuad::~CCParticleSystemQuad();

	using FunctionType = void(*)(cocos2d::CCParticleSystemQuad*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52a2c0, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCParticleSystemQuad::~CCParticleSystemQuad() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCParticleSystemQuad*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x52a3a8, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCParticleSystemQuad(geode::CutoffConstructor, sizeof(cocos2d::CCParticleSystemQuad));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCParticleSystemQuad::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52b1cc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCParticleSystemQuad::create(char const* p0, bool p1) -> decltype(create(p0, p1)) {
	using FunctionType = decltype(create(p0, p1))(*)(char const*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52a440, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCParticleSystemQuad::createWithTotalParticles(unsigned int p0, bool p1) -> decltype(createWithTotalParticles(p0, p1)) {
	using FunctionType = decltype(createWithTotalParticles(p0, p1))(*)(unsigned int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52a528, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCParticleSystemQuad::draw() -> decltype(draw()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystemQuad::draw), this);
	using FunctionType = decltype(draw())(*)(cocos2d::CCParticleSystemQuad*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52ad78, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystemQuad::setBatchNode(cocos2d::CCParticleBatchNode* p0) -> decltype(setBatchNode(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCParticleBatchNode*>::func(&cocos2d::CCParticleSystemQuad::setBatchNode), this);
	using FunctionType = decltype(setBatchNode(p0))(*)(cocos2d::CCParticleSystemQuad*, cocos2d::CCParticleBatchNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52b050, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystemQuad::setTotalParticles(unsigned int p0) -> decltype(setTotalParticles(p0)) {
	auto self = addresser::thunkAdjust(Resolve<unsigned int>::func(&cocos2d::CCParticleSystemQuad::setTotalParticles), this);
	using FunctionType = decltype(setTotalParticles(p0))(*)(cocos2d::CCParticleSystemQuad*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52ae40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystemQuad::initWithTotalParticles(unsigned int p0, bool p1) -> decltype(initWithTotalParticles(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<unsigned int, bool>::func(&cocos2d::CCParticleSystemQuad::initWithTotalParticles), this);
	using FunctionType = decltype(initWithTotalParticles(p0, p1))(*)(cocos2d::CCParticleSystemQuad*, unsigned int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x529f58, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::CCParticleSystemQuad::updateQuadWithParticle(cocos2d::sCCParticle* p0, cocos2d::CCPoint const& p1) -> decltype(updateQuadWithParticle(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::sCCParticle*, cocos2d::CCPoint const&>::func(&cocos2d::CCParticleSystemQuad::updateQuadWithParticle), this);
	using FunctionType = decltype(updateQuadWithParticle(p0, p1))(*)(cocos2d::CCParticleSystemQuad*, cocos2d::sCCParticle*, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52aa70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::CCParticleSystemQuad::postStep() -> decltype(postStep()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleSystemQuad::postStep), this);
	using FunctionType = decltype(postStep())(*)(cocos2d::CCParticleSystemQuad*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52ad2c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleSystemQuad::setTexture(cocos2d::CCTexture2D* p0) -> decltype(setTexture(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTexture2D*>::func(&cocos2d::CCParticleSystemQuad::setTexture), this);
	using FunctionType = decltype(setTexture(p0))(*)(cocos2d::CCParticleSystemQuad*, cocos2d::CCTexture2D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52a88c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleSystemQuad::allocMemory() -> decltype(allocMemory()) {
	using FunctionType = decltype(allocMemory())(*)(cocos2d::CCParticleSystemQuad*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52a03c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCParticleSystemQuad::initIndices() -> decltype(initIndices()) {
	using FunctionType = decltype(initIndices())(*)(cocos2d::CCParticleSystemQuad*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52a11c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCParticleSystemQuad::initTexCoordsWithRect(cocos2d::CCRect const& p0) -> decltype(initTexCoordsWithRect(p0)) {
	using FunctionType = decltype(initTexCoordsWithRect(p0))(*)(cocos2d::CCParticleSystemQuad*, cocos2d::CCRect const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52a618, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCParticleSystemQuad::listenBackToForeground(cocos2d::CCObject* p0) -> decltype(listenBackToForeground(p0)) {
	using FunctionType = decltype(listenBackToForeground(p0))(*)(cocos2d::CCParticleSystemQuad*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52b04c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCParticleSystemQuad::setDisplayFrame(cocos2d::CCSpriteFrame* p0) -> decltype(setDisplayFrame(p0)) {
	using FunctionType = decltype(setDisplayFrame(p0))(*)(cocos2d::CCParticleSystemQuad*, cocos2d::CCSpriteFrame*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52a9d8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCParticleSystemQuad::setTextureWithRect(cocos2d::CCTexture2D* p0, cocos2d::CCRect const& p1) -> decltype(setTextureWithRect(p0, p1)) {
	using FunctionType = decltype(setTextureWithRect(p0, p1))(*)(cocos2d::CCParticleSystemQuad*, cocos2d::CCTexture2D*, cocos2d::CCRect const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52a818, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCParticleSystemQuad::setupVBOandVAO() -> decltype(setupVBOandVAO()) {
	using FunctionType = decltype(setupVBOandVAO())(*)(cocos2d::CCParticleSystemQuad*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52a18c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCParticleSystemQuad::updateTexCoords() -> decltype(updateTexCoords()) {
	using FunctionType = decltype(updateTexCoords())(*)(cocos2d::CCParticleSystemQuad*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52a804, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
