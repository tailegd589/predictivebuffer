
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/EffectGameObject.hpp>
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

EffectGameObject::EffectGameObject() : EffectGameObject(geode::CutoffConstructor, sizeof(EffectGameObject)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	EffectGameObject::~EffectGameObject();

	using FunctionType = void(*)(EffectGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1a2200, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

auto EffectGameObject::create(char const* frame) -> decltype(create(frame)) {
	using FunctionType = decltype(create(frame))(*)(char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x172940, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(frame);
}

auto EffectGameObject::setOpacity(unsigned char opacity) -> decltype(setOpacity(opacity)) {
	auto self = addresser::thunkAdjust(Resolve<unsigned char>::func(&EffectGameObject::setOpacity), this);
	using FunctionType = decltype(setOpacity(opacity))(*)(EffectGameObject*, unsigned char);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x172d20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, opacity);
}

auto EffectGameObject::firstSetup() -> decltype(firstSetup()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&EffectGameObject::firstSetup), this);
	using FunctionType = decltype(firstSetup())(*)(EffectGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x174270, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto EffectGameObject::customSetup() -> decltype(customSetup()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&EffectGameObject::customSetup), this);
	using FunctionType = decltype(customSetup())(*)(EffectGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1572dc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto EffectGameObject::triggerObject(GJBaseGameLayer* layer, int uniqueID, gd::vector<int> const* remapKeys) -> decltype(triggerObject(layer, uniqueID, remapKeys)) {
	auto self = addresser::thunkAdjust(Resolve<GJBaseGameLayer*, int, gd::vector<int> const*>::func(&EffectGameObject::triggerObject), this);
	using FunctionType = decltype(triggerObject(layer, uniqueID, remapKeys))(*)(EffectGameObject*, GJBaseGameLayer*, int, gd::vector<int> const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x172da4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, layer, uniqueID, remapKeys);
}

auto EffectGameObject::customObjectSetup(gd::vector<gd::string>& values, gd::vector<void*>& exists) -> decltype(customObjectSetup(values, exists)) {
	auto self = addresser::thunkAdjust(Resolve<gd::vector<gd::string>&, gd::vector<void*>&>::func(&EffectGameObject::customObjectSetup), this);
	using FunctionType = decltype(customObjectSetup(values, exists))(*)(EffectGameObject*, gd::vector<gd::string>&, gd::vector<void*>&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1586f8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, values, exists);
}

auto EffectGameObject::getSaveString(GJBaseGameLayer* layer) -> decltype(getSaveString(layer)) {
	auto self = addresser::thunkAdjust(Resolve<GJBaseGameLayer*>::func(&EffectGameObject::getSaveString), this);
	using FunctionType = decltype(getSaveString(layer))(*)(EffectGameObject*, GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x14f4f8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, layer);
}

auto EffectGameObject::setRScaleX(float scaleX) -> decltype(setRScaleX(scaleX)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&EffectGameObject::setRScaleX), this);
	using FunctionType = decltype(setRScaleX(scaleX))(*)(EffectGameObject*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1729e4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, scaleX);
}

auto EffectGameObject::setRScaleY(float scaleY) -> decltype(setRScaleY(scaleY)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&EffectGameObject::setRScaleY), this);
	using FunctionType = decltype(setRScaleY(scaleY))(*)(EffectGameObject*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1729f4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, scaleY);
}

auto EffectGameObject::triggerActivated(float xPosition) -> decltype(triggerActivated(xPosition)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&EffectGameObject::triggerActivated), this);
	using FunctionType = decltype(triggerActivated(xPosition))(*)(EffectGameObject*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1741fc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, xPosition);
}

auto EffectGameObject::restoreObject() -> decltype(restoreObject()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&EffectGameObject::restoreObject), this);
	using FunctionType = decltype(restoreObject())(*)(EffectGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x173fb8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto EffectGameObject::spawnXPosition() -> decltype(spawnXPosition()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&EffectGameObject::spawnXPosition), this);
	using FunctionType = decltype(spawnXPosition())(*)(EffectGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1741b8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto EffectGameObject::canReverse() -> decltype(canReverse()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&EffectGameObject::canReverse), this);
	using FunctionType = decltype(canReverse())(*)(EffectGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1744c8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto EffectGameObject::isSpecialSpawnObject() -> decltype(isSpecialSpawnObject()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&EffectGameObject::isSpecialSpawnObject), this);
	using FunctionType = decltype(isSpecialSpawnObject())(*)(EffectGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x174554, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto EffectGameObject::canBeOrdered() -> decltype(canBeOrdered()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&EffectGameObject::canBeOrdered), this);
	using FunctionType = decltype(canBeOrdered())(*)(EffectGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1746f4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto EffectGameObject::getObjectLabel() -> decltype(getObjectLabel()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&EffectGameObject::getObjectLabel), this);
	using FunctionType = decltype(getObjectLabel())(*)(EffectGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1a1f90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto EffectGameObject::setObjectLabel(cocos2d::CCLabelBMFont* label) -> decltype(setObjectLabel(label)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCLabelBMFont*>::func(&EffectGameObject::setObjectLabel), this);
	using FunctionType = decltype(setObjectLabel(label))(*)(EffectGameObject*, cocos2d::CCLabelBMFont*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1a1f98, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, label);
}

auto EffectGameObject::stateSensitiveOff(GJBaseGameLayer* layer) -> decltype(stateSensitiveOff(layer)) {
	auto self = addresser::thunkAdjust(Resolve<GJBaseGameLayer*>::func(&EffectGameObject::stateSensitiveOff), this);
	using FunctionType = decltype(stateSensitiveOff(layer))(*)(EffectGameObject*, GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x173f2c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, layer);
}

auto EffectGameObject::canSpawnTriggers() -> decltype(canSpawnTriggers()) {
	using FunctionType = decltype(canSpawnTriggers())(*)(EffectGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x17429c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto EffectGameObject::getTargetColorIndex() -> decltype(getTargetColorIndex()) {
	using FunctionType = decltype(getTargetColorIndex())(*)(EffectGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x173fcc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto EffectGameObject::hasSpawnTargetID(int id) -> decltype(hasSpawnTargetID(id)) {
	using FunctionType = decltype(hasSpawnTargetID(id))(*)(EffectGameObject*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x17455c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto EffectGameObject::init(char const* frame) -> decltype(init(frame)) {
	using FunctionType = decltype(init(frame))(*)(EffectGameObject*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x149850, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, frame);
}

auto EffectGameObject::playTriggerEffect() -> decltype(playTriggerEffect()) {
	using FunctionType = decltype(playTriggerEffect())(*)(EffectGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x172a04, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto EffectGameObject::resetSpawnTrigger() -> decltype(resetSpawnTrigger()) {
	using FunctionType = decltype(resetSpawnTrigger())(*)(EffectGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x17423c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto EffectGameObject::setTargetID(int id) -> decltype(setTargetID(id)) {
	using FunctionType = decltype(setTargetID(id))(*)(EffectGameObject*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x160968, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto EffectGameObject::setTargetID2(int id) -> decltype(setTargetID2(id)) {
	using FunctionType = decltype(setTargetID2(id))(*)(EffectGameObject*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x160980, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto EffectGameObject::triggerEffectFinished() -> decltype(triggerEffectFinished()) {
	using FunctionType = decltype(triggerEffectFinished())(*)(EffectGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x172d18, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto EffectGameObject::updateInteractiveHover(float offset) -> decltype(updateInteractiveHover(offset)) {
	using FunctionType = decltype(updateInteractiveHover(offset))(*)(EffectGameObject*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1740b8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, offset);
}

auto EffectGameObject::updateSpecialColor() -> decltype(updateSpecialColor()) {
	using FunctionType = decltype(updateSpecialColor())(*)(EffectGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x174040, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto EffectGameObject::updateSpeedModType() -> decltype(updateSpeedModType()) {
	using FunctionType = decltype(updateSpeedModType())(*)(EffectGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x174364, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
