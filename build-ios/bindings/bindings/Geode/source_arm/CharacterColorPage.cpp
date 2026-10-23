
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/CharacterColorPage.hpp>
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

CharacterColorPage::~CharacterColorPage() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(CharacterColorPage*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x57c6c4, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) CharacterColorPage(geode::CutoffConstructor, sizeof(CharacterColorPage));
		geode::DestructorLock::addLock(this);
	}
}

auto CharacterColorPage::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x57c78c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto CharacterColorPage::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CharacterColorPage::init), this);
	using FunctionType = decltype(init())(*)(CharacterColorPage*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x57c894, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CharacterColorPage::registerWithTouchDispatcher() -> decltype(registerWithTouchDispatcher()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CharacterColorPage::registerWithTouchDispatcher), this);
	using FunctionType = decltype(registerWithTouchDispatcher())(*)(CharacterColorPage*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x57e748, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CharacterColorPage::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CharacterColorPage::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(CharacterColorPage*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x57e69c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CharacterColorPage::show() -> decltype(show()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&CharacterColorPage::show), this);
	using FunctionType = decltype(show())(*)(CharacterColorPage*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x57e510, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto CharacterColorPage::activeColorForMode(int mode) -> decltype(activeColorForMode(mode)) {
	using FunctionType = decltype(activeColorForMode(mode))(*)(CharacterColorPage*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x57e438, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, mode);
}

auto CharacterColorPage::checkColor(int id, UnlockType type) -> decltype(checkColor(id, type)) {
	using FunctionType = decltype(checkColor(id, type))(*)(CharacterColorPage*, int, UnlockType);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x57e4a8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, type);
}

auto CharacterColorPage::colorForIndex(int index) -> decltype(colorForIndex(index)) {
	using FunctionType = decltype(colorForIndex(index))(*)(CharacterColorPage*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x57e188, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index);
}

auto CharacterColorPage::createColorMenu() -> decltype(createColorMenu()) {
	using FunctionType = decltype(createColorMenu())(*)(CharacterColorPage*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x57d898, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto CharacterColorPage::FLAlert_Clicked(FLAlertLayer* layer, bool btn2) -> decltype(FLAlert_Clicked(layer, btn2)) {
	using FunctionType = decltype(FLAlert_Clicked(layer, btn2))(*)(CharacterColorPage*, FLAlertLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x57e698, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, layer, btn2);
}

auto CharacterColorPage::offsetForIndex(int index) -> decltype(offsetForIndex(index)) {
	using FunctionType = decltype(offsetForIndex(index))(*)(CharacterColorPage*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x57e3e4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, index);
}

auto CharacterColorPage::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	using FunctionType = decltype(onClose(sender))(*)(CharacterColorPage*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x57d450, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto CharacterColorPage::onMode(cocos2d::CCObject* sender) -> decltype(onMode(sender)) {
	using FunctionType = decltype(onMode(sender))(*)(CharacterColorPage*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x57d56c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto CharacterColorPage::onPlayerColor(cocos2d::CCObject* sender) -> decltype(onPlayerColor(sender)) {
	using FunctionType = decltype(onPlayerColor(sender))(*)(CharacterColorPage*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x57e1a8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto CharacterColorPage::toggleGlow(cocos2d::CCObject* sender) -> decltype(toggleGlow(sender)) {
	using FunctionType = decltype(toggleGlow(sender))(*)(CharacterColorPage*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x57dc70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto CharacterColorPage::toggleGlowItems(bool visible) -> decltype(toggleGlowItems(visible)) {
	using FunctionType = decltype(toggleGlowItems(visible))(*)(CharacterColorPage*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x57e134, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, visible);
}

auto CharacterColorPage::toggleShip(cocos2d::CCObject* sender) -> decltype(toggleShip(sender)) {
	using FunctionType = decltype(toggleShip(sender))(*)(CharacterColorPage*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x57d4a4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto CharacterColorPage::updateColorMode(int mode) -> decltype(updateColorMode(mode)) {
	using FunctionType = decltype(updateColorMode(mode))(*)(CharacterColorPage*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x57dca8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, mode);
}

auto CharacterColorPage::updateIconColors() -> decltype(updateIconColors()) {
	using FunctionType = decltype(updateIconColors())(*)(CharacterColorPage*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x57d758, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
