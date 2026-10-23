
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/MusicDownloadManager.hpp>
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

auto MusicDownloadManager::sharedState() -> decltype(sharedState()) {
	using FunctionType = decltype(sharedState())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x589f90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto MusicDownloadManager::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&MusicDownloadManager::init), this);
	using FunctionType = decltype(init())(*)(MusicDownloadManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58af00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto MusicDownloadManager::addDLToActive(char const* tag) -> decltype(addDLToActive(tag)) {
	using FunctionType = decltype(addDLToActive(tag))(*)(MusicDownloadManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58bbc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, tag);
}

auto MusicDownloadManager::addDLToActive(char const* tag, cocos2d::CCObject* obj) -> decltype(addDLToActive(tag, obj)) {
	using FunctionType = decltype(addDLToActive(tag, obj))(*)(MusicDownloadManager*, char const*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58f7f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, tag, obj);
}

auto MusicDownloadManager::addMusicDownloadDelegate(MusicDownloadDelegate* delegate) -> decltype(addMusicDownloadDelegate(delegate)) {
	using FunctionType = decltype(addMusicDownloadDelegate(delegate))(*)(MusicDownloadManager*, MusicDownloadDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58b0b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, delegate);
}

auto MusicDownloadManager::addSongObjectFromString(gd::string str) -> decltype(addSongObjectFromString(str)) {
	using FunctionType = decltype(addSongObjectFromString(str))(*)(MusicDownloadManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58bc60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, str);
}

auto MusicDownloadManager::clearSong(int songID) -> decltype(clearSong(songID)) {
	using FunctionType = decltype(clearSong(songID))(*)(MusicDownloadManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58e9f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, songID);
}

auto MusicDownloadManager::clearUnusedSongs() -> decltype(clearUnusedSongs()) {
	using FunctionType = decltype(clearUnusedSongs())(*)(MusicDownloadManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58eba0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto MusicDownloadManager::createArtistsInfo(gd::string str) -> decltype(createArtistsInfo(str)) {
	using FunctionType = decltype(createArtistsInfo(str))(*)(MusicDownloadManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58d820, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, str);
}

auto MusicDownloadManager::createSongsInfo(gd::string songsStr, gd::string artistsStr) -> decltype(createSongsInfo(songsStr, artistsStr)) {
	using FunctionType = decltype(createSongsInfo(songsStr, artistsStr))(*)(MusicDownloadManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58d3d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, songsStr, artistsStr);
}

auto MusicDownloadManager::dataLoaded(DS_Dictionary* dict) -> decltype(dataLoaded(dict)) {
	using FunctionType = decltype(dataLoaded(dict))(*)(MusicDownloadManager*, DS_Dictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5906f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dict);
}

auto MusicDownloadManager::deleteSFX(int id) -> decltype(deleteSFX(id)) {
	using FunctionType = decltype(deleteSFX(id))(*)(MusicDownloadManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x596ad0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto MusicDownloadManager::deleteSong(int id) -> decltype(deleteSong(id)) {
	using FunctionType = decltype(deleteSong(id))(*)(MusicDownloadManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58e9a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto MusicDownloadManager::downloadCustomSong(int id) -> decltype(downloadCustomSong(id)) {
	using FunctionType = decltype(downloadCustomSong(id))(*)(MusicDownloadManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58f200, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto MusicDownloadManager::downloadMusicLibrary() -> decltype(downloadMusicLibrary()) {
	using FunctionType = decltype(downloadMusicLibrary())(*)(MusicDownloadManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x591ac0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto MusicDownloadManager::downloadSFX(int id) -> decltype(downloadSFX(id)) {
	using FunctionType = decltype(downloadSFX(id))(*)(MusicDownloadManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x594c10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto MusicDownloadManager::downloadSFXFailed(int id, GJSongError errorCode) -> decltype(downloadSFXFailed(id, errorCode)) {
	using FunctionType = decltype(downloadSFXFailed(id, errorCode))(*)(MusicDownloadManager*, int, GJSongError);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x595150, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, errorCode);
}

auto MusicDownloadManager::downloadSFXFinished(int id) -> decltype(downloadSFXFinished(id)) {
	using FunctionType = decltype(downloadSFXFinished(id))(*)(MusicDownloadManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5951c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto MusicDownloadManager::downloadSFXLibrary() -> decltype(downloadSFXLibrary()) {
	using FunctionType = decltype(downloadSFXLibrary())(*)(MusicDownloadManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x595570, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto MusicDownloadManager::downloadSong(int id) -> decltype(downloadSong(id)) {
	using FunctionType = decltype(downloadSong(id))(*)(MusicDownloadManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58ed00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto MusicDownloadManager::downloadSongFailed(int id, GJSongError errorCode) -> decltype(downloadSongFailed(id, errorCode)) {
	using FunctionType = decltype(downloadSongFailed(id, errorCode))(*)(MusicDownloadManager*, int, GJSongError);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58f8e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, errorCode);
}

auto MusicDownloadManager::downloadSongFinished(int id) -> decltype(downloadSongFinished(id)) {
	using FunctionType = decltype(downloadSongFinished(id))(*)(MusicDownloadManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58f950, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto MusicDownloadManager::downloadSongStarted(int id) -> decltype(downloadSongStarted(id)) {
	using FunctionType = decltype(downloadSongStarted(id))(*)(MusicDownloadManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58ec80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto MusicDownloadManager::encodeDataTo(DS_Dictionary* dict) -> decltype(encodeDataTo(dict)) {
	using FunctionType = decltype(encodeDataTo(dict))(*)(MusicDownloadManager*, DS_Dictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x590690, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dict);
}

auto MusicDownloadManager::filterMusicByArtistID(int id, cocos2d::CCArray* songs) -> decltype(filterMusicByArtistID(id, songs)) {
	using FunctionType = decltype(filterMusicByArtistID(id, songs))(*)(MusicDownloadManager*, int, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5947e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, songs);
}

auto MusicDownloadManager::filterMusicByTag(int id, cocos2d::CCArray* songs) -> decltype(filterMusicByTag(id, songs)) {
	using FunctionType = decltype(filterMusicByTag(id, songs))(*)(MusicDownloadManager*, int, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x594a00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, songs);
}

auto MusicDownloadManager::firstSetup() -> decltype(firstSetup()) {
	using FunctionType = decltype(firstSetup())(*)(MusicDownloadManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x590630, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto MusicDownloadManager::generateCustomContentURL(gd::string path) -> decltype(generateCustomContentURL(path)) {
	using FunctionType = decltype(generateCustomContentURL(path))(*)(MusicDownloadManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x590f80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, path);
}

auto MusicDownloadManager::generateResourceAssetList() -> decltype(generateResourceAssetList()) {
	using FunctionType = decltype(generateResourceAssetList())(*)(MusicDownloadManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58aff0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto MusicDownloadManager::getAllMusicArtists(OptionsObjectDelegate* delegate) -> decltype(getAllMusicArtists(delegate)) {
	using FunctionType = decltype(getAllMusicArtists(delegate))(*)(MusicDownloadManager*, OptionsObjectDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5946c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, delegate);
}

auto MusicDownloadManager::getAllMusicObjects(GJSongType type) -> decltype(getAllMusicObjects(type)) {
	using FunctionType = decltype(getAllMusicObjects(type))(*)(MusicDownloadManager*, GJSongType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5944a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type);
}

auto MusicDownloadManager::getAllMusicTags(OptionsObjectDelegate* delegate) -> decltype(getAllMusicTags(delegate)) {
	using FunctionType = decltype(getAllMusicTags(delegate))(*)(MusicDownloadManager*, OptionsObjectDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x594560, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, delegate);
}

auto MusicDownloadManager::getAllSFXObjects(bool onlySFX) -> decltype(getAllSFXObjects(onlySFX)) {
	using FunctionType = decltype(getAllSFXObjects(onlySFX))(*)(MusicDownloadManager*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x596a10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, onlySFX);
}

auto MusicDownloadManager::getAllSongs() -> decltype(getAllSongs()) {
	using FunctionType = decltype(getAllSongs())(*)(MusicDownloadManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58e800, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto MusicDownloadManager::getCustomContentURL() -> decltype(getCustomContentURL()) {
	using FunctionType = decltype(getCustomContentURL())(*)(MusicDownloadManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x590d30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto MusicDownloadManager::getDLObject(char const* id) -> decltype(getDLObject(id)) {
	using FunctionType = decltype(getDLObject(id))(*)(MusicDownloadManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58b350, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto MusicDownloadManager::getDownloadedSongs() -> decltype(getDownloadedSongs()) {
	using FunctionType = decltype(getDownloadedSongs())(*)(MusicDownloadManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58e4b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto MusicDownloadManager::getDownloadProgress(int id) -> decltype(getDownloadProgress(id)) {
	using FunctionType = decltype(getDownloadProgress(id))(*)(MusicDownloadManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58f9c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto MusicDownloadManager::getMusicArtistForID(int id) -> decltype(getMusicArtistForID(id)) {
	using FunctionType = decltype(getMusicArtistForID(id))(*)(MusicDownloadManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x594480, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto MusicDownloadManager::getMusicObject(int id) -> decltype(getMusicObject(id)) {
	using FunctionType = decltype(getMusicObject(id))(*)(MusicDownloadManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58fa80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto MusicDownloadManager::getSFXDownloadKey(int id) -> decltype(getSFXDownloadKey(id)) {
	using FunctionType = decltype(getSFXDownloadKey(id))(*)(MusicDownloadManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58fa60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto MusicDownloadManager::getSFXDownloadProgress(int id) -> decltype(getSFXDownloadProgress(id)) {
	using FunctionType = decltype(getSFXDownloadProgress(id))(*)(MusicDownloadManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58fa10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto MusicDownloadManager::getSFXFolderObjectForID(int id) -> decltype(getSFXFolderObjectForID(id)) {
	using FunctionType = decltype(getSFXFolderObjectForID(id))(*)(MusicDownloadManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5966d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto MusicDownloadManager::getSFXFolderPathForID(int id, bool nextFolder) -> decltype(getSFXFolderPathForID(id, nextFolder)) {
	using FunctionType = decltype(getSFXFolderPathForID(id, nextFolder))(*)(MusicDownloadManager*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x596950, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, nextFolder);
}

auto MusicDownloadManager::getSFXObject(int id) -> decltype(getSFXObject(id)) {
	using FunctionType = decltype(getSFXObject(id))(*)(MusicDownloadManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5966b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto MusicDownloadManager::getSongDownloadKey(int id) -> decltype(getSongDownloadKey(id)) {
	using FunctionType = decltype(getSongDownloadKey(id))(*)(MusicDownloadManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58b2e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto MusicDownloadManager::getSongInfo(int id, bool download) -> decltype(getSongInfo(id, download)) {
	using FunctionType = decltype(getSongInfo(id, download))(*)(MusicDownloadManager*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58b700, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, download);
}

auto MusicDownloadManager::getSongInfoKey(int id) -> decltype(getSongInfoKey(id)) {
	using FunctionType = decltype(getSongInfoKey(id))(*)(MusicDownloadManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58b2c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto MusicDownloadManager::getSongInfoObject(int id) -> decltype(getSongInfoObject(id)) {
	using FunctionType = decltype(getSongInfoObject(id))(*)(MusicDownloadManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58b5a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto MusicDownloadManager::getSongPriority() -> decltype(getSongPriority()) {
	using FunctionType = decltype(getSongPriority())(*)(MusicDownloadManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58b6e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto MusicDownloadManager::handleIt(bool success, gd::string response, gd::string tag, GJHttpType type) -> decltype(handleIt(success, response, tag, type)) {
	using FunctionType = decltype(handleIt(success, response, tag, type))(*)(MusicDownloadManager*, bool, gd::string, gd::string, GJHttpType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58a560, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, success, response, tag, type);
}

auto MusicDownloadManager::handleItDelayed(bool success, gd::string response, gd::string tag, GJHttpType type) -> decltype(handleItDelayed(success, response, tag, type)) {
	using FunctionType = decltype(handleItDelayed(success, response, tag, type))(*)(MusicDownloadManager*, bool, gd::string, gd::string, GJHttpType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58a730, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, success, response, tag, type);
}

auto MusicDownloadManager::handleItND(cocos2d::CCNode* node, void* data) -> decltype(handleItND(node, data)) {
	using FunctionType = decltype(handleItND(node, data))(*)(MusicDownloadManager*, cocos2d::CCNode*, void*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58a870, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, node, data);
}

auto MusicDownloadManager::incrementPriorityForSong(int id) -> decltype(incrementPriorityForSong(id)) {
	using FunctionType = decltype(incrementPriorityForSong(id))(*)(MusicDownloadManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58b570, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto MusicDownloadManager::isDLActive(char const* tag) -> decltype(isDLActive(tag)) {
	using FunctionType = decltype(isDLActive(tag))(*)(MusicDownloadManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58b2a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, tag);
}

auto MusicDownloadManager::isMusicLibraryLoaded() -> decltype(isMusicLibraryLoaded()) {
	using FunctionType = decltype(isMusicLibraryLoaded())(*)(MusicDownloadManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x593ce0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto MusicDownloadManager::isResourceSFX(int id) -> decltype(isResourceSFX(id)) {
	using FunctionType = decltype(isResourceSFX(id))(*)(MusicDownloadManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5900f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto MusicDownloadManager::isResourceSong(int id) -> decltype(isResourceSong(id)) {
	using FunctionType = decltype(isResourceSong(id))(*)(MusicDownloadManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58faa0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto MusicDownloadManager::isRunningActionForSongID(int id) -> decltype(isRunningActionForSongID(id)) {
	using FunctionType = decltype(isRunningActionForSongID(id))(*)(MusicDownloadManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58b230, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto MusicDownloadManager::isSFXDownloaded(int id) -> decltype(isSFXDownloaded(id)) {
	using FunctionType = decltype(isSFXDownloaded(id))(*)(MusicDownloadManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58fe40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto MusicDownloadManager::isSFXLibraryLoaded() -> decltype(isSFXLibraryLoaded()) {
	using FunctionType = decltype(isSFXLibraryLoaded())(*)(MusicDownloadManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5963e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto MusicDownloadManager::isSongDownloaded(int id) -> decltype(isSongDownloaded(id)) {
	using FunctionType = decltype(isSongDownloaded(id))(*)(MusicDownloadManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58e550, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto MusicDownloadManager::limitDownloadedSongs() -> decltype(limitDownloadedSongs()) {
	using FunctionType = decltype(limitDownloadedSongs())(*)(MusicDownloadManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58e860, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto MusicDownloadManager::loadSongInfoFailed(int id, GJSongError errorCode) -> decltype(loadSongInfoFailed(id, errorCode)) {
	using FunctionType = decltype(loadSongInfoFailed(id, errorCode))(*)(MusicDownloadManager*, int, GJSongError);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58bbf0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, errorCode);
}

auto MusicDownloadManager::loadSongInfoFinished(SongInfoObject* object) -> decltype(loadSongInfoFinished(object)) {
	using FunctionType = decltype(loadSongInfoFinished(object))(*)(MusicDownloadManager*, SongInfoObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58bb50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto MusicDownloadManager::musicActionFailed(GJMusicAction action) -> decltype(musicActionFailed(action)) {
	using FunctionType = decltype(musicActionFailed(action))(*)(MusicDownloadManager*, GJMusicAction);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x590ea0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, action);
}

auto MusicDownloadManager::musicActionFinished(GJMusicAction action) -> decltype(musicActionFinished(action)) {
	using FunctionType = decltype(musicActionFinished(action))(*)(MusicDownloadManager*, GJMusicAction);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x590f10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, action);
}

auto MusicDownloadManager::nameForTagID(int id) -> decltype(nameForTagID(id)) {
	using FunctionType = decltype(nameForTagID(id))(*)(MusicDownloadManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x594ae0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto MusicDownloadManager::onDownloadMusicLibraryCompleted(cocos2d::extension::CCHttpClient* client, cocos2d::extension::CCHttpResponse* response) -> decltype(onDownloadMusicLibraryCompleted(client, response)) {
	using FunctionType = decltype(onDownloadMusicLibraryCompleted(client, response))(*)(MusicDownloadManager*, cocos2d::extension::CCHttpClient*, cocos2d::extension::CCHttpResponse*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x591cb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, client, response);
}

auto MusicDownloadManager::onDownloadSFXCompleted(cocos2d::extension::CCHttpClient* client, cocos2d::extension::CCHttpResponse* response) -> decltype(onDownloadSFXCompleted(client, response)) {
	using FunctionType = decltype(onDownloadSFXCompleted(client, response))(*)(MusicDownloadManager*, cocos2d::extension::CCHttpClient*, cocos2d::extension::CCHttpResponse*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x594f00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, client, response);
}

auto MusicDownloadManager::onDownloadSFXLibraryCompleted(cocos2d::extension::CCHttpClient* client, cocos2d::extension::CCHttpResponse* response) -> decltype(onDownloadSFXLibraryCompleted(client, response)) {
	using FunctionType = decltype(onDownloadSFXLibraryCompleted(client, response))(*)(MusicDownloadManager*, cocos2d::extension::CCHttpClient*, cocos2d::extension::CCHttpResponse*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x595720, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, client, response);
}

auto MusicDownloadManager::onDownloadSongCompleted(cocos2d::extension::CCHttpClient* client, cocos2d::extension::CCHttpResponse* response) -> decltype(onDownloadSongCompleted(client, response)) {
	using FunctionType = decltype(onDownloadSongCompleted(client, response))(*)(MusicDownloadManager*, cocos2d::extension::CCHttpClient*, cocos2d::extension::CCHttpResponse*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58f540, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, client, response);
}

auto MusicDownloadManager::onGetCustomContentURLCompleted(gd::string response, gd::string tag) -> decltype(onGetCustomContentURLCompleted(response, tag)) {
	using FunctionType = decltype(onGetCustomContentURLCompleted(response, tag))(*)(MusicDownloadManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58ac30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto MusicDownloadManager::onGetSongInfoCompleted(gd::string response, gd::string tag) -> decltype(onGetSongInfoCompleted(response, tag)) {
	using FunctionType = decltype(onGetSongInfoCompleted(response, tag))(*)(MusicDownloadManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58a990, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto MusicDownloadManager::onProcessHttpRequestCompleted(cocos2d::extension::CCHttpClient* client, cocos2d::extension::CCHttpResponse* response) -> decltype(onProcessHttpRequestCompleted(client, response)) {
	using FunctionType = decltype(onProcessHttpRequestCompleted(client, response))(*)(MusicDownloadManager*, cocos2d::extension::CCHttpClient*, cocos2d::extension::CCHttpResponse*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58a230, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, client, response);
}

auto MusicDownloadManager::onTryUpdateMusicLibraryCompleted(cocos2d::extension::CCHttpClient* client, cocos2d::extension::CCHttpResponse* response) -> decltype(onTryUpdateMusicLibraryCompleted(client, response)) {
	using FunctionType = decltype(onTryUpdateMusicLibraryCompleted(client, response))(*)(MusicDownloadManager*, cocos2d::extension::CCHttpClient*, cocos2d::extension::CCHttpResponse*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x591970, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, client, response);
}

auto MusicDownloadManager::onTryUpdateSFXLibraryCompleted(cocos2d::extension::CCHttpClient* client, cocos2d::extension::CCHttpResponse* response) -> decltype(onTryUpdateSFXLibraryCompleted(client, response)) {
	using FunctionType = decltype(onTryUpdateSFXLibraryCompleted(client, response))(*)(MusicDownloadManager*, cocos2d::extension::CCHttpClient*, cocos2d::extension::CCHttpResponse*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x595420, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, client, response);
}

auto MusicDownloadManager::parseMusicLibrary() -> decltype(parseMusicLibrary()) {
	using FunctionType = decltype(parseMusicLibrary())(*)(MusicDownloadManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x591f00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto MusicDownloadManager::parseSFXLibrary() -> decltype(parseSFXLibrary()) {
	using FunctionType = decltype(parseSFXLibrary())(*)(MusicDownloadManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5958f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto MusicDownloadManager::pathForSFX(int id) -> decltype(pathForSFX(id)) {
	using FunctionType = decltype(pathForSFX(id))(*)(MusicDownloadManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x590230, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto MusicDownloadManager::pathForSFXFolder(int id) -> decltype(pathForSFXFolder(id)) {
	using FunctionType = decltype(pathForSFXFolder(id))(*)(MusicDownloadManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5902f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto MusicDownloadManager::pathForSong(int id) -> decltype(pathForSong(id)) {
	using FunctionType = decltype(pathForSong(id))(*)(MusicDownloadManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58eae0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto MusicDownloadManager::pathForSongFolder(int id) -> decltype(pathForSongFolder(id)) {
	using FunctionType = decltype(pathForSongFolder(id))(*)(MusicDownloadManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58fbe0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto MusicDownloadManager::ProcessHttpGetRequest(gd::string url, gd::string tag, cocos2d::extension::SEL_HttpResponse selector, int connectTimeout, int readTimeout) -> decltype(ProcessHttpGetRequest(url, tag, selector, connectTimeout, readTimeout)) {
	using FunctionType = decltype(ProcessHttpGetRequest(url, tag, selector, connectTimeout, readTimeout))(*)(MusicDownloadManager*, gd::string, gd::string, cocos2d::extension::SEL_HttpResponse, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58a3f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, url, tag, selector, connectTimeout, readTimeout);
}

auto MusicDownloadManager::ProcessHttpRequest(gd::string url, gd::string params, gd::string tag, GJHttpType type) -> decltype(ProcessHttpRequest(url, params, tag, type)) {
	using FunctionType = decltype(ProcessHttpRequest(url, params, tag, type))(*)(MusicDownloadManager*, gd::string, gd::string, gd::string, GJHttpType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58a0a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, url, params, tag, type);
}

auto MusicDownloadManager::removeDLFromActive(char const* tag) -> decltype(removeDLFromActive(tag)) {
	using FunctionType = decltype(removeDLFromActive(tag))(*)(MusicDownloadManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58b430, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, tag);
}

auto MusicDownloadManager::removeMusicDownloadDelegate(MusicDownloadDelegate* delegate) -> decltype(removeMusicDownloadDelegate(delegate)) {
	using FunctionType = decltype(removeMusicDownloadDelegate(delegate))(*)(MusicDownloadManager*, MusicDownloadDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58b1a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, delegate);
}

auto MusicDownloadManager::responseToDict(gd::string response, char const* delimiter) -> decltype(responseToDict(response, delimiter)) {
	using FunctionType = decltype(responseToDict(response, delimiter))(*)(MusicDownloadManager*, gd::string, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58bf00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, delimiter);
}

auto MusicDownloadManager::showTOS(FLAlertLayerProtocol* delegate) -> decltype(showTOS(delegate)) {
	using FunctionType = decltype(showTOS(delegate))(*)(MusicDownloadManager*, FLAlertLayerProtocol*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x590550, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, delegate);
}

auto MusicDownloadManager::songStateChanged() -> decltype(songStateChanged()) {
	using FunctionType = decltype(songStateChanged())(*)(MusicDownloadManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58b510, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto MusicDownloadManager::stopDownload(int id) -> decltype(stopDownload(id)) {
	using FunctionType = decltype(stopDownload(id))(*)(MusicDownloadManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x58b300, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto MusicDownloadManager::storeMusicObject(SongInfoObject* object) -> decltype(storeMusicObject(object)) {
	using FunctionType = decltype(storeMusicObject(object))(*)(MusicDownloadManager*, SongInfoObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x594460, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto MusicDownloadManager::storeSFXInfoObject(SFXInfoObject* object) -> decltype(storeSFXInfoObject(object)) {
	using FunctionType = decltype(storeSFXInfoObject(object))(*)(MusicDownloadManager*, SFXInfoObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x596400, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto MusicDownloadManager::tryLoadLibraries() -> decltype(tryLoadLibraries()) {
	using FunctionType = decltype(tryLoadLibraries())(*)(MusicDownloadManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x596640, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto MusicDownloadManager::tryUpdateMusicLibrary() -> decltype(tryUpdateMusicLibrary()) {
	using FunctionType = decltype(tryUpdateMusicLibrary())(*)(MusicDownloadManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x591780, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto MusicDownloadManager::tryUpdateSFXLibrary() -> decltype(tryUpdateSFXLibrary()) {
	using FunctionType = decltype(tryUpdateSFXLibrary())(*)(MusicDownloadManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x595230, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
