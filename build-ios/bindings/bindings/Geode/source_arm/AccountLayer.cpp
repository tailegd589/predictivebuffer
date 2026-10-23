
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/AccountLayer.hpp>
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

auto AccountLayer::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0xb3128, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto AccountLayer::customSetup() -> decltype(customSetup()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&AccountLayer::customSetup), this);
	using FunctionType = decltype(customSetup())(*)(AccountLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xb33b8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto AccountLayer::layerHidden() -> decltype(layerHidden()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&AccountLayer::layerHidden), this);
	using FunctionType = decltype(layerHidden())(*)(AccountLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xb5318, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto AccountLayer::backupAccountFinished() -> decltype(backupAccountFinished()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&AccountLayer::backupAccountFinished), this);
	using FunctionType = decltype(backupAccountFinished())(*)(AccountLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xb48d4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto AccountLayer::backupAccountFailed(BackupAccountError errorType, int response) -> decltype(backupAccountFailed(errorType, response)) {
	auto self = addresser::thunkAdjust(Resolve<BackupAccountError, int>::func(&AccountLayer::backupAccountFailed), this);
	using FunctionType = decltype(backupAccountFailed(errorType, response))(*)(AccountLayer*, BackupAccountError, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xb4a98, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, errorType, response);
}

auto AccountLayer::syncAccountFinished() -> decltype(syncAccountFinished()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&AccountLayer::syncAccountFinished), this);
	using FunctionType = decltype(syncAccountFinished())(*)(AccountLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xb4e04, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto AccountLayer::syncAccountFailed(BackupAccountError errorType, int response) -> decltype(syncAccountFailed(errorType, response)) {
	auto self = addresser::thunkAdjust(Resolve<BackupAccountError, int>::func(&AccountLayer::syncAccountFailed), this);
	using FunctionType = decltype(syncAccountFailed(errorType, response))(*)(AccountLayer*, BackupAccountError, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xb4f70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, errorType, response);
}

auto AccountLayer::accountStatusChanged() -> decltype(accountStatusChanged()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&AccountLayer::accountStatusChanged), this);
	using FunctionType = decltype(accountStatusChanged())(*)(AccountLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xb48c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto AccountLayer::FLAlert_Clicked(FLAlertLayer* layer, bool btn2) -> decltype(FLAlert_Clicked(layer, btn2)) {
	auto self = addresser::thunkAdjust(Resolve<FLAlertLayer*, bool>::func(&AccountLayer::FLAlert_Clicked), this);
	using FunctionType = decltype(FLAlert_Clicked(layer, btn2))(*)(AccountLayer*, FLAlertLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xb51e8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, layer, btn2);
}

auto AccountLayer::createToggleButton(gd::string text, cocos2d::SEL_MenuHandler selector, bool toggled, cocos2d::CCMenu* menu, cocos2d::CCPoint position) -> decltype(createToggleButton(text, selector, toggled, menu, position)) {
	using FunctionType = decltype(createToggleButton(text, selector, toggled, menu, position))(*)(AccountLayer*, gd::string, cocos2d::SEL_MenuHandler, bool, cocos2d::CCMenu*, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xb44e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, text, selector, toggled, menu, position);
}

auto AccountLayer::doBackup() -> decltype(doBackup()) {
	using FunctionType = decltype(doBackup())(*)(AccountLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xb4754, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto AccountLayer::doSync() -> decltype(doSync()) {
	using FunctionType = decltype(doSync())(*)(AccountLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xb4830, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto AccountLayer::exitLayer() -> decltype(exitLayer()) {
	using FunctionType = decltype(exitLayer())(*)(AccountLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xb48b8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto AccountLayer::hideLoadingUI() -> decltype(hideLoadingUI()) {
	using FunctionType = decltype(hideLoadingUI())(*)(AccountLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xb4a3c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto AccountLayer::onBackup(cocos2d::CCObject* sender) -> decltype(onBackup(sender)) {
	using FunctionType = decltype(onBackup(sender))(*)(AccountLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xb3ac0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto AccountLayer::onHelp(cocos2d::CCObject* sender) -> decltype(onHelp(sender)) {
	using FunctionType = decltype(onHelp(sender))(*)(AccountLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xb3fb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto AccountLayer::onLogin(cocos2d::CCObject* sender) -> decltype(onLogin(sender)) {
	using FunctionType = decltype(onLogin(sender))(*)(AccountLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xb3a08, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto AccountLayer::onMore(cocos2d::CCObject* sender) -> decltype(onMore(sender)) {
	using FunctionType = decltype(onMore(sender))(*)(AccountLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xb4088, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto AccountLayer::onRegister(cocos2d::CCObject* sender) -> decltype(onRegister(sender)) {
	using FunctionType = decltype(onRegister(sender))(*)(AccountLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xb3aa4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto AccountLayer::onSync(cocos2d::CCObject* sender) -> decltype(onSync(sender)) {
	using FunctionType = decltype(onSync(sender))(*)(AccountLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xb3db8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto AccountLayer::showLoadingUI() -> decltype(showLoadingUI()) {
	using FunctionType = decltype(showLoadingUI())(*)(AccountLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xb47dc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto AccountLayer::toggleUI(bool enable) -> decltype(toggleUI(enable)) {
	using FunctionType = decltype(toggleUI(enable))(*)(AccountLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xb51a8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, enable);
}

auto AccountLayer::updatePage(bool changed) -> decltype(updatePage(changed)) {
	using FunctionType = decltype(updatePage(changed))(*)(AccountLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xb4098, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, changed);
}
