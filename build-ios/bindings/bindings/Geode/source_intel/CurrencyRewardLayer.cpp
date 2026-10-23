
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/CurrencyRewardLayer.hpp>
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

auto CurrencyRewardLayer::create(int orbs, int stars, int moons, int diamonds, CurrencySpriteType demonKey, int keyCount, CurrencySpriteType shardType, int shardsCount, cocos2d::CCPoint position, CurrencyRewardType rewardType, float yOffset, float time) -> decltype(create(orbs, stars, moons, diamonds, demonKey, keyCount, shardType, shardsCount, position, rewardType, yOffset, time)) {
	using FunctionType = decltype(create(orbs, stars, moons, diamonds, demonKey, keyCount, shardType, shardsCount, position, rewardType, yOffset, time))(*)(int, int, int, int, CurrencySpriteType, int, CurrencySpriteType, int, cocos2d::CCPoint, CurrencyRewardType, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7a5b40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(orbs, stars, moons, diamonds, demonKey, keyCount, shardType, shardsCount, position, rewardType, yOffset, time);
}

auto CurrencyRewardLayer::update(float dt) -> decltype(update(dt)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&CurrencyRewardLayer::update), this);
	using FunctionType = decltype(update(dt))(*)(CurrencyRewardLayer*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7a8b50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, dt);
}

auto CurrencyRewardLayer::createObjects(CurrencySpriteType type, int count, cocos2d::CCPoint position, float time) -> decltype(createObjects(type, count, position, time)) {
	using FunctionType = decltype(createObjects(type, count, position, time))(*)(CurrencyRewardLayer*, CurrencySpriteType, int, cocos2d::CCPoint, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7a7d50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type, count, position, time);
}

auto CurrencyRewardLayer::createObjectsFull(CurrencySpriteType type, int count, cocos2d::CCSprite* sprite, cocos2d::CCPoint position, float time) -> decltype(createObjectsFull(type, count, sprite, position, time)) {
	using FunctionType = decltype(createObjectsFull(type, count, sprite, position, time))(*)(CurrencyRewardLayer*, CurrencySpriteType, int, cocos2d::CCSprite*, cocos2d::CCPoint, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7a7df0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type, count, sprite, position, time);
}

auto CurrencyRewardLayer::createUnlockObject(cocos2d::CCSprite* sprite, cocos2d::CCPoint position, float time) -> decltype(createUnlockObject(sprite, position, time)) {
	using FunctionType = decltype(createUnlockObject(sprite, position, time))(*)(CurrencyRewardLayer*, cocos2d::CCSprite*, cocos2d::CCPoint, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7a7da0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sprite, position, time);
}

auto CurrencyRewardLayer::incrementCount(int count) -> decltype(incrementCount(count)) {
	using FunctionType = decltype(incrementCount(count))(*)(CurrencyRewardLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7a9280, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, count);
}

auto CurrencyRewardLayer::incrementDiamondsCount(int count) -> decltype(incrementDiamondsCount(count)) {
	using FunctionType = decltype(incrementDiamondsCount(count))(*)(CurrencyRewardLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7a9700, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, count);
}

auto CurrencyRewardLayer::incrementMoonsCount(int count) -> decltype(incrementMoonsCount(count)) {
	using FunctionType = decltype(incrementMoonsCount(count))(*)(CurrencyRewardLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7a9580, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, count);
}

auto CurrencyRewardLayer::incrementSpecialCount1(int count) -> decltype(incrementSpecialCount1(count)) {
	using FunctionType = decltype(incrementSpecialCount1(count))(*)(CurrencyRewardLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7a9a00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, count);
}

auto CurrencyRewardLayer::incrementSpecialCount2(int count) -> decltype(incrementSpecialCount2(count)) {
	using FunctionType = decltype(incrementSpecialCount2(count))(*)(CurrencyRewardLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7a9880, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, count);
}

auto CurrencyRewardLayer::incrementStarsCount(int count) -> decltype(incrementStarsCount(count)) {
	using FunctionType = decltype(incrementStarsCount(count))(*)(CurrencyRewardLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7a9400, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, count);
}

auto CurrencyRewardLayer::init(int orbs, int stars, int moons, int diamonds, CurrencySpriteType demonKey, int keyCount, CurrencySpriteType shardType, int shardsCount, cocos2d::CCPoint position, CurrencyRewardType rewardType, float yOffset, float time) -> decltype(init(orbs, stars, moons, diamonds, demonKey, keyCount, shardType, shardsCount, position, rewardType, yOffset, time)) {
	using FunctionType = decltype(init(orbs, stars, moons, diamonds, demonKey, keyCount, shardType, shardsCount, position, rewardType, yOffset, time))(*)(CurrencyRewardLayer*, int, int, int, int, CurrencySpriteType, int, CurrencySpriteType, int, cocos2d::CCPoint, CurrencyRewardType, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7a5c20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, orbs, stars, moons, diamonds, demonKey, keyCount, shardType, shardsCount, position, rewardType, yOffset, time);
}

auto CurrencyRewardLayer::pulseSprite(cocos2d::CCSprite* sprite) -> decltype(pulseSprite(sprite)) {
	using FunctionType = decltype(pulseSprite(sprite))(*)(CurrencyRewardLayer*, cocos2d::CCSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7a9b80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sprite);
}
