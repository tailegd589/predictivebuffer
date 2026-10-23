
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/FRequestProfilePage.hpp>
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

auto FRequestProfilePage::create(bool sent) -> decltype(create(sent)) {
	using FunctionType = decltype(create(sent))(*)(bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6984d4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(sent);
}

auto FRequestProfilePage::registerWithTouchDispatcher() -> decltype(registerWithTouchDispatcher()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&FRequestProfilePage::registerWithTouchDispatcher), this);
	using FunctionType = decltype(registerWithTouchDispatcher())(*)(FRequestProfilePage*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x699b64, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto FRequestProfilePage::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&FRequestProfilePage::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(FRequestProfilePage*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x699b58, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto FRequestProfilePage::FLAlert_Clicked(FLAlertLayer* layer, bool btn2) -> decltype(FLAlert_Clicked(layer, btn2)) {
	auto self = addresser::thunkAdjust(Resolve<FLAlertLayer*, bool>::func(&FRequestProfilePage::FLAlert_Clicked), this);
	using FunctionType = decltype(FLAlert_Clicked(layer, btn2))(*)(FRequestProfilePage*, FLAlertLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x699a60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, layer, btn2);
}

auto FRequestProfilePage::onClosePopup(UploadActionPopup* popup) -> decltype(onClosePopup(popup)) {
	auto self = addresser::thunkAdjust(Resolve<UploadActionPopup*>::func(&FRequestProfilePage::onClosePopup), this);
	using FunctionType = decltype(onClosePopup(popup))(*)(FRequestProfilePage*, UploadActionPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x699b9c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, popup);
}

auto FRequestProfilePage::uploadActionFinished(int id, int response) -> decltype(uploadActionFinished(id, response)) {
	auto self = addresser::thunkAdjust(Resolve<int, int>::func(&FRequestProfilePage::uploadActionFinished), this);
	using FunctionType = decltype(uploadActionFinished(id, response))(*)(FRequestProfilePage*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x699c24, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, id, response);
}

auto FRequestProfilePage::uploadActionFailed(int id, int response) -> decltype(uploadActionFailed(id, response)) {
	auto self = addresser::thunkAdjust(Resolve<int, int>::func(&FRequestProfilePage::uploadActionFailed), this);
	using FunctionType = decltype(uploadActionFailed(id, response))(*)(FRequestProfilePage*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x699de4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, id, response);
}

auto FRequestProfilePage::loadFRequestsFinished(cocos2d::CCArray* scores, char const* key) -> decltype(loadFRequestsFinished(scores, key)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCArray*, char const*>::func(&FRequestProfilePage::loadFRequestsFinished), this);
	using FunctionType = decltype(loadFRequestsFinished(scores, key))(*)(FRequestProfilePage*, cocos2d::CCArray*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69a1a8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, scores, key);
}

auto FRequestProfilePage::loadFRequestsFailed(char const* key, GJErrorCode errorType) -> decltype(loadFRequestsFailed(key, errorType)) {
	auto self = addresser::thunkAdjust(Resolve<char const*, GJErrorCode>::func(&FRequestProfilePage::loadFRequestsFailed), this);
	using FunctionType = decltype(loadFRequestsFailed(key, errorType))(*)(FRequestProfilePage*, char const*, GJErrorCode);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69a2b4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, key, errorType);
}

auto FRequestProfilePage::setupPageInfo(gd::string info, char const* key) -> decltype(setupPageInfo(info, key)) {
	auto self = addresser::thunkAdjust(Resolve<gd::string, char const*>::func(&FRequestProfilePage::setupPageInfo), this);
	using FunctionType = decltype(setupPageInfo(info, key))(*)(FRequestProfilePage*, gd::string, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69a414, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, info, key);
}

auto FRequestProfilePage::forceReloadRequests(bool sent) -> decltype(forceReloadRequests(sent)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&FRequestProfilePage::forceReloadRequests), this);
	using FunctionType = decltype(forceReloadRequests(sent))(*)(FRequestProfilePage*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69a3e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, sent);
}

auto FRequestProfilePage::deleteSelected() -> decltype(deleteSelected()) {
	using FunctionType = decltype(deleteSelected())(*)(FRequestProfilePage*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x699890, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto FRequestProfilePage::init(bool sent) -> decltype(init(sent)) {
	using FunctionType = decltype(init(sent))(*)(FRequestProfilePage*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69860c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sent);
}

auto FRequestProfilePage::isCorrect(char const* key) -> decltype(isCorrect(key)) {
	using FunctionType = decltype(isCorrect(key))(*)(FRequestProfilePage*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x699f2c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto FRequestProfilePage::loadPage(int page) -> decltype(loadPage(page)) {
	using FunctionType = decltype(loadPage(page))(*)(FRequestProfilePage*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6994dc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, page);
}

auto FRequestProfilePage::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	using FunctionType = decltype(onClose(sender))(*)(FRequestProfilePage*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x699014, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto FRequestProfilePage::onDeleteSelected(cocos2d::CCObject* sender) -> decltype(onDeleteSelected(sender)) {
	using FunctionType = decltype(onDeleteSelected(sender))(*)(FRequestProfilePage*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6991f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto FRequestProfilePage::onNextPage(cocos2d::CCObject* sender) -> decltype(onNextPage(sender)) {
	using FunctionType = decltype(onNextPage(sender))(*)(FRequestProfilePage*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69946c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto FRequestProfilePage::onPrevPage(cocos2d::CCObject* sender) -> decltype(onPrevPage(sender)) {
	using FunctionType = decltype(onPrevPage(sender))(*)(FRequestProfilePage*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x699460, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto FRequestProfilePage::onSentRequests(cocos2d::CCObject* sender) -> decltype(onSentRequests(sender)) {
	using FunctionType = decltype(onSentRequests(sender))(*)(FRequestProfilePage*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x699118, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto FRequestProfilePage::onToggleAllObjects(cocos2d::CCObject* sender) -> decltype(onToggleAllObjects(sender)) {
	using FunctionType = decltype(onToggleAllObjects(sender))(*)(FRequestProfilePage*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6993bc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto FRequestProfilePage::onUpdate(cocos2d::CCObject* sender) -> decltype(onUpdate(sender)) {
	using FunctionType = decltype(onUpdate(sender))(*)(FRequestProfilePage*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x699478, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto FRequestProfilePage::setupCommentsBrowser(cocos2d::CCArray* scores) -> decltype(setupCommentsBrowser(scores)) {
	using FunctionType = decltype(setupCommentsBrowser(scores))(*)(FRequestProfilePage*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69a034, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, scores);
}

auto FRequestProfilePage::untoggleAll() -> decltype(untoggleAll()) {
	using FunctionType = decltype(untoggleAll())(*)(FRequestProfilePage*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x699af0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto FRequestProfilePage::updateLevelsLabel() -> decltype(updateLevelsLabel()) {
	using FunctionType = decltype(updateLevelsLabel())(*)(FRequestProfilePage*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69a9b4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto FRequestProfilePage::updatePageArrows() -> decltype(updatePageArrows()) {
	using FunctionType = decltype(updatePageArrows())(*)(FRequestProfilePage*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69a9b8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
