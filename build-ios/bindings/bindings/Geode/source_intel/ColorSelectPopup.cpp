
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/ColorSelectPopup.hpp>
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

ColorSelectPopup::~ColorSelectPopup() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(ColorSelectPopup*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x7249b0, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) ColorSelectPopup(geode::CutoffConstructor, sizeof(ColorSelectPopup));
		geode::DestructorLock::addLock(this);
	}
}

auto ColorSelectPopup::colorToHex(cocos2d::ccColor3B color) -> decltype(colorToHex(color)) {
	using FunctionType = decltype(colorToHex(color))(*)(cocos2d::ccColor3B);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x729930, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(color);
}

auto ColorSelectPopup::create(ColorAction* action) -> decltype(create(action)) {
	using FunctionType = decltype(create(action))(*)(ColorAction*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x724e30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(action);
}

auto ColorSelectPopup::create(cocos2d::ccColor3B color) -> decltype(create(color)) {
	using FunctionType = decltype(create(color))(*)(cocos2d::ccColor3B);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x724e50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(color);
}

auto ColorSelectPopup::create(EffectGameObject* effect, cocos2d::CCArray* array) -> decltype(create(effect, array)) {
	using FunctionType = decltype(create(effect, array))(*)(EffectGameObject*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x724b40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(effect, array);
}

auto ColorSelectPopup::create(EffectGameObject* effect, cocos2d::CCArray* array, ColorAction* action) -> decltype(create(effect, array, action)) {
	using FunctionType = decltype(create(effect, array, action))(*)(EffectGameObject*, cocos2d::CCArray*, ColorAction*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x724b50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(effect, array, action);
}

auto ColorSelectPopup::hexToColor(gd::string hex) -> decltype(hexToColor(hex)) {
	using FunctionType = decltype(hexToColor(hex))(*)(gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x729e80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(hex);
}

auto ColorSelectPopup::show() -> decltype(show()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&ColorSelectPopup::show), this);
	using FunctionType = decltype(show())(*)(ColorSelectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x72ad50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto ColorSelectPopup::determineStartValues() -> decltype(determineStartValues()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&ColorSelectPopup::determineStartValues), this);
	using FunctionType = decltype(determineStartValues())(*)(ColorSelectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x728aa0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto ColorSelectPopup::textChanged(CCTextInputNode* node) -> decltype(textChanged(node)) {
	auto self = addresser::thunkAdjust(Resolve<CCTextInputNode*>::func(&ColorSelectPopup::textChanged), this);
	using FunctionType = decltype(textChanged(node))(*)(ColorSelectPopup*, CCTextInputNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x72ae40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, node);
}

auto ColorSelectPopup::colorValueChanged(cocos2d::ccColor3B color) -> decltype(colorValueChanged(color)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::ccColor3B>::func(&ColorSelectPopup::colorValueChanged), this);
	using FunctionType = decltype(colorValueChanged(color))(*)(ColorSelectPopup*, cocos2d::ccColor3B);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x729310, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, color);
}

auto ColorSelectPopup::colorSelectClosed(GJSpecialColorSelect* select, int id) -> decltype(colorSelectClosed(select, id)) {
	auto self = addresser::thunkAdjust(Resolve<GJSpecialColorSelect*, int>::func(&ColorSelectPopup::colorSelectClosed), this);
	using FunctionType = decltype(colorSelectClosed(select, id))(*)(ColorSelectPopup*, GJSpecialColorSelect*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x72b3e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, select, id);
}

auto ColorSelectPopup::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&ColorSelectPopup::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(ColorSelectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7292e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto ColorSelectPopup::closeColorSelect(cocos2d::CCObject* sender) -> decltype(closeColorSelect(sender)) {
	using FunctionType = decltype(closeColorSelect(sender))(*)(ColorSelectPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x727570, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto ColorSelectPopup::getColorValue() -> decltype(getColorValue()) {
	using FunctionType = decltype(getColorValue())(*)(ColorSelectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7290b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto ColorSelectPopup::init(EffectGameObject* object, cocos2d::CCArray* objects, ColorAction* action) -> decltype(init(object, objects, action)) {
	using FunctionType = decltype(init(object, objects, action))(*)(ColorSelectPopup*, EffectGameObject*, cocos2d::CCArray*, ColorAction*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x724e80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, objects, action);
}

auto ColorSelectPopup::onCopy(cocos2d::CCObject* sender) -> decltype(onCopy(sender)) {
	using FunctionType = decltype(onCopy(sender))(*)(ColorSelectPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x727b80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto ColorSelectPopup::onCopyOpacity(cocos2d::CCObject* sender) -> decltype(onCopyOpacity(sender)) {
	using FunctionType = decltype(onCopyOpacity(sender))(*)(ColorSelectPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7282c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto ColorSelectPopup::onDefault(cocos2d::CCObject* sender) -> decltype(onDefault(sender)) {
	using FunctionType = decltype(onDefault(sender))(*)(ColorSelectPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x727c00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto ColorSelectPopup::onHSVLegacyMode(cocos2d::CCObject* sender) -> decltype(onHSVLegacyMode(sender)) {
	using FunctionType = decltype(onHSVLegacyMode(sender))(*)(ColorSelectPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x728360, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto ColorSelectPopup::onPaste(cocos2d::CCObject* sender) -> decltype(onPaste(sender)) {
	using FunctionType = decltype(onPaste(sender))(*)(ColorSelectPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x727bc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto ColorSelectPopup::onPlayerColor1(cocos2d::CCObject* sender) -> decltype(onPlayerColor1(sender)) {
	using FunctionType = decltype(onPlayerColor1(sender))(*)(ColorSelectPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x727fc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto ColorSelectPopup::onPlayerColor2(cocos2d::CCObject* sender) -> decltype(onPlayerColor2(sender)) {
	using FunctionType = decltype(onPlayerColor2(sender))(*)(ColorSelectPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x728080, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto ColorSelectPopup::onSelectSpecialColor(cocos2d::CCObject* sender) -> decltype(onSelectSpecialColor(sender)) {
	using FunctionType = decltype(onSelectSpecialColor(sender))(*)(ColorSelectPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7283f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto ColorSelectPopup::onTintGround(cocos2d::CCObject* sender) -> decltype(onTintGround(sender)) {
	using FunctionType = decltype(onTintGround(sender))(*)(ColorSelectPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x728140, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto ColorSelectPopup::onToggleHSVMode(cocos2d::CCObject* sender) -> decltype(onToggleHSVMode(sender)) {
	using FunctionType = decltype(onToggleHSVMode(sender))(*)(ColorSelectPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x728280, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto ColorSelectPopup::onToggleTintMode(cocos2d::CCObject* sender) -> decltype(onToggleTintMode(sender)) {
	using FunctionType = decltype(onToggleTintMode(sender))(*)(ColorSelectPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7281d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto ColorSelectPopup::onUpdateCopyColor(cocos2d::CCObject* sender) -> decltype(onUpdateCopyColor(sender)) {
	using FunctionType = decltype(onUpdateCopyColor(sender))(*)(ColorSelectPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x728440, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto ColorSelectPopup::onUpdateCustomColor(cocos2d::CCObject* sender) -> decltype(onUpdateCustomColor(sender)) {
	using FunctionType = decltype(onUpdateCustomColor(sender))(*)(ColorSelectPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x728710, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto ColorSelectPopup::selectColor(cocos2d::ccColor3B color) -> decltype(selectColor(color)) {
	using FunctionType = decltype(selectColor(color))(*)(ColorSelectPopup*, cocos2d::ccColor3B);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x727af0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, color);
}

auto ColorSelectPopup::sliderChanged(cocos2d::CCObject* sender) -> decltype(sliderChanged(sender)) {
	using FunctionType = decltype(sliderChanged(sender))(*)(ColorSelectPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x727780, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto ColorSelectPopup::updateColorLabels() -> decltype(updateColorLabels()) {
	using FunctionType = decltype(updateColorLabels())(*)(ColorSelectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x729510, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto ColorSelectPopup::updateColorValue() -> decltype(updateColorValue()) {
	using FunctionType = decltype(updateColorValue())(*)(ColorSelectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x729440, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto ColorSelectPopup::updateCopyColor() -> decltype(updateCopyColor()) {
	using FunctionType = decltype(updateCopyColor())(*)(ColorSelectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x72b2e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto ColorSelectPopup::updateCopyColorTextInputLabel() -> decltype(updateCopyColorTextInputLabel()) {
	using FunctionType = decltype(updateCopyColorTextInputLabel())(*)(ColorSelectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7288b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto ColorSelectPopup::updateCustomColorIdx() -> decltype(updateCustomColorIdx()) {
	using FunctionType = decltype(updateCustomColorIdx())(*)(ColorSelectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x72adb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto ColorSelectPopup::updateDuration() -> decltype(updateDuration()) {
	using FunctionType = decltype(updateDuration())(*)(ColorSelectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x729180, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto ColorSelectPopup::updateDurLabel() -> decltype(updateDurLabel()) {
	using FunctionType = decltype(updateDurLabel())(*)(ColorSelectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7279a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto ColorSelectPopup::updateHSVMode() -> decltype(updateHSVMode()) {
	using FunctionType = decltype(updateHSVMode())(*)(ColorSelectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x728780, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto ColorSelectPopup::updateHSVValue() -> decltype(updateHSVValue()) {
	using FunctionType = decltype(updateHSVValue())(*)(ColorSelectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x729210, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto ColorSelectPopup::updateOpacity() -> decltype(updateOpacity()) {
	using FunctionType = decltype(updateOpacity())(*)(ColorSelectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7290d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto ColorSelectPopup::updateOpacityLabel() -> decltype(updateOpacityLabel()) {
	using FunctionType = decltype(updateOpacityLabel())(*)(ColorSelectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x727b20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto ColorSelectPopup::updateTextInputLabel() -> decltype(updateTextInputLabel()) {
	using FunctionType = decltype(updateTextInputLabel())(*)(ColorSelectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x728520, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
