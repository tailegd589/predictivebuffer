
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/FriendsProfilePage.hpp>
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

auto FriendsProfilePage::create(UserListType type) -> decltype(create(type)) {
	using FunctionType = decltype(create(type))(*)(UserListType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x577cd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(type);
}

auto FriendsProfilePage::registerWithTouchDispatcher() -> decltype(registerWithTouchDispatcher()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&FriendsProfilePage::registerWithTouchDispatcher), this);
	using FunctionType = decltype(registerWithTouchDispatcher())(*)(FriendsProfilePage*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x578bf8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto FriendsProfilePage::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&FriendsProfilePage::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(FriendsProfilePage*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x578bec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto FriendsProfilePage::getUserListFinished(cocos2d::CCArray* scores, UserListType type) -> decltype(getUserListFinished(scores, type)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCArray*, UserListType>::func(&FriendsProfilePage::getUserListFinished), this);
	using FunctionType = decltype(getUserListFinished(scores, type))(*)(FriendsProfilePage*, cocos2d::CCArray*, UserListType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x57888c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, scores, type);
}

auto FriendsProfilePage::getUserListFailed(UserListType type, GJErrorCode errorType) -> decltype(getUserListFailed(type, errorType)) {
	auto self = addresser::thunkAdjust(Resolve<UserListType, GJErrorCode>::func(&FriendsProfilePage::getUserListFailed), this);
	using FunctionType = decltype(getUserListFailed(type, errorType))(*)(FriendsProfilePage*, UserListType, GJErrorCode);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x57899c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, type, errorType);
}

auto FriendsProfilePage::userListChanged(cocos2d::CCArray* scores, UserListType type) -> decltype(userListChanged(scores, type)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCArray*, UserListType>::func(&FriendsProfilePage::userListChanged), this);
	using FunctionType = decltype(userListChanged(scores, type))(*)(FriendsProfilePage*, cocos2d::CCArray*, UserListType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x578ac4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, scores, type);
}

auto FriendsProfilePage::forceReloadList(UserListType type) -> decltype(forceReloadList(type)) {
	auto self = addresser::thunkAdjust(Resolve<UserListType>::func(&FriendsProfilePage::forceReloadList), this);
	using FunctionType = decltype(forceReloadList(type))(*)(FriendsProfilePage*, UserListType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x578ae0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, type);
}

auto FriendsProfilePage::init(UserListType type) -> decltype(init(type)) {
	using FunctionType = decltype(init(type))(*)(FriendsProfilePage*, UserListType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x577df8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type);
}

auto FriendsProfilePage::onBlocked(cocos2d::CCObject* sender) -> decltype(onBlocked(sender)) {
	using FunctionType = decltype(onBlocked(sender))(*)(FriendsProfilePage*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x578518, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto FriendsProfilePage::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	using FunctionType = decltype(onClose(sender))(*)(FriendsProfilePage*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x578460, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto FriendsProfilePage::onUpdate(cocos2d::CCObject* sender) -> decltype(onUpdate(sender)) {
	using FunctionType = decltype(onUpdate(sender))(*)(FriendsProfilePage*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5785a4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto FriendsProfilePage::setupUsersBrowser(cocos2d::CCArray* users, UserListType type) -> decltype(setupUsersBrowser(users, type)) {
	using FunctionType = decltype(setupUsersBrowser(users, type))(*)(FriendsProfilePage*, cocos2d::CCArray*, UserListType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x578608, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, users, type);
}
