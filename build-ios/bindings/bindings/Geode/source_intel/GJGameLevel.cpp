
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GJGameLevel.hpp>
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

GJGameLevel::GJGameLevel() : GJGameLevel(geode::CutoffConstructor, sizeof(GJGameLevel)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	GJGameLevel::~GJGameLevel();

	using FunctionType = void(*)(GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x563bf0, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

GJGameLevel::~GJGameLevel() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(GJGameLevel*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x55b090, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) GJGameLevel(geode::CutoffConstructor, sizeof(GJGameLevel));
		geode::DestructorLock::addLock(this);
	}
}

auto GJGameLevel::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52c890, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto GJGameLevel::create(cocos2d::CCDictionary* dict, bool download) -> decltype(create(dict, download)) {
	using FunctionType = decltype(create(dict, download))(*)(cocos2d::CCDictionary*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52efa0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(dict, download);
}

auto GJGameLevel::createWithCoder(DS_Dictionary* dict) -> decltype(createWithCoder(dict)) {
	using FunctionType = decltype(createWithCoder(dict))(*)(DS_Dictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x55d880, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(dict);
}

auto GJGameLevel::demonIconForDifficulty(DemonDifficultyType type) -> decltype(demonIconForDifficulty(type)) {
	using FunctionType = decltype(demonIconForDifficulty(type))(*)(DemonDifficultyType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x55f710, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(type);
}

auto GJGameLevel::getLengthKey(int length, bool platformer) -> decltype(getLengthKey(length, platformer)) {
	using FunctionType = decltype(getLengthKey(length, platformer))(*)(int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x55bc60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(length, platformer);
}

auto GJGameLevel::lengthKeyToString(int key) -> decltype(lengthKeyToString(key)) {
	using FunctionType = decltype(lengthKeyToString(key))(*)(int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x55bca0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(key);
}

auto GJGameLevel::encodeWithCoder(DS_Dictionary* dict) -> decltype(encodeWithCoder(dict)) {
	auto self = addresser::thunkAdjust(Resolve<DS_Dictionary*>::func(&GJGameLevel::encodeWithCoder), this);
	using FunctionType = decltype(encodeWithCoder(dict))(*)(GJGameLevel*, DS_Dictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x55ea40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, dict);
}

auto GJGameLevel::canEncode() -> decltype(canEncode()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJGameLevel::canEncode), this);
	using FunctionType = decltype(canEncode())(*)(GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x55f600, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJGameLevel::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJGameLevel::init), this);
	using FunctionType = decltype(init())(*)(GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x55b3d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJGameLevel::areCoinsVerified() -> decltype(areCoinsVerified()) {
	using FunctionType = decltype(areCoinsVerified())(*)(GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x55f610, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJGameLevel::copyLevelInfo(GJGameLevel* level) -> decltype(copyLevelInfo(level)) {
	using FunctionType = decltype(copyLevelInfo(level))(*)(GJGameLevel*, GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x55cee0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, level);
}

auto GJGameLevel::dataLoaded(DS_Dictionary* dict) -> decltype(dataLoaded(dict)) {
	using FunctionType = decltype(dataLoaded(dict))(*)(GJGameLevel*, DS_Dictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x55d8f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dict);
}

auto GJGameLevel::generateSettingsString() -> decltype(generateSettingsString()) {
	using FunctionType = decltype(generateSettingsString())(*)(GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x55c1d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJGameLevel::getAudioFileName() -> decltype(getAudioFileName()) {
	using FunctionType = decltype(getAudioFileName())(*)(GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x55bfe0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJGameLevel::getAverageDifficulty() -> decltype(getAverageDifficulty()) {
	using FunctionType = decltype(getAverageDifficulty())(*)(GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x55bd70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJGameLevel::getCoinKey(int coinNumber) -> decltype(getCoinKey(coinNumber)) {
	using FunctionType = decltype(getCoinKey(coinNumber))(*)(GJGameLevel*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x54c470, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, coinNumber);
}

auto GJGameLevel::getLastBuildPageForTab(int tab) -> decltype(getLastBuildPageForTab(tab)) {
	using FunctionType = decltype(getLastBuildPageForTab(tab))(*)(GJGameLevel*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x55bdc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, tab);
}

auto GJGameLevel::getListSnapshot() -> decltype(getListSnapshot()) {
	using FunctionType = decltype(getListSnapshot())(*)(GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x55d4d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJGameLevel::getNormalPercent() -> decltype(getNormalPercent()) {
	using FunctionType = decltype(getNormalPercent())(*)(GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52d210, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJGameLevel::getSongName() -> decltype(getSongName()) {
	using FunctionType = decltype(getSongName())(*)(GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x55c100, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJGameLevel::getUnpackedLevelDescription() -> decltype(getUnpackedLevelDescription()) {
	using FunctionType = decltype(getUnpackedLevelDescription())(*)(GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x55f670, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJGameLevel::handleStatsConflict(GJGameLevel* level) -> decltype(handleStatsConflict(level)) {
	using FunctionType = decltype(handleStatsConflict(level))(*)(GJGameLevel*, GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x53c950, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, level);
}

auto GJGameLevel::isPlatformer() -> decltype(isPlatformer()) {
	using FunctionType = decltype(isPlatformer())(*)(GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x536c80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJGameLevel::levelWasAltered() -> decltype(levelWasAltered()) {
	using FunctionType = decltype(levelWasAltered())(*)(GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x55b5f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJGameLevel::levelWasSubmitted() -> decltype(levelWasSubmitted()) {
	using FunctionType = decltype(levelWasSubmitted())(*)(GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x53e880, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJGameLevel::parseSettingsString(gd::string str) -> decltype(parseSettingsString(str)) {
	using FunctionType = decltype(parseSettingsString(str))(*)(GJGameLevel*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x55b3c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, str);
}

auto GJGameLevel::saveNewScore(int value, int type, int ticks, int clicks, int coins, gd::string inputs, bool save) -> decltype(saveNewScore(value, type, ticks, clicks, coins, inputs, save)) {
	using FunctionType = decltype(saveNewScore(value, type, ticks, clicks, coins, inputs, save))(*)(GJGameLevel*, int, int, int, int, int, gd::string, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x55c330, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, value, type, ticks, clicks, coins, inputs, save);
}

auto GJGameLevel::savePercentage(int percent, bool isPracticeMode, int clicks, int attempts, bool isChkValid) -> decltype(savePercentage(percent, isPracticeMode, clicks, attempts, isChkValid)) {
	using FunctionType = decltype(savePercentage(percent, isPracticeMode, clicks, attempts, isChkValid))(*)(GJGameLevel*, int, bool, int, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x55b7d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, percent, isPracticeMode, clicks, attempts, isChkValid);
}

auto GJGameLevel::scoreStringToVector(gd::string& str, gd::vector<int>& vec) -> decltype(scoreStringToVector(str, vec)) {
	using FunctionType = decltype(scoreStringToVector(str, vec))(*)(GJGameLevel*, gd::string&, gd::vector<int>&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x55c910, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, str, vec);
}

auto GJGameLevel::scoreVectorToString(gd::vector<int>& vec, int type) -> decltype(scoreVectorToString(vec, type)) {
	using FunctionType = decltype(scoreVectorToString(vec, type))(*)(GJGameLevel*, gd::vector<int>&, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x55cb80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, vec, type);
}

auto GJGameLevel::setLastBuildPageForTab(int tab, int page) -> decltype(setLastBuildPageForTab(tab, page)) {
	using FunctionType = decltype(setLastBuildPageForTab(tab, page))(*)(GJGameLevel*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x55bec0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, tab, page);
}

auto GJGameLevel::setNormalPercent(int percent) -> decltype(setNormalPercent(percent)) {
	using FunctionType = decltype(setNormalPercent(percent))(*)(GJGameLevel*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52ebf0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, percent);
}

auto GJGameLevel::shouldCheatReset() -> decltype(shouldCheatReset()) {
	using FunctionType = decltype(shouldCheatReset())(*)(GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x52ebb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJGameLevel::storeNewLocalScore(int value, int type) -> decltype(storeNewLocalScore(value, type)) {
	using FunctionType = decltype(storeNewLocalScore(value, type))(*)(GJGameLevel*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x55c740, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, value, type);
}

auto GJGameLevel::unverifyCoins() -> decltype(unverifyCoins()) {
	using FunctionType = decltype(unverifyCoins())(*)(GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x55b720, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
