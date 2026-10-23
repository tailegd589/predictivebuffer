
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/CustomSongWidget.hpp>
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

CustomSongWidget::~CustomSongWidget() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(CustomSongWidget*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x61a640, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) CustomSongWidget(geode::CutoffConstructor, sizeof(CustomSongWidget));
		geode::DestructorLock::addLock(this);
	}
}

auto CustomSongWidget::create(SongInfoObject* songInfo, CustomSongDelegate* songDelegate, bool showSongSelect, bool showPlayMusic, bool showDownload, bool isRobtopSong, bool unkBool, bool isMusicLibrary, int unk) -> decltype(create(songInfo, songDelegate, showSongSelect, showPlayMusic, showDownload, isRobtopSong, unkBool, isMusicLibrary, unk)) {
	using FunctionType = decltype(create(songInfo, songDelegate, showSongSelect, showPlayMusic, showDownload, isRobtopSong, unkBool, isMusicLibrary, unk))(*)(SongInfoObject*, CustomSongDelegate*, bool, bool, bool, bool, bool, bool, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x61a730, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(songInfo, songDelegate, showSongSelect, showPlayMusic, showDownload, isRobtopSong, unkBool, isMusicLibrary, unk);
}

auto CustomSongWidget::loadSongInfoFinished(SongInfoObject* object) -> decltype(loadSongInfoFinished(object)) {
	auto self = addresser::thunkAdjust(Resolve<SongInfoObject*>::func(&CustomSongWidget::loadSongInfoFinished), this);
	using FunctionType = decltype(loadSongInfoFinished(object))(*)(CustomSongWidget*, SongInfoObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x620210, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, object);
}

auto CustomSongWidget::loadSongInfoFailed(int id, GJSongError errorType) -> decltype(loadSongInfoFailed(id, errorType)) {
	auto self = addresser::thunkAdjust(Resolve<int, GJSongError>::func(&CustomSongWidget::loadSongInfoFailed), this);
	using FunctionType = decltype(loadSongInfoFailed(id, errorType))(*)(CustomSongWidget*, int, GJSongError);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6204f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, id, errorType);
}

auto CustomSongWidget::downloadSongStarted(int id) -> decltype(downloadSongStarted(id)) {
	auto self = addresser::thunkAdjust(Resolve<int>::func(&CustomSongWidget::downloadSongStarted), this);
	using FunctionType = decltype(downloadSongStarted(id))(*)(CustomSongWidget*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6207f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, id);
}

auto CustomSongWidget::downloadSongFinished(int id) -> decltype(downloadSongFinished(id)) {
	auto self = addresser::thunkAdjust(Resolve<int>::func(&CustomSongWidget::downloadSongFinished), this);
	using FunctionType = decltype(downloadSongFinished(id))(*)(CustomSongWidget*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x620990, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, id);
}

auto CustomSongWidget::downloadSongFailed(int id, GJSongError errorType) -> decltype(downloadSongFailed(id, errorType)) {
	auto self = addresser::thunkAdjust(Resolve<int, GJSongError>::func(&CustomSongWidget::downloadSongFailed), this);
	using FunctionType = decltype(downloadSongFailed(id, errorType))(*)(CustomSongWidget*, int, GJSongError);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x620c80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, id, errorType);
}

auto CustomSongWidget::downloadSFXFinished(int id) -> decltype(downloadSFXFinished(id)) {
	auto self = addresser::thunkAdjust(Resolve<int>::func(&CustomSongWidget::downloadSFXFinished), this);
	using FunctionType = decltype(downloadSFXFinished(id))(*)(CustomSongWidget*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x620eb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, id);
}

auto CustomSongWidget::downloadSFXFailed(int id, GJSongError errorType) -> decltype(downloadSFXFailed(id, errorType)) {
	auto self = addresser::thunkAdjust(Resolve<int, GJSongError>::func(&CustomSongWidget::downloadSFXFailed), this);
	using FunctionType = decltype(downloadSFXFailed(id, errorType))(*)(CustomSongWidget*, int, GJSongError);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x620ee0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, id, errorType);
}

auto CustomSongWidget::musicActionFinished(GJMusicAction action) -> decltype(musicActionFinished(action)) {
	auto self = addresser::thunkAdjust(Resolve<GJMusicAction>::func(&CustomSongWidget::musicActionFinished), this);
	using FunctionType = decltype(musicActionFinished(action))(*)(CustomSongWidget*, GJMusicAction);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x621320, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, action);
}

auto CustomSongWidget::musicActionFailed(GJMusicAction action) -> decltype(musicActionFailed(action)) {
	auto self = addresser::thunkAdjust(Resolve<GJMusicAction>::func(&CustomSongWidget::musicActionFailed), this);
	using FunctionType = decltype(musicActionFailed(action))(*)(CustomSongWidget*, GJMusicAction);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x621380, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, action);
}

auto CustomSongWidget::songStateChanged() -> decltype(songStateChanged()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CustomSongWidget::songStateChanged), this);
	using FunctionType = decltype(songStateChanged())(*)(CustomSongWidget*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x61f330, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CustomSongWidget::FLAlert_Clicked(FLAlertLayer* layer, bool btn2) -> decltype(FLAlert_Clicked(layer, btn2)) {
	auto self = addresser::thunkAdjust(Resolve<FLAlertLayer*, bool>::func(&CustomSongWidget::FLAlert_Clicked), this);
	using FunctionType = decltype(FLAlert_Clicked(layer, btn2))(*)(CustomSongWidget*, FLAlertLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x621420, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, layer, btn2);
}

auto CustomSongWidget::addExtraVisuals(bool newMusic, bool newLibraryMusic) -> decltype(addExtraVisuals(newMusic, newLibraryMusic)) {
	using FunctionType = decltype(addExtraVisuals(newMusic, newLibraryMusic))(*)(CustomSongWidget*, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x61e7f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, newMusic, newLibraryMusic);
}

auto CustomSongWidget::deleteSong() -> decltype(deleteSong()) {
	using FunctionType = decltype(deleteSong())(*)(CustomSongWidget*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x61e910, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CustomSongWidget::downloadAssetFailed(int id, GJAssetType type, GJSongError errorType) -> decltype(downloadAssetFailed(id, type, errorType)) {
	using FunctionType = decltype(downloadAssetFailed(id, type, errorType))(*)(CustomSongWidget*, int, GJAssetType, GJSongError);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x620e30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, type, errorType);
}

auto CustomSongWidget::downloadAssetFinished(int id, GJAssetType type) -> decltype(downloadAssetFinished(id, type)) {
	using FunctionType = decltype(downloadAssetFinished(id, type))(*)(CustomSongWidget*, int, GJAssetType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x620a50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, type);
}

auto CustomSongWidget::downloadFailed() -> decltype(downloadFailed()) {
	using FunctionType = decltype(downloadFailed())(*)(CustomSongWidget*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x61f2e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CustomSongWidget::getSongInfoIfUnloaded() -> decltype(getSongInfoIfUnloaded()) {
	using FunctionType = decltype(getSongInfoIfUnloaded())(*)(CustomSongWidget*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x61ec90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CustomSongWidget::init(SongInfoObject* songInfo, CustomSongDelegate* songDelegate, bool showSongSelect, bool showPlayMusic, bool showDownload, bool isRobtopSong, bool unkBool, bool isMusicLibrary, int unk) -> decltype(init(songInfo, songDelegate, showSongSelect, showPlayMusic, showDownload, isRobtopSong, unkBool, isMusicLibrary, unk)) {
	using FunctionType = decltype(init(songInfo, songDelegate, showSongSelect, showPlayMusic, showDownload, isRobtopSong, unkBool, isMusicLibrary, unk))(*)(CustomSongWidget*, SongInfoObject*, CustomSongDelegate*, bool, bool, bool, bool, bool, bool, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x61a8f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, songInfo, songDelegate, showSongSelect, showPlayMusic, showDownload, isRobtopSong, unkBool, isMusicLibrary, unk);
}

auto CustomSongWidget::onCancelDownload(cocos2d::CCObject* sender) -> decltype(onCancelDownload(sender)) {
	using FunctionType = decltype(onCancelDownload(sender))(*)(CustomSongWidget*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x61bd00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto CustomSongWidget::onDelete(cocos2d::CCObject* sender) -> decltype(onDelete(sender)) {
	using FunctionType = decltype(onDelete(sender))(*)(CustomSongWidget*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x61bd40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto CustomSongWidget::onDownload(cocos2d::CCObject* sender) -> decltype(onDownload(sender)) {
	using FunctionType = decltype(onDownload(sender))(*)(CustomSongWidget*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x61ba70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto CustomSongWidget::onGetSongInfo(cocos2d::CCObject* sender) -> decltype(onGetSongInfo(sender)) {
	using FunctionType = decltype(onGetSongInfo(sender))(*)(CustomSongWidget*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x61be80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto CustomSongWidget::onInfo(cocos2d::CCObject* sender) -> decltype(onInfo(sender)) {
	using FunctionType = decltype(onInfo(sender))(*)(CustomSongWidget*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x61cb90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto CustomSongWidget::onMore(cocos2d::CCObject* sender) -> decltype(onMore(sender)) {
	using FunctionType = decltype(onMore(sender))(*)(CustomSongWidget*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x61c1a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto CustomSongWidget::onPlayback(cocos2d::CCObject* sender) -> decltype(onPlayback(sender)) {
	using FunctionType = decltype(onPlayback(sender))(*)(CustomSongWidget*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x61bf10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto CustomSongWidget::onSelect(cocos2d::CCObject* sender) -> decltype(onSelect(sender)) {
	using FunctionType = decltype(onSelect(sender))(*)(CustomSongWidget*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x61be20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto CustomSongWidget::positionInfoObjects() -> decltype(positionInfoObjects()) {
	using FunctionType = decltype(positionInfoObjects())(*)(CustomSongWidget*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x61cfc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CustomSongWidget::processNextMultiAsset() -> decltype(processNextMultiAsset()) {
	using FunctionType = decltype(processNextMultiAsset())(*)(CustomSongWidget*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x621070, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CustomSongWidget::showError(bool fast) -> decltype(showError(fast)) {
	using FunctionType = decltype(showError(fast))(*)(CustomSongWidget*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x61ea50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, fast);
}

auto CustomSongWidget::startDownload() -> decltype(startDownload()) {
	using FunctionType = decltype(startDownload())(*)(CustomSongWidget*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x61f140, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CustomSongWidget::startMonitorDownload() -> decltype(startMonitorDownload()) {
	using FunctionType = decltype(startMonitorDownload())(*)(CustomSongWidget*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x61e660, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CustomSongWidget::startMultiAssetDownload() -> decltype(startMultiAssetDownload()) {
	using FunctionType = decltype(startMultiAssetDownload())(*)(CustomSongWidget*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x61ede0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CustomSongWidget::toggleUpdateButton(bool enabled) -> decltype(toggleUpdateButton(enabled)) {
	using FunctionType = decltype(toggleUpdateButton(enabled))(*)(CustomSongWidget*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x61ed90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, enabled);
}

auto CustomSongWidget::updateDownloadProgress(float dt) -> decltype(updateDownloadProgress(dt)) {
	using FunctionType = decltype(updateDownloadProgress(dt))(*)(CustomSongWidget*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x61f210, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt);
}

auto CustomSongWidget::updateError(GJSongError errorType) -> decltype(updateError(errorType)) {
	using FunctionType = decltype(updateError(errorType))(*)(CustomSongWidget*, GJSongError);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x620710, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, errorType);
}

auto CustomSongWidget::updateLengthMod(float lengthMod) -> decltype(updateLengthMod(lengthMod)) {
	using FunctionType = decltype(updateLengthMod(lengthMod))(*)(CustomSongWidget*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x61f380, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, lengthMod);
}

auto CustomSongWidget::updateMultiAssetInfo(bool update) -> decltype(updateMultiAssetInfo(update)) {
	using FunctionType = decltype(updateMultiAssetInfo(update))(*)(CustomSongWidget*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x61fb70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, update);
}

auto CustomSongWidget::updatePlaybackBtn() -> decltype(updatePlaybackBtn()) {
	using FunctionType = decltype(updatePlaybackBtn())(*)(CustomSongWidget*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x61e710, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CustomSongWidget::updateProgressBar(int progress) -> decltype(updateProgressBar(progress)) {
	using FunctionType = decltype(updateProgressBar(progress))(*)(CustomSongWidget*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x61d5f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, progress);
}

auto CustomSongWidget::updateSongInfo() -> decltype(updateSongInfo()) {
	using FunctionType = decltype(updateSongInfo())(*)(CustomSongWidget*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x61d710, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CustomSongWidget::updateSongObject(SongInfoObject* songInfo) -> decltype(updateSongObject(songInfo)) {
	using FunctionType = decltype(updateSongObject(songInfo))(*)(CustomSongWidget*, SongInfoObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x61d670, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, songInfo);
}

auto CustomSongWidget::updateWithMultiAssets(gd::string songList, gd::string sfxList, int bytes) -> decltype(updateWithMultiAssets(songList, sfxList, bytes)) {
	using FunctionType = decltype(updateWithMultiAssets(songList, sfxList, bytes))(*)(CustomSongWidget*, gd::string, gd::string, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x61f3a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, songList, sfxList, bytes);
}

auto CustomSongWidget::verifySongID(int id) -> decltype(verifySongID(id)) {
	using FunctionType = decltype(verifySongID(id))(*)(CustomSongWidget*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6201f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}
