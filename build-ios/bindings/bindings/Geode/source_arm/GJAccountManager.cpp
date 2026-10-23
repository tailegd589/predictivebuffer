
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GJAccountManager.hpp>
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

auto GJAccountManager::sharedState() -> decltype(sharedState()) {
	using FunctionType = decltype(sharedState())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0xb6520, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto GJAccountManager::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJAccountManager::init), this);
	using FunctionType = decltype(init())(*)(GJAccountManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xb8b04, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJAccountManager::addDLToActive(char const* tag) -> decltype(addDLToActive(tag)) {
	using FunctionType = decltype(addDLToActive(tag))(*)(GJAccountManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xb8c5c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, tag);
}

auto GJAccountManager::addDLToActive(char const* tag, cocos2d::CCObject* object) -> decltype(addDLToActive(tag, object)) {
	using FunctionType = decltype(addDLToActive(tag, object))(*)(GJAccountManager*, char const*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xb8c8c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, tag, object);
}

auto GJAccountManager::backupAccount(gd::string url) -> decltype(backupAccount(url)) {
	using FunctionType = decltype(backupAccount(url))(*)(GJAccountManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xb9cb8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, url);
}

auto GJAccountManager::dataLoaded(DS_Dictionary* dict) -> decltype(dataLoaded(dict)) {
	using FunctionType = decltype(dataLoaded(dict))(*)(GJAccountManager*, DS_Dictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xbad8c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dict);
}

auto GJAccountManager::encodeDataTo(DS_Dictionary* dict) -> decltype(encodeDataTo(dict)) {
	using FunctionType = decltype(encodeDataTo(dict))(*)(GJAccountManager*, DS_Dictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xbad34, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dict);
}

auto GJAccountManager::firstSetup() -> decltype(firstSetup()) {
	using FunctionType = decltype(firstSetup())(*)(GJAccountManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xbad30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJAccountManager::getAccountBackupURL() -> decltype(getAccountBackupURL()) {
	using FunctionType = decltype(getAccountBackupURL())(*)(GJAccountManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xb999c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJAccountManager::getAccountSyncURL() -> decltype(getAccountSyncURL()) {
	using FunctionType = decltype(getAccountSyncURL())(*)(GJAccountManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xba160, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJAccountManager::getDLObject(char const* tag) -> decltype(getDLObject(tag)) {
	using FunctionType = decltype(getDLObject(tag))(*)(GJAccountManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xb8b58, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, tag);
}

auto GJAccountManager::getShaPassword(gd::string password) -> decltype(getShaPassword(password)) {
	using FunctionType = decltype(getShaPassword(password))(*)(GJAccountManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xbaf60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, password);
}

auto GJAccountManager::handleIt(bool success, gd::string response, gd::string tag, GJHttpType type) -> decltype(handleIt(success, response, tag, type)) {
	using FunctionType = decltype(handleIt(success, response, tag, type))(*)(GJAccountManager*, bool, gd::string, gd::string, GJHttpType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xb6910, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, success, response, tag, type);
}

auto GJAccountManager::handleItDelayed(bool success, gd::string response, gd::string tag, GJHttpType type) -> decltype(handleItDelayed(success, response, tag, type)) {
	using FunctionType = decltype(handleItDelayed(success, response, tag, type))(*)(GJAccountManager*, bool, gd::string, gd::string, GJHttpType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xb6f8c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, success, response, tag, type);
}

auto GJAccountManager::handleItND(cocos2d::CCNode* node, void* data) -> decltype(handleItND(node, data)) {
	using FunctionType = decltype(handleItND(node, data))(*)(GJAccountManager*, cocos2d::CCNode*, void*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xb70f8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, node, data);
}

auto GJAccountManager::isDLActive(char const* tag) -> decltype(isDLActive(tag)) {
	using FunctionType = decltype(isDLActive(tag))(*)(GJAccountManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xb8b3c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, tag);
}

auto GJAccountManager::linkToAccount(gd::string username, gd::string gjp2, int accountID, int userID) -> decltype(linkToAccount(username, gjp2, accountID, userID)) {
	using FunctionType = decltype(linkToAccount(username, gjp2, accountID, userID))(*)(GJAccountManager*, gd::string, gd::string, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xba734, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, username, gjp2, accountID, userID);
}

auto GJAccountManager::loginAccount(gd::string username, gd::string gjp2) -> decltype(loginAccount(username, gjp2)) {
	using FunctionType = decltype(loginAccount(username, gjp2))(*)(GJAccountManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xb911c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, username, gjp2);
}

auto GJAccountManager::onBackupAccountCompleted(gd::string response, gd::string tag) -> decltype(onBackupAccountCompleted(response, tag)) {
	using FunctionType = decltype(onBackupAccountCompleted(response, tag))(*)(GJAccountManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xb7654, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GJAccountManager::onGetAccountBackupURLCompleted(gd::string response, gd::string tag) -> decltype(onGetAccountBackupURLCompleted(response, tag)) {
	using FunctionType = decltype(onGetAccountBackupURLCompleted(response, tag))(*)(GJAccountManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xb8604, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GJAccountManager::onGetAccountSyncURLCompleted(gd::string response, gd::string tag) -> decltype(onGetAccountSyncURLCompleted(response, tag)) {
	using FunctionType = decltype(onGetAccountSyncURLCompleted(response, tag))(*)(GJAccountManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xb882c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GJAccountManager::onLoginAccountCompleted(gd::string response, gd::string tag) -> decltype(onLoginAccountCompleted(response, tag)) {
	using FunctionType = decltype(onLoginAccountCompleted(response, tag))(*)(GJAccountManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xb72f8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GJAccountManager::onProcessHttpRequestCompleted(cocos2d::extension::CCHttpClient* client, cocos2d::extension::CCHttpResponse* response) -> decltype(onProcessHttpRequestCompleted(client, response)) {
	using FunctionType = decltype(onProcessHttpRequestCompleted(client, response))(*)(GJAccountManager*, cocos2d::extension::CCHttpClient*, cocos2d::extension::CCHttpResponse*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xb6720, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, client, response);
}

auto GJAccountManager::onRegisterAccountCompleted(gd::string response, gd::string tag) -> decltype(onRegisterAccountCompleted(response, tag)) {
	using FunctionType = decltype(onRegisterAccountCompleted(response, tag))(*)(GJAccountManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xb721c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GJAccountManager::onSyncAccountCompleted(gd::string response, gd::string tag) -> decltype(onSyncAccountCompleted(response, tag)) {
	using FunctionType = decltype(onSyncAccountCompleted(response, tag))(*)(GJAccountManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xb7900, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GJAccountManager::onUpdateAccountSettingsCompleted(gd::string response, gd::string tag) -> decltype(onUpdateAccountSettingsCompleted(response, tag)) {
	using FunctionType = decltype(onUpdateAccountSettingsCompleted(response, tag))(*)(GJAccountManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xb8538, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GJAccountManager::ProcessHttpRequest(gd::string url, gd::string params, gd::string tag, GJHttpType type) -> decltype(ProcessHttpRequest(url, params, tag, type)) {
	using FunctionType = decltype(ProcessHttpRequest(url, params, tag, type))(*)(GJAccountManager*, gd::string, gd::string, gd::string, GJHttpType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xb65cc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, url, params, tag, type);
}

auto GJAccountManager::registerAccount(gd::string response, gd::string tag, gd::string data) -> decltype(registerAccount(response, tag, data)) {
	using FunctionType = decltype(registerAccount(response, tag, data))(*)(GJAccountManager*, gd::string, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xb8e84, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag, data);
}

auto GJAccountManager::removeDLFromActive(char const* tag) -> decltype(removeDLFromActive(tag)) {
	using FunctionType = decltype(removeDLFromActive(tag))(*)(GJAccountManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xb8d8c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, tag);
}

auto GJAccountManager::syncAccount(gd::string url) -> decltype(syncAccount(url)) {
	using FunctionType = decltype(syncAccount(url))(*)(GJAccountManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xba484, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, url);
}

auto GJAccountManager::unlinkFromAccount() -> decltype(unlinkFromAccount()) {
	using FunctionType = decltype(unlinkFromAccount())(*)(GJAccountManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xba848, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJAccountManager::updateAccountSettings(int messageStatus, int friendRequestStatus, int commentStatus, gd::string youtube, gd::string twitter, gd::string twitch, gd::string instagram, gd::string tiktok, gd::string discord, gd::string custom) -> decltype(updateAccountSettings(messageStatus, friendRequestStatus, commentStatus, youtube, twitter, twitch, instagram, tiktok, discord, custom)) {
	using FunctionType = decltype(updateAccountSettings(messageStatus, friendRequestStatus, commentStatus, youtube, twitter, twitch, instagram, tiktok, discord, custom))(*)(GJAccountManager*, int, int, int, gd::string, gd::string, gd::string, gd::string, gd::string, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xba8e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, messageStatus, friendRequestStatus, commentStatus, youtube, twitter, twitch, instagram, tiktok, discord, custom);
}
