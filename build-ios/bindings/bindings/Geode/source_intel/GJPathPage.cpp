
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GJPathPage.hpp>
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

auto GJPathPage::create(int path, GJPathsLayer* layer) -> decltype(create(path, layer)) {
	using FunctionType = decltype(create(path, layer))(*)(int, GJPathsLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2feb40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(path, layer);
}

auto GJPathPage::registerWithTouchDispatcher() -> decltype(registerWithTouchDispatcher()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJPathPage::registerWithTouchDispatcher), this);
	using FunctionType = decltype(registerWithTouchDispatcher())(*)(GJPathPage*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x302bb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJPathPage::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJPathPage::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(GJPathPage*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x302a70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJPathPage::show() -> decltype(show()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJPathPage::show), this);
	using FunctionType = decltype(show())(*)(GJPathPage*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x302bf0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJPathPage::didPurchaseItem(GJStoreItem* item) -> decltype(didPurchaseItem(item)) {
	auto self = addresser::thunkAdjust(Resolve<GJStoreItem*>::func(&GJPathPage::didPurchaseItem), this);
	using FunctionType = decltype(didPurchaseItem(item))(*)(GJPathPage*, GJStoreItem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x300ea0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, item);
}

auto GJPathPage::init(int path, GJPathsLayer* layer) -> decltype(init(path, layer)) {
	using FunctionType = decltype(init(path, layer))(*)(GJPathPage*, int, GJPathsLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2ff120, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, path, layer);
}

auto GJPathPage::onActivatePath(cocos2d::CCObject* sender) -> decltype(onActivatePath(sender)) {
	using FunctionType = decltype(onActivatePath(sender))(*)(GJPathPage*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x300e70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto GJPathPage::onBack(cocos2d::CCObject* sender) -> decltype(onBack(sender)) {
	using FunctionType = decltype(onBack(sender))(*)(GJPathPage*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x300b40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto GJPathPage::onIconInfo(cocos2d::CCObject* sender) -> decltype(onIconInfo(sender)) {
	using FunctionType = decltype(onIconInfo(sender))(*)(GJPathPage*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x300bd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto GJPathPage::onUnlock(cocos2d::CCObject* sender) -> decltype(onUnlock(sender)) {
	using FunctionType = decltype(onUnlock(sender))(*)(GJPathPage*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x300d80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto GJPathPage::playUnlockAnimation() -> decltype(playUnlockAnimation()) {
	using FunctionType = decltype(playUnlockAnimation())(*)(GJPathPage*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x300eb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJPathPage::showCantAffordMessage(GJStoreItem* item) -> decltype(showCantAffordMessage(item)) {
	using FunctionType = decltype(showCantAffordMessage(item))(*)(GJPathPage*, GJStoreItem*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x301560, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, item);
}

auto GJPathPage::unlockAnimationFinished() -> decltype(unlockAnimationFinished()) {
	using FunctionType = decltype(unlockAnimationFinished())(*)(GJPathPage*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x301ef0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJPathPage::unlockAnimationStep2() -> decltype(unlockAnimationStep2()) {
	using FunctionType = decltype(unlockAnimationStep2())(*)(GJPathPage*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x301c00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJPathPage::unlockAnimationStep3() -> decltype(unlockAnimationStep3()) {
	using FunctionType = decltype(unlockAnimationStep3())(*)(GJPathPage*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x302050, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
