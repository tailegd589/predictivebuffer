
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCActionManager.hpp>
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

cocos2d::CCActionManager::CCActionManager() : cocos2d::CCActionManager(geode::CutoffConstructor, sizeof(cocos2d::CCActionManager)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCActionManager::~CCActionManager();

	using FunctionType = void(*)(cocos2d::CCActionManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1dd1a4, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCActionManager::~CCActionManager() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCActionManager*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x1dd1cc, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCActionManager(geode::CutoffConstructor, sizeof(cocos2d::CCActionManager));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCActionManager::update(float p0) -> decltype(update(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCActionManager::update), this);
	using FunctionType = decltype(update(p0))(*)(cocos2d::CCActionManager*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1de410, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCActionManager::actionAllocWithHashElement(cocos2d::_hashElement* p0) -> decltype(actionAllocWithHashElement(p0)) {
	using FunctionType = decltype(actionAllocWithHashElement(p0))(*)(cocos2d::CCActionManager*, cocos2d::_hashElement*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1dd41c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCActionManager::addAction(cocos2d::CCAction* p0, cocos2d::CCNode* p1, bool p2) -> decltype(addAction(p0, p1, p2)) {
	using FunctionType = decltype(addAction(p0, p1, p2))(*)(cocos2d::CCActionManager*, cocos2d::CCAction*, cocos2d::CCNode*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1dd834, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto cocos2d::CCActionManager::deleteHashElement(cocos2d::_hashElement* p0) -> decltype(deleteHashElement(p0)) {
	using FunctionType = decltype(deleteHashElement(p0))(*)(cocos2d::CCActionManager*, cocos2d::_hashElement*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1dd2ec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCActionManager::getActionByTag(unsigned int p0, cocos2d::CCObject* p1) -> decltype(getActionByTag(p0, p1)) {
	using FunctionType = decltype(getActionByTag(p0, p1))(*)(cocos2d::CCActionManager*, unsigned int, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1de1d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCActionManager::numberOfRunningActionsInTarget(cocos2d::CCObject* target) -> decltype(numberOfRunningActionsInTarget(target)) {
	using FunctionType = decltype(numberOfRunningActionsInTarget(target))(*)(cocos2d::CCActionManager*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1de304, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, target);
}

auto cocos2d::CCActionManager::pauseAllRunningActions() -> decltype(pauseAllRunningActions()) {
	using FunctionType = decltype(pauseAllRunningActions())(*)(cocos2d::CCActionManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1dd718, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCActionManager::pauseTarget(cocos2d::CCObject* p0) -> decltype(pauseTarget(p0)) {
	using FunctionType = decltype(pauseTarget(p0))(*)(cocos2d::CCActionManager*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1dd524, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCActionManager::removeAction(cocos2d::CCAction* p0) -> decltype(removeAction(p0)) {
	using FunctionType = decltype(removeAction(p0))(*)(cocos2d::CCActionManager*, cocos2d::CCAction*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1dde28, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCActionManager::removeActionAtIndex(unsigned int p0, cocos2d::_hashElement* p1) -> decltype(removeActionAtIndex(p0, p1)) {
	using FunctionType = decltype(removeActionAtIndex(p0, p1))(*)(cocos2d::CCActionManager*, unsigned int, cocos2d::_hashElement*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1dd45c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCActionManager::removeActionByTag(unsigned int p0, cocos2d::CCObject* p1) -> decltype(removeActionByTag(p0, p1)) {
	using FunctionType = decltype(removeActionByTag(p0, p1))(*)(cocos2d::CCActionManager*, unsigned int, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1ddfe0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCActionManager::removeAllActions() -> decltype(removeAllActions()) {
	using FunctionType = decltype(removeAllActions())(*)(cocos2d::CCActionManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1dd218, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCActionManager::removeAllActionsFromTarget(cocos2d::CCObject* p0) -> decltype(removeAllActionsFromTarget(p0)) {
	using FunctionType = decltype(removeAllActionsFromTarget(p0))(*)(cocos2d::CCActionManager*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1ddca4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCActionManager::resumeTarget(cocos2d::CCObject* p0) -> decltype(resumeTarget(p0)) {
	using FunctionType = decltype(resumeTarget(p0))(*)(cocos2d::CCActionManager*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1dd620, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCActionManager::resumeTargets(cocos2d::CCSet* p0) -> decltype(resumeTargets(p0)) {
	using FunctionType = decltype(resumeTargets(p0))(*)(cocos2d::CCActionManager*, cocos2d::CCSet*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1dd7a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
