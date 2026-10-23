
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GameToolbox.hpp>
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

auto GameToolbox::addBackButton(cocos2d::CCLayer* parent, cocos2d::CCMenuItem* menuItem) -> decltype(addBackButton(parent, menuItem)) {
	using FunctionType = decltype(addBackButton(parent, menuItem))(*)(cocos2d::CCLayer*, cocos2d::CCMenuItem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4495cc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(parent, menuItem);
}

auto GameToolbox::addRThumbScrollButton(cocos2d::CCLayer* parent) -> decltype(addRThumbScrollButton(parent)) {
	using FunctionType = decltype(addRThumbScrollButton(parent))(*)(cocos2d::CCLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4496b4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(parent);
}

auto GameToolbox::alignItemsHorisontally(cocos2d::CCArray* items, float gap, cocos2d::CCPoint position, bool skipSize) -> decltype(alignItemsHorisontally(items, gap, position, skipSize)) {
	using FunctionType = decltype(alignItemsHorisontally(items, gap, position, skipSize))(*)(cocos2d::CCArray*, float, cocos2d::CCPoint, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4481a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(items, gap, position, skipSize);
}

auto GameToolbox::alignItemsVertically(cocos2d::CCArray* items, float gap, cocos2d::CCPoint position) -> decltype(alignItemsVertically(items, gap, position)) {
	using FunctionType = decltype(alignItemsVertically(items, gap, position))(*)(cocos2d::CCArray*, float, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x448458, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(items, gap, position);
}

auto GameToolbox::bounceTime(float time) -> decltype(bounceTime(time)) {
	using FunctionType = decltype(bounceTime(time))(*)(float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x44f8a8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(time);
}

auto GameToolbox::colorToSepia(cocos2d::ccColor3B color, float factor) -> decltype(colorToSepia(color, factor)) {
	using FunctionType = decltype(colorToSepia(color, factor))(*)(cocos2d::ccColor3B, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x449b14, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(color, factor);
}

auto GameToolbox::contentScaleClipRect(cocos2d::CCRect& rect) -> decltype(contentScaleClipRect(rect)) {
	using FunctionType = decltype(contentScaleClipRect(rect))(*)(cocos2d::CCRect&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x448a9c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(rect);
}

auto GameToolbox::createHashString(gd::string const& str, int length) -> decltype(createHashString(str, length)) {
	using FunctionType = decltype(createHashString(str, length))(*)(gd::string const&, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x44b1ec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(str, length);
}

auto GameToolbox::createToggleButton(gd::string label, cocos2d::SEL_MenuHandler selector, bool state, cocos2d::CCMenu* menu, cocos2d::CCPoint position, cocos2d::CCNode* parent, cocos2d::CCNode* labelParent, cocos2d::CCArray* container) -> decltype(createToggleButton(label, selector, state, menu, position, parent, labelParent, container)) {
	using FunctionType = decltype(createToggleButton(label, selector, state, menu, position, parent, labelParent, container))(*)(gd::string, cocos2d::SEL_MenuHandler, bool, cocos2d::CCMenu*, cocos2d::CCPoint, cocos2d::CCNode*, cocos2d::CCNode*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x448ae0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(label, selector, state, menu, position, parent, labelParent, container);
}

auto GameToolbox::createToggleButton(gd::string label, cocos2d::SEL_MenuHandler selector, bool state, cocos2d::CCMenu* menu, cocos2d::CCPoint position, cocos2d::CCNode* parent, cocos2d::CCNode* labelParent, float buttonScale, float maxLabelScale, float maxLabelWidth, cocos2d::CCPoint labelOffset, char const* font, bool labelTop, int labelTag, cocos2d::CCArray* container) -> decltype(createToggleButton(label, selector, state, menu, position, parent, labelParent, buttonScale, maxLabelScale, maxLabelWidth, labelOffset, font, labelTop, labelTag, container)) {
	using FunctionType = decltype(createToggleButton(label, selector, state, menu, position, parent, labelParent, buttonScale, maxLabelScale, maxLabelWidth, labelOffset, font, labelTop, labelTag, container))(*)(gd::string, cocos2d::SEL_MenuHandler, bool, cocos2d::CCMenu*, cocos2d::CCPoint, cocos2d::CCNode*, cocos2d::CCNode*, float, float, float, cocos2d::CCPoint, char const*, bool, int, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x448c1c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(label, selector, state, menu, position, parent, labelParent, buttonScale, maxLabelScale, maxLabelWidth, labelOffset, font, labelTop, labelTag, container);
}

auto GameToolbox::doWeHaveInternet() -> decltype(doWeHaveInternet()) {
	using FunctionType = decltype(doWeHaveInternet())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4485e8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto GameToolbox::easeToText(int easingType) -> decltype(easeToText(easingType)) {
	using FunctionType = decltype(easeToText(easingType))(*)(int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x44f594, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(easingType);
}

auto GameToolbox::fast_rand() -> decltype(fast_rand()) {
	using FunctionType = decltype(fast_rand())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x44b6ec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto GameToolbox::fast_rand_0_1() -> decltype(fast_rand_0_1()) {
	using FunctionType = decltype(fast_rand_0_1())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x44b714, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto GameToolbox::fast_rand_minus1_1() -> decltype(fast_rand_minus1_1()) {
	using FunctionType = decltype(fast_rand_minus1_1())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x44b750, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto GameToolbox::fast_srand(uint64_t seed) -> decltype(fast_srand(seed)) {
	using FunctionType = decltype(fast_srand(seed))(*)(uint64_t);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x44b6d4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(seed);
}

auto GameToolbox::gen_random(int length) -> decltype(gen_random(length)) {
	using FunctionType = decltype(gen_random(length))(*)(int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x44b554, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(length);
}

auto GameToolbox::getDropActionWDelay(float delay, float duration, float scale, cocos2d::CCNode* target, cocos2d::SEL_CallFunc selector) -> decltype(getDropActionWDelay(delay, duration, scale, target, selector)) {
	using FunctionType = decltype(getDropActionWDelay(delay, duration, scale, target, selector))(*)(float, float, float, cocos2d::CCNode*, cocos2d::SEL_CallFunc);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x448044, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(delay, duration, scale, target, selector);
}

auto GameToolbox::getDropActionWEnd(float delay, float duration, float scale, cocos2d::CCAction* action, float actionDelay) -> decltype(getDropActionWEnd(delay, duration, scale, action, actionDelay)) {
	using FunctionType = decltype(getDropActionWEnd(delay, duration, scale, action, actionDelay))(*)(float, float, float, cocos2d::CCAction*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x448100, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(delay, duration, scale, action, actionDelay);
}

auto GameToolbox::getEasedAction(cocos2d::CCActionInterval* action, int easingType, float easingRate) -> decltype(getEasedAction(action, easingType, easingRate)) {
	using FunctionType = decltype(getEasedAction(action, easingType, easingRate))(*)(cocos2d::CCActionInterval*, int, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x44b498, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(action, easingType, easingRate);
}

auto GameToolbox::getEasedValue(float value, int easingType, float easingRate) -> decltype(getEasedValue(value, easingType, easingRate)) {
	using FunctionType = decltype(getEasedValue(value, easingType, easingRate))(*)(float, int, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x44f990, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(value, easingType, easingRate);
}

auto GameToolbox::getfast_srand() -> decltype(getfast_srand()) {
	using FunctionType = decltype(getfast_srand())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x44b6e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto GameToolbox::getInvertedEasing(int easingType) -> decltype(getInvertedEasing(easingType)) {
	using FunctionType = decltype(getInvertedEasing(easingType))(*)(int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x44b518, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(easingType);
}

auto GameToolbox::getLargestMergedIntDicts(cocos2d::CCDictionary* dict1, cocos2d::CCDictionary* dict2) -> decltype(getLargestMergedIntDicts(dict1, dict2)) {
	using FunctionType = decltype(getLargestMergedIntDicts(dict1, dict2))(*)(cocos2d::CCDictionary*, cocos2d::CCDictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4490b8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(dict1, dict2);
}

auto GameToolbox::getMultipliedHSV(cocos2d::ccHSVValue const& value, float factor) -> decltype(getMultipliedHSV(value, factor)) {
	using FunctionType = decltype(getMultipliedHSV(value, factor))(*)(cocos2d::ccHSVValue const&, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x449ca0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(value, factor);
}

auto GameToolbox::getRelativeOffset(GameObject* object, cocos2d::CCPoint offset) -> decltype(getRelativeOffset(object, offset)) {
	using FunctionType = decltype(getRelativeOffset(object, offset))(*)(GameObject*, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x448ec0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(object, offset);
}

auto GameToolbox::getResponse(cocos2d::extension::CCHttpResponse* response) -> decltype(getResponse(response)) {
	using FunctionType = decltype(getResponse(response))(*)(cocos2d::extension::CCHttpResponse*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x44886c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(response);
}

auto GameToolbox::getTimeString(int seconds, bool noSeconds) -> decltype(getTimeString(seconds, noSeconds)) {
	using FunctionType = decltype(getTimeString(seconds, noSeconds))(*)(int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x44b2bc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(seconds, noSeconds);
}

auto GameToolbox::hsvFromString(gd::string const& str, char const* delim) -> decltype(hsvFromString(str, delim)) {
	using FunctionType = decltype(hsvFromString(str, delim))(*)(gd::string const&, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x449d0c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(str, delim);
}

auto GameToolbox::intToShortString(int value) -> decltype(intToShortString(value)) {
	using FunctionType = decltype(intToShortString(value))(*)(int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4503e8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(value);
}

auto GameToolbox::intToString(int value) -> decltype(intToString(value)) {
	using FunctionType = decltype(intToString(value))(*)(int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4500bc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(value);
}

auto GameToolbox::isIOS() -> decltype(isIOS()) {
	using FunctionType = decltype(isIOS())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x448748, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto GameToolbox::isRateEasing(int easingType) -> decltype(isRateEasing(easingType)) {
	using FunctionType = decltype(isRateEasing(easingType))(*)(int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x44b544, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(easingType);
}

auto GameToolbox::mergeDictsSaveLargestInt(cocos2d::CCDictionary* toDict, cocos2d::CCDictionary* fromDict) -> decltype(mergeDictsSaveLargestInt(toDict, fromDict)) {
	using FunctionType = decltype(mergeDictsSaveLargestInt(toDict, fromDict))(*)(cocos2d::CCDictionary*, cocos2d::CCDictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x44910c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(toDict, fromDict);
}

auto GameToolbox::mergeDictsSkipConflict(cocos2d::CCDictionary* toDict, cocos2d::CCDictionary* fromDict) -> decltype(mergeDictsSkipConflict(toDict, fromDict)) {
	using FunctionType = decltype(mergeDictsSkipConflict(toDict, fromDict))(*)(cocos2d::CCDictionary*, cocos2d::CCDictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x449378, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(toDict, fromDict);
}

auto GameToolbox::msToTimeString(int milliseconds, int formattingMode) -> decltype(msToTimeString(milliseconds, formattingMode)) {
	using FunctionType = decltype(msToTimeString(milliseconds, formattingMode))(*)(int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x450a1c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(milliseconds, formattingMode);
}

auto GameToolbox::multipliedColorValue(cocos2d::ccColor3B minColor, cocos2d::ccColor3B maxColor, float factor) -> decltype(multipliedColorValue(minColor, maxColor, factor)) {
	using FunctionType = decltype(multipliedColorValue(minColor, maxColor, factor))(*)(cocos2d::ccColor3B, cocos2d::ccColor3B, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x449a40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(minColor, maxColor, factor);
}

auto GameToolbox::openAppPage() -> decltype(openAppPage()) {
	using FunctionType = decltype(openAppPage())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x448848, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto GameToolbox::openRateURL(gd::string str1, gd::string str2) -> decltype(openRateURL(str1, str2)) {
	using FunctionType = decltype(openRateURL(str1, str2))(*)(gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x448750, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(str1, str2);
}

auto GameToolbox::particleFromString(gd::string const& str, cocos2d::CCParticleSystemQuad* system, bool dontUpdate) -> decltype(particleFromString(str, system, dontUpdate)) {
	using FunctionType = decltype(particleFromString(str, system, dontUpdate))(*)(gd::string const&, cocos2d::CCParticleSystemQuad*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x44efec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(str, system, dontUpdate);
}

auto GameToolbox::particleFromStruct(cocos2d::ParticleStruct const& particleStruct, cocos2d::CCParticleSystemQuad* system, bool dontUpdate) -> decltype(particleFromStruct(particleStruct, system, dontUpdate)) {
	using FunctionType = decltype(particleFromStruct(particleStruct, system, dontUpdate))(*)(cocos2d::ParticleStruct const&, cocos2d::CCParticleSystemQuad*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x44f0d8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(particleStruct, system, dontUpdate);
}

auto GameToolbox::particleStringToStruct(gd::string const& str, cocos2d::ParticleStruct& particleStruct) -> decltype(particleStringToStruct(str, particleStruct)) {
	using FunctionType = decltype(particleStringToStruct(str, particleStruct))(*)(gd::string const&, cocos2d::ParticleStruct&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x44e1b4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(str, particleStruct);
}

auto GameToolbox::pointsToString(int points) -> decltype(pointsToString(points)) {
	using FunctionType = decltype(pointsToString(points))(*)(int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x450b70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(points);
}

auto GameToolbox::postClipVisit() -> decltype(postClipVisit()) {
	using FunctionType = decltype(postClipVisit())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x448ad8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto GameToolbox::preVisitWithClippingRect(cocos2d::CCNode* node, cocos2d::CCRect rect) -> decltype(preVisitWithClippingRect(node, rect)) {
	using FunctionType = decltype(preVisitWithClippingRect(node, rect))(*)(cocos2d::CCNode*, cocos2d::CCRect);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4489f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(node, rect);
}

auto GameToolbox::preVisitWithClipRect(cocos2d::CCRect rect) -> decltype(preVisitWithClipRect(rect)) {
	using FunctionType = decltype(preVisitWithClipRect(rect))(*)(cocos2d::CCRect);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x448aa0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(rect);
}

auto GameToolbox::saveParticleToString(cocos2d::CCParticleSystemQuad* system) -> decltype(saveParticleToString(system)) {
	using FunctionType = decltype(saveParticleToString(system))(*)(cocos2d::CCParticleSystemQuad*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x44b798, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(system);
}

auto GameToolbox::saveStringToFile(gd::string const& path, gd::string const& content) -> decltype(saveStringToFile(path, content)) {
	using FunctionType = decltype(saveStringToFile(path, content))(*)(gd::string const&, gd::string const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x45025c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(path, content);
}

auto GameToolbox::stringFromHSV(cocos2d::ccHSVValue value, char const* separator) -> decltype(stringFromHSV(value, separator)) {
	using FunctionType = decltype(stringFromHSV(value, separator))(*)(cocos2d::ccHSVValue, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x44a2a4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(value, separator);
}

auto GameToolbox::stringSetupToDict(gd::string const& str, char const* separator) -> decltype(stringSetupToDict(str, separator)) {
	using FunctionType = decltype(stringSetupToDict(str, separator))(*)(gd::string const&, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x44ab30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(str, separator);
}

auto GameToolbox::stringSetupToMap(gd::string const& str, char const* separator, gd::map<gd::string, gd::string>& setup) -> decltype(stringSetupToMap(str, separator, setup)) {
	using FunctionType = decltype(stringSetupToMap(str, separator, setup))(*)(gd::string const&, char const*, gd::map<gd::string, gd::string>&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x44a790, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(str, separator, setup);
}

auto GameToolbox::strongColor(cocos2d::ccColor3B color) -> decltype(strongColor(color)) {
	using FunctionType = decltype(strongColor(color))(*)(cocos2d::ccColor3B);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x44b154, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(color);
}

auto GameToolbox::timestampToHumanReadable(time_t timestamp) -> decltype(timestampToHumanReadable(timestamp)) {
	using FunctionType = decltype(timestampToHumanReadable(timestamp))(*)(time_t);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4507bc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(timestamp);
}

auto GameToolbox::transformColor(cocos2d::ccColor3B const& color, cocos2d::ccHSVValue hsv) -> decltype(transformColor(color, hsv)) {
	using FunctionType = decltype(transformColor(color, hsv))(*)(cocos2d::ccColor3B const&, cocos2d::ccHSVValue);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x449884, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(color, hsv);
}

auto GameToolbox::transformColor(cocos2d::ccColor3B const& color, float h, float s, float v) -> decltype(transformColor(color, h, s, v)) {
	using FunctionType = decltype(transformColor(color, h, s, v))(*)(cocos2d::ccColor3B const&, float, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x449868, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(color, h, s, v);
}
