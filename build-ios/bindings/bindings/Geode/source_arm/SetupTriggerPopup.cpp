
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/SetupTriggerPopup.hpp>
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

SetupTriggerPopup::~SetupTriggerPopup() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(SetupTriggerPopup*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x1de5a0, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) SetupTriggerPopup(geode::CutoffConstructor, sizeof(SetupTriggerPopup));
		geode::DestructorLock::addLock(this);
	}
}

auto SetupTriggerPopup::create(float width, float height) -> decltype(create(width, height)) {
	using FunctionType = decltype(create(width, height))(*)(float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1deb8c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(width, height);
}

auto SetupTriggerPopup::create(EffectGameObject* trigger, cocos2d::CCArray* triggers, float width, float height, int background) -> decltype(create(trigger, triggers, width, height, background)) {
	using FunctionType = decltype(create(trigger, triggers, width, height, background))(*)(EffectGameObject*, cocos2d::CCArray*, float, float, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1de748, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(trigger, triggers, width, height, background);
}

auto SetupTriggerPopup::ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchBegan(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&SetupTriggerPopup::ccTouchBegan), this);
	using FunctionType = decltype(ccTouchBegan(touch, event))(*)(SetupTriggerPopup*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e78c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto SetupTriggerPopup::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&SetupTriggerPopup::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(SetupTriggerPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e1710, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto SetupTriggerPopup::show() -> decltype(show()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&SetupTriggerPopup::show), this);
	using FunctionType = decltype(show())(*)(SetupTriggerPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e158c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto SetupTriggerPopup::toggleGroup(int group, bool visible) -> decltype(toggleGroup(group, visible)) {
	auto self = addresser::thunkAdjust(Resolve<int, bool>::func(&SetupTriggerPopup::toggleGroup), this);
	using FunctionType = decltype(toggleGroup(group, visible))(*)(SetupTriggerPopup*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1df31c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, group, visible);
}

auto SetupTriggerPopup::determineStartValues() -> decltype(determineStartValues()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&SetupTriggerPopup::determineStartValues), this);
	using FunctionType = decltype(determineStartValues())(*)(SetupTriggerPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e036c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto SetupTriggerPopup::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCObject*>::func(&SetupTriggerPopup::onClose), this);
	using FunctionType = decltype(onClose(sender))(*)(SetupTriggerPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e15d8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, sender);
}

auto SetupTriggerPopup::textInputClosed(CCTextInputNode* node) -> decltype(textInputClosed(node)) {
	auto self = addresser::thunkAdjust(Resolve<CCTextInputNode*>::func(&SetupTriggerPopup::textInputClosed), this);
	using FunctionType = decltype(textInputClosed(node))(*)(SetupTriggerPopup*, CCTextInputNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e066c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, node);
}

auto SetupTriggerPopup::textChanged(CCTextInputNode* node) -> decltype(textChanged(node)) {
	auto self = addresser::thunkAdjust(Resolve<CCTextInputNode*>::func(&SetupTriggerPopup::textChanged), this);
	using FunctionType = decltype(textChanged(node))(*)(SetupTriggerPopup*, CCTextInputNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e0688, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, node);
}

auto SetupTriggerPopup::textInputShouldOffset(CCTextInputNode* node, float yOffset) -> decltype(textInputShouldOffset(node, yOffset)) {
	auto self = addresser::thunkAdjust(Resolve<CCTextInputNode*, float>::func(&SetupTriggerPopup::textInputShouldOffset), this);
	using FunctionType = decltype(textInputShouldOffset(node, yOffset))(*)(SetupTriggerPopup*, CCTextInputNode*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e1734, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, node, yOffset);
}

auto SetupTriggerPopup::textInputReturn(CCTextInputNode* node) -> decltype(textInputReturn(node)) {
	auto self = addresser::thunkAdjust(Resolve<CCTextInputNode*>::func(&SetupTriggerPopup::textInputReturn), this);
	using FunctionType = decltype(textInputReturn(node))(*)(SetupTriggerPopup*, CCTextInputNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e1804, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, node);
}

auto SetupTriggerPopup::sliderBegan(Slider* slider) -> decltype(sliderBegan(slider)) {
	auto self = addresser::thunkAdjust(Resolve<Slider*>::func(&SetupTriggerPopup::sliderBegan), this);
	using FunctionType = decltype(sliderBegan(slider))(*)(SetupTriggerPopup*, Slider*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e18bc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, slider);
}

auto SetupTriggerPopup::sliderEnded(Slider* slider) -> decltype(sliderEnded(slider)) {
	auto self = addresser::thunkAdjust(Resolve<Slider*>::func(&SetupTriggerPopup::sliderEnded), this);
	using FunctionType = decltype(sliderEnded(slider))(*)(SetupTriggerPopup*, Slider*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e198c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, slider);
}

auto SetupTriggerPopup::updateDefaultTriggerValues() -> decltype(updateDefaultTriggerValues()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&SetupTriggerPopup::updateDefaultTriggerValues), this);
	using FunctionType = decltype(updateDefaultTriggerValues())(*)(SetupTriggerPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e3eb8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto SetupTriggerPopup::updateInputNode(int tag, float value) -> decltype(updateInputNode(tag, value)) {
	auto self = addresser::thunkAdjust(Resolve<int, float>::func(&SetupTriggerPopup::updateInputNode), this);
	using FunctionType = decltype(updateInputNode(tag, value))(*)(SetupTriggerPopup*, int, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e555c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, tag, value);
}

auto SetupTriggerPopup::updateToggleItem(int value, bool toggled) -> decltype(updateToggleItem(value, toggled)) {
	auto self = addresser::thunkAdjust(Resolve<int, bool>::func(&SetupTriggerPopup::updateToggleItem), this);
	using FunctionType = decltype(updateToggleItem(value, toggled))(*)(SetupTriggerPopup*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e5798, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, value, toggled);
}

auto SetupTriggerPopup::getValue(int tag) -> decltype(getValue(tag)) {
	auto self = addresser::thunkAdjust(Resolve<int>::func(&SetupTriggerPopup::getValue), this);
	using FunctionType = decltype(getValue(tag))(*)(SetupTriggerPopup*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e5850, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, tag);
}

auto SetupTriggerPopup::triggerValueFromSliderValue(int tag, float value) -> decltype(triggerValueFromSliderValue(tag, value)) {
	auto self = addresser::thunkAdjust(Resolve<int, float>::func(&SetupTriggerPopup::triggerValueFromSliderValue), this);
	using FunctionType = decltype(triggerValueFromSliderValue(tag, value))(*)(SetupTriggerPopup*, int, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e5bfc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, tag, value);
}

auto SetupTriggerPopup::triggerSliderValueFromValue(int tag, float value) -> decltype(triggerSliderValueFromValue(tag, value)) {
	auto self = addresser::thunkAdjust(Resolve<int, float>::func(&SetupTriggerPopup::triggerSliderValueFromValue), this);
	using FunctionType = decltype(triggerSliderValueFromValue(tag, value))(*)(SetupTriggerPopup*, int, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e5c88, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, tag, value);
}

auto SetupTriggerPopup::valuePopupClosed(ConfigureValuePopup* popup, float value) -> decltype(valuePopupClosed(popup, value)) {
	auto self = addresser::thunkAdjust(Resolve<ConfigureValuePopup*, float>::func(&SetupTriggerPopup::valuePopupClosed), this);
	using FunctionType = decltype(valuePopupClosed(popup, value))(*)(SetupTriggerPopup*, ConfigureValuePopup*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e68c8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, popup, value);
}

auto SetupTriggerPopup::addCloseButton(gd::string text) -> decltype(addCloseButton(text)) {
	using FunctionType = decltype(addCloseButton(text))(*)(SetupTriggerPopup*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1df7bc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, text);
}

auto SetupTriggerPopup::addCustomButton(int tag, ButtonSprite* sprite, cocos2d::CCPoint position, int page, int group) -> decltype(addCustomButton(tag, sprite, position, page, group)) {
	using FunctionType = decltype(addCustomButton(tag, sprite, position, page, group))(*)(SetupTriggerPopup*, int, ButtonSprite*, cocos2d::CCPoint, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e3d1c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, tag, sprite, position, page, group);
}

auto SetupTriggerPopup::addHelpButton(gd::string title, gd::string desc, float scale) -> decltype(addHelpButton(title, desc, scale)) {
	using FunctionType = decltype(addHelpButton(title, desc, scale))(*)(SetupTriggerPopup*, gd::string, gd::string, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1df83c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, title, desc, scale);
}

auto SetupTriggerPopup::addInfoLabel(gd::string text, float scale, cocos2d::CCPoint position, int page, int group) -> decltype(addInfoLabel(text, scale, position, page, group)) {
	using FunctionType = decltype(addInfoLabel(text, scale, position, page, group))(*)(SetupTriggerPopup*, gd::string, float, cocos2d::CCPoint, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e36e8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, text, scale, position, page, group);
}

auto SetupTriggerPopup::addObjectsToGroup(cocos2d::CCArray* objects, int group) -> decltype(addObjectsToGroup(objects, group)) {
	using FunctionType = decltype(addObjectsToGroup(objects, group))(*)(SetupTriggerPopup*, cocos2d::CCArray*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1df610, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, objects, group);
}

auto SetupTriggerPopup::addObjectsToPage(cocos2d::CCArray* objects, int page) -> decltype(addObjectsToPage(objects, page)) {
	using FunctionType = decltype(addObjectsToPage(objects, page))(*)(SetupTriggerPopup*, cocos2d::CCArray*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1df4bc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, objects, page);
}

auto SetupTriggerPopup::addObjectToGroup(cocos2d::CCObject* object, int group) -> decltype(addObjectToGroup(object, group)) {
	using FunctionType = decltype(addObjectToGroup(object, group))(*)(SetupTriggerPopup*, cocos2d::CCObject*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1df5a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, group);
}

auto SetupTriggerPopup::addObjectToPage(cocos2d::CCObject* object, int page) -> decltype(addObjectToPage(object, page)) {
	using FunctionType = decltype(addObjectToPage(object, page))(*)(SetupTriggerPopup*, cocos2d::CCObject*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1df44c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, page);
}

auto SetupTriggerPopup::addTitle(gd::string title) -> decltype(addTitle(title)) {
	using FunctionType = decltype(addTitle(title))(*)(SetupTriggerPopup*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1df6f4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, title);
}

auto SetupTriggerPopup::closeInputNodes() -> decltype(closeInputNodes()) {
	using FunctionType = decltype(closeInputNodes())(*)(SetupTriggerPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e16c4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupTriggerPopup::createCustomButton(int tag, gd::string text, gd::string frame, cocos2d::CCPoint position, float buttonScale, float labelScale, bool vertical, int page, int group) -> decltype(createCustomButton(tag, text, frame, position, buttonScale, labelScale, vertical, page, group)) {
	using FunctionType = decltype(createCustomButton(tag, text, frame, position, buttonScale, labelScale, vertical, page, group))(*)(SetupTriggerPopup*, int, gd::string, gd::string, cocos2d::CCPoint, float, float, bool, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e39e4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, tag, text, frame, position, buttonScale, labelScale, vertical, page, group);
}

auto SetupTriggerPopup::createCustomEasingControls(gd::string text, cocos2d::CCPoint position, float scale, int typeProperty, int rateProperty, int page, int group) -> decltype(createCustomEasingControls(text, position, scale, typeProperty, rateProperty, page, group)) {
	using FunctionType = decltype(createCustomEasingControls(text, position, scale, typeProperty, rateProperty, page, group))(*)(SetupTriggerPopup*, gd::string, cocos2d::CCPoint, float, int, int, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e6abc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, text, position, scale, typeProperty, rateProperty, page, group);
}

auto SetupTriggerPopup::createCustomToggleValueControl(int property, bool toggled, bool notClickable, gd::string text, cocos2d::CCPoint position, bool vertical, int page, int group) -> decltype(createCustomToggleValueControl(property, toggled, notClickable, text, position, vertical, page, group)) {
	using FunctionType = decltype(createCustomToggleValueControl(property, toggled, notClickable, text, position, vertical, page, group))(*)(SetupTriggerPopup*, int, bool, bool, gd::string, cocos2d::CCPoint, bool, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e33f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, property, toggled, notClickable, text, position, vertical, page, group);
}

auto SetupTriggerPopup::createEasingControls(cocos2d::CCPoint position, float scale, int page, int group) -> decltype(createEasingControls(position, scale, page, group)) {
	using FunctionType = decltype(createEasingControls(position, scale, page, group))(*)(SetupTriggerPopup*, cocos2d::CCPoint, float, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e5d38, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, position, scale, page, group);
}

auto SetupTriggerPopup::createMultiTriggerItems(cocos2d::CCPoint touchPos, cocos2d::CCPoint spawnPos, cocos2d::CCPoint multiPos) -> decltype(createMultiTriggerItems(touchPos, spawnPos, multiPos)) {
	using FunctionType = decltype(createMultiTriggerItems(touchPos, spawnPos, multiPos))(*)(SetupTriggerPopup*, cocos2d::CCPoint, cocos2d::CCPoint, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1dfbfc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, touchPos, spawnPos, multiPos);
}

auto SetupTriggerPopup::createMultiTriggerItemsCorner() -> decltype(createMultiTriggerItemsCorner()) {
	using FunctionType = decltype(createMultiTriggerItemsCorner())(*)(SetupTriggerPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1dff1c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupTriggerPopup::createMultiTriggerItemsDefault() -> decltype(createMultiTriggerItemsDefault()) {
	using FunctionType = decltype(createMultiTriggerItemsDefault())(*)(SetupTriggerPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1dfb1c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupTriggerPopup::createMultiTriggerItemsDefaultHorizontal() -> decltype(createMultiTriggerItemsDefaultHorizontal()) {
	using FunctionType = decltype(createMultiTriggerItemsDefaultHorizontal())(*)(SetupTriggerPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e00bc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupTriggerPopup::createMultiTriggerItemsDefaultVertical() -> decltype(createMultiTriggerItemsDefaultVertical()) {
	using FunctionType = decltype(createMultiTriggerItemsDefaultVertical())(*)(SetupTriggerPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1dffec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupTriggerPopup::createPageButtons(float offset, int arrow) -> decltype(createPageButtons(offset, arrow)) {
	using FunctionType = decltype(createPageButtons(offset, arrow))(*)(SetupTriggerPopup*, float, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1debe8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, offset, arrow);
}

auto SetupTriggerPopup::createPlusButton(int tag, cocos2d::CCPoint position, float scale, gd::string frame, int page, int group) -> decltype(createPlusButton(tag, position, scale, frame, page, group)) {
	using FunctionType = decltype(createPlusButton(tag, position, scale, frame, page, group))(*)(SetupTriggerPopup*, int, cocos2d::CCPoint, float, gd::string, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e3828, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, tag, position, scale, frame, page, group);
}

auto SetupTriggerPopup::createToggleButton(gd::string text, cocos2d::SEL_MenuHandler selector, bool toggled, cocos2d::CCPoint position) -> decltype(createToggleButton(text, selector, toggled, position)) {
	using FunctionType = decltype(createToggleButton(text, selector, toggled, position))(*)(SetupTriggerPopup*, gd::string, cocos2d::SEL_MenuHandler, bool, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1df9e8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, text, selector, toggled, position);
}

auto SetupTriggerPopup::createToggleValueControl(int property, gd::string label, cocos2d::CCPoint position, bool vertical, int page, int group, float scale) -> decltype(createToggleValueControl(property, label, position, vertical, page, group, scale)) {
	using FunctionType = decltype(createToggleValueControl(property, label, position, vertical, page, group, scale))(*)(SetupTriggerPopup*, int, gd::string, cocos2d::CCPoint, bool, int, int, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e2ffc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, property, label, position, vertical, page, group, scale);
}

auto SetupTriggerPopup::createToggleValueControlAdvanced(int property, gd::string label, cocos2d::CCPoint position, bool vertical, int page, int group, float buttonScale, float labelScale, float labelWidth, cocos2d::CCPoint offset) -> decltype(createToggleValueControlAdvanced(property, label, position, vertical, page, group, buttonScale, labelScale, labelWidth, offset)) {
	using FunctionType = decltype(createToggleValueControlAdvanced(property, label, position, vertical, page, group, buttonScale, labelScale, labelWidth, offset))(*)(SetupTriggerPopup*, int, gd::string, cocos2d::CCPoint, bool, int, int, float, float, float, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e3150, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, property, label, position, vertical, page, group, buttonScale, labelScale, labelWidth, offset);
}

auto SetupTriggerPopup::createValueControl(int property, gd::string label, cocos2d::CCPoint position, float scale, float sliderMin, float sliderMax) -> decltype(createValueControl(property, label, position, scale, sliderMin, sliderMax)) {
	using FunctionType = decltype(createValueControl(property, label, position, scale, sliderMin, sliderMax))(*)(SetupTriggerPopup*, int, gd::string, cocos2d::CCPoint, float, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e1e6c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, property, label, position, scale, sliderMin, sliderMax);
}

auto SetupTriggerPopup::createValueControlAdvanced(int property, gd::string label, cocos2d::CCPoint position, float scale, bool noSlider, InputValueType valueType, int length, bool arrows, float sliderMin, float sliderMax, int page, int group, GJInputStyle inputStyle, int decimalPlaces, bool allowDisable) -> decltype(createValueControlAdvanced(property, label, position, scale, noSlider, valueType, length, arrows, sliderMin, sliderMax, page, group, inputStyle, decimalPlaces, allowDisable)) {
	using FunctionType = decltype(createValueControlAdvanced(property, label, position, scale, noSlider, valueType, length, arrows, sliderMin, sliderMax, page, group, inputStyle, decimalPlaces, allowDisable))(*)(SetupTriggerPopup*, int, gd::string, cocos2d::CCPoint, float, bool, InputValueType, int, bool, float, float, int, int, GJInputStyle, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e1f58, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, property, label, position, scale, noSlider, valueType, length, arrows, sliderMin, sliderMax, page, group, inputStyle, decimalPlaces, allowDisable);
}

auto SetupTriggerPopup::createValueControlWArrows(int property, gd::string label, cocos2d::CCPoint position, float scale) -> decltype(createValueControlWArrows(property, label, position, scale)) {
	using FunctionType = decltype(createValueControlWArrows(property, label, position, scale))(*)(SetupTriggerPopup*, int, gd::string, cocos2d::CCPoint, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e2b0c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, property, label, position, scale);
}

auto SetupTriggerPopup::getGroupContainer(int group) -> decltype(getGroupContainer(group)) {
	using FunctionType = decltype(getGroupContainer(group))(*)(SetupTriggerPopup*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1df2b8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, group);
}

auto SetupTriggerPopup::getMaxSliderValue(int property) -> decltype(getMaxSliderValue(property)) {
	using FunctionType = decltype(getMaxSliderValue(property))(*)(SetupTriggerPopup*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e5bcc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, property);
}

auto SetupTriggerPopup::getMinSliderValue(int property) -> decltype(getMinSliderValue(property)) {
	using FunctionType = decltype(getMinSliderValue(property))(*)(SetupTriggerPopup*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e5b9c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, property);
}

auto SetupTriggerPopup::getObjects() -> decltype(getObjects()) {
	using FunctionType = decltype(getObjects())(*)(SetupTriggerPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e0320, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupTriggerPopup::getPageContainer(int page) -> decltype(getPageContainer(page)) {
	using FunctionType = decltype(getPageContainer(page))(*)(SetupTriggerPopup*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1df138, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, page);
}

auto SetupTriggerPopup::getTriggerValue(int property, GameObject* object) -> decltype(getTriggerValue(property, object)) {
	using FunctionType = decltype(getTriggerValue(property, object))(*)(SetupTriggerPopup*, int, GameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e423c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, property, object);
}

auto SetupTriggerPopup::getTruncatedValue(float value, int decimals) -> decltype(getTruncatedValue(value, decimals)) {
	using FunctionType = decltype(getTruncatedValue(value, decimals))(*)(SetupTriggerPopup*, float, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e0824, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, value, decimals);
}

auto SetupTriggerPopup::getTruncatedValueByTag(int tag, float value) -> decltype(getTruncatedValueByTag(tag, value)) {
	using FunctionType = decltype(getTruncatedValueByTag(tag, value))(*)(SetupTriggerPopup*, int, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e1b40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, tag, value);
}

auto SetupTriggerPopup::goToPage(int page, bool hideAll) -> decltype(goToPage(page, hideAll)) {
	using FunctionType = decltype(goToPage(page, hideAll))(*)(SetupTriggerPopup*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1def88, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, page, hideAll);
}

auto SetupTriggerPopup::hideAll() -> decltype(hideAll()) {
	using FunctionType = decltype(hideAll())(*)(SetupTriggerPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1df19c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupTriggerPopup::init(EffectGameObject* trigger, cocos2d::CCArray* triggers, float width, float height, int background) -> decltype(init(trigger, triggers, width, height, background)) {
	using FunctionType = decltype(init(trigger, triggers, width, height, background))(*)(SetupTriggerPopup*, EffectGameObject*, cocos2d::CCArray*, float, float, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1de8f4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, trigger, triggers, width, height, background);
}

auto SetupTriggerPopup::onCustomEaseArrow(int property, bool up) -> decltype(onCustomEaseArrow(property, up)) {
	using FunctionType = decltype(onCustomEaseArrow(property, up))(*)(SetupTriggerPopup*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e781c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, property, up);
}

auto SetupTriggerPopup::onCustomEaseArrowDown(cocos2d::CCObject* sender) -> decltype(onCustomEaseArrowDown(sender)) {
	using FunctionType = decltype(onCustomEaseArrowDown(sender))(*)(SetupTriggerPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e74ec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupTriggerPopup::onCustomEaseArrowUp(cocos2d::CCObject* sender) -> decltype(onCustomEaseArrowUp(sender)) {
	using FunctionType = decltype(onCustomEaseArrowUp(sender))(*)(SetupTriggerPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e7438, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupTriggerPopup::onCustomEaseRate(cocos2d::CCObject* sender) -> decltype(onCustomEaseRate(sender)) {
	using FunctionType = decltype(onCustomEaseRate(sender))(*)(SetupTriggerPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e72f8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupTriggerPopup::onDisableValue(cocos2d::CCObject* sender) -> decltype(onDisableValue(sender)) {
	using FunctionType = decltype(onDisableValue(sender))(*)(SetupTriggerPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e2d00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupTriggerPopup::onEase(cocos2d::CCObject* sender) -> decltype(onEase(sender)) {
	using FunctionType = decltype(onEase(sender))(*)(SetupTriggerPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e6570, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupTriggerPopup::onEaseRate(cocos2d::CCObject* sender) -> decltype(onEaseRate(sender)) {
	using FunctionType = decltype(onEaseRate(sender))(*)(SetupTriggerPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e6468, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupTriggerPopup::onMultiTrigger(cocos2d::CCObject* sender) -> decltype(onMultiTrigger(sender)) {
	using FunctionType = decltype(onMultiTrigger(sender))(*)(SetupTriggerPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e0230, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupTriggerPopup::onPage(cocos2d::CCObject* sender) -> decltype(onPage(sender)) {
	using FunctionType = decltype(onPage(sender))(*)(SetupTriggerPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1dee9c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupTriggerPopup::onSpawnedByTrigger(cocos2d::CCObject* sender) -> decltype(onSpawnedByTrigger(sender)) {
	using FunctionType = decltype(onSpawnedByTrigger(sender))(*)(SetupTriggerPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e01e8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupTriggerPopup::onToggleTriggerValue(cocos2d::CCObject* sender) -> decltype(onToggleTriggerValue(sender)) {
	using FunctionType = decltype(onToggleTriggerValue(sender))(*)(SetupTriggerPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e3374, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupTriggerPopup::onTouchTriggered(cocos2d::CCObject* sender) -> decltype(onTouchTriggered(sender)) {
	using FunctionType = decltype(onTouchTriggered(sender))(*)(SetupTriggerPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e01a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupTriggerPopup::postSetup() -> decltype(postSetup()) {
	using FunctionType = decltype(postSetup())(*)(SetupTriggerPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e3e8c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupTriggerPopup::preSetup() -> decltype(preSetup()) {
	using FunctionType = decltype(preSetup())(*)(SetupTriggerPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e3e78, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupTriggerPopup::refreshGroupVisibility() -> decltype(refreshGroupVisibility()) {
	using FunctionType = decltype(refreshGroupVisibility())(*)(SetupTriggerPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1df1a8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupTriggerPopup::removeObjectFromGroup(cocos2d::CCObject* object, int group) -> decltype(removeObjectFromGroup(object, group)) {
	using FunctionType = decltype(removeObjectFromGroup(object, group))(*)(SetupTriggerPopup*, cocos2d::CCObject*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1df680, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, group);
}

auto SetupTriggerPopup::removeObjectFromPage(cocos2d::CCObject* object, int page) -> decltype(removeObjectFromPage(object, page)) {
	using FunctionType = decltype(removeObjectFromPage(object, page))(*)(SetupTriggerPopup*, cocos2d::CCObject*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1df52c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, page);
}

auto SetupTriggerPopup::resetDisabledValues() -> decltype(resetDisabledValues()) {
	using FunctionType = decltype(resetDisabledValues())(*)(SetupTriggerPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e2e00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupTriggerPopup::setMaxSliderValue(float value, int property) -> decltype(setMaxSliderValue(value, property)) {
	using FunctionType = decltype(setMaxSliderValue(value, property))(*)(SetupTriggerPopup*, float, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e2c80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, value, property);
}

auto SetupTriggerPopup::setMinSliderValue(float value, int property) -> decltype(setMinSliderValue(value, property)) {
	using FunctionType = decltype(setMinSliderValue(value, property))(*)(SetupTriggerPopup*, float, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e2c00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, value, property);
}

auto SetupTriggerPopup::shouldLimitValue(int property) -> decltype(shouldLimitValue(property)) {
	using FunctionType = decltype(shouldLimitValue(property))(*)(SetupTriggerPopup*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e595c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, property);
}

auto SetupTriggerPopup::toggleBG(bool visible) -> decltype(toggleBG(visible)) {
	using FunctionType = decltype(toggleBG(visible))(*)(SetupTriggerPopup*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1deb9c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, visible);
}

auto SetupTriggerPopup::toggleCustomEaseRateVisibility(int property, int tag) -> decltype(toggleCustomEaseRateVisibility(property, tag)) {
	using FunctionType = decltype(toggleCustomEaseRateVisibility(property, tag))(*)(SetupTriggerPopup*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e76e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, property, tag);
}

auto SetupTriggerPopup::toggleDisableButtons(bool visible) -> decltype(toggleDisableButtons(visible)) {
	using FunctionType = decltype(toggleDisableButtons(visible))(*)(SetupTriggerPopup*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e2ee4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, visible);
}

auto SetupTriggerPopup::toggleEaseRateVisibility() -> decltype(toggleEaseRateVisibility()) {
	using FunctionType = decltype(toggleEaseRateVisibility())(*)(SetupTriggerPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e6828, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupTriggerPopup::toggleLimitValue(int property, bool limit) -> decltype(toggleLimitValue(property, limit)) {
	using FunctionType = decltype(toggleLimitValue(property, limit))(*)(SetupTriggerPopup*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e5ad8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, property, limit);
}

auto SetupTriggerPopup::togglePageArrows(bool visible) -> decltype(togglePageArrows(visible)) {
	using FunctionType = decltype(togglePageArrows(visible))(*)(SetupTriggerPopup*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1def10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, visible);
}

auto SetupTriggerPopup::triggerArrowChanged(int property, bool isRight) -> decltype(triggerArrowChanged(property, isRight)) {
	using FunctionType = decltype(triggerArrowChanged(property, isRight))(*)(SetupTriggerPopup*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e1c4c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, property, isRight);
}

auto SetupTriggerPopup::triggerArrowLeft(cocos2d::CCObject* sender) -> decltype(triggerArrowLeft(sender)) {
	using FunctionType = decltype(triggerArrowLeft(sender))(*)(SetupTriggerPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e1bb4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupTriggerPopup::triggerArrowRight(cocos2d::CCObject* sender) -> decltype(triggerArrowRight(sender)) {
	using FunctionType = decltype(triggerArrowRight(sender))(*)(SetupTriggerPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e1ce0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupTriggerPopup::triggerSliderChanged(cocos2d::CCObject* sender) -> decltype(triggerSliderChanged(sender)) {
	using FunctionType = decltype(triggerSliderChanged(sender))(*)(SetupTriggerPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e1a5c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupTriggerPopup::updateCustomEaseLabel(int property, int easingType) -> decltype(updateCustomEaseLabel(property, easingType)) {
	using FunctionType = decltype(updateCustomEaseLabel(property, easingType))(*)(SetupTriggerPopup*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e75a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, property, easingType);
}

auto SetupTriggerPopup::updateCustomEaseRateLabel(int property, float easingRate) -> decltype(updateCustomEaseRateLabel(property, easingRate)) {
	using FunctionType = decltype(updateCustomEaseRateLabel(property, easingRate))(*)(SetupTriggerPopup*, int, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e698c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, property, easingRate);
}

auto SetupTriggerPopup::updateCustomToggleTrigger(int tag, bool toggled) -> decltype(updateCustomToggleTrigger(tag, toggled)) {
	using FunctionType = decltype(updateCustomToggleTrigger(tag, toggled))(*)(SetupTriggerPopup*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e3644, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, tag, toggled);
}

auto SetupTriggerPopup::updateEaseLabel() -> decltype(updateEaseLabel()) {
	using FunctionType = decltype(updateEaseLabel())(*)(SetupTriggerPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e65dc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupTriggerPopup::updateEaseRateLabel() -> decltype(updateEaseRateLabel()) {
	using FunctionType = decltype(updateEaseRateLabel())(*)(SetupTriggerPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e66d8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupTriggerPopup::updateEditorLabel() -> decltype(updateEditorLabel()) {
	using FunctionType = decltype(updateEditorLabel())(*)(SetupTriggerPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e0464, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupTriggerPopup::updateInputNodeLabel(int property, gd::string text) -> decltype(updateInputNodeLabel(property, text)) {
	using FunctionType = decltype(updateInputNodeLabel(property, text))(*)(SetupTriggerPopup*, int, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e5a1c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, property, text);
}

auto SetupTriggerPopup::updateLabel(int property, gd::string text) -> decltype(updateLabel(property, text)) {
	using FunctionType = decltype(updateLabel(property, text))(*)(SetupTriggerPopup*, int, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e3680, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, property, text);
}

auto SetupTriggerPopup::updateMultiTriggerBtn() -> decltype(updateMultiTriggerBtn()) {
	using FunctionType = decltype(updateMultiTriggerBtn())(*)(SetupTriggerPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e02a8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupTriggerPopup::updateSlider(int property) -> decltype(updateSlider(property)) {
	using FunctionType = decltype(updateSlider(property))(*)(SetupTriggerPopup*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e5728, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, property);
}

auto SetupTriggerPopup::updateSlider(int property, float value) -> decltype(updateSlider(property, value)) {
	using FunctionType = decltype(updateSlider(property, value))(*)(SetupTriggerPopup*, int, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e1548, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, property, value);
}

auto SetupTriggerPopup::updateSpawnedByTrigger() -> decltype(updateSpawnedByTrigger()) {
	using FunctionType = decltype(updateSpawnedByTrigger())(*)(SetupTriggerPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e04dc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupTriggerPopup::updateTouchTriggered() -> decltype(updateTouchTriggered()) {
	using FunctionType = decltype(updateTouchTriggered())(*)(SetupTriggerPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e05a4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupTriggerPopup::updateValue(int property, float value) -> decltype(updateValue(property, value)) {
	using FunctionType = decltype(updateValue(property, value))(*)(SetupTriggerPopup*, int, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e2d88, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, property, value);
}

auto SetupTriggerPopup::updateValueControls(int property, float value) -> decltype(updateValueControls(property, value)) {
	using FunctionType = decltype(updateValueControls(property, value))(*)(SetupTriggerPopup*, int, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e1d78, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, property, value);
}

auto SetupTriggerPopup::valueChanged(int property, float value) -> decltype(valueChanged(property, value)) {
	using FunctionType = decltype(valueChanged(property, value))(*)(SetupTriggerPopup*, int, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1e0880, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, property, value);
}
