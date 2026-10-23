
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCEGLView.hpp>
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

cocos2d::CCEGLView::CCEGLView() {
	using FunctionType = void(*)(cocos2d::CCEGLView*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x45b284, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCEGLView::~CCEGLView() {
	// basically we destruct it once by calling the gd function,
	// then we release the lock because there are no other destructors after this
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCEGLView*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x45b2d4, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);
	}
	else {
		geode::DestructorLock::removeLock(this);
	}
}

auto cocos2d::CCEGLView::sharedOpenGLView() -> decltype(sharedOpenGLView()) {
	using FunctionType = decltype(sharedOpenGLView())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x45b214, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCEGLView::end() -> decltype(end()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCEGLView::end), this);
	using FunctionType = decltype(end())(*)(cocos2d::CCEGLView*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x45b358, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCEGLView::swapBuffers() -> decltype(swapBuffers()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCEGLView::swapBuffers), this);
	using FunctionType = decltype(swapBuffers())(*)(cocos2d::CCEGLView*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x45b3b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCEGLView::isOpenGLReady() -> decltype(isOpenGLReady()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCEGLView::isOpenGLReady), this);
	using FunctionType = decltype(isOpenGLReady())(*)(cocos2d::CCEGLView*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x45b32c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCEGLView::setIMEKeyboardState(bool p0) -> decltype(setIMEKeyboardState(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::CCEGLView::setIMEKeyboardState), this);
	using FunctionType = decltype(setIMEKeyboardState(p0))(*)(cocos2d::CCEGLView*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x45b3e8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCEGLView::setContentScaleFactor(float p0) -> decltype(setContentScaleFactor(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCEGLView::setContentScaleFactor), this);
	using FunctionType = decltype(setContentScaleFactor(p0))(*)(cocos2d::CCEGLView*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x45b350, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCEGLView::setViewPortInPoints(float p0, float p1, float p2, float p3) -> decltype(setViewPortInPoints(p0, p1, p2, p3)) {
	auto self = addresser::thunkAdjust(Resolve<float, float, float, float>::func(&cocos2d::CCEGLView::setViewPortInPoints), this);
	using FunctionType = decltype(setViewPortInPoints(p0, p1, p2, p3))(*)(cocos2d::CCEGLView*, float, float, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x45b420, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2, p3);
}

auto cocos2d::CCEGLView::setScissorInPoints(float p0, float p1, float p2, float p3) -> decltype(setScissorInPoints(p0, p1, p2, p3)) {
	auto self = addresser::thunkAdjust(Resolve<float, float, float, float>::func(&cocos2d::CCEGLView::setScissorInPoints), this);
	using FunctionType = decltype(setScissorInPoints(p0, p1, p2, p3))(*)(cocos2d::CCEGLView*, float, float, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x45b4c8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2, p3);
}

auto cocos2d::CCEGLView::setMultiTouchMask(bool p0) -> decltype(setMultiTouchMask(p0)) {
	auto self = addresser::thunkAdjust(Resolve<bool>::func(&cocos2d::CCEGLView::setMultiTouchMask), this);
	using FunctionType = decltype(setMultiTouchMask(p0))(*)(cocos2d::CCEGLView*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x45b570, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCEGLView::showCursor(bool state) -> decltype(showCursor(state)) {
	using FunctionType = decltype(showCursor(state))(*)(cocos2d::CCEGLView*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x45b574, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, state);
}
