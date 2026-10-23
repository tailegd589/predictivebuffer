
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCParallaxNode.hpp>
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

cocos2d::CCParallaxNode::CCParallaxNode() : cocos2d::CCParallaxNode(geode::CutoffConstructor, sizeof(cocos2d::CCParallaxNode)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCParallaxNode::~CCParallaxNode();

	using FunctionType = void(*)(cocos2d::CCParallaxNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4ae6f0, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCParallaxNode::~CCParallaxNode() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCParallaxNode*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x4ae7f0, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCParallaxNode(geode::CutoffConstructor, sizeof(cocos2d::CCParallaxNode));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCParallaxNode::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4ae8e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCParallaxNode::addChild(cocos2d::CCNode* p0, unsigned int p1, cocos2d::CCPoint const& p2, cocos2d::CCPoint const& p3) -> decltype(addChild(p0, p1, p2, p3)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*, unsigned int, cocos2d::CCPoint const&, cocos2d::CCPoint const&>::func(&cocos2d::CCParallaxNode::addChild), this);
	using FunctionType = decltype(addChild(p0, p1, p2, p3))(*)(cocos2d::CCParallaxNode*, cocos2d::CCNode*, unsigned int, cocos2d::CCPoint const&, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4ae9b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2, p3);
}

auto cocos2d::CCParallaxNode::addChild(cocos2d::CCNode* p0, unsigned int p1, int p2) -> decltype(addChild(p0, p1, p2)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*, unsigned int, int>::func(&cocos2d::CCParallaxNode::addChild), this);
	using FunctionType = decltype(addChild(p0, p1, p2))(*)(cocos2d::CCParallaxNode*, cocos2d::CCNode*, unsigned int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4ae9a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2);
}

auto cocos2d::CCParallaxNode::removeChild(cocos2d::CCNode* p0, bool p1) -> decltype(removeChild(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*, bool>::func(&cocos2d::CCParallaxNode::removeChild), this);
	using FunctionType = decltype(removeChild(p0, p1))(*)(cocos2d::CCParallaxNode*, cocos2d::CCNode*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4aeb70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::CCParallaxNode::removeAllChildrenWithCleanup(bool p0) -> decltype(removeAllChildrenWithCleanup(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::CCParallaxNode::removeAllChildrenWithCleanup), this);
	using FunctionType = decltype(removeAllChildrenWithCleanup(p0))(*)(cocos2d::CCParallaxNode*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4aebf0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCParallaxNode::visit() -> decltype(visit()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCParallaxNode::visit), this);
	using FunctionType = decltype(visit())(*)(cocos2d::CCParallaxNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4aecb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCParallaxNode::absolutePosition() -> decltype(absolutePosition()) {
	using FunctionType = decltype(absolutePosition())(*)(cocos2d::CCParallaxNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4aec20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
