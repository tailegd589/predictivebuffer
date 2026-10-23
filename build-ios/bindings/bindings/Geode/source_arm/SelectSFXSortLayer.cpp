
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/SelectSFXSortLayer.hpp>
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

auto SelectSFXSortLayer::create(AudioSortType sortType) -> decltype(create(sortType)) {
	using FunctionType = decltype(create(sortType))(*)(AudioSortType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3b1f00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(sortType);
}

auto SelectSFXSortLayer::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&SelectSFXSortLayer::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(SelectSFXSortLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3b2d58, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto SelectSFXSortLayer::init(AudioSortType sortType) -> decltype(init(sortType)) {
	using FunctionType = decltype(init(sortType))(*)(SelectSFXSortLayer*, AudioSortType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3b2838, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sortType);
}

auto SelectSFXSortLayer::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	using FunctionType = decltype(onClose(sender))(*)(SelectSFXSortLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3b2cb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SelectSFXSortLayer::onSelect(cocos2d::CCObject* sender) -> decltype(onSelect(sender)) {
	using FunctionType = decltype(onSelect(sender))(*)(SelectSFXSortLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3b2cec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}
