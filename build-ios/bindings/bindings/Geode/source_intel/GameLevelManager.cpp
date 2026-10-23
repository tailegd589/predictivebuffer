
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GameLevelManager.hpp>
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

auto GameLevelManager::responseToDict(gd::string response, bool colon) -> decltype(responseToDict(response, colon)) {
	using FunctionType = decltype(responseToDict(response, colon))(*)(gd::string, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x531090, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(response, colon);
}

auto GameLevelManager::sharedState() -> decltype(sharedState()) {
	using FunctionType = decltype(sharedState())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51aa10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto GameLevelManager::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GameLevelManager::init), this);
	using FunctionType = decltype(init())(*)(GameLevelManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52bd80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GameLevelManager::acceptFriendRequest(int accountID, int requestID) -> decltype(acceptFriendRequest(accountID, requestID)) {
	using FunctionType = decltype(acceptFriendRequest(accountID, requestID))(*)(GameLevelManager*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x554ea0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, accountID, requestID);
}

auto GameLevelManager::accountIDForUserID(int userID) -> decltype(accountIDForUserID(userID)) {
	using FunctionType = decltype(accountIDForUserID(userID))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52ea50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, userID);
}

auto GameLevelManager::addDLToActive(char const* key) -> decltype(addDLToActive(key)) {
	using FunctionType = decltype(addDLToActive(key))(*)(GameLevelManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5389d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GameLevelManager::areGauntletsLoaded() -> decltype(areGauntletsLoaded()) {
	using FunctionType = decltype(areGauntletsLoaded())(*)(GameLevelManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x543c50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameLevelManager::banUser(int accountID) -> decltype(banUser(accountID)) {
	using FunctionType = decltype(banUser(accountID))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x547290, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, accountID);
}

auto GameLevelManager::blockUser(int accountID) -> decltype(blockUser(accountID)) {
	using FunctionType = decltype(blockUser(accountID))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x555e50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, accountID);
}

auto GameLevelManager::cleanupDailyLevels() -> decltype(cleanupDailyLevels()) {
	using FunctionType = decltype(cleanupDailyLevels())(*)(GameLevelManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x539cb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameLevelManager::createAndGetAccountComments(gd::string str, int accountID) -> decltype(createAndGetAccountComments(str, accountID)) {
	using FunctionType = decltype(createAndGetAccountComments(str, accountID))(*)(GameLevelManager*, gd::string, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x550210, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, str, accountID);
}

auto GameLevelManager::createAndGetCommentsFull(gd::string str, int parentID, bool account) -> decltype(createAndGetCommentsFull(str, parentID, account)) {
	using FunctionType = decltype(createAndGetCommentsFull(str, parentID, account))(*)(GameLevelManager*, gd::string, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5502a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, str, parentID, account);
}

auto GameLevelManager::createAndGetLevelComments(gd::string str, int levelID) -> decltype(createAndGetLevelComments(str, levelID)) {
	using FunctionType = decltype(createAndGetLevelComments(str, levelID))(*)(GameLevelManager*, gd::string, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x54fe10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, str, levelID);
}

auto GameLevelManager::createAndGetLevelLists(gd::string str) -> decltype(createAndGetLevelLists(str)) {
	using FunctionType = decltype(createAndGetLevelLists(str))(*)(GameLevelManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x531650, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, str);
}

auto GameLevelManager::createAndGetLevels(gd::string str) -> decltype(createAndGetLevels(str)) {
	using FunctionType = decltype(createAndGetLevels(str))(*)(GameLevelManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52ed20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, str);
}

auto GameLevelManager::createAndGetMapPacks(gd::string str) -> decltype(createAndGetMapPacks(str)) {
	using FunctionType = decltype(createAndGetMapPacks(str))(*)(GameLevelManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5320c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, str);
}

auto GameLevelManager::createAndGetScores(gd::string str, GJScoreType type) -> decltype(createAndGetScores(str, type)) {
	using FunctionType = decltype(createAndGetScores(str, type))(*)(GameLevelManager*, gd::string, GJScoreType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x532d10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, str, type);
}

auto GameLevelManager::createNewLevel() -> decltype(createNewLevel()) {
	using FunctionType = decltype(createNewLevel())(*)(GameLevelManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52c590, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameLevelManager::createNewLevelList() -> decltype(createNewLevelList()) {
	using FunctionType = decltype(createNewLevelList())(*)(GameLevelManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52d2a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameLevelManager::createPageInfo(int total, int start, int count) -> decltype(createPageInfo(total, start, count)) {
	using FunctionType = decltype(createPageInfo(total, start, count))(*)(GameLevelManager*, int, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x538830, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, total, start, count);
}

auto GameLevelManager::createSmartTemplate() -> decltype(createSmartTemplate()) {
	using FunctionType = decltype(createSmartTemplate())(*)(GameLevelManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x53aab0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameLevelManager::dataLoaded(DS_Dictionary* dict) -> decltype(dataLoaded(dict)) {
	using FunctionType = decltype(dataLoaded(dict))(*)(GameLevelManager*, DS_Dictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x53b450, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dict);
}

auto GameLevelManager::deleteAccountComment(int id, int accountID) -> decltype(deleteAccountComment(id, accountID)) {
	using FunctionType = decltype(deleteAccountComment(id, accountID))(*)(GameLevelManager*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5537f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, accountID);
}

auto GameLevelManager::deleteComment(int id, CommentType type, int parentID) -> decltype(deleteComment(id, type, parentID)) {
	using FunctionType = decltype(deleteComment(id, type, parentID))(*)(GameLevelManager*, int, CommentType, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x553000, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, type, parentID);
}

auto GameLevelManager::deleteFriendRequests(int accountID, cocos2d::CCArray* accounts, bool sent) -> decltype(deleteFriendRequests(accountID, accounts, sent)) {
	using FunctionType = decltype(deleteFriendRequests(accountID, accounts, sent))(*)(GameLevelManager*, int, cocos2d::CCArray*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x554510, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, accountID, accounts, sent);
}

auto GameLevelManager::deleteLevel(GJGameLevel* level) -> decltype(deleteLevel(level)) {
	using FunctionType = decltype(deleteLevel(level))(*)(GameLevelManager*, GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52cf90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, level);
}

auto GameLevelManager::deleteLevelComment(int id, int levelID) -> decltype(deleteLevelComment(id, levelID)) {
	using FunctionType = decltype(deleteLevelComment(id, levelID))(*)(GameLevelManager*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x552ff0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, levelID);
}

auto GameLevelManager::deleteLevelList(GJLevelList* list) -> decltype(deleteLevelList(list)) {
	using FunctionType = decltype(deleteLevelList(list))(*)(GameLevelManager*, GJLevelList*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52d7e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, list);
}

auto GameLevelManager::deleteSentFriendRequest(int accountID) -> decltype(deleteSentFriendRequest(accountID)) {
	using FunctionType = decltype(deleteSentFriendRequest(accountID))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5544f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, accountID);
}

auto GameLevelManager::deleteServerLevel(int id) -> decltype(deleteServerLevel(id)) {
	using FunctionType = decltype(deleteServerLevel(id))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x546c60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameLevelManager::deleteServerLevelList(int id) -> decltype(deleteServerLevelList(id)) {
	using FunctionType = decltype(deleteServerLevelList(id))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x541f50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameLevelManager::deleteSmartTemplate(GJSmartTemplate* smartTemplate) -> decltype(deleteSmartTemplate(smartTemplate)) {
	using FunctionType = decltype(deleteSmartTemplate(smartTemplate))(*)(GameLevelManager*, GJSmartTemplate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x53aaf0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, smartTemplate);
}

auto GameLevelManager::deleteUserMessages(GJUserMessage* message, cocos2d::CCArray* messages, bool isSender) -> decltype(deleteUserMessages(message, messages, isSender)) {
	using FunctionType = decltype(deleteUserMessages(message, messages, isSender))(*)(GameLevelManager*, GJUserMessage*, cocos2d::CCArray*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x54eec0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, message, messages, isSender);
}

auto GameLevelManager::downloadLevel(int id, bool gauntletLevel, int dailyID) -> decltype(downloadLevel(id, gauntletLevel, dailyID)) {
	using FunctionType = decltype(downloadLevel(id, gauntletLevel, dailyID))(*)(GameLevelManager*, int, bool, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x543cb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, gauntletLevel, dailyID);
}

auto GameLevelManager::downloadUserMessage(int id, bool sent) -> decltype(downloadUserMessage(id, sent)) {
	using FunctionType = decltype(downloadUserMessage(id, sent))(*)(GameLevelManager*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x54e510, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, sent);
}

auto GameLevelManager::encodeDataTo(DS_Dictionary* dict) -> decltype(encodeDataTo(dict)) {
	using FunctionType = decltype(encodeDataTo(dict))(*)(GameLevelManager*, DS_Dictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x53af30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dict);
}

auto GameLevelManager::firstSetup() -> decltype(firstSetup()) {
	using FunctionType = decltype(firstSetup())(*)(GameLevelManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x53ab70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameLevelManager::followUser(int id) -> decltype(followUser(id)) {
	using FunctionType = decltype(followUser(id))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x53a170, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameLevelManager::friendRequestFromAccountID(int id) -> decltype(friendRequestFromAccountID(id)) {
	using FunctionType = decltype(friendRequestFromAccountID(id))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x54d550, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameLevelManager::friendRequestWasRemoved(int accountID, bool sent) -> decltype(friendRequestWasRemoved(accountID, sent)) {
	using FunctionType = decltype(friendRequestWasRemoved(accountID, sent))(*)(GameLevelManager*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x554cc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, accountID, sent);
}

auto GameLevelManager::getAccountCommentKey(int accountID, int page) -> decltype(getAccountCommentKey(accountID, page)) {
	using FunctionType = decltype(getAccountCommentKey(accountID, page))(*)(GameLevelManager*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5501f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, accountID, page);
}

auto GameLevelManager::getAccountComments(int accountID, int page, int total) -> decltype(getAccountComments(accountID, page, total)) {
	using FunctionType = decltype(getAccountComments(accountID, page, total))(*)(GameLevelManager*, int, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x54fea0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, accountID, page, total);
}

auto GameLevelManager::getActiveDailyID(GJTimedLevelType type) -> decltype(getActiveDailyID(type)) {
	using FunctionType = decltype(getActiveDailyID(type))(*)(GameLevelManager*, GJTimedLevelType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x559e90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type);
}

auto GameLevelManager::getActiveSmartTemplate() -> decltype(getActiveSmartTemplate()) {
	using FunctionType = decltype(getActiveSmartTemplate())(*)(GameLevelManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x53a9c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameLevelManager::getAllSmartTemplates() -> decltype(getAllSmartTemplates()) {
	using FunctionType = decltype(getAllSmartTemplates())(*)(GameLevelManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x53ab40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameLevelManager::getAllUsedSongIDs() -> decltype(getAllUsedSongIDs()) {
	using FunctionType = decltype(getAllUsedSongIDs())(*)(GameLevelManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x55af80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameLevelManager::getBasePostString() -> decltype(getBasePostString()) {
	using FunctionType = decltype(getBasePostString())(*)(GameLevelManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x53d1c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameLevelManager::getBoolForKey(char const* key) -> decltype(getBoolForKey(key)) {
	using FunctionType = decltype(getBoolForKey(key))(*)(GameLevelManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x55ae90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GameLevelManager::getCommentKey(int ID, int page, int mode, CommentKeyType keytype) -> decltype(getCommentKey(ID, page, mode, keytype)) {
	using FunctionType = decltype(getCommentKey(ID, page, mode, keytype))(*)(GameLevelManager*, int, int, int, CommentKeyType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x54fc50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, ID, page, mode, keytype);
}

auto GameLevelManager::getCompletedDailyLevels() -> decltype(getCompletedDailyLevels()) {
	using FunctionType = decltype(getCompletedDailyLevels())(*)(GameLevelManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x536e90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameLevelManager::getCompletedEventLevels(int minStars, int maxStars) -> decltype(getCompletedEventLevels(minStars, maxStars)) {
	using FunctionType = decltype(getCompletedEventLevels(minStars, maxStars))(*)(GameLevelManager*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x537090, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, minStars, maxStars);
}

auto GameLevelManager::getCompletedGauntletDemons() -> decltype(getCompletedGauntletDemons()) {
	using FunctionType = decltype(getCompletedGauntletDemons())(*)(GameLevelManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5372a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameLevelManager::getCompletedGauntletLevels() -> decltype(getCompletedGauntletLevels()) {
	using FunctionType = decltype(getCompletedGauntletLevels())(*)(GameLevelManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x537360, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameLevelManager::getCompletedLevels(bool useOrbCompletion) -> decltype(getCompletedLevels(useOrbCompletion)) {
	using FunctionType = decltype(getCompletedLevels(useOrbCompletion))(*)(GameLevelManager*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5350b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, useOrbCompletion);
}

auto GameLevelManager::getCompletedWeeklyLevels() -> decltype(getCompletedWeeklyLevels()) {
	using FunctionType = decltype(getCompletedWeeklyLevels())(*)(GameLevelManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x536c90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameLevelManager::getDailyID(GJTimedLevelType type) -> decltype(getDailyID(type)) {
	using FunctionType = decltype(getDailyID(type))(*)(GameLevelManager*, GJTimedLevelType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x559e60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type);
}

auto GameLevelManager::getDailyTimer(GJTimedLevelType type) -> decltype(getDailyTimer(type)) {
	using FunctionType = decltype(getDailyTimer(type))(*)(GameLevelManager*, GJTimedLevelType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x559ec0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type);
}

auto GameLevelManager::getDeleteCommentKey(int parentID, int id, int type) -> decltype(getDeleteCommentKey(parentID, id, type)) {
	using FunctionType = decltype(getDeleteCommentKey(parentID, id, type))(*)(GameLevelManager*, int, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5513c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, parentID, id, type);
}

auto GameLevelManager::getDeleteMessageKey(int id, bool sent) -> decltype(getDeleteMessageKey(id, sent)) {
	using FunctionType = decltype(getDeleteMessageKey(id, sent))(*)(GameLevelManager*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x54f3c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, sent);
}

auto GameLevelManager::getDemonLevelsString() -> decltype(getDemonLevelsString()) {
	using FunctionType = decltype(getDemonLevelsString())(*)(GameLevelManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x535280, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameLevelManager::getDescKey(int levelID) -> decltype(getDescKey(levelID)) {
	using FunctionType = decltype(getDescKey(levelID))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x551380, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, levelID);
}

auto GameLevelManager::getDifficultyStr(bool isNA, bool isEasy, bool isNormal, bool isHard, bool isHarder, bool isInsane, bool isDemon, bool isAuto) -> decltype(getDifficultyStr(isNA, isEasy, isNormal, isHard, isHarder, isInsane, isDemon, isAuto)) {
	using FunctionType = decltype(getDifficultyStr(isNA, isEasy, isNormal, isHard, isHarder, isInsane, isDemon, isAuto))(*)(GameLevelManager*, bool, bool, bool, bool, bool, bool, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x53e890, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, isNA, isEasy, isNormal, isHard, isHarder, isInsane, isDemon, isAuto);
}

auto GameLevelManager::getDiffKey(int diff) -> decltype(getDiffKey(diff)) {
	using FunctionType = decltype(getDiffKey(diff))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x55a720, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, diff);
}

auto GameLevelManager::getDiffVal(int diff) -> decltype(getDiffVal(diff)) {
	using FunctionType = decltype(getDiffVal(diff))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x55a740, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, diff);
}

auto GameLevelManager::getFolderName(int id, bool local) -> decltype(getFolderName(id, local)) {
	using FunctionType = decltype(getFolderName(id, local))(*)(GameLevelManager*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x53a6f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, local);
}

auto GameLevelManager::getFriendRequestKey(bool sent, int page) -> decltype(getFriendRequestKey(sent, page)) {
	using FunctionType = decltype(getFriendRequestKey(sent, page))(*)(GameLevelManager*, bool, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x551360, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sent, page);
}

auto GameLevelManager::getFriendRequests(bool sent, int page, int total) -> decltype(getFriendRequests(sent, page, total)) {
	using FunctionType = decltype(getFriendRequests(sent, page, total))(*)(GameLevelManager*, bool, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x553c00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sent, page, total);
}

auto GameLevelManager::getGauntletKey(int id) -> decltype(getGauntletKey(id)) {
	using FunctionType = decltype(getGauntletKey(id))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x543b30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameLevelManager::getGauntletLevels(int id) -> decltype(getGauntletLevels(id)) {
	using FunctionType = decltype(getGauntletLevels(id))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x543630, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameLevelManager::getGauntlets() -> decltype(getGauntlets()) {
	using FunctionType = decltype(getGauntlets())(*)(GameLevelManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x543270, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameLevelManager::getGauntletSearchKey(int id) -> decltype(getGauntletSearchKey(id)) {
	using FunctionType = decltype(getGauntletSearchKey(id))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5431b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameLevelManager::getGJChallenges() -> decltype(getGJChallenges()) {
	using FunctionType = decltype(getGJChallenges())(*)(GameLevelManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x559270, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameLevelManager::getGJDailyLevelState(GJTimedLevelType type) -> decltype(getGJDailyLevelState(type)) {
	using FunctionType = decltype(getGJDailyLevelState(type))(*)(GameLevelManager*, GJTimedLevelType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x559720, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type);
}

auto GameLevelManager::getGJRewards(int type) -> decltype(getGJRewards(type)) {
	using FunctionType = decltype(getGJRewards(type))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x558a60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type);
}

auto GameLevelManager::getGJSecretReward(gd::string key) -> decltype(getGJSecretReward(key)) {
	using FunctionType = decltype(getGJSecretReward(key))(*)(GameLevelManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x558580, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GameLevelManager::getGJUserInfo(int id) -> decltype(getGJUserInfo(id)) {
	using FunctionType = decltype(getGJUserInfo(id))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x54ccb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameLevelManager::getHighestLevelOrder() -> decltype(getHighestLevelOrder()) {
	using FunctionType = decltype(getHighestLevelOrder())(*)(GameLevelManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x534e20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameLevelManager::getIntForKey(char const* key) -> decltype(getIntForKey(key)) {
	using FunctionType = decltype(getIntForKey(key))(*)(GameLevelManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x55aca0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GameLevelManager::getLeaderboardKey(LeaderboardType type, LeaderboardStat stat) -> decltype(getLeaderboardKey(type, stat)) {
	using FunctionType = decltype(getLeaderboardKey(type, stat))(*)(GameLevelManager*, LeaderboardType, LeaderboardStat);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5472a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type, stat);
}

auto GameLevelManager::getLeaderboardScores(LeaderboardType type, LeaderboardStat stat) -> decltype(getLeaderboardScores(type, stat)) {
	using FunctionType = decltype(getLeaderboardScores(type, stat))(*)(GameLevelManager*, LeaderboardType, LeaderboardStat);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x54a990, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type, stat);
}

auto GameLevelManager::getLengthStr(bool isTiny, bool isShort, bool isMedium, bool isLong, bool isXL, bool isPlat) -> decltype(getLengthStr(isTiny, isShort, isMedium, isLong, isXL, isPlat)) {
	using FunctionType = decltype(getLengthStr(isTiny, isShort, isMedium, isLong, isXL, isPlat))(*)(GameLevelManager*, bool, bool, bool, bool, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x53ee70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, isTiny, isShort, isMedium, isLong, isXL, isPlat);
}

auto GameLevelManager::getLenKey(int len) -> decltype(getLenKey(len)) {
	using FunctionType = decltype(getLenKey(len))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x55a960, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, len);
}

auto GameLevelManager::getLenVal(int len) -> decltype(getLenVal(len)) {
	using FunctionType = decltype(getLenVal(len))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x55a980, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, len);
}

auto GameLevelManager::getLevelComments(int ID, int page, int total, int mode, CommentKeyType keytype) -> decltype(getLevelComments(ID, page, total, mode, keytype)) {
	using FunctionType = decltype(getLevelComments(ID, page, total, mode, keytype))(*)(GameLevelManager*, int, int, int, int, CommentKeyType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x54f770, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, ID, page, total, mode, keytype);
}

auto GameLevelManager::getLevelDownloadKey(int levelID, bool isGauntlet, int dailyID) -> decltype(getLevelDownloadKey(levelID, isGauntlet, dailyID)) {
	using FunctionType = decltype(getLevelDownloadKey(levelID, isGauntlet, dailyID))(*)(GameLevelManager*, int, bool, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x543c90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, levelID, isGauntlet, dailyID);
}

auto GameLevelManager::getLevelKey(int levelID) -> decltype(getLevelKey(levelID)) {
	using FunctionType = decltype(getLevelKey(levelID))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52c3c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, levelID);
}

auto GameLevelManager::getLevelLeaderboard(GJGameLevel* level, LevelLeaderboardType type, LevelLeaderboardMode mode) -> decltype(getLevelLeaderboard(level, type, mode)) {
	using FunctionType = decltype(getLevelLeaderboard(level, type, mode))(*)(GameLevelManager*, GJGameLevel*, LevelLeaderboardType, LevelLeaderboardMode);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x54b2f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, level, type, mode);
}

auto GameLevelManager::getLevelLeaderboardKey(int levelID, LevelLeaderboardType type, LevelLeaderboardMode mode) -> decltype(getLevelLeaderboardKey(levelID, type, mode)) {
	using FunctionType = decltype(getLevelLeaderboardKey(levelID, type, mode))(*)(GameLevelManager*, int, LevelLeaderboardType, LevelLeaderboardMode);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x54c450, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, levelID, type, mode);
}

auto GameLevelManager::getLevelListKey(int listID) -> decltype(getLevelListKey(listID)) {
	using FunctionType = decltype(getLevelListKey(listID))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52d910, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, listID);
}

auto GameLevelManager::getLevelLists(GJSearchObject* object) -> decltype(getLevelLists(object)) {
	using FunctionType = decltype(getLevelLists(object))(*)(GameLevelManager*, GJSearchObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x542500, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GameLevelManager::getLevelRateInfo(int id) -> decltype(getLevelRateInfo(id)) {
	using FunctionType = decltype(getLevelRateInfo(id))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x553810, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameLevelManager::getLevelSaveData() -> decltype(getLevelSaveData()) {
	using FunctionType = decltype(getLevelSaveData())(*)(GameLevelManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x540b10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameLevelManager::getLikeAccountItemKey(LikeItemType type, int id, bool liked, int parentID) -> decltype(getLikeAccountItemKey(type, id, liked, parentID)) {
	using FunctionType = decltype(getLikeAccountItemKey(type, id, liked, parentID))(*)(GameLevelManager*, LikeItemType, int, bool, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x558260, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type, id, liked, parentID);
}

auto GameLevelManager::getLikeItemKey(LikeItemType type, int id, bool liked, int parentID) -> decltype(getLikeItemKey(type, id, liked, parentID)) {
	using FunctionType = decltype(getLikeItemKey(type, id, liked, parentID))(*)(GameLevelManager*, LikeItemType, int, bool, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x557c20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type, id, liked, parentID);
}

auto GameLevelManager::getLocalLevel(int uniqueID) -> decltype(getLocalLevel(uniqueID)) {
	using FunctionType = decltype(getLocalLevel(uniqueID))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52c520, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, uniqueID);
}

auto GameLevelManager::getLocalLevelByName(gd::string name) -> decltype(getLocalLevelByName(name)) {
	using FunctionType = decltype(getLocalLevelByName(name))(*)(GameLevelManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52c3e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, name);
}

auto GameLevelManager::getLocalLevelList(int uniqueID) -> decltype(getLocalLevelList(uniqueID)) {
	using FunctionType = decltype(getLocalLevelList(uniqueID))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52d230, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, uniqueID);
}

auto GameLevelManager::getLowestLevelOrder() -> decltype(getLowestLevelOrder()) {
	using FunctionType = decltype(getLowestLevelOrder())(*)(GameLevelManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x534e60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameLevelManager::getMainLevel(int levelID, bool dontGetLevelString) -> decltype(getMainLevel(levelID, dontGetLevelString)) {
	using FunctionType = decltype(getMainLevel(levelID, dontGetLevelString))(*)(GameLevelManager*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52bf20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, levelID, dontGetLevelString);
}

auto GameLevelManager::getMapPackKey(int pack) -> decltype(getMapPackKey(pack)) {
	using FunctionType = decltype(getMapPackKey(pack))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5410e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, pack);
}

auto GameLevelManager::getMapPacks(GJSearchObject* object) -> decltype(getMapPacks(object)) {
	using FunctionType = decltype(getMapPacks(object))(*)(GameLevelManager*, GJSearchObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x540da0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GameLevelManager::getMessageKey(int id) -> decltype(getMessageKey(id)) {
	using FunctionType = decltype(getMessageKey(id))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x54e860, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameLevelManager::getMessagesKey(bool sent, int page) -> decltype(getMessagesKey(sent, page)) {
	using FunctionType = decltype(getMessagesKey(sent, page))(*)(GameLevelManager*, bool, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x54d960, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sent, page);
}

auto GameLevelManager::getNews() -> decltype(getNews()) {
	using FunctionType = decltype(getNews())(*)(GameLevelManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x54f750, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameLevelManager::getNextFreeTemplateID() -> decltype(getNextFreeTemplateID()) {
	using FunctionType = decltype(getNextFreeTemplateID())(*)(GameLevelManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x53a9e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameLevelManager::getNextLevelName(gd::string name) -> decltype(getNextLevelName(name)) {
	using FunctionType = decltype(getNextLevelName(name))(*)(GameLevelManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52c8f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, name);
}

auto GameLevelManager::getOnlineLevels(GJSearchObject* object) -> decltype(getOnlineLevels(object)) {
	using FunctionType = decltype(getOnlineLevels(object))(*)(GameLevelManager*, GJSearchObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x53fa90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GameLevelManager::getPageInfo(char const* key) -> decltype(getPageInfo(key)) {
	using FunctionType = decltype(getPageInfo(key))(*)(GameLevelManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x538740, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GameLevelManager::getPostCommentKey(int parentID) -> decltype(getPostCommentKey(parentID)) {
	using FunctionType = decltype(getPostCommentKey(parentID))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5513a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, parentID);
}

auto GameLevelManager::getRateStarsKey(int levelID) -> decltype(getRateStarsKey(levelID)) {
	using FunctionType = decltype(getRateStarsKey(levelID))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5469e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, levelID);
}

auto GameLevelManager::getReportKey(int levelID) -> decltype(getReportKey(levelID)) {
	using FunctionType = decltype(getReportKey(levelID))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x55a700, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, levelID);
}

auto GameLevelManager::getSavedDailyLevel(int dailyID) -> decltype(getSavedDailyLevel(dailyID)) {
	using FunctionType = decltype(getSavedDailyLevel(dailyID))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x537420, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dailyID);
}

auto GameLevelManager::getSavedDailyLevelFromLevelID(int id) -> decltype(getSavedDailyLevelFromLevelID(id)) {
	using FunctionType = decltype(getSavedDailyLevelFromLevelID(id))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x537720, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameLevelManager::getSavedGauntlet(int id) -> decltype(getSavedGauntlet(id)) {
	using FunctionType = decltype(getSavedGauntlet(id))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x543b50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameLevelManager::getSavedGauntletLevel(int id) -> decltype(getSavedGauntletLevel(id)) {
	using FunctionType = decltype(getSavedGauntletLevel(id))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x537520, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameLevelManager::getSavedLevel(GJGameLevel* level) -> decltype(getSavedLevel(level)) {
	using FunctionType = decltype(getSavedLevel(level))(*)(GameLevelManager*, GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x531600, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, level);
}

auto GameLevelManager::getSavedLevel(int id) -> decltype(getSavedLevel(id)) {
	using FunctionType = decltype(getSavedLevel(id))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x537620, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameLevelManager::getSavedLevelList(int listID) -> decltype(getSavedLevelList(listID)) {
	using FunctionType = decltype(getSavedLevelList(listID))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x542be0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, listID);
}

auto GameLevelManager::getSavedLevelLists(int folder) -> decltype(getSavedLevelLists(folder)) {
	using FunctionType = decltype(getSavedLevelLists(folder))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x534d50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, folder);
}

auto GameLevelManager::getSavedLevels(bool favorite, int folder) -> decltype(getSavedLevels(favorite, folder)) {
	using FunctionType = decltype(getSavedLevels(favorite, folder))(*)(GameLevelManager*, bool, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x534b60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, favorite, folder);
}

auto GameLevelManager::getSavedMapPack(int id) -> decltype(getSavedMapPack(id)) {
	using FunctionType = decltype(getSavedMapPack(id))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x541100, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameLevelManager::getSearchScene(char const* key) -> decltype(getSearchScene(key)) {
	using FunctionType = decltype(getSearchScene(key))(*)(GameLevelManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x538ee0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GameLevelManager::getSplitIntFromKey(char const* key, int index) -> decltype(getSplitIntFromKey(key, index)) {
	using FunctionType = decltype(getSplitIntFromKey(key, index))(*)(GameLevelManager*, char const*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x547840, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key, index);
}

auto GameLevelManager::getStarLevelsString() -> decltype(getStarLevelsString()) {
	using FunctionType = decltype(getStarLevelsString())(*)(GameLevelManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x535620, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameLevelManager::getStoredLevelComments(char const* key) -> decltype(getStoredLevelComments(key)) {
	using FunctionType = decltype(getStoredLevelComments(key))(*)(GameLevelManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5516e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GameLevelManager::getStoredOnlineLevels(char const* key) -> decltype(getStoredOnlineLevels(key)) {
	using FunctionType = decltype(getStoredOnlineLevels(key))(*)(GameLevelManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x538500, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GameLevelManager::getStoredUserList(UserListType type) -> decltype(getStoredUserList(type)) {
	using FunctionType = decltype(getStoredUserList(type))(*)(GameLevelManager*, UserListType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x555da0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type);
}

auto GameLevelManager::getStoredUserMessage(int id) -> decltype(getStoredUserMessage(id)) {
	using FunctionType = decltype(getStoredUserMessage(id))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x54d590, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameLevelManager::getStoredUserMessageReply(int id) -> decltype(getStoredUserMessageReply(id)) {
	using FunctionType = decltype(getStoredUserMessageReply(id))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x54d5e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameLevelManager::getTimeLeft(char const* key, float length) -> decltype(getTimeLeft(key, length)) {
	using FunctionType = decltype(getTimeLeft(key, length))(*)(GameLevelManager*, char const*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x538ba0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key, length);
}

auto GameLevelManager::getTopArtists(int page, int total) -> decltype(getTopArtists(page, total)) {
	using FunctionType = decltype(getTopArtists(page, total))(*)(GameLevelManager*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x54c4e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, page, total);
}

auto GameLevelManager::getTopArtistsKey(int page) -> decltype(getTopArtistsKey(page)) {
	using FunctionType = decltype(getTopArtistsKey(page))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x54c8b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, page);
}

auto GameLevelManager::getUploadMessageKey(int accountID) -> decltype(getUploadMessageKey(accountID)) {
	using FunctionType = decltype(getUploadMessageKey(accountID))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x54e880, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, accountID);
}

auto GameLevelManager::getUserInfoKey(int id) -> decltype(getUserInfoKey(id)) {
	using FunctionType = decltype(getUserInfoKey(id))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x54cc90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameLevelManager::getUserList(UserListType type) -> decltype(getUserList(type)) {
	using FunctionType = decltype(getUserList(type))(*)(GameLevelManager*, UserListType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x556890, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type);
}

auto GameLevelManager::getUserMessages(bool sent, int page, int total) -> decltype(getUserMessages(sent, page, total)) {
	using FunctionType = decltype(getUserMessages(sent, page, total))(*)(GameLevelManager*, bool, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x54d600, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sent, page, total);
}

auto GameLevelManager::getUsers(GJSearchObject* object) -> decltype(getUsers(object)) {
	using FunctionType = decltype(getUsers(object))(*)(GameLevelManager*, GJSearchObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x54c8d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto GameLevelManager::gotoLevelPage(GJGameLevel* level) -> decltype(gotoLevelPage(level)) {
	using FunctionType = decltype(gotoLevelPage(level))(*)(GameLevelManager*, GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x537fd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, level);
}

auto GameLevelManager::handleIt(bool success, gd::string response, gd::string tag, GJHttpType type) -> decltype(handleIt(success, response, tag, type)) {
	using FunctionType = decltype(handleIt(success, response, tag, type))(*)(GameLevelManager*, bool, gd::string, gd::string, GJHttpType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51b0e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, success, response, tag, type);
}

auto GameLevelManager::handleItDelayed(bool success, gd::string response, gd::string tag, GJHttpType type) -> decltype(handleItDelayed(success, response, tag, type)) {
	using FunctionType = decltype(handleItDelayed(success, response, tag, type))(*)(GameLevelManager*, bool, gd::string, gd::string, GJHttpType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51df80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, success, response, tag, type);
}

auto GameLevelManager::handleItND(cocos2d::CCNode* node, void* data) -> decltype(handleItND(node, data)) {
	using FunctionType = decltype(handleItND(node, data))(*)(GameLevelManager*, cocos2d::CCNode*, void*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51e270, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, node, data);
}

auto GameLevelManager::hasDailyStateBeenLoaded(GJTimedLevelType type) -> decltype(hasDailyStateBeenLoaded(type)) {
	using FunctionType = decltype(hasDailyStateBeenLoaded(type))(*)(GameLevelManager*, GJTimedLevelType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x559e20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type);
}

auto GameLevelManager::hasDownloadedLevel(int id) -> decltype(hasDownloadedLevel(id)) {
	using FunctionType = decltype(hasDownloadedLevel(id))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x544510, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameLevelManager::hasDownloadedList(int id) -> decltype(hasDownloadedList(id)) {
	using FunctionType = decltype(hasDownloadedList(id))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x540b00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameLevelManager::hasLikedAccountItem(LikeItemType type, int id, bool liked, int parentID) -> decltype(hasLikedAccountItem(type, id, liked, parentID)) {
	using FunctionType = decltype(hasLikedAccountItem(type, id, liked, parentID))(*)(GameLevelManager*, LikeItemType, int, bool, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x558380, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type, id, liked, parentID);
}

auto GameLevelManager::hasLikedItem(LikeItemType type, int id, bool liked, int parentID) -> decltype(hasLikedItem(type, id, liked, parentID)) {
	using FunctionType = decltype(hasLikedItem(type, id, liked, parentID))(*)(GameLevelManager*, LikeItemType, int, bool, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x558280, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type, id, liked, parentID);
}

auto GameLevelManager::hasLikedItemFullCheck(LikeItemType type, int id, bool liked, int parentID) -> decltype(hasLikedItemFullCheck(type, id, liked, parentID)) {
	using FunctionType = decltype(hasLikedItemFullCheck(type, id, liked, parentID))(*)(GameLevelManager*, LikeItemType, int, bool, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x557a90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type, id, liked, parentID);
}

auto GameLevelManager::hasRatedDemon(int id) -> decltype(hasRatedDemon(id)) {
	using FunctionType = decltype(hasRatedDemon(id))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x546b60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameLevelManager::hasRatedLevelStars(int id) -> decltype(hasRatedLevelStars(id)) {
	using FunctionType = decltype(hasRatedLevelStars(id))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x546780, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameLevelManager::hasReportedLevel(int id) -> decltype(hasReportedLevel(id)) {
	using FunctionType = decltype(hasReportedLevel(id))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x55a4a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameLevelManager::invalidateMessages(bool sent, bool reload) -> decltype(invalidateMessages(sent, reload)) {
	using FunctionType = decltype(invalidateMessages(sent, reload))(*)(GameLevelManager*, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x54f3e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sent, reload);
}

auto GameLevelManager::invalidateRequests(bool sent, bool reload) -> decltype(invalidateRequests(sent, reload)) {
	using FunctionType = decltype(invalidateRequests(sent, reload))(*)(GameLevelManager*, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x554b30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sent, reload);
}

auto GameLevelManager::invalidateUserList(UserListType type, bool reload) -> decltype(invalidateUserList(type, reload)) {
	using FunctionType = decltype(invalidateUserList(type, reload))(*)(GameLevelManager*, UserListType, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x556b50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type, reload);
}

auto GameLevelManager::isDLActive(char const* tag) -> decltype(isDLActive(tag)) {
	using FunctionType = decltype(isDLActive(tag))(*)(GameLevelManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5388f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, tag);
}

auto GameLevelManager::isFollowingUser(int id) -> decltype(isFollowingUser(id)) {
	using FunctionType = decltype(isFollowingUser(id))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x53a070, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameLevelManager::isTimeValid(char const* key, float length) -> decltype(isTimeValid(key, length)) {
	using FunctionType = decltype(isTimeValid(key, length))(*)(GameLevelManager*, char const*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x538600, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key, length);
}

auto GameLevelManager::isUpdateValid(int id) -> decltype(isUpdateValid(id)) {
	using FunctionType = decltype(isUpdateValid(id))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x545b20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameLevelManager::itemIDFromLikeKey(char const* key) -> decltype(itemIDFromLikeKey(key)) {
	using FunctionType = decltype(itemIDFromLikeKey(key))(*)(GameLevelManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x557d40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GameLevelManager::keyHasTimer(char const* key) -> decltype(keyHasTimer(key)) {
	using FunctionType = decltype(keyHasTimer(key))(*)(GameLevelManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x538d00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GameLevelManager::levelIDFromCommentKey(char const* key) -> decltype(levelIDFromCommentKey(key)) {
	using FunctionType = decltype(levelIDFromCommentKey(key))(*)(GameLevelManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x54fd10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GameLevelManager::levelIDFromPostCommentKey(char const* key) -> decltype(levelIDFromPostCommentKey(key)) {
	using FunctionType = decltype(levelIDFromPostCommentKey(key))(*)(GameLevelManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5513e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GameLevelManager::likeFromLikeKey(char const* key) -> decltype(likeFromLikeKey(key)) {
	using FunctionType = decltype(likeFromLikeKey(key))(*)(GameLevelManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x557e40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GameLevelManager::likeItem(LikeItemType type, int id, bool liked, int parentID) -> decltype(likeItem(type, id, liked, parentID)) {
	using FunctionType = decltype(likeItem(type, id, liked, parentID))(*)(GameLevelManager*, LikeItemType, int, bool, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x557100, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type, id, liked, parentID);
}

auto GameLevelManager::limitSavedLevels() -> decltype(limitSavedLevels()) {
	using FunctionType = decltype(limitSavedLevels())(*)(GameLevelManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x539770, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameLevelManager::makeTimeStamp(char const* key) -> decltype(makeTimeStamp(key)) {
	using FunctionType = decltype(makeTimeStamp(key))(*)(GameLevelManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5383d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GameLevelManager::markItemAsLiked(LikeItemType type, int id, bool liked, int parentID) -> decltype(markItemAsLiked(type, id, liked, parentID)) {
	using FunctionType = decltype(markItemAsLiked(type, id, liked, parentID))(*)(GameLevelManager*, LikeItemType, int, bool, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x557b20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type, id, liked, parentID);
}

auto GameLevelManager::markLevelAsDownloaded(int id) -> decltype(markLevelAsDownloaded(id)) {
	using FunctionType = decltype(markLevelAsDownloaded(id))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5459b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameLevelManager::markLevelAsRatedDemon(int id) -> decltype(markLevelAsRatedDemon(id)) {
	using FunctionType = decltype(markLevelAsRatedDemon(id))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x546a00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameLevelManager::markLevelAsRatedStars(int id) -> decltype(markLevelAsRatedStars(id)) {
	using FunctionType = decltype(markLevelAsRatedStars(id))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x546880, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameLevelManager::markLevelAsReported(int id) -> decltype(markLevelAsReported(id)) {
	using FunctionType = decltype(markLevelAsReported(id))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x55a5a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameLevelManager::markListAsDownloaded(int id) -> decltype(markListAsDownloaded(id)) {
	using FunctionType = decltype(markListAsDownloaded(id))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x545b10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameLevelManager::messageWasRemoved(int id, bool sent) -> decltype(messageWasRemoved(id, sent)) {
	using FunctionType = decltype(messageWasRemoved(id, sent))(*)(GameLevelManager*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x54f570, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, sent);
}

auto GameLevelManager::onAcceptFriendRequestCompleted(gd::string response, gd::string tag) -> decltype(onAcceptFriendRequestCompleted(response, tag)) {
	using FunctionType = decltype(onAcceptFriendRequestCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5233c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onBanUserCompleted(gd::string response, gd::string tag) -> decltype(onBanUserCompleted(response, tag)) {
	using FunctionType = decltype(onBanUserCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x526070, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onBlockUserCompleted(gd::string response, gd::string tag) -> decltype(onBlockUserCompleted(response, tag)) {
	using FunctionType = decltype(onBlockUserCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x523950, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onDeleteCommentCompleted(gd::string response, gd::string tag) -> decltype(onDeleteCommentCompleted(response, tag)) {
	using FunctionType = decltype(onDeleteCommentCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x522560, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onDeleteFriendRequestCompleted(gd::string response, gd::string tag) -> decltype(onDeleteFriendRequestCompleted(response, tag)) {
	using FunctionType = decltype(onDeleteFriendRequestCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5231b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onDeleteServerLevelCompleted(gd::string response, gd::string tag) -> decltype(onDeleteServerLevelCompleted(response, tag)) {
	using FunctionType = decltype(onDeleteServerLevelCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x520180, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onDeleteServerLevelListCompleted(gd::string response, gd::string tag) -> decltype(onDeleteServerLevelListCompleted(response, tag)) {
	using FunctionType = decltype(onDeleteServerLevelListCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52ade0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onDeleteUserMessagesCompleted(gd::string response, gd::string tag) -> decltype(onDeleteUserMessagesCompleted(response, tag)) {
	using FunctionType = decltype(onDeleteUserMessagesCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5254a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onDownloadLevelCompleted(gd::string response, gd::string tag) -> decltype(onDownloadLevelCompleted(response, tag)) {
	using FunctionType = decltype(onDownloadLevelCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51fe30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onDownloadUserMessageCompleted(gd::string response, gd::string tag) -> decltype(onDownloadUserMessageCompleted(response, tag)) {
	using FunctionType = decltype(onDownloadUserMessageCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x525660, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onGetAccountCommentsCompleted(gd::string response, gd::string tag) -> decltype(onGetAccountCommentsCompleted(response, tag)) {
	using FunctionType = decltype(onGetAccountCommentsCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x520fc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onGetFriendRequestsCompleted(gd::string response, gd::string tag) -> decltype(onGetFriendRequestsCompleted(response, tag)) {
	using FunctionType = decltype(onGetFriendRequestsCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x524450, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onGetGauntletsCompleted(gd::string response, gd::string tag) -> decltype(onGetGauntletsCompleted(response, tag)) {
	using FunctionType = decltype(onGetGauntletsCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x529700, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onGetGJChallengesCompleted(gd::string response, gd::string tag) -> decltype(onGetGJChallengesCompleted(response, tag)) {
	using FunctionType = decltype(onGetGJChallengesCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5276f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onGetGJDailyLevelStateCompleted(gd::string response, gd::string tag) -> decltype(onGetGJDailyLevelStateCompleted(response, tag)) {
	using FunctionType = decltype(onGetGJDailyLevelStateCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5285f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onGetGJRewardsCompleted(gd::string response, gd::string tag) -> decltype(onGetGJRewardsCompleted(response, tag)) {
	using FunctionType = decltype(onGetGJRewardsCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x526a90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onGetGJSecretRewardCompleted(gd::string response, gd::string tag) -> decltype(onGetGJSecretRewardCompleted(response, tag)) {
	using FunctionType = decltype(onGetGJSecretRewardCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52af40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onGetGJUserInfoCompleted(gd::string response, gd::string tag) -> decltype(onGetGJUserInfoCompleted(response, tag)) {
	using FunctionType = decltype(onGetGJUserInfoCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x522e20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onGetLeaderboardScoresCompleted(gd::string response, gd::string tag) -> decltype(onGetLeaderboardScoresCompleted(response, tag)) {
	using FunctionType = decltype(onGetLeaderboardScoresCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5207a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onGetLevelCommentsCompleted(gd::string response, gd::string tag) -> decltype(onGetLevelCommentsCompleted(response, tag)) {
	using FunctionType = decltype(onGetLevelCommentsCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x520a90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onGetLevelLeaderboardCompleted(gd::string response, gd::string tag) -> decltype(onGetLevelLeaderboardCompleted(response, tag)) {
	using FunctionType = decltype(onGetLevelLeaderboardCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5294e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onGetLevelListsCompleted(gd::string response, gd::string tag) -> decltype(onGetLevelListsCompleted(response, tag)) {
	using FunctionType = decltype(onGetLevelListsCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52a470, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onGetLevelRateInfoCompleted(gd::string response, gd::string tag) -> decltype(onGetLevelRateInfoCompleted(response, tag)) {
	using FunctionType = decltype(onGetLevelRateInfoCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52b9d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onGetLevelSaveDataCompleted(gd::string response, gd::string tag) -> decltype(onGetLevelSaveDataCompleted(response, tag)) {
	using FunctionType = decltype(onGetLevelSaveDataCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5265a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onGetMapPacksCompleted(gd::string response, gd::string tag) -> decltype(onGetMapPacksCompleted(response, tag)) {
	using FunctionType = decltype(onGetMapPacksCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51f320, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onGetNewsCompleted(gd::string response, gd::string tag) -> decltype(onGetNewsCompleted(response, tag)) {
	using FunctionType = decltype(onGetNewsCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52af30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onGetOnlineLevelsCompleted(gd::string response, gd::string tag) -> decltype(onGetOnlineLevelsCompleted(response, tag)) {
	using FunctionType = decltype(onGetOnlineLevelsCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51e630, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onGetTopArtistsCompleted(gd::string response, gd::string tag) -> decltype(onGetTopArtistsCompleted(response, tag)) {
	using FunctionType = decltype(onGetTopArtistsCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x529db0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onGetUserListCompleted(gd::string response, gd::string tag) -> decltype(onGetUserListCompleted(response, tag)) {
	using FunctionType = decltype(onGetUserListCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x523e60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onGetUserMessagesCompleted(gd::string response, gd::string tag) -> decltype(onGetUserMessagesCompleted(response, tag)) {
	using FunctionType = decltype(onGetUserMessagesCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x524cb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onGetUsersCompleted(gd::string response, gd::string tag) -> decltype(onGetUsersCompleted(response, tag)) {
	using FunctionType = decltype(onGetUsersCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x525bc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onLikeItemCompleted(gd::string response, gd::string tag) -> decltype(onLikeItemCompleted(response, tag)) {
	using FunctionType = decltype(onLikeItemCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x522700, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onProcessHttpRequestCompleted(cocos2d::extension::CCHttpClient* client, cocos2d::extension::CCHttpResponse* response) -> decltype(onProcessHttpRequestCompleted(client, response)) {
	using FunctionType = decltype(onProcessHttpRequestCompleted(client, response))(*)(GameLevelManager*, cocos2d::extension::CCHttpClient*, cocos2d::extension::CCHttpResponse*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51ad60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, client, response);
}

auto GameLevelManager::onRateDemonCompleted(gd::string response, gd::string tag) -> decltype(onRateDemonCompleted(response, tag)) {
	using FunctionType = decltype(onRateDemonCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5291f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onRateLevelAdminCompleted(gd::string response, gd::string tag) -> decltype(onRateLevelAdminCompleted(response, tag)) {
	using FunctionType = decltype(onRateLevelAdminCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52bb20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onRateStarsCompleted(gd::string response, gd::string tag) -> decltype(onRateStarsCompleted(response, tag)) {
	using FunctionType = decltype(onRateStarsCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x520000, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onReadFriendRequestCompleted(gd::string response, gd::string tag) -> decltype(onReadFriendRequestCompleted(response, tag)) {
	using FunctionType = decltype(onReadFriendRequestCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5235f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onRemoveFriendCompleted(gd::string response, gd::string tag) -> decltype(onRemoveFriendCompleted(response, tag)) {
	using FunctionType = decltype(onRemoveFriendCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5236e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onReportLevelCompleted(gd::string response, gd::string tag) -> decltype(onReportLevelCompleted(response, tag)) {
	using FunctionType = decltype(onReportLevelCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x522a80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onRequestUserAccessCompleted(gd::string response, gd::string tag) -> decltype(onRequestUserAccessCompleted(response, tag)) {
	using FunctionType = decltype(onRequestUserAccessCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x526420, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onRestoreItemsCompleted(gd::string response, gd::string tag) -> decltype(onRestoreItemsCompleted(response, tag)) {
	using FunctionType = decltype(onRestoreItemsCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5228b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onSetLevelFeaturedCompleted(gd::string response, gd::string tag) -> decltype(onSetLevelFeaturedCompleted(response, tag)) {
	using FunctionType = decltype(onSetLevelFeaturedCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x520470, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onSetLevelStarsCompleted(gd::string response, gd::string tag) -> decltype(onSetLevelStarsCompleted(response, tag)) {
	using FunctionType = decltype(onSetLevelStarsCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5202f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onSubmitUserInfoCompleted(gd::string response, gd::string tag) -> decltype(onSubmitUserInfoCompleted(response, tag)) {
	using FunctionType = decltype(onSubmitUserInfoCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x522a70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onSuggestLevelStarsCompleted(gd::string response, gd::string tag) -> decltype(onSuggestLevelStarsCompleted(response, tag)) {
	using FunctionType = decltype(onSuggestLevelStarsCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x526890, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onUnblockUserCompleted(gd::string response, gd::string tag) -> decltype(onUnblockUserCompleted(response, tag)) {
	using FunctionType = decltype(onUnblockUserCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x523c20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onUpdateDescriptionCompleted(gd::string response, gd::string tag) -> decltype(onUpdateDescriptionCompleted(response, tag)) {
	using FunctionType = decltype(onUpdateDescriptionCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x522be0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onUpdateLevelCompleted(gd::string response, gd::string tag) -> decltype(onUpdateLevelCompleted(response, tag)) {
	using FunctionType = decltype(onUpdateLevelCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51ff10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onUpdateUserScoreCompleted(gd::string response, gd::string tag) -> decltype(onUpdateUserScoreCompleted(response, tag)) {
	using FunctionType = decltype(onUpdateUserScoreCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x520480, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onUploadCommentCompleted(gd::string response, gd::string tag) -> decltype(onUploadCommentCompleted(response, tag)) {
	using FunctionType = decltype(onUploadCommentCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x521500, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onUploadFriendRequestCompleted(gd::string response, gd::string tag) -> decltype(onUploadFriendRequestCompleted(response, tag)) {
	using FunctionType = decltype(onUploadFriendRequestCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x522fe0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onUploadLevelCompleted(gd::string response, gd::string tag) -> decltype(onUploadLevelCompleted(response, tag)) {
	using FunctionType = decltype(onUploadLevelCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51e390, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onUploadLevelListCompleted(gd::string response, gd::string tag) -> decltype(onUploadLevelListCompleted(response, tag)) {
	using FunctionType = decltype(onUploadLevelListCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52abf0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onUploadUserMessageCompleted(gd::string response, gd::string tag) -> decltype(onUploadUserMessageCompleted(response, tag)) {
	using FunctionType = decltype(onUploadUserMessageCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x525850, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::pageFromCommentKey(char const* key) -> decltype(pageFromCommentKey(key)) {
	using FunctionType = decltype(pageFromCommentKey(key))(*)(GameLevelManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5514e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GameLevelManager::parseRestoreData(gd::string str) -> decltype(parseRestoreData(str)) {
	using FunctionType = decltype(parseRestoreData(str))(*)(GameLevelManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x55a1d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, str);
}

auto GameLevelManager::performNetworkTest() -> decltype(performNetworkTest()) {
	using FunctionType = decltype(performNetworkTest())(*)(GameLevelManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51abc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameLevelManager::ProcessHttpRequest(gd::string endpoint, gd::string params, gd::string tag, GJHttpType httpType) -> decltype(ProcessHttpRequest(endpoint, params, tag, httpType)) {
	using FunctionType = decltype(ProcessHttpRequest(endpoint, params, tag, httpType))(*)(GameLevelManager*, gd::string, gd::string, gd::string, GJHttpType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51af20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, endpoint, params, tag, httpType);
}

auto GameLevelManager::processOnDownloadLevelCompleted(gd::string response, gd::string tag, bool update) -> decltype(processOnDownloadLevelCompleted(response, tag, update)) {
	using FunctionType = decltype(processOnDownloadLevelCompleted(response, tag, update))(*)(GameLevelManager*, gd::string, gd::string, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x544610, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag, update);
}

auto GameLevelManager::purgeUnusedLevels() -> decltype(purgeUnusedLevels()) {
	using FunctionType = decltype(purgeUnusedLevels())(*)(GameLevelManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5399b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameLevelManager::rateDemon(int id, int diff, bool moderator) -> decltype(rateDemon(id, diff, moderator)) {
	using FunctionType = decltype(rateDemon(id, diff, moderator))(*)(GameLevelManager*, int, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x547950, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, diff, moderator);
}

auto GameLevelManager::rateLevelAdmin(int id, int stars, int feature, int rank, bool coins, bool updateRank) -> decltype(rateLevelAdmin(id, stars, feature, rank, coins, updateRank)) {
	using FunctionType = decltype(rateLevelAdmin(id, stars, feature, rank, coins, updateRank))(*)(GameLevelManager*, int, int, int, int, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x553bd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, stars, feature, rank, coins, updateRank);
}

auto GameLevelManager::rateStars(int id, int diff) -> decltype(rateStars(id, diff)) {
	using FunctionType = decltype(rateStars(id, diff))(*)(GameLevelManager*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x545ec0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, diff);
}

auto GameLevelManager::readFriendRequest(int id) -> decltype(readFriendRequest(id)) {
	using FunctionType = decltype(readFriendRequest(id))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x555410, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameLevelManager::removeDelimiterChars(gd::string str, bool colon) -> decltype(removeDelimiterChars(str, colon)) {
	using FunctionType = decltype(removeDelimiterChars(str, colon))(*)(GameLevelManager*, gd::string, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x53e6b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, str, colon);
}

auto GameLevelManager::removeDLFromActive(char const* key) -> decltype(removeDLFromActive(key)) {
	using FunctionType = decltype(removeDLFromActive(key))(*)(GameLevelManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x538ac0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GameLevelManager::removeFriend(int accountID) -> decltype(removeFriend(accountID)) {
	using FunctionType = decltype(removeFriend(accountID))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5558d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, accountID);
}

auto GameLevelManager::removeLevelDownloadedKeysFromDict(cocos2d::CCDictionary* dict) -> decltype(removeLevelDownloadedKeysFromDict(dict)) {
	using FunctionType = decltype(removeLevelDownloadedKeysFromDict(dict))(*)(GameLevelManager*, cocos2d::CCDictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x53a3c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dict);
}

auto GameLevelManager::removeUserFromList(int id, UserListType type) -> decltype(removeUserFromList(id, type)) {
	using FunctionType = decltype(removeUserFromList(id, type))(*)(GameLevelManager*, int, UserListType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x556310, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, type);
}

auto GameLevelManager::reportLevel(int id) -> decltype(reportLevel(id)) {
	using FunctionType = decltype(reportLevel(id))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x55a1e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameLevelManager::requestUserAccess() -> decltype(requestUserAccess()) {
	using FunctionType = decltype(requestUserAccess())(*)(GameLevelManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x557f40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameLevelManager::resetAccountComments(int accountID) -> decltype(resetAccountComments(accountID)) {
	using FunctionType = decltype(resetAccountComments(accountID))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5511e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, accountID);
}

auto GameLevelManager::resetAllTimers() -> decltype(resetAllTimers()) {
	using FunctionType = decltype(resetAllTimers())(*)(GameLevelManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x538ec0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameLevelManager::resetCommentTimersForAccountID(int id) -> decltype(resetCommentTimersForAccountID(id)) {
	using FunctionType = decltype(resetCommentTimersForAccountID(id))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x552cf0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameLevelManager::resetCommentTimersForLevelID(int id, CommentKeyType type) -> decltype(resetCommentTimersForLevelID(id, type)) {
	using FunctionType = decltype(resetCommentTimersForLevelID(id, type))(*)(GameLevelManager*, int, CommentKeyType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x552830, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, type);
}

auto GameLevelManager::resetDailyLevelState(GJTimedLevelType type) -> decltype(resetDailyLevelState(type)) {
	using FunctionType = decltype(resetDailyLevelState(type))(*)(GameLevelManager*, GJTimedLevelType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x559de0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type);
}

auto GameLevelManager::resetGauntlets() -> decltype(resetGauntlets()) {
	using FunctionType = decltype(resetGauntlets())(*)(GameLevelManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x543c70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameLevelManager::resetStoredUserInfo(int id) -> decltype(resetStoredUserInfo(id)) {
	using FunctionType = decltype(resetStoredUserInfo(id))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x54d530, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameLevelManager::resetStoredUserList(UserListType type) -> decltype(resetStoredUserList(type)) {
	using FunctionType = decltype(resetStoredUserList(type))(*)(GameLevelManager*, UserListType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x555370, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type);
}

auto GameLevelManager::resetTimerForKey(char const* key) -> decltype(resetTimerForKey(key)) {
	using FunctionType = decltype(resetTimerForKey(key))(*)(GameLevelManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x538de0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GameLevelManager::restoreItems() -> decltype(restoreItems()) {
	using FunctionType = decltype(restoreItems())(*)(GameLevelManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x559ef0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameLevelManager::saveFetchedLevelLists(cocos2d::CCArray* lists) -> decltype(saveFetchedLevelLists(lists)) {
	using FunctionType = decltype(saveFetchedLevelLists(lists))(*)(GameLevelManager*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x531f50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, lists);
}

auto GameLevelManager::saveFetchedLevels(cocos2d::CCArray* levels) -> decltype(saveFetchedLevels(levels)) {
	using FunctionType = decltype(saveFetchedLevels(levels))(*)(GameLevelManager*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x531350, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, levels);
}

auto GameLevelManager::saveFetchedMapPacks(cocos2d::CCArray* packs) -> decltype(saveFetchedMapPacks(packs)) {
	using FunctionType = decltype(saveFetchedMapPacks(packs))(*)(GameLevelManager*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x532ba0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, packs);
}

auto GameLevelManager::saveGauntlet(GJMapPack* gauntlet) -> decltype(saveGauntlet(gauntlet)) {
	using FunctionType = decltype(saveGauntlet(gauntlet))(*)(GameLevelManager*, GJMapPack*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x543520, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, gauntlet);
}

auto GameLevelManager::saveLevel(GJGameLevel* level) -> decltype(saveLevel(level)) {
	using FunctionType = decltype(saveLevel(level))(*)(GameLevelManager*, GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x537770, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, level);
}

auto GameLevelManager::saveLevelList(GJLevelList* list) -> decltype(saveLevelList(list)) {
	using FunctionType = decltype(saveLevelList(list))(*)(GameLevelManager*, GJLevelList*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x531fb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, list);
}

auto GameLevelManager::saveLocalScore(int id, int value, int type) -> decltype(saveLocalScore(id, value, type)) {
	using FunctionType = decltype(saveLocalScore(id, value, type))(*)(GameLevelManager*, int, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x53a9b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, value, type);
}

auto GameLevelManager::saveMapPack(GJMapPack* pack) -> decltype(saveMapPack(pack)) {
	using FunctionType = decltype(saveMapPack(pack))(*)(GameLevelManager*, GJMapPack*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x532c00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, pack);
}

auto GameLevelManager::setActiveSmartTemplate(GJSmartTemplate* smartTemplate) -> decltype(setActiveSmartTemplate(smartTemplate)) {
	using FunctionType = decltype(setActiveSmartTemplate(smartTemplate))(*)(GameLevelManager*, GJSmartTemplate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x53a9d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, smartTemplate);
}

auto GameLevelManager::setBoolForKey(bool value, char const* key) -> decltype(setBoolForKey(value, key)) {
	using FunctionType = decltype(setBoolForKey(value, key))(*)(GameLevelManager*, bool, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x55ad90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, value, key);
}

auto GameLevelManager::setDiffVal(int diff, bool value) -> decltype(setDiffVal(diff, value)) {
	using FunctionType = decltype(setDiffVal(diff, value))(*)(GameLevelManager*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x55a840, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, diff, value);
}

auto GameLevelManager::setFolderName(int id, gd::string name, bool local) -> decltype(setFolderName(id, name, local)) {
	using FunctionType = decltype(setFolderName(id, name, local))(*)(GameLevelManager*, int, gd::string, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x53a890, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, name, local);
}

auto GameLevelManager::setIntForKey(int value, char const* key) -> decltype(setIntForKey(value, key)) {
	using FunctionType = decltype(setIntForKey(value, key))(*)(GameLevelManager*, int, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x55aba0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, value, key);
}

auto GameLevelManager::setLenVal(int diff, bool value) -> decltype(setLenVal(diff, value)) {
	using FunctionType = decltype(setLenVal(diff, value))(*)(GameLevelManager*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x55aa80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, diff, value);
}

auto GameLevelManager::setLevelFeatured(int id, int rank, bool epic) -> decltype(setLevelFeatured(id, rank, epic)) {
	using FunctionType = decltype(setLevelFeatured(id, rank, epic))(*)(GameLevelManager*, int, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x547e70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, rank, epic);
}

auto GameLevelManager::setLevelStars(int id, int stars, bool coins) -> decltype(setLevelStars(id, stars, coins)) {
	using FunctionType = decltype(setLevelStars(id, stars, coins))(*)(GameLevelManager*, int, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x547e60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, stars, coins);
}

auto GameLevelManager::specialFromLikeKey(char const* key) -> decltype(specialFromLikeKey(key)) {
	using FunctionType = decltype(specialFromLikeKey(key))(*)(GameLevelManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x558480, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GameLevelManager::storeCommentsResult(cocos2d::CCArray* comments, gd::string pageInfo, char const* key) -> decltype(storeCommentsResult(comments, pageInfo, key)) {
	using FunctionType = decltype(storeCommentsResult(comments, pageInfo, key))(*)(GameLevelManager*, cocos2d::CCArray*, gd::string, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x54e290, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, comments, pageInfo, key);
}

auto GameLevelManager::storeDailyLevelState(int id, int remaining, GJTimedLevelType type) -> decltype(storeDailyLevelState(id, remaining, type)) {
	using FunctionType = decltype(storeDailyLevelState(id, remaining, type))(*)(GameLevelManager*, int, int, GJTimedLevelType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x559cc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, remaining, type);
}

auto GameLevelManager::storeFriendRequest(GJFriendRequest* request) -> decltype(storeFriendRequest(request)) {
	using FunctionType = decltype(storeFriendRequest(request))(*)(GameLevelManager*, GJFriendRequest*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x54d500, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, request);
}

auto GameLevelManager::storeSearchResult(cocos2d::CCArray* levels, gd::string pageInfo, char const* searchKey) -> decltype(storeSearchResult(levels, pageInfo, searchKey)) {
	using FunctionType = decltype(storeSearchResult(levels, pageInfo, searchKey))(*)(GameLevelManager*, cocos2d::CCArray*, gd::string, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x538130, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, levels, pageInfo, searchKey);
}

auto GameLevelManager::storeUserInfo(GJUserScore* score) -> decltype(storeUserInfo(score)) {
	using FunctionType = decltype(storeUserInfo(score))(*)(GameLevelManager*, GJUserScore*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x54cff0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, score);
}

auto GameLevelManager::storeUserMessage(GJUserMessage* message) -> decltype(storeUserMessage(message)) {
	using FunctionType = decltype(storeUserMessage(message))(*)(GameLevelManager*, GJUserMessage*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x54d570, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, message);
}

auto GameLevelManager::storeUserMessageReply(int id, GJUserMessage* message) -> decltype(storeUserMessageReply(id, message)) {
	using FunctionType = decltype(storeUserMessageReply(id, message))(*)(GameLevelManager*, int, GJUserMessage*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x54d5b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, message);
}

auto GameLevelManager::storeUserName(int userID, int accountID, gd::string userName) -> decltype(storeUserName(userID, accountID, userName)) {
	using FunctionType = decltype(storeUserName(userID, accountID, userName))(*)(GameLevelManager*, int, int, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52e100, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, userID, accountID, userName);
}

auto GameLevelManager::storeUserNames(gd::string usernameString) -> decltype(storeUserNames(usernameString)) {
	using FunctionType = decltype(storeUserNames(usernameString))(*)(GameLevelManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52d930, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, usernameString);
}

auto GameLevelManager::submitUserInfo() -> decltype(submitUserInfo()) {
	using FunctionType = decltype(submitUserInfo())(*)(GameLevelManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x54a0c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameLevelManager::suggestLevelStars(int id, int stars, int feature) -> decltype(suggestLevelStars(id, stars, feature)) {
	using FunctionType = decltype(suggestLevelStars(id, stars, feature))(*)(GameLevelManager*, int, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x547360, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, stars, feature);
}

auto GameLevelManager::tryGetUsername(int accountID) -> decltype(tryGetUsername(accountID)) {
	using FunctionType = decltype(tryGetUsername(accountID))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52e500, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, accountID);
}

auto GameLevelManager::typeFromCommentKey(char const* key) -> decltype(typeFromCommentKey(key)) {
	using FunctionType = decltype(typeFromCommentKey(key))(*)(GameLevelManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5515e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GameLevelManager::typeFromLikeKey(char const* key) -> decltype(typeFromLikeKey(key)) {
	using FunctionType = decltype(typeFromLikeKey(key))(*)(GameLevelManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x557c40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GameLevelManager::unblockUser(int id) -> decltype(unblockUser(id)) {
	using FunctionType = decltype(unblockUser(id))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5563c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameLevelManager::unfollowUser(int id) -> decltype(unfollowUser(id)) {
	using FunctionType = decltype(unfollowUser(id))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x53a2d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameLevelManager::unrateLevelAdmin(int id) -> decltype(unrateLevelAdmin(id)) {
	using FunctionType = decltype(unrateLevelAdmin(id))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x553be0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameLevelManager::updateDescription(int id, gd::string description) -> decltype(updateDescription(id, description)) {
	using FunctionType = decltype(updateDescription(id, description))(*)(GameLevelManager*, int, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x556ba0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, description);
}

auto GameLevelManager::updateLevel(GJGameLevel* level) -> decltype(updateLevel(level)) {
	using FunctionType = decltype(updateLevel(level))(*)(GameLevelManager*, GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x545b60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, level);
}

auto GameLevelManager::updateLevelOrders() -> decltype(updateLevelOrders()) {
	using FunctionType = decltype(updateLevelOrders())(*)(GameLevelManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x534ea0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameLevelManager::updateLevelRankAdmin(int id, int rank) -> decltype(updateLevelRankAdmin(id, rank)) {
	using FunctionType = decltype(updateLevelRankAdmin(id, rank))(*)(GameLevelManager*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x553bf0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, rank);
}

auto GameLevelManager::updateLevelRewards(GJGameLevel* level) -> decltype(updateLevelRewards(level)) {
	using FunctionType = decltype(updateLevelRewards(level))(*)(GameLevelManager*, GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52ec40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, level);
}

auto GameLevelManager::updateSavedLevelList(GJLevelList* list) -> decltype(updateSavedLevelList(list)) {
	using FunctionType = decltype(updateSavedLevelList(list))(*)(GameLevelManager*, GJLevelList*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x542900, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, list);
}

auto GameLevelManager::updateUsernames() -> decltype(updateUsernames()) {
	using FunctionType = decltype(updateUsernames())(*)(GameLevelManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x539f60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameLevelManager::updateUserScore() -> decltype(updateUserScore()) {
	using FunctionType = decltype(updateUserScore())(*)(GameLevelManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x547e80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GameLevelManager::uploadAccountComment(gd::string content) -> decltype(uploadAccountComment(content)) {
	using FunctionType = decltype(uploadAccountComment(content))(*)(GameLevelManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5527b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, content);
}

auto GameLevelManager::uploadComment(gd::string content, CommentType type, int levelID, int percent) -> decltype(uploadComment(content, type, levelID, percent)) {
	using FunctionType = decltype(uploadComment(content, type, levelID, percent))(*)(GameLevelManager*, gd::string, CommentType, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x551870, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, content, type, levelID, percent);
}

auto GameLevelManager::uploadFriendRequest(int accountID, gd::string content) -> decltype(uploadFriendRequest(accountID, content)) {
	using FunctionType = decltype(uploadFriendRequest(accountID, content))(*)(GameLevelManager*, int, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x553f60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, accountID, content);
}

auto GameLevelManager::uploadLevel(GJGameLevel* level) -> decltype(uploadLevel(level)) {
	using FunctionType = decltype(uploadLevel(level))(*)(GameLevelManager*, GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x53d400, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, level);
}

auto GameLevelManager::uploadLevelComment(int levelID, gd::string content, int percent) -> decltype(uploadLevelComment(levelID, content, percent)) {
	using FunctionType = decltype(uploadLevelComment(levelID, content, percent))(*)(GameLevelManager*, int, gd::string, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5517e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, levelID, content, percent);
}

auto GameLevelManager::uploadLevelList(GJLevelList* list) -> decltype(uploadLevelList(list)) {
	using FunctionType = decltype(uploadLevelList(list))(*)(GameLevelManager*, GJLevelList*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x541200, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, list);
}

auto GameLevelManager::uploadUserMessage(int accountID, gd::string subject, gd::string content) -> decltype(uploadUserMessage(accountID, subject, content)) {
	using FunctionType = decltype(uploadUserMessage(accountID, subject, content))(*)(GameLevelManager*, int, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x54e8a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, accountID, subject, content);
}

auto GameLevelManager::userIDForAccountID(int id) -> decltype(userIDForAccountID(id)) {
	using FunctionType = decltype(userIDForAccountID(id))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52ea10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameLevelManager::userInfoForAccountID(int id) -> decltype(userInfoForAccountID(id)) {
	using FunctionType = decltype(userInfoForAccountID(id))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52ea30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameLevelManager::userNameForUserID(int id) -> decltype(userNameForUserID(id)) {
	using FunctionType = decltype(userNameForUserID(id))(*)(GameLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52e360, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GameLevelManager::verifyContainerOnlyHasLevels(cocos2d::CCDictionary* dict) -> decltype(verifyContainerOnlyHasLevels(dict)) {
	using FunctionType = decltype(verifyContainerOnlyHasLevels(dict))(*)(GameLevelManager*, cocos2d::CCDictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x53b160, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dict);
}

auto GameLevelManager::verifyLevelState(GJGameLevel* level) -> decltype(verifyLevelState(level)) {
	using FunctionType = decltype(verifyLevelState(level))(*)(GameLevelManager*, GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52ea70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, level);
}

auto GameLevelManager::writeSpecialFilters(GJSearchObject* object) -> decltype(writeSpecialFilters(object)) {
	using FunctionType = decltype(writeSpecialFilters(object))(*)(GameLevelManager*, GJSearchObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x53f5e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}
