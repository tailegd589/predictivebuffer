
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/UILayer.hpp>
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

UILayer::~UILayer() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(UILayer*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x429614, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) UILayer(geode::CutoffConstructor, sizeof(UILayer));
		geode::DestructorLock::addLock(this);
	}
}

auto UILayer::create(GJBaseGameLayer* layer) -> decltype(create(layer)) {
	using FunctionType = decltype(create(layer))(*)(GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x426c64, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(layer);
}

auto UILayer::draw() -> decltype(draw()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&UILayer::draw), this);
	using FunctionType = decltype(draw())(*)(UILayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4287fc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto UILayer::ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchBegan(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&UILayer::ccTouchBegan), this);
	using FunctionType = decltype(ccTouchBegan(touch, event))(*)(UILayer*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42889c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto UILayer::ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchMoved(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&UILayer::ccTouchMoved), this);
	using FunctionType = decltype(ccTouchMoved(touch, event))(*)(UILayer*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x428b20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto UILayer::ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchEnded(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&UILayer::ccTouchEnded), this);
	using FunctionType = decltype(ccTouchEnded(touch, event))(*)(UILayer*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x428c74, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto UILayer::ccTouchCancelled(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) -> decltype(ccTouchCancelled(touch, event)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouch*, cocos2d::CCEvent*>::func(&UILayer::ccTouchCancelled), this);
	using FunctionType = decltype(ccTouchCancelled(touch, event))(*)(UILayer*, cocos2d::CCTouch*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4295c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, touch, event);
}

auto UILayer::registerWithTouchDispatcher() -> decltype(registerWithTouchDispatcher()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&UILayer::registerWithTouchDispatcher), this);
	using FunctionType = decltype(registerWithTouchDispatcher())(*)(UILayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4295dc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto UILayer::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&UILayer::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(UILayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4283e4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto UILayer::keyDown(cocos2d::enumKeyCodes key, double timestamp) -> decltype(keyDown(key, timestamp)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::enumKeyCodes, double>::func(&UILayer::keyDown), this);
	using FunctionType = decltype(keyDown(key, timestamp))(*)(UILayer*, cocos2d::enumKeyCodes, double);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4283a4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, key, timestamp);
}

auto UILayer::keyUp(cocos2d::enumKeyCodes key, double timestamp) -> decltype(keyUp(key, timestamp)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::enumKeyCodes, double>::func(&UILayer::keyUp), this);
	using FunctionType = decltype(keyUp(key, timestamp))(*)(UILayer*, cocos2d::enumKeyCodes, double);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4283c4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, key, timestamp);
}

auto UILayer::disableMenu() -> decltype(disableMenu()) {
	using FunctionType = decltype(disableMenu())(*)(UILayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x427f00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto UILayer::doPause() -> decltype(doPause()) {
	using FunctionType = decltype(doPause())(*)(UILayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4284a4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto UILayer::editorPlaytest(bool visible) -> decltype(editorPlaytest(visible)) {
	using FunctionType = decltype(editorPlaytest(visible))(*)(UILayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x427f14, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, visible);
}

auto UILayer::enableEditorMode() -> decltype(enableEditorMode()) {
	using FunctionType = decltype(enableEditorMode())(*)(UILayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x427dc4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto UILayer::enableMenu() -> decltype(enableMenu()) {
	using FunctionType = decltype(enableMenu())(*)(UILayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4285ac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto UILayer::handleKeypress(cocos2d::enumKeyCodes key, bool down, double timestamp) -> decltype(handleKeypress(key, down, timestamp)) {
	using FunctionType = decltype(handleKeypress(key, down, timestamp))(*)(UILayer*, cocos2d::enumKeyCodes, bool, double);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x428024, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key, down, timestamp);
}

auto UILayer::init(GJBaseGameLayer* layer) -> decltype(init(layer)) {
	using FunctionType = decltype(init(layer))(*)(UILayer*, GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x426d68, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, layer);
}

auto UILayer::isJumpButtonPressed() -> decltype(isJumpButtonPressed()) {
	using FunctionType = decltype(isJumpButtonPressed())(*)(UILayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x428800, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto UILayer::isJumpButtonPressed(bool player1) -> decltype(isJumpButtonPressed(player1)) {
	using FunctionType = decltype(isJumpButtonPressed(player1))(*)(UILayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x428850, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, player1);
}

auto UILayer::onCheck(cocos2d::CCObject* sender) -> decltype(onCheck(sender)) {
	using FunctionType = decltype(onCheck(sender))(*)(UILayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42758c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto UILayer::onDeleteCheck(cocos2d::CCObject* sender) -> decltype(onDeleteCheck(sender)) {
	using FunctionType = decltype(onDeleteCheck(sender))(*)(UILayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4275e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto UILayer::onPause(cocos2d::CCObject* sender) -> decltype(onPause(sender)) {
	using FunctionType = decltype(onPause(sender))(*)(UILayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x427540, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto UILayer::processUINodesTouch(GJUITouchEvent event, cocos2d::CCTouch* touch) -> decltype(processUINodesTouch(event, touch)) {
	using FunctionType = decltype(processUINodesTouch(event, touch))(*)(UILayer*, GJUITouchEvent, cocos2d::CCTouch*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4289bc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, event, touch);
}

auto UILayer::processUINodeTouch(GJUITouchEvent event, int touchID, cocos2d::CCPoint position, GJUINode* node, double timestamp) -> decltype(processUINodeTouch(event, touchID, position, node, timestamp)) {
	using FunctionType = decltype(processUINodeTouch(event, touchID, position, node, timestamp))(*)(UILayer*, GJUITouchEvent, int, cocos2d::CCPoint, GJUINode*, double);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x428e60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, event, touchID, position, node, timestamp);
}

auto UILayer::refreshDpad() -> decltype(refreshDpad()) {
	using FunctionType = decltype(refreshDpad())(*)(UILayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x427924, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto UILayer::resetAllButtons() -> decltype(resetAllButtons()) {
	using FunctionType = decltype(resetAllButtons())(*)(UILayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42871c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto UILayer::resetUINodeState() -> decltype(resetUINodeState()) {
	using FunctionType = decltype(resetUINodeState())(*)(UILayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x427c68, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto UILayer::toggleCheckpointsMenu(bool visible) -> decltype(toggleCheckpointsMenu(visible)) {
	using FunctionType = decltype(toggleCheckpointsMenu(visible))(*)(UILayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x427628, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, visible);
}

auto UILayer::toggleMenuVisibility(bool visible) -> decltype(toggleMenuVisibility(visible)) {
	using FunctionType = decltype(toggleMenuVisibility(visible))(*)(UILayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4285c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, visible);
}

auto UILayer::togglePlatformerMode(bool platformer) -> decltype(togglePlatformerMode(platformer)) {
	using FunctionType = decltype(togglePlatformerMode(platformer))(*)(UILayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4277e8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, platformer);
}

auto UILayer::updateCheckState() -> decltype(updateCheckState()) {
	using FunctionType = decltype(updateCheckState())(*)(UILayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42766c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto UILayer::updateDualMode(bool dual) -> decltype(updateDualMode(dual)) {
	using FunctionType = decltype(updateDualMode(dual))(*)(UILayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42789c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dual);
}

auto UILayer::updateUINodeVisibility(bool visible) -> decltype(updateUINodeVisibility(visible)) {
	using FunctionType = decltype(updateUINodeVisibility(visible))(*)(UILayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x427ba0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, visible);
}
