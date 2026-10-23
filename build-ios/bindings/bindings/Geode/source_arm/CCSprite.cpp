
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCSprite.hpp>
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

cocos2d::CCSprite::CCSprite() : cocos2d::CCSprite(geode::CutoffConstructor, sizeof(cocos2d::CCSprite)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCSprite::~CCSprite();

	using FunctionType = void(*)(cocos2d::CCSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22a200, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCSprite::~CCSprite() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCSprite*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x22a288, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCSprite(geode::CutoffConstructor, sizeof(cocos2d::CCSprite));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCSprite::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x229d88, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCSprite::create(char const* p0) -> decltype(create(p0)) {
	using FunctionType = decltype(create(p0))(*)(char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x229a78, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::CCSprite::create(char const* p0, cocos2d::CCRect const& p1) -> decltype(create(p0, p1)) {
	using FunctionType = decltype(create(p0, p1))(*)(char const*, cocos2d::CCRect const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x229b68, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCSprite::createWithSpriteFrame(cocos2d::CCSpriteFrame* p0) -> decltype(createWithSpriteFrame(p0)) {
	using FunctionType = decltype(createWithSpriteFrame(p0))(*)(cocos2d::CCSpriteFrame*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x229c6c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::CCSprite::createWithSpriteFrameName(char const* p0) -> decltype(createWithSpriteFrameName(p0)) {
	using FunctionType = decltype(createWithSpriteFrameName(p0))(*)(char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x229d60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::CCSprite::createWithTexture(cocos2d::CCTexture2D* p0) -> decltype(createWithTexture(p0)) {
	using FunctionType = decltype(createWithTexture(p0))(*)(cocos2d::CCTexture2D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2297fc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::CCSprite::createWithTexture(cocos2d::CCTexture2D* p0, cocos2d::CCRect const& p1) -> decltype(createWithTexture(p0, p1)) {
	using FunctionType = decltype(createWithTexture(p0, p1))(*)(cocos2d::CCTexture2D*, cocos2d::CCRect const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x229974, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCSprite::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCSprite::init), this);
	using FunctionType = decltype(init())(*)(cocos2d::CCSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x229e70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCSprite::setVertexZ(float p0) -> decltype(setVertexZ(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCSprite::setVertexZ), this);
	using FunctionType = decltype(setVertexZ(p0))(*)(cocos2d::CCSprite*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22b6a8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCSprite::setScaleX(float p0) -> decltype(setScaleX(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCSprite::setScaleX), this);
	using FunctionType = decltype(setScaleX(p0))(*)(cocos2d::CCSprite*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22b518, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCSprite::setScaleY(float p0) -> decltype(setScaleY(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCSprite::setScaleY), this);
	using FunctionType = decltype(setScaleY(p0))(*)(cocos2d::CCSprite*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22b598, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCSprite::setScale(float p0) -> decltype(setScale(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCSprite::setScale), this);
	using FunctionType = decltype(setScale(p0))(*)(cocos2d::CCSprite*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22b618, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCSprite::setPosition(cocos2d::CCPoint const& p0) -> decltype(setPosition(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCPoint const&>::func(&cocos2d::CCSprite::setPosition), this);
	using FunctionType = decltype(setPosition(p0))(*)(cocos2d::CCSprite*, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22b23c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCSprite::setSkewX(float p0) -> decltype(setSkewX(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCSprite::setSkewX), this);
	using FunctionType = decltype(setSkewX(p0))(*)(cocos2d::CCSprite*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22b430, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCSprite::setSkewY(float p0) -> decltype(setSkewY(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCSprite::setSkewY), this);
	using FunctionType = decltype(setSkewY(p0))(*)(cocos2d::CCSprite*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22b4a4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCSprite::setAnchorPoint(cocos2d::CCPoint const& p0) -> decltype(setAnchorPoint(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCPoint const&>::func(&cocos2d::CCSprite::setAnchorPoint), this);
	using FunctionType = decltype(setAnchorPoint(p0))(*)(cocos2d::CCSprite*, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22b71c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCSprite::setVisible(bool p0) -> decltype(setVisible(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::CCSprite::setVisible), this);
	using FunctionType = decltype(setVisible(p0))(*)(cocos2d::CCSprite*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22b794, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCSprite::setRotation(float p0) -> decltype(setRotation(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCSprite::setRotation), this);
	using FunctionType = decltype(setRotation(p0))(*)(cocos2d::CCSprite*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22b2d4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCSprite::setRotationX(float p0) -> decltype(setRotationX(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCSprite::setRotationX), this);
	using FunctionType = decltype(setRotationX(p0))(*)(cocos2d::CCSprite*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22b348, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCSprite::setRotationY(float p0) -> decltype(setRotationY(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCSprite::setRotationY), this);
	using FunctionType = decltype(setRotationY(p0))(*)(cocos2d::CCSprite*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22b3bc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCSprite::ignoreAnchorPointForPosition(bool p0) -> decltype(ignoreAnchorPointForPosition(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::CCSprite::ignoreAnchorPointForPosition), this);
	using FunctionType = decltype(ignoreAnchorPointForPosition(p0))(*)(cocos2d::CCSprite*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22b790, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCSprite::addChild(cocos2d::CCNode* p0) -> decltype(addChild(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*>::func(&cocos2d::CCSprite::addChild), this);
	using FunctionType = decltype(addChild(p0))(*)(cocos2d::CCSprite*, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22ad68, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCSprite::addChild(cocos2d::CCNode* p0, int p1) -> decltype(addChild(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*, int>::func(&cocos2d::CCSprite::addChild), this);
	using FunctionType = decltype(addChild(p0, p1))(*)(cocos2d::CCSprite*, cocos2d::CCNode*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22ad6c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::CCSprite::addChild(cocos2d::CCNode* p0, int p1, int p2) -> decltype(addChild(p0, p1, p2)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*, int, int>::func(&cocos2d::CCSprite::addChild), this);
	using FunctionType = decltype(addChild(p0, p1, p2))(*)(cocos2d::CCSprite*, cocos2d::CCNode*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22ad70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2);
}

auto cocos2d::CCSprite::removeChild(cocos2d::CCNode* p0, bool p1) -> decltype(removeChild(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*, bool>::func(&cocos2d::CCSprite::removeChild), this);
	using FunctionType = decltype(removeChild(p0, p1))(*)(cocos2d::CCSprite*, cocos2d::CCNode*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22aed8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::CCSprite::removeAllChildrenWithCleanup(bool p0) -> decltype(removeAllChildrenWithCleanup(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::CCSprite::removeAllChildrenWithCleanup), this);
	using FunctionType = decltype(removeAllChildrenWithCleanup(p0))(*)(cocos2d::CCSprite*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22af20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCSprite::reorderChild(cocos2d::CCNode* p0, int p1) -> decltype(reorderChild(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*, int>::func(&cocos2d::CCSprite::reorderChild), this);
	using FunctionType = decltype(reorderChild(p0, p1))(*)(cocos2d::CCSprite*, cocos2d::CCNode*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22ae44, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::CCSprite::sortAllChildren() -> decltype(sortAllChildren()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCSprite::sortAllChildren), this);
	using FunctionType = decltype(sortAllChildren())(*)(cocos2d::CCSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22afd4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCSprite::draw() -> decltype(draw()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCSprite::draw), this);
	using FunctionType = decltype(draw())(*)(cocos2d::CCSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22ac58, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCSprite::updateTransform() -> decltype(updateTransform()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCSprite::updateTransform), this);
	using FunctionType = decltype(updateTransform())(*)(cocos2d::CCSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22a86c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCSprite::initWithTexture(cocos2d::CCTexture2D* p0) -> decltype(initWithTexture(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTexture2D*>::func(&cocos2d::CCSprite::initWithTexture), this);
	using FunctionType = decltype(initWithTexture(p0))(*)(cocos2d::CCSprite*, cocos2d::CCTexture2D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x229fec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCSprite::initWithTexture(cocos2d::CCTexture2D* p0, cocos2d::CCRect const& p1) -> decltype(initWithTexture(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTexture2D*, cocos2d::CCRect const&>::func(&cocos2d::CCSprite::initWithTexture), this);
	using FunctionType = decltype(initWithTexture(p0, p1))(*)(cocos2d::CCSprite*, cocos2d::CCTexture2D*, cocos2d::CCRect const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x229fdc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::CCSprite::initWithTexture(cocos2d::CCTexture2D* p0, cocos2d::CCRect const& p1, bool p2) -> decltype(initWithTexture(p0, p1, p2)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTexture2D*, cocos2d::CCRect const&, bool>::func(&cocos2d::CCSprite::initWithTexture), this);
	using FunctionType = decltype(initWithTexture(p0, p1, p2))(*)(cocos2d::CCSprite*, cocos2d::CCTexture2D*, cocos2d::CCRect const&, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x229e88, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2);
}

auto cocos2d::CCSprite::initWithSpriteFrame(cocos2d::CCSpriteFrame* p0) -> decltype(initWithSpriteFrame(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCSpriteFrame*>::func(&cocos2d::CCSprite::initWithSpriteFrame), this);
	using FunctionType = decltype(initWithSpriteFrame(p0))(*)(cocos2d::CCSprite*, cocos2d::CCSpriteFrame*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22a160, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCSprite::initWithSpriteFrameName(char const* p0) -> decltype(initWithSpriteFrameName(p0)) {
	auto self = addresser::thunkAdjust(Resolve<char const*>::func(&cocos2d::CCSprite::initWithSpriteFrameName), this);
	using FunctionType = decltype(initWithSpriteFrameName(p0))(*)(cocos2d::CCSprite*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22a1c4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCSprite::initWithFile(char const* p0) -> decltype(initWithFile(p0)) {
	auto self = addresser::thunkAdjust(Resolve<char const*>::func(&cocos2d::CCSprite::initWithFile), this);
	using FunctionType = decltype(initWithFile(p0))(*)(cocos2d::CCSprite*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22a068, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCSprite::initWithFile(char const* p0, cocos2d::CCRect const& p1) -> decltype(initWithFile(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<char const*, cocos2d::CCRect const&>::func(&cocos2d::CCSprite::initWithFile), this);
	using FunctionType = decltype(initWithFile(p0, p1))(*)(cocos2d::CCSprite*, char const*, cocos2d::CCRect const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22a0fc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::CCSprite::setChildColor(cocos2d::ccColor3B const& p0) -> decltype(setChildColor(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::ccColor3B const&>::func(&cocos2d::CCSprite::setChildColor), this);
	using FunctionType = decltype(setChildColor(p0))(*)(cocos2d::CCSprite*, cocos2d::ccColor3B const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22bb8c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCSprite::setChildOpacity(unsigned char p0) -> decltype(setChildOpacity(p0)) {
	auto self = addresser::thunkAdjust(Resolve<unsigned char>::func(&cocos2d::CCSprite::setChildOpacity), this);
	using FunctionType = decltype(setChildOpacity(p0))(*)(cocos2d::CCSprite*, unsigned char);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22ba30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCSprite::getBatchNode() -> decltype(getBatchNode()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCSprite::getBatchNode), this);
	using FunctionType = decltype(getBatchNode())(*)(cocos2d::CCSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22bf94, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCSprite::setBatchNode(cocos2d::CCSpriteBatchNode* p0) -> decltype(setBatchNode(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCSpriteBatchNode*>::func(&cocos2d::CCSprite::setBatchNode), this);
	using FunctionType = decltype(setBatchNode(p0))(*)(cocos2d::CCSprite*, cocos2d::CCSpriteBatchNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22bf9c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCSprite::refreshTextureRect() -> decltype(refreshTextureRect()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCSprite::refreshTextureRect), this);
	using FunctionType = decltype(refreshTextureRect())(*)(cocos2d::CCSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22a370, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCSprite::setTextureRect(cocos2d::CCRect const& p0) -> decltype(setTextureRect(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCRect const&>::func(&cocos2d::CCSprite::setTextureRect), this);
	using FunctionType = decltype(setTextureRect(p0))(*)(cocos2d::CCSprite*, cocos2d::CCRect const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22a3f4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCSprite::setTextureRect(cocos2d::CCRect const& p0, bool p1, cocos2d::CCSize const& p2) -> decltype(setTextureRect(p0, p1, p2)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCRect const&, bool, cocos2d::CCSize const&>::func(&cocos2d::CCSprite::setTextureRect), this);
	using FunctionType = decltype(setTextureRect(p0, p1, p2))(*)(cocos2d::CCSprite*, cocos2d::CCRect const&, bool, cocos2d::CCSize const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22a408, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2);
}

auto cocos2d::CCSprite::setVertexRect(cocos2d::CCRect const& p0) -> decltype(setVertexRect(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCRect const&>::func(&cocos2d::CCSprite::setVertexRect), this);
	using FunctionType = decltype(setVertexRect(p0))(*)(cocos2d::CCSprite*, cocos2d::CCRect const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22a698, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCSprite::setDisplayFrame(cocos2d::CCSpriteFrame* p0) -> decltype(setDisplayFrame(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCSpriteFrame*>::func(&cocos2d::CCSprite::setDisplayFrame), this);
	using FunctionType = decltype(setDisplayFrame(p0))(*)(cocos2d::CCSprite*, cocos2d::CCSpriteFrame*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22bd14, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCSprite::isFrameDisplayed(cocos2d::CCSpriteFrame* p0) -> decltype(isFrameDisplayed(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCSpriteFrame*>::func(&cocos2d::CCSprite::isFrameDisplayed), this);
	using FunctionType = decltype(isFrameDisplayed(p0))(*)(cocos2d::CCSprite*, cocos2d::CCSpriteFrame*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22bde8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCSprite::displayFrame() -> decltype(displayFrame()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCSprite::displayFrame), this);
	using FunctionType = decltype(displayFrame())(*)(cocos2d::CCSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22be8c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCSprite::setDisplayFrameWithAnimationName(char const* p0, int p1) -> decltype(setDisplayFrameWithAnimationName(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<char const*, int>::func(&cocos2d::CCSprite::setDisplayFrameWithAnimationName), this);
	using FunctionType = decltype(setDisplayFrameWithAnimationName(p0, p1))(*)(cocos2d::CCSprite*, char const*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22bd94, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::CCSprite::setTextureCoords(cocos2d::CCRect const& p0) -> decltype(setTextureCoords(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCRect const&>::func(&cocos2d::CCSprite::setTextureCoords), this);
	using FunctionType = decltype(setTextureCoords(p0))(*)(cocos2d::CCSprite*, cocos2d::CCRect const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22a6a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCSprite::updateBlendFunc() -> decltype(updateBlendFunc()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCSprite::updateBlendFunc), this);
	using FunctionType = decltype(updateBlendFunc())(*)(cocos2d::CCSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22bfe8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCSprite::setReorderChildDirtyRecursively() -> decltype(setReorderChildDirtyRecursively()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCSprite::setReorderChildDirtyRecursively), this);
	using FunctionType = decltype(setReorderChildDirtyRecursively())(*)(cocos2d::CCSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22b158, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCSprite::setDirtyRecursively(bool p0) -> decltype(setDirtyRecursively(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::CCSprite::setDirtyRecursively), this);
	using FunctionType = decltype(setDirtyRecursively(p0))(*)(cocos2d::CCSprite*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22b1c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCSprite::setOpacity(unsigned char p0) -> decltype(setOpacity(p0)) {
	auto self = addresser::thunkAdjust(Resolve<unsigned char>::func(&cocos2d::CCSprite::setOpacity), this);
	using FunctionType = decltype(setOpacity(p0))(*)(cocos2d::CCSprite*, unsigned char);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22b938, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCSprite::updateDisplayedOpacity(unsigned char p0) -> decltype(updateDisplayedOpacity(p0)) {
	auto self = addresser::thunkAdjust(Resolve<unsigned char>::func(&cocos2d::CCSprite::updateDisplayedOpacity), this);
	using FunctionType = decltype(updateDisplayedOpacity(p0))(*)(cocos2d::CCSprite*, unsigned char);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22bcc8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCSprite::setColor(cocos2d::ccColor3B const& p0) -> decltype(setColor(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::ccColor3B const&>::func(&cocos2d::CCSprite::setColor), this);
	using FunctionType = decltype(setColor(p0))(*)(cocos2d::CCSprite*, cocos2d::ccColor3B const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22bad8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCSprite::updateDisplayedColor(cocos2d::ccColor3B const& p0) -> decltype(updateDisplayedColor(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::ccColor3B const&>::func(&cocos2d::CCSprite::updateDisplayedColor), this);
	using FunctionType = decltype(updateDisplayedColor(p0))(*)(cocos2d::CCSprite*, cocos2d::ccColor3B const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22bc7c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCSprite::setOpacityModifyRGB(bool p0) -> decltype(setOpacityModifyRGB(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::CCSprite::setOpacityModifyRGB), this);
	using FunctionType = decltype(setOpacityModifyRGB(p0))(*)(cocos2d::CCSprite*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22bc34, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCSprite::isOpacityModifyRGB() -> decltype(isOpacityModifyRGB()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCSprite::isOpacityModifyRGB), this);
	using FunctionType = decltype(isOpacityModifyRGB())(*)(cocos2d::CCSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22bc6c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCSprite::setTexture(cocos2d::CCTexture2D* p0) -> decltype(setTexture(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTexture2D*>::func(&cocos2d::CCSprite::setTexture), this);
	using FunctionType = decltype(setTexture(p0))(*)(cocos2d::CCSprite*, cocos2d::CCTexture2D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22c044, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCSprite::getTexture() -> decltype(getTexture()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCSprite::getTexture), this);
	using FunctionType = decltype(getTexture())(*)(cocos2d::CCSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22c184, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCSprite::isFlipX() -> decltype(isFlipX()) {
	using FunctionType = decltype(isFlipX())(*)(cocos2d::CCSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22b834, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCSprite::isFlipY() -> decltype(isFlipY()) {
	using FunctionType = decltype(isFlipY())(*)(cocos2d::CCSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22b868, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCSprite::setFlipX(bool p0) -> decltype(setFlipX(p0)) {
	using FunctionType = decltype(setFlipX(p0))(*)(cocos2d::CCSprite*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22b808, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCSprite::setFlipY(bool p0) -> decltype(setFlipY(p0)) {
	using FunctionType = decltype(setFlipY(p0))(*)(cocos2d::CCSprite*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22b83c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCSprite::updateColor() -> decltype(updateColor()) {
	using FunctionType = decltype(updateColor())(*)(cocos2d::CCSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x22b870, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
