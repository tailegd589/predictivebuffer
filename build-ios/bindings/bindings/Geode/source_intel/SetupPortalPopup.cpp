
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/SetupPortalPopup.hpp>
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

auto SetupPortalPopup::create(EffectGameObject* object, cocos2d::CCArray* objects) -> decltype(create(object, objects)) {
	using FunctionType = decltype(create(object, objects))(*)(EffectGameObject*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x56f690, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(object, objects);
}

auto SetupPortalPopup::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&SetupPortalPopup::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(SetupPortalPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5709d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto SetupPortalPopup::determineStartValues() -> decltype(determineStartValues()) {
	using FunctionType = decltype(determineStartValues())(*)(SetupPortalPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5701a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupPortalPopup::init(EffectGameObject* object, cocos2d::CCArray* objects) -> decltype(init(object, objects)) {
	using FunctionType = decltype(init(object, objects))(*)(SetupPortalPopup*, EffectGameObject*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x56f810, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, objects);
}

auto SetupPortalPopup::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	using FunctionType = decltype(onClose(sender))(*)(SetupPortalPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x570150, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupPortalPopup::onEditCameraSettings(cocos2d::CCObject* sender) -> decltype(onEditCameraSettings(sender)) {
	using FunctionType = decltype(onEditCameraSettings(sender))(*)(SetupPortalPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x570450, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupPortalPopup::onUnboundMode(cocos2d::CCObject* sender) -> decltype(onUnboundMode(sender)) {
	using FunctionType = decltype(onUnboundMode(sender))(*)(SetupPortalPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5703d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupPortalPopup::sliderChanged(cocos2d::CCObject* sender) -> decltype(sliderChanged(sender)) {
	using FunctionType = decltype(sliderChanged(sender))(*)(SetupPortalPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5705b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupPortalPopup::updateCameraEasing() -> decltype(updateCameraEasing()) {
	using FunctionType = decltype(updateCameraEasing())(*)(SetupPortalPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5708d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupPortalPopup::updateCameraEasingLabel() -> decltype(updateCameraEasingLabel()) {
	using FunctionType = decltype(updateCameraEasingLabel())(*)(SetupPortalPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x570780, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupPortalPopup::updateCameraPadding() -> decltype(updateCameraPadding()) {
	using FunctionType = decltype(updateCameraPadding())(*)(SetupPortalPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x570950, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupPortalPopup::updateCameraPaddingLabel() -> decltype(updateCameraPaddingLabel()) {
	using FunctionType = decltype(updateCameraPaddingLabel())(*)(SetupPortalPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5707d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupPortalPopup::updateItemVisibility() -> decltype(updateItemVisibility()) {
	using FunctionType = decltype(updateItemVisibility())(*)(SetupPortalPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x570820, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
