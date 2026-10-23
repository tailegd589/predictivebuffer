
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/PlatformToolbox.hpp>
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

auto PlatformToolbox::activateGameCenter() -> decltype(activateGameCenter()) {
	using FunctionType = decltype(activateGameCenter())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c3dc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto PlatformToolbox::copyToClipboard(gd::string str) -> decltype(copyToClipboard(str)) {
	using FunctionType = decltype(copyToClipboard(str))(*)(gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c4a20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(str);
}

auto PlatformToolbox::doesFileExist(gd::string path) -> decltype(doesFileExist(path)) {
	using FunctionType = decltype(doesFileExist(path))(*)(gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c4240, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(path);
}

auto PlatformToolbox::downloadAndSavePromoImage(gd::string url, gd::string path) -> decltype(downloadAndSavePromoImage(url, path)) {
	using FunctionType = decltype(downloadAndSavePromoImage(url, path))(*)(gd::string, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c4330, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(url, path);
}

auto PlatformToolbox::gameDidSave() -> decltype(gameDidSave()) {
	using FunctionType = decltype(gameDidSave())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c4ac0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto PlatformToolbox::getDisplaySize() -> decltype(getDisplaySize()) {
	using FunctionType = decltype(getDisplaySize())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c4c10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto PlatformToolbox::getRawPath(char const* path) -> decltype(getRawPath(path)) {
	using FunctionType = decltype(getRawPath(path))(*)(char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c4910, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(path);
}

auto PlatformToolbox::getUniqueUserID() -> decltype(getUniqueUserID()) {
	using FunctionType = decltype(getUniqueUserID())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c3c10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto PlatformToolbox::getUserID() -> decltype(getUserID()) {
	using FunctionType = decltype(getUserID())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c3cf0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto PlatformToolbox::hideCursor() -> decltype(hideCursor()) {
	using FunctionType = decltype(hideCursor())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c3e60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto PlatformToolbox::isControllerConnected() -> decltype(isControllerConnected()) {
	using FunctionType = decltype(isControllerConnected())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c4d50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto PlatformToolbox::isHD() -> decltype(isHD()) {
	using FunctionType = decltype(isHD())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c4210, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto PlatformToolbox::isLocalPlayerAuthenticated() -> decltype(isLocalPlayerAuthenticated()) {
	using FunctionType = decltype(isLocalPlayerAuthenticated())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c3dd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto PlatformToolbox::isLowMemoryDevice() -> decltype(isLowMemoryDevice()) {
	using FunctionType = decltype(isLowMemoryDevice())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c3d20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto PlatformToolbox::isNetworkAvailable() -> decltype(isNetworkAvailable()) {
	using FunctionType = decltype(isNetworkAvailable())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c3d10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto PlatformToolbox::isSignedInGooglePlay() -> decltype(isSignedInGooglePlay()) {
	using FunctionType = decltype(isSignedInGooglePlay())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c3de0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto PlatformToolbox::loadAndDecryptFileToString(char const* dirPath, char const* fileName, gd::string& str) -> decltype(loadAndDecryptFileToString(dirPath, fileName, str)) {
	using FunctionType = decltype(loadAndDecryptFileToString(dirPath, fileName, str))(*)(char const*, char const*, gd::string&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c40a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(dirPath, fileName, str);
}

auto PlatformToolbox::logEvent(char const* event) -> decltype(logEvent(event)) {
	using FunctionType = decltype(logEvent(event))(*)(char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c3db0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(event);
}

auto PlatformToolbox::onGameLaunch() -> decltype(onGameLaunch()) {
	using FunctionType = decltype(onGameLaunch())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c3d80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto PlatformToolbox::onNativePause() -> decltype(onNativePause()) {
	using FunctionType = decltype(onNativePause())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c3d40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto PlatformToolbox::onNativeResume() -> decltype(onNativeResume()) {
	using FunctionType = decltype(onNativeResume())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c3d50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto PlatformToolbox::onToggleKeyboard() -> decltype(onToggleKeyboard()) {
	using FunctionType = decltype(onToggleKeyboard())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c3d60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto PlatformToolbox::openAppPage() -> decltype(openAppPage()) {
	using FunctionType = decltype(openAppPage())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c3eb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto PlatformToolbox::platformShutdown() -> decltype(platformShutdown()) {
	using FunctionType = decltype(platformShutdown())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c4c70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto PlatformToolbox::refreshWindow() -> decltype(refreshWindow()) {
	using FunctionType = decltype(refreshWindow())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c4e00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto PlatformToolbox::reportAchievementWithID(char const* key, int percent) -> decltype(reportAchievementWithID(key, percent)) {
	using FunctionType = decltype(reportAchievementWithID(key, percent))(*)(char const*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c3e10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(key, percent);
}

auto PlatformToolbox::reportLoadingFinished() -> decltype(reportLoadingFinished()) {
	using FunctionType = decltype(reportLoadingFinished())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c3d30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto PlatformToolbox::resizeWindow(float width, float height) -> decltype(resizeWindow(width, height)) {
	using FunctionType = decltype(resizeWindow(width, height))(*)(float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c4b80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(width, height);
}

auto PlatformToolbox::saveAndEncryptStringToFile(gd::string& str, char const* fileName, char const* dirPath) -> decltype(saveAndEncryptStringToFile(str, fileName, dirPath)) {
	using FunctionType = decltype(saveAndEncryptStringToFile(str, fileName, dirPath))(*)(gd::string&, char const*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c3ec0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(str, fileName, dirPath);
}

auto PlatformToolbox::sendMail(char const* title, char const* content, char const* address) -> decltype(sendMail(title, content, address)) {
	using FunctionType = decltype(sendMail(title, content, address))(*)(char const*, char const*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c3e50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(title, content, address);
}

auto PlatformToolbox::setBlockBackButton(bool block) -> decltype(setBlockBackButton(block)) {
	using FunctionType = decltype(setBlockBackButton(block))(*)(bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c3d90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(block);
}

auto PlatformToolbox::setKeyboardState(bool state) -> decltype(setKeyboardState(state)) {
	using FunctionType = decltype(setKeyboardState(state))(*)(bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c3d70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(state);
}

auto PlatformToolbox::shouldResumeSound() -> decltype(shouldResumeSound()) {
	using FunctionType = decltype(shouldResumeSound())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c3da0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto PlatformToolbox::showAchievements() -> decltype(showAchievements()) {
	using FunctionType = decltype(showAchievements())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c3e40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto PlatformToolbox::showCursor() -> decltype(showCursor()) {
	using FunctionType = decltype(showCursor())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c3e80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto PlatformToolbox::signInGooglePlay() -> decltype(signInGooglePlay()) {
	using FunctionType = decltype(signInGooglePlay())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c3df0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto PlatformToolbox::signOutGooglePlay() -> decltype(signOutGooglePlay()) {
	using FunctionType = decltype(signOutGooglePlay())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c3e00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto PlatformToolbox::spriteFromSavedFile(gd::string path) -> decltype(spriteFromSavedFile(path)) {
	using FunctionType = decltype(spriteFromSavedFile(path))(*)(gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c4340, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(path);
}

auto PlatformToolbox::toggleCallGLFinish(bool enable) -> decltype(toggleCallGLFinish(enable)) {
	using FunctionType = decltype(toggleCallGLFinish(enable))(*)(bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c4dc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(enable);
}

auto PlatformToolbox::toggleCPUSleepMode(bool enable) -> decltype(toggleCPUSleepMode(enable)) {
	using FunctionType = decltype(toggleCPUSleepMode(enable))(*)(bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c4da0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(enable);
}

auto PlatformToolbox::toggleForceTimer(bool enable) -> decltype(toggleForceTimer(enable)) {
	using FunctionType = decltype(toggleForceTimer(enable))(*)(bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c4dd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(enable);
}

auto PlatformToolbox::toggleFullScreen(bool fullscreen, bool borderless, bool fix) -> decltype(toggleFullScreen(fullscreen, borderless, fix)) {
	using FunctionType = decltype(toggleFullScreen(fullscreen, borderless, fix))(*)(bool, bool, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c4b10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(fullscreen, borderless, fix);
}

auto PlatformToolbox::toggleLockCursor(bool isLocked) -> decltype(toggleLockCursor(isLocked)) {
	using FunctionType = decltype(toggleLockCursor(isLocked))(*)(bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c4b70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(isLocked);
}

auto PlatformToolbox::toggleMouseControl(bool enable) -> decltype(toggleMouseControl(enable)) {
	using FunctionType = decltype(toggleMouseControl(enable))(*)(bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c4d00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(enable);
}

auto PlatformToolbox::toggleSmoothFix(bool enable) -> decltype(toggleSmoothFix(enable)) {
	using FunctionType = decltype(toggleSmoothFix(enable))(*)(bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c4de0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(enable);
}

auto PlatformToolbox::toggleVerticalSync(bool enable) -> decltype(toggleVerticalSync(enable)) {
	using FunctionType = decltype(toggleVerticalSync(enable))(*)(bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c4db0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(enable);
}

auto PlatformToolbox::tryShowRateDialog(gd::string gameName) -> decltype(tryShowRateDialog(gameName)) {
	using FunctionType = decltype(tryShowRateDialog(gameName))(*)(gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c3ea0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(gameName);
}

auto PlatformToolbox::updateMouseControl() -> decltype(updateMouseControl()) {
	using FunctionType = decltype(updateMouseControl())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c4cc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto PlatformToolbox::updateWindowedSize(float width, float height) -> decltype(updateWindowedSize(width, height)) {
	using FunctionType = decltype(updateWindowedSize(width, height))(*)(float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c4c00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(width, height);
}
