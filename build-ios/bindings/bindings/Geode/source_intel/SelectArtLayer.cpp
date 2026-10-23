
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/SelectArtLayer.hpp>
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

auto SelectArtLayer::create(SelectArtType type, int index) -> decltype(create(type, index)) {
	using FunctionType = decltype(create(type, index))(*)(SelectArtType, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26f170, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(type, index);
}

auto SelectArtLayer::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&SelectArtLayer::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(SelectArtLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2705b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto SelectArtLayer::init(SelectArtType type, int index) -> decltype(init(type, index)) {
	using FunctionType = decltype(init(type, index))(*)(SelectArtLayer*, SelectArtType, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26f9a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, type, index);
}

auto SelectArtLayer::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	using FunctionType = decltype(onClose(sender))(*)(SelectArtLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2704a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SelectArtLayer::onSelectCustom(cocos2d::CCObject* sender) -> decltype(onSelectCustom(sender)) {
	using FunctionType = decltype(onSelectCustom(sender))(*)(SelectArtLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2704f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SelectArtLayer::selectArt(cocos2d::CCObject* sender) -> decltype(selectArt(sender)) {
	using FunctionType = decltype(selectArt(sender))(*)(SelectArtLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2703d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SelectArtLayer::updateSelectedCustom(int idx) -> decltype(updateSelectedCustom(idx)) {
	using FunctionType = decltype(updateSelectedCustom(idx))(*)(SelectArtLayer*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26f2e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, idx);
}
