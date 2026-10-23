
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/LikeItemLayer.hpp>
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

auto LikeItemLayer::create(LikeItemType type, int id, int parentID) -> decltype(create(type, id, parentID)) {
	using FunctionType = decltype(create(type, id, parentID))(*)(LikeItemType, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f8bf0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(type, id, parentID);
}

auto LikeItemLayer::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&LikeItemLayer::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(LikeItemLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f92e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto LikeItemLayer::init(LikeItemType type, int id, int parentID) -> decltype(init(type, id, parentID)) {
	using FunctionType = decltype(init(type, id, parentID))(*)(LikeItemLayer*, LikeItemType, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f8d60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type, id, parentID);
}

auto LikeItemLayer::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	using FunctionType = decltype(onClose(sender))(*)(LikeItemLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f9130, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LikeItemLayer::onDislike(cocos2d::CCObject* sender) -> decltype(onDislike(sender)) {
	using FunctionType = decltype(onDislike(sender))(*)(LikeItemLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f91e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LikeItemLayer::onLike(cocos2d::CCObject* sender) -> decltype(onLike(sender)) {
	using FunctionType = decltype(onLike(sender))(*)(LikeItemLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f9160, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto LikeItemLayer::triggerLike(bool isLiked) -> decltype(triggerLike(isLiked)) {
	using FunctionType = decltype(triggerLike(isLiked))(*)(LikeItemLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f9260, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, isLiked);
}
