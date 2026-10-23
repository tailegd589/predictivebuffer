
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GJSmartBlockPreview.hpp>
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

auto GJSmartBlockPreview::create(gd::string key) -> decltype(create(key)) {
	using FunctionType = decltype(create(key))(*)(gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39b134, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(key);
}

auto GJSmartBlockPreview::addChance(int count, int total) -> decltype(addChance(count, total)) {
	using FunctionType = decltype(addChance(count, total))(*)(GJSmartBlockPreview*, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39becc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, count, total);
}

auto GJSmartBlockPreview::addCount(int count) -> decltype(addCount(count)) {
	using FunctionType = decltype(addCount(count))(*)(GJSmartBlockPreview*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39bdf4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, count);
}

auto GJSmartBlockPreview::addPreview(gd::string key, gd::string data, LevelEditorLayer* layer) -> decltype(addPreview(key, data, layer)) {
	using FunctionType = decltype(addPreview(key, data, layer))(*)(GJSmartBlockPreview*, gd::string, gd::string, LevelEditorLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39bc14, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key, data, layer);
}

auto GJSmartBlockPreview::addTemplateGuide(SmartPrefabResult result, float opacity) -> decltype(addTemplateGuide(result, opacity)) {
	using FunctionType = decltype(addTemplateGuide(result, opacity))(*)(GJSmartBlockPreview*, SmartPrefabResult, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39b5f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, result, opacity);
}

auto GJSmartBlockPreview::addTemplateGuide(gd::string key, int type) -> decltype(addTemplateGuide(key, type)) {
	using FunctionType = decltype(addTemplateGuide(key, type))(*)(GJSmartBlockPreview*, gd::string, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39b2e4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key, type);
}

auto GJSmartBlockPreview::createInfoLabel() -> decltype(createInfoLabel()) {
	using FunctionType = decltype(createInfoLabel())(*)(GJSmartBlockPreview*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39bda0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJSmartBlockPreview::init(gd::string key) -> decltype(init(key)) {
	using FunctionType = decltype(init(key))(*)(GJSmartBlockPreview*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39b270, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, key);
}

auto GJSmartBlockPreview::toggleSelectItem(bool selected) -> decltype(toggleSelectItem(selected)) {
	using FunctionType = decltype(toggleSelectItem(selected))(*)(GJSmartBlockPreview*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x39c088, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, selected);
}
