
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCSpriteBatchNode.hpp>
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

cocos2d::CCSpriteBatchNode::CCSpriteBatchNode() : cocos2d::CCSpriteBatchNode(geode::CutoffConstructor, sizeof(cocos2d::CCSpriteBatchNode)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCSpriteBatchNode::~CCSpriteBatchNode();

	using FunctionType = void(*)(cocos2d::CCSpriteBatchNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1766b0, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCSpriteBatchNode::~CCSpriteBatchNode() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCSpriteBatchNode*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x176700, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCSpriteBatchNode(geode::CutoffConstructor, sizeof(cocos2d::CCSpriteBatchNode));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCSpriteBatchNode::create(char const* fileImage, unsigned int capacity) -> decltype(create(fileImage, capacity)) {
	using FunctionType = decltype(create(fileImage, capacity))(*)(char const*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x176520, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(fileImage, capacity);
}

auto cocos2d::CCSpriteBatchNode::createWithTexture(cocos2d::CCTexture2D* p0, unsigned int p1) -> decltype(createWithTexture(p0, p1)) {
	using FunctionType = decltype(createWithTexture(p0, p1))(*)(cocos2d::CCTexture2D*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1762f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCSpriteBatchNode::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCSpriteBatchNode::init), this);
	using FunctionType = decltype(init())(*)(cocos2d::CCSpriteBatchNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x176660, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCSpriteBatchNode::addChild(cocos2d::CCNode* p0) -> decltype(addChild(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*>::func(&cocos2d::CCSpriteBatchNode::addChild), this);
	using FunctionType = decltype(addChild(p0))(*)(cocos2d::CCSpriteBatchNode*, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x176b10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCSpriteBatchNode::addChild(cocos2d::CCNode* p0, int p1) -> decltype(addChild(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*, int>::func(&cocos2d::CCSpriteBatchNode::addChild), this);
	using FunctionType = decltype(addChild(p0, p1))(*)(cocos2d::CCSpriteBatchNode*, cocos2d::CCNode*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x176b20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::CCSpriteBatchNode::addChild(cocos2d::CCNode* p0, int p1, int p2) -> decltype(addChild(p0, p1, p2)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*, int, int>::func(&cocos2d::CCSpriteBatchNode::addChild), this);
	using FunctionType = decltype(addChild(p0, p1, p2))(*)(cocos2d::CCSpriteBatchNode*, cocos2d::CCNode*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1768d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2);
}

auto cocos2d::CCSpriteBatchNode::removeChild(cocos2d::CCNode* p0, bool p1) -> decltype(removeChild(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*, bool>::func(&cocos2d::CCSpriteBatchNode::removeChild), this);
	using FunctionType = decltype(removeChild(p0, p1))(*)(cocos2d::CCSpriteBatchNode*, cocos2d::CCNode*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x176b90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::CCSpriteBatchNode::removeAllChildrenWithCleanup(bool p0) -> decltype(removeAllChildrenWithCleanup(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::CCSpriteBatchNode::removeAllChildrenWithCleanup), this);
	using FunctionType = decltype(removeAllChildrenWithCleanup(p0))(*)(cocos2d::CCSpriteBatchNode*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x176e70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCSpriteBatchNode::reorderChild(cocos2d::CCNode* p0, int p1) -> decltype(reorderChild(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*, int>::func(&cocos2d::CCSpriteBatchNode::reorderChild), this);
	using FunctionType = decltype(reorderChild(p0, p1))(*)(cocos2d::CCSpriteBatchNode*, cocos2d::CCNode*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x176b30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::CCSpriteBatchNode::sortAllChildren() -> decltype(sortAllChildren()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCSpriteBatchNode::sortAllChildren), this);
	using FunctionType = decltype(sortAllChildren())(*)(cocos2d::CCSpriteBatchNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x176f20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCSpriteBatchNode::draw() -> decltype(draw()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCSpriteBatchNode::draw), this);
	using FunctionType = decltype(draw())(*)(cocos2d::CCSpriteBatchNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1776e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCSpriteBatchNode::visit() -> decltype(visit()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCSpriteBatchNode::visit), this);
	using FunctionType = decltype(visit())(*)(cocos2d::CCSpriteBatchNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x176830, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCSpriteBatchNode::setBlendFunc(cocos2d::ccBlendFunc p0) -> decltype(setBlendFunc(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::ccBlendFunc>::func(&cocos2d::CCSpriteBatchNode::setBlendFunc), this);
	using FunctionType = decltype(setBlendFunc(p0))(*)(cocos2d::CCSpriteBatchNode*, cocos2d::ccBlendFunc);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x177f50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCSpriteBatchNode::getBlendFunc() -> decltype(getBlendFunc()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCSpriteBatchNode::getBlendFunc), this);
	using FunctionType = decltype(getBlendFunc())(*)(cocos2d::CCSpriteBatchNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x177f70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCSpriteBatchNode::getTexture() -> decltype(getTexture()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCSpriteBatchNode::getTexture), this);
	using FunctionType = decltype(getTexture())(*)(cocos2d::CCSpriteBatchNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x177f90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCSpriteBatchNode::setTexture(cocos2d::CCTexture2D* p0) -> decltype(setTexture(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTexture2D*>::func(&cocos2d::CCSpriteBatchNode::setTexture), this);
	using FunctionType = decltype(setTexture(p0))(*)(cocos2d::CCSpriteBatchNode*, cocos2d::CCTexture2D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x177fc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCSpriteBatchNode::addSpriteWithoutQuad(cocos2d::CCSprite* p0, unsigned int p1, int p2) -> decltype(addSpriteWithoutQuad(p0, p1, p2)) {
	using FunctionType = decltype(addSpriteWithoutQuad(p0, p1, p2))(*)(cocos2d::CCSpriteBatchNode*, cocos2d::CCSprite*, unsigned int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x178290, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto cocos2d::CCSpriteBatchNode::appendChild(cocos2d::CCSprite* p0) -> decltype(appendChild(p0)) {
	using FunctionType = decltype(appendChild(p0))(*)(cocos2d::CCSpriteBatchNode*, cocos2d::CCSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x176940, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCSpriteBatchNode::atlasIndexForChild(cocos2d::CCSprite* p0, int p1) -> decltype(atlasIndexForChild(p0, p1)) {
	using FunctionType = decltype(atlasIndexForChild(p0, p1))(*)(cocos2d::CCSpriteBatchNode*, cocos2d::CCSprite*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x177a70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCSpriteBatchNode::getAtlasCapacity() -> decltype(getAtlasCapacity()) {
	using FunctionType = decltype(getAtlasCapacity())(*)(cocos2d::CCSpriteBatchNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x177870, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCSpriteBatchNode::getUsedAtlasCapacity() -> decltype(getUsedAtlasCapacity()) {
	using FunctionType = decltype(getUsedAtlasCapacity())(*)(cocos2d::CCSpriteBatchNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x177860, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCSpriteBatchNode::highestAtlasIndexInChild(cocos2d::CCSprite* p0) -> decltype(highestAtlasIndexInChild(p0)) {
	using FunctionType = decltype(highestAtlasIndexInChild(p0))(*)(cocos2d::CCSpriteBatchNode*, cocos2d::CCSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1779b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCSpriteBatchNode::increaseAtlasCapacity() -> decltype(increaseAtlasCapacity()) {
	using FunctionType = decltype(increaseAtlasCapacity())(*)(cocos2d::CCSpriteBatchNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1777c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCSpriteBatchNode::increaseAtlasCapacity(unsigned int p0) -> decltype(increaseAtlasCapacity(p0)) {
	using FunctionType = decltype(increaseAtlasCapacity(p0))(*)(cocos2d::CCSpriteBatchNode*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x177820, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCSpriteBatchNode::initWithFile(char const* p0, unsigned int p1) -> decltype(initWithFile(p0, p1)) {
	using FunctionType = decltype(initWithFile(p0, p1))(*)(cocos2d::CCSpriteBatchNode*, char const*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1765d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCSpriteBatchNode::initWithTexture(cocos2d::CCTexture2D* p0, unsigned int p1) -> decltype(initWithTexture(p0, p1)) {
	using FunctionType = decltype(initWithTexture(p0, p1))(*)(cocos2d::CCSpriteBatchNode*, cocos2d::CCTexture2D*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1763e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCSpriteBatchNode::insertChild(cocos2d::CCSprite* p0, unsigned int p1) -> decltype(insertChild(p0, p1)) {
	using FunctionType = decltype(insertChild(p0, p1))(*)(cocos2d::CCSpriteBatchNode*, cocos2d::CCSprite*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x177c00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCSpriteBatchNode::insertQuadFromSprite(cocos2d::CCSprite* p0, unsigned int p1) -> decltype(insertQuadFromSprite(p0, p1)) {
	using FunctionType = decltype(insertQuadFromSprite(p0, p1))(*)(cocos2d::CCSpriteBatchNode*, cocos2d::CCSprite*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x178070, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCSpriteBatchNode::lowestAtlasIndexInChild(cocos2d::CCSprite* p0) -> decltype(lowestAtlasIndexInChild(p0)) {
	using FunctionType = decltype(lowestAtlasIndexInChild(p0))(*)(cocos2d::CCSpriteBatchNode*, cocos2d::CCSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x177a10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCSpriteBatchNode::manualSortAllChildren() -> decltype(manualSortAllChildren()) {
	using FunctionType = decltype(manualSortAllChildren())(*)(cocos2d::CCSpriteBatchNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x176f10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCSpriteBatchNode::rebuildIndexInOrder(cocos2d::CCSprite* p0, unsigned int p1) -> decltype(rebuildIndexInOrder(p0, p1)) {
	using FunctionType = decltype(rebuildIndexInOrder(p0, p1))(*)(cocos2d::CCSpriteBatchNode*, cocos2d::CCSprite*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x177890, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCSpriteBatchNode::removeChildAtIndex(unsigned int p0, bool p1) -> decltype(removeChildAtIndex(p0, p1)) {
	using FunctionType = decltype(removeChildAtIndex(p0, p1))(*)(cocos2d::CCSpriteBatchNode*, unsigned int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x176e40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCSpriteBatchNode::removeSpriteFromAtlas(cocos2d::CCSprite* p0) -> decltype(removeSpriteFromAtlas(p0)) {
	using FunctionType = decltype(removeSpriteFromAtlas(p0))(*)(cocos2d::CCSpriteBatchNode*, cocos2d::CCSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x176bd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCSpriteBatchNode::reorderBatch(bool p0) -> decltype(reorderBatch(p0)) {
	using FunctionType = decltype(reorderBatch(p0))(*)(cocos2d::CCSpriteBatchNode*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1776d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCSpriteBatchNode::swap(int p0, int p1) -> decltype(swap(p0, p1)) {
	using FunctionType = decltype(swap(p0, p1))(*)(cocos2d::CCSpriteBatchNode*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1775a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCSpriteBatchNode::updateAtlasIndex(cocos2d::CCSprite* p0, int* p1) -> decltype(updateAtlasIndex(p0, p1)) {
	using FunctionType = decltype(updateAtlasIndex(p0, p1))(*)(cocos2d::CCSpriteBatchNode*, cocos2d::CCSprite*, int*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x177060, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCSpriteBatchNode::updateBlendFunc() -> decltype(updateBlendFunc()) {
	using FunctionType = decltype(updateBlendFunc())(*)(cocos2d::CCSpriteBatchNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x176610, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCSpriteBatchNode::updateQuadFromSprite(cocos2d::CCSprite* p0, unsigned int p1) -> decltype(updateQuadFromSprite(p0, p1)) {
	using FunctionType = decltype(updateQuadFromSprite(p0, p1))(*)(cocos2d::CCSpriteBatchNode*, cocos2d::CCSprite*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1781b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}
