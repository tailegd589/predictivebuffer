
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/FriendRequestPopup.hpp>
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

auto FriendRequestPopup::create(GJFriendRequest* request) -> decltype(create(request)) {
	using FunctionType = decltype(create(request))(*)(GJFriendRequest*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x243b00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(request);
}

auto FriendRequestPopup::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&FriendRequestPopup::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(FriendRequestPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x244fb8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto FriendRequestPopup::uploadActionFinished(int id, int response) -> decltype(uploadActionFinished(id, response)) {
	auto self = addresser::thunkAdjust(Resolve<int, int>::func(&FriendRequestPopup::uploadActionFinished), this);
	using FunctionType = decltype(uploadActionFinished(id, response))(*)(FriendRequestPopup*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x245094, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, id, response);
}

auto FriendRequestPopup::uploadActionFailed(int id, int response) -> decltype(uploadActionFailed(id, response)) {
	auto self = addresser::thunkAdjust(Resolve<int, int>::func(&FriendRequestPopup::uploadActionFailed), this);
	using FunctionType = decltype(uploadActionFailed(id, response))(*)(FriendRequestPopup*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x245288, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, id, response);
}

auto FriendRequestPopup::onClosePopup(UploadActionPopup* popup) -> decltype(onClosePopup(popup)) {
	auto self = addresser::thunkAdjust(Resolve<UploadActionPopup*>::func(&FriendRequestPopup::onClosePopup), this);
	using FunctionType = decltype(onClosePopup(popup))(*)(FriendRequestPopup*, UploadActionPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2453f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, popup);
}

auto FriendRequestPopup::FLAlert_Clicked(FLAlertLayer* layer, bool btn2) -> decltype(FLAlert_Clicked(layer, btn2)) {
	auto self = addresser::thunkAdjust(Resolve<FLAlertLayer*, bool>::func(&FriendRequestPopup::FLAlert_Clicked), this);
	using FunctionType = decltype(FLAlert_Clicked(layer, btn2))(*)(FriendRequestPopup*, FLAlertLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x245574, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, layer, btn2);
}

auto FriendRequestPopup::blockUser() -> decltype(blockUser()) {
	using FunctionType = decltype(blockUser())(*)(FriendRequestPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x244f3c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto FriendRequestPopup::init(GJFriendRequest* request) -> decltype(init(request)) {
	using FunctionType = decltype(init(request))(*)(FriendRequestPopup*, GJFriendRequest*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x243c20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, request);
}

auto FriendRequestPopup::loadFromGJFriendRequest(GJFriendRequest* request) -> decltype(loadFromGJFriendRequest(request)) {
	using FunctionType = decltype(loadFromGJFriendRequest(request))(*)(FriendRequestPopup*, GJFriendRequest*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2442a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, request);
}

auto FriendRequestPopup::onAccept(cocos2d::CCObject* sender) -> decltype(onAccept(sender)) {
	using FunctionType = decltype(onAccept(sender))(*)(FriendRequestPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x244b20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto FriendRequestPopup::onBlock(cocos2d::CCObject* sender) -> decltype(onBlock(sender)) {
	using FunctionType = decltype(onBlock(sender))(*)(FriendRequestPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x244c9c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto FriendRequestPopup::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	using FunctionType = decltype(onClose(sender))(*)(FriendRequestPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x244234, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto FriendRequestPopup::onRemove(cocos2d::CCObject* sender) -> decltype(onRemove(sender)) {
	using FunctionType = decltype(onRemove(sender))(*)(FriendRequestPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x244bdc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}
