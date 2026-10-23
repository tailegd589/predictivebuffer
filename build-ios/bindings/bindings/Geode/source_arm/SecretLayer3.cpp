
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/SecretLayer3.hpp>
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

SecretLayer3::~SecretLayer3() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(SecretLayer3*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x406eb4, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) SecretLayer3(geode::CutoffConstructor, sizeof(SecretLayer3));
		geode::DestructorLock::addLock(this);
	}
}

auto SecretLayer3::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4070b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto SecretLayer3::scene() -> decltype(scene()) {
	using FunctionType = decltype(scene())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x404920, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto SecretLayer3::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&SecretLayer3::init), this);
	using FunctionType = decltype(init())(*)(SecretLayer3*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x407168, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto SecretLayer3::onExit() -> decltype(onExit()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&SecretLayer3::onExit), this);
	using FunctionType = decltype(onExit())(*)(SecretLayer3*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40bb8c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto SecretLayer3::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&SecretLayer3::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(SecretLayer3*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40bb80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto SecretLayer3::dialogClosed(DialogLayer* layer) -> decltype(dialogClosed(layer)) {
	auto self = addresser::thunkAdjust(Resolve<DialogLayer*>::func(&SecretLayer3::dialogClosed), this);
	using FunctionType = decltype(dialogClosed(layer))(*)(SecretLayer3*, DialogLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40b848, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, layer);
}

auto SecretLayer3::animateEyes() -> decltype(animateEyes()) {
	using FunctionType = decltype(animateEyes())(*)(SecretLayer3*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4087e8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SecretLayer3::firstInteractionStep1() -> decltype(firstInteractionStep1()) {
	using FunctionType = decltype(firstInteractionStep1())(*)(SecretLayer3*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x409924, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SecretLayer3::firstInteractionStep2() -> decltype(firstInteractionStep2()) {
	using FunctionType = decltype(firstInteractionStep2())(*)(SecretLayer3*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4099e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SecretLayer3::firstInteractionStep3() -> decltype(firstInteractionStep3()) {
	using FunctionType = decltype(firstInteractionStep3())(*)(SecretLayer3*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x409db8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SecretLayer3::firstInteractionStep4() -> decltype(firstInteractionStep4()) {
	using FunctionType = decltype(firstInteractionStep4())(*)(SecretLayer3*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x409f28, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SecretLayer3::onBack(cocos2d::CCObject* sender) -> decltype(onBack(sender)) {
	using FunctionType = decltype(onBack(sender))(*)(SecretLayer3*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4097d4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SecretLayer3::onChest01(cocos2d::CCObject* sender) -> decltype(onChest01(sender)) {
	using FunctionType = decltype(onChest01(sender))(*)(SecretLayer3*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4095fc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SecretLayer3::onChest02(cocos2d::CCObject* sender) -> decltype(onChest02(sender)) {
	using FunctionType = decltype(onChest02(sender))(*)(SecretLayer3*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4096e8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SecretLayer3::onClick(cocos2d::CCObject* sender) -> decltype(onClick(sender)) {
	using FunctionType = decltype(onClick(sender))(*)(SecretLayer3*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4088dc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SecretLayer3::revealStep1() -> decltype(revealStep1()) {
	using FunctionType = decltype(revealStep1())(*)(SecretLayer3*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40a2ec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SecretLayer3::revealStep2() -> decltype(revealStep2()) {
	using FunctionType = decltype(revealStep2())(*)(SecretLayer3*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40a8c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SecretLayer3::revealStep3() -> decltype(revealStep3()) {
	using FunctionType = decltype(revealStep3())(*)(SecretLayer3*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40abc8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SecretLayer3::revealStep4() -> decltype(revealStep4()) {
	using FunctionType = decltype(revealStep4())(*)(SecretLayer3*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40ac64, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SecretLayer3::revealStep5() -> decltype(revealStep5()) {
	using FunctionType = decltype(revealStep5())(*)(SecretLayer3*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40b390, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SecretLayer3::showUnlockDialog() -> decltype(showUnlockDialog()) {
	using FunctionType = decltype(showUnlockDialog())(*)(SecretLayer3*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x40a354, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
