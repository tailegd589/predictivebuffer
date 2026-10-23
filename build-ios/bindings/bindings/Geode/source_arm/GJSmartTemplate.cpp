
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GJSmartTemplate.hpp>
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

auto GJSmartTemplate::applyTransformationsForType(SmartBlockType type, cocos2d::CCSprite* sprite) -> decltype(applyTransformationsForType(type, sprite)) {
	using FunctionType = decltype(applyTransformationsForType(type, sprite))(*)(SmartBlockType, cocos2d::CCSprite*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x399508, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(type, sprite);
}

auto GJSmartTemplate::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39546c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto GJSmartTemplate::createWithCoder(DS_Dictionary* dict) -> decltype(createWithCoder(dict)) {
	using FunctionType = decltype(createWithCoder(dict))(*)(DS_Dictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39a910, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(dict);
}

auto GJSmartTemplate::flipBlockType(SmartBlockType type, bool flipX, bool flipY) -> decltype(flipBlockType(type, flipX, flipY)) {
	using FunctionType = decltype(flipBlockType(type, flipX, flipY))(*)(SmartBlockType, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x399754, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(type, flipX, flipY);
}

auto GJSmartTemplate::flipBlockTypeX(SmartBlockType type) -> decltype(flipBlockTypeX(type)) {
	using FunctionType = decltype(flipBlockTypeX(type))(*)(SmartBlockType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39970c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(type);
}

auto GJSmartTemplate::flipBlockTypeY(SmartBlockType type) -> decltype(flipBlockTypeY(type)) {
	using FunctionType = decltype(flipBlockTypeY(type))(*)(SmartBlockType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x399730, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(type);
}

auto GJSmartTemplate::flipKey(gd::string key, bool flipX, bool flipY) -> decltype(flipKey(key, flipX, flipY)) {
	using FunctionType = decltype(flipKey(key, flipX, flipY))(*)(gd::string, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x398690, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(key, flipX, flipY);
}

auto GJSmartTemplate::generateRemapDict() -> decltype(generateRemapDict()) {
	using FunctionType = decltype(generateRemapDict())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3999f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto GJSmartTemplate::getSimplifiedKey(gd::string key) -> decltype(getSimplifiedKey(key)) {
	using FunctionType = decltype(getSimplifiedKey(key))(*)(gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x396128, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(key);
}

auto GJSmartTemplate::getSimplifiedType(SmartBlockType type, bool& changed) -> decltype(getSimplifiedType(type, changed)) {
	using FunctionType = decltype(getSimplifiedType(type, changed))(*)(SmartBlockType, bool&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x396cc8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(type, changed);
}

auto GJSmartTemplate::getVerySimplifiedKey(gd::string key) -> decltype(getVerySimplifiedKey(key)) {
	using FunctionType = decltype(getVerySimplifiedKey(key))(*)(gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x396a94, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(key);
}

auto GJSmartTemplate::keyFromNeighbors(SmartBlockType type, SmartBlockType left, SmartBlockType right, SmartBlockType top, SmartBlockType bottom, SmartBlockType topLeft, SmartBlockType topRight, SmartBlockType bottomLeft, SmartBlockType bottomRight) -> decltype(keyFromNeighbors(type, left, right, top, bottom, topLeft, topRight, bottomLeft, bottomRight)) {
	using FunctionType = decltype(keyFromNeighbors(type, left, right, top, bottom, topLeft, topRight, bottomLeft, bottomRight))(*)(SmartBlockType, SmartBlockType, SmartBlockType, SmartBlockType, SmartBlockType, SmartBlockType, SmartBlockType, SmartBlockType, SmartBlockType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x396cf8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(type, left, right, top, bottom, topLeft, topRight, bottomLeft, bottomRight);
}

auto GJSmartTemplate::keyFromNeighbors(cocos2d::CCPoint position, SmartGameObject* object, SmartGameObject* left, SmartGameObject* right, SmartGameObject* top, SmartGameObject* bottom, SmartGameObject* topLeft, SmartGameObject* topRight, SmartGameObject* bottomLeft, SmartGameObject* bottomRight) -> decltype(keyFromNeighbors(position, object, left, right, top, bottom, topLeft, topRight, bottomLeft, bottomRight)) {
	using FunctionType = decltype(keyFromNeighbors(position, object, left, right, top, bottom, topLeft, topRight, bottomLeft, bottomRight))(*)(cocos2d::CCPoint, SmartGameObject*, SmartGameObject*, SmartGameObject*, SmartGameObject*, SmartGameObject*, SmartGameObject*, SmartGameObject*, SmartGameObject*, SmartGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x398a80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(position, object, left, right, top, bottom, topLeft, topRight, bottomLeft, bottomRight);
}

auto GJSmartTemplate::keyFromNeighborsOld(bool left, bool right, bool top, bool bottom, bool topLeft, bool topRight, bool bottomLeft, bool bottomRight) -> decltype(keyFromNeighborsOld(left, right, top, bottom, topLeft, topRight, bottomLeft, bottomRight)) {
	using FunctionType = decltype(keyFromNeighborsOld(left, right, top, bottom, topLeft, topRight, bottomLeft, bottomRight))(*)(bool, bool, bool, bool, bool, bool, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3997b8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(left, right, top, bottom, topLeft, topRight, bottomLeft, bottomRight);
}

auto GJSmartTemplate::offsetForDir(GJSmartDirection direction, int key) -> decltype(offsetForDir(direction, key)) {
	using FunctionType = decltype(offsetForDir(direction, key))(*)(GJSmartDirection, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x398e88, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(direction, key);
}

auto GJSmartTemplate::offsetForObject(SmartGameObject* object) -> decltype(offsetForObject(object)) {
	using FunctionType = decltype(offsetForObject(object))(*)(SmartGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x399014, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(object);
}

auto GJSmartTemplate::offsetForType(SmartBlockType type) -> decltype(offsetForType(type)) {
	using FunctionType = decltype(offsetForType(type))(*)(SmartBlockType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3993e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(type);
}

auto GJSmartTemplate::rotateBlockType(SmartBlockType type, int degrees) -> decltype(rotateBlockType(type, degrees)) {
	using FunctionType = decltype(rotateBlockType(type, degrees))(*)(SmartBlockType, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3996b8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(type, degrees);
}

auto GJSmartTemplate::rotateBlockType90(SmartBlockType type) -> decltype(rotateBlockType90(type)) {
	using FunctionType = decltype(rotateBlockType90(type))(*)(SmartBlockType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39968c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(type);
}

auto GJSmartTemplate::rotateKey(gd::string key, int degrees) -> decltype(rotateKey(key, degrees)) {
	using FunctionType = decltype(rotateKey(key, degrees))(*)(gd::string, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39792c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(key, degrees);
}

auto GJSmartTemplate::shouldDiscardObject(SmartBlockType type, GJSmartDirection direction) -> decltype(shouldDiscardObject(type, direction)) {
	using FunctionType = decltype(shouldDiscardObject(type, direction))(*)(SmartBlockType, GJSmartDirection);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x399448, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(type, direction);
}

auto GJSmartTemplate::smartObjectToType(SmartGameObject* object, cocos2d::CCPoint point) -> decltype(smartObjectToType(object, point)) {
	using FunctionType = decltype(smartObjectToType(object, point))(*)(SmartGameObject*, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x399080, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(object, point);
}

auto GJSmartTemplate::smartTypeToObjectKey(SmartBlockType type) -> decltype(smartTypeToObjectKey(type)) {
	using FunctionType = decltype(smartTypeToObjectKey(type))(*)(SmartBlockType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x399668, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(type);
}

auto GJSmartTemplate::encodeWithCoder(DS_Dictionary* dict) -> decltype(encodeWithCoder(dict)) {
	auto self = addresser::thunkAdjust(Resolve<DS_Dictionary*>::func(&GJSmartTemplate::encodeWithCoder), this);
	using FunctionType = decltype(encodeWithCoder(dict))(*)(GJSmartTemplate*, DS_Dictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39acac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, dict);
}

auto GJSmartTemplate::canEncode() -> decltype(canEncode()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJSmartTemplate::canEncode), this);
	using FunctionType = decltype(canEncode())(*)(GJSmartTemplate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39a908, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJSmartTemplate::dataLoaded(DS_Dictionary* dict) -> decltype(dataLoaded(dict)) {
	using FunctionType = decltype(dataLoaded(dict))(*)(GJSmartTemplate*, DS_Dictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39a9a8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dict);
}

auto GJSmartTemplate::getNoCornerKey(gd::string key) -> decltype(getNoCornerKey(key)) {
	using FunctionType = decltype(getNoCornerKey(key))(*)(GJSmartTemplate*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x396944, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GJSmartTemplate::getPrefab(gd::string key, bool flipX, bool flipY) -> decltype(getPrefab(key, flipX, flipY)) {
	using FunctionType = decltype(getPrefab(key, flipX, flipY))(*)(GJSmartTemplate*, gd::string, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x397d30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key, flipX, flipY);
}

auto GJSmartTemplate::getPrefab(cocos2d::CCPoint position, SmartGameObject* object, SmartGameObject* left, SmartGameObject* right, SmartGameObject* top, SmartGameObject* bottom, SmartGameObject* topLeft, SmartGameObject* topRight, SmartGameObject* bottomLeft, SmartGameObject* bottomRight) -> decltype(getPrefab(position, object, left, right, top, bottom, topLeft, topRight, bottomLeft, bottomRight)) {
	using FunctionType = decltype(getPrefab(position, object, left, right, top, bottom, topLeft, topRight, bottomLeft, bottomRight))(*)(GJSmartTemplate*, cocos2d::CCPoint, SmartGameObject*, SmartGameObject*, SmartGameObject*, SmartGameObject*, SmartGameObject*, SmartGameObject*, SmartGameObject*, SmartGameObject*, SmartGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39899c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, position, object, left, right, top, bottom, topLeft, topRight, bottomLeft, bottomRight);
}

auto GJSmartTemplate::getPrefabs(gd::string key) -> decltype(getPrefabs(key)) {
	using FunctionType = decltype(getPrefabs(key))(*)(GJSmartTemplate*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x398994, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GJSmartTemplate::getPrefabWithID(gd::string key, int id) -> decltype(getPrefabWithID(key, id)) {
	using FunctionType = decltype(getPrefabWithID(key, id))(*)(GJSmartTemplate*, gd::string, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x398d4c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key, id);
}

auto GJSmartTemplate::getRandomPrefab(gd::string key) -> decltype(getRandomPrefab(key)) {
	using FunctionType = decltype(getRandomPrefab(key))(*)(GJSmartTemplate*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x397758, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GJSmartTemplate::getTemplateState(gd::vector<SmartPrefabResult>& results) -> decltype(getTemplateState(results)) {
	using FunctionType = decltype(getTemplateState(results))(*)(GJSmartTemplate*, gd::vector<SmartPrefabResult>&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39a36c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, results);
}

auto GJSmartTemplate::getTotalChanceForPrefab(gd::string key) -> decltype(getTotalChanceForPrefab(key)) {
	using FunctionType = decltype(getTotalChanceForPrefab(key))(*)(GJSmartTemplate*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3988a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GJSmartTemplate::init() -> decltype(init()) {
	using FunctionType = decltype(init())(*)(GJSmartTemplate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3954f4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJSmartTemplate::isUnrequired(gd::string key) -> decltype(isUnrequired(key)) {
	using FunctionType = decltype(isUnrequired(key))(*)(GJSmartTemplate*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39a208, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GJSmartTemplate::logTemplateStatus(bool unused) -> decltype(logTemplateStatus(unused)) {
	using FunctionType = decltype(logTemplateStatus(unused))(*)(GJSmartTemplate*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x399e24, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, unused);
}

auto GJSmartTemplate::removePrefab(gd::string prefabKey, int prefabID) -> decltype(removePrefab(prefabKey, prefabID)) {
	using FunctionType = decltype(removePrefab(prefabKey, prefabID))(*)(GJSmartTemplate*, gd::string, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x398dec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, prefabKey, prefabID);
}

auto GJSmartTemplate::resetScannedPrefabs() -> decltype(resetScannedPrefabs()) {
	using FunctionType = decltype(resetScannedPrefabs())(*)(GJSmartTemplate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x396ddc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJSmartTemplate::savePrefab(gd::string key, gd::string data) -> decltype(savePrefab(key, data)) {
	using FunctionType = decltype(savePrefab(key, data))(*)(GJSmartTemplate*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39558c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key, data);
}

auto GJSmartTemplate::saveRemap(gd::string key) -> decltype(saveRemap(key)) {
	using FunctionType = decltype(saveRemap(key))(*)(GJSmartTemplate*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3957f4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GJSmartTemplate::saveRemapToDict(gd::string key, gd::string remap, cocos2d::CCDictionary* dict) -> decltype(saveRemapToDict(key, remap, dict)) {
	using FunctionType = decltype(saveRemapToDict(key, remap, dict))(*)(GJSmartTemplate*, gd::string, gd::string, cocos2d::CCDictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x396778, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key, remap, dict);
}

auto GJSmartTemplate::scanForPrefab(gd::string key) -> decltype(scanForPrefab(key)) {
	using FunctionType = decltype(scanForPrefab(key))(*)(GJSmartTemplate*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x396e0c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}
