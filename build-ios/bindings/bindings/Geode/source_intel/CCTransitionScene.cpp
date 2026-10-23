
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCTransitionScene.hpp>
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

cocos2d::CCTransitionScene::CCTransitionScene() : cocos2d::CCTransitionScene(geode::CutoffConstructor, sizeof(cocos2d::CCTransitionScene)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCTransitionScene::~CCTransitionScene();

	using FunctionType = void(*)(cocos2d::CCTransitionScene*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd46e0, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCTransitionScene::~CCTransitionScene() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCTransitionScene*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0xd4720, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCTransitionScene(geode::CutoffConstructor, sizeof(cocos2d::CCTransitionScene));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCTransitionScene::create(float p0, cocos2d::CCScene* p1) -> decltype(create(p0, p1)) {
	using FunctionType = decltype(create(p0, p1))(*)(float, cocos2d::CCScene*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd4810, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCTransitionScene::onEnter() -> decltype(onEnter()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTransitionScene::onEnter), this);
	using FunctionType = decltype(onEnter())(*)(cocos2d::CCTransitionScene*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd4ba0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTransitionScene::onExit() -> decltype(onExit()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTransitionScene::onExit), this);
	using FunctionType = decltype(onExit())(*)(cocos2d::CCTransitionScene*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd4bf0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTransitionScene::cleanup() -> decltype(cleanup()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTransitionScene::cleanup), this);
	using FunctionType = decltype(cleanup())(*)(cocos2d::CCTransitionScene*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd4c50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTransitionScene::draw() -> decltype(draw()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTransitionScene::draw), this);
	using FunctionType = decltype(draw())(*)(cocos2d::CCTransitionScene*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd4960, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTransitionScene::initWithDuration(float p0, cocos2d::CCScene* p1) -> decltype(initWithDuration(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<float, cocos2d::CCScene*>::func(&cocos2d::CCTransitionScene::initWithDuration), this);
	using FunctionType = decltype(initWithDuration(p0, p1))(*)(cocos2d::CCTransitionScene*, float, cocos2d::CCScene*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd4890, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::CCTransitionScene::sceneOrder() -> decltype(sceneOrder()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCTransitionScene::sceneOrder), this);
	using FunctionType = decltype(sceneOrder())(*)(cocos2d::CCTransitionScene*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd4950, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCTransitionScene::finish() -> decltype(finish()) {
	using FunctionType = decltype(finish())(*)(cocos2d::CCTransitionScene*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd49b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTransitionScene::hideOutShowIn() -> decltype(hideOutShowIn()) {
	using FunctionType = decltype(hideOutShowIn())(*)(cocos2d::CCTransitionScene*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd4b50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTransitionScene::setNewScene(float p0) -> decltype(setNewScene(p0)) {
	using FunctionType = decltype(setNewScene(p0))(*)(cocos2d::CCTransitionScene*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xd4ae0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
