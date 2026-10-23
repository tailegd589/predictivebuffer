
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/CustomSFXWidget.hpp>
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

auto CustomSFXWidget::create(SFXInfoObject* object, CustomSFXDelegate* delegate, bool showDelete, bool showPlay, bool showDownload, bool noBackground, bool compactMode) -> decltype(create(object, delegate, showDelete, showPlay, showDownload, noBackground, compactMode)) {
	using FunctionType = decltype(create(object, delegate, showDelete, showPlay, showDownload, noBackground, compactMode))(*)(SFXInfoObject*, CustomSFXDelegate*, bool, bool, bool, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5e2900, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(object, delegate, showDelete, showPlay, showDownload, noBackground, compactMode);
}

auto CustomSFXWidget::downloadSFXFinished(int id) -> decltype(downloadSFXFinished(id)) {
	auto self = addresser::thunkAdjust(Resolve<int>::func(&CustomSFXWidget::downloadSFXFinished), this);
	using FunctionType = decltype(downloadSFXFinished(id))(*)(CustomSFXWidget*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5e4b90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, id);
}

auto CustomSFXWidget::downloadSFXFailed(int id, GJSongError errorType) -> decltype(downloadSFXFailed(id, errorType)) {
	auto self = addresser::thunkAdjust(Resolve<int, GJSongError>::func(&CustomSFXWidget::downloadSFXFailed), this);
	using FunctionType = decltype(downloadSFXFailed(id, errorType))(*)(CustomSFXWidget*, int, GJSongError);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5e4c40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, id, errorType);
}

auto CustomSFXWidget::songStateChanged() -> decltype(songStateChanged()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CustomSFXWidget::songStateChanged), this);
	using FunctionType = decltype(songStateChanged())(*)(CustomSFXWidget*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5e4b20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CustomSFXWidget::FLAlert_Clicked(FLAlertLayer* layer, bool btn2) -> decltype(FLAlert_Clicked(layer, btn2)) {
	auto self = addresser::thunkAdjust(Resolve<FLAlertLayer*, bool>::func(&CustomSFXWidget::FLAlert_Clicked), this);
	using FunctionType = decltype(FLAlert_Clicked(layer, btn2))(*)(CustomSFXWidget*, FLAlertLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5e4e60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, layer, btn2);
}

auto CustomSFXWidget::deleteSFX() -> decltype(deleteSFX()) {
	using FunctionType = decltype(deleteSFX())(*)(CustomSFXWidget*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5e4660, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CustomSFXWidget::downloadFailed() -> decltype(downloadFailed()) {
	using FunctionType = decltype(downloadFailed())(*)(CustomSFXWidget*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5e4a70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CustomSFXWidget::hideLoadingArt() -> decltype(hideLoadingArt()) {
	using FunctionType = decltype(hideLoadingArt())(*)(CustomSFXWidget*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5e3e20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CustomSFXWidget::init(SFXInfoObject* object, CustomSFXDelegate* delegate, bool showDelete, bool showPlay, bool showDownload, bool noBackground, bool compactMode) -> decltype(init(object, delegate, showDelete, showPlay, showDownload, noBackground, compactMode)) {
	using FunctionType = decltype(init(object, delegate, showDelete, showPlay, showDownload, noBackground, compactMode))(*)(CustomSFXWidget*, SFXInfoObject*, CustomSFXDelegate*, bool, bool, bool, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5e2a20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, delegate, showDelete, showPlay, showDownload, noBackground, compactMode);
}

auto CustomSFXWidget::onCancelDownload(cocos2d::CCObject* sender) -> decltype(onCancelDownload(sender)) {
	using FunctionType = decltype(onCancelDownload(sender))(*)(CustomSFXWidget*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5e3ad0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto CustomSFXWidget::onDelete(cocos2d::CCObject* sender) -> decltype(onDelete(sender)) {
	using FunctionType = decltype(onDelete(sender))(*)(CustomSFXWidget*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5e3b10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto CustomSFXWidget::onDownload(cocos2d::CCObject* sender) -> decltype(onDownload(sender)) {
	using FunctionType = decltype(onDownload(sender))(*)(CustomSFXWidget*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5e3970, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto CustomSFXWidget::onPlayback(cocos2d::CCObject* sender) -> decltype(onPlayback(sender)) {
	using FunctionType = decltype(onPlayback(sender))(*)(CustomSFXWidget*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5e3c20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto CustomSFXWidget::onSelect(cocos2d::CCObject* sender) -> decltype(onSelect(sender)) {
	using FunctionType = decltype(onSelect(sender))(*)(CustomSFXWidget*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5e3bf0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto CustomSFXWidget::showLoadingArt() -> decltype(showLoadingArt()) {
	using FunctionType = decltype(showLoadingArt())(*)(CustomSFXWidget*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5e4760, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CustomSFXWidget::startDownload() -> decltype(startDownload()) {
	using FunctionType = decltype(startDownload())(*)(CustomSFXWidget*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5e48e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CustomSFXWidget::startMonitorDownload() -> decltype(startMonitorDownload()) {
	using FunctionType = decltype(startMonitorDownload())(*)(CustomSFXWidget*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5e45b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CustomSFXWidget::updateDownloadProgress(float dt) -> decltype(updateDownloadProgress(dt)) {
	using FunctionType = decltype(updateDownloadProgress(dt))(*)(CustomSFXWidget*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5e49a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt);
}

auto CustomSFXWidget::updateError(GJSongError errorType) -> decltype(updateError(errorType)) {
	using FunctionType = decltype(updateError(errorType))(*)(CustomSFXWidget*, GJSongError);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5e4d00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, errorType);
}

auto CustomSFXWidget::updateLengthMod(float mod) -> decltype(updateLengthMod(mod)) {
	using FunctionType = decltype(updateLengthMod(mod))(*)(CustomSFXWidget*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5e4b50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, mod);
}

auto CustomSFXWidget::updatePlaybackBtn() -> decltype(updatePlaybackBtn()) {
	using FunctionType = decltype(updatePlaybackBtn())(*)(CustomSFXWidget*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5e4650, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CustomSFXWidget::updateProgressBar(int progress) -> decltype(updateProgressBar(progress)) {
	using FunctionType = decltype(updateProgressBar(progress))(*)(CustomSFXWidget*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5e3da0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, progress);
}

auto CustomSFXWidget::updateSFXInfo() -> decltype(updateSFXInfo()) {
	using FunctionType = decltype(updateSFXInfo())(*)(CustomSFXWidget*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5e3f40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CustomSFXWidget::updateSFXObject(SFXInfoObject* object) -> decltype(updateSFXObject(object)) {
	using FunctionType = decltype(updateSFXObject(object))(*)(CustomSFXWidget*, SFXInfoObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5e3eb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto CustomSFXWidget::verifySFXID(int id) -> decltype(verifySFXID(id)) {
	using FunctionType = decltype(verifySFXID(id))(*)(CustomSFXWidget*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5e4b70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}
