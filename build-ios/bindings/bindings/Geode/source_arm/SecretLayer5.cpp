
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/SecretLayer5.hpp>
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

SecretLayer5::~SecretLayer5() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(SecretLayer5*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x3e0918, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) SecretLayer5(geode::CutoffConstructor, sizeof(SecretLayer5));
		geode::DestructorLock::addLock(this);
	}
}

auto SecretLayer5::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e0a54, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto SecretLayer5::scene() -> decltype(scene()) {
	using FunctionType = decltype(scene())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e0a10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto SecretLayer5::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&SecretLayer5::init), this);
	using FunctionType = decltype(init())(*)(SecretLayer5*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e0b60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto SecretLayer5::onExit() -> decltype(onExit()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&SecretLayer5::onExit), this);
	using FunctionType = decltype(onExit())(*)(SecretLayer5*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e4db8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto SecretLayer5::updateTweenActionInt(float value, int tag) -> decltype(updateTweenActionInt(value, tag)) {
	auto self = addresser::thunkAdjust(Resolve<float, int>::func(&SecretLayer5::updateTweenActionInt), this);
	using FunctionType = decltype(updateTweenActionInt(value, tag))(*)(SecretLayer5*, float, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e2d50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, value, tag);
}

auto SecretLayer5::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&SecretLayer5::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(SecretLayer5*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e4cac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto SecretLayer5::textInputOpened(CCTextInputNode* node) -> decltype(textInputOpened(node)) {
	auto self = addresser::thunkAdjust(Resolve<CCTextInputNode*>::func(&SecretLayer5::textInputOpened), this);
	using FunctionType = decltype(textInputOpened(node))(*)(SecretLayer5*, CCTextInputNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e4974, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, node);
}

auto SecretLayer5::textInputClosed(CCTextInputNode* node) -> decltype(textInputClosed(node)) {
	auto self = addresser::thunkAdjust(Resolve<CCTextInputNode*>::func(&SecretLayer5::textInputClosed), this);
	using FunctionType = decltype(textInputClosed(node))(*)(SecretLayer5*, CCTextInputNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e4a54, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, node);
}

auto SecretLayer5::textChanged(CCTextInputNode* node) -> decltype(textChanged(node)) {
	auto self = addresser::thunkAdjust(Resolve<CCTextInputNode*>::func(&SecretLayer5::textChanged), this);
	using FunctionType = decltype(textChanged(node))(*)(SecretLayer5*, CCTextInputNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e4b64, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, node);
}

auto SecretLayer5::FLAlert_Clicked(FLAlertLayer* layer, bool btn2) -> decltype(FLAlert_Clicked(layer, btn2)) {
	auto self = addresser::thunkAdjust(Resolve<FLAlertLayer*, bool>::func(&SecretLayer5::FLAlert_Clicked), this);
	using FunctionType = decltype(FLAlert_Clicked(layer, btn2))(*)(SecretLayer5*, FLAlertLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e496c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, layer, btn2);
}

auto SecretLayer5::dialogClosed(DialogLayer* layer) -> decltype(dialogClosed(layer)) {
	auto self = addresser::thunkAdjust(Resolve<DialogLayer*>::func(&SecretLayer5::dialogClosed), this);
	using FunctionType = decltype(dialogClosed(layer))(*)(SecretLayer5*, DialogLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e4964, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, layer);
}

auto SecretLayer5::onlineRewardStatusFinished(gd::string key) -> decltype(onlineRewardStatusFinished(key)) {
	auto self = addresser::thunkAdjust(Resolve<gd::string>::func(&SecretLayer5::onlineRewardStatusFinished), this);
	using FunctionType = decltype(onlineRewardStatusFinished(key))(*)(SecretLayer5*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e3ed0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, key);
}

auto SecretLayer5::onlineRewardStatusFailed() -> decltype(onlineRewardStatusFailed()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&SecretLayer5::onlineRewardStatusFailed), this);
	using FunctionType = decltype(onlineRewardStatusFailed())(*)(SecretLayer5*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e4040, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto SecretLayer5::animateHead() -> decltype(animateHead()) {
	using FunctionType = decltype(animateHead())(*)(SecretLayer5*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e2a40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SecretLayer5::claimOnlineReward() -> decltype(claimOnlineReward()) {
	using FunctionType = decltype(claimOnlineReward())(*)(SecretLayer5*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e3c58, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SecretLayer5::fadeInMessage() -> decltype(fadeInMessage()) {
	using FunctionType = decltype(fadeInMessage())(*)(SecretLayer5*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e28b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SecretLayer5::fadeInSubmitMessage() -> decltype(fadeInSubmitMessage()) {
	using FunctionType = decltype(fadeInSubmitMessage())(*)(SecretLayer5*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e281c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SecretLayer5::fadeOutMessage() -> decltype(fadeOutMessage()) {
	using FunctionType = decltype(fadeOutMessage())(*)(SecretLayer5*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e2a18, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SecretLayer5::finishLoadingState() -> decltype(finishLoadingState()) {
	using FunctionType = decltype(finishLoadingState())(*)(SecretLayer5*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e2d64, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SecretLayer5::getMessage() -> decltype(getMessage()) {
	using FunctionType = decltype(getMessage())(*)(SecretLayer5*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e1a50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SecretLayer5::handleSecretResponse() -> decltype(handleSecretResponse()) {
	using FunctionType = decltype(handleSecretResponse())(*)(SecretLayer5*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e2d78, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SecretLayer5::hideTextInput() -> decltype(hideTextInput()) {
	using FunctionType = decltype(hideTextInput())(*)(SecretLayer5*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e40d8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SecretLayer5::incrementChatIdx() -> decltype(incrementChatIdx()) {
	using FunctionType = decltype(incrementChatIdx())(*)(SecretLayer5*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e270c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SecretLayer5::nodeWithTag(int tag) -> decltype(nodeWithTag(tag)) {
	using FunctionType = decltype(nodeWithTag(tag))(*)(SecretLayer5*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e4c74, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, tag);
}

auto SecretLayer5::onBack(cocos2d::CCObject* sender) -> decltype(onBack(sender)) {
	using FunctionType = decltype(onBack(sender))(*)(SecretLayer5*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e1cbc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SecretLayer5::onSubmit(cocos2d::CCObject* sender) -> decltype(onSubmit(sender)) {
	using FunctionType = decltype(onSubmit(sender))(*)(SecretLayer5*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e1d40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SecretLayer5::playWinSFX() -> decltype(playWinSFX()) {
	using FunctionType = decltype(playWinSFX())(*)(SecretLayer5*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e3bc4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SecretLayer5::showDialog(int index) -> decltype(showDialog(index)) {
	using FunctionType = decltype(showDialog(index))(*)(SecretLayer5*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e4150, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index);
}

auto SecretLayer5::showFailAnimation() -> decltype(showFailAnimation()) {
	using FunctionType = decltype(showFailAnimation())(*)(SecretLayer5*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e3678, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SecretLayer5::showFirstDialog() -> decltype(showFirstDialog()) {
	using FunctionType = decltype(showFirstDialog())(*)(SecretLayer5*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e2200, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SecretLayer5::showSuccessAnimation() -> decltype(showSuccessAnimation()) {
	using FunctionType = decltype(showSuccessAnimation())(*)(SecretLayer5*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e2e30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SecretLayer5::showTextInput() -> decltype(showTextInput()) {
	using FunctionType = decltype(showTextInput())(*)(SecretLayer5*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e3b58, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SecretLayer5::unlockUI() -> decltype(unlockUI()) {
	using FunctionType = decltype(unlockUI())(*)(SecretLayer5*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e3e60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SecretLayer5::updateMessageLabel(gd::string text) -> decltype(updateMessageLabel(text)) {
	using FunctionType = decltype(updateMessageLabel(text))(*)(SecretLayer5*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e19fc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, text);
}

auto SecretLayer5::updateSearchLabel(char const* text) -> decltype(updateSearchLabel(text)) {
	using FunctionType = decltype(updateSearchLabel(text))(*)(SecretLayer5*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3e1a64, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, text);
}
