
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/FileSaveManager.hpp>
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

auto FileSaveManager::sharedState() -> decltype(sharedState()) {
	using FunctionType = decltype(sharedState())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x61b4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto FileSaveManager::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&FileSaveManager::init), this);
	using FunctionType = decltype(init())(*)(FileSaveManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x623c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto FileSaveManager::firstLoad() -> decltype(firstLoad()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&FileSaveManager::firstLoad), this);
	using FunctionType = decltype(firstLoad())(*)(FileSaveManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x626c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto FileSaveManager::getStoreData() -> decltype(getStoreData()) {
	using FunctionType = decltype(getStoreData())(*)(FileSaveManager*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6734, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto FileSaveManager::loadDataFromFile(char const* filename) -> decltype(loadDataFromFile(filename)) {
	using FunctionType = decltype(loadDataFromFile(filename))(*)(FileSaveManager*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6260, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, filename);
}
