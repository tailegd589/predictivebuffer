
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/SetupAreaMoveTriggerPopup.hpp>
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

SetupAreaMoveTriggerPopup::~SetupAreaMoveTriggerPopup() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(SetupAreaMoveTriggerPopup*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x42fe9c, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) SetupAreaMoveTriggerPopup(geode::CutoffConstructor, sizeof(SetupAreaMoveTriggerPopup));
		geode::DestructorLock::addLock(this);
	}
}

auto SetupAreaMoveTriggerPopup::create(EnterEffectObject* object, cocos2d::CCArray* objects) -> decltype(create(object, objects)) {
	using FunctionType = decltype(create(object, objects))(*)(EnterEffectObject*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x430174, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(object, objects);
}

auto SetupAreaMoveTriggerPopup::updateInputValue(int tag, float& value) -> decltype(updateInputValue(tag, value)) {
	auto self = addresser::thunkAdjust(Resolve<int, float&>::func(&SetupAreaMoveTriggerPopup::updateInputValue), this);
	using FunctionType = decltype(updateInputValue(tag, value))(*)(SetupAreaMoveTriggerPopup*, int, float&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x432b14, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, tag, value);
}

auto SetupAreaMoveTriggerPopup::updateDefaultTriggerValues() -> decltype(updateDefaultTriggerValues()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&SetupAreaMoveTriggerPopup::updateDefaultTriggerValues), this);
	using FunctionType = decltype(updateDefaultTriggerValues())(*)(SetupAreaMoveTriggerPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4326a8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto SetupAreaMoveTriggerPopup::updateInputNode(int tag, float value) -> decltype(updateInputNode(tag, value)) {
	auto self = addresser::thunkAdjust(Resolve<int, float>::func(&SetupAreaMoveTriggerPopup::updateInputNode), this);
	using FunctionType = decltype(updateInputNode(tag, value))(*)(SetupAreaMoveTriggerPopup*, int, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x432ae0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, tag, value);
}

auto SetupAreaMoveTriggerPopup::valueDidChange(int tag, float value) -> decltype(valueDidChange(tag, value)) {
	auto self = addresser::thunkAdjust(Resolve<int, float>::func(&SetupAreaMoveTriggerPopup::valueDidChange), this);
	using FunctionType = decltype(valueDidChange(tag, value))(*)(SetupAreaMoveTriggerPopup*, int, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4329bc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, tag, value);
}

auto SetupAreaMoveTriggerPopup::triggerValueFromSliderValue(int tag, float value) -> decltype(triggerValueFromSliderValue(tag, value)) {
	auto self = addresser::thunkAdjust(Resolve<int, float>::func(&SetupAreaMoveTriggerPopup::triggerValueFromSliderValue), this);
	using FunctionType = decltype(triggerValueFromSliderValue(tag, value))(*)(SetupAreaMoveTriggerPopup*, int, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x432a58, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, tag, value);
}

auto SetupAreaMoveTriggerPopup::triggerSliderValueFromValue(int tag, float value) -> decltype(triggerSliderValueFromValue(tag, value)) {
	auto self = addresser::thunkAdjust(Resolve<int, float>::func(&SetupAreaMoveTriggerPopup::triggerSliderValueFromValue), this);
	using FunctionType = decltype(triggerSliderValueFromValue(tag, value))(*)(SetupAreaMoveTriggerPopup*, int, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x432aac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, tag, value);
}

auto SetupAreaMoveTriggerPopup::addAreaDefaultControls(int objectID) -> decltype(addAreaDefaultControls(objectID)) {
	using FunctionType = decltype(addAreaDefaultControls(objectID))(*)(SetupAreaMoveTriggerPopup*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x431004, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, objectID);
}

auto SetupAreaMoveTriggerPopup::getModeValues(int mode, int& direction, bool& inbound, bool& twoDirections) -> decltype(getModeValues(mode, direction, inbound, twoDirections)) {
	using FunctionType = decltype(getModeValues(mode, direction, inbound, twoDirections))(*)(SetupAreaMoveTriggerPopup*, int, int&, bool&, bool&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x432498, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, mode, direction, inbound, twoDirections);
}

auto SetupAreaMoveTriggerPopup::init(EnterEffectObject* object, cocos2d::CCArray* objects) -> decltype(init(object, objects)) {
	using FunctionType = decltype(init(object, objects))(*)(SetupAreaMoveTriggerPopup*, EnterEffectObject*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x430300, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, objects);
}

auto SetupAreaMoveTriggerPopup::onMode(cocos2d::CCObject* sender) -> decltype(onMode(sender)) {
	using FunctionType = decltype(onMode(sender))(*)(SetupAreaMoveTriggerPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4324ec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupAreaMoveTriggerPopup::onNextFreeEffectID(cocos2d::CCObject* sender) -> decltype(onNextFreeEffectID(sender)) {
	using FunctionType = decltype(onNextFreeEffectID(sender))(*)(SetupAreaMoveTriggerPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x43232c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupAreaMoveTriggerPopup::onSpecialTarget(cocos2d::CCObject* sender) -> decltype(onSpecialTarget(sender)) {
	using FunctionType = decltype(onSpecialTarget(sender))(*)(SetupAreaMoveTriggerPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4323c8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupAreaMoveTriggerPopup::updateEnterTargetIDState() -> decltype(updateEnterTargetIDState()) {
	using FunctionType = decltype(updateEnterTargetIDState())(*)(SetupAreaMoveTriggerPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4326fc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
