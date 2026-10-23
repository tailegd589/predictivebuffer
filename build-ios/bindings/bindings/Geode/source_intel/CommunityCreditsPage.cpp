
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/CommunityCreditsPage.hpp>
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

CommunityCreditsPage::~CommunityCreditsPage() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(CommunityCreditsPage*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x31e5d0, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) CommunityCreditsPage(geode::CutoffConstructor, sizeof(CommunityCreditsPage));
		geode::DestructorLock::addLock(this);
	}
}

auto CommunityCreditsPage::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x31e900, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto CommunityCreditsPage::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CommunityCreditsPage::init), this);
	using FunctionType = decltype(init())(*)(CommunityCreditsPage*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x31ea50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CommunityCreditsPage::registerWithTouchDispatcher() -> decltype(registerWithTouchDispatcher()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CommunityCreditsPage::registerWithTouchDispatcher), this);
	using FunctionType = decltype(registerWithTouchDispatcher())(*)(CommunityCreditsPage*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x320fb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CommunityCreditsPage::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CommunityCreditsPage::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(CommunityCreditsPage*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x320f40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CommunityCreditsPage::show() -> decltype(show()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CommunityCreditsPage::show), this);
	using FunctionType = decltype(show())(*)(CommunityCreditsPage*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x320db0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CommunityCreditsPage::FLAlert_Clicked(FLAlertLayer* alert, bool btn2) -> decltype(FLAlert_Clicked(alert, btn2)) {
	using FunctionType = decltype(FLAlert_Clicked(alert, btn2))(*)(CommunityCreditsPage*, FLAlertLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x320f30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, alert, btn2);
}

auto CommunityCreditsPage::goToPage(int page) -> decltype(goToPage(page)) {
	using FunctionType = decltype(goToPage(page))(*)(CommunityCreditsPage*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x320ca0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, page);
}

auto CommunityCreditsPage::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	using FunctionType = decltype(onClose(sender))(*)(CommunityCreditsPage*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x320c30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto CommunityCreditsPage::onSwitchPage(cocos2d::CCObject* sender) -> decltype(onSwitchPage(sender)) {
	using FunctionType = decltype(onSwitchPage(sender))(*)(CommunityCreditsPage*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x320c60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}
