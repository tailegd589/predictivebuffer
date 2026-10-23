
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GJUserCell.hpp>
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

GJUserCell::GJUserCell(char const* identifier, float width, float height) : GJUserCell(geode::CutoffConstructor, sizeof(GJUserCell)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	GJUserCell::~GJUserCell();

	using FunctionType = void(*)(GJUserCell*, char const*, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x256350, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this, identifier, width, height);
}

GJUserCell::~GJUserCell() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(GJUserCell*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x255f50, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) GJUserCell(geode::CutoffConstructor, sizeof(GJUserCell));
		geode::DestructorLock::addLock(this);
	}
}

auto GJUserCell::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJUserCell::init), this);
	using FunctionType = decltype(init())(*)(GJUserCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2563f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJUserCell::draw() -> decltype(draw()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJUserCell::draw), this);
	using FunctionType = decltype(draw())(*)(GJUserCell*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x256b50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJUserCell::FLAlert_Clicked(FLAlertLayer* layer, bool btn2) -> decltype(FLAlert_Clicked(layer, btn2)) {
	auto self = addresser::thunkAdjust(Resolve<FLAlertLayer*, bool>::func(&GJUserCell::FLAlert_Clicked), this);
	using FunctionType = decltype(FLAlert_Clicked(layer, btn2))(*)(GJUserCell*, FLAlertLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x256c20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, layer, btn2);
}

auto GJUserCell::uploadActionFinished(int id, int response) -> decltype(uploadActionFinished(id, response)) {
	auto self = addresser::thunkAdjust(Resolve<int, int>::func(&GJUserCell::uploadActionFinished), this);
	using FunctionType = decltype(uploadActionFinished(id, response))(*)(GJUserCell*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x256ed0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, id, response);
}

auto GJUserCell::uploadActionFailed(int id, int response) -> decltype(uploadActionFailed(id, response)) {
	auto self = addresser::thunkAdjust(Resolve<int, int>::func(&GJUserCell::uploadActionFailed), this);
	using FunctionType = decltype(uploadActionFailed(id, response))(*)(GJUserCell*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2570d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, id, response);
}

auto GJUserCell::onClosePopup(UploadActionPopup* popup) -> decltype(onClosePopup(popup)) {
	auto self = addresser::thunkAdjust(Resolve<UploadActionPopup*>::func(&GJUserCell::onClosePopup), this);
	using FunctionType = decltype(onClosePopup(popup))(*)(GJUserCell*, UploadActionPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x257240, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, popup);
}

auto GJUserCell::loadFromScore(GJUserScore* score) -> decltype(loadFromScore(score)) {
	using FunctionType = decltype(loadFromScore(score))(*)(GJUserCell*, GJUserScore*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x24ba20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, score);
}

auto GJUserCell::onCancelFriendRequest(cocos2d::CCObject* sender) -> decltype(onCancelFriendRequest(sender)) {
	using FunctionType = decltype(onCancelFriendRequest(sender))(*)(GJUserCell*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2566d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto GJUserCell::onRemoveFriend(cocos2d::CCObject* sender) -> decltype(onRemoveFriend(sender)) {
	using FunctionType = decltype(onRemoveFriend(sender))(*)(GJUserCell*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x256810, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto GJUserCell::onSendMessage(cocos2d::CCObject* sender) -> decltype(onSendMessage(sender)) {
	using FunctionType = decltype(onSendMessage(sender))(*)(GJUserCell*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2567e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto GJUserCell::onUnblockUser(cocos2d::CCObject* sender) -> decltype(onUnblockUser(sender)) {
	using FunctionType = decltype(onUnblockUser(sender))(*)(GJUserCell*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x256440, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto GJUserCell::onViewFriendRequest(cocos2d::CCObject* sender) -> decltype(onViewFriendRequest(sender)) {
	using FunctionType = decltype(onViewFriendRequest(sender))(*)(GJUserCell*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x256aa0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto GJUserCell::onViewProfile(cocos2d::CCObject* sender) -> decltype(onViewProfile(sender)) {
	using FunctionType = decltype(onViewProfile(sender))(*)(GJUserCell*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x256410, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto GJUserCell::updateBGColor(int index) -> decltype(updateBGColor(index)) {
	using FunctionType = decltype(updateBGColor(index))(*)(GJUserCell*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x24b9c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index);
}
