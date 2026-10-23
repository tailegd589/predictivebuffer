
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/CustomizeObjectSettingsPopup.hpp>
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

auto CustomizeObjectSettingsPopup::create(GameObject* object, cocos2d::CCArray* objects, CustomizeObjectLayer* layer) -> decltype(create(object, objects, layer)) {
	using FunctionType = decltype(create(object, objects, layer))(*)(GameObject*, cocos2d::CCArray*, CustomizeObjectLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1a61a8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(object, objects, layer);
}

auto CustomizeObjectSettingsPopup::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCObject*>::func(&CustomizeObjectSettingsPopup::onClose), this);
	using FunctionType = decltype(onClose(sender))(*)(CustomizeObjectSettingsPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1a75c8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, sender);
}

auto CustomizeObjectSettingsPopup::onCustomToggleTriggerValue(cocos2d::CCObject* sender) -> decltype(onCustomToggleTriggerValue(sender)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCObject*>::func(&CustomizeObjectSettingsPopup::onCustomToggleTriggerValue), this);
	using FunctionType = decltype(onCustomToggleTriggerValue(sender))(*)(CustomizeObjectSettingsPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1a7548, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, sender);
}

auto CustomizeObjectSettingsPopup::init(GameObject* object, cocos2d::CCArray* objects, CustomizeObjectLayer* layer) -> decltype(init(object, objects, layer)) {
	using FunctionType = decltype(init(object, objects, layer))(*)(CustomizeObjectSettingsPopup*, GameObject*, cocos2d::CCArray*, CustomizeObjectLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1a7178, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, objects, layer);
}
