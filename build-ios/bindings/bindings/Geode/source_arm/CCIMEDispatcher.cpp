
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCIMEDispatcher.hpp>
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

cocos2d::CCIMEDispatcher::CCIMEDispatcher() {
	using FunctionType = void(*)(cocos2d::CCIMEDispatcher*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x41c560, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCIMEDispatcher::~CCIMEDispatcher() {
	// basically we destruct it once by calling the gd function,
	// then we release the lock because there are no other destructors after this
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCIMEDispatcher*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x41c5c8, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);
	}
	else {
		geode::DestructorLock::removeLock(this);
	}
}

auto cocos2d::CCIMEDispatcher::sharedDispatcher() -> decltype(sharedDispatcher()) {
	using FunctionType = decltype(sharedDispatcher())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x41bf40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCIMEDispatcher::addDelegate(cocos2d::CCIMEDelegate* p0) -> decltype(addDelegate(p0)) {
	using FunctionType = decltype(addDelegate(p0))(*)(cocos2d::CCIMEDispatcher*, cocos2d::CCIMEDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x41bfe8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCIMEDispatcher::attachDelegateWithIME(cocos2d::CCIMEDelegate* p0) -> decltype(attachDelegateWithIME(p0)) {
	using FunctionType = decltype(attachDelegateWithIME(p0))(*)(cocos2d::CCIMEDispatcher*, cocos2d::CCIMEDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x41c318, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCIMEDispatcher::detachDelegateWithIME(cocos2d::CCIMEDelegate* p0) -> decltype(detachDelegateWithIME(p0)) {
	using FunctionType = decltype(detachDelegateWithIME(p0))(*)(cocos2d::CCIMEDispatcher*, cocos2d::CCIMEDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x41c4e8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCIMEDispatcher::dispatchDeleteBackward() -> decltype(dispatchDeleteBackward()) {
	using FunctionType = decltype(dispatchDeleteBackward())(*)(cocos2d::CCIMEDispatcher*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x41c6f8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCIMEDispatcher::dispatchDeleteForward() -> decltype(dispatchDeleteForward()) {
	using FunctionType = decltype(dispatchDeleteForward())(*)(cocos2d::CCIMEDispatcher*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x41c718, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCIMEDispatcher::dispatchInsertText(char const* p0, int p1, cocos2d::enumKeyCodes p2) -> decltype(dispatchInsertText(p0, p1, p2)) {
	using FunctionType = decltype(dispatchInsertText(p0, p1, p2))(*)(cocos2d::CCIMEDispatcher*, char const*, int, cocos2d::enumKeyCodes);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x41c6cc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto cocos2d::CCIMEDispatcher::dispatchKeyboardDidHide(cocos2d::CCIMEKeyboardNotificationInfo& p0) -> decltype(dispatchKeyboardDidHide(p0)) {
	using FunctionType = decltype(dispatchKeyboardDidHide(p0))(*)(cocos2d::CCIMEDispatcher*, cocos2d::CCIMEKeyboardNotificationInfo&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x41c8b8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCIMEDispatcher::dispatchKeyboardDidShow(cocos2d::CCIMEKeyboardNotificationInfo& p0) -> decltype(dispatchKeyboardDidShow(p0)) {
	using FunctionType = decltype(dispatchKeyboardDidShow(p0))(*)(cocos2d::CCIMEDispatcher*, cocos2d::CCIMEKeyboardNotificationInfo&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x41c7f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCIMEDispatcher::dispatchKeyboardWillHide() -> decltype(dispatchKeyboardWillHide()) {
	using FunctionType = decltype(dispatchKeyboardWillHide())(*)(cocos2d::CCIMEDispatcher*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x41c91c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCIMEDispatcher::dispatchKeyboardWillHide(cocos2d::CCIMEKeyboardNotificationInfo& p0) -> decltype(dispatchKeyboardWillHide(p0)) {
	using FunctionType = decltype(dispatchKeyboardWillHide(p0))(*)(cocos2d::CCIMEDispatcher*, cocos2d::CCIMEKeyboardNotificationInfo&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x41c854, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCIMEDispatcher::dispatchKeyboardWillShow(cocos2d::CCIMEKeyboardNotificationInfo& p0) -> decltype(dispatchKeyboardWillShow(p0)) {
	using FunctionType = decltype(dispatchKeyboardWillShow(p0))(*)(cocos2d::CCIMEDispatcher*, cocos2d::CCIMEKeyboardNotificationInfo&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x41c78c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCIMEDispatcher::getContentText() -> decltype(getContentText()) {
	using FunctionType = decltype(getContentText())(*)(cocos2d::CCIMEDispatcher*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x41c738, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCIMEDispatcher::hasDelegate() -> decltype(hasDelegate()) {
	using FunctionType = decltype(hasDelegate())(*)(cocos2d::CCIMEDispatcher*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x41c6b8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCIMEDispatcher::removeDelegate(cocos2d::CCIMEDelegate* p0) -> decltype(removeDelegate(p0)) {
	using FunctionType = decltype(removeDelegate(p0))(*)(cocos2d::CCIMEDispatcher*, cocos2d::CCIMEDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x41c14c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
