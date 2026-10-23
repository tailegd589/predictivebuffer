
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/SetupSFXPopup.hpp>
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

auto SetupSFXPopup::create(SFXTriggerGameObject* object, cocos2d::CCArray* objects) -> decltype(create(object, objects)) {
	using FunctionType = decltype(create(object, objects))(*)(SFXTriggerGameObject*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b8950, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(object, objects);
}

auto SetupSFXPopup::pageChanged() -> decltype(pageChanged()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&SetupSFXPopup::pageChanged), this);
	using FunctionType = decltype(pageChanged())(*)(SetupSFXPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4ba1f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto SetupSFXPopup::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCObject*>::func(&SetupSFXPopup::onClose), this);
	using FunctionType = decltype(onClose(sender))(*)(SetupSFXPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4ba250, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, sender);
}

auto SetupSFXPopup::onPlusButton(cocos2d::CCObject* sender) -> decltype(onPlusButton(sender)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCObject*>::func(&SetupSFXPopup::onPlusButton), this);
	using FunctionType = decltype(onPlusButton(sender))(*)(SetupSFXPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4ba710, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, sender);
}

auto SetupSFXPopup::valueDidChange(int tag, float value) -> decltype(valueDidChange(tag, value)) {
	auto self = addresser::thunkAdjust(Resolve<int, float>::func(&SetupSFXPopup::valueDidChange), this);
	using FunctionType = decltype(valueDidChange(tag, value))(*)(SetupSFXPopup*, int, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4ba5f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, tag, value);
}

auto SetupSFXPopup::sfxObjectSelected(SFXInfoObject* object) -> decltype(sfxObjectSelected(object)) {
	auto self = addresser::thunkAdjust(Resolve<SFXInfoObject*>::func(&SetupSFXPopup::sfxObjectSelected), this);
	using FunctionType = decltype(sfxObjectSelected(object))(*)(SetupSFXPopup*, SFXInfoObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4ba510, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, object);
}

auto SetupSFXPopup::getActiveSFXID() -> decltype(getActiveSFXID()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&SetupSFXPopup::getActiveSFXID), this);
	using FunctionType = decltype(getActiveSFXID())(*)(SetupSFXPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4ba530, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto SetupSFXPopup::overridePlaySFX(SFXInfoObject* object) -> decltype(overridePlaySFX(object)) {
	auto self = addresser::thunkAdjust(Resolve<SFXInfoObject*>::func(&SetupSFXPopup::overridePlaySFX), this);
	using FunctionType = decltype(overridePlaySFX(object))(*)(SetupSFXPopup*, SFXInfoObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4ba550, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, object);
}

auto SetupSFXPopup::sfxBrowserClosed(SFXBrowser* browser) -> decltype(sfxBrowserClosed(browser)) {
	auto self = addresser::thunkAdjust(Resolve<SFXBrowser*>::func(&SetupSFXPopup::sfxBrowserClosed), this);
	using FunctionType = decltype(sfxBrowserClosed(browser))(*)(SetupSFXPopup*, SFXBrowser*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4ba880, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, browser);
}

auto SetupSFXPopup::createSFXWidget() -> decltype(createSFXWidget()) {
	using FunctionType = decltype(createSFXWidget())(*)(SetupSFXPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b9f40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupSFXPopup::init(SFXTriggerGameObject* object, cocos2d::CCArray* objects) -> decltype(init(object, objects)) {
	using FunctionType = decltype(init(object, objects))(*)(SetupSFXPopup*, SFXTriggerGameObject*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b8bc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, objects);
}

auto SetupSFXPopup::onBrowseSFX(cocos2d::CCObject* sender) -> decltype(onBrowseSFX(sender)) {
	using FunctionType = decltype(onBrowseSFX(sender))(*)(SetupSFXPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4b9ee0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupSFXPopup::updateLength() -> decltype(updateLength()) {
	using FunctionType = decltype(updateLength())(*)(SetupSFXPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4ba4c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
