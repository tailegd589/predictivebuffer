
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/SetupPulsePopup.hpp>
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

auto SetupPulsePopup::create(EffectGameObject* object, cocos2d::CCArray* objects) -> decltype(create(object, objects)) {
	using FunctionType = decltype(create(object, objects))(*)(EffectGameObject*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3aa030, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(object, objects);
}

auto SetupPulsePopup::show() -> decltype(show()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&SetupPulsePopup::show), this);
	using FunctionType = decltype(show())(*)(SetupPulsePopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3aff50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto SetupPulsePopup::determineStartValues() -> decltype(determineStartValues()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&SetupPulsePopup::determineStartValues), this);
	using FunctionType = decltype(determineStartValues())(*)(SetupPulsePopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3aeb50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto SetupPulsePopup::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCObject*>::func(&SetupPulsePopup::onClose), this);
	using FunctionType = decltype(onClose(sender))(*)(SetupPulsePopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3af7b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, sender);
}

auto SetupPulsePopup::textChanged(CCTextInputNode* node) -> decltype(textChanged(node)) {
	auto self = addresser::thunkAdjust(Resolve<CCTextInputNode*>::func(&SetupPulsePopup::textChanged), this);
	using FunctionType = decltype(textChanged(node))(*)(SetupPulsePopup*, CCTextInputNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3affd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, node);
}

auto SetupPulsePopup::colorValueChanged(cocos2d::ccColor3B color) -> decltype(colorValueChanged(color)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::ccColor3B>::func(&SetupPulsePopup::colorValueChanged), this);
	using FunctionType = decltype(colorValueChanged(color))(*)(SetupPulsePopup*, cocos2d::ccColor3B);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3af990, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, color);
}

auto SetupPulsePopup::textInputOpened(CCTextInputNode* node) -> decltype(textInputOpened(node)) {
	auto self = addresser::thunkAdjust(Resolve<CCTextInputNode*>::func(&SetupPulsePopup::textInputOpened), this);
	using FunctionType = decltype(textInputOpened(node))(*)(SetupPulsePopup*, CCTextInputNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3affb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, node);
}

auto SetupPulsePopup::colorSelectClosed(GJSpecialColorSelect* select, int id) -> decltype(colorSelectClosed(select, id)) {
	auto self = addresser::thunkAdjust(Resolve<GJSpecialColorSelect*, int>::func(&SetupPulsePopup::colorSelectClosed), this);
	using FunctionType = decltype(colorSelectClosed(select, id))(*)(SetupPulsePopup*, GJSpecialColorSelect*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3af100, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, select, id);
}

auto SetupPulsePopup::getColorValue() -> decltype(getColorValue()) {
	using FunctionType = decltype(getColorValue())(*)(SetupPulsePopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3af530, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupPulsePopup::init(EffectGameObject* object, cocos2d::CCArray* objects) -> decltype(init(object, objects)) {
	using FunctionType = decltype(init(object, objects))(*)(SetupPulsePopup*, EffectGameObject*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3aa300, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, objects);
}

auto SetupPulsePopup::onCopy(cocos2d::CCObject* sender) -> decltype(onCopy(sender)) {
	using FunctionType = decltype(onCopy(sender))(*)(SetupPulsePopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ae420, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupPulsePopup::onExclusive(cocos2d::CCObject* sender) -> decltype(onExclusive(sender)) {
	using FunctionType = decltype(onExclusive(sender))(*)(SetupPulsePopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ae0a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupPulsePopup::onGroupMainOnly(cocos2d::CCObject* sender) -> decltype(onGroupMainOnly(sender)) {
	using FunctionType = decltype(onGroupMainOnly(sender))(*)(SetupPulsePopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ae130, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupPulsePopup::onGroupSecondaryOnly(cocos2d::CCObject* sender) -> decltype(onGroupSecondaryOnly(sender)) {
	using FunctionType = decltype(onGroupSecondaryOnly(sender))(*)(SetupPulsePopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ae260, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupPulsePopup::onHSVLegacyMode(cocos2d::CCObject* sender) -> decltype(onHSVLegacyMode(sender)) {
	using FunctionType = decltype(onHSVLegacyMode(sender))(*)(SetupPulsePopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ae390, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupPulsePopup::onPaste(cocos2d::CCObject* sender) -> decltype(onPaste(sender)) {
	using FunctionType = decltype(onPaste(sender))(*)(SetupPulsePopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ae460, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupPulsePopup::onSelectPulseMode(cocos2d::CCObject* sender) -> decltype(onSelectPulseMode(sender)) {
	using FunctionType = decltype(onSelectPulseMode(sender))(*)(SetupPulsePopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ade80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupPulsePopup::onSelectSpecialColor(cocos2d::CCObject* sender) -> decltype(onSelectSpecialColor(sender)) {
	using FunctionType = decltype(onSelectSpecialColor(sender))(*)(SetupPulsePopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ae5a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupPulsePopup::onSelectSpecialTargetID(cocos2d::CCObject* sender) -> decltype(onSelectSpecialTargetID(sender)) {
	using FunctionType = decltype(onSelectSpecialTargetID(sender))(*)(SetupPulsePopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ade40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupPulsePopup::onSelectTargetMode(cocos2d::CCObject* sender) -> decltype(onSelectTargetMode(sender)) {
	using FunctionType = decltype(onSelectTargetMode(sender))(*)(SetupPulsePopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3adad0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupPulsePopup::onUpdateCopyColor(cocos2d::CCObject* sender) -> decltype(onUpdateCopyColor(sender)) {
	using FunctionType = decltype(onUpdateCopyColor(sender))(*)(SetupPulsePopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ae4d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupPulsePopup::onUpdateCustomColor(cocos2d::CCObject* sender) -> decltype(onUpdateCustomColor(sender)) {
	using FunctionType = decltype(onUpdateCustomColor(sender))(*)(SetupPulsePopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3add50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupPulsePopup::selectColor(cocos2d::ccColor3B color) -> decltype(selectColor(color)) {
	using FunctionType = decltype(selectColor(color))(*)(SetupPulsePopup*, cocos2d::ccColor3B);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ae4a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, color);
}

auto SetupPulsePopup::sliderChanged(cocos2d::CCObject* sender) -> decltype(sliderChanged(sender)) {
	using FunctionType = decltype(sliderChanged(sender))(*)(SetupPulsePopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ad4b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupPulsePopup::updateColorLabels() -> decltype(updateColorLabels()) {
	using FunctionType = decltype(updateColorLabels())(*)(SetupPulsePopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3afb30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupPulsePopup::updateColorValue() -> decltype(updateColorValue()) {
	using FunctionType = decltype(updateColorValue())(*)(SetupPulsePopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3afa90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupPulsePopup::updateCopyColor() -> decltype(updateCopyColor()) {
	using FunctionType = decltype(updateCopyColor())(*)(SetupPulsePopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3af490, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupPulsePopup::updateCopyColorTextInputLabel() -> decltype(updateCopyColorTextInputLabel()) {
	using FunctionType = decltype(updateCopyColorTextInputLabel())(*)(SetupPulsePopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ae7e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupPulsePopup::updateFadeInLabel(bool decimals) -> decltype(updateFadeInLabel(decimals)) {
	using FunctionType = decltype(updateFadeInLabel(decimals))(*)(SetupPulsePopup*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ad6e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, decimals);
}

auto SetupPulsePopup::updateFadeInTime() -> decltype(updateFadeInTime()) {
	using FunctionType = decltype(updateFadeInTime())(*)(SetupPulsePopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3af550, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupPulsePopup::updateFadeOutLabel(bool decimals) -> decltype(updateFadeOutLabel(decimals)) {
	using FunctionType = decltype(updateFadeOutLabel(decimals))(*)(SetupPulsePopup*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ad980, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, decimals);
}

auto SetupPulsePopup::updateFadeOutTime() -> decltype(updateFadeOutTime()) {
	using FunctionType = decltype(updateFadeOutTime())(*)(SetupPulsePopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3af670, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupPulsePopup::updateGroupMainOnly() -> decltype(updateGroupMainOnly()) {
	using FunctionType = decltype(updateGroupMainOnly())(*)(SetupPulsePopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3af080, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupPulsePopup::updateGroupSecondaryOnly() -> decltype(updateGroupSecondaryOnly()) {
	using FunctionType = decltype(updateGroupSecondaryOnly())(*)(SetupPulsePopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3af000, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupPulsePopup::updateHoldLabel(bool decimals) -> decltype(updateHoldLabel(decimals)) {
	using FunctionType = decltype(updateHoldLabel(decimals))(*)(SetupPulsePopup*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ad830, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, decimals);
}

auto SetupPulsePopup::updateHoldTime() -> decltype(updateHoldTime()) {
	using FunctionType = decltype(updateHoldTime())(*)(SetupPulsePopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3af5e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupPulsePopup::updateHSVValue() -> decltype(updateHSVValue()) {
	using FunctionType = decltype(updateHSVValue())(*)(SetupPulsePopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3af700, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupPulsePopup::updatePulseMode() -> decltype(updatePulseMode()) {
	using FunctionType = decltype(updatePulseMode())(*)(SetupPulsePopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ae9d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupPulsePopup::updatePulseTargetType() -> decltype(updatePulseTargetType()) {
	using FunctionType = decltype(updatePulseTargetType())(*)(SetupPulsePopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3aead0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupPulsePopup::updateTargetID() -> decltype(updateTargetID()) {
	using FunctionType = decltype(updateTargetID())(*)(SetupPulsePopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3aea50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupPulsePopup::updateTextInputLabel() -> decltype(updateTextInputLabel()) {
	using FunctionType = decltype(updateTextInputLabel())(*)(SetupPulsePopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3ae5e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
