
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GJPromoPopup.hpp>
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

auto GJPromoPopup::create(gd::string filename) -> decltype(create(filename)) {
	using FunctionType = decltype(create(filename))(*)(gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x253cd8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(filename);
}

auto GJPromoPopup::onExit() -> decltype(onExit()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJPromoPopup::onExit), this);
	using FunctionType = decltype(onExit())(*)(GJPromoPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2540f4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJPromoPopup::registerWithTouchDispatcher() -> decltype(registerWithTouchDispatcher()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJPromoPopup::registerWithTouchDispatcher), this);
	using FunctionType = decltype(registerWithTouchDispatcher())(*)(GJPromoPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x254204, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJPromoPopup::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJPromoPopup::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(GJPromoPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x254134, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJPromoPopup::show() -> decltype(show()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJPromoPopup::show), this);
	using FunctionType = decltype(show())(*)(GJPromoPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x25423c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJPromoPopup::init(gd::string filename) -> decltype(init(filename)) {
	using FunctionType = decltype(init(filename))(*)(GJPromoPopup*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x253e48, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, filename);
}

auto GJPromoPopup::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	using FunctionType = decltype(onClose(sender))(*)(GJPromoPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x25408c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}
