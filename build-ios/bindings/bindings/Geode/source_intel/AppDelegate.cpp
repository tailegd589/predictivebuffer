
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/AppDelegate.hpp>
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

auto AppDelegate::get() -> decltype(get()) {
	using FunctionType = decltype(get())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x65c240, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto AppDelegate::applicationDidFinishLaunching() -> decltype(applicationDidFinishLaunching()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&AppDelegate::applicationDidFinishLaunching), this);
	using FunctionType = decltype(applicationDidFinishLaunching())(*)(AppDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x65c0c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto AppDelegate::applicationDidEnterBackground() -> decltype(applicationDidEnterBackground()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&AppDelegate::applicationDidEnterBackground), this);
	using FunctionType = decltype(applicationDidEnterBackground())(*)(AppDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x65c360, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto AppDelegate::applicationWillEnterForeground() -> decltype(applicationWillEnterForeground()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&AppDelegate::applicationWillEnterForeground), this);
	using FunctionType = decltype(applicationWillEnterForeground())(*)(AppDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x65c4c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto AppDelegate::applicationWillBecomeActive() -> decltype(applicationWillBecomeActive()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&AppDelegate::applicationWillBecomeActive), this);
	using FunctionType = decltype(applicationWillBecomeActive())(*)(AppDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x65c260, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto AppDelegate::applicationWillResignActive() -> decltype(applicationWillResignActive()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&AppDelegate::applicationWillResignActive), this);
	using FunctionType = decltype(applicationWillResignActive())(*)(AppDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x65c280, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto AppDelegate::trySaveGame(bool force) -> decltype(trySaveGame(force)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&AppDelegate::trySaveGame), this);
	using FunctionType = decltype(trySaveGame(force))(*)(AppDelegate*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x65c750, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, force);
}

auto AppDelegate::willSwitchToScene(cocos2d::CCScene* scene) -> decltype(willSwitchToScene(scene)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCScene*>::func(&AppDelegate::willSwitchToScene), this);
	using FunctionType = decltype(willSwitchToScene(scene))(*)(AppDelegate*, cocos2d::CCScene*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x65c830, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, scene);
}

auto AppDelegate::bgScale() -> decltype(bgScale()) {
	using FunctionType = decltype(bgScale())(*)(AppDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x65c220, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto AppDelegate::checkSound() -> decltype(checkSound()) {
	using FunctionType = decltype(checkSound())(*)(AppDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x65c6d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto AppDelegate::hideLoadingCircle() -> decltype(hideLoadingCircle()) {
	using FunctionType = decltype(hideLoadingCircle())(*)(AppDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x65c880, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto AppDelegate::loadingIsFinished() -> decltype(loadingIsFinished()) {
	using FunctionType = decltype(loadingIsFinished())(*)(AppDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x65c250, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto AppDelegate::musicTest() -> decltype(musicTest()) {
	using FunctionType = decltype(musicTest())(*)(AppDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x65c660, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto AppDelegate::pauseGame() -> decltype(pauseGame()) {
	using FunctionType = decltype(pauseGame())(*)(AppDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x65c2f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto AppDelegate::pauseSound() -> decltype(pauseSound()) {
	using FunctionType = decltype(pauseSound())(*)(AppDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x65c460, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto AppDelegate::platformShutdown() -> decltype(platformShutdown()) {
	using FunctionType = decltype(platformShutdown())(*)(AppDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x65bff0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto AppDelegate::resumeSound() -> decltype(resumeSound()) {
	using FunctionType = decltype(resumeSound())(*)(AppDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x65c5b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto AppDelegate::setIdleTimerDisabled(bool disabled) -> decltype(setIdleTimerDisabled(disabled)) {
	using FunctionType = decltype(setIdleTimerDisabled(disabled))(*)(AppDelegate*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x65c5a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, disabled);
}

auto AppDelegate::setupGLView() -> decltype(setupGLView()) {
	using FunctionType = decltype(setupGLView())(*)(AppDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x65c000, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto AppDelegate::showLoadingCircle(bool unk1, bool unk2, bool unk3) -> decltype(showLoadingCircle(unk1, unk2, unk3)) {
	using FunctionType = decltype(showLoadingCircle(unk1, unk2, unk3))(*)(AppDelegate*, bool, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x65c870, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, unk1, unk2, unk3);
}
