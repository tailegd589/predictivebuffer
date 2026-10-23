
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/CCMenuItemSpriteExtra.hpp>
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

CCMenuItemSpriteExtra::CCMenuItemSpriteExtra() : CCMenuItemSpriteExtra(geode::CutoffConstructor, sizeof(CCMenuItemSpriteExtra)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	CCMenuItemSpriteExtra::~CCMenuItemSpriteExtra();

	using FunctionType = void(*)(CCMenuItemSpriteExtra*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x49240, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

auto CCMenuItemSpriteExtra::create(cocos2d::CCNode* sprite, cocos2d::CCNode* selectedSprite, cocos2d::CCObject* target, cocos2d::SEL_MenuHandler callback) -> decltype(create(sprite, selectedSprite, target, callback)) {
	using FunctionType = decltype(create(sprite, selectedSprite, target, callback))(*)(cocos2d::CCNode*, cocos2d::CCNode*, cocos2d::CCObject*, cocos2d::SEL_MenuHandler);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x21903c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(sprite, selectedSprite, target, callback);
}

auto CCMenuItemSpriteExtra::activate() -> decltype(activate()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CCMenuItemSpriteExtra::activate), this);
	using FunctionType = decltype(activate())(*)(CCMenuItemSpriteExtra*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x219280, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CCMenuItemSpriteExtra::selected() -> decltype(selected()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CCMenuItemSpriteExtra::selected), this);
	using FunctionType = decltype(selected())(*)(CCMenuItemSpriteExtra*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2193d4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CCMenuItemSpriteExtra::unselected() -> decltype(unselected()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CCMenuItemSpriteExtra::unselected), this);
	using FunctionType = decltype(unselected())(*)(CCMenuItemSpriteExtra*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x219620, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CCMenuItemSpriteExtra::init(cocos2d::CCNode* sprite, cocos2d::CCNode* selectedSprite, cocos2d::CCObject* target, cocos2d::SEL_MenuHandler callback) -> decltype(init(sprite, selectedSprite, target, callback)) {
	using FunctionType = decltype(init(sprite, selectedSprite, target, callback))(*)(CCMenuItemSpriteExtra*, cocos2d::CCNode*, cocos2d::CCNode*, cocos2d::CCObject*, cocos2d::SEL_MenuHandler);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2190f4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sprite, selectedSprite, target, callback);
}

auto CCMenuItemSpriteExtra::setSizeMult(float mult) -> decltype(setSizeMult(mult)) {
	using FunctionType = decltype(setSizeMult(mult))(*)(CCMenuItemSpriteExtra*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x219278, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, mult);
}

auto CCMenuItemSpriteExtra::useAnimationType(MenuAnimationType type) -> decltype(useAnimationType(type)) {
	using FunctionType = decltype(useAnimationType(type))(*)(CCMenuItemSpriteExtra*, MenuAnimationType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x219230, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type);
}
