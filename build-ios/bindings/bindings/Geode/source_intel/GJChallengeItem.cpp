
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GJChallengeItem.hpp>
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

auto GJChallengeItem::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x8f7c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto GJChallengeItem::create(GJChallengeType challengeType, int goal, int reward, int timeLeft, gd::string questName) -> decltype(create(challengeType, goal, reward, timeLeft, questName)) {
	using FunctionType = decltype(create(challengeType, goal, reward, timeLeft, questName))(*)(GJChallengeType, int, int, int, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x8f660, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(challengeType, goal, reward, timeLeft, questName);
}

auto GJChallengeItem::createFromString(gd::string string) -> decltype(createFromString(string)) {
	using FunctionType = decltype(createFromString(string))(*)(gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x8f450, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(string);
}

auto GJChallengeItem::createWithCoder(DS_Dictionary* dsdict) -> decltype(createWithCoder(dsdict)) {
	using FunctionType = decltype(createWithCoder(dsdict))(*)(DS_Dictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x8f880, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(dsdict);
}

auto GJChallengeItem::encodeWithCoder(DS_Dictionary* dsdict) -> decltype(encodeWithCoder(dsdict)) {
	auto self = addresser::thunkAdjust(Resolve<DS_Dictionary*>::func(&GJChallengeItem::encodeWithCoder), this);
	using FunctionType = decltype(encodeWithCoder(dsdict))(*)(GJChallengeItem*, DS_Dictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x8fa20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, dsdict);
}

auto GJChallengeItem::canEncode() -> decltype(canEncode()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJChallengeItem::canEncode), this);
	using FunctionType = decltype(canEncode())(*)(GJChallengeItem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x8faf0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJChallengeItem::dataLoaded(DS_Dictionary* dsdict) -> decltype(dataLoaded(dsdict)) {
	using FunctionType = decltype(dataLoaded(dsdict))(*)(GJChallengeItem*, DS_Dictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x8f8c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dsdict);
}

auto GJChallengeItem::incrementCount(int add) -> decltype(incrementCount(add)) {
	using FunctionType = decltype(incrementCount(add))(*)(GJChallengeItem*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x736d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, add);
}

auto GJChallengeItem::init(GJChallengeType challengeType, int goal, int reward, int timeLeft, gd::string questName) -> decltype(init(challengeType, goal, reward, timeLeft, questName)) {
	using FunctionType = decltype(init(challengeType, goal, reward, timeLeft, questName))(*)(GJChallengeItem*, GJChallengeType, int, int, int, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x8f7f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, challengeType, goal, reward, timeLeft, questName);
}
