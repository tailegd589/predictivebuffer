
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GameStatsManager.hpp>
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

auto GameStatsManager::sharedState() -> decltype(sharedState()) {
	using FunctionType = decltype(sharedState())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x59fb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto GameStatsManager::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GameStatsManager::init), this);
	using FunctionType = decltype(init())(*)(GameStatsManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5a490, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GameStatsManager::accountIDForIcon(int id, UnlockType type) -> decltype(accountIDForIcon(id, type)) {
	using FunctionType = decltype(accountIDForIcon(id, type))(*)(GameStatsManager*, int, UnlockType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x32b630, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, type);
}

auto GameStatsManager::addSimpleSpecialChestReward(gd::string key, UnlockType type, int id, bool unused) -> decltype(addSimpleSpecialChestReward(key, type, id, unused)) {
	using FunctionType = decltype(addSimpleSpecialChestReward(key, type, id, unused))(*)(GameStatsManager*, gd::string, UnlockType, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x77e00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key, type, id, unused);
}

auto GameStatsManager::addSpecialRewardDescription(gd::string key, gd::string description) -> decltype(addSpecialRewardDescription(key, description)) {
	using FunctionType = decltype(addSpecialRewardDescription(key, description))(*)(GameStatsManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x77dc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key, description);
}

auto GameStatsManager::addStoreItem(int index, int id, int unlockType, int price, ShopType shopType) -> decltype(addStoreItem(index, id, unlockType, price, shopType)) {
	using FunctionType = decltype(addStoreItem(index, id, unlockType, price, shopType))(*)(GameStatsManager*, int, int, int, int, ShopType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x667b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index, id, unlockType, price, shopType);
}

auto GameStatsManager::areChallengesLoaded() -> decltype(areChallengesLoaded()) {
	using FunctionType = decltype(areChallengesLoaded())(*)(GameStatsManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x72dd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameStatsManager::areRewardsLoaded() -> decltype(areRewardsLoaded()) {
	using FunctionType = decltype(areRewardsLoaded())(*)(GameStatsManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x722f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameStatsManager::awardCurrencyForLevel(GJGameLevel* level) -> decltype(awardCurrencyForLevel(level)) {
	using FunctionType = decltype(awardCurrencyForLevel(level))(*)(GameStatsManager*, GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x71090, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, level);
}

auto GameStatsManager::awardDiamondsForLevel(GJGameLevel* level) -> decltype(awardDiamondsForLevel(level)) {
	using FunctionType = decltype(awardDiamondsForLevel(level))(*)(GameStatsManager*, GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x71810, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, level);
}

auto GameStatsManager::awardOldSpecialStats() -> decltype(awardOldSpecialStats()) {
	using FunctionType = decltype(awardOldSpecialStats())(*)(GameStatsManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x75be0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameStatsManager::awardSecretKey() -> decltype(awardSecretKey()) {
	using FunctionType = decltype(awardSecretKey())(*)(GameStatsManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x8c5a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameStatsManager::canItemBeUnlocked(int id, UnlockType type) -> decltype(canItemBeUnlocked(id, type)) {
	using FunctionType = decltype(canItemBeUnlocked(id, type))(*)(GameStatsManager*, int, UnlockType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x77880, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, type);
}

auto GameStatsManager::checkAchievement(char const* statKey) -> decltype(checkAchievement(statKey)) {
	using FunctionType = decltype(checkAchievement(statKey))(*)(GameStatsManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x673f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, statKey);
}

auto GameStatsManager::checkCoinAchievement(GJGameLevel* level) -> decltype(checkCoinAchievement(level)) {
	using FunctionType = decltype(checkCoinAchievement(level))(*)(GameStatsManager*, GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cdf0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, level);
}

auto GameStatsManager::checkCoinsForLevel(GJGameLevel* level) -> decltype(checkCoinsForLevel(level)) {
	using FunctionType = decltype(checkCoinsForLevel(level))(*)(GameStatsManager*, GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6fe40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, level);
}

auto GameStatsManager::claimListReward(GJLevelList* list) -> decltype(claimListReward(list)) {
	using FunctionType = decltype(claimListReward(list))(*)(GameStatsManager*, GJLevelList*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x73c90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, list);
}

auto GameStatsManager::collectReward(GJRewardType type, GJRewardItem* item) -> decltype(collectReward(type, item)) {
	using FunctionType = decltype(collectReward(type, item))(*)(GameStatsManager*, GJRewardType, GJRewardItem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x72610, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type, item);
}

auto GameStatsManager::collectVideoReward(int orbs) -> decltype(collectVideoReward(orbs)) {
	using FunctionType = decltype(collectVideoReward(orbs))(*)(GameStatsManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x8c660, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, orbs);
}

auto GameStatsManager::completedChallenge(GJChallengeItem* item) -> decltype(completedChallenge(item)) {
	using FunctionType = decltype(completedChallenge(item))(*)(GameStatsManager*, GJChallengeItem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x738f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, item);
}

auto GameStatsManager::completedDailyLevel(GJGameLevel* level) -> decltype(completedDailyLevel(level)) {
	using FunctionType = decltype(completedDailyLevel(level))(*)(GameStatsManager*, GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x74130, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, level);
}

auto GameStatsManager::completedDemonLevel(GJGameLevel* level) -> decltype(completedDemonLevel(level)) {
	using FunctionType = decltype(completedDemonLevel(level))(*)(GameStatsManager*, GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6dcf0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, level);
}

auto GameStatsManager::completedLevel(GJGameLevel* level) -> decltype(completedLevel(level)) {
	using FunctionType = decltype(completedLevel(level))(*)(GameStatsManager*, GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6dbb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, level);
}

auto GameStatsManager::completedMapPack(GJMapPack* pack) -> decltype(completedMapPack(pack)) {
	using FunctionType = decltype(completedMapPack(pack))(*)(GameStatsManager*, GJMapPack*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6e6c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, pack);
}

auto GameStatsManager::completedStarLevel(GJGameLevel* level) -> decltype(completedStarLevel(level)) {
	using FunctionType = decltype(completedStarLevel(level))(*)(GameStatsManager*, GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6de90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, level);
}

auto GameStatsManager::countSecretChests(GJRewardType rewardType) -> decltype(countSecretChests(rewardType)) {
	using FunctionType = decltype(countSecretChests(rewardType))(*)(GameStatsManager*, GJRewardType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x8c440, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, rewardType);
}

auto GameStatsManager::countUnlockedSecretChests(GJRewardType rewardType) -> decltype(countUnlockedSecretChests(rewardType)) {
	using FunctionType = decltype(countUnlockedSecretChests(rewardType))(*)(GameStatsManager*, GJRewardType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x8c490, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, rewardType);
}

auto GameStatsManager::createReward(GJRewardType type, int id, gd::string str) -> decltype(createReward(type, id, str)) {
	using FunctionType = decltype(createReward(type, id, str))(*)(GameStatsManager*, GJRewardType, int, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x71cc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type, id, str);
}

auto GameStatsManager::createSecretChestItems() -> decltype(createSecretChestItems()) {
	using FunctionType = decltype(createSecretChestItems())(*)(GameStatsManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5cbd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameStatsManager::createSecretChestRewards() -> decltype(createSecretChestRewards()) {
	using FunctionType = decltype(createSecretChestRewards())(*)(GameStatsManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x78dc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameStatsManager::createSpecialChestItems() -> decltype(createSpecialChestItems()) {
	using FunctionType = decltype(createSpecialChestItems())(*)(GameStatsManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5cd20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameStatsManager::createStoreItems() -> decltype(createStoreItems()) {
	using FunctionType = decltype(createStoreItems())(*)(GameStatsManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5a540, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameStatsManager::dataLoaded(DS_Dictionary* dict) -> decltype(dataLoaded(dict)) {
	using FunctionType = decltype(dataLoaded(dict))(*)(GameStatsManager*, DS_Dictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x8d470, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dict);
}

auto GameStatsManager::encodeDataTo(DS_Dictionary* dict) -> decltype(encodeDataTo(dict)) {
	using FunctionType = decltype(encodeDataTo(dict))(*)(GameStatsManager*, DS_Dictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x8cf50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dict);
}

auto GameStatsManager::firstSetup() -> decltype(firstSetup()) {
	using FunctionType = decltype(firstSetup())(*)(GameStatsManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x8c7c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameStatsManager::generateItemUnlockableData() -> decltype(generateItemUnlockableData()) {
	using FunctionType = decltype(generateItemUnlockableData())(*)(GameStatsManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x65890, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameStatsManager::getAwardedCurrencyForLevel(GJGameLevel* level) -> decltype(getAwardedCurrencyForLevel(level)) {
	using FunctionType = decltype(getAwardedCurrencyForLevel(level))(*)(GameStatsManager*, GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x70ec0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, level);
}

auto GameStatsManager::getAwardedDiamondsForLevel(GJGameLevel* level) -> decltype(getAwardedDiamondsForLevel(level)) {
	using FunctionType = decltype(getAwardedDiamondsForLevel(level))(*)(GameStatsManager*, GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x71650, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, level);
}

auto GameStatsManager::getBaseCurrency(int stars, bool mainLevel, int levelID) -> decltype(getBaseCurrency(stars, mainLevel, levelID)) {
	using FunctionType = decltype(getBaseCurrency(stars, mainLevel, levelID))(*)(GameStatsManager*, int, bool, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x70c90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, stars, mainLevel, levelID);
}

auto GameStatsManager::getBaseCurrencyForLevel(GJGameLevel* level) -> decltype(getBaseCurrencyForLevel(level)) {
	using FunctionType = decltype(getBaseCurrencyForLevel(level))(*)(GameStatsManager*, GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x70ce0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, level);
}

auto GameStatsManager::getBaseDiamonds(int stars) -> decltype(getBaseDiamonds(stars)) {
	using FunctionType = decltype(getBaseDiamonds(stars))(*)(GameStatsManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x715f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, stars);
}

auto GameStatsManager::getBonusDiamonds(int stars) -> decltype(getBonusDiamonds(stars)) {
	using FunctionType = decltype(getBonusDiamonds(stars))(*)(GameStatsManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x71610, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, stars);
}

auto GameStatsManager::getChallenge(int id) -> decltype(getChallenge(id)) {
	using FunctionType = decltype(getChallenge(id))(*)(GameStatsManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x733d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameStatsManager::getChallengeKey(GJChallengeItem* chal) -> decltype(getChallengeKey(chal)) {
	using FunctionType = decltype(getChallengeKey(chal))(*)(GameStatsManager*, GJChallengeItem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x73730, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, chal);
}

auto GameStatsManager::getCollectedCoinsForLevel(GJGameLevel* level) -> decltype(getCollectedCoinsForLevel(level)) {
	using FunctionType = decltype(getCollectedCoinsForLevel(level))(*)(GameStatsManager*, GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6d260, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, level);
}

auto GameStatsManager::getCompletedMapPacks() -> decltype(getCompletedMapPacks()) {
	using FunctionType = decltype(getCompletedMapPacks())(*)(GameStatsManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6eb80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameStatsManager::getCurrencyKey(GJGameLevel* level) -> decltype(getCurrencyKey(level)) {
	using FunctionType = decltype(getCurrencyKey(level))(*)(GameStatsManager*, GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x70bc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, level);
}

auto GameStatsManager::getDailyLevelKey(int dailyID) -> decltype(getDailyLevelKey(dailyID)) {
	using FunctionType = decltype(getDailyLevelKey(dailyID))(*)(GameStatsManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x73f40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dailyID);
}

auto GameStatsManager::getDemonLevelKey(GJGameLevel* level) -> decltype(getDemonLevelKey(level)) {
	using FunctionType = decltype(getDemonLevelKey(level))(*)(GameStatsManager*, GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6d660, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, level);
}

auto GameStatsManager::getEventRewardKey(int id) -> decltype(getEventRewardKey(id)) {
	using FunctionType = decltype(getEventRewardKey(id))(*)(GameStatsManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x789e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameStatsManager::getGauntletRewardKey(int id) -> decltype(getGauntletRewardKey(id)) {
	using FunctionType = decltype(getGauntletRewardKey(id))(*)(GameStatsManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x77be0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameStatsManager::getItemKey(int id, int type) -> decltype(getItemKey(id, type)) {
	using FunctionType = decltype(getItemKey(id, type))(*)(GameStatsManager*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x66520, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, type);
}

auto GameStatsManager::getItemUnlockState(int itemID, UnlockType unlockType) -> decltype(getItemUnlockState(itemID, unlockType)) {
	using FunctionType = decltype(getItemUnlockState(itemID, unlockType))(*)(GameStatsManager*, int, UnlockType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x77500, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, itemID, unlockType);
}

auto GameStatsManager::getItemUnlockStateLite(int id, UnlockType type) -> decltype(getItemUnlockStateLite(id, type)) {
	using FunctionType = decltype(getItemUnlockStateLite(id, type))(*)(GameStatsManager*, int, UnlockType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x775c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, type);
}

auto GameStatsManager::getLevelKey(GJGameLevel* level) -> decltype(getLevelKey(level)) {
	using FunctionType = decltype(getLevelKey(level))(*)(GameStatsManager*, GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6d3e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, level);
}

auto GameStatsManager::getLevelKey(int levelID, bool isOnline, bool isDaily, bool isGauntlet, bool isEvent) -> decltype(getLevelKey(levelID, isOnline, isDaily, isGauntlet, isEvent)) {
	using FunctionType = decltype(getLevelKey(levelID, isOnline, isDaily, isGauntlet, isEvent))(*)(GameStatsManager*, int, bool, bool, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6d450, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, levelID, isOnline, isDaily, isGauntlet, isEvent);
}

auto GameStatsManager::getListRewardKey(GJLevelList* list) -> decltype(getListRewardKey(list)) {
	using FunctionType = decltype(getListRewardKey(list))(*)(GameStatsManager*, GJLevelList*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x73ad0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, list);
}

auto GameStatsManager::getMapPackKey(int id) -> decltype(getMapPackKey(id)) {
	using FunctionType = decltype(getMapPackKey(id))(*)(GameStatsManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6e6a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameStatsManager::getNextGoldChestID() -> decltype(getNextGoldChestID()) {
	using FunctionType = decltype(getNextGoldChestID())(*)(GameStatsManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x8beb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameStatsManager::getNextVideoAdReward() -> decltype(getNextVideoAdReward()) {
	using FunctionType = decltype(getNextVideoAdReward())(*)(GameStatsManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x781a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameStatsManager::getPathRewardKey(int id) -> decltype(getPathRewardKey(id)) {
	using FunctionType = decltype(getPathRewardKey(id))(*)(GameStatsManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6c990, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameStatsManager::getQueuedChallenge(int id) -> decltype(getQueuedChallenge(id)) {
	using FunctionType = decltype(getQueuedChallenge(id))(*)(GameStatsManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x734d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameStatsManager::getRewardForSecretChest(int id) -> decltype(getRewardForSecretChest(id)) {
	using FunctionType = decltype(getRewardForSecretChest(id))(*)(GameStatsManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x8c2b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameStatsManager::getRewardForSpecialChest(gd::string key) -> decltype(getRewardForSpecialChest(key)) {
	using FunctionType = decltype(getRewardForSpecialChest(key))(*)(GameStatsManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x784a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GameStatsManager::getRewardItem(GJRewardType type) -> decltype(getRewardItem(type)) {
	using FunctionType = decltype(getRewardItem(type))(*)(GameStatsManager*, GJRewardType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x722d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type);
}

auto GameStatsManager::getRewardKey(GJRewardType type, int id) -> decltype(getRewardKey(type, id)) {
	using FunctionType = decltype(getRewardKey(type, id))(*)(GameStatsManager*, GJRewardType, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x72310, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type, id);
}

auto GameStatsManager::getSecondaryQueuedChallenge(int id) -> decltype(getSecondaryQueuedChallenge(id)) {
	using FunctionType = decltype(getSecondaryQueuedChallenge(id))(*)(GameStatsManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x735d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameStatsManager::getSecretChestForItem(int id, UnlockType type) -> decltype(getSecretChestForItem(id, type)) {
	using FunctionType = decltype(getSecretChestForItem(id, type))(*)(GameStatsManager*, int, UnlockType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x66440, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, type);
}

auto GameStatsManager::getSecretCoinKey(char const* key) -> decltype(getSecretCoinKey(key)) {
	using FunctionType = decltype(getSecretCoinKey(key))(*)(GameStatsManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x70520, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GameStatsManager::getSecretOnlineRewardKey(int id) -> decltype(getSecretOnlineRewardKey(id)) {
	using FunctionType = decltype(getSecretOnlineRewardKey(id))(*)(GameStatsManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x78bd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameStatsManager::getSpecialChestKeyForItem(int id, UnlockType type) -> decltype(getSpecialChestKeyForItem(id, type)) {
	using FunctionType = decltype(getSpecialChestKeyForItem(id, type))(*)(GameStatsManager*, int, UnlockType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x664b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, type);
}

auto GameStatsManager::getSpecialRewardDescription(gd::string key, bool unused) -> decltype(getSpecialRewardDescription(key, unused)) {
	using FunctionType = decltype(getSpecialRewardDescription(key, unused))(*)(GameStatsManager*, gd::string, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x78020, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key, unused);
}

auto GameStatsManager::getSpecialUnlockDescription(int id, UnlockType type, bool unused) -> decltype(getSpecialUnlockDescription(id, type, unused)) {
	using FunctionType = decltype(getSpecialUnlockDescription(id, type, unused))(*)(GameStatsManager*, int, UnlockType, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x78080, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, type, unused);
}

auto GameStatsManager::getStarLevelKey(GJGameLevel* level) -> decltype(getStarLevelKey(level)) {
	using FunctionType = decltype(getStarLevelKey(level))(*)(GameStatsManager*, GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6d6c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, level);
}

auto GameStatsManager::getStat(char const* key) -> decltype(getStat(key)) {
	using FunctionType = decltype(getStat(key))(*)(GameStatsManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x66ce0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GameStatsManager::getStatFromKey(StatKey key) -> decltype(getStatFromKey(key)) {
	using FunctionType = decltype(getStatFromKey(key))(*)(GameStatsManager*, StatKey);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6c920, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GameStatsManager::getStoreItem(int index) -> decltype(getStoreItem(index)) {
	using FunctionType = decltype(getStoreItem(index))(*)(GameStatsManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x669a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index);
}

auto GameStatsManager::getStoreItem(int id, int type) -> decltype(getStoreItem(id, type)) {
	using FunctionType = decltype(getStoreItem(id, type))(*)(GameStatsManager*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x663d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, type);
}

auto GameStatsManager::getTotalCollectedCurrency() -> decltype(getTotalCollectedCurrency()) {
	using FunctionType = decltype(getTotalCollectedCurrency())(*)(GameStatsManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x74900, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameStatsManager::getTotalCollectedDiamonds() -> decltype(getTotalCollectedDiamonds()) {
	using FunctionType = decltype(getTotalCollectedDiamonds())(*)(GameStatsManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x75660, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameStatsManager::hasClaimedListReward(GJLevelList* list) -> decltype(hasClaimedListReward(list)) {
	using FunctionType = decltype(hasClaimedListReward(list))(*)(GameStatsManager*, GJLevelList*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x73b90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, list);
}

auto GameStatsManager::hasCompletedChallenge(GJChallengeItem* item) -> decltype(hasCompletedChallenge(item)) {
	using FunctionType = decltype(hasCompletedChallenge(item))(*)(GameStatsManager*, GJChallengeItem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x737f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, item);
}

auto GameStatsManager::hasCompletedDailyLevel(int dailyID) -> decltype(hasCompletedDailyLevel(dailyID)) {
	using FunctionType = decltype(hasCompletedDailyLevel(dailyID))(*)(GameStatsManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x74000, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dailyID);
}

auto GameStatsManager::hasCompletedDemonLevel(GJGameLevel* level) -> decltype(hasCompletedDemonLevel(level)) {
	using FunctionType = decltype(hasCompletedDemonLevel(level))(*)(GameStatsManager*, GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6d950, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, level);
}

auto GameStatsManager::hasCompletedGauntletLevel(int id) -> decltype(hasCompletedGauntletLevel(id)) {
	using FunctionType = decltype(hasCompletedGauntletLevel(id))(*)(GameStatsManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6d8d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameStatsManager::hasCompletedLevel(GJGameLevel* level) -> decltype(hasCompletedLevel(level)) {
	using FunctionType = decltype(hasCompletedLevel(level))(*)(GameStatsManager*, GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6d7a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, level);
}

auto GameStatsManager::hasCompletedMainLevel(int levelID) -> decltype(hasCompletedMainLevel(levelID)) {
	using FunctionType = decltype(hasCompletedMainLevel(levelID))(*)(GameStatsManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6d720, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, levelID);
}

auto GameStatsManager::hasCompletedMapPack(int id) -> decltype(hasCompletedMapPack(id)) {
	using FunctionType = decltype(hasCompletedMapPack(id))(*)(GameStatsManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6e860, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameStatsManager::hasCompletedOnlineLevel(int id) -> decltype(hasCompletedOnlineLevel(id)) {
	using FunctionType = decltype(hasCompletedOnlineLevel(id))(*)(GameStatsManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6d850, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameStatsManager::hasCompletedStarLevel(GJGameLevel* level) -> decltype(hasCompletedStarLevel(level)) {
	using FunctionType = decltype(hasCompletedStarLevel(level))(*)(GameStatsManager*, GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6da80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, level);
}

auto GameStatsManager::hasPendingUserCoin(char const* key) -> decltype(hasPendingUserCoin(key)) {
	using FunctionType = decltype(hasPendingUserCoin(key))(*)(GameStatsManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x70180, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GameStatsManager::hasRewardBeenCollected(GJRewardType type, int id) -> decltype(hasRewardBeenCollected(type, id)) {
	using FunctionType = decltype(hasRewardBeenCollected(type, id))(*)(GameStatsManager*, GJRewardType, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x725a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type, id);
}

auto GameStatsManager::hasSecretCoin(char const* key) -> decltype(hasSecretCoin(key)) {
	using FunctionType = decltype(hasSecretCoin(key))(*)(GameStatsManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6d2e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GameStatsManager::hasUserCoin(char const* key) -> decltype(hasUserCoin(key)) {
	using FunctionType = decltype(hasUserCoin(key))(*)(GameStatsManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x70260, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GameStatsManager::incrementActivePath(int amount) -> decltype(incrementActivePath(amount)) {
	using FunctionType = decltype(incrementActivePath(amount))(*)(GameStatsManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6b900, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, amount);
}

auto GameStatsManager::incrementChallenge(GJChallengeType type, int amount) -> decltype(incrementChallenge(type, amount)) {
	using FunctionType = decltype(incrementChallenge(type, amount))(*)(GameStatsManager*, GJChallengeType, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6b6b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type, amount);
}

auto GameStatsManager::incrementStat(char const* key) -> decltype(incrementStat(key)) {
	using FunctionType = decltype(incrementStat(key))(*)(GameStatsManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x67020, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GameStatsManager::incrementStat(char const* key, int amount) -> decltype(incrementStat(key, amount)) {
	using FunctionType = decltype(incrementStat(key, amount))(*)(GameStatsManager*, char const*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x67030, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key, amount);
}

auto GameStatsManager::isGauntletChestUnlocked(int id) -> decltype(isGauntletChestUnlocked(id)) {
	using FunctionType = decltype(isGauntletChestUnlocked(id))(*)(GameStatsManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x77230, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameStatsManager::isGauntletUnlocked(int id) -> decltype(isGauntletUnlocked(id)) {
	using FunctionType = decltype(isGauntletUnlocked(id))(*)(GameStatsManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x78730, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameStatsManager::isItemEnabled(UnlockType type, int id) -> decltype(isItemEnabled(type, id)) {
	using FunctionType = decltype(isItemEnabled(type, id))(*)(GameStatsManager*, UnlockType, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x77890, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type, id);
}

auto GameStatsManager::isItemUnlocked(UnlockType type, int id) -> decltype(isItemUnlocked(type, id)) {
	using FunctionType = decltype(isItemUnlocked(type, id))(*)(GameStatsManager*, UnlockType, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6b9a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type, id);
}

auto GameStatsManager::isPathChestUnlocked(int path) -> decltype(isPathChestUnlocked(path)) {
	using FunctionType = decltype(isPathChestUnlocked(path))(*)(GameStatsManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x78820, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, path);
}

auto GameStatsManager::isPathUnlocked(StatKey key) -> decltype(isPathUnlocked(key)) {
	using FunctionType = decltype(isPathUnlocked(key))(*)(GameStatsManager*, StatKey);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6b980, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GameStatsManager::isSecretChestUnlocked(int id) -> decltype(isSecretChestUnlocked(id)) {
	using FunctionType = decltype(isSecretChestUnlocked(id))(*)(GameStatsManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x77310, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameStatsManager::isSecretCoin(gd::string key) -> decltype(isSecretCoin(key)) {
	using FunctionType = decltype(isSecretCoin(key))(*)(GameStatsManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x70650, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GameStatsManager::isSecretCoinValid(gd::string key) -> decltype(isSecretCoinValid(key)) {
	using FunctionType = decltype(isSecretCoinValid(key))(*)(GameStatsManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x70680, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GameStatsManager::isSpecialChestLiteUnlockable(gd::string key) -> decltype(isSpecialChestLiteUnlockable(key)) {
	using FunctionType = decltype(isSpecialChestLiteUnlockable(key))(*)(GameStatsManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x77860, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GameStatsManager::isSpecialChestUnlocked(gd::string key) -> decltype(isSpecialChestUnlocked(key)) {
	using FunctionType = decltype(isSpecialChestUnlocked(key))(*)(GameStatsManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x77410, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GameStatsManager::isStoreItemUnlocked(int index) -> decltype(isStoreItemUnlocked(index)) {
	using FunctionType = decltype(isStoreItemUnlocked(index))(*)(GameStatsManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x669c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index);
}

auto GameStatsManager::keyCostForSecretChest(int id) -> decltype(keyCostForSecretChest(id)) {
	using FunctionType = decltype(keyCostForSecretChest(id))(*)(GameStatsManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x76f30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameStatsManager::linkSpecialChestUnlocks(GJRewardItem* item, gd::string key) -> decltype(linkSpecialChestUnlocks(item, key)) {
	using FunctionType = decltype(linkSpecialChestUnlocks(item, key))(*)(GameStatsManager*, GJRewardItem*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x77ef0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, item, key);
}

auto GameStatsManager::logCoins() -> decltype(logCoins()) {
	using FunctionType = decltype(logCoins())(*)(GameStatsManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x8ec50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameStatsManager::markLevelAsCompletedAndClaimed(GJGameLevel* level) -> decltype(markLevelAsCompletedAndClaimed(level)) {
	using FunctionType = decltype(markLevelAsCompletedAndClaimed(level))(*)(GameStatsManager*, GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6e070, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, level);
}

auto GameStatsManager::postLoadGameStats() -> decltype(postLoadGameStats()) {
	using FunctionType = decltype(postLoadGameStats())(*)(GameStatsManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x8e7f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameStatsManager::preProcessReward(GJRewardItem* item) -> decltype(preProcessReward(item)) {
	using FunctionType = decltype(preProcessReward(item))(*)(GameStatsManager*, GJRewardItem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x727a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, item);
}

auto GameStatsManager::preSaveGameStats() -> decltype(preSaveGameStats()) {
	using FunctionType = decltype(preSaveGameStats())(*)(GameStatsManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x8d220, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameStatsManager::processChallengeQueue(int position) -> decltype(processChallengeQueue(position)) {
	using FunctionType = decltype(processChallengeQueue(position))(*)(GameStatsManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x73a50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, position);
}

auto GameStatsManager::processOnlineChests() -> decltype(processOnlineChests()) {
	using FunctionType = decltype(processOnlineChests())(*)(GameStatsManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x8ea70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameStatsManager::purchaseItem(int index) -> decltype(purchaseItem(index)) {
	using FunctionType = decltype(purchaseItem(index))(*)(GameStatsManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x66ac0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index);
}

auto GameStatsManager::recountSpecialStats() -> decltype(recountSpecialStats()) {
	using FunctionType = decltype(recountSpecialStats())(*)(GameStatsManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x75d00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameStatsManager::recountUserCoins(bool force) -> decltype(recountUserCoins(force)) {
	using FunctionType = decltype(recountUserCoins(force))(*)(GameStatsManager*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6f240, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, force);
}

auto GameStatsManager::registerRewardsFromItem(GJRewardItem* item) -> decltype(registerRewardsFromItem(item)) {
	using FunctionType = decltype(registerRewardsFromItem(item))(*)(GameStatsManager*, GJRewardItem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x726e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, item);
}

auto GameStatsManager::removeChallenge(int position) -> decltype(removeChallenge(position)) {
	using FunctionType = decltype(removeChallenge(position))(*)(GameStatsManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x72ef0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, position);
}

auto GameStatsManager::removeErrorFromSpecialChests() -> decltype(removeErrorFromSpecialChests()) {
	using FunctionType = decltype(removeErrorFromSpecialChests())(*)(GameStatsManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x76d30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameStatsManager::removeQueuedChallenge(int position) -> decltype(removeQueuedChallenge(position)) {
	using FunctionType = decltype(removeQueuedChallenge(position))(*)(GameStatsManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x730e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, position);
}

auto GameStatsManager::removeQueuedSecondaryChallenge(int position) -> decltype(removeQueuedSecondaryChallenge(position)) {
	using FunctionType = decltype(removeQueuedSecondaryChallenge(position))(*)(GameStatsManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x732e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, position);
}

auto GameStatsManager::resetChallengeTimer() -> decltype(resetChallengeTimer()) {
	using FunctionType = decltype(resetChallengeTimer())(*)(GameStatsManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x72db0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameStatsManager::resetPreSync() -> decltype(resetPreSync()) {
	using FunctionType = decltype(resetPreSync())(*)(GameStatsManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x8ec30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameStatsManager::resetSpecialChest(gd::string key) -> decltype(resetSpecialChest(key)) {
	using FunctionType = decltype(resetSpecialChest(key))(*)(GameStatsManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cb80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GameStatsManager::resetSpecialStatAchievements() -> decltype(resetSpecialStatAchievements()) {
	using FunctionType = decltype(resetSpecialStatAchievements())(*)(GameStatsManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x76f90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameStatsManager::resetUserCoins() -> decltype(resetUserCoins()) {
	using FunctionType = decltype(resetUserCoins())(*)(GameStatsManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6f200, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameStatsManager::restorePostSync() -> decltype(restorePostSync()) {
	using FunctionType = decltype(restorePostSync())(*)(GameStatsManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x8ec40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameStatsManager::setStarsForMapPack(int id, int stars) -> decltype(setStarsForMapPack(id, stars)) {
	using FunctionType = decltype(setStarsForMapPack(id, stars))(*)(GameStatsManager*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6e960, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, stars);
}

auto GameStatsManager::setStat(char const* key, int value) -> decltype(setStat(key, value)) {
	using FunctionType = decltype(setStat(key, value))(*)(GameStatsManager*, char const*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x66e40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key, value);
}

auto GameStatsManager::setStatIfHigher(char const* key, int value) -> decltype(setStatIfHigher(key, value)) {
	using FunctionType = decltype(setStatIfHigher(key, value))(*)(GameStatsManager*, char const*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cdb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key, value);
}

auto GameStatsManager::setupIconCredits() -> decltype(setupIconCredits()) {
	using FunctionType = decltype(setupIconCredits())(*)(GameStatsManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x32b730, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameStatsManager::shopTypeForItemID(int index) -> decltype(shopTypeForItemID(index)) {
	using FunctionType = decltype(shopTypeForItemID(index))(*)(GameStatsManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x66ff0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index);
}

auto GameStatsManager::shouldAwardSecretKey() -> decltype(shouldAwardSecretKey()) {
	using FunctionType = decltype(shouldAwardSecretKey())(*)(GameStatsManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x8c550, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameStatsManager::starsForMapPack(int id) -> decltype(starsForMapPack(id)) {
	using FunctionType = decltype(starsForMapPack(id))(*)(GameStatsManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6ea80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameStatsManager::storeChallenge(int position, GJChallengeItem* challenge) -> decltype(storeChallenge(position, challenge)) {
	using FunctionType = decltype(storeChallenge(position, challenge))(*)(GameStatsManager*, int, GJChallengeItem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x72df0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, position, challenge);
}

auto GameStatsManager::storeChallengeTime(int remaining) -> decltype(storeChallengeTime(remaining)) {
	using FunctionType = decltype(storeChallengeTime(remaining))(*)(GameStatsManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x72d50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, remaining);
}

auto GameStatsManager::storeEventChest(int eventID, GJRewardItem* item) -> decltype(storeEventChest(eventID, item)) {
	using FunctionType = decltype(storeEventChest(eventID, item))(*)(GameStatsManager*, int, GJRewardItem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x73e30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, eventID, item);
}

auto GameStatsManager::storeOnlineChest(gd::string key, GJRewardItem* item) -> decltype(storeOnlineChest(key, item)) {
	using FunctionType = decltype(storeOnlineChest(key, item))(*)(GameStatsManager*, gd::string, GJRewardItem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x747c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key, item);
}

auto GameStatsManager::storePendingUserCoin(char const* key) -> decltype(storePendingUserCoin(key)) {
	using FunctionType = decltype(storePendingUserCoin(key))(*)(GameStatsManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x70430, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GameStatsManager::storeQueuedChallenge(int position, GJChallengeItem* challenge) -> decltype(storeQueuedChallenge(position, challenge)) {
	using FunctionType = decltype(storeQueuedChallenge(position, challenge))(*)(GameStatsManager*, int, GJChallengeItem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x72fe0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, position, challenge);
}

auto GameStatsManager::storeRewardState(GJRewardType type, int id, int remaining, gd::string str) -> decltype(storeRewardState(type, id, remaining, str)) {
	using FunctionType = decltype(storeRewardState(type, id, remaining, str))(*)(GameStatsManager*, GJRewardType, int, int, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x720f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type, id, remaining, str);
}

auto GameStatsManager::storeSecondaryQueuedChallenge(int position, GJChallengeItem* challenge) -> decltype(storeSecondaryQueuedChallenge(position, challenge)) {
	using FunctionType = decltype(storeSecondaryQueuedChallenge(position, challenge))(*)(GameStatsManager*, int, GJChallengeItem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x731d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, position, challenge);
}

auto GameStatsManager::storeSecretCoin(char const* key) -> decltype(storeSecretCoin(key)) {
	using FunctionType = decltype(storeSecretCoin(key))(*)(GameStatsManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x70540, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GameStatsManager::storeUserCoin(char const* key) -> decltype(storeUserCoin(key)) {
	using FunctionType = decltype(storeUserCoin(key))(*)(GameStatsManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x70340, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GameStatsManager::tempClear() -> decltype(tempClear()) {
	using FunctionType = decltype(tempClear())(*)(GameStatsManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x70bb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameStatsManager::toggleEnableItem(UnlockType type, int id, bool enabled) -> decltype(toggleEnableItem(type, id, enabled)) {
	using FunctionType = decltype(toggleEnableItem(type, id, enabled))(*)(GameStatsManager*, UnlockType, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x77920, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type, id, enabled);
}

auto GameStatsManager::tryFixPathBug() -> decltype(tryFixPathBug()) {
	using FunctionType = decltype(tryFixPathBug())(*)(GameStatsManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6c060, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameStatsManager::trySelectActivePath() -> decltype(trySelectActivePath()) {
	using FunctionType = decltype(trySelectActivePath())(*)(GameStatsManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6bbd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameStatsManager::uncompleteLevel(GJGameLevel* level) -> decltype(uncompleteLevel(level)) {
	using FunctionType = decltype(uncompleteLevel(level))(*)(GameStatsManager*, GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6e3a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, level);
}

auto GameStatsManager::unlockGauntlet(int id) -> decltype(unlockGauntlet(id)) {
	using FunctionType = decltype(unlockGauntlet(id))(*)(GameStatsManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x785e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameStatsManager::unlockGauntletChest(int id) -> decltype(unlockGauntletChest(id)) {
	using FunctionType = decltype(unlockGauntletChest(id))(*)(GameStatsManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x78740, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameStatsManager::unlockGoldChest(int id) -> decltype(unlockGoldChest(id)) {
	using FunctionType = decltype(unlockGoldChest(id))(*)(GameStatsManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x8c2d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameStatsManager::unlockOnlineChest(gd::string key) -> decltype(unlockOnlineChest(key)) {
	using FunctionType = decltype(unlockOnlineChest(key))(*)(GameStatsManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x747f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GameStatsManager::unlockPathChest(int id) -> decltype(unlockPathChest(id)) {
	using FunctionType = decltype(unlockPathChest(id))(*)(GameStatsManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x78900, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameStatsManager::unlockSecretChest(int id) -> decltype(unlockSecretChest(id)) {
	using FunctionType = decltype(unlockSecretChest(id))(*)(GameStatsManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x8c0e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameStatsManager::unlockSpecialChest(gd::string key) -> decltype(unlockSpecialChest(key)) {
	using FunctionType = decltype(unlockSpecialChest(key))(*)(GameStatsManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x784c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GameStatsManager::updateActivePath(StatKey key) -> decltype(updateActivePath(key)) {
	using FunctionType = decltype(updateActivePath(key))(*)(GameStatsManager*, StatKey);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6bbb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GameStatsManager::usernameForAccountID(int id) -> decltype(usernameForAccountID(id)) {
	using FunctionType = decltype(usernameForAccountID(id))(*)(GameStatsManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x32b6a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameStatsManager::verifyPathAchievements() -> decltype(verifyPathAchievements()) {
	using FunctionType = decltype(verifyPathAchievements())(*)(GameStatsManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6cba0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameStatsManager::verifyUserCoins() -> decltype(verifyUserCoins()) {
	using FunctionType = decltype(verifyUserCoins())(*)(GameStatsManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6f8e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
