
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GJRewardObject.hpp>
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

auto GJRewardObject::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x80380, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto GJRewardObject::create(SpecialRewardItem type, int total, int itemID) -> decltype(create(type, total, itemID)) {
	using FunctionType = decltype(create(type, total, itemID))(*)(SpecialRewardItem, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x638b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(type, total, itemID);
}

auto GJRewardObject::createItemUnlock(UnlockType type, int id) -> decltype(createItemUnlock(type, id)) {
	using FunctionType = decltype(createItemUnlock(type, id))(*)(UnlockType, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x63838, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(type, id);
}

auto GJRewardObject::createWithCoder(DS_Dictionary* dict) -> decltype(createWithCoder(dict)) {
	using FunctionType = decltype(createWithCoder(dict))(*)(DS_Dictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x80408, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(dict);
}

auto GJRewardObject::encodeWithCoder(DS_Dictionary* dict) -> decltype(encodeWithCoder(dict)) {
	auto self = addresser::thunkAdjust(Resolve<DS_Dictionary*>::func(&GJRewardObject::encodeWithCoder), this);
	using FunctionType = decltype(encodeWithCoder(dict))(*)(GJRewardObject*, DS_Dictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x80528, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, dict);
}

auto GJRewardObject::canEncode() -> decltype(canEncode()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJRewardObject::canEncode), this);
	using FunctionType = decltype(canEncode())(*)(GJRewardObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x805a8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJRewardObject::dataLoaded(DS_Dictionary* dict) -> decltype(dataLoaded(dict)) {
	using FunctionType = decltype(dataLoaded(dict))(*)(GJRewardObject*, DS_Dictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x804b8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dict);
}

auto GJRewardObject::init(SpecialRewardItem specialRewardItem, int total, int itemID) -> decltype(init(specialRewardItem, total, itemID)) {
	using FunctionType = decltype(init(specialRewardItem, total, itemID))(*)(GJRewardObject*, SpecialRewardItem, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x803dc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, specialRewardItem, total, itemID);
}

auto GJRewardObject::isSpecialType() -> decltype(isSpecialType()) {
	using FunctionType = decltype(isSpecialType())(*)(GJRewardObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x803ec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
