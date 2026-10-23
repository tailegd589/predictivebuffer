
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GManager.hpp>
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

auto GManager::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GManager::init), this);
	using FunctionType = decltype(init())(*)(GManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40ecbc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GManager::setup() -> decltype(setup()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GManager::setup), this);
	using FunctionType = decltype(setup())(*)(GManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40eccc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GManager::encodeDataTo(DS_Dictionary* dict) -> decltype(encodeDataTo(dict)) {
	auto self = addresser::thunkAdjust(Resolve<DS_Dictionary*>::func(&GManager::encodeDataTo), this);
	using FunctionType = decltype(encodeDataTo(dict))(*)(GManager*, DS_Dictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40f1c8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, dict);
}

auto GManager::dataLoaded(DS_Dictionary* dict) -> decltype(dataLoaded(dict)) {
	auto self = addresser::thunkAdjust(Resolve<DS_Dictionary*>::func(&GManager::dataLoaded), this);
	using FunctionType = decltype(dataLoaded(dict))(*)(GManager*, DS_Dictionary*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40f870, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, dict);
}

auto GManager::firstLoad() -> decltype(firstLoad()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GManager::firstLoad), this);
	using FunctionType = decltype(firstLoad())(*)(GManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40f874, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GManager::getCompressedSaveString() -> decltype(getCompressedSaveString()) {
	using FunctionType = decltype(getCompressedSaveString())(*)(GManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40ed68, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GManager::getSaveString() -> decltype(getSaveString()) {
	using FunctionType = decltype(getSaveString())(*)(GManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40ece4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GManager::load() -> decltype(load()) {
	using FunctionType = decltype(load())(*)(GManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40ecdc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GManager::loadDataFromFile(gd::string const& filename) -> decltype(loadDataFromFile(filename)) {
	using FunctionType = decltype(loadDataFromFile(filename))(*)(GManager*, gd::string const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40f1cc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, filename);
}

auto GManager::loadFromCompressedString(gd::string& str) -> decltype(loadFromCompressedString(str)) {
	using FunctionType = decltype(loadFromCompressedString(str))(*)(GManager*, gd::string&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40ee90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, str);
}

auto GManager::loadFromString(gd::string& str) -> decltype(loadFromString(str)) {
	using FunctionType = decltype(loadFromString(str))(*)(GManager*, gd::string&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40ede4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, str);
}

auto GManager::save() -> decltype(save()) {
	using FunctionType = decltype(save())(*)(GManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40ef34, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GManager::saveData(DS_Dictionary* dict, gd::string filename) -> decltype(saveData(dict, filename)) {
	using FunctionType = decltype(saveData(dict, filename))(*)(GManager*, DS_Dictionary*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40f13c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dict, filename);
}

auto GManager::saveGMTo(gd::string filename) -> decltype(saveGMTo(filename)) {
	using FunctionType = decltype(saveGMTo(filename))(*)(GManager*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40efd8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, filename);
}

auto GManager::tryLoadData(DS_Dictionary* dict, gd::string const& filename) -> decltype(tryLoadData(dict, filename)) {
	using FunctionType = decltype(tryLoadData(dict, filename))(*)(GManager*, DS_Dictionary*, gd::string const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40f488, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dict, filename);
}
