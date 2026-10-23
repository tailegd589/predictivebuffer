
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/PlayerObject.hpp>
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

PlayerObject::PlayerObject() : PlayerObject(geode::CutoffConstructor, sizeof(PlayerObject)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	PlayerObject::~PlayerObject();

	using FunctionType = void(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39215c, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

PlayerObject::~PlayerObject() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(PlayerObject*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x372f0c, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) PlayerObject(geode::CutoffConstructor, sizeof(PlayerObject));
		geode::DestructorLock::addLock(this);
	}
}

auto PlayerObject::create(int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer) -> decltype(create(player, ship, gameLayer, layer, playLayer)) {
	using FunctionType = decltype(create(player, ship, gameLayer, layer, playLayer))(*)(int, int, GJBaseGameLayer*, cocos2d::CCLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x373100, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(player, ship, gameLayer, layer, playLayer);
}

auto PlayerObject::update(float dt) -> decltype(update(dt)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&PlayerObject::update), this);
	using FunctionType = decltype(update(dt))(*)(PlayerObject*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x375754, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, dt);
}

auto PlayerObject::setScaleX(float scale) -> decltype(setScaleX(scale)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&PlayerObject::setScaleX), this);
	using FunctionType = decltype(setScaleX(scale))(*)(PlayerObject*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x391b90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, scale);
}

auto PlayerObject::setScaleY(float scale) -> decltype(setScaleY(scale)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&PlayerObject::setScaleY), this);
	using FunctionType = decltype(setScaleY(scale))(*)(PlayerObject*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x391b94, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, scale);
}

auto PlayerObject::setScale(float scale) -> decltype(setScale(scale)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&PlayerObject::setScale), this);
	using FunctionType = decltype(setScale(scale))(*)(PlayerObject*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x391b98, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, scale);
}

auto PlayerObject::setPosition(cocos2d::CCPoint const& position) -> decltype(setPosition(position)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCPoint const&>::func(&PlayerObject::setPosition), this);
	using FunctionType = decltype(setPosition(position))(*)(PlayerObject*, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38e200, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, position);
}

auto PlayerObject::setVisible(bool visible) -> decltype(setVisible(visible)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&PlayerObject::setVisible), this);
	using FunctionType = decltype(setVisible(visible))(*)(PlayerObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x391b9c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, visible);
}

auto PlayerObject::setRotation(float rotation) -> decltype(setRotation(rotation)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&PlayerObject::setRotation), this);
	using FunctionType = decltype(setRotation(rotation))(*)(PlayerObject*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x391b20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, rotation);
}

auto PlayerObject::setOpacity(unsigned char opacity) -> decltype(setOpacity(opacity)) {
	auto self = addresser::thunkAdjust(Resolve<unsigned char>::func(&PlayerObject::setOpacity), this);
	using FunctionType = decltype(setOpacity(opacity))(*)(PlayerObject*, unsigned char);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38f294, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, opacity);
}

auto PlayerObject::setColor(cocos2d::ccColor3B const& color) -> decltype(setColor(color)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::ccColor3B const&>::func(&PlayerObject::setColor), this);
	using FunctionType = decltype(setColor(color))(*)(PlayerObject*, cocos2d::ccColor3B const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38ecb8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, color);
}

auto PlayerObject::setFlipX(bool flipX) -> decltype(setFlipX(flipX)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&PlayerObject::setFlipX), this);
	using FunctionType = decltype(setFlipX(flipX))(*)(PlayerObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x391b24, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, flipX);
}

auto PlayerObject::setFlipY(bool flipY) -> decltype(setFlipY(flipY)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&PlayerObject::setFlipY), this);
	using FunctionType = decltype(setFlipY(flipY))(*)(PlayerObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x391b8c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, flipY);
}

auto PlayerObject::resetObject() -> decltype(resetObject()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&PlayerObject::resetObject), this);
	using FunctionType = decltype(resetObject())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x387858, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto PlayerObject::getRealPosition() -> decltype(getRealPosition()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&PlayerObject::getRealPosition), this);
	using FunctionType = decltype(getRealPosition())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38f490, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto PlayerObject::getOrientedBox() -> decltype(getOrientedBox()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&PlayerObject::getOrientedBox), this);
	using FunctionType = decltype(getOrientedBox())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x390668, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto PlayerObject::getObjectRotation() -> decltype(getObjectRotation()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&PlayerObject::getObjectRotation), this);
	using FunctionType = decltype(getObjectRotation())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x390694, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto PlayerObject::animationFinished(char const* key) -> decltype(animationFinished(key)) {
	auto self = addresser::thunkAdjust(Resolve<char const*>::func(&PlayerObject::animationFinished), this);
	using FunctionType = decltype(animationFinished(key))(*)(PlayerObject*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x391c6c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, key);
}

auto PlayerObject::activateStreak() -> decltype(activateStreak()) {
	using FunctionType = decltype(activateStreak())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37afbc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::addAllParticles() -> decltype(addAllParticles()) {
	using FunctionType = decltype(addAllParticles())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3753fc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::addToTouchedRings(RingObject* object) -> decltype(addToTouchedRings(object)) {
	using FunctionType = decltype(addToTouchedRings(object))(*)(PlayerObject*, RingObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38aaec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto PlayerObject::addToYVelocity(double yVelocity, int type) -> decltype(addToYVelocity(yVelocity, type)) {
	using FunctionType = decltype(addToYVelocity(yVelocity, type))(*)(PlayerObject*, double, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37570c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, yVelocity, type);
}

auto PlayerObject::animatePlatformerJump(float scale) -> decltype(animatePlatformerJump(scale)) {
	using FunctionType = decltype(animatePlatformerJump(scale))(*)(PlayerObject*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37b780, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, scale);
}

auto PlayerObject::boostPlayer(float yVelocity) -> decltype(boostPlayer(yVelocity)) {
	using FunctionType = decltype(boostPlayer(yVelocity))(*)(PlayerObject*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37da2c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, yVelocity);
}

auto PlayerObject::bumpPlayer(float bumpMod, int objectType, bool noEffects, GameObject* object) -> decltype(bumpPlayer(bumpMod, objectType, noEffects, object)) {
	using FunctionType = decltype(bumpPlayer(bumpMod, objectType, noEffects, object))(*)(PlayerObject*, float, int, bool, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38f9d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, bumpMod, objectType, noEffects, object);
}

auto PlayerObject::buttonDown(PlayerButton button) -> decltype(buttonDown(button)) {
	using FunctionType = decltype(buttonDown(button))(*)(PlayerObject*, PlayerButton);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38aad0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, button);
}

auto PlayerObject::canStickToGround() -> decltype(canStickToGround()) {
	using FunctionType = decltype(canStickToGround())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38b440, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::checkSnapJumpToObject(GameObject* object) -> decltype(checkSnapJumpToObject(object)) {
	using FunctionType = decltype(checkSnapJumpToObject(object))(*)(PlayerObject*, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x382fbc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto PlayerObject::collidedWithObject(float dt, GameObject* object) -> decltype(collidedWithObject(dt, object)) {
	using FunctionType = decltype(collidedWithObject(dt, object))(*)(PlayerObject*, float, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x382efc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt, object);
}

auto PlayerObject::collidedWithObject(float dt, GameObject* object, cocos2d::CCRect rect, bool skipCheck) -> decltype(collidedWithObject(dt, object, rect, skipCheck)) {
	using FunctionType = decltype(collidedWithObject(dt, object, rect, skipCheck))(*)(PlayerObject*, float, GameObject*, cocos2d::CCRect, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37dca0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt, object, rect, skipCheck);
}

auto PlayerObject::collidedWithObjectInternal(float dt, GameObject* object, cocos2d::CCRect rect, bool skipCheck) -> decltype(collidedWithObjectInternal(dt, object, rect, skipCheck)) {
	using FunctionType = decltype(collidedWithObjectInternal(dt, object, rect, skipCheck))(*)(PlayerObject*, float, GameObject*, cocos2d::CCRect, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37f8e4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt, object, rect, skipCheck);
}

auto PlayerObject::collidedWithSlope(float dt, GameObject* object, bool skipPre) -> decltype(collidedWithSlope(dt, object, skipPre)) {
	using FunctionType = decltype(collidedWithSlope(dt, object, skipPre))(*)(PlayerObject*, float, GameObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37dd60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt, object, skipPre);
}

auto PlayerObject::collidedWithSlopeInternal(float dt, GameObject* object, bool forced) -> decltype(collidedWithSlopeInternal(dt, object, forced)) {
	using FunctionType = decltype(collidedWithSlopeInternal(dt, object, forced))(*)(PlayerObject*, float, GameObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37e3e4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt, object, forced);
}

auto PlayerObject::convertToClosestRotation(float rotation) -> decltype(convertToClosestRotation(rotation)) {
	using FunctionType = decltype(convertToClosestRotation(rotation))(*)(PlayerObject*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37a6dc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, rotation);
}

auto PlayerObject::copyAttributes(PlayerObject* player) -> decltype(copyAttributes(player)) {
	using FunctionType = decltype(copyAttributes(player))(*)(PlayerObject*, PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39036c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, player);
}

auto PlayerObject::createFadeOutDartStreak() -> decltype(createFadeOutDartStreak()) {
	using FunctionType = decltype(createFadeOutDartStreak())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38ac1c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::createRobot(int frame) -> decltype(createRobot(frame)) {
	using FunctionType = decltype(createRobot(frame))(*)(PlayerObject*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x374834, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, frame);
}

auto PlayerObject::createSpider(int frame) -> decltype(createSpider(frame)) {
	using FunctionType = decltype(createSpider(frame))(*)(PlayerObject*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x374b78, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, frame);
}

auto PlayerObject::deactivateParticle() -> decltype(deactivateParticle()) {
	using FunctionType = decltype(deactivateParticle())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x379454, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::deactivateStreak(bool stop) -> decltype(deactivateStreak(stop)) {
	using FunctionType = decltype(deactivateStreak(stop))(*)(PlayerObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x375594, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, stop);
}

auto PlayerObject::destroyFromHitHead() -> decltype(destroyFromHitHead()) {
	using FunctionType = decltype(destroyFromHitHead())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38e190, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::didHitHead() -> decltype(didHitHead()) {
	using FunctionType = decltype(didHitHead())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3834bc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::disableCustomGlowColor() -> decltype(disableCustomGlowColor()) {
	using FunctionType = decltype(disableCustomGlowColor())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38ede8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::disablePlayerControls() -> decltype(disablePlayerControls()) {
	using FunctionType = decltype(disablePlayerControls())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38f688, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::disableSwingFire() -> decltype(disableSwingFire()) {
	using FunctionType = decltype(disableSwingFire())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3892fc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::doReversePlayer(bool reverse) -> decltype(doReversePlayer(reverse)) {
	using FunctionType = decltype(doReversePlayer(reverse))(*)(PlayerObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37a070, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, reverse);
}

auto PlayerObject::enableCustomGlowColor(cocos2d::ccColor3B const& color) -> decltype(enableCustomGlowColor(color)) {
	using FunctionType = decltype(enableCustomGlowColor(color))(*)(PlayerObject*, cocos2d::ccColor3B const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38edc8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, color);
}

auto PlayerObject::enablePlayerControls() -> decltype(enablePlayerControls()) {
	using FunctionType = decltype(enablePlayerControls())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38f6e4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::exitPlatformerAnimateJump() -> decltype(exitPlatformerAnimateJump()) {
	using FunctionType = decltype(exitPlatformerAnimateJump())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37a298, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::fadeOutStreak2(float duration) -> decltype(fadeOutStreak2(duration)) {
	using FunctionType = decltype(fadeOutStreak2(duration))(*)(PlayerObject*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x389260, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, duration);
}

auto PlayerObject::flashPlayer(float flashDuration, float flashDelay, cocos2d::ccColor3B mainColor, cocos2d::ccColor3B secondColor) -> decltype(flashPlayer(flashDuration, flashDelay, mainColor, secondColor)) {
	using FunctionType = decltype(flashPlayer(flashDuration, flashDelay, mainColor, secondColor))(*)(PlayerObject*, float, float, cocos2d::ccColor3B, cocos2d::ccColor3B);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x384aa8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, flashDuration, flashDelay, mainColor, secondColor);
}

auto PlayerObject::flipGravity(bool flip, bool noEffects) -> decltype(flipGravity(flip, noEffects)) {
	using FunctionType = decltype(flipGravity(flip, noEffects))(*)(PlayerObject*, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37b40c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, flip, noEffects);
}

auto PlayerObject::flipMod() -> decltype(flipMod()) {
	using FunctionType = decltype(flipMod())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3793cc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::gameEventTriggered(int gameEvent, int material) -> decltype(gameEventTriggered(gameEvent, material)) {
	using FunctionType = decltype(gameEventTriggered(gameEvent, material))(*)(PlayerObject*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37b768, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, gameEvent, material);
}

auto PlayerObject::getActiveMode() -> decltype(getActiveMode()) {
	using FunctionType = decltype(getActiveMode())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38b470, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::getCurrentXVelocity() -> decltype(getCurrentXVelocity()) {
	using FunctionType = decltype(getCurrentXVelocity())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3793a4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::getModifiedSlopeYVel() -> decltype(getModifiedSlopeYVel()) {
	using FunctionType = decltype(getModifiedSlopeYVel())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37b378, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::getOldPosition(float dt) -> decltype(getOldPosition(dt)) {
	using FunctionType = decltype(getOldPosition(dt))(*)(PlayerObject*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37a85c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt);
}

auto PlayerObject::getSecondColor() -> decltype(getSecondColor()) {
	using FunctionType = decltype(getSecondColor())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38ed9c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::getYVelocity() -> decltype(getYVelocity()) {
	using FunctionType = decltype(getYVelocity())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x375704, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::gravityDown() -> decltype(gravityDown()) {
	using FunctionType = decltype(gravityDown())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x391bcc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::gravityUp() -> decltype(gravityUp()) {
	using FunctionType = decltype(gravityUp())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x391ba8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::handlePlayerCommand(int command) -> decltype(handlePlayerCommand(command)) {
	using FunctionType = decltype(handlePlayerCommand(command))(*)(PlayerObject*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37bfd8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, command);
}

auto PlayerObject::handleRotatedCollisionInternal(float dt, GameObject* object, cocos2d::CCRect rect, bool skipCheck, bool skipPre, bool slope) -> decltype(handleRotatedCollisionInternal(dt, object, rect, skipCheck, skipPre, slope)) {
	using FunctionType = decltype(handleRotatedCollisionInternal(dt, object, rect, skipCheck, skipPre, slope))(*)(PlayerObject*, float, GameObject*, cocos2d::CCRect, bool, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37df88, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt, object, rect, skipCheck, skipPre, slope);
}

auto PlayerObject::handleRotatedObjectCollision(float dt, GameObject* object, cocos2d::CCRect rect, bool skipCheck) -> decltype(handleRotatedObjectCollision(dt, object, rect, skipCheck)) {
	using FunctionType = decltype(handleRotatedObjectCollision(dt, object, rect, skipCheck))(*)(PlayerObject*, float, GameObject*, cocos2d::CCRect, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37df1c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt, object, rect, skipCheck);
}

auto PlayerObject::handleRotatedSlopeCollision(float dt, GameObject* object, bool skipPre) -> decltype(handleRotatedSlopeCollision(dt, object, skipPre)) {
	using FunctionType = decltype(handleRotatedSlopeCollision(dt, object, skipPre))(*)(PlayerObject*, float, GameObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37e0e8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt, object, skipPre);
}

auto PlayerObject::hardFlipGravity() -> decltype(hardFlipGravity()) {
	using FunctionType = decltype(hardFlipGravity())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3836a4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::hitGround(GameObject* object, bool notFlipped) -> decltype(hitGround(object, notFlipped)) {
	using FunctionType = decltype(hitGround(object, notFlipped))(*)(PlayerObject*, GameObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x381ea0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, notFlipped);
}

auto PlayerObject::hitGroundNoJump(GameObject* object, bool notFlipped) -> decltype(hitGroundNoJump(object, notFlipped)) {
	using FunctionType = decltype(hitGroundNoJump(object, notFlipped))(*)(PlayerObject*, GameObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x383324, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, notFlipped);
}

auto PlayerObject::incrementJumps() -> decltype(incrementJumps()) {
	using FunctionType = decltype(incrementJumps())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37b3d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::init(int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer) -> decltype(init(player, ship, gameLayer, layer, playLayer)) {
	using FunctionType = decltype(init(player, ship, gameLayer, layer, playLayer))(*)(PlayerObject*, int, int, GJBaseGameLayer*, cocos2d::CCLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3731b8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, player, ship, gameLayer, layer, playLayer);
}

auto PlayerObject::isBoostValid(float yVelocity) -> decltype(isBoostValid(yVelocity)) {
	using FunctionType = decltype(isBoostValid(yVelocity))(*)(PlayerObject*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37d9d4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, yVelocity);
}

auto PlayerObject::isFlying() -> decltype(isFlying()) {
	using FunctionType = decltype(isFlying())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3793e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::isInBasicMode() -> decltype(isInBasicMode()) {
	using FunctionType = decltype(isInBasicMode())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x384318, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::isInNormalMode() -> decltype(isInNormalMode()) {
	using FunctionType = decltype(isInNormalMode())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x377ef8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::isSafeFlip(float flipTime) -> decltype(isSafeFlip(flipTime)) {
	using FunctionType = decltype(isSafeFlip(flipTime))(*)(PlayerObject*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x381e74, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, flipTime);
}

auto PlayerObject::isSafeHeadTest() -> decltype(isSafeHeadTest()) {
	using FunctionType = decltype(isSafeHeadTest())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x390244, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::isSafeMode(float changeTime) -> decltype(isSafeMode(changeTime)) {
	using FunctionType = decltype(isSafeMode(changeTime))(*)(PlayerObject*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x381e48, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, changeTime);
}

auto PlayerObject::isSafeSpiderFlip(float flipTime) -> decltype(isSafeSpiderFlip(flipTime)) {
	using FunctionType = decltype(isSafeSpiderFlip(flipTime))(*)(PlayerObject*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x383678, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, flipTime);
}

auto PlayerObject::levelFlipFinished() -> decltype(levelFlipFinished()) {
	using FunctionType = decltype(levelFlipFinished())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37b168, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::levelFlipping() -> decltype(levelFlipping()) {
	using FunctionType = decltype(levelFlipping())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x379428, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::levelWillFlip() -> decltype(levelWillFlip()) {
	using FunctionType = decltype(levelWillFlip())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37b120, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::limitDashRotation(float& rotation) -> decltype(limitDashRotation(rotation)) {
	using FunctionType = decltype(limitDashRotation(rotation))(*)(PlayerObject*, float&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x386c4c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, rotation);
}

auto PlayerObject::loadFromCheckpoint(PlayerCheckpoint* object) -> decltype(loadFromCheckpoint(object)) {
	using FunctionType = decltype(loadFromCheckpoint(object))(*)(PlayerObject*, PlayerCheckpoint*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39107c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto PlayerObject::lockPlayer() -> decltype(lockPlayer()) {
	using FunctionType = decltype(lockPlayer())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38f534, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::logValues() -> decltype(logValues()) {
	using FunctionType = decltype(logValues())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x391bc8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::modeDidChange() -> decltype(modeDidChange()) {
	using FunctionType = decltype(modeDidChange())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38bf2c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::performSlideCheck() -> decltype(performSlideCheck()) {
	using FunctionType = decltype(performSlideCheck())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37dbd8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::placeStreakPoint() -> decltype(placeStreakPoint()) {
	using FunctionType = decltype(placeStreakPoint())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37b07c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::playBumpEffect(int objectType, GameObject* player) -> decltype(playBumpEffect(objectType, player)) {
	using FunctionType = decltype(playBumpEffect(objectType, player))(*)(PlayerObject*, int, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38fb88, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, objectType, player);
}

auto PlayerObject::playBurstEffect() -> decltype(playBurstEffect()) {
	using FunctionType = decltype(playBurstEffect())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37bb60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::playCompleteEffect(bool noEffects, bool instant) -> decltype(playCompleteEffect(noEffects, instant)) {
	using FunctionType = decltype(playCompleteEffect(noEffects, instant))(*)(PlayerObject*, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1bf7f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, noEffects, instant);
}

auto PlayerObject::playDeathEffect() -> decltype(playDeathEffect()) {
	using FunctionType = decltype(playDeathEffect())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b7e94, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::playDynamicSpiderRun() -> decltype(playDynamicSpiderRun()) {
	using FunctionType = decltype(playDynamicSpiderRun())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x379dac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::playerDestroyed(bool noEffects) -> decltype(playerDestroyed(noEffects)) {
	using FunctionType = decltype(playerDestroyed(noEffects))(*)(PlayerObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38907c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, noEffects);
}

auto PlayerObject::playerIsFalling(float yVelocity) -> decltype(playerIsFalling(yVelocity)) {
	using FunctionType = decltype(playerIsFalling(yVelocity))(*)(PlayerObject*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37bb30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, yVelocity);
}

auto PlayerObject::playerIsFallingBugged() -> decltype(playerIsFallingBugged()) {
	using FunctionType = decltype(playerIsFallingBugged())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37ba64, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::playerIsMovingUp() -> decltype(playerIsMovingUp()) {
	using FunctionType = decltype(playerIsMovingUp())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37bb10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::playerTeleported() -> decltype(playerTeleported()) {
	using FunctionType = decltype(playerTeleported())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38b238, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::playingEndEffect() -> decltype(playingEndEffect()) {
	using FunctionType = decltype(playingEndEffect())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38f930, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::playSpawnEffect() -> decltype(playSpawnEffect()) {
	using FunctionType = decltype(playSpawnEffect())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3889d8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::playSpiderDashEffect(cocos2d::CCPoint from, cocos2d::CCPoint to) -> decltype(playSpiderDashEffect(from, to)) {
	using FunctionType = decltype(playSpiderDashEffect(from, to))(*)(PlayerObject*, cocos2d::CCPoint, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x384378, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, from, to);
}

auto PlayerObject::postCollision(float dt, bool betweenSteps) -> decltype(postCollision(dt, betweenSteps)) {
	using FunctionType = decltype(postCollision(dt, betweenSteps))(*)(PlayerObject*, float, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37c258, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt, betweenSteps);
}

auto PlayerObject::preCollision() -> decltype(preCollision()) {
	using FunctionType = decltype(preCollision())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37c100, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::preSlopeCollision(float dt, GameObject* object) -> decltype(preSlopeCollision(dt, object)) {
	using FunctionType = decltype(preSlopeCollision(dt, object))(*)(PlayerObject*, float, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3819b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt, object);
}

auto PlayerObject::propellPlayer(float yVelocity, bool noEffects, int objectType) -> decltype(propellPlayer(yVelocity, noEffects, objectType)) {
	using FunctionType = decltype(propellPlayer(yVelocity, noEffects, objectType))(*)(PlayerObject*, float, bool, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38fcac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, yVelocity, noEffects, objectType);
}

auto PlayerObject::pushButton(PlayerButton button) -> decltype(pushButton(button)) {
	using FunctionType = decltype(pushButton(button))(*)(PlayerObject*, PlayerButton);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38957c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, button);
}

auto PlayerObject::pushDown() -> decltype(pushDown()) {
	using FunctionType = decltype(pushDown())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3902bc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::pushPlayer(float yVelocity) -> decltype(pushPlayer(yVelocity)) {
	using FunctionType = decltype(pushPlayer(yVelocity))(*)(PlayerObject*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38fed4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, yVelocity);
}

auto PlayerObject::redirectDash(float rotation) -> decltype(redirectDash(rotation)) {
	using FunctionType = decltype(redirectDash(rotation))(*)(PlayerObject*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x386598, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, rotation);
}

auto PlayerObject::redirectPlayerForce(float rotation, float modifier, float minimum, float maximum) -> decltype(redirectPlayerForce(rotation, modifier, minimum, maximum)) {
	using FunctionType = decltype(redirectPlayerForce(rotation, modifier, minimum, maximum))(*)(PlayerObject*, float, float, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39005c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, rotation, modifier, minimum, maximum);
}

auto PlayerObject::releaseAllButtons() -> decltype(releaseAllButtons()) {
	using FunctionType = decltype(releaseAllButtons())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38f4f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::releaseButton(PlayerButton button) -> decltype(releaseButton(button)) {
	using FunctionType = decltype(releaseButton(button))(*)(PlayerObject*, PlayerButton);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38a678, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, button);
}

auto PlayerObject::removeAllParticles() -> decltype(removeAllParticles()) {
	using FunctionType = decltype(removeAllParticles())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37551c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::removePendingCheckpoint() -> decltype(removePendingCheckpoint()) {
	using FunctionType = decltype(removePendingCheckpoint())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3882ec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::removePlacedCheckpoint() -> decltype(removePlacedCheckpoint()) {
	using FunctionType = decltype(removePlacedCheckpoint())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x389040, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::resetAllParticles() -> decltype(resetAllParticles()) {
	using FunctionType = decltype(resetAllParticles())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37ae70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::resetCollisionLog(bool full) -> decltype(resetCollisionLog(full)) {
	using FunctionType = decltype(resetCollisionLog(full))(*)(PlayerObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37bfec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, full);
}

auto PlayerObject::resetCollisionValues() -> decltype(resetCollisionValues()) {
	using FunctionType = decltype(resetCollisionValues())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38372c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::resetPlayerIcon() -> decltype(resetPlayerIcon()) {
	using FunctionType = decltype(resetPlayerIcon())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38bd44, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::resetStateVariables() -> decltype(resetStateVariables()) {
	using FunctionType = decltype(resetStateVariables())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x388100, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::resetStreak() -> decltype(resetStreak()) {
	using FunctionType = decltype(resetStreak())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37aed4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::resetTouchedRings(bool removeAll) -> decltype(resetTouchedRings(removeAll)) {
	using FunctionType = decltype(resetTouchedRings(removeAll))(*)(PlayerObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x388164, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, removeAll);
}

auto PlayerObject::reverseMod() -> decltype(reverseMod()) {
	using FunctionType = decltype(reverseMod())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37bea8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::reversePlayer(EffectGameObject* object) -> decltype(reversePlayer(object)) {
	using FunctionType = decltype(reversePlayer(object))(*)(PlayerObject*, EffectGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38ab44, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto PlayerObject::ringJump(RingObject* object, bool skipCheck) -> decltype(ringJump(object, skipCheck)) {
	using FunctionType = decltype(ringJump(object, skipCheck))(*)(PlayerObject*, RingObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38991c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, skipCheck);
}

auto PlayerObject::rotateGameplay(int moveDirection, int groundDirection, bool editVelocity, float velocityModX, float velocityModY, bool overrideVelocity, bool dontSlide) -> decltype(rotateGameplay(moveDirection, groundDirection, editVelocity, velocityModX, velocityModY, overrideVelocity, dontSlide)) {
	using FunctionType = decltype(rotateGameplay(moveDirection, groundDirection, editVelocity, velocityModX, velocityModY, overrideVelocity, dontSlide))(*)(PlayerObject*, int, int, bool, float, float, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x387c94, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, moveDirection, groundDirection, editVelocity, velocityModX, velocityModY, overrideVelocity, dontSlide);
}

auto PlayerObject::rotateGameplayObject(GameObject* object) -> decltype(rotateGameplayObject(object)) {
	using FunctionType = decltype(rotateGameplayObject(object))(*)(PlayerObject*, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37e158, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto PlayerObject::rotateGameplayOnly(bool sideways) -> decltype(rotateGameplayOnly(sideways)) {
	using FunctionType = decltype(rotateGameplayOnly(sideways))(*)(PlayerObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38b230, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sideways);
}

auto PlayerObject::rotatePreSlopeObjects() -> decltype(rotatePreSlopeObjects()) {
	using FunctionType = decltype(rotatePreSlopeObjects())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37e3ac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::runBallRotation(float speed) -> decltype(runBallRotation(speed)) {
	using FunctionType = decltype(runBallRotation(speed))(*)(PlayerObject*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37bd90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, speed);
}

auto PlayerObject::runBallRotation2() -> decltype(runBallRotation2()) {
	using FunctionType = decltype(runBallRotation2())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37bebc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::runNormalRotation() -> decltype(runNormalRotation()) {
	using FunctionType = decltype(runNormalRotation())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37bcb4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::runNormalRotation(bool notNormalMode, float speed) -> decltype(runNormalRotation(notNormalMode, speed)) {
	using FunctionType = decltype(runNormalRotation(notNormalMode, speed))(*)(PlayerObject*, bool, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x377f68, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, notNormalMode, speed);
}

auto PlayerObject::runRotateAction(bool ground, int type) -> decltype(runRotateAction(ground, type)) {
	using FunctionType = decltype(runRotateAction(ground, type))(*)(PlayerObject*, bool, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37a398, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, ground, type);
}

auto PlayerObject::saveToCheckpoint(PlayerCheckpoint* checkpoint) -> decltype(saveToCheckpoint(checkpoint)) {
	using FunctionType = decltype(saveToCheckpoint(checkpoint))(*)(PlayerObject*, PlayerCheckpoint*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x390ad0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, checkpoint);
}

auto PlayerObject::setSecondColor(cocos2d::ccColor3B const& color) -> decltype(setSecondColor(color)) {
	using FunctionType = decltype(setSecondColor(color))(*)(PlayerObject*, cocos2d::ccColor3B const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x376680, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, color);
}

auto PlayerObject::setupStreak() -> decltype(setupStreak()) {
	using FunctionType = decltype(setupStreak())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x375058, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::setYVelocity(double velocity, int type) -> decltype(setYVelocity(velocity, type)) {
	using FunctionType = decltype(setYVelocity(velocity, type))(*)(PlayerObject*, double, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x374ddc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, velocity, type);
}

auto PlayerObject::spawnCircle() -> decltype(spawnCircle()) {
	using FunctionType = decltype(spawnCircle())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x388b68, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::spawnCircle2() -> decltype(spawnCircle2()) {
	using FunctionType = decltype(spawnCircle2())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x388c4c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::spawnDualCircle() -> decltype(spawnDualCircle()) {
	using FunctionType = decltype(spawnDualCircle())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x388f50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::spawnFromPlayer(PlayerObject* player, bool flip) -> decltype(spawnFromPlayer(player, flip)) {
	using FunctionType = decltype(spawnFromPlayer(player, flip))(*)(PlayerObject*, PlayerObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3904fc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, player, flip);
}

auto PlayerObject::spawnPortalCircle(cocos2d::ccColor3B color, float startRadius) -> decltype(spawnPortalCircle(color, startRadius)) {
	using FunctionType = decltype(spawnPortalCircle(color, startRadius))(*)(PlayerObject*, cocos2d::ccColor3B, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x388cf0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, color, startRadius);
}

auto PlayerObject::spawnScaleCircle() -> decltype(spawnScaleCircle()) {
	using FunctionType = decltype(spawnScaleCircle())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x388e10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::specialGroundHit() -> decltype(specialGroundHit()) {
	using FunctionType = decltype(specialGroundHit())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3902cc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::speedDown() -> decltype(speedDown()) {
	using FunctionType = decltype(speedDown())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x391c0c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::speedUp() -> decltype(speedUp()) {
	using FunctionType = decltype(speedUp())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x391bec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::spiderTestJump(bool dynamic) -> decltype(spiderTestJump(dynamic)) {
	using FunctionType = decltype(spiderTestJump(dynamic))(*)(PlayerObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37b2c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dynamic);
}

auto PlayerObject::spiderTestJumpInternal(bool dynamic) -> decltype(spiderTestJumpInternal(dynamic)) {
	using FunctionType = decltype(spiderTestJumpInternal(dynamic))(*)(PlayerObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38373c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dynamic);
}

auto PlayerObject::spiderTestJumpX(bool dynamic) -> decltype(spiderTestJumpX(dynamic)) {
	using FunctionType = decltype(spiderTestJumpX(dynamic))(*)(PlayerObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x384b64, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dynamic);
}

auto PlayerObject::spiderTestJumpY(bool dynamic) -> decltype(spiderTestJumpY(dynamic)) {
	using FunctionType = decltype(spiderTestJumpY(dynamic))(*)(PlayerObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38587c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dynamic);
}

auto PlayerObject::startDashing(DashRingObject* object) -> decltype(startDashing(object)) {
	using FunctionType = decltype(startDashing(object))(*)(PlayerObject*, DashRingObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x386de8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto PlayerObject::stopBurstEffect() -> decltype(stopBurstEffect()) {
	using FunctionType = decltype(stopBurstEffect())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38d598, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::stopDashing() -> decltype(stopDashing()) {
	using FunctionType = decltype(stopDashing())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3796d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::stopParticles() -> decltype(stopParticles()) {
	using FunctionType = decltype(stopParticles())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37b270, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::stopPlatformerJumpAnimation() -> decltype(stopPlatformerJumpAnimation()) {
	using FunctionType = decltype(stopPlatformerJumpAnimation())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37bc1c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::stopRotation(bool ground, int type) -> decltype(stopRotation(ground, type)) {
	using FunctionType = decltype(stopRotation(ground, type))(*)(PlayerObject*, bool, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37bca4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, ground, type);
}

auto PlayerObject::stopStreak2() -> decltype(stopStreak2()) {
	using FunctionType = decltype(stopStreak2())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x390204, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::storeCollision(PlayerCollisionDirection direction, int id) -> decltype(storeCollision(direction, id)) {
	using FunctionType = decltype(storeCollision(direction, id))(*)(PlayerObject*, PlayerCollisionDirection, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37c04c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, direction, id);
}

auto PlayerObject::switchedDirTo(PlayerButton button) -> decltype(switchedDirTo(button)) {
	using FunctionType = decltype(switchedDirTo(button))(*)(PlayerObject*, PlayerButton);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x389378, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, button);
}

auto PlayerObject::switchedToMode(GameObjectType type) -> decltype(switchedToMode(type)) {
	using FunctionType = decltype(switchedToMode(type))(*)(PlayerObject*, GameObjectType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x388338, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type);
}

auto PlayerObject::testForMoving(float dt, GameObject* object) -> decltype(testForMoving(dt, object)) {
	using FunctionType = decltype(testForMoving(dt, object))(*)(PlayerObject*, float, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37dde4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt, object);
}

auto PlayerObject::toggleBirdMode(bool enable, bool noEffects) -> decltype(toggleBirdMode(enable, noEffects)) {
	using FunctionType = decltype(toggleBirdMode(enable, noEffects))(*)(PlayerObject*, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38bf50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, enable, noEffects);
}

auto PlayerObject::toggleDartMode(bool enable, bool noEffects) -> decltype(toggleDartMode(enable, noEffects)) {
	using FunctionType = decltype(toggleDartMode(enable, noEffects))(*)(PlayerObject*, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38cf84, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, enable, noEffects);
}

auto PlayerObject::toggleFlyMode(bool enable, bool noEffects) -> decltype(toggleFlyMode(enable, noEffects)) {
	using FunctionType = decltype(toggleFlyMode(enable, noEffects))(*)(PlayerObject*, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38b4d8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, enable, noEffects);
}

auto PlayerObject::toggleGhostEffect(GhostType type) -> decltype(toggleGhostEffect(type)) {
	using FunctionType = decltype(toggleGhostEffect(type))(*)(PlayerObject*, GhostType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x388894, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type);
}

auto PlayerObject::togglePlatformerMode(bool val) -> decltype(togglePlatformerMode(val)) {
	using FunctionType = decltype(togglePlatformerMode(val))(*)(PlayerObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3753f4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, val);
}

auto PlayerObject::togglePlayerScale(bool enable, bool noEffects) -> decltype(togglePlayerScale(enable, noEffects)) {
	using FunctionType = decltype(togglePlayerScale(enable, noEffects))(*)(PlayerObject*, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3884b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, enable, noEffects);
}

auto PlayerObject::toggleRobotMode(bool enable, bool noEffects) -> decltype(toggleRobotMode(enable, noEffects)) {
	using FunctionType = decltype(toggleRobotMode(enable, noEffects))(*)(PlayerObject*, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38d95c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, enable, noEffects);
}

auto PlayerObject::toggleRollMode(bool enable, bool noEffects) -> decltype(toggleRollMode(enable, noEffects)) {
	using FunctionType = decltype(toggleRollMode(enable, noEffects))(*)(PlayerObject*, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38d5a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, enable, noEffects);
}

auto PlayerObject::toggleSpiderMode(bool enable, bool noEffects) -> decltype(toggleSpiderMode(enable, noEffects)) {
	using FunctionType = decltype(toggleSpiderMode(enable, noEffects))(*)(PlayerObject*, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38dd8c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, enable, noEffects);
}

auto PlayerObject::toggleSwingMode(bool enable, bool noEffects) -> decltype(toggleSwingMode(enable, noEffects)) {
	using FunctionType = decltype(toggleSwingMode(enable, noEffects))(*)(PlayerObject*, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38c5b4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, enable, noEffects);
}

auto PlayerObject::toggleVisibility(bool visible) -> decltype(toggleVisibility(visible)) {
	using FunctionType = decltype(toggleVisibility(visible))(*)(PlayerObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37ac64, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, visible);
}

auto PlayerObject::touchedObject(GameObject* object) -> decltype(touchedObject(object)) {
	using FunctionType = decltype(touchedObject(object))(*)(PlayerObject*, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x391880, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto PlayerObject::tryPlaceCheckpoint() -> decltype(tryPlaceCheckpoint()) {
	using FunctionType = decltype(tryPlaceCheckpoint())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37a9c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::unrotateGameplayObject(GameObject* object) -> decltype(unrotateGameplayObject(object)) {
	using FunctionType = decltype(unrotateGameplayObject(object))(*)(PlayerObject*, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x381774, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto PlayerObject::unrotatePreSlopeObjects() -> decltype(unrotatePreSlopeObjects()) {
	using FunctionType = decltype(unrotatePreSlopeObjects())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x381978, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::updateCheckpointMode(bool enable) -> decltype(updateCheckpointMode(enable)) {
	using FunctionType = decltype(updateCheckpointMode(enable))(*)(PlayerObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3753ec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, enable);
}

auto PlayerObject::updateCheckpointTest() -> decltype(updateCheckpointTest()) {
	using FunctionType = decltype(updateCheckpointTest())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37a8d4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::updateCollide(PlayerCollisionDirection direction, GameObject* object) -> decltype(updateCollide(direction, object)) {
	using FunctionType = decltype(updateCollide(direction, object))(*)(PlayerObject*, PlayerCollisionDirection, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x382520, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, direction, object);
}

auto PlayerObject::updateCollideBottom(float y, GameObject* object) -> decltype(updateCollideBottom(y, object)) {
	using FunctionType = decltype(updateCollideBottom(y, object))(*)(PlayerObject*, float, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3833fc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, y, object);
}

auto PlayerObject::updateCollideLeft(float x, GameObject* object) -> decltype(updateCollideLeft(x, object)) {
	using FunctionType = decltype(updateCollideLeft(x, object))(*)(PlayerObject*, float, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3835ec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, x, object);
}

auto PlayerObject::updateCollideRight(float x, GameObject* object) -> decltype(updateCollideRight(x, object)) {
	using FunctionType = decltype(updateCollideRight(x, object))(*)(PlayerObject*, float, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x383560, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, x, object);
}

auto PlayerObject::updateCollideTop(float y, GameObject* object) -> decltype(updateCollideTop(y, object)) {
	using FunctionType = decltype(updateCollideTop(y, object))(*)(PlayerObject*, float, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x383370, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, y, object);
}

auto PlayerObject::updateDashAnimation() -> decltype(updateDashAnimation()) {
	using FunctionType = decltype(updateDashAnimation())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x379488, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::updateDashArt() -> decltype(updateDashArt()) {
	using FunctionType = decltype(updateDashArt())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x386724, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::updateEffects(float param) -> decltype(updateEffects(param)) {
	using FunctionType = decltype(updateEffects(param))(*)(PlayerObject*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37a854, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, param);
}

auto PlayerObject::updateGlowColor() -> decltype(updateGlowColor()) {
	using FunctionType = decltype(updateGlowColor())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38edf0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::updateInternalActions(float dt) -> decltype(updateInternalActions(dt)) {
	using FunctionType = decltype(updateInternalActions(dt))(*)(PlayerObject*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x392150, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt);
}

auto PlayerObject::updateJump(float dt) -> decltype(updateJump(dt)) {
	using FunctionType = decltype(updateJump(dt))(*)(PlayerObject*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3766e8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt);
}

auto PlayerObject::updateJumpVariables() -> decltype(updateJumpVariables()) {
	using FunctionType = decltype(updateJumpVariables())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x379634, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::updateLastGroundObject(GameObject* object) -> decltype(updateLastGroundObject(object)) {
	using FunctionType = decltype(updateLastGroundObject(object))(*)(PlayerObject*, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x383488, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto PlayerObject::updateMove(float dt) -> decltype(updateMove(dt)) {
	using FunctionType = decltype(updateMove(dt))(*)(PlayerObject*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x378054, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt);
}

auto PlayerObject::updatePlayerArt() -> decltype(updatePlayerArt()) {
	using FunctionType = decltype(updatePlayerArt())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38aeb8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::updatePlayerBirdFrame(int frame) -> decltype(updatePlayerBirdFrame(frame)) {
	using FunctionType = decltype(updatePlayerBirdFrame(frame))(*)(PlayerObject*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38c330, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, frame);
}

auto PlayerObject::updatePlayerDartFrame(int frame) -> decltype(updatePlayerDartFrame(frame)) {
	using FunctionType = decltype(updatePlayerDartFrame(frame))(*)(PlayerObject*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38d368, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, frame);
}

auto PlayerObject::updatePlayerForce(cocos2d::CCPoint velocity, bool additive) -> decltype(updatePlayerForce(velocity, additive)) {
	using FunctionType = decltype(updatePlayerForce(velocity, additive))(*)(PlayerObject*, cocos2d::CCPoint, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3877f8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, velocity, additive);
}

auto PlayerObject::updatePlayerFrame(int frame) -> decltype(updatePlayerFrame(frame)) {
	using FunctionType = decltype(updatePlayerFrame(frame))(*)(PlayerObject*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38cc84, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, frame);
}

auto PlayerObject::updatePlayerGlow() -> decltype(updatePlayerGlow()) {
	using FunctionType = decltype(updatePlayerGlow())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38acf8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::updatePlayerJetpackFrame(int frame) -> decltype(updatePlayerJetpackFrame(frame)) {
	using FunctionType = decltype(updatePlayerJetpackFrame(frame))(*)(PlayerObject*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38bb14, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, frame);
}

auto PlayerObject::updatePlayerRobotFrame(int frame) -> decltype(updatePlayerRobotFrame(frame)) {
	using FunctionType = decltype(updatePlayerRobotFrame(frame))(*)(PlayerObject*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38f4c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, frame);
}

auto PlayerObject::updatePlayerRollFrame(int frame) -> decltype(updatePlayerRollFrame(frame)) {
	using FunctionType = decltype(updatePlayerRollFrame(frame))(*)(PlayerObject*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38d730, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, frame);
}

auto PlayerObject::updatePlayerScale() -> decltype(updatePlayerScale()) {
	using FunctionType = decltype(updatePlayerScale())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38b2e4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::updatePlayerShipFrame(int frame) -> decltype(updatePlayerShipFrame(frame)) {
	using FunctionType = decltype(updatePlayerShipFrame(frame))(*)(PlayerObject*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38b8e4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, frame);
}

auto PlayerObject::updatePlayerSpiderFrame(int frame) -> decltype(updatePlayerSpiderFrame(frame)) {
	using FunctionType = decltype(updatePlayerSpiderFrame(frame))(*)(PlayerObject*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38f4d8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, frame);
}

auto PlayerObject::updatePlayerSpriteExtra(gd::string frameName) -> decltype(updatePlayerSpriteExtra(frameName)) {
	using FunctionType = decltype(updatePlayerSpriteExtra(frameName))(*)(PlayerObject*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37466c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, frameName);
}

auto PlayerObject::updatePlayerSwingFrame(int frame) -> decltype(updatePlayerSwingFrame(frame)) {
	using FunctionType = decltype(updatePlayerSwingFrame(frame))(*)(PlayerObject*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38c9bc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, frame);
}

auto PlayerObject::updateRobotAnimationSpeed() -> decltype(updateRobotAnimationSpeed()) {
	using FunctionType = decltype(updateRobotAnimationSpeed())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x390710, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::updateRotation(float dt) -> decltype(updateRotation(dt)) {
	using FunctionType = decltype(updateRotation(dt))(*)(PlayerObject*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x382d40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt);
}

auto PlayerObject::updateRotation(float dt, float rotation) -> decltype(updateRotation(dt, rotation)) {
	using FunctionType = decltype(updateRotation(dt, rotation))(*)(PlayerObject*, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37a590, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt, rotation);
}

auto PlayerObject::updateShipRotation(float dt) -> decltype(updateShipRotation(dt)) {
	using FunctionType = decltype(updateShipRotation(dt))(*)(PlayerObject*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x382970, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt);
}

auto PlayerObject::updateShipSpriteExtra(gd::string frameName) -> decltype(updateShipSpriteExtra(frameName)) {
	using FunctionType = decltype(updateShipSpriteExtra(frameName))(*)(PlayerObject*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x374750, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, frameName);
}

auto PlayerObject::updateSlopeRotation(float dt) -> decltype(updateSlopeRotation(dt)) {
	using FunctionType = decltype(updateSlopeRotation(dt))(*)(PlayerObject*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3827f4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt);
}

auto PlayerObject::updateSlopeYVelocity(float yVelocity) -> decltype(updateSlopeYVelocity(yVelocity)) {
	using FunctionType = decltype(updateSlopeYVelocity(yVelocity))(*)(PlayerObject*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38296c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, yVelocity);
}

auto PlayerObject::updateSpecial(float dt) -> decltype(updateSpecial(dt)) {
	using FunctionType = decltype(updateSpecial(dt))(*)(PlayerObject*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x37a7dc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt);
}

auto PlayerObject::updateStateVariables() -> decltype(updateStateVariables()) {
	using FunctionType = decltype(updateStateVariables())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x379650, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::updateStaticForce(float rotation, float staticForce, bool additive) -> decltype(updateStaticForce(rotation, staticForce, additive)) {
	using FunctionType = decltype(updateStaticForce(rotation, staticForce, additive))(*)(PlayerObject*, float, float, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38ff20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, rotation, staticForce, additive);
}

auto PlayerObject::updateStreakBlend(bool blend) -> decltype(updateStreakBlend(blend)) {
	using FunctionType = decltype(updateStreakBlend(blend))(*)(PlayerObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x375668, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, blend);
}

auto PlayerObject::updateStreaks(float dt) -> decltype(updateStreaks(dt)) {
	using FunctionType = decltype(updateStreaks(dt))(*)(PlayerObject*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3756ec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt);
}

auto PlayerObject::updateSwingFire() -> decltype(updateSwingFire()) {
	using FunctionType = decltype(updateSwingFire())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x38b330, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::updateTimeMod(float speed, bool noEffects) -> decltype(updateTimeMod(speed, noEffects)) {
	using FunctionType = decltype(updateTimeMod(speed, noEffects))(*)(PlayerObject*, float, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x374e1c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, speed, noEffects);
}

auto PlayerObject::usingWallLimitedMode() -> decltype(usingWallLimitedMode()) {
	using FunctionType = decltype(usingWallLimitedMode())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3906a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::yStartDown() -> decltype(yStartDown()) {
	using FunctionType = decltype(yStartDown())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x391c4c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerObject::yStartUp() -> decltype(yStartUp()) {
	using FunctionType = decltype(yStartUp())(*)(PlayerObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x391c2c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
