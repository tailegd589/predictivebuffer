
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/AccountLoginLayer.hpp>
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

auto AccountLoginLayer::create(gd::string username) -> decltype(create(username)) {
	using FunctionType = decltype(create(username))(*)(gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x498c10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(username);
}

auto AccountLoginLayer::registerWithTouchDispatcher() -> decltype(registerWithTouchDispatcher()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&AccountLoginLayer::registerWithTouchDispatcher), this);
	using FunctionType = decltype(registerWithTouchDispatcher())(*)(AccountLoginLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x49ab30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto AccountLoginLayer::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&AccountLoginLayer::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(AccountLoginLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x49a9f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto AccountLoginLayer::FLAlert_Clicked(FLAlertLayer* layer, bool btn2) -> decltype(FLAlert_Clicked(layer, btn2)) {
	auto self = addresser::thunkAdjust(Resolve<FLAlertLayer*, bool>::func(&AccountLoginLayer::FLAlert_Clicked), this);
	using FunctionType = decltype(FLAlert_Clicked(layer, btn2))(*)(AccountLoginLayer*, FLAlertLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x49a830, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, layer, btn2);
}

auto AccountLoginLayer::textInputOpened(CCTextInputNode* node) -> decltype(textInputOpened(node)) {
	auto self = addresser::thunkAdjust(Resolve<CCTextInputNode*>::func(&AccountLoginLayer::textInputOpened), this);
	using FunctionType = decltype(textInputOpened(node))(*)(AccountLoginLayer*, CCTextInputNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x49acd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, node);
}

auto AccountLoginLayer::textInputClosed(CCTextInputNode* node) -> decltype(textInputClosed(node)) {
	auto self = addresser::thunkAdjust(Resolve<CCTextInputNode*>::func(&AccountLoginLayer::textInputClosed), this);
	using FunctionType = decltype(textInputClosed(node))(*)(AccountLoginLayer*, CCTextInputNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x49ab70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, node);
}

auto AccountLoginLayer::textChanged(CCTextInputNode* node) -> decltype(textChanged(node)) {
	auto self = addresser::thunkAdjust(Resolve<CCTextInputNode*>::func(&AccountLoginLayer::textChanged), this);
	using FunctionType = decltype(textChanged(node))(*)(AccountLoginLayer*, CCTextInputNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x49acf0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, node);
}

auto AccountLoginLayer::loginAccountFinished(int accountID, int userID) -> decltype(loginAccountFinished(accountID, userID)) {
	auto self = addresser::thunkAdjust(Resolve<int, int>::func(&AccountLoginLayer::loginAccountFinished), this);
	using FunctionType = decltype(loginAccountFinished(accountID, userID))(*)(AccountLoginLayer*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x49a1a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, accountID, userID);
}

auto AccountLoginLayer::loginAccountFailed(AccountError errorType) -> decltype(loginAccountFailed(errorType)) {
	auto self = addresser::thunkAdjust(Resolve<AccountError>::func(&AccountLoginLayer::loginAccountFailed), this);
	using FunctionType = decltype(loginAccountFailed(errorType))(*)(AccountLoginLayer*, AccountError);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x49a520, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, errorType);
}

auto AccountLoginLayer::createTextBackground(cocos2d::CCPoint position, char const* text, cocos2d::CCSize size) -> decltype(createTextBackground(position, text, size)) {
	using FunctionType = decltype(createTextBackground(position, text, size))(*)(AccountLoginLayer*, cocos2d::CCPoint, char const*, cocos2d::CCSize);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x499ee0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, position, text, size);
}

auto AccountLoginLayer::createTextInput(cocos2d::CCPoint position, cocos2d::CCSize size, char const* text, int tag) -> decltype(createTextInput(position, size, text, tag)) {
	using FunctionType = decltype(createTextInput(position, size, text, tag))(*)(AccountLoginLayer*, cocos2d::CCPoint, cocos2d::CCSize, char const*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x49a080, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, position, size, text, tag);
}

auto AccountLoginLayer::createTextLabel(cocos2d::CCPoint position, char const* text, cocos2d::CCSize size) -> decltype(createTextLabel(position, text, size)) {
	using FunctionType = decltype(createTextLabel(position, text, size))(*)(AccountLoginLayer*, cocos2d::CCPoint, char const*, cocos2d::CCSize);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x499fa0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, position, text, size);
}

auto AccountLoginLayer::disableNodes() -> decltype(disableNodes()) {
	using FunctionType = decltype(disableNodes())(*)(AccountLoginLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x49a910, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto AccountLoginLayer::hideLoadingUI() -> decltype(hideLoadingUI()) {
	using FunctionType = decltype(hideLoadingUI())(*)(AccountLoginLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x49a470, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto AccountLoginLayer::init(gd::string username) -> decltype(init(username)) {
	using FunctionType = decltype(init(username))(*)(AccountLoginLayer*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x498df0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, username);
}

auto AccountLoginLayer::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	using FunctionType = decltype(onClose(sender))(*)(AccountLoginLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x499a90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto AccountLoginLayer::onForgotPassword(cocos2d::CCObject* sender) -> decltype(onForgotPassword(sender)) {
	using FunctionType = decltype(onForgotPassword(sender))(*)(AccountLoginLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x49a180, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto AccountLoginLayer::onForgotUser(cocos2d::CCObject* sender) -> decltype(onForgotUser(sender)) {
	using FunctionType = decltype(onForgotUser(sender))(*)(AccountLoginLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x49a160, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto AccountLoginLayer::onSubmit(cocos2d::CCObject* sender) -> decltype(onSubmit(sender)) {
	using FunctionType = decltype(onSubmit(sender))(*)(AccountLoginLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x499af0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto AccountLoginLayer::resetLabel(int tag) -> decltype(resetLabel(tag)) {
	using FunctionType = decltype(resetLabel(tag))(*)(AccountLoginLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x49a7d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, tag);
}

auto AccountLoginLayer::resetLabels() -> decltype(resetLabels()) {
	using FunctionType = decltype(resetLabels())(*)(AccountLoginLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x49a760, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto AccountLoginLayer::showLoadingUI() -> decltype(showLoadingUI()) {
	using FunctionType = decltype(showLoadingUI())(*)(AccountLoginLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x49a950, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto AccountLoginLayer::toggleUI(bool enable) -> decltype(toggleUI(enable)) {
	using FunctionType = decltype(toggleUI(enable))(*)(AccountLoginLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x49aac0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, enable);
}

auto AccountLoginLayer::updateLabel(AccountError type) -> decltype(updateLabel(type)) {
	using FunctionType = decltype(updateLabel(type))(*)(AccountLoginLayer*, AccountError);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x49a670, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type);
}
