
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/LevelTools.hpp>
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

auto LevelTools::artistForAudio(int id) -> decltype(artistForAudio(id)) {
	using FunctionType = decltype(artistForAudio(id))(*)(int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x457004, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(id);
}

auto LevelTools::base64DecodeString(gd::string str) -> decltype(base64DecodeString(str)) {
	using FunctionType = decltype(base64DecodeString(str))(*)(gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x459d54, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(str);
}

auto LevelTools::base64EncodeString(gd::string str) -> decltype(base64EncodeString(str)) {
	using FunctionType = decltype(base64EncodeString(str))(*)(gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x459d20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(str);
}

auto LevelTools::createStarPackDict() -> decltype(createStarPackDict()) {
	using FunctionType = decltype(createStarPackDict())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x459d88, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto LevelTools::fbURLForArtist(int id) -> decltype(fbURLForArtist(id)) {
	using FunctionType = decltype(fbURLForArtist(id))(*)(int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x457fac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(id);
}

auto LevelTools::getAudioBPM(int id) -> decltype(getAudioBPM(id)) {
	using FunctionType = decltype(getAudioBPM(id))(*)(int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x458304, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(id);
}

auto LevelTools::getAudioFileName(int id) -> decltype(getAudioFileName(id)) {
	using FunctionType = decltype(getAudioFileName(id))(*)(int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x456978, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(id);
}

auto LevelTools::getAudioString(int id) -> decltype(getAudioString(id)) {
	using FunctionType = decltype(getAudioString(id))(*)(int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x458324, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(id);
}

auto LevelTools::getAudioTitle(int id) -> decltype(getAudioTitle(id)) {
	using FunctionType = decltype(getAudioTitle(id))(*)(int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x456228, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(id);
}

auto LevelTools::getLastGameplayReversed() -> decltype(getLastGameplayReversed()) {
	using FunctionType = decltype(getLastGameplayReversed())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x459850, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto LevelTools::getLastGameplayRotated() -> decltype(getLastGameplayRotated()) {
	using FunctionType = decltype(getLastGameplayRotated())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x45985c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto LevelTools::getLastTimewarp() -> decltype(getLastTimewarp()) {
	using FunctionType = decltype(getLastTimewarp())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x459844, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto LevelTools::getLevel(int id, bool noString) -> decltype(getLevel(id, noString)) {
	using FunctionType = decltype(getLevel(id, noString))(*)(int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4544b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(id, noString);
}

auto LevelTools::getLevelList() -> decltype(getLevelList()) {
	using FunctionType = decltype(getLevelList())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4540fc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto LevelTools::getSongObject(int id) -> decltype(getSongObject(id)) {
	using FunctionType = decltype(getSongObject(id))(*)(int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x459868, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(id);
}

auto LevelTools::moveTriggerObjectsToArray(cocos2d::CCArray* objects, cocos2d::CCDictionary* objectsDict, int index) -> decltype(moveTriggerObjectsToArray(objects, objectsDict, index)) {
	using FunctionType = decltype(moveTriggerObjectsToArray(objects, objectsDict, index))(*)(cocos2d::CCArray*, cocos2d::CCDictionary*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x45a1f8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(objects, objectsDict, index);
}

auto LevelTools::nameForArtist(int id) -> decltype(nameForArtist(id)) {
	using FunctionType = decltype(nameForArtist(id))(*)(int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x457028, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(id);
}

auto LevelTools::ngURLForArtist(int id) -> decltype(ngURLForArtist(id)) {
	using FunctionType = decltype(ngURLForArtist(id))(*)(int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4578d4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(id);
}

auto LevelTools::offsetBPMForTrack(int id) -> decltype(offsetBPMForTrack(id)) {
	using FunctionType = decltype(offsetBPMForTrack(id))(*)(int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x458920, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(id);
}

auto LevelTools::posForTime(float time, cocos2d::CCArray* objects, int speed, bool platformer, int& rotateChannel) -> decltype(posForTime(time, objects, speed, platformer, rotateChannel)) {
	using FunctionType = decltype(posForTime(time, objects, speed, platformer, rotateChannel))(*)(float, cocos2d::CCArray*, int, bool, int&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x45934c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(time, objects, speed, platformer, rotateChannel);
}

auto LevelTools::posForTimeInternal(float time, cocos2d::CCArray* objects, int speed, bool platformer, bool ignoreMinorAxis, bool ignoreWarp, int& rotateChannel, int unused) -> decltype(posForTimeInternal(time, objects, speed, platformer, ignoreMinorAxis, ignoreWarp, rotateChannel, unused)) {
	using FunctionType = decltype(posForTimeInternal(time, objects, speed, platformer, ignoreMinorAxis, ignoreWarp, rotateChannel, unused))(*)(float, cocos2d::CCArray*, int, bool, bool, bool, int&, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x45935c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(time, objects, speed, platformer, ignoreMinorAxis, ignoreWarp, rotateChannel, unused);
}

auto LevelTools::sortChannelOrderObjects(cocos2d::CCArray* objects, cocos2d::CCDictionary* objectsDict, bool moveObjects) -> decltype(sortChannelOrderObjects(objects, objectsDict, moveObjects)) {
	using FunctionType = decltype(sortChannelOrderObjects(objects, objectsDict, moveObjects))(*)(cocos2d::CCArray*, cocos2d::CCDictionary*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x45a2b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(objects, objectsDict, moveObjects);
}

auto LevelTools::sortSpeedObjects(cocos2d::CCArray* objects, GJBaseGameLayer* layer) -> decltype(sortSpeedObjects(objects, layer)) {
	using FunctionType = decltype(sortSpeedObjects(objects, layer))(*)(cocos2d::CCArray*, GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x45a578, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(objects, layer);
}

auto LevelTools::timeForPos(cocos2d::CCPoint position, cocos2d::CCArray* objects, int speed, int order, int channel, bool songTriggers, bool platformer, bool ignoreWarp, bool ignoreRotate, int id) -> decltype(timeForPos(position, objects, speed, order, channel, songTriggers, platformer, ignoreWarp, ignoreRotate, id)) {
	using FunctionType = decltype(timeForPos(position, objects, speed, order, channel, songTriggers, platformer, ignoreWarp, ignoreRotate, id))(*)(cocos2d::CCPoint, cocos2d::CCArray*, int, int, int, bool, bool, bool, bool, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x45896c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(position, objects, speed, order, channel, songTriggers, platformer, ignoreWarp, ignoreRotate, id);
}

auto LevelTools::toggleDebugLogging(bool enabled) -> decltype(toggleDebugLogging(enabled)) {
	using FunctionType = decltype(toggleDebugLogging(enabled))(*)(bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4540f8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(enabled);
}

auto LevelTools::urlForAudio(int id) -> decltype(urlForAudio(id)) {
	using FunctionType = decltype(urlForAudio(id))(*)(int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x457274, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(id);
}

auto LevelTools::valueForSpeedMod(int speed) -> decltype(valueForSpeedMod(speed)) {
	using FunctionType = decltype(valueForSpeedMod(speed))(*)(int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x458940, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(speed);
}

auto LevelTools::verifyLevelIntegrity(gd::string str, int id) -> decltype(verifyLevelIntegrity(str, id)) {
	using FunctionType = decltype(verifyLevelIntegrity(str, id))(*)(gd::string, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x459b70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(str, id);
}

auto LevelTools::ytURLForArtist(int id) -> decltype(ytURLForArtist(id)) {
	using FunctionType = decltype(ytURLForArtist(id))(*)(int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x457c18, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(id);
}
