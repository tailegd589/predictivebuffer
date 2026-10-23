
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/CreateGuidelinesLayer.hpp>
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

CreateGuidelinesLayer::~CreateGuidelinesLayer() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(CreateGuidelinesLayer*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x46257c, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) CreateGuidelinesLayer(geode::CutoffConstructor, sizeof(CreateGuidelinesLayer));
		geode::DestructorLock::addLock(this);
	}
}

auto CreateGuidelinesLayer::create(CustomSongDelegate* delegate, AudioGuidelinesType type) -> decltype(create(delegate, type)) {
	using FunctionType = decltype(create(delegate, type))(*)(CustomSongDelegate*, AudioGuidelinesType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x462810, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(delegate, type);
}

auto CreateGuidelinesLayer::update(float dt) -> decltype(update(dt)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&CreateGuidelinesLayer::update), this);
	using FunctionType = decltype(update(dt))(*)(CreateGuidelinesLayer*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x464594, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, dt);
}

auto CreateGuidelinesLayer::ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchBegan(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&CreateGuidelinesLayer::ccTouchBegan), this);
	using FunctionType = decltype(ccTouchBegan(touch, event))(*)(CreateGuidelinesLayer*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4647f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto CreateGuidelinesLayer::ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchMoved(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&CreateGuidelinesLayer::ccTouchMoved), this);
	using FunctionType = decltype(ccTouchMoved(touch, event))(*)(CreateGuidelinesLayer*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x464920, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto CreateGuidelinesLayer::ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchEnded(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&CreateGuidelinesLayer::ccTouchEnded), this);
	using FunctionType = decltype(ccTouchEnded(touch, event))(*)(CreateGuidelinesLayer*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x464928, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto CreateGuidelinesLayer::ccTouchCancelled(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchCancelled(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&CreateGuidelinesLayer::ccTouchCancelled), this);
	using FunctionType = decltype(ccTouchCancelled(touch, event))(*)(CreateGuidelinesLayer*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x464a08, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto CreateGuidelinesLayer::registerWithTouchDispatcher() -> decltype(registerWithTouchDispatcher()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CreateGuidelinesLayer::registerWithTouchDispatcher), this);
	using FunctionType = decltype(registerWithTouchDispatcher())(*)(CreateGuidelinesLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x464a24, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CreateGuidelinesLayer::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CreateGuidelinesLayer::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(CreateGuidelinesLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x46476c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CreateGuidelinesLayer::keyDown(cocos2d::enumKeyCodes key, double timestamp) -> decltype(keyDown(key, timestamp)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::enumKeyCodes, double>::func(&CreateGuidelinesLayer::keyDown), this);
	using FunctionType = decltype(keyDown(key, timestamp))(*)(CreateGuidelinesLayer*, cocos2d::enumKeyCodes, double);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x464a5c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, key, timestamp);
}

auto CreateGuidelinesLayer::FLAlert_Clicked(FLAlertLayer* layer, bool btn2) -> decltype(FLAlert_Clicked(layer, btn2)) {
	auto self = addresser::thunkAdjust(Resolve<FLAlertLayer*, bool>::func(&CreateGuidelinesLayer::FLAlert_Clicked), this);
	using FunctionType = decltype(FLAlert_Clicked(layer, btn2))(*)(CreateGuidelinesLayer*, FLAlertLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x464660, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, layer, btn2);
}

auto CreateGuidelinesLayer::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCObject*>::func(&CreateGuidelinesLayer::onClose), this);
	using FunctionType = decltype(onClose(sender))(*)(CreateGuidelinesLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x464730, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, sender);
}

auto CreateGuidelinesLayer::keyUp(cocos2d::enumKeyCodes key, double timestamp) -> decltype(keyUp(key, timestamp)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::enumKeyCodes, double>::func(&CreateGuidelinesLayer::keyUp), this);
	using FunctionType = decltype(keyUp(key, timestamp))(*)(CreateGuidelinesLayer*, cocos2d::enumKeyCodes, double);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x464aa0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, key, timestamp);
}

auto CreateGuidelinesLayer::playMusic() -> decltype(playMusic()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CreateGuidelinesLayer::playMusic), this);
	using FunctionType = decltype(playMusic())(*)(CreateGuidelinesLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x463b68, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CreateGuidelinesLayer::registerTouch() -> decltype(registerTouch()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CreateGuidelinesLayer::registerTouch), this);
	using FunctionType = decltype(registerTouch())(*)(CreateGuidelinesLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4647a8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CreateGuidelinesLayer::onInfo(cocos2d::CCObject* sender) -> decltype(onInfo(sender)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCObject*>::func(&CreateGuidelinesLayer::onInfo), this);
	using FunctionType = decltype(onInfo(sender))(*)(CreateGuidelinesLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4645a4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, sender);
}

auto CreateGuidelinesLayer::onRecord(cocos2d::CCObject* sender) -> decltype(onRecord(sender)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCObject*>::func(&CreateGuidelinesLayer::onRecord), this);
	using FunctionType = decltype(onRecord(sender))(*)(CreateGuidelinesLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x463a54, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, sender);
}

auto CreateGuidelinesLayer::recordingDidStop() -> decltype(recordingDidStop()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CreateGuidelinesLayer::recordingDidStop), this);
	using FunctionType = decltype(recordingDidStop())(*)(CreateGuidelinesLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x463c08, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CreateGuidelinesLayer::doClearGuidelines() -> decltype(doClearGuidelines()) {
	using FunctionType = decltype(doClearGuidelines())(*)(CreateGuidelinesLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4639ac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CreateGuidelinesLayer::getMergedRecordString(gd::string str1, gd::string str2) -> decltype(getMergedRecordString(str1, str2)) {
	using FunctionType = decltype(getMergedRecordString(str1, str2))(*)(CreateGuidelinesLayer*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x463f50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, str1, str2);
}

auto CreateGuidelinesLayer::init(CustomSongDelegate* delegate, AudioGuidelinesType type) -> decltype(init(delegate, type)) {
	using FunctionType = decltype(init(delegate, type))(*)(CreateGuidelinesLayer*, CustomSongDelegate*, AudioGuidelinesType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x46293c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, delegate, type);
}

auto CreateGuidelinesLayer::onClearGuidelines(cocos2d::CCObject* sender) -> decltype(onClearGuidelines(sender)) {
	using FunctionType = decltype(onClearGuidelines(sender))(*)(CreateGuidelinesLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4637d4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto CreateGuidelinesLayer::onStop(cocos2d::CCObject* sender) -> decltype(onStop(sender)) {
	using FunctionType = decltype(onStop(sender))(*)(CreateGuidelinesLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4638a4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto CreateGuidelinesLayer::toggleItems(bool visible) -> decltype(toggleItems(visible)) {
	using FunctionType = decltype(toggleItems(visible))(*)(CreateGuidelinesLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x463904, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, visible);
}
