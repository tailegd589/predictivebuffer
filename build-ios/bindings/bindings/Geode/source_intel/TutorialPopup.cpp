
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/TutorialPopup.hpp>
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

auto TutorialPopup::create(gd::string frame) -> decltype(create(frame)) {
	using FunctionType = decltype(create(frame))(*)(gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5d41d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(frame);
}

auto TutorialPopup::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&TutorialPopup::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(TutorialPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5d45e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto TutorialPopup::show() -> decltype(show()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&TutorialPopup::show), this);
	using FunctionType = decltype(show())(*)(TutorialPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5d46b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto TutorialPopup::animateMenu() -> decltype(animateMenu()) {
	using FunctionType = decltype(animateMenu())(*)(TutorialPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5d4700, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto TutorialPopup::closeTutorial(cocos2d::CCObject* sender) -> decltype(closeTutorial(sender)) {
	using FunctionType = decltype(closeTutorial(sender))(*)(TutorialPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5d4580, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto TutorialPopup::init(gd::string frame) -> decltype(init(frame)) {
	using FunctionType = decltype(init(frame))(*)(TutorialPopup*, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5d4380, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, frame);
}

auto TutorialPopup::registerForCallback(cocos2d::SEL_MenuHandler selector, cocos2d::CCNode* target) -> decltype(registerForCallback(selector, target)) {
	using FunctionType = decltype(registerForCallback(selector, target))(*)(TutorialPopup*, cocos2d::SEL_MenuHandler, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5d4770, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, selector, target);
}
