
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GJRewardItem.hpp>
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

auto GJRewardItem::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x80668, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto GJRewardItem::create(int chestID, int timeRemaining, gd::string rewardStr) -> decltype(create(chestID, timeRemaining, rewardStr)) {
	using FunctionType = decltype(create(chestID, timeRemaining, rewardStr))(*)(int, int, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x63ab0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(chestID, timeRemaining, rewardStr);
}

auto GJRewardItem::createSpecial(GJRewardType rewardType, int orbs, int diamonds, SpecialRewardItem specialType1, int specialCount1, SpecialRewardItem specialType2, int specialCount2, int unlockType, int itemID) -> decltype(createSpecial(rewardType, orbs, diamonds, specialType1, specialCount1, specialType2, specialCount2, unlockType, itemID)) {
	using FunctionType = decltype(createSpecial(rewardType, orbs, diamonds, specialType1, specialCount1, specialType2, specialCount2, unlockType, itemID))(*)(GJRewardType, int, int, SpecialRewardItem, int, SpecialRewardItem, int, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x69144, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(rewardType, orbs, diamonds, specialType1, specialCount1, specialType2, specialCount2, unlockType, itemID);
}

auto GJRewardItem::createWithCoder(DS_Dictionary* dict) -> decltype(createWithCoder(dict)) {
	using FunctionType = decltype(createWithCoder(dict))(*)(DS_Dictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x80968, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(dict);
}

auto GJRewardItem::createWithObject(GJRewardType type, GJRewardObject* object) -> decltype(createWithObject(type, object)) {
	using FunctionType = decltype(createWithObject(type, object))(*)(GJRewardType, GJRewardObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7dfc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(type, object);
}

auto GJRewardItem::createWithObjects(GJRewardType type, cocos2d::CCArray* objects) -> decltype(createWithObjects(type, objects)) {
	using FunctionType = decltype(createWithObjects(type, objects))(*)(GJRewardType, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x63920, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(type, objects);
}

auto GJRewardItem::getNextShardType(SpecialRewardItem type) -> decltype(getNextShardType(type)) {
	using FunctionType = decltype(getNextShardType(type))(*)(SpecialRewardItem);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x808ec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(type);
}

auto GJRewardItem::getRandomNonMaxShardType() -> decltype(getRandomNonMaxShardType()) {
	using FunctionType = decltype(getRandomNonMaxShardType())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x65f80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto GJRewardItem::getRandomShardType() -> decltype(getRandomShardType()) {
	using FunctionType = decltype(getRandomShardType())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x80910, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto GJRewardItem::isShardType(SpecialRewardItem type) -> decltype(isShardType(type)) {
	using FunctionType = decltype(isShardType(type))(*)(SpecialRewardItem);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x643c4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(type);
}

auto GJRewardItem::rewardItemToStat(SpecialRewardItem rewardItem) -> decltype(rewardItemToStat(rewardItem)) {
	using FunctionType = decltype(rewardItemToStat(rewardItem))(*)(SpecialRewardItem);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x643dc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(rewardItem);
}

auto GJRewardItem::encodeWithCoder(DS_Dictionary* dict) -> decltype(encodeWithCoder(dict)) {
	auto self = addresser::thunkAdjust(Resolve<DS_Dictionary*>::func(&GJRewardItem::encodeWithCoder), this);
	using FunctionType = decltype(encodeWithCoder(dict))(*)(GJRewardItem*, DS_Dictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x80a9c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, dict);
}

auto GJRewardItem::canEncode() -> decltype(canEncode()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJRewardItem::canEncode), this);
	using FunctionType = decltype(canEncode())(*)(GJRewardItem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x80b08, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJRewardItem::dataLoaded(DS_Dictionary* dict) -> decltype(dataLoaded(dict)) {
	using FunctionType = decltype(dataLoaded(dict))(*)(GJRewardItem*, DS_Dictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x80a14, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dict);
}

auto GJRewardItem::getRewardCount(SpecialRewardItem type) -> decltype(getRewardCount(type)) {
	using FunctionType = decltype(getRewardCount(type))(*)(GJRewardItem*, SpecialRewardItem);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x68564, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type);
}

auto GJRewardItem::getRewardObjectForType(SpecialRewardItem type) -> decltype(getRewardObjectForType(type)) {
	using FunctionType = decltype(getRewardObjectForType(type))(*)(GJRewardItem*, SpecialRewardItem);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x64580, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type);
}

auto GJRewardItem::init(int chestID, int timeRemaining, gd::string rewardStr) -> decltype(init(chestID, timeRemaining, rewardStr)) {
	using FunctionType = decltype(init(chestID, timeRemaining, rewardStr))(*)(GJRewardItem*, int, int, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x80698, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, chestID, timeRemaining, rewardStr);
}
