
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/SecretLayer2.hpp>
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

SecretLayer2::~SecretLayer2() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(SecretLayer2*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x49cc70, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) SecretLayer2(geode::CutoffConstructor, sizeof(SecretLayer2));
		geode::DestructorLock::addLock(this);
	}
}

auto SecretLayer2::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x49d070, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto SecretLayer2::scene() -> decltype(scene()) {
	using FunctionType = decltype(scene())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x49d030, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto SecretLayer2::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&SecretLayer2::init), this);
	using FunctionType = decltype(init())(*)(SecretLayer2*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x49d1a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto SecretLayer2::onExit() -> decltype(onExit()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&SecretLayer2::onExit), this);
	using FunctionType = decltype(onExit())(*)(SecretLayer2*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4a3160, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto SecretLayer2::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&SecretLayer2::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(SecretLayer2*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4a3070, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto SecretLayer2::textInputOpened(CCTextInputNode* node) -> decltype(textInputOpened(node)) {
	auto self = addresser::thunkAdjust(Resolve<CCTextInputNode*>::func(&SecretLayer2::textInputOpened), this);
	using FunctionType = decltype(textInputOpened(node))(*)(SecretLayer2*, CCTextInputNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4a20f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, node);
}

auto SecretLayer2::textInputClosed(CCTextInputNode* node) -> decltype(textInputClosed(node)) {
	auto self = addresser::thunkAdjust(Resolve<CCTextInputNode*>::func(&SecretLayer2::textInputClosed), this);
	using FunctionType = decltype(textInputClosed(node))(*)(SecretLayer2*, CCTextInputNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4a21c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, node);
}

auto SecretLayer2::textChanged(CCTextInputNode* node) -> decltype(textChanged(node)) {
	auto self = addresser::thunkAdjust(Resolve<CCTextInputNode*>::func(&SecretLayer2::textChanged), this);
	using FunctionType = decltype(textChanged(node))(*)(SecretLayer2*, CCTextInputNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4a2290, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, node);
}

auto SecretLayer2::FLAlert_Clicked(FLAlertLayer* layer, bool btn2) -> decltype(FLAlert_Clicked(layer, btn2)) {
	auto self = addresser::thunkAdjust(Resolve<FLAlertLayer*, bool>::func(&SecretLayer2::FLAlert_Clicked), this);
	using FunctionType = decltype(FLAlert_Clicked(layer, btn2))(*)(SecretLayer2*, FLAlertLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4a20d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, layer, btn2);
}

auto SecretLayer2::dialogClosed(DialogLayer* layer) -> decltype(dialogClosed(layer)) {
	auto self = addresser::thunkAdjust(Resolve<DialogLayer*>::func(&SecretLayer2::dialogClosed), this);
	using FunctionType = decltype(dialogClosed(layer))(*)(SecretLayer2*, DialogLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4a0c40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, layer);
}

auto SecretLayer2::getBasicMessage() -> decltype(getBasicMessage()) {
	using FunctionType = decltype(getBasicMessage())(*)(SecretLayer2*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4a2450, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SecretLayer2::getErrorMessage() -> decltype(getErrorMessage()) {
	using FunctionType = decltype(getErrorMessage())(*)(SecretLayer2*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4a18b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SecretLayer2::getMessage() -> decltype(getMessage()) {
	using FunctionType = decltype(getMessage())(*)(SecretLayer2*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x49e0a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SecretLayer2::getThreadMessage() -> decltype(getThreadMessage()) {
	using FunctionType = decltype(getThreadMessage())(*)(SecretLayer2*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4a2b30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SecretLayer2::nodeWithTag(int tag) -> decltype(nodeWithTag(tag)) {
	using FunctionType = decltype(nodeWithTag(tag))(*)(SecretLayer2*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x49e020, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, tag);
}

auto SecretLayer2::onBack(cocos2d::CCObject* sender) -> decltype(onBack(sender)) {
	using FunctionType = decltype(onBack(sender))(*)(SecretLayer2*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x49e3c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SecretLayer2::onDoor(cocos2d::CCObject* sender) -> decltype(onDoor(sender)) {
	using FunctionType = decltype(onDoor(sender))(*)(SecretLayer2*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x49fb10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SecretLayer2::onSecretLevel(cocos2d::CCObject* sender) -> decltype(onSecretLevel(sender)) {
	using FunctionType = decltype(onSecretLevel(sender))(*)(SecretLayer2*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x49fd40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SecretLayer2::onSubmit(cocos2d::CCObject* sender) -> decltype(onSubmit(sender)) {
	using FunctionType = decltype(onSubmit(sender))(*)(SecretLayer2*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x49e430, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SecretLayer2::playCoinEffect() -> decltype(playCoinEffect()) {
	using FunctionType = decltype(playCoinEffect())(*)(SecretLayer2*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4a0e10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SecretLayer2::selectAThread() -> decltype(selectAThread()) {
	using FunctionType = decltype(selectAThread())(*)(SecretLayer2*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4a2360, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SecretLayer2::showCompletedLevel() -> decltype(showCompletedLevel()) {
	using FunctionType = decltype(showCompletedLevel())(*)(SecretLayer2*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x49ff00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SecretLayer2::showSecretLevel() -> decltype(showSecretLevel()) {
	using FunctionType = decltype(showSecretLevel())(*)(SecretLayer2*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4a0b10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SecretLayer2::updateMessageLabel(gd::string text) -> decltype(updateMessageLabel(text)) {
	using FunctionType = decltype(updateMessageLabel(text))(*)(SecretLayer2*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x49e050, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, text);
}

auto SecretLayer2::updateSearchLabel(char const* text) -> decltype(updateSearchLabel(text)) {
	using FunctionType = decltype(updateSearchLabel(text))(*)(SecretLayer2*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x49e130, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, text);
}
