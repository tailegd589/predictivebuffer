
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/EditorPauseLayer.hpp>
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

auto EditorPauseLayer::create(LevelEditorLayer* layer) -> decltype(create(layer)) {
	using FunctionType = decltype(create(layer))(*)(LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2910a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(layer);
}

auto EditorPauseLayer::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&EditorPauseLayer::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(EditorPauseLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x294f30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto EditorPauseLayer::keyDown(cocos2d::enumKeyCodes key, double timestamp) -> decltype(keyDown(key, timestamp)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::enumKeyCodes, double>::func(&EditorPauseLayer::keyDown), this);
	using FunctionType = decltype(keyDown(key, timestamp))(*)(EditorPauseLayer*, cocos2d::enumKeyCodes, double);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x295020, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, key, timestamp);
}

auto EditorPauseLayer::customSetup() -> decltype(customSetup()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&EditorPauseLayer::customSetup), this);
	using FunctionType = decltype(customSetup())(*)(EditorPauseLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2919f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto EditorPauseLayer::FLAlert_Clicked(FLAlertLayer* layer, bool btn2) -> decltype(FLAlert_Clicked(layer, btn2)) {
	auto self = addresser::thunkAdjust(Resolve<FLAlertLayer*, bool>::func(&EditorPauseLayer::FLAlert_Clicked), this);
	using FunctionType = decltype(FLAlert_Clicked(layer, btn2))(*)(EditorPauseLayer*, FLAlertLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x294e50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, layer, btn2);
}

auto EditorPauseLayer::doResetUnused() -> decltype(doResetUnused()) {
	using FunctionType = decltype(doResetUnused())(*)(EditorPauseLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x294230, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto EditorPauseLayer::init(LevelEditorLayer* layer) -> decltype(init(layer)) {
	using FunctionType = decltype(init(layer))(*)(EditorPauseLayer*, LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2911a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, layer);
}

auto EditorPauseLayer::onAlignX(cocos2d::CCObject* sender) -> decltype(onAlignX(sender)) {
	using FunctionType = decltype(onAlignX(sender))(*)(EditorPauseLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x293f00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EditorPauseLayer::onAlignY(cocos2d::CCObject* sender) -> decltype(onAlignY(sender)) {
	using FunctionType = decltype(onAlignY(sender))(*)(EditorPauseLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x293f30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EditorPauseLayer::onBuildHelper(cocos2d::CCObject* sender) -> decltype(onBuildHelper(sender)) {
	using FunctionType = decltype(onBuildHelper(sender))(*)(EditorPauseLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x293ea0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EditorPauseLayer::onCopyWColor(cocos2d::CCObject* sender) -> decltype(onCopyWColor(sender)) {
	using FunctionType = decltype(onCopyWColor(sender))(*)(EditorPauseLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x293e80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EditorPauseLayer::onCreateExtras(cocos2d::CCObject* sender) -> decltype(onCreateExtras(sender)) {
	using FunctionType = decltype(onCreateExtras(sender))(*)(EditorPauseLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x293e30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EditorPauseLayer::onCreateLoop(cocos2d::CCObject* sender) -> decltype(onCreateLoop(sender)) {
	using FunctionType = decltype(onCreateLoop(sender))(*)(EditorPauseLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x293ec0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EditorPauseLayer::onCreateTemplate(cocos2d::CCObject* sender) -> decltype(onCreateTemplate(sender)) {
	using FunctionType = decltype(onCreateTemplate(sender))(*)(EditorPauseLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x294250, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EditorPauseLayer::onExitEditor(cocos2d::CCObject* sender) -> decltype(onExitEditor(sender)) {
	using FunctionType = decltype(onExitEditor(sender))(*)(EditorPauseLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x294e10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EditorPauseLayer::onExitNoSave(cocos2d::CCObject* sender) -> decltype(onExitNoSave(sender)) {
	using FunctionType = decltype(onExitNoSave(sender))(*)(EditorPauseLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2939b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EditorPauseLayer::onHelp(cocos2d::CCObject* sender) -> decltype(onHelp(sender)) {
	using FunctionType = decltype(onHelp(sender))(*)(EditorPauseLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x293b90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EditorPauseLayer::onKeybindings(cocos2d::CCObject* sender) -> decltype(onKeybindings(sender)) {
	using FunctionType = decltype(onKeybindings(sender))(*)(EditorPauseLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2941f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EditorPauseLayer::onNewGroupX(cocos2d::CCObject* sender) -> decltype(onNewGroupX(sender)) {
	using FunctionType = decltype(onNewGroupX(sender))(*)(EditorPauseLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x293fd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EditorPauseLayer::onNewGroupY(cocos2d::CCObject* sender) -> decltype(onNewGroupY(sender)) {
	using FunctionType = decltype(onNewGroupY(sender))(*)(EditorPauseLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x293ff0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EditorPauseLayer::onOptions(cocos2d::CCObject* sender) -> decltype(onOptions(sender)) {
	using FunctionType = decltype(onOptions(sender))(*)(EditorPauseLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x294210, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EditorPauseLayer::onPasteWColor(cocos2d::CCObject* sender) -> decltype(onPasteWColor(sender)) {
	using FunctionType = decltype(onPasteWColor(sender))(*)(EditorPauseLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x293e60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EditorPauseLayer::onReGroup(cocos2d::CCObject* sender) -> decltype(onReGroup(sender)) {
	using FunctionType = decltype(onReGroup(sender))(*)(EditorPauseLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x293ee0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EditorPauseLayer::onResetUnusedColors(cocos2d::CCObject* sender) -> decltype(onResetUnusedColors(sender)) {
	using FunctionType = decltype(onResetUnusedColors(sender))(*)(EditorPauseLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x293d10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EditorPauseLayer::onResume(cocos2d::CCObject* sender) -> decltype(onResume(sender)) {
	using FunctionType = decltype(onResume(sender))(*)(EditorPauseLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x293790, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EditorPauseLayer::onSave(cocos2d::CCObject* sender) -> decltype(onSave(sender)) {
	using FunctionType = decltype(onSave(sender))(*)(EditorPauseLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2938e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EditorPauseLayer::onSaveAndExit(cocos2d::CCObject* sender) -> decltype(onSaveAndExit(sender)) {
	using FunctionType = decltype(onSaveAndExit(sender))(*)(EditorPauseLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x293870, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EditorPauseLayer::onSaveAndPlay(cocos2d::CCObject* sender) -> decltype(onSaveAndPlay(sender)) {
	using FunctionType = decltype(onSaveAndPlay(sender))(*)(EditorPauseLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x293800, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EditorPauseLayer::onSelectAll(cocos2d::CCObject* sender) -> decltype(onSelectAll(sender)) {
	using FunctionType = decltype(onSelectAll(sender))(*)(EditorPauseLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x293f70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EditorPauseLayer::onSelectAllLeft(cocos2d::CCObject* sender) -> decltype(onSelectAllLeft(sender)) {
	using FunctionType = decltype(onSelectAllLeft(sender))(*)(EditorPauseLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x293f90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EditorPauseLayer::onSelectAllRight(cocos2d::CCObject* sender) -> decltype(onSelectAllRight(sender)) {
	using FunctionType = decltype(onSelectAllRight(sender))(*)(EditorPauseLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x293fb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EditorPauseLayer::onSong(cocos2d::CCObject* sender) -> decltype(onSong(sender)) {
	using FunctionType = decltype(onSong(sender))(*)(EditorPauseLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x293b00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EditorPauseLayer::onUnlockAllLayers(cocos2d::CCObject* sender) -> decltype(onUnlockAllLayers(sender)) {
	using FunctionType = decltype(onUnlockAllLayers(sender))(*)(EditorPauseLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x293e10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EditorPauseLayer::playStep2() -> decltype(playStep2()) {
	using FunctionType = decltype(playStep2())(*)(EditorPauseLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x294ce0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto EditorPauseLayer::playStep3() -> decltype(playStep3()) {
	using FunctionType = decltype(playStep3())(*)(EditorPauseLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x294db0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto EditorPauseLayer::saveLevel() -> decltype(saveLevel()) {
	using FunctionType = decltype(saveLevel())(*)(EditorPauseLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x294850, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto EditorPauseLayer::toggleDebugDraw(cocos2d::CCObject* sender) -> decltype(toggleDebugDraw(sender)) {
	using FunctionType = decltype(toggleDebugDraw(sender))(*)(EditorPauseLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2941d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EditorPauseLayer::toggleEditorBackground(cocos2d::CCObject* sender) -> decltype(toggleEditorBackground(sender)) {
	using FunctionType = decltype(toggleEditorBackground(sender))(*)(EditorPauseLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x294760, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EditorPauseLayer::toggleEditorColorMode(cocos2d::CCObject* sender) -> decltype(toggleEditorColorMode(sender)) {
	using FunctionType = decltype(toggleEditorColorMode(sender))(*)(EditorPauseLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x294180, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EditorPauseLayer::toggleEditorGrid(cocos2d::CCObject* sender) -> decltype(toggleEditorGrid(sender)) {
	using FunctionType = decltype(toggleEditorGrid(sender))(*)(EditorPauseLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x294050, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EditorPauseLayer::toggleEditorGround(cocos2d::CCObject* sender) -> decltype(toggleEditorGround(sender)) {
	using FunctionType = decltype(toggleEditorGround(sender))(*)(EditorPauseLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2940b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EditorPauseLayer::toggleEffectDuration(cocos2d::CCObject* sender) -> decltype(toggleEffectDuration(sender)) {
	using FunctionType = decltype(toggleEffectDuration(sender))(*)(EditorPauseLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x294720, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EditorPauseLayer::toggleEffectLines(cocos2d::CCObject* sender) -> decltype(toggleEffectLines(sender)) {
	using FunctionType = decltype(toggleEffectLines(sender))(*)(EditorPauseLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x294740, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EditorPauseLayer::toggleFollowPlayer(cocos2d::CCObject* sender) -> decltype(toggleFollowPlayer(sender)) {
	using FunctionType = decltype(toggleFollowPlayer(sender))(*)(EditorPauseLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2946e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EditorPauseLayer::toggleGridOnTop(cocos2d::CCObject* sender) -> decltype(toggleGridOnTop(sender)) {
	using FunctionType = decltype(toggleGridOnTop(sender))(*)(EditorPauseLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2947b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EditorPauseLayer::toggleHideInvisible(cocos2d::CCObject* sender) -> decltype(toggleHideInvisible(sender)) {
	using FunctionType = decltype(toggleHideInvisible(sender))(*)(EditorPauseLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2941b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EditorPauseLayer::toggleIgnoreDamage(cocos2d::CCObject* sender) -> decltype(toggleIgnoreDamage(sender)) {
	using FunctionType = decltype(toggleIgnoreDamage(sender))(*)(EditorPauseLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x294010, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EditorPauseLayer::togglePlaytestMusic(cocos2d::CCObject* sender) -> decltype(togglePlaytestMusic(sender)) {
	using FunctionType = decltype(togglePlaytestMusic(sender))(*)(EditorPauseLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x294700, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EditorPauseLayer::togglePreviewAnim(cocos2d::CCObject* sender) -> decltype(togglePreviewAnim(sender)) {
	using FunctionType = decltype(togglePreviewAnim(sender))(*)(EditorPauseLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x294150, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EditorPauseLayer::togglePreviewParticles(cocos2d::CCObject* sender) -> decltype(togglePreviewParticles(sender)) {
	using FunctionType = decltype(togglePreviewParticles(sender))(*)(EditorPauseLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x294120, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EditorPauseLayer::togglePreviewShaders(cocos2d::CCObject* sender) -> decltype(togglePreviewShaders(sender)) {
	using FunctionType = decltype(togglePreviewShaders(sender))(*)(EditorPauseLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x294100, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EditorPauseLayer::toggleRecordOrder(cocos2d::CCObject* sender) -> decltype(toggleRecordOrder(sender)) {
	using FunctionType = decltype(toggleRecordOrder(sender))(*)(EditorPauseLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x294830, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EditorPauseLayer::toggleSelectFilter(cocos2d::CCObject* sender) -> decltype(toggleSelectFilter(sender)) {
	using FunctionType = decltype(toggleSelectFilter(sender))(*)(EditorPauseLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x294030, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EditorPauseLayer::toggleShowObjectInfo(cocos2d::CCObject* sender) -> decltype(toggleShowObjectInfo(sender)) {
	using FunctionType = decltype(toggleShowObjectInfo(sender))(*)(EditorPauseLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x294070, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EditorPauseLayer::uncheckAllPortals(cocos2d::CCObject* sender) -> decltype(uncheckAllPortals(sender)) {
	using FunctionType = decltype(uncheckAllPortals(sender))(*)(EditorPauseLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x293c30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto EditorPauseLayer::updateSongButton() -> decltype(updateSongButton()) {
	using FunctionType = decltype(updateSongButton())(*)(EditorPauseLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x293bb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
