
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/UploadActionPopup.hpp>
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

auto UploadActionPopup::create(UploadPopupDelegate* delegate, gd::string str) -> decltype(create(delegate, str)) {
	using FunctionType = decltype(create(delegate, str))(*)(UploadPopupDelegate*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a3fc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(delegate, str);
}

auto UploadActionPopup::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&UploadActionPopup::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(UploadActionPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a48f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto UploadActionPopup::closePopup() -> decltype(closePopup()) {
	using FunctionType = decltype(closePopup())(*)(UploadActionPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a48c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto UploadActionPopup::init(UploadPopupDelegate* delegate, gd::string str) -> decltype(init(delegate, str)) {
	using FunctionType = decltype(init(delegate, str))(*)(UploadActionPopup*, UploadPopupDelegate*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a4160, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, delegate, str);
}

auto UploadActionPopup::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	using FunctionType = decltype(onClose(sender))(*)(UploadActionPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a45b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto UploadActionPopup::showFailMessage(gd::string message) -> decltype(showFailMessage(message)) {
	using FunctionType = decltype(showFailMessage(message))(*)(UploadActionPopup*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a4770, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, message);
}

auto UploadActionPopup::showSuccessMessage(gd::string message) -> decltype(showSuccessMessage(message)) {
	using FunctionType = decltype(showSuccessMessage(message))(*)(UploadActionPopup*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2a4600, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, message);
}
