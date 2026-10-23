
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GJMultiplayerManager.hpp>
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

auto GJMultiplayerManager::sharedState() -> decltype(sharedState()) {
	using FunctionType = decltype(sharedState())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x658b50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto GJMultiplayerManager::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJMultiplayerManager::init), this);
	using FunctionType = decltype(init())(*)(GJMultiplayerManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x65a2c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJMultiplayerManager::addComment(gd::string str, int lobbyID) -> decltype(addComment(str, lobbyID)) {
	using FunctionType = decltype(addComment(str, lobbyID))(*)(GJMultiplayerManager*, gd::string, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x65aef0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, str, lobbyID);
}

auto GJMultiplayerManager::addDLToActive(char const* tag) -> decltype(addDLToActive(tag)) {
	using FunctionType = decltype(addDLToActive(tag))(*)(GJMultiplayerManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x65a430, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, tag);
}

auto GJMultiplayerManager::addDLToActive(char const* tag, cocos2d::CCObject* obj) -> decltype(addDLToActive(tag, obj)) {
	using FunctionType = decltype(addDLToActive(tag, obj))(*)(GJMultiplayerManager*, char const*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x65a460, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, tag, obj);
}

auto GJMultiplayerManager::createAndAddComment(gd::string text, int lobbyID) -> decltype(createAndAddComment(text, lobbyID)) {
	using FunctionType = decltype(createAndAddComment(text, lobbyID))(*)(GJMultiplayerManager*, gd::string, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x65bd70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, text, lobbyID);
}

auto GJMultiplayerManager::dataLoaded(DS_Dictionary* dict) -> decltype(dataLoaded(dict)) {
	using FunctionType = decltype(dataLoaded(dict))(*)(GJMultiplayerManager*, DS_Dictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x65bf40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dict);
}

auto GJMultiplayerManager::encodeDataTo(DS_Dictionary* dict) -> decltype(encodeDataTo(dict)) {
	using FunctionType = decltype(encodeDataTo(dict))(*)(GJMultiplayerManager*, DS_Dictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x65bf30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dict);
}

auto GJMultiplayerManager::exitLobby(int id) -> decltype(exitLobby(id)) {
	using FunctionType = decltype(exitLobby(id))(*)(GJMultiplayerManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x65b100, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GJMultiplayerManager::firstSetup() -> decltype(firstSetup()) {
	using FunctionType = decltype(firstSetup())(*)(GJMultiplayerManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x65bf20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJMultiplayerManager::getBasePostString() -> decltype(getBasePostString()) {
	using FunctionType = decltype(getBasePostString())(*)(GJMultiplayerManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x65a9b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJMultiplayerManager::getDLObject(char const* tag) -> decltype(getDLObject(tag)) {
	using FunctionType = decltype(getDLObject(tag))(*)(GJMultiplayerManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x65a350, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, tag);
}

auto GJMultiplayerManager::getLastCommentIDForGame(int id) -> decltype(getLastCommentIDForGame(id)) {
	using FunctionType = decltype(getLastCommentIDForGame(id))(*)(GJMultiplayerManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x65aaa0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GJMultiplayerManager::handleIt(bool success, gd::string response, gd::string tag, GJHttpType type) -> decltype(handleIt(success, response, tag, type)) {
	using FunctionType = decltype(handleIt(success, response, tag, type))(*)(GJMultiplayerManager*, bool, gd::string, gd::string, GJHttpType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x659090, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, success, response, tag, type);
}

auto GJMultiplayerManager::handleItDelayed(bool success, gd::string response, gd::string tag, GJHttpType type) -> decltype(handleItDelayed(success, response, tag, type)) {
	using FunctionType = decltype(handleItDelayed(success, response, tag, type))(*)(GJMultiplayerManager*, bool, gd::string, gd::string, GJHttpType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6594d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, success, response, tag, type);
}

auto GJMultiplayerManager::handleItND(cocos2d::CCNode* node, void* data) -> decltype(handleItND(node, data)) {
	using FunctionType = decltype(handleItND(node, data))(*)(GJMultiplayerManager*, cocos2d::CCNode*, void*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x659610, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, node, data);
}

auto GJMultiplayerManager::isDLActive(char const* tag) -> decltype(isDLActive(tag)) {
	using FunctionType = decltype(isDLActive(tag))(*)(GJMultiplayerManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x65a330, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, tag);
}

auto GJMultiplayerManager::joinLobby(int id) -> decltype(joinLobby(id)) {
	using FunctionType = decltype(joinLobby(id))(*)(GJMultiplayerManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x65a630, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto GJMultiplayerManager::onExitLobbyCompleted(gd::string response, gd::string tag) -> decltype(onExitLobbyCompleted(response, tag)) {
	using FunctionType = decltype(onExitLobbyCompleted(response, tag))(*)(GJMultiplayerManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x65a060, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GJMultiplayerManager::onJoinLobbyCompleted(gd::string response, gd::string tag) -> decltype(onJoinLobbyCompleted(response, tag)) {
	using FunctionType = decltype(onJoinLobbyCompleted(response, tag))(*)(GJMultiplayerManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x659730, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GJMultiplayerManager::onProcessHttpRequestCompleted(cocos2d::extension::CCHttpClient* client, cocos2d::extension::CCHttpResponse* response) -> decltype(onProcessHttpRequestCompleted(client, response)) {
	using FunctionType = decltype(onProcessHttpRequestCompleted(client, response))(*)(GJMultiplayerManager*, cocos2d::extension::CCHttpClient*, cocos2d::extension::CCHttpResponse*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x658ed0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, client, response);
}

auto GJMultiplayerManager::onUploadCommentCompleted(gd::string response, gd::string tag) -> decltype(onUploadCommentCompleted(response, tag)) {
	using FunctionType = decltype(onUploadCommentCompleted(response, tag))(*)(GJMultiplayerManager*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x65a140, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GJMultiplayerManager::ProcessHttpRequest(gd::string url, gd::string params, gd::string tag, GJHttpType type) -> decltype(ProcessHttpRequest(url, params, tag, type)) {
	using FunctionType = decltype(ProcessHttpRequest(url, params, tag, type))(*)(GJMultiplayerManager*, gd::string, gd::string, gd::string, GJHttpType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x658bd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, url, params, tag, type);
}

auto GJMultiplayerManager::removeDLFromActive(char const* tag) -> decltype(removeDLFromActive(tag)) {
	using FunctionType = decltype(removeDLFromActive(tag))(*)(GJMultiplayerManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x65a550, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, tag);
}

auto GJMultiplayerManager::uploadComment(gd::string text, int lobbyID) -> decltype(uploadComment(text, lobbyID)) {
	using FunctionType = decltype(uploadComment(text, lobbyID))(*)(GJMultiplayerManager*, gd::string, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x65b3e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, text, lobbyID);
}
