
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/SetGroupIDLayer.hpp>
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

SetGroupIDLayer::~SetGroupIDLayer() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(SetGroupIDLayer*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x2a13e0, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) SetGroupIDLayer(geode::CutoffConstructor, sizeof(SetGroupIDLayer));
		geode::DestructorLock::addLock(this);
	}
}

auto SetGroupIDLayer::create(GameObject* object, cocos2d::CCArray* objects) -> decltype(create(object, objects)) {
	using FunctionType = decltype(create(object, objects))(*)(GameObject*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a14b8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(object, objects);
}

auto SetGroupIDLayer::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&SetGroupIDLayer::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(SetGroupIDLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a6748, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto SetGroupIDLayer::valuePopupClosed(ConfigureValuePopup* popup, float value) -> decltype(valuePopupClosed(popup, value)) {
	auto self = addresser::thunkAdjust(Resolve<ConfigureValuePopup*, float>::func(&SetGroupIDLayer::valuePopupClosed), this);
	using FunctionType = decltype(valuePopupClosed(popup, value))(*)(SetGroupIDLayer*, ConfigureValuePopup*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a6678, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, popup, value);
}

auto SetGroupIDLayer::textInputClosed(CCTextInputNode* node) -> decltype(textInputClosed(node)) {
	auto self = addresser::thunkAdjust(Resolve<CCTextInputNode*>::func(&SetGroupIDLayer::textInputClosed), this);
	using FunctionType = decltype(textInputClosed(node))(*)(SetGroupIDLayer*, CCTextInputNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a5fd4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, node);
}

auto SetGroupIDLayer::textChanged(CCTextInputNode* node) -> decltype(textChanged(node)) {
	auto self = addresser::thunkAdjust(Resolve<CCTextInputNode*>::func(&SetGroupIDLayer::textChanged), this);
	using FunctionType = decltype(textChanged(node))(*)(SetGroupIDLayer*, CCTextInputNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a5ff0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, node);
}

auto SetGroupIDLayer::addGroupID(int id) -> decltype(addGroupID(id)) {
	using FunctionType = decltype(addGroupID(id))(*)(SetGroupIDLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a658c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto SetGroupIDLayer::callRemoveFromGroup(float dt) -> decltype(callRemoveFromGroup(dt)) {
	using FunctionType = decltype(callRemoveFromGroup(dt))(*)(SetGroupIDLayer*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a6438, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt);
}

auto SetGroupIDLayer::createTextInput(cocos2d::CCPoint position, int tag, int length, gd::string placeholder, float width, int arrow) -> decltype(createTextInput(position, tag, length, placeholder, width, arrow)) {
	using FunctionType = decltype(createTextInput(position, tag, length, placeholder, width, arrow))(*)(SetGroupIDLayer*, cocos2d::CCPoint, int, int, gd::string, float, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a3c00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, position, tag, length, placeholder, width, arrow);
}

auto SetGroupIDLayer::determineStartValues() -> decltype(determineStartValues()) {
	using FunctionType = decltype(determineStartValues())(*)(SetGroupIDLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a433c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetGroupIDLayer::init(GameObject* obj, cocos2d::CCArray* objs) -> decltype(init(obj, objs)) {
	using FunctionType = decltype(init(obj, objs))(*)(SetGroupIDLayer*, GameObject*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a1628, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, obj, objs);
}

auto SetGroupIDLayer::onAddGroup(cocos2d::CCObject* sender) -> decltype(onAddGroup(sender)) {
	using FunctionType = decltype(onAddGroup(sender))(*)(SetGroupIDLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a41a8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetGroupIDLayer::onAddGroupParent(cocos2d::CCObject* sender) -> decltype(onAddGroupParent(sender)) {
	using FunctionType = decltype(onAddGroupParent(sender))(*)(SetGroupIDLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a41b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetGroupIDLayer::onAnim(cocos2d::CCObject* sender) -> decltype(onAnim(sender)) {
	using FunctionType = decltype(onAnim(sender))(*)(SetGroupIDLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a55a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetGroupIDLayer::onArrow(int tag, int increment) -> decltype(onArrow(tag, increment)) {
	using FunctionType = decltype(onArrow(tag, increment))(*)(SetGroupIDLayer*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a56f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, tag, increment);
}

auto SetGroupIDLayer::onArrowLeft(cocos2d::CCObject* sender) -> decltype(onArrowLeft(sender)) {
	using FunctionType = decltype(onArrowLeft(sender))(*)(SetGroupIDLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a5680, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetGroupIDLayer::onArrowRight(cocos2d::CCObject* sender) -> decltype(onArrowRight(sender)) {
	using FunctionType = decltype(onArrowRight(sender))(*)(SetGroupIDLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a56b8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetGroupIDLayer::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	using FunctionType = decltype(onClose(sender))(*)(SetGroupIDLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a3668, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetGroupIDLayer::onCopy(cocos2d::CCObject* sender) -> decltype(onCopy(sender)) {
	using FunctionType = decltype(onCopy(sender))(*)(SetGroupIDLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a5448, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetGroupIDLayer::onExtra(cocos2d::CCObject* sender) -> decltype(onExtra(sender)) {
	using FunctionType = decltype(onExtra(sender))(*)(SetGroupIDLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a5550, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetGroupIDLayer::onExtra2(cocos2d::CCObject* sender) -> decltype(onExtra2(sender)) {
	using FunctionType = decltype(onExtra2(sender))(*)(SetGroupIDLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a5578, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetGroupIDLayer::onGroupIDOptions(cocos2d::CCObject* sender) -> decltype(onGroupIDOptions(sender)) {
	using FunctionType = decltype(onGroupIDOptions(sender))(*)(SetGroupIDLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a3a24, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetGroupIDLayer::onNextFreeEditorLayer1(cocos2d::CCObject* sender) -> decltype(onNextFreeEditorLayer1(sender)) {
	using FunctionType = decltype(onNextFreeEditorLayer1(sender))(*)(SetGroupIDLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a384c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetGroupIDLayer::onNextFreeEditorLayer2(cocos2d::CCObject* sender) -> decltype(onNextFreeEditorLayer2(sender)) {
	using FunctionType = decltype(onNextFreeEditorLayer2(sender))(*)(SetGroupIDLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a3938, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetGroupIDLayer::onNextFreeOrderChannel(cocos2d::CCObject* sender) -> decltype(onNextFreeOrderChannel(sender)) {
	using FunctionType = decltype(onNextFreeOrderChannel(sender))(*)(SetGroupIDLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a4970, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetGroupIDLayer::onNextGroupID1(cocos2d::CCObject* sender) -> decltype(onNextGroupID1(sender)) {
	using FunctionType = decltype(onNextGroupID1(sender))(*)(SetGroupIDLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a411c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetGroupIDLayer::onPaste(cocos2d::CCObject* sender) -> decltype(onPaste(sender)) {
	using FunctionType = decltype(onPaste(sender))(*)(SetGroupIDLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a5470, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetGroupIDLayer::onRemoveFromGroup(cocos2d::CCObject* sender) -> decltype(onRemoveFromGroup(sender)) {
	using FunctionType = decltype(onRemoveFromGroup(sender))(*)(SetGroupIDLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a6378, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetGroupIDLayer::onSmoothEase(cocos2d::CCObject* sender) -> decltype(onSmoothEase(sender)) {
	using FunctionType = decltype(onSmoothEase(sender))(*)(SetGroupIDLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a6730, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetGroupIDLayer::onToggleGuide(cocos2d::CCObject* sender) -> decltype(onToggleGuide(sender)) {
	using FunctionType = decltype(onToggleGuide(sender))(*)(SetGroupIDLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a55d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetGroupIDLayer::onToggleSelectedOrder(cocos2d::CCObject* sender) -> decltype(onToggleSelectedOrder(sender)) {
	using FunctionType = decltype(onToggleSelectedOrder(sender))(*)(SetGroupIDLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a55fc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetGroupIDLayer::onToggleTraceIn(cocos2d::CCObject* sender) -> decltype(onToggleTraceIn(sender)) {
	using FunctionType = decltype(onToggleTraceIn(sender))(*)(SetGroupIDLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a5654, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetGroupIDLayer::onToggleTraceOut(cocos2d::CCObject* sender) -> decltype(onToggleTraceOut(sender)) {
	using FunctionType = decltype(onToggleTraceOut(sender))(*)(SetGroupIDLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a5628, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetGroupIDLayer::onZLayer(cocos2d::CCObject* sender) -> decltype(onZLayer(sender)) {
	using FunctionType = decltype(onZLayer(sender))(*)(SetGroupIDLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a4234, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetGroupIDLayer::onZLayerShift(cocos2d::CCObject* sender) -> decltype(onZLayerShift(sender)) {
	using FunctionType = decltype(onZLayerShift(sender))(*)(SetGroupIDLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a4624, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetGroupIDLayer::removeGroupID(int id) -> decltype(removeGroupID(id)) {
	using FunctionType = decltype(removeGroupID(id))(*)(SetGroupIDLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a64b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto SetGroupIDLayer::updateEditorLabel() -> decltype(updateEditorLabel()) {
	using FunctionType = decltype(updateEditorLabel())(*)(SetGroupIDLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a4bb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetGroupIDLayer::updateEditorLabel2() -> decltype(updateEditorLabel2()) {
	using FunctionType = decltype(updateEditorLabel2())(*)(SetGroupIDLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a4cd8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetGroupIDLayer::updateEditorLayerID() -> decltype(updateEditorLayerID()) {
	using FunctionType = decltype(updateEditorLayerID())(*)(SetGroupIDLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a5a50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetGroupIDLayer::updateEditorLayerID2() -> decltype(updateEditorLayerID2()) {
	using FunctionType = decltype(updateEditorLayerID2())(*)(SetGroupIDLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a5ac0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetGroupIDLayer::updateEditorOrder() -> decltype(updateEditorOrder()) {
	using FunctionType = decltype(updateEditorOrder())(*)(SetGroupIDLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a5b30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetGroupIDLayer::updateEditorOrderLabel() -> decltype(updateEditorOrderLabel()) {
	using FunctionType = decltype(updateEditorOrderLabel())(*)(SetGroupIDLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a46e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetGroupIDLayer::updateGroupIDButtons() -> decltype(updateGroupIDButtons()) {
	using FunctionType = decltype(updateGroupIDButtons())(*)(SetGroupIDLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a4fac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetGroupIDLayer::updateGroupIDLabel() -> decltype(updateGroupIDLabel()) {
	using FunctionType = decltype(updateGroupIDLabel())(*)(SetGroupIDLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a4a88, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetGroupIDLayer::updateOrderChannel() -> decltype(updateOrderChannel()) {
	using FunctionType = decltype(updateOrderChannel())(*)(SetGroupIDLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a5bd8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetGroupIDLayer::updateOrderChannelLabel() -> decltype(updateOrderChannelLabel()) {
	using FunctionType = decltype(updateOrderChannelLabel())(*)(SetGroupIDLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a4828, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetGroupIDLayer::updateZLayerButtons() -> decltype(updateZLayerButtons()) {
	using FunctionType = decltype(updateZLayerButtons())(*)(SetGroupIDLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a4f1c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetGroupIDLayer::updateZOrder() -> decltype(updateZOrder()) {
	using FunctionType = decltype(updateZOrder())(*)(SetGroupIDLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a5c80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetGroupIDLayer::updateZOrderLabel() -> decltype(updateZOrderLabel()) {
	using FunctionType = decltype(updateZOrderLabel())(*)(SetGroupIDLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a4e00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
