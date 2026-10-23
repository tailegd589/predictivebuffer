
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GJWriteMessagePopup.hpp>
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

auto GJWriteMessagePopup::create(int accountID, int messageID) -> decltype(create(accountID, messageID)) {
	using FunctionType = decltype(create(accountID, messageID))(*)(int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a8280, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(accountID, messageID);
}

auto GJWriteMessagePopup::registerWithTouchDispatcher() -> decltype(registerWithTouchDispatcher()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJWriteMessagePopup::registerWithTouchDispatcher), this);
	using FunctionType = decltype(registerWithTouchDispatcher())(*)(GJWriteMessagePopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2aa370, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJWriteMessagePopup::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJWriteMessagePopup::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(GJWriteMessagePopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2aa340, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJWriteMessagePopup::textInputOpened(CCTextInputNode* node) -> decltype(textInputOpened(node)) {
	auto self = addresser::thunkAdjust(Resolve<CCTextInputNode*>::func(&GJWriteMessagePopup::textInputOpened), this);
	using FunctionType = decltype(textInputOpened(node))(*)(GJWriteMessagePopup*, CCTextInputNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2aa3f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, node);
}

auto GJWriteMessagePopup::textInputClosed(CCTextInputNode* node) -> decltype(textInputClosed(node)) {
	auto self = addresser::thunkAdjust(Resolve<CCTextInputNode*>::func(&GJWriteMessagePopup::textInputClosed), this);
	using FunctionType = decltype(textInputClosed(node))(*)(GJWriteMessagePopup*, CCTextInputNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2aa3b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, node);
}

auto GJWriteMessagePopup::textChanged(CCTextInputNode* node) -> decltype(textChanged(node)) {
	auto self = addresser::thunkAdjust(Resolve<CCTextInputNode*>::func(&GJWriteMessagePopup::textChanged), this);
	using FunctionType = decltype(textChanged(node))(*)(GJWriteMessagePopup*, CCTextInputNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2aa410, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, node);
}

auto GJWriteMessagePopup::uploadMessageFinished(int accountID) -> decltype(uploadMessageFinished(accountID)) {
	auto self = addresser::thunkAdjust(Resolve<int>::func(&GJWriteMessagePopup::uploadMessageFinished), this);
	using FunctionType = decltype(uploadMessageFinished(accountID))(*)(GJWriteMessagePopup*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2aaac0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, accountID);
}

auto GJWriteMessagePopup::uploadMessageFailed(int accountID) -> decltype(uploadMessageFailed(accountID)) {
	auto self = addresser::thunkAdjust(Resolve<int>::func(&GJWriteMessagePopup::uploadMessageFailed), this);
	using FunctionType = decltype(uploadMessageFailed(accountID))(*)(GJWriteMessagePopup*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2aab80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, accountID);
}

auto GJWriteMessagePopup::onClosePopup(UploadActionPopup* popup) -> decltype(onClosePopup(popup)) {
	auto self = addresser::thunkAdjust(Resolve<UploadActionPopup*>::func(&GJWriteMessagePopup::onClosePopup), this);
	using FunctionType = decltype(onClosePopup(popup))(*)(GJWriteMessagePopup*, UploadActionPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2aacb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, popup);
}

auto GJWriteMessagePopup::FLAlert_Clicked(FLAlertLayer* layer, bool btn2) -> decltype(FLAlert_Clicked(layer, btn2)) {
	auto self = addresser::thunkAdjust(Resolve<FLAlertLayer*, bool>::func(&GJWriteMessagePopup::FLAlert_Clicked), this);
	using FunctionType = decltype(FLAlert_Clicked(layer, btn2))(*)(GJWriteMessagePopup*, FLAlertLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2aae00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, layer, btn2);
}

auto GJWriteMessagePopup::textInputShouldOffset(CCTextInputNode* node, float yOffset) -> decltype(textInputShouldOffset(node, yOffset)) {
	auto self = addresser::thunkAdjust(Resolve<CCTextInputNode*, float>::func(&GJWriteMessagePopup::textInputShouldOffset), this);
	using FunctionType = decltype(textInputShouldOffset(node, yOffset))(*)(GJWriteMessagePopup*, CCTextInputNode*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2aaee0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, node, yOffset);
}

auto GJWriteMessagePopup::textInputReturn(CCTextInputNode* node) -> decltype(textInputReturn(node)) {
	auto self = addresser::thunkAdjust(Resolve<CCTextInputNode*>::func(&GJWriteMessagePopup::textInputReturn), this);
	using FunctionType = decltype(textInputReturn(node))(*)(GJWriteMessagePopup*, CCTextInputNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2aafa0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, node);
}

auto GJWriteMessagePopup::closeMessagePopup(bool fullExit) -> decltype(closeMessagePopup(fullExit)) {
	using FunctionType = decltype(closeMessagePopup(fullExit))(*)(GJWriteMessagePopup*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2aa170, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, fullExit);
}

auto GJWriteMessagePopup::init(int accountID, int messageID) -> decltype(init(accountID, messageID)) {
	using FunctionType = decltype(init(accountID, messageID))(*)(GJWriteMessagePopup*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a8d70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, accountID, messageID);
}

auto GJWriteMessagePopup::onClearBody(cocos2d::CCObject* sender) -> decltype(onClearBody(sender)) {
	using FunctionType = decltype(onClearBody(sender))(*)(GJWriteMessagePopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2aa080, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto GJWriteMessagePopup::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	using FunctionType = decltype(onClose(sender))(*)(GJWriteMessagePopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a9c30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto GJWriteMessagePopup::onSend(cocos2d::CCObject* sender) -> decltype(onSend(sender)) {
	using FunctionType = decltype(onSend(sender))(*)(GJWriteMessagePopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a9c40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto GJWriteMessagePopup::updateBody(gd::string body) -> decltype(updateBody(body)) {
	using FunctionType = decltype(updateBody(body))(*)(GJWriteMessagePopup*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2aa000, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, body);
}

auto GJWriteMessagePopup::updateCharCountLabel(int type) -> decltype(updateCharCountLabel(type)) {
	using FunctionType = decltype(updateCharCountLabel(type))(*)(GJWriteMessagePopup*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2aa9a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type);
}

auto GJWriteMessagePopup::updateSubject(gd::string subject) -> decltype(updateSubject(subject)) {
	using FunctionType = decltype(updateSubject(subject))(*)(GJWriteMessagePopup*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a9f80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, subject);
}

auto GJWriteMessagePopup::updateText(gd::string text, int type) -> decltype(updateText(text, type)) {
	using FunctionType = decltype(updateText(text, type))(*)(GJWriteMessagePopup*, gd::string, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2aa720, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, text, type);
}
