
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/AnimatedGameObject.hpp>
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

AnimatedGameObject::~AnimatedGameObject() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(AnimatedGameObject*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x1b6150, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) AnimatedGameObject(geode::CutoffConstructor, sizeof(AnimatedGameObject));
		geode::DestructorLock::addLock(this);
	}
}

auto AnimatedGameObject::animationForID(int type, int id) -> decltype(animationForID(type, id)) {
	using FunctionType = decltype(animationForID(type, id))(*)(int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b8c80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(type, id);
}

auto AnimatedGameObject::create(int id) -> decltype(create(id)) {
	using FunctionType = decltype(create(id))(*)(int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b6300, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(id);
}

auto AnimatedGameObject::getTweenTime(int type, int id) -> decltype(getTweenTime(type, id)) {
	using FunctionType = decltype(getTweenTime(type, id))(*)(int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b8f20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(type, id);
}

auto AnimatedGameObject::setOpacity(unsigned char opacity) -> decltype(setOpacity(opacity)) {
	auto self = addresser::thunkAdjust(Resolve<unsigned char>::func(&AnimatedGameObject::setOpacity), this);
	using FunctionType = decltype(setOpacity(opacity))(*)(AnimatedGameObject*, unsigned char);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b73a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, opacity);
}

auto AnimatedGameObject::setChildColor(cocos2d::ccColor3B const& color) -> decltype(setChildColor(color)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::ccColor3B const&>::func(&AnimatedGameObject::setChildColor), this);
	using FunctionType = decltype(setChildColor(color))(*)(AnimatedGameObject*, cocos2d::ccColor3B const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b8fa0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, color);
}

auto AnimatedGameObject::resetObject() -> decltype(resetObject()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&AnimatedGameObject::resetObject), this);
	using FunctionType = decltype(resetObject())(*)(AnimatedGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b8f30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto AnimatedGameObject::activateObject() -> decltype(activateObject()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&AnimatedGameObject::activateObject), this);
	using FunctionType = decltype(activateObject())(*)(AnimatedGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b7290, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto AnimatedGameObject::deactivateObject(bool deactivate) -> decltype(deactivateObject(deactivate)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&AnimatedGameObject::deactivateObject), this);
	using FunctionType = decltype(deactivateObject(deactivate))(*)(AnimatedGameObject*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b72d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, deactivate);
}

auto AnimatedGameObject::setObjectColor(cocos2d::ccColor3B const& color) -> decltype(setObjectColor(color)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::ccColor3B const&>::func(&AnimatedGameObject::setObjectColor), this);
	using FunctionType = decltype(setObjectColor(color))(*)(AnimatedGameObject*, cocos2d::ccColor3B const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b7480, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, color);
}

auto AnimatedGameObject::animationFinished(char const* key) -> decltype(animationFinished(key)) {
	auto self = addresser::thunkAdjust(Resolve<char const*>::func(&AnimatedGameObject::animationFinished), this);
	using FunctionType = decltype(animationFinished(key))(*)(AnimatedGameObject*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b74b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, key);
}

auto AnimatedGameObject::displayFrameChanged(cocos2d::CCObject* sprite, gd::string frameName) -> decltype(displayFrameChanged(sprite, frameName)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCObject*, gd::string>::func(&AnimatedGameObject::displayFrameChanged), this);
	using FunctionType = decltype(displayFrameChanged(sprite, frameName))(*)(AnimatedGameObject*, cocos2d::CCObject*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b87e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, sprite, frameName);
}

auto AnimatedGameObject::init(int id) -> decltype(init(id)) {
	using FunctionType = decltype(init(id))(*)(AnimatedGameObject*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b6450, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto AnimatedGameObject::playAnimation(int type) -> decltype(playAnimation(type)) {
	using FunctionType = decltype(playAnimation(type))(*)(AnimatedGameObject*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b8b20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type);
}

auto AnimatedGameObject::setupAnimatedSize(int id) -> decltype(setupAnimatedSize(id)) {
	using FunctionType = decltype(setupAnimatedSize(id))(*)(AnimatedGameObject*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b65f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto AnimatedGameObject::setupChildSprites() -> decltype(setupChildSprites()) {
	using FunctionType = decltype(setupChildSprites())(*)(AnimatedGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b67b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto AnimatedGameObject::updateChildSpriteColor(cocos2d::ccColor3B color) -> decltype(updateChildSpriteColor(color)) {
	using FunctionType = decltype(updateChildSpriteColor(color))(*)(AnimatedGameObject*, cocos2d::ccColor3B);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b7050, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, color);
}

auto AnimatedGameObject::updateObjectAnimation() -> decltype(updateObjectAnimation()) {
	using FunctionType = decltype(updateObjectAnimation())(*)(AnimatedGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1b70d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
