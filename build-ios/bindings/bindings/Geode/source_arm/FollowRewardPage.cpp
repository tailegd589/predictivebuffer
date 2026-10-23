
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/FollowRewardPage.hpp>
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

auto FollowRewardPage::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x392f3c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto FollowRewardPage::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&FollowRewardPage::init), this);
	using FunctionType = decltype(init())(*)(FollowRewardPage*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39304c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto FollowRewardPage::registerWithTouchDispatcher() -> decltype(registerWithTouchDispatcher()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&FollowRewardPage::registerWithTouchDispatcher), this);
	using FunctionType = decltype(registerWithTouchDispatcher())(*)(FollowRewardPage*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x394fec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto FollowRewardPage::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&FollowRewardPage::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(FollowRewardPage*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x394f70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto FollowRewardPage::show() -> decltype(show()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&FollowRewardPage::show), this);
	using FunctionType = decltype(show())(*)(FollowRewardPage*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x394d40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto FollowRewardPage::FLAlert_Clicked(FLAlertLayer* layer, bool btn2) -> decltype(FLAlert_Clicked(layer, btn2)) {
	auto self = addresser::thunkAdjust(Resolve<FLAlertLayer*, bool>::func(&FollowRewardPage::FLAlert_Clicked), this);
	using FunctionType = decltype(FLAlert_Clicked(layer, btn2))(*)(FollowRewardPage*, FLAlertLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x394ec8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, layer, btn2);
}

auto FollowRewardPage::rewardedVideoFinished() -> decltype(rewardedVideoFinished()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&FollowRewardPage::rewardedVideoFinished), this);
	using FunctionType = decltype(rewardedVideoFinished())(*)(FollowRewardPage*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x394d30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto FollowRewardPage::updateRate() -> decltype(updateRate()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&FollowRewardPage::updateRate), this);
	using FunctionType = decltype(updateRate())(*)(FollowRewardPage*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x394658, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto FollowRewardPage::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	using FunctionType = decltype(onClose(sender))(*)(FollowRewardPage*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x393f78, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto FollowRewardPage::onRewardedVideo(cocos2d::CCObject* sender) -> decltype(onRewardedVideo(sender)) {
	using FunctionType = decltype(onRewardedVideo(sender))(*)(FollowRewardPage*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3949a8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto FollowRewardPage::onSpecialItem(cocos2d::CCObject* sender) -> decltype(onSpecialItem(sender)) {
	using FunctionType = decltype(onSpecialItem(sender))(*)(FollowRewardPage*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x393fb4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto FollowRewardPage::switchToOpenedState(CCMenuItemSpriteExtra* button) -> decltype(switchToOpenedState(button)) {
	using FunctionType = decltype(switchToOpenedState(button))(*)(FollowRewardPage*, CCMenuItemSpriteExtra*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x394574, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, button);
}
