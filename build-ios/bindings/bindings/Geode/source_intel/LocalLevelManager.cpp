
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/LocalLevelManager.hpp>
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

auto LocalLevelManager::sharedState() -> decltype(sharedState()) {
	using FunctionType = decltype(sharedState())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f6810, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto LocalLevelManager::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&LocalLevelManager::init), this);
	using FunctionType = decltype(init())(*)(LocalLevelManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f69b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto LocalLevelManager::encodeDataTo(DS_Dictionary* dict) -> decltype(encodeDataTo(dict)) {
	auto self = addresser::thunkAdjust(Resolve<DS_Dictionary*>::func(&LocalLevelManager::encodeDataTo), this);
	using FunctionType = decltype(encodeDataTo(dict))(*)(LocalLevelManager*, DS_Dictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f7df0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, dict);
}

auto LocalLevelManager::dataLoaded(DS_Dictionary* dict) -> decltype(dataLoaded(dict)) {
	auto self = addresser::thunkAdjust(Resolve<DS_Dictionary*>::func(&LocalLevelManager::dataLoaded), this);
	using FunctionType = decltype(dataLoaded(dict))(*)(LocalLevelManager*, DS_Dictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f7e50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, dict);
}

auto LocalLevelManager::firstLoad() -> decltype(firstLoad()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&LocalLevelManager::firstLoad), this);
	using FunctionType = decltype(firstLoad())(*)(LocalLevelManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f7d60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto LocalLevelManager::getAllLevelsInDict() -> decltype(getAllLevelsInDict()) {
	using FunctionType = decltype(getAllLevelsInDict())(*)(LocalLevelManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f7180, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LocalLevelManager::getAllLevelsWithName(gd::string name) -> decltype(getAllLevelsWithName(name)) {
	using FunctionType = decltype(getAllLevelsWithName(name))(*)(LocalLevelManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f73b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, name);
}

auto LocalLevelManager::getCreatedLevels(int folder) -> decltype(getCreatedLevels(folder)) {
	using FunctionType = decltype(getCreatedLevels(folder))(*)(LocalLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f7b70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, folder);
}

auto LocalLevelManager::getCreatedLists(int folder) -> decltype(getCreatedLists(folder)) {
	using FunctionType = decltype(getCreatedLists(folder))(*)(LocalLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f7cd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, folder);
}

auto LocalLevelManager::getLevelsInNameGroups() -> decltype(getLevelsInNameGroups()) {
	using FunctionType = decltype(getLevelsInNameGroups())(*)(LocalLevelManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f7000, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LocalLevelManager::getMainLevelString(int id) -> decltype(getMainLevelString(id)) {
	using FunctionType = decltype(getMainLevelString(id))(*)(LocalLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f6e00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto LocalLevelManager::markLevelsAsUnmodified() -> decltype(markLevelsAsUnmodified()) {
	using FunctionType = decltype(markLevelsAsUnmodified())(*)(LocalLevelManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f7ad0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LocalLevelManager::moveLevelToTop(GJGameLevel* level) -> decltype(moveLevelToTop(level)) {
	using FunctionType = decltype(moveLevelToTop(level))(*)(LocalLevelManager*, GJGameLevel*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f7980, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, level);
}

auto LocalLevelManager::reorderLevels() -> decltype(reorderLevels()) {
	using FunctionType = decltype(reorderLevels())(*)(LocalLevelManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f7b20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LocalLevelManager::reorderLists() -> decltype(reorderLists()) {
	using FunctionType = decltype(reorderLists())(*)(LocalLevelManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f7c80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LocalLevelManager::tryLoadMainLevelString(int id) -> decltype(tryLoadMainLevelString(id)) {
	using FunctionType = decltype(tryLoadMainLevelString(id))(*)(LocalLevelManager*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f69f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id);
}

auto LocalLevelManager::updateLevelOrder() -> decltype(updateLevelOrder()) {
	using FunctionType = decltype(updateLevelOrder())(*)(LocalLevelManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f7a50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LocalLevelManager::updateLevelRevision() -> decltype(updateLevelRevision()) {
	using FunctionType = decltype(updateLevelRevision())(*)(LocalLevelManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f7510, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto LocalLevelManager::updateListOrder() -> decltype(updateListOrder()) {
	using FunctionType = decltype(updateListOrder())(*)(LocalLevelManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5f7c00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
