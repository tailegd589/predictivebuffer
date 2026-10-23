
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCClippingNode.hpp>
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

cocos2d::CCClippingNode::CCClippingNode() : cocos2d::CCClippingNode(geode::CutoffConstructor, sizeof(cocos2d::CCClippingNode)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCClippingNode::~CCClippingNode();

	using FunctionType = void(*)(cocos2d::CCClippingNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6320b0, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCClippingNode::~CCClippingNode() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCClippingNode*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x632108, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCClippingNode(geode::CutoffConstructor, sizeof(cocos2d::CCClippingNode));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCClippingNode::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6321c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCClippingNode::create(cocos2d::CCNode* stencil) -> decltype(create(stencil)) {
	using FunctionType = decltype(create(stencil))(*)(cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x632248, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(stencil);
}

auto cocos2d::CCClippingNode::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCClippingNode::init), this);
	using FunctionType = decltype(init())(*)(cocos2d::CCClippingNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6322e8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCClippingNode::init(cocos2d::CCNode* pStencil) -> decltype(init(pStencil)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*>::func(&cocos2d::CCClippingNode::init), this);
	using FunctionType = decltype(init(pStencil))(*)(cocos2d::CCClippingNode*, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6322f8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, pStencil);
}

auto cocos2d::CCClippingNode::onEnter() -> decltype(onEnter()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCClippingNode::onEnter), this);
	using FunctionType = decltype(onEnter())(*)(cocos2d::CCClippingNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x632368, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCClippingNode::onEnterTransitionDidFinish() -> decltype(onEnterTransitionDidFinish()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCClippingNode::onEnterTransitionDidFinish), this);
	using FunctionType = decltype(onEnterTransitionDidFinish())(*)(cocos2d::CCClippingNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x632394, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCClippingNode::onExit() -> decltype(onExit()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCClippingNode::onExit), this);
	using FunctionType = decltype(onExit())(*)(cocos2d::CCClippingNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6323f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCClippingNode::onExitTransitionDidStart() -> decltype(onExitTransitionDidStart()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCClippingNode::onExitTransitionDidStart), this);
	using FunctionType = decltype(onExitTransitionDidStart())(*)(cocos2d::CCClippingNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6323c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCClippingNode::visit() -> decltype(visit()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCClippingNode::visit), this);
	using FunctionType = decltype(visit())(*)(cocos2d::CCClippingNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x632420, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCClippingNode::getAlphaThreshold() const  -> decltype(getAlphaThreshold()) {
	using FunctionType = decltype(getAlphaThreshold())(*)(cocos2d::CCClippingNode const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6327a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCClippingNode::getStencil() const  -> decltype(getStencil()) {
	using FunctionType = decltype(getStencil())(*)(cocos2d::CCClippingNode const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x632754, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCClippingNode::isInverted() const  -> decltype(isInverted()) {
	using FunctionType = decltype(isInverted())(*)(cocos2d::CCClippingNode const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6327b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCClippingNode::setAlphaThreshold(float fAlphaThreshold) -> decltype(setAlphaThreshold(fAlphaThreshold)) {
	using FunctionType = decltype(setAlphaThreshold(fAlphaThreshold))(*)(cocos2d::CCClippingNode*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6327a8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, fAlphaThreshold);
}

auto cocos2d::CCClippingNode::setInverted(bool bInverted) -> decltype(setInverted(bInverted)) {
	using FunctionType = decltype(setInverted(bInverted))(*)(cocos2d::CCClippingNode*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6327b8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, bInverted);
}

auto cocos2d::CCClippingNode::setStencil(cocos2d::CCNode* pStencil) -> decltype(setStencil(pStencil)) {
	using FunctionType = decltype(setStencil(pStencil))(*)(cocos2d::CCClippingNode*, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x63275c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, pStencil);
}
