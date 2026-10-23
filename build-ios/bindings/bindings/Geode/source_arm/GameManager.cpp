
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GameManager.hpp>
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

auto GameManager::sharedState() -> decltype(sharedState()) {
	using FunctionType = decltype(sharedState())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x300128, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto GameManager::update(float dt) -> decltype(update(dt)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&GameManager::update), this);
	using FunctionType = decltype(update(dt))(*)(GameManager*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x312910, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, dt);
}

auto GameManager::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GameManager::init), this);
	using FunctionType = decltype(init())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x300194, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GameManager::encodeDataTo(DS_Dictionary* dict) -> decltype(encodeDataTo(dict)) {
	auto self = addresser::thunkAdjust(Resolve<DS_Dictionary*>::func(&GameManager::encodeDataTo), this);
	using FunctionType = decltype(encodeDataTo(dict))(*)(GameManager*, DS_Dictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x311d34, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, dict);
}

auto GameManager::dataLoaded(DS_Dictionary* dict) -> decltype(dataLoaded(dict)) {
	auto self = addresser::thunkAdjust(Resolve<DS_Dictionary*>::func(&GameManager::dataLoaded), this);
	using FunctionType = decltype(dataLoaded(dict))(*)(GameManager*, DS_Dictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x310294, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, dict);
}

auto GameManager::firstLoad() -> decltype(firstLoad()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GameManager::firstLoad), this);
	using FunctionType = decltype(firstLoad())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x311520, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GameManager::accountStatusChanged() -> decltype(accountStatusChanged()) {
	using FunctionType = decltype(accountStatusChanged())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30cb20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::activeIconForType(IconType type) -> decltype(activeIconForType(type)) {
	using FunctionType = decltype(activeIconForType(type))(*)(GameManager*, IconType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x308b74, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type);
}

auto GameManager::addCustomAnimationFrame(int objectID, int frameIndex, gd::string mainFrame, gd::string detailFrame) -> decltype(addCustomAnimationFrame(objectID, frameIndex, mainFrame, detailFrame)) {
	using FunctionType = decltype(addCustomAnimationFrame(objectID, frameIndex, mainFrame, detailFrame))(*)(GameManager*, int, int, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x20a000, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, objectID, frameIndex, mainFrame, detailFrame);
}

auto GameManager::addDuplicateLastFrame(int objectID) -> decltype(addDuplicateLastFrame(objectID)) {
	using FunctionType = decltype(addDuplicateLastFrame(objectID))(*)(GameManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x20a118, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, objectID);
}

auto GameManager::addGameAnimation(int objectID, int frames, float frameTime, gd::string mainAnimFrame, gd::string detailAnimFrame, int defaultFrame) -> decltype(addGameAnimation(objectID, frames, frameTime, mainAnimFrame, detailAnimFrame, defaultFrame)) {
	using FunctionType = decltype(addGameAnimation(objectID, frames, frameTime, mainAnimFrame, detailAnimFrame, defaultFrame))(*)(GameManager*, int, int, float, gd::string, gd::string, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x209d90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, objectID, frames, frameTime, mainAnimFrame, detailAnimFrame, defaultFrame);
}

auto GameManager::addIconDelegate(cocos2d::CCObject* delegate, int key) -> decltype(addIconDelegate(delegate, key)) {
	using FunctionType = decltype(addIconDelegate(delegate, key))(*)(GameManager*, cocos2d::CCObject*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30951c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, delegate, key);
}

auto GameManager::addNewCustomObject(gd::string str) -> decltype(addNewCustomObject(str)) {
	using FunctionType = decltype(addNewCustomObject(str))(*)(GameManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30c39c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, str);
}

auto GameManager::addToGJLog(cocos2d::CCString* str) -> decltype(addToGJLog(str)) {
	using FunctionType = decltype(addToGJLog(str))(*)(GameManager*, cocos2d::CCString*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30e288, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, str);
}

auto GameManager::applicationDidEnterBackground() -> decltype(applicationDidEnterBackground()) {
	using FunctionType = decltype(applicationDidEnterBackground())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x31295c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::applicationWillEnterForeground() -> decltype(applicationWillEnterForeground()) {
	using FunctionType = decltype(applicationWillEnterForeground())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x312960, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::calculateBaseKeyForIcons() -> decltype(calculateBaseKeyForIcons()) {
	using FunctionType = decltype(calculateBaseKeyForIcons())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x300268, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::canShowRewardedVideo() -> decltype(canShowRewardedVideo()) {
	using FunctionType = decltype(canShowRewardedVideo())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x308258, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::checkSteamAchievementUnlock() -> decltype(checkSteamAchievementUnlock()) {
	using FunctionType = decltype(checkSteamAchievementUnlock())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x303330, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::checkUsedIcons() -> decltype(checkUsedIcons()) {
	using FunctionType = decltype(checkUsedIcons())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x306d84, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::claimItemsResponse(gd::string str) -> decltype(claimItemsResponse(str)) {
	using FunctionType = decltype(claimItemsResponse(str))(*)(GameManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x307b04, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, str);
}

auto GameManager::clearGJLog() -> decltype(clearGJLog()) {
	using FunctionType = decltype(clearGJLog())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30e290, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::colorForIdx(int index) -> decltype(colorForIdx(index)) {
	using FunctionType = decltype(colorForIdx(index))(*)(GameManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x307b08, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index);
}

auto GameManager::colorForPos(int pos) -> decltype(colorForPos(pos)) {
	using FunctionType = decltype(colorForPos(pos))(*)(GameManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x307fd4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, pos);
}

auto GameManager::colorKey(int id, UnlockType type) -> decltype(colorKey(id, type)) {
	using FunctionType = decltype(colorKey(id, type))(*)(GameManager*, int, UnlockType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x301680, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, type);
}

auto GameManager::completedAchievement(gd::string key) -> decltype(completedAchievement(key)) {
	using FunctionType = decltype(completedAchievement(key))(*)(GameManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30253c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GameManager::countForType(IconType type) -> decltype(countForType(type)) {
	using FunctionType = decltype(countForType(type))(*)(GameManager*, IconType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x308c84, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type);
}

auto GameManager::defaultFrameForAnimation(int objectID) -> decltype(defaultFrameForAnimation(objectID)) {
	using FunctionType = decltype(defaultFrameForAnimation(objectID))(*)(GameManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x201d2c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, objectID);
}

auto GameManager::didExitPlayscene() -> decltype(didExitPlayscene()) {
	using FunctionType = decltype(didExitPlayscene())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x312860, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::doQuickSave() -> decltype(doQuickSave()) {
	using FunctionType = decltype(doQuickSave())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x312834, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::dpadConfigToString(UIButtonConfig& config) -> decltype(dpadConfigToString(config)) {
	using FunctionType = decltype(dpadConfigToString(config))(*)(GameManager*, UIButtonConfig&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30ecf4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, config);
}

auto GameManager::eventUnlockFeature(char const* key) -> decltype(eventUnlockFeature(key)) {
	using FunctionType = decltype(eventUnlockFeature(key))(*)(GameManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x307af0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GameManager::fadeInMenuMusic() -> decltype(fadeInMenuMusic()) {
	using FunctionType = decltype(fadeInMenuMusic())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x300a40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::fadeInMusic(gd::string path) -> decltype(fadeInMusic(path)) {
	using FunctionType = decltype(fadeInMusic(path))(*)(GameManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x300b38, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, path);
}

auto GameManager::finishedLoadingBGAsync(cocos2d::CCObject* obj) -> decltype(finishedLoadingBGAsync(obj)) {
	using FunctionType = decltype(finishedLoadingBGAsync(obj))(*)(GameManager*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30b078, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, obj);
}

auto GameManager::finishedLoadingGAsync(int index) -> decltype(finishedLoadingGAsync(index)) {
	using FunctionType = decltype(finishedLoadingGAsync(index))(*)(GameManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30b700, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index);
}

auto GameManager::finishedLoadingGAsync1(cocos2d::CCObject* obj) -> decltype(finishedLoadingGAsync1(obj)) {
	using FunctionType = decltype(finishedLoadingGAsync1(obj))(*)(GameManager*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30b668, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, obj);
}

auto GameManager::finishedLoadingGAsync2(cocos2d::CCObject* obj) -> decltype(finishedLoadingGAsync2(obj)) {
	using FunctionType = decltype(finishedLoadingGAsync2(obj))(*)(GameManager*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30b6b4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, obj);
}

auto GameManager::finishedLoadingIconAsync(cocos2d::CCObject* obj) -> decltype(finishedLoadingIconAsync(obj)) {
	using FunctionType = decltype(finishedLoadingIconAsync(obj))(*)(GameManager*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x309690, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, obj);
}

auto GameManager::finishedLoadingMGAsync(int index) -> decltype(finishedLoadingMGAsync(index)) {
	using FunctionType = decltype(finishedLoadingMGAsync(index))(*)(GameManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30b3a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index);
}

auto GameManager::finishedLoadingMGAsync1(cocos2d::CCObject* obj) -> decltype(finishedLoadingMGAsync1(obj)) {
	using FunctionType = decltype(finishedLoadingMGAsync1(obj))(*)(GameManager*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30b308, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, obj);
}

auto GameManager::finishedLoadingMGAsync2(cocos2d::CCObject* obj) -> decltype(finishedLoadingMGAsync2(obj)) {
	using FunctionType = decltype(finishedLoadingMGAsync2(obj))(*)(GameManager*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30b354, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, obj);
}

auto GameManager::followTwitch() -> decltype(followTwitch()) {
	using FunctionType = decltype(followTwitch())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3088ac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::followTwitter() -> decltype(followTwitter()) {
	using FunctionType = decltype(followTwitter())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3087ac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::framesForAnimation(int objectID) -> decltype(framesForAnimation(objectID)) {
	using FunctionType = decltype(framesForAnimation(objectID))(*)(GameManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x201f04, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, objectID);
}

auto GameManager::frameTimeForAnimation(int objectID) -> decltype(frameTimeForAnimation(objectID)) {
	using FunctionType = decltype(frameTimeForAnimation(objectID))(*)(GameManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x201f34, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, objectID);
}

auto GameManager::generateSecretNumber() -> decltype(generateSecretNumber()) {
	using FunctionType = decltype(generateSecretNumber())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30e0cc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::getBGTexture(int index) -> decltype(getBGTexture(index)) {
	using FunctionType = decltype(getBGTexture(index))(*)(GameManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30b79c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index);
}

auto GameManager::getFontFile(int index) -> decltype(getFontFile(index)) {
	using FunctionType = decltype(getFontFile(index))(*)(GameManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30acd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index);
}

auto GameManager::getFontTexture(int index) -> decltype(getFontTexture(index)) {
	using FunctionType = decltype(getFontTexture(index))(*)(GameManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30ad3c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index);
}

auto GameManager::getGameVariable(char const* key) -> decltype(getGameVariable(key)) {
	using FunctionType = decltype(getGameVariable(key))(*)(GameManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3008a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GameManager::getGTexture(int index) -> decltype(getGTexture(index)) {
	using FunctionType = decltype(getGTexture(index))(*)(GameManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30b834, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index);
}

auto GameManager::getIconRequestID() -> decltype(getIconRequestID()) {
	using FunctionType = decltype(getIconRequestID())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30ab30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::getIntGameVariable(char const* key) -> decltype(getIntGameVariable(key)) {
	using FunctionType = decltype(getIntGameVariable(key))(*)(GameManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30c050, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GameManager::getMenuMusicFile() -> decltype(getMenuMusicFile()) {
	using FunctionType = decltype(getMenuMusicFile())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3003e8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::getMGTexture(int index) -> decltype(getMGTexture(index)) {
	using FunctionType = decltype(getMGTexture(index))(*)(GameManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30b7e8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index);
}

auto GameManager::getNextUniqueObjectKey() -> decltype(getNextUniqueObjectKey()) {
	using FunctionType = decltype(getNextUniqueObjectKey())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30c174, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::getNextUsedKey(int index, bool up) -> decltype(getNextUsedKey(index, up)) {
	using FunctionType = decltype(getNextUsedKey(index, up))(*)(GameManager*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30c26c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index, up);
}

auto GameManager::getOrderedCustomObjectKeys() -> decltype(getOrderedCustomObjectKeys()) {
	using FunctionType = decltype(getOrderedCustomObjectKeys())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30c220, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::getPracticeMusicFile() -> decltype(getPracticeMusicFile()) {
	using FunctionType = decltype(getPracticeMusicFile())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30055c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::getUGV(char const* key) -> decltype(getUGV(key)) {
	using FunctionType = decltype(getUGV(key))(*)(GameManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30bd78, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GameManager::getUnlockForAchievement(gd::string key, int& id, UnlockType& type) -> decltype(getUnlockForAchievement(key, id, type)) {
	using FunctionType = decltype(getUnlockForAchievement(key, id, type))(*)(GameManager*, gd::string, int&, UnlockType&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x301aa4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key, id, type);
}

auto GameManager::groundHasSecondaryColor(int index) -> decltype(groundHasSecondaryColor(index)) {
	using FunctionType = decltype(groundHasSecondaryColor(index))(*)(GameManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30b43c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index);
}

auto GameManager::iconAndTypeForKey(int key, int& id, int& type) -> decltype(iconAndTypeForKey(key, id, type)) {
	using FunctionType = decltype(iconAndTypeForKey(key, id, type))(*)(GameManager*, int, int&, int&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x309a4c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key, id, type);
}

auto GameManager::iconKey(int id, IconType type) -> decltype(iconKey(id, type)) {
	using FunctionType = decltype(iconKey(id, type))(*)(GameManager*, int, IconType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x301028, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, type);
}

auto GameManager::iconTypeToUnlockType(IconType type) -> decltype(iconTypeToUnlockType(type)) {
	using FunctionType = decltype(iconTypeToUnlockType(type))(*)(GameManager*, IconType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3014ac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type);
}

auto GameManager::isColorUnlocked(int id, UnlockType type) -> decltype(isColorUnlocked(id, type)) {
	using FunctionType = decltype(isColorUnlocked(id, type))(*)(GameManager*, int, UnlockType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3018b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, type);
}

auto GameManager::isIconLoaded(int id, int type) -> decltype(isIconLoaded(id, type)) {
	using FunctionType = decltype(isIconLoaded(id, type))(*)(GameManager*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x308d60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, type);
}

auto GameManager::isIconUnlocked(int id, IconType type) -> decltype(isIconUnlocked(id, type)) {
	using FunctionType = decltype(isIconUnlocked(id, type))(*)(GameManager*, int, IconType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x301398, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, type);
}

auto GameManager::itemPurchased(char const* key) -> decltype(itemPurchased(key)) {
	using FunctionType = decltype(itemPurchased(key))(*)(GameManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x307af8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GameManager::joinDiscord() -> decltype(joinDiscord()) {
	using FunctionType = decltype(joinDiscord())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30892c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::joinReddit() -> decltype(joinReddit()) {
	using FunctionType = decltype(joinReddit())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3089ac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::keyForIcon(int id, int type) -> decltype(keyForIcon(id, type)) {
	using FunctionType = decltype(keyForIcon(id, type))(*)(GameManager*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x308e34, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, type);
}

auto GameManager::levelIsPremium(int unk1, int unk2) -> decltype(levelIsPremium(unk1, unk2)) {
	using FunctionType = decltype(levelIsPremium(unk1, unk2))(*)(GameManager*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x307afc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, unk1, unk2);
}

auto GameManager::likeFacebook() -> decltype(likeFacebook()) {
	using FunctionType = decltype(likeFacebook())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30872c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::loadBackground(int index) -> decltype(loadBackground(index)) {
	using FunctionType = decltype(loadBackground(index))(*)(GameManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30af28, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index);
}

auto GameManager::loadBackgroundAsync(int index) -> decltype(loadBackgroundAsync(index)) {
	using FunctionType = decltype(loadBackgroundAsync(index))(*)(GameManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30afcc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index);
}

auto GameManager::loadDeathEffect(int id) -> decltype(loadDeathEffect(id)) {
	using FunctionType = decltype(loadDeathEffect(id))(*)(GameManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30ada8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameManager::loadDpadFromString(UIButtonConfig& config, gd::string str) -> decltype(loadDpadFromString(config, str)) {
	using FunctionType = decltype(loadDpadFromString(config, str))(*)(GameManager*, UIButtonConfig&, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30f7ec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, config, str);
}

auto GameManager::loadDPadLayout(int index, bool dual) -> decltype(loadDPadLayout(index, dual)) {
	using FunctionType = decltype(loadDPadLayout(index, dual))(*)(GameManager*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30f3e8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index, dual);
}

auto GameManager::loadFont(int index) -> decltype(loadFont(index)) {
	using FunctionType = decltype(loadFont(index))(*)(GameManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30ac24, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index);
}

auto GameManager::loadGround(int index) -> decltype(loadGround(index)) {
	using FunctionType = decltype(loadGround(index))(*)(GameManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30b44c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index);
}

auto GameManager::loadGroundAsync(int index) -> decltype(loadGroundAsync(index)) {
	using FunctionType = decltype(loadGroundAsync(index))(*)(GameManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30b560, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index);
}

auto GameManager::loadIcon(int id, int type, int requestID) -> decltype(loadIcon(id, type, requestID)) {
	using FunctionType = decltype(loadIcon(id, type, requestID))(*)(GameManager*, int, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x309b04, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, type, requestID);
}

auto GameManager::loadIconAsync(int id, int type, int requestID, cocos2d::CCObject* delegate) -> decltype(loadIconAsync(id, type, requestID, delegate)) {
	using FunctionType = decltype(loadIconAsync(id, type, requestID, delegate))(*)(GameManager*, int, int, int, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x308e48, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, type, requestID, delegate);
}

auto GameManager::loadMiddleground(int index) -> decltype(loadMiddleground(index)) {
	using FunctionType = decltype(loadMiddleground(index))(*)(GameManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30b114, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index);
}

auto GameManager::loadMiddlegroundAsync(int index) -> decltype(loadMiddlegroundAsync(index)) {
	using FunctionType = decltype(loadMiddlegroundAsync(index))(*)(GameManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30b214, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index);
}

auto GameManager::loadVideoSettings() -> decltype(loadVideoSettings()) {
	using FunctionType = decltype(loadVideoSettings())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x310138, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::lockColor(int id, UnlockType type) -> decltype(lockColor(id, type)) {
	using FunctionType = decltype(lockColor(id, type))(*)(GameManager*, int, UnlockType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x301a30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, type);
}

auto GameManager::lockIcon(int id, IconType type) -> decltype(lockIcon(id, type)) {
	using FunctionType = decltype(lockIcon(id, type))(*)(GameManager*, int, IconType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30160c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, type);
}

auto GameManager::logLoadedIconInfo() -> decltype(logLoadedIconInfo()) {
	using FunctionType = decltype(logLoadedIconInfo())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30ab44, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::openEditorGuide() -> decltype(openEditorGuide()) {
	using FunctionType = decltype(openEditorGuide())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x308a2c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::playMenuMusic() -> decltype(playMenuMusic()) {
	using FunctionType = decltype(playMenuMusic())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3006c4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::playSFXTrigger(SFXTriggerGameObject* object) -> decltype(playSFXTrigger(object)) {
	using FunctionType = decltype(playSFXTrigger(object))(*)(GameManager*, SFXTriggerGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x300c70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GameManager::prepareDPadSettings() -> decltype(prepareDPadSettings()) {
	using FunctionType = decltype(prepareDPadSettings())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30fb2c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::printGJLog() -> decltype(printGJLog()) {
	using FunctionType = decltype(printGJLog())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30e28c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::queueReloadMenu() -> decltype(queueReloadMenu()) {
	using FunctionType = decltype(queueReloadMenu())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x31316c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::rateGame() -> decltype(rateGame()) {
	using FunctionType = decltype(rateGame())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3086f8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::recountUserStats(gd::string str) -> decltype(recountUserStats(str)) {
	using FunctionType = decltype(recountUserStats(str))(*)(GameManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30d280, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, str);
}

auto GameManager::reloadAll(bool switchingModes, bool toFullscreen, bool borderless, bool fix, bool unused) -> decltype(reloadAll(switchingModes, toFullscreen, borderless, fix, unused)) {
	using FunctionType = decltype(reloadAll(switchingModes, toFullscreen, borderless, fix, unused))(*)(GameManager*, bool, bool, bool, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3132b4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, switchingModes, toFullscreen, borderless, fix, unused);
}

auto GameManager::reloadAllStep2() -> decltype(reloadAllStep2()) {
	using FunctionType = decltype(reloadAllStep2())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x313358, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::reloadAllStep3() -> decltype(reloadAllStep3()) {
	using FunctionType = decltype(reloadAllStep3())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x313444, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::reloadAllStep4() -> decltype(reloadAllStep4()) {
	using FunctionType = decltype(reloadAllStep4())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3134cc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::reloadAllStep5() -> decltype(reloadAllStep5()) {
	using FunctionType = decltype(reloadAllStep5())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x313538, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::reloadMenu() -> decltype(reloadMenu()) {
	using FunctionType = decltype(reloadMenu())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3131e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::removeCustomObject(int key) -> decltype(removeCustomObject(key)) {
	using FunctionType = decltype(removeCustomObject(key))(*)(GameManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30ca14, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GameManager::removeIconDelegate(int requestID) -> decltype(removeIconDelegate(requestID)) {
	using FunctionType = decltype(removeIconDelegate(requestID))(*)(GameManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30a7b8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, requestID);
}

auto GameManager::reorderKey(int index, bool up) -> decltype(reorderKey(index, up)) {
	using FunctionType = decltype(reorderKey(index, up))(*)(GameManager*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30c6b8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index, up);
}

auto GameManager::reportAchievementWithID(char const* key, int percent, bool dontNotify) -> decltype(reportAchievementWithID(key, percent, dontNotify)) {
	using FunctionType = decltype(reportAchievementWithID(key, percent, dontNotify))(*)(GameManager*, char const*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x303214, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key, percent, dontNotify);
}

auto GameManager::reportPercentageForLevel(int levelID, int percentage, bool isPlatformer) -> decltype(reportPercentageForLevel(levelID, percentage, isPlatformer)) {
	using FunctionType = decltype(reportPercentageForLevel(levelID, percentage, isPlatformer))(*)(GameManager*, int, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30288c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, levelID, percentage, isPlatformer);
}

auto GameManager::resetAchievement(gd::string key) -> decltype(resetAchievement(key)) {
	using FunctionType = decltype(resetAchievement(key))(*)(GameManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3026ec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GameManager::resetAdTimer() -> decltype(resetAdTimer()) {
	using FunctionType = decltype(resetAdTimer())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x307ff8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::resetAllIcons() -> decltype(resetAllIcons()) {
	using FunctionType = decltype(resetAllIcons())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30cb30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::resetCoinUnlocks() -> decltype(resetCoinUnlocks()) {
	using FunctionType = decltype(resetCoinUnlocks())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3064f8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::resetDPadSettings(bool dual) -> decltype(resetDPadSettings(dual)) {
	using FunctionType = decltype(resetDPadSettings(dual))(*)(GameManager*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30fe98, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dual);
}

auto GameManager::resolutionForKey(int key) -> decltype(resolutionForKey(key)) {
	using FunctionType = decltype(resolutionForKey(key))(*)(GameManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x31358c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GameManager::resumeAudio() -> decltype(resumeAudio()) {
	using FunctionType = decltype(resumeAudio())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x308228, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::resumeAudioDelayed() -> decltype(resumeAudioDelayed()) {
	using FunctionType = decltype(resumeAudioDelayed())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3081a4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::returnToLastScene(GJGameLevel* level) -> decltype(returnToLastScene(level)) {
	using FunctionType = decltype(returnToLastScene(level))(*)(GameManager*, GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x312dd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, level);
}

auto GameManager::rewardedVideoAdFinished(int unused) -> decltype(rewardedVideoAdFinished(unused)) {
	using FunctionType = decltype(rewardedVideoAdFinished(unused))(*)(GameManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3082c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, unused);
}

auto GameManager::rewardedVideoHidden() -> decltype(rewardedVideoHidden()) {
	using FunctionType = decltype(rewardedVideoHidden())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x308404, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::rewardedVideoHiddenDelayed() -> decltype(rewardedVideoHiddenDelayed()) {
	using FunctionType = decltype(rewardedVideoHiddenDelayed())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x308380, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::safePopScene() -> decltype(safePopScene()) {
	using FunctionType = decltype(safePopScene())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x31310c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::saveAdTimer() -> decltype(saveAdTimer()) {
	using FunctionType = decltype(saveAdTimer())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x308014, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::saveDPadLayout(int index, bool dual) -> decltype(saveDPadLayout(index, dual)) {
	using FunctionType = decltype(saveDPadLayout(index, dual))(*)(GameManager*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30e298, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index, dual);
}

auto GameManager::setGameVariable(char const* key, bool value) -> decltype(setGameVariable(key, value)) {
	using FunctionType = decltype(setGameVariable(key, value))(*)(GameManager*, char const*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30b880, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key, value);
}

auto GameManager::setIntGameVariable(char const* key, int value) -> decltype(setIntGameVariable(key, value)) {
	using FunctionType = decltype(setIntGameVariable(key, value))(*)(GameManager*, char const*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30bf1c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key, value);
}

auto GameManager::setUGV(char const* key, bool value) -> decltype(setUGV(key, value)) {
	using FunctionType = decltype(setUGV(key, value))(*)(GameManager*, char const*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30bbd4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key, value);
}

auto GameManager::setupGameAnimations() -> decltype(setupGameAnimations()) {
	using FunctionType = decltype(setupGameAnimations())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x203598, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::sheetNameForIcon(int id, int type) -> decltype(sheetNameForIcon(id, type)) {
	using FunctionType = decltype(sheetNameForIcon(id, type))(*)(GameManager*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x309110, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, type);
}

auto GameManager::shortenAdTimer(float time) -> decltype(shortenAdTimer(time)) {
	using FunctionType = decltype(shortenAdTimer(time))(*)(GameManager*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x308000, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, time);
}

auto GameManager::shouldShowInterstitial(int unk1, int unk2, int unk3) -> decltype(shouldShowInterstitial(unk1, unk2, unk3)) {
	using FunctionType = decltype(shouldShowInterstitial(unk1, unk2, unk3))(*)(GameManager*, int, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x308070, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, unk1, unk2, unk3);
}

auto GameManager::showInterstitial() -> decltype(showInterstitial()) {
	using FunctionType = decltype(showInterstitial())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x308078, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::showInterstitialForced() -> decltype(showInterstitialForced()) {
	using FunctionType = decltype(showInterstitialForced())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x308124, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::showMainMenuAd() -> decltype(showMainMenuAd()) {
	using FunctionType = decltype(showMainMenuAd())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x307ff0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::startUpdate() -> decltype(startUpdate()) {
	using FunctionType = decltype(startUpdate())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3003a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::stringForCustomObject(int customObjectID) -> decltype(stringForCustomObject(customObjectID)) {
	using FunctionType = decltype(stringForCustomObject(customObjectID))(*)(GameManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30c530, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, customObjectID);
}

auto GameManager::subYouTube() -> decltype(subYouTube()) {
	using FunctionType = decltype(subYouTube())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30882c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::switchCustomObjects(int key1, int key2) -> decltype(switchCustomObjects(key1, key2)) {
	using FunctionType = decltype(switchCustomObjects(key1, key2))(*)(GameManager*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30c704, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key1, key2);
}

auto GameManager::switchScreenMode(bool fullscreen, bool borderless, bool fix, bool unused) -> decltype(switchScreenMode(fullscreen, borderless, fix, unused)) {
	using FunctionType = decltype(switchScreenMode(fullscreen, borderless, fix, unused))(*)(GameManager*, bool, bool, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x313210, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, fullscreen, borderless, fix, unused);
}

auto GameManager::syncPlatformAchievements() -> decltype(syncPlatformAchievements()) {
	using FunctionType = decltype(syncPlatformAchievements())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x308a58, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::toggleGameVariable(char const* key) -> decltype(toggleGameVariable(key)) {
	using FunctionType = decltype(toggleGameVariable(key))(*)(GameManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30baf0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GameManager::tryCacheAd() -> decltype(tryCacheAd()) {
	using FunctionType = decltype(tryCacheAd())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x308080, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::tryShowInterstitial(int unk1, int unk2, int unk3) -> decltype(tryShowInterstitial(unk1, unk2, unk3)) {
	using FunctionType = decltype(tryShowInterstitial(unk1, unk2, unk3))(*)(GameManager*, int, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30806c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, unk1, unk2, unk3);
}

auto GameManager::unloadBackground() -> decltype(unloadBackground()) {
	using FunctionType = decltype(unloadBackground())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30ae90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::unloadIcon(int id, int type, int requestID) -> decltype(unloadIcon(id, type, requestID)) {
	using FunctionType = decltype(unloadIcon(id, type, requestID))(*)(GameManager*, int, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30a158, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, type, requestID);
}

auto GameManager::unloadIcons(int requestID) -> decltype(unloadIcons(requestID)) {
	using FunctionType = decltype(unloadIcons(requestID))(*)(GameManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30a8ac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, requestID);
}

auto GameManager::unlockColor(int id, UnlockType type) -> decltype(unlockColor(id, type)) {
	using FunctionType = decltype(unlockColor(id, type))(*)(GameManager*, int, UnlockType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x301984, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, type);
}

auto GameManager::unlockedPremium() -> decltype(unlockedPremium()) {
	using FunctionType = decltype(unlockedPremium())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x307af4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::unlockIcon(int id, IconType type) -> decltype(unlockIcon(id, type)) {
	using FunctionType = decltype(unlockIcon(id, type))(*)(GameManager*, int, IconType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x301560, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, type);
}

auto GameManager::unlockTypeToIconType(int type) -> decltype(unlockTypeToIconType(type)) {
	using FunctionType = decltype(unlockTypeToIconType(type))(*)(GameManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30153c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type);
}

auto GameManager::updateCustomFPS() -> decltype(updateCustomFPS()) {
	using FunctionType = decltype(updateCustomFPS())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x313840, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::updateMusic() -> decltype(updateMusic()) {
	using FunctionType = decltype(updateMusic())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3086b4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::verifyAchievementUnlocks() -> decltype(verifyAchievementUnlocks()) {
	using FunctionType = decltype(verifyAchievementUnlocks())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x303458, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::verifyCoinUnlocks() -> decltype(verifyCoinUnlocks()) {
	using FunctionType = decltype(verifyCoinUnlocks())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x303664, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::verifyStarUnlocks() -> decltype(verifyStarUnlocks()) {
	using FunctionType = decltype(verifyStarUnlocks())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x303604, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::verifySyncedCoins() -> decltype(verifySyncedCoins()) {
	using FunctionType = decltype(verifySyncedCoins())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30777c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::videoAdHidden() -> decltype(videoAdHidden()) {
	using FunctionType = decltype(videoAdHidden())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x308170, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameManager::videoAdShowed() -> decltype(videoAdShowed()) {
	using FunctionType = decltype(videoAdShowed())(*)(GameManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x30812c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
