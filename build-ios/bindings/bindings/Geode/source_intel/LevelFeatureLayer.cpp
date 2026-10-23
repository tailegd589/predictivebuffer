
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/LevelFeatureLayer.hpp>
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

auto LevelFeatureLayer::create(int levelID) -> decltype(create(levelID)) {
	using FunctionType = decltype(create(levelID))(*)(int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x504bd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(levelID);
}

auto LevelFeatureLayer::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&LevelFeatureLayer::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(LevelFeatureLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5057f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto LevelFeatureLayer::init(int levelID) -> decltype(init(levelID)) {
	using FunctionType = decltype(init(levelID))(*)(LevelFeatureLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x504d10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, levelID);
}

auto LevelFeatureLayer::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	using FunctionType = decltype(onClose(sender))(*)(LevelFeatureLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5054c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelFeatureLayer::onDown(cocos2d::CCObject* sender) -> decltype(onDown(sender)) {
	using FunctionType = decltype(onDown(sender))(*)(LevelFeatureLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5055a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelFeatureLayer::onDown2(cocos2d::CCObject* sender) -> decltype(onDown2(sender)) {
	using FunctionType = decltype(onDown2(sender))(*)(LevelFeatureLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x505650, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelFeatureLayer::onRemoveValues(cocos2d::CCObject* sender) -> decltype(onRemoveValues(sender)) {
	using FunctionType = decltype(onRemoveValues(sender))(*)(LevelFeatureLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x505750, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelFeatureLayer::onSetEpicOnly(cocos2d::CCObject* sender) -> decltype(onSetEpicOnly(sender)) {
	using FunctionType = decltype(onSetEpicOnly(sender))(*)(LevelFeatureLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x505550, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelFeatureLayer::onSetFeatured(cocos2d::CCObject* sender) -> decltype(onSetFeatured(sender)) {
	using FunctionType = decltype(onSetFeatured(sender))(*)(LevelFeatureLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5054f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelFeatureLayer::onToggleEpic(cocos2d::CCObject* sender) -> decltype(onToggleEpic(sender)) {
	using FunctionType = decltype(onToggleEpic(sender))(*)(LevelFeatureLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5057a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelFeatureLayer::onUp(cocos2d::CCObject* sender) -> decltype(onUp(sender)) {
	using FunctionType = decltype(onUp(sender))(*)(LevelFeatureLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x505600, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelFeatureLayer::onUp2(cocos2d::CCObject* sender) -> decltype(onUp2(sender)) {
	using FunctionType = decltype(onUp2(sender))(*)(LevelFeatureLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5056b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LevelFeatureLayer::updateStars() -> decltype(updateStars()) {
	using FunctionType = decltype(updateStars())(*)(LevelFeatureLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x505700, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
