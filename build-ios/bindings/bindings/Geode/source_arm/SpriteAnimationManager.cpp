
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
		static auto func = wrapFunction<FunctionType>(base::get() + 0x636e98, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) SpriteAnimationManager(geode::CutoffConstructor, sizeof(SpriteAnimationManager));
		geode::DestructorLock::addLock(this);
	}
}

auto SpriteAnimationManager::createAnimations(gd::string definition) -> decltype(createAnimations(definition)) {
	using FunctionType = decltype(createAnimations(definition))(*)(gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x633f14, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(definition);
}

auto SpriteAnimationManager::createWithOwner(CCAnimatedSprite* sprite, gd::string definition) -> decltype(createWithOwner(sprite, definition)) {
	using FunctionType = decltype(createWithOwner(sprite, definition))(*)(CCAnimatedSprite*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x633c00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(sprite, definition);
}

auto SpriteAnimationManager::animationFinished() -> decltype(animationFinished()) {
	using FunctionType = decltype(animationFinished())(*)(SpriteAnimationManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x635894, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SpriteAnimationManager::callAnimationFinished() -> decltype(callAnimationFinished()) {
	using FunctionType = decltype(callAnimationFinished())(*)(SpriteAnimationManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6369b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SpriteAnimationManager::doCleanup() -> decltype(doCleanup()) {
	using FunctionType = decltype(doCleanup())(*)(SpriteAnimationManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x636e70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SpriteAnimationManager::executeAnimation(gd::string animation) -> decltype(executeAnimation(animation)) {
	using FunctionType = decltype(executeAnimation(animation))(*)(SpriteAnimationManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x636320, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, animation);
}

auto SpriteAnimationManager::finishAnimation(gd::string animation) -> decltype(finishAnimation(animation)) {
	using FunctionType = decltype(finishAnimation(animation))(*)(SpriteAnimationManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x636ac4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, animation);
}

auto SpriteAnimationManager::getAnimType(gd::string animation) -> decltype(getAnimType(animation)) {
	using FunctionType = decltype(getAnimType(animation))(*)(SpriteAnimationManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6366d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, animation);
}

auto SpriteAnimationManager::getPrio(gd::string animation) -> decltype(getPrio(animation)) {
	using FunctionType = decltype(getPrio(animation))(*)(SpriteAnimationManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x636140, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, animation);
}

auto SpriteAnimationManager::initWithOwner(CCAnimatedSprite* sprite, gd::string definition) -> decltype(initWithOwner(sprite, definition)) {
	using FunctionType = decltype(initWithOwner(sprite, definition))(*)(SpriteAnimationManager*, CCAnimatedSprite*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x633ce8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sprite, definition);
}

auto SpriteAnimationManager::loadAnimations(gd::string definition) -> decltype(loadAnimations(definition)) {
	using FunctionType = decltype(loadAnimations(definition))(*)(SpriteAnimationManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x634e14, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, definition);
}

auto SpriteAnimationManager::offsetCurrentAnimation(float dt) -> decltype(offsetCurrentAnimation(dt)) {
	using FunctionType = decltype(offsetCurrentAnimation(dt))(*)(SpriteAnimationManager*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x636bd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt);
}

auto SpriteAnimationManager::overridePrio() -> decltype(overridePrio()) {
	using FunctionType = decltype(overridePrio())(*)(SpriteAnimationManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6366e8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SpriteAnimationManager::playSound(gd::string sound) -> decltype(playSound(sound)) {
	using FunctionType = decltype(playSound(sound))(*)(SpriteAnimationManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x635dd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sound);
}

auto SpriteAnimationManager::playSoundForAnimation(gd::string animation) -> decltype(playSoundForAnimation(animation)) {
	using FunctionType = decltype(playSoundForAnimation(animation))(*)(SpriteAnimationManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x635bf4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, animation);
}

auto SpriteAnimationManager::queueAnimation(gd::string animation) -> decltype(queueAnimation(animation)) {
	using FunctionType = decltype(queueAnimation(animation))(*)(SpriteAnimationManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x636168, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, animation);
}

auto SpriteAnimationManager::resetAnimState() -> decltype(resetAnimState()) {
	using FunctionType = decltype(resetAnimState())(*)(SpriteAnimationManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x636c48, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SpriteAnimationManager::runAnimation(gd::string animation) -> decltype(runAnimation(animation)) {
	using FunctionType = decltype(runAnimation(animation))(*)(SpriteAnimationManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x635dd4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, animation);
}

auto SpriteAnimationManager::runQueuedAnimation() -> decltype(runQueuedAnimation()) {
	using FunctionType = decltype(runQueuedAnimation())(*)(SpriteAnimationManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x636798, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SpriteAnimationManager::stopAnimations() -> decltype(stopAnimations()) {
	using FunctionType = decltype(stopAnimations())(*)(SpriteAnimationManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6368e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SpriteAnimationManager::storeAnimation(cocos2d::CCAnimate* action, cocos2d::CCAnimate* frames, gd::string name, int priority, spriteMode type, cocos2d::CCSpriteFrame* first) -> decltype(storeAnimation(action, frames, name, priority, type, first)) {
	using FunctionType = decltype(storeAnimation(action, frames, name, priority, type, first))(*)(SpriteAnimationManager*, cocos2d::CCAnimate*, cocos2d::CCAnimate*, gd::string, int, spriteMode, cocos2d::CCSpriteFrame*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6358f8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, action, frames, name, priority, type, first);
}

auto SpriteAnimationManager::storeSoundForAnimation(cocos2d::CCString* sound, gd::string animation, float delay) -> decltype(storeSoundForAnimation(sound, animation, delay)) {
	using FunctionType = decltype(storeSoundForAnimation(sound, animation, delay))(*)(SpriteAnimationManager*, cocos2d::CCString*, gd::string, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x635834, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sound, animation, delay);
}

auto SpriteAnimationManager::switchToFirstFrameOfAnimation(gd::string animation) -> decltype(switchToFirstFrameOfAnimation(animation)) {
	using FunctionType = decltype(switchToFirstFrameOfAnimation(animation))(*)(SpriteAnimationManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x636c80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, animation);
}

auto SpriteAnimationManager::updateAnimationSpeed(float speed) -> decltype(updateAnimationSpeed(speed)) {
	using FunctionType = decltype(updateAnimationSpeed(speed))(*)(SpriteAnimationManager*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x635bb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, speed);
}
