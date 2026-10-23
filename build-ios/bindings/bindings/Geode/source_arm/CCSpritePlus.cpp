
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/CCSpritePlus.hpp>
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

CCSpritePlus::~CCSpritePlus() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(CCSpritePlus*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x3e79bc, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) CCSpritePlus(geode::CutoffConstructor, sizeof(CCSpritePlus));
		geode::DestructorLock::addLock(this);
	}
}

auto CCSpritePlus::createWithSpriteFrame(cocos2d::CCSpriteFrame* frame) -> decltype(createWithSpriteFrame(frame)) {
	using FunctionType = decltype(createWithSpriteFrame(frame))(*)(cocos2d::CCSpriteFrame*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e7aa4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(frame);
}

auto CCSpritePlus::createWithSpriteFrameName(char const* frame) -> decltype(createWithSpriteFrameName(frame)) {
	using FunctionType = decltype(createWithSpriteFrameName(frame))(*)(char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e7b54, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(frame);
}

auto CCSpritePlus::setScaleX(float scaleX) -> decltype(setScaleX(scaleX)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&CCSpritePlus::setScaleX), this);
	using FunctionType = decltype(setScaleX(scaleX))(*)(CCSpritePlus*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e7f84, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, scaleX);
}

auto CCSpritePlus::setScaleY(float scaleY) -> decltype(setScaleY(scaleY)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&CCSpritePlus::setScaleY), this);
	using FunctionType = decltype(setScaleY(scaleY))(*)(CCSpritePlus*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e8008, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, scaleY);
}

auto CCSpritePlus::setScale(float scale) -> decltype(setScale(scale)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&CCSpritePlus::setScale), this);
	using FunctionType = decltype(setScale(scale))(*)(CCSpritePlus*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e808c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, scale);
}

auto CCSpritePlus::setPosition(cocos2d::CCPoint const& position) -> decltype(setPosition(position)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCPoint const&>::func(&CCSpritePlus::setPosition), this);
	using FunctionType = decltype(setPosition(position))(*)(CCSpritePlus*, cocos2d::CCPoint const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e7c34, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, position);
}

auto CCSpritePlus::setRotation(float rotation) -> decltype(setRotation(rotation)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&CCSpritePlus::setRotation), this);
	using FunctionType = decltype(setRotation(rotation))(*)(CCSpritePlus*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e7cac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, rotation);
}

auto CCSpritePlus::setRotationX(float rotationX) -> decltype(setRotationX(rotationX)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&CCSpritePlus::setRotationX), this);
	using FunctionType = decltype(setRotationX(rotationX))(*)(CCSpritePlus*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e7d24, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, rotationX);
}

auto CCSpritePlus::setRotationY(float rotationY) -> decltype(setRotationY(rotationY)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&CCSpritePlus::setRotationY), this);
	using FunctionType = decltype(setRotationY(rotationY))(*)(CCSpritePlus*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e7d9c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, rotationY);
}

auto CCSpritePlus::initWithTexture(cocos2d::CCTexture2D* texture) -> decltype(initWithTexture(texture)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTexture2D*>::func(&CCSpritePlus::initWithTexture), this);
	using FunctionType = decltype(initWithTexture(texture))(*)(CCSpritePlus*, cocos2d::CCTexture2D*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e7c20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, texture);
}

auto CCSpritePlus::initWithSpriteFrameName(char const* frameName) -> decltype(initWithSpriteFrameName(frameName)) {
	auto self = addresser::thunkAdjust(Resolve<char const*>::func(&CCSpritePlus::initWithSpriteFrameName), this);
	using FunctionType = decltype(initWithSpriteFrameName(frameName))(*)(CCSpritePlus*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e7c14, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, frameName);
}

auto CCSpritePlus::setFlipX(bool flipX) -> decltype(setFlipX(flipX)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&CCSpritePlus::setFlipX), this);
	using FunctionType = decltype(setFlipX(flipX))(*)(CCSpritePlus*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e7e14, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, flipX);
}

auto CCSpritePlus::setFlipY(bool flipY) -> decltype(setFlipY(flipY)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&CCSpritePlus::setFlipY), this);
	using FunctionType = decltype(setFlipY(flipY))(*)(CCSpritePlus*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e7ecc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, flipY);
}

auto CCSpritePlus::addFollower(cocos2d::CCNode* follower) -> decltype(addFollower(follower)) {
	using FunctionType = decltype(addFollower(follower))(*)(CCSpritePlus*, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e8110, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, follower);
}

auto CCSpritePlus::followSprite(CCSpritePlus* sprite) -> decltype(followSprite(sprite)) {
	using FunctionType = decltype(followSprite(sprite))(*)(CCSpritePlus*, CCSpritePlus*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e81a8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sprite);
}

auto CCSpritePlus::getFollower() -> decltype(getFollower()) {
	using FunctionType = decltype(getFollower())(*)(CCSpritePlus*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e8250, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CCSpritePlus::removeFollower(cocos2d::CCNode* sprite) -> decltype(removeFollower(sprite)) {
	using FunctionType = decltype(removeFollower(sprite))(*)(CCSpritePlus*, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e8160, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sprite);
}

auto CCSpritePlus::stopFollow() -> decltype(stopFollow()) {
	using FunctionType = decltype(stopFollow())(*)(CCSpritePlus*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e8200, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
