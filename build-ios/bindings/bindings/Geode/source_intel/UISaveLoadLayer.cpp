
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/UISaveLoadLayer.hpp>
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

auto UISaveLoadLayer::create(UIOptionsLayer* layer) -> decltype(create(layer)) {
	using FunctionType = decltype(create(layer))(*)(UIOptionsLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2b4430, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(layer);
}

auto UISaveLoadLayer::init(UIOptionsLayer* layer) -> decltype(init(layer)) {
	using FunctionType = decltype(init(layer))(*)(UISaveLoadLayer*, UIOptionsLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2b51c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, layer);
}

auto UISaveLoadLayer::onLoad(cocos2d::CCObject* sender) -> decltype(onLoad(sender)) {
	using FunctionType = decltype(onLoad(sender))(*)(UISaveLoadLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2b5ad0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto UISaveLoadLayer::onSave(cocos2d::CCObject* sender) -> decltype(onSave(sender)) {
	using FunctionType = decltype(onSave(sender))(*)(UISaveLoadLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2b58a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}
