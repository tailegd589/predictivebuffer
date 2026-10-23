
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/SpriteAnimationManager.hpp>
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

SpriteAnimationManager::~SpriteAnimationManager() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(SpriteAnimationManager*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x7246a0, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) SpriteAnimationManager(geode::CutoffConstructor, sizeof(SpriteAnimationManager));
		geode::DestructorLock::addLock(this);
	}
}

auto SpriteAnimationManager::createAnimations(gd::string definition) -> decltype(createAnimations(definition)) {
	using FunctionType = decltype(createAnimations(definition))(*)(gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7212c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(definition);
}

auto SpriteAnimationManager::createWithOwner(CCAnimatedSprite* sprite, gd::string definition) -> decltype(createWithOwner(sprite, definition)) {
	using FunctionType = decltype(createWithOwner(sprite, definition))(*)(CCAnimatedSprite*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x720fa0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(sprite, definition);
}

auto SpriteAnimationManager::animationFinished() -> decltype(animationFinished()) {
	using FunctionType = decltype(animationFinished())(*)(SpriteAnimationManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x722f20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SpriteAnimationManager::callAnimationFinished() -> decltype(callAnimationFinished()) {
	using FunctionType = decltype(callAnimationFinished())(*)(SpriteAnimationManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7241b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SpriteAnimationManager::doCleanup() -> decltype(doCleanup()) {
	using FunctionType = decltype(doCleanup())(*)(SpriteAnimationManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x724670, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SpriteAnimationManager::executeAnimation(gd::string animation) -> decltype(executeAnimation(animation)) {
	using FunctionType = decltype(executeAnimation(animation))(*)(SpriteAnimationManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x723ab0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, animation);
}

auto SpriteAnimationManager::finishAnimation(gd::string animation) -> decltype(finishAnimation(animation)) {
	using FunctionType = decltype(finishAnimation(animation))(*)(SpriteAnimationManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7242c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, animation);
}

auto SpriteAnimationManager::getAnimType(gd::string animation) -> decltype(getAnimType(animation)) {
	using FunctionType = decltype(getAnimType(animation))(*)(SpriteAnimationManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x723ec0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, animation);
}

auto SpriteAnimationManager::getPrio(gd::string animation) -> decltype(getPrio(animation)) {
	using FunctionType = decltype(getPrio(animation))(*)(SpriteAnimationManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7238c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, animation);
}

auto SpriteAnimationManager::initWithOwner(CCAnimatedSprite* sprite, gd::string definition) -> decltype(initWithOwner(sprite, definition)) {
	using FunctionType = decltype(initWithOwner(sprite, definition))(*)(SpriteAnimationManager*, CCAnimatedSprite*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7210a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sprite, definition);
}

auto SpriteAnimationManager::loadAnimations(gd::string definition) -> decltype(loadAnimations(definition)) {
	using FunctionType = decltype(loadAnimations(definition))(*)(SpriteAnimationManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x722270, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, definition);
}

auto SpriteAnimationManager::offsetCurrentAnimation(float dt) -> decltype(offsetCurrentAnimation(dt)) {
	using FunctionType = decltype(offsetCurrentAnimation(dt))(*)(SpriteAnimationManager*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x724410, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt);
}

auto SpriteAnimationManager::overridePrio() -> decltype(overridePrio()) {
	using FunctionType = decltype(overridePrio())(*)(SpriteAnimationManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x723ee0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SpriteAnimationManager::playSound(gd::string sound) -> decltype(playSound(sound)) {
	using FunctionType = decltype(playSound(sound))(*)(SpriteAnimationManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7234c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sound);
}

auto SpriteAnimationManager::playSoundForAnimation(gd::string animation) -> decltype(playSoundForAnimation(animation)) {
	using FunctionType = decltype(playSoundForAnimation(animation))(*)(SpriteAnimationManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7232d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, animation);
}

auto SpriteAnimationManager::queueAnimation(gd::string animation) -> decltype(queueAnimation(animation)) {
	using FunctionType = decltype(queueAnimation(animation))(*)(SpriteAnimationManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7238f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, animation);
}

auto SpriteAnimationManager::resetAnimState() -> decltype(resetAnimState()) {
	using FunctionType = decltype(resetAnimState())(*)(SpriteAnimationManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x724470, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SpriteAnimationManager::runAnimation(gd::string animation) -> decltype(runAnimation(animation)) {
	using FunctionType = decltype(runAnimation(animation))(*)(SpriteAnimationManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7234d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, animation);
}

auto SpriteAnimationManager::runQueuedAnimation() -> decltype(runQueuedAnimation()) {
	using FunctionType = decltype(runQueuedAnimation())(*)(SpriteAnimationManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x723f90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SpriteAnimationManager::stopAnimations() -> decltype(stopAnimations()) {
	using FunctionType = decltype(stopAnimations())(*)(SpriteAnimationManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7240e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SpriteAnimationManager::storeAnimation(cocos2d::CCAnimate* action, cocos2d::CCAnimate* frames, gd::string name, int priority, spriteMode type, cocos2d::CCSpriteFrame* first) -> decltype(storeAnimation(action, frames, name, priority, type, first)) {
	using FunctionType = decltype(storeAnimation(action, frames, name, priority, type, first))(*)(SpriteAnimationManager*, cocos2d::CCAnimate*, cocos2d::CCAnimate*, gd::string, int, spriteMode, cocos2d::CCSpriteFrame*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x722f80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, action, frames, name, priority, type, first);
}

auto SpriteAnimationManager::storeSoundForAnimation(cocos2d::CCString* sound, gd::string animation, float delay) -> decltype(storeSoundForAnimation(sound, animation, delay)) {
	using FunctionType = decltype(storeSoundForAnimation(sound, animation, delay))(*)(SpriteAnimationManager*, cocos2d::CCString*, gd::string, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x722ec0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sound, animation, delay);
}

auto SpriteAnimationManager::switchToFirstFrameOfAnimation(gd::string animation) -> decltype(switchToFirstFrameOfAnimation(animation)) {
	using FunctionType = decltype(switchToFirstFrameOfAnimation(animation))(*)(SpriteAnimationManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7244b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, animation);
}

auto SpriteAnimationManager::updateAnimationSpeed(float speed) -> decltype(updateAnimationSpeed(speed)) {
	using FunctionType = decltype(updateAnimationSpeed(speed))(*)(SpriteAnimationManager*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x723270, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, speed);
}
