
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/SpawnTriggerGameObject.hpp>
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

auto SpawnTriggerGameObject::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1d2d30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto SpawnTriggerGameObject::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&SpawnTriggerGameObject::init), this);
	using FunctionType = decltype(init())(*)(SpawnTriggerGameObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1d2e10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto SpawnTriggerGameObject::triggerObject(GJBaseGameLayer* layer, int uniqueID, gd::vector<int> const* remapKeys) -> decltype(triggerObject(layer, uniqueID, remapKeys)) {
	auto self = addresser::thunkAdjust(Resolve<GJBaseGameLayer*, int, gd::vector<int> const*>::func(&SpawnTriggerGameObject::triggerObject), this);
	using FunctionType = decltype(triggerObject(layer, uniqueID, remapKeys))(*)(SpawnTriggerGameObject*, GJBaseGameLayer*, int, gd::vector<int> const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1d3100, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, layer, uniqueID, remapKeys);
}

auto SpawnTriggerGameObject::customObjectSetup(gd::vector<gd::string>& values, gd::vector<void*>& exists) -> decltype(customObjectSetup(values, exists)) {
	auto self = addresser::thunkAdjust(Resolve<gd::vector<gd::string>&, gd::vector<void*>&>::func(&SpawnTriggerGameObject::customObjectSetup), this);
	using FunctionType = decltype(customObjectSetup(values, exists))(*)(SpawnTriggerGameObject*, gd::vector<gd::string>&, gd::vector<void*>&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1d3640, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, values, exists);
}

auto SpawnTriggerGameObject::getSaveString(GJBaseGameLayer* layer) -> decltype(getSaveString(layer)) {
	auto self = addresser::thunkAdjust(Resolve<GJBaseGameLayer*>::func(&SpawnTriggerGameObject::getSaveString), this);
	using FunctionType = decltype(getSaveString(layer))(*)(SpawnTriggerGameObject*, GJBaseGameLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1d3a70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, layer);
}

auto SpawnTriggerGameObject::addRemap(int oldID, int newID) -> decltype(addRemap(oldID, newID)) {
	using FunctionType = decltype(addRemap(oldID, newID))(*)(SpawnTriggerGameObject*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1d3240, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, oldID, newID);
}

auto SpawnTriggerGameObject::changeRemap(int oldID, int newID, bool reverse) -> decltype(changeRemap(oldID, newID, reverse)) {
	using FunctionType = decltype(changeRemap(oldID, newID, reverse))(*)(SpawnTriggerGameObject*, int, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1d3450, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, oldID, newID, reverse);
}

auto SpawnTriggerGameObject::getRemapWithSource(int id) -> decltype(getRemapWithSource(id)) {
	using FunctionType = decltype(getRemapWithSource(id))(*)(SpawnTriggerGameObject*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1d31c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto SpawnTriggerGameObject::getRemapWithTarget(int id) -> decltype(getRemapWithTarget(id)) {
	using FunctionType = decltype(getRemapWithTarget(id))(*)(SpawnTriggerGameObject*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1d3200, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto SpawnTriggerGameObject::removeRemap(int oldID, int newID) -> decltype(removeRemap(oldID, newID)) {
	using FunctionType = decltype(removeRemap(oldID, newID))(*)(SpawnTriggerGameObject*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1d33c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, oldID, newID);
}

auto SpawnTriggerGameObject::updateRemapKeys(gd::vector<int> const& remapKeys) -> decltype(updateRemapKeys(remapKeys)) {
	using FunctionType = decltype(updateRemapKeys(remapKeys))(*)(SpawnTriggerGameObject*, gd::vector<int> const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1d2e60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, remapKeys);
}
