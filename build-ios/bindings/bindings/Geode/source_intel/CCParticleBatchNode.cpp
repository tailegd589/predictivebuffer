
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCParticleBatchNode.hpp>
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

cocos2d::CCParticleBatchNode::CCParticleBatchNode() : cocos2d::CCParticleBatchNode(geode::CutoffConstructor, sizeof(cocos2d::CCParticleBatchNode)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCParticleBatchNode::~CCParticleBatchNode();

	using FunctionType = void(*)(cocos2d::CCParticleBatchNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3c8820, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCParticleBatchNode::~CCParticleBatchNode() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCParticleBatchNode*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x3c88a0, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCParticleBatchNode(geode::CutoffConstructor, sizeof(cocos2d::CCParticleBatchNode));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCParticleBatchNode::create(char const* p0, unsigned int p1) -> decltype(create(p0, p1)) {
	using FunctionType = decltype(create(p0, p1))(*)(char const*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3c8ad0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCParticleBatchNode::createWithTexture(cocos2d::CCTexture2D* p0, unsigned int p1) -> decltype(createWithTexture(p0, p1)) {
	using FunctionType = decltype(createWithTexture(p0, p1))(*)(cocos2d::CCTexture2D*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3c8990, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCParticleBatchNode::addChild(cocos2d::CCNode* p0) -> decltype(addChild(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*>::func(&cocos2d::CCParticleBatchNode::addChild), this);
	using FunctionType = decltype(addChild(p0))(*)(cocos2d::CCParticleBatchNode*, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3c8c20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleBatchNode::addChild(cocos2d::CCNode* p0, int p1) -> decltype(addChild(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*, int>::func(&cocos2d::CCParticleBatchNode::addChild), this);
	using FunctionType = decltype(addChild(p0, p1))(*)(cocos2d::CCParticleBatchNode*, cocos2d::CCNode*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3c8c30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::CCParticleBatchNode::addChild(cocos2d::CCNode* p0, int p1, int p2) -> decltype(addChild(p0, p1, p2)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*, int, int>::func(&cocos2d::CCParticleBatchNode::addChild), this);
	using FunctionType = decltype(addChild(p0, p1, p2))(*)(cocos2d::CCParticleBatchNode*, cocos2d::CCNode*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3c8c40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2);
}

auto cocos2d::CCParticleBatchNode::removeChild(cocos2d::CCNode* p0, bool p1) -> decltype(removeChild(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*, bool>::func(&cocos2d::CCParticleBatchNode::removeChild), this);
	using FunctionType = decltype(removeChild(p0, p1))(*)(cocos2d::CCParticleBatchNode*, cocos2d::CCNode*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3c9490, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::CCParticleBatchNode::reorderChild(cocos2d::CCNode* p0, int p1) -> decltype(reorderChild(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*, int>::func(&cocos2d::CCParticleBatchNode::reorderChild), this);
	using FunctionType = decltype(reorderChild(p0, p1))(*)(cocos2d::CCParticleBatchNode*, cocos2d::CCNode*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3c9080, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::CCParticleBatchNode::removeAllChildrenWithCleanup(bool p0) -> decltype(removeAllChildrenWithCleanup(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::CCParticleBatchNode::removeAllChildrenWithCleanup), this);
	using FunctionType = decltype(removeAllChildrenWithCleanup(p0))(*)(cocos2d::CCParticleBatchNode*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3c95c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleBatchNode::draw() -> decltype(draw()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleBatchNode::draw), this);
	using FunctionType = decltype(draw())(*)(cocos2d::CCParticleBatchNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3c9650, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleBatchNode::getTexture() -> decltype(getTexture()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleBatchNode::getTexture), this);
	using FunctionType = decltype(getTexture())(*)(cocos2d::CCParticleBatchNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3c9830, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleBatchNode::setTexture(cocos2d::CCTexture2D* p0) -> decltype(setTexture(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTexture2D*>::func(&cocos2d::CCParticleBatchNode::setTexture), this);
	using FunctionType = decltype(setTexture(p0))(*)(cocos2d::CCParticleBatchNode*, cocos2d::CCTexture2D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3c9790, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleBatchNode::setBlendFunc(cocos2d::ccBlendFunc p0) -> decltype(setBlendFunc(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::ccBlendFunc>::func(&cocos2d::CCParticleBatchNode::setBlendFunc), this);
	using FunctionType = decltype(setBlendFunc(p0))(*)(cocos2d::CCParticleBatchNode*, cocos2d::ccBlendFunc);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3c9860, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParticleBatchNode::getBlendFunc() -> decltype(getBlendFunc()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleBatchNode::getBlendFunc), this);
	using FunctionType = decltype(getBlendFunc())(*)(cocos2d::CCParticleBatchNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3c9880, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleBatchNode::visit() -> decltype(visit()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParticleBatchNode::visit), this);
	using FunctionType = decltype(visit())(*)(cocos2d::CCParticleBatchNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3c8bb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParticleBatchNode::addChildHelper(cocos2d::CCParticleSystem* p0, int p1, int p2) -> decltype(addChildHelper(p0, p1, p2)) {
	using FunctionType = decltype(addChildHelper(p0, p1, p2))(*)(cocos2d::CCParticleBatchNode*, cocos2d::CCParticleSystem*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3c8d40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto cocos2d::CCParticleBatchNode::disableParticle(unsigned int p0) -> decltype(disableParticle(p0)) {
	using FunctionType = decltype(disableParticle(p0))(*)(cocos2d::CCParticleBatchNode*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3c9700, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCParticleBatchNode::getCurrentIndex(unsigned int* p0, unsigned int* p1, cocos2d::CCNode* p2, int p3) -> decltype(getCurrentIndex(p0, p1, p2, p3)) {
	using FunctionType = decltype(getCurrentIndex(p0, p1, p2, p3))(*)(cocos2d::CCParticleBatchNode*, unsigned int*, unsigned int*, cocos2d::CCNode*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3c9320, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3);
}

auto cocos2d::CCParticleBatchNode::increaseAtlasCapacityTo(unsigned int p0) -> decltype(increaseAtlasCapacityTo(p0)) {
	using FunctionType = decltype(increaseAtlasCapacityTo(p0))(*)(cocos2d::CCParticleBatchNode*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3c96e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCParticleBatchNode::initWithFile(char const* p0, unsigned int p1) -> decltype(initWithFile(p0, p1)) {
	using FunctionType = decltype(initWithFile(p0, p1))(*)(cocos2d::CCParticleBatchNode*, char const*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3c8b70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCParticleBatchNode::initWithTexture(cocos2d::CCTexture2D* p0, unsigned int p1) -> decltype(initWithTexture(p0, p1)) {
	using FunctionType = decltype(initWithTexture(p0, p1))(*)(cocos2d::CCParticleBatchNode*, cocos2d::CCTexture2D*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3c8a10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCParticleBatchNode::insertChild(cocos2d::CCParticleSystem* p0, unsigned int p1) -> decltype(insertChild(p0, p1)) {
	using FunctionType = decltype(insertChild(p0, p1))(*)(cocos2d::CCParticleBatchNode*, cocos2d::CCParticleSystem*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3c8e80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCParticleBatchNode::removeChildAtIndex(unsigned int p0, bool p1) -> decltype(removeChildAtIndex(p0, p1)) {
	using FunctionType = decltype(removeChildAtIndex(p0, p1))(*)(cocos2d::CCParticleBatchNode*, unsigned int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3c9590, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCParticleBatchNode::searchNewPositionInChildrenForZ(int p0) -> decltype(searchNewPositionInChildrenForZ(p0)) {
	using FunctionType = decltype(searchNewPositionInChildrenForZ(p0))(*)(cocos2d::CCParticleBatchNode*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3c9010, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCParticleBatchNode::updateAllAtlasIndexes() -> decltype(updateAllAtlasIndexes()) {
	using FunctionType = decltype(updateAllAtlasIndexes())(*)(cocos2d::CCParticleBatchNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3c9430, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCParticleBatchNode::updateBlendFunc() -> decltype(updateBlendFunc()) {
	using FunctionType = decltype(updateBlendFunc())(*)(cocos2d::CCParticleBatchNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3c9750, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
