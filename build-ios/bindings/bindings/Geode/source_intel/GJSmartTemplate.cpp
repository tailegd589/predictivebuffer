
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
	static auto func = wrapFunction<FunctionType>(base::get() + 0x426990, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(type, sprite);
}

auto GJSmartTemplate::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x421f80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto GJSmartTemplate::createWithCoder(DS_Dictionary* dict) -> decltype(createWithCoder(dict)) {
	using FunctionType = decltype(createWithCoder(dict))(*)(DS_Dictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x428010, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(dict);
}

auto GJSmartTemplate::flipBlockType(SmartBlockType type, bool flipX, bool flipY) -> decltype(flipBlockType(type, flipX, flipY)) {
	using FunctionType = decltype(flipBlockType(type, flipX, flipY))(*)(SmartBlockType, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x426c00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(type, flipX, flipY);
}

auto GJSmartTemplate::flipBlockTypeX(SmartBlockType type) -> decltype(flipBlockTypeX(type)) {
	using FunctionType = decltype(flipBlockTypeX(type))(*)(SmartBlockType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x426bc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(type);
}

auto GJSmartTemplate::flipBlockTypeY(SmartBlockType type) -> decltype(flipBlockTypeY(type)) {
	using FunctionType = decltype(flipBlockTypeY(type))(*)(SmartBlockType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x426be0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(type);
}

auto GJSmartTemplate::flipKey(gd::string key, bool flipX, bool flipY) -> decltype(flipKey(key, flipX, flipY)) {
	using FunctionType = decltype(flipKey(key, flipX, flipY))(*)(gd::string, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x425bc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(key, flipX, flipY);
}

auto GJSmartTemplate::generateRemapDict() -> decltype(generateRemapDict()) {
	using FunctionType = decltype(generateRemapDict())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x426ee0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto GJSmartTemplate::getSimplifiedKey(gd::string key) -> decltype(getSimplifiedKey(key)) {
	using FunctionType = decltype(getSimplifiedKey(key))(*)(gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x422e80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(key);
}

auto GJSmartTemplate::getSimplifiedType(SmartBlockType type, bool& changed) -> decltype(getSimplifiedType(type, changed)) {
	using FunctionType = decltype(getSimplifiedType(type, changed))(*)(SmartBlockType, bool&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x423970, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(type, changed);
}

auto GJSmartTemplate::getVerySimplifiedKey(gd::string key) -> decltype(getVerySimplifiedKey(key)) {
	using FunctionType = decltype(getVerySimplifiedKey(key))(*)(gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4237b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(key);
}

auto GJSmartTemplate::keyFromNeighbors(SmartBlockType type, SmartBlockType left, SmartBlockType right, SmartBlockType top, SmartBlockType bottom, SmartBlockType topLeft, SmartBlockType topRight, SmartBlockType bottomLeft, SmartBlockType bottomRight) -> decltype(keyFromNeighbors(type, left, right, top, bottom, topLeft, topRight, bottomLeft, bottomRight)) {
	using FunctionType = decltype(keyFromNeighbors(type, left, right, top, bottom, topLeft, topRight, bottomLeft, bottomRight))(*)(SmartBlockType, SmartBlockType, SmartBlockType, SmartBlockType, SmartBlockType, SmartBlockType, SmartBlockType, SmartBlockType, SmartBlockType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4239a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(type, left, right, top, bottom, topLeft, topRight, bottomLeft, bottomRight);
}

auto GJSmartTemplate::keyFromNeighbors(cocos2d::CCPoint position, SmartGameObject* object, SmartGameObject* left, SmartGameObject* right, SmartGameObject* top, SmartGameObject* bottom, SmartGameObject* topLeft, SmartGameObject* topRight, SmartGameObject* bottomLeft, SmartGameObject* bottomRight) -> decltype(keyFromNeighbors(position, object, left, right, top, bottom, topLeft, topRight, bottomLeft, bottomRight)) {
	using FunctionType = decltype(keyFromNeighbors(position, object, left, right, top, bottom, topLeft, topRight, bottomLeft, bottomRight))(*)(cocos2d::CCPoint, SmartGameObject*, SmartGameObject*, SmartGameObject*, SmartGameObject*, SmartGameObject*, SmartGameObject*, SmartGameObject*, SmartGameObject*, SmartGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x425f60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(position, object, left, right, top, bottom, topLeft, topRight, bottomLeft, bottomRight);
}

auto GJSmartTemplate::keyFromNeighborsOld(bool left, bool right, bool top, bool bottom, bool topLeft, bool topRight, bool bottomLeft, bool bottomRight) -> decltype(keyFromNeighborsOld(left, right, top, bottom, topLeft, topRight, bottomLeft, bottomRight)) {
	using FunctionType = decltype(keyFromNeighborsOld(left, right, top, bottom, topLeft, topRight, bottomLeft, bottomRight))(*)(bool, bool, bool, bool, bool, bool, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x426c70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(left, right, top, bottom, topLeft, topRight, bottomLeft, bottomRight);
}

auto GJSmartTemplate::offsetForDir(GJSmartDirection direction, int key) -> decltype(offsetForDir(direction, key)) {
	using FunctionType = decltype(offsetForDir(direction, key))(*)(GJSmartDirection, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4263f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(direction, key);
}

auto GJSmartTemplate::offsetForObject(SmartGameObject* object) -> decltype(offsetForObject(object)) {
	using FunctionType = decltype(offsetForObject(object))(*)(SmartGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4264e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(object);
}

auto GJSmartTemplate::offsetForType(SmartBlockType type) -> decltype(offsetForType(type)) {
	using FunctionType = decltype(offsetForType(type))(*)(SmartBlockType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x426800, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(type);
}

auto GJSmartTemplate::rotateBlockType(SmartBlockType type, int degrees) -> decltype(rotateBlockType(type, degrees)) {
	using FunctionType = decltype(rotateBlockType(type, degrees))(*)(SmartBlockType, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x426b10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(type, degrees);
}

auto GJSmartTemplate::rotateBlockType90(SmartBlockType type) -> decltype(rotateBlockType90(type)) {
	using FunctionType = decltype(rotateBlockType90(type))(*)(SmartBlockType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x426ae0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(type);
}

auto GJSmartTemplate::rotateKey(gd::string key, int degrees) -> decltype(rotateKey(key, degrees)) {
	using FunctionType = decltype(rotateKey(key, degrees))(*)(gd::string, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4247d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(key, degrees);
}

auto GJSmartTemplate::shouldDiscardObject(SmartBlockType type, GJSmartDirection direction) -> decltype(shouldDiscardObject(type, direction)) {
	using FunctionType = decltype(shouldDiscardObject(type, direction))(*)(SmartBlockType, GJSmartDirection);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4268d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(type, direction);
}

auto GJSmartTemplate::smartObjectToType(SmartGameObject* object, cocos2d::CCPoint point) -> decltype(smartObjectToType(object, point)) {
	using FunctionType = decltype(smartObjectToType(object, point))(*)(SmartGameObject*, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x426540, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(object, point);
}

auto GJSmartTemplate::smartTypeToObjectKey(SmartBlockType type) -> decltype(smartTypeToObjectKey(type)) {
	using FunctionType = decltype(smartTypeToObjectKey(type))(*)(SmartBlockType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x426ac0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(type);
}

auto GJSmartTemplate::encodeWithCoder(DS_Dictionary* dict) -> decltype(encodeWithCoder(dict)) {
	auto self = addresser::thunkAdjust(Resolve<DS_Dictionary*>::func(&GJSmartTemplate::encodeWithCoder), this);
	using FunctionType = decltype(encodeWithCoder(dict))(*)(GJSmartTemplate*, DS_Dictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4283e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, dict);
}

auto GJSmartTemplate::canEncode() -> decltype(canEncode()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJSmartTemplate::canEncode), this);
	using FunctionType = decltype(canEncode())(*)(GJSmartTemplate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x428000, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJSmartTemplate::dataLoaded(DS_Dictionary* dict) -> decltype(dataLoaded(dict)) {
	using FunctionType = decltype(dataLoaded(dict))(*)(GJSmartTemplate*, DS_Dictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4280c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dict);
}

auto GJSmartTemplate::getNoCornerKey(gd::string key) -> decltype(getNoCornerKey(key)) {
	using FunctionType = decltype(getNoCornerKey(key))(*)(GJSmartTemplate*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x423670, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GJSmartTemplate::getPrefab(gd::string key, bool flipX, bool flipY) -> decltype(getPrefab(key, flipX, flipY)) {
	using FunctionType = decltype(getPrefab(key, flipX, flipY))(*)(GJSmartTemplate*, gd::string, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x425020, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key, flipX, flipY);
}

auto GJSmartTemplate::getPrefab(cocos2d::CCPoint position, SmartGameObject* object, SmartGameObject* left, SmartGameObject* right, SmartGameObject* top, SmartGameObject* bottom, SmartGameObject* topLeft, SmartGameObject* topRight, SmartGameObject* bottomLeft, SmartGameObject* bottomRight) -> decltype(getPrefab(position, object, left, right, top, bottom, topLeft, topRight, bottomLeft, bottomRight)) {
	using FunctionType = decltype(getPrefab(position, object, left, right, top, bottom, topLeft, topRight, bottomLeft, bottomRight))(*)(GJSmartTemplate*, cocos2d::CCPoint, SmartGameObject*, SmartGameObject*, SmartGameObject*, SmartGameObject*, SmartGameObject*, SmartGameObject*, SmartGameObject*, SmartGameObject*, SmartGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x425ea0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, position, object, left, right, top, bottom, topLeft, topRight, bottomLeft, bottomRight);
}

auto GJSmartTemplate::getPrefabs(gd::string key) -> decltype(getPrefabs(key)) {
	using FunctionType = decltype(getPrefabs(key))(*)(GJSmartTemplate*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x425e90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GJSmartTemplate::getPrefabWithID(gd::string key, int id) -> decltype(getPrefabWithID(key, id)) {
	using FunctionType = decltype(getPrefabWithID(key, id))(*)(GJSmartTemplate*, gd::string, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4262f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key, id);
}

auto GJSmartTemplate::getRandomPrefab(gd::string key) -> decltype(getRandomPrefab(key)) {
	using FunctionType = decltype(getRandomPrefab(key))(*)(GJSmartTemplate*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x424630, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GJSmartTemplate::getTemplateState(gd::vector<SmartPrefabResult>& results) -> decltype(getTemplateState(results)) {
	using FunctionType = decltype(getTemplateState(results))(*)(GJSmartTemplate*, gd::vector<SmartPrefabResult>&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x427990, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, results);
}

auto GJSmartTemplate::getTotalChanceForPrefab(gd::string key) -> decltype(getTotalChanceForPrefab(key)) {
	using FunctionType = decltype(getTotalChanceForPrefab(key))(*)(GJSmartTemplate*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x425dd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GJSmartTemplate::init() -> decltype(init()) {
	using FunctionType = decltype(init())(*)(GJSmartTemplate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x422020, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJSmartTemplate::isUnrequired(gd::string key) -> decltype(isUnrequired(key)) {
	using FunctionType = decltype(isUnrequired(key))(*)(GJSmartTemplate*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x427850, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GJSmartTemplate::logTemplateStatus(bool unused) -> decltype(logTemplateStatus(unused)) {
	using FunctionType = decltype(logTemplateStatus(unused))(*)(GJSmartTemplate*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x427370, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, unused);
}

auto GJSmartTemplate::removePrefab(gd::string prefabKey, int prefabID) -> decltype(removePrefab(prefabKey, prefabID)) {
	using FunctionType = decltype(removePrefab(prefabKey, prefabID))(*)(GJSmartTemplate*, gd::string, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x426360, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, prefabKey, prefabID);
}

auto GJSmartTemplate::resetScannedPrefabs() -> decltype(resetScannedPrefabs()) {
	using FunctionType = decltype(resetScannedPrefabs())(*)(GJSmartTemplate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x423a60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJSmartTemplate::savePrefab(gd::string key, gd::string data) -> decltype(savePrefab(key, data)) {
	using FunctionType = decltype(savePrefab(key, data))(*)(GJSmartTemplate*, gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4220d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key, data);
}

auto GJSmartTemplate::saveRemap(gd::string key) -> decltype(saveRemap(key)) {
	using FunctionType = decltype(saveRemap(key))(*)(GJSmartTemplate*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x422340, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GJSmartTemplate::saveRemapToDict(gd::string key, gd::string remap, cocos2d::CCDictionary* dict) -> decltype(saveRemapToDict(key, remap, dict)) {
	using FunctionType = decltype(saveRemapToDict(key, remap, dict))(*)(GJSmartTemplate*, gd::string, gd::string, cocos2d::CCDictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x423480, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key, remap, dict);
}

auto GJSmartTemplate::scanForPrefab(gd::string key) -> decltype(scanForPrefab(key)) {
	using FunctionType = decltype(scanForPrefab(key))(*)(GJSmartTemplate*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x423a90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}
