
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/RewardUnlockLayer.hpp>
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

auto RewardUnlockLayer::create(int type, RewardsPage* page) -> decltype(create(type, page)) {
	using FunctionType = decltype(create(type, page))(*)(int, RewardsPage*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1c6590, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(type, page);
}

auto RewardUnlockLayer::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&RewardUnlockLayer::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(RewardUnlockLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1ca598, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto RewardUnlockLayer::currencyWillExit(CurrencyRewardLayer* layer) -> decltype(currencyWillExit(layer)) {
	auto self = addresser::thunkAdjust(Resolve<CurrencyRewardLayer*>::func(&RewardUnlockLayer::currencyWillExit), this);
	using FunctionType = decltype(currencyWillExit(layer))(*)(RewardUnlockLayer*, CurrencyRewardLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1ca570, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, layer);
}

auto RewardUnlockLayer::connectionTimeout() -> decltype(connectionTimeout()) {
	using FunctionType = decltype(connectionTimeout())(*)(RewardUnlockLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1c7e78, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto RewardUnlockLayer::init(int type, RewardsPage* page) -> decltype(init(type, page)) {
	using FunctionType = decltype(init(type, page))(*)(RewardUnlockLayer*, int, RewardsPage*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1c6eec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type, page);
}

auto RewardUnlockLayer::labelEnterFinishedO(cocos2d::CCObject* object) -> decltype(labelEnterFinishedO(object)) {
	using FunctionType = decltype(labelEnterFinishedO(object))(*)(RewardUnlockLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1ca56c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object);
}

auto RewardUnlockLayer::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	using FunctionType = decltype(onClose(sender))(*)(RewardUnlockLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1c7e20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto RewardUnlockLayer::playDropSound() -> decltype(playDropSound()) {
	using FunctionType = decltype(playDropSound())(*)(RewardUnlockLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1c7cc4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto RewardUnlockLayer::playLabelEffect(int count, int type, cocos2d::CCSprite* sprite, cocos2d::CCPoint position, float delay) -> decltype(playLabelEffect(count, type, sprite, position, delay)) {
	using FunctionType = decltype(playLabelEffect(count, type, sprite, position, delay))(*)(RewardUnlockLayer*, int, int, cocos2d::CCSprite*, cocos2d::CCPoint, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1c9e28, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, count, type, sprite, position, delay);
}

auto RewardUnlockLayer::playRewardEffect() -> decltype(playRewardEffect()) {
	using FunctionType = decltype(playRewardEffect())(*)(RewardUnlockLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1c7edc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto RewardUnlockLayer::readyToCollect(GJRewardItem* item) -> decltype(readyToCollect(item)) {
	using FunctionType = decltype(readyToCollect(item))(*)(RewardUnlockLayer*, GJRewardItem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1c683c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, item);
}

auto RewardUnlockLayer::showCloseButton() -> decltype(showCloseButton()) {
	using FunctionType = decltype(showCloseButton())(*)(RewardUnlockLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1ca4f4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto RewardUnlockLayer::showCollectReward(GJRewardItem* item) -> decltype(showCollectReward(item)) {
	using FunctionType = decltype(showCollectReward(item))(*)(RewardUnlockLayer*, GJRewardItem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1c685c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, item);
}

auto RewardUnlockLayer::step2() -> decltype(step2()) {
	using FunctionType = decltype(step2())(*)(RewardUnlockLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1c7d50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto RewardUnlockLayer::step3() -> decltype(step3()) {
	using FunctionType = decltype(step3())(*)(RewardUnlockLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1c9e0c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
