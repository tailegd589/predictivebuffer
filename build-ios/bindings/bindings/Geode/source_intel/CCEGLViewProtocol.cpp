
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCEGLViewProtocol.hpp>
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

cocos2d::CCEGLViewProtocol::CCEGLViewProtocol() {
	using FunctionType = void(*)(cocos2d::CCEGLViewProtocol*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50fb10, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCEGLViewProtocol::~CCEGLViewProtocol() {
	// basically we destruct it once by calling the gd function,
	// then we release the lock because there are no other destructors after this
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCEGLViewProtocol*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x50fb70, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);
	}
	else {
		geode::DestructorLock::removeLock(this);
	}
}

auto cocos2d::CCEGLViewProtocol::getFrameSize() const  -> decltype(getFrameSize()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCEGLViewProtocol::getFrameSize), this);
	using FunctionType = decltype(getFrameSize())(*)(cocos2d::CCEGLViewProtocol const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50fcf0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCEGLViewProtocol::setFrameSize(float p0, float p1) -> decltype(setFrameSize(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<float, float>::func(&cocos2d::CCEGLViewProtocol::setFrameSize), this);
	using FunctionType = decltype(setFrameSize(p0, p1))(*)(cocos2d::CCEGLViewProtocol*, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50fd00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::CCEGLViewProtocol::getVisibleSize() const  -> decltype(getVisibleSize()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCEGLViewProtocol::getVisibleSize), this);
	using FunctionType = decltype(getVisibleSize())(*)(cocos2d::CCEGLViewProtocol const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50fd40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCEGLViewProtocol::getVisibleOrigin() const  -> decltype(getVisibleOrigin()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCEGLViewProtocol::getVisibleOrigin), this);
	using FunctionType = decltype(getVisibleOrigin())(*)(cocos2d::CCEGLViewProtocol const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50fd90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCEGLViewProtocol::setDesignResolutionSize(float p0, float p1, ResolutionPolicy p2) -> decltype(setDesignResolutionSize(p0, p1, p2)) {
	auto self = addresser::thunkAdjust(Resolve<float, float, ResolutionPolicy>::func(&cocos2d::CCEGLViewProtocol::setDesignResolutionSize), this);
	using FunctionType = decltype(setDesignResolutionSize(p0, p1, p2))(*)(cocos2d::CCEGLViewProtocol*, float, float, ResolutionPolicy);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50fba0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2);
}

auto cocos2d::CCEGLViewProtocol::getDesignResolutionSize() const  -> decltype(getDesignResolutionSize()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCEGLViewProtocol::getDesignResolutionSize), this);
	using FunctionType = decltype(getDesignResolutionSize())(*)(cocos2d::CCEGLViewProtocol const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50fce0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCEGLViewProtocol::setTouchDelegate(cocos2d::EGLTouchDelegate* p0) -> decltype(setTouchDelegate(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::EGLTouchDelegate*>::func(&cocos2d::CCEGLViewProtocol::setTouchDelegate), this);
	using FunctionType = decltype(setTouchDelegate(p0))(*)(cocos2d::CCEGLViewProtocol*, cocos2d::EGLTouchDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50fe00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCEGLViewProtocol::setViewPortInPoints(float p0, float p1, float p2, float p3) -> decltype(setViewPortInPoints(p0, p1, p2, p3)) {
	auto self = addresser::thunkAdjust(Resolve<float, float, float, float>::func(&cocos2d::CCEGLViewProtocol::setViewPortInPoints), this);
	using FunctionType = decltype(setViewPortInPoints(p0, p1, p2, p3))(*)(cocos2d::CCEGLViewProtocol*, float, float, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50fe10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2, p3);
}

auto cocos2d::CCEGLViewProtocol::setScissorInPoints(float p0, float p1, float p2, float p3) -> decltype(setScissorInPoints(p0, p1, p2, p3)) {
	auto self = addresser::thunkAdjust(Resolve<float, float, float, float>::func(&cocos2d::CCEGLViewProtocol::setScissorInPoints), this);
	using FunctionType = decltype(setScissorInPoints(p0, p1, p2, p3))(*)(cocos2d::CCEGLViewProtocol*, float, float, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50fe50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2, p3);
}

auto cocos2d::CCEGLViewProtocol::isScissorEnabled() -> decltype(isScissorEnabled()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCEGLViewProtocol::isScissorEnabled), this);
	using FunctionType = decltype(isScissorEnabled())(*)(cocos2d::CCEGLViewProtocol*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50fe90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCEGLViewProtocol::getScissorRect() -> decltype(getScissorRect()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCEGLViewProtocol::getScissorRect), this);
	using FunctionType = decltype(getScissorRect())(*)(cocos2d::CCEGLViewProtocol*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50feb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCEGLViewProtocol::setViewName(char const* p0) -> decltype(setViewName(p0)) {
	auto self = addresser::thunkAdjust(Resolve<char const*>::func(&cocos2d::CCEGLViewProtocol::setViewName), this);
	using FunctionType = decltype(setViewName(p0))(*)(cocos2d::CCEGLViewProtocol*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50ff50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCEGLViewProtocol::pollInputEvents() -> decltype(pollInputEvents()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCEGLViewProtocol::pollInputEvents), this);
	using FunctionType = decltype(pollInputEvents())(*)(cocos2d::CCEGLViewProtocol*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5106e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCEGLViewProtocol::handleTouchesBegin(int p0, int* p1, float* p2, float* p3, double p4) -> decltype(handleTouchesBegin(p0, p1, p2, p3, p4)) {
	auto self = addresser::thunkAdjust(Resolve<int, int*, float*, float*, double>::func(&cocos2d::CCEGLViewProtocol::handleTouchesBegin), this);
	using FunctionType = decltype(handleTouchesBegin(p0, p1, p2, p3, p4))(*)(cocos2d::CCEGLViewProtocol*, int, int*, float*, float*, double);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50ff80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2, p3, p4);
}

auto cocos2d::CCEGLViewProtocol::handleTouchesMove(int p0, int* p1, float* p2, float* p3, double p4) -> decltype(handleTouchesMove(p0, p1, p2, p3, p4)) {
	auto self = addresser::thunkAdjust(Resolve<int, int*, float*, float*, double>::func(&cocos2d::CCEGLViewProtocol::handleTouchesMove), this);
	using FunctionType = decltype(handleTouchesMove(p0, p1, p2, p3, p4))(*)(cocos2d::CCEGLViewProtocol*, int, int*, float*, float*, double);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x510260, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2, p3, p4);
}

auto cocos2d::CCEGLViewProtocol::handleTouchesEnd(int p0, int* p1, float* p2, float* p3, double p4) -> decltype(handleTouchesEnd(p0, p1, p2, p3, p4)) {
	auto self = addresser::thunkAdjust(Resolve<int, int*, float*, float*, double>::func(&cocos2d::CCEGLViewProtocol::handleTouchesEnd), this);
	using FunctionType = decltype(handleTouchesEnd(p0, p1, p2, p3, p4))(*)(cocos2d::CCEGLViewProtocol*, int, int*, float*, float*, double);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x510590, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2, p3, p4);
}

auto cocos2d::CCEGLViewProtocol::handleTouchesCancel(int p0, int* p1, float* p2, float* p3, double p4) -> decltype(handleTouchesCancel(p0, p1, p2, p3, p4)) {
	auto self = addresser::thunkAdjust(Resolve<int, int*, float*, float*, double>::func(&cocos2d::CCEGLViewProtocol::handleTouchesCancel), this);
	using FunctionType = decltype(handleTouchesCancel(p0, p1, p2, p3, p4))(*)(cocos2d::CCEGLViewProtocol*, int, int*, float*, float*, double);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x510620, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2, p3, p4);
}

auto cocos2d::CCEGLViewProtocol::getScaleX() const  -> decltype(getScaleX()) {
	using FunctionType = decltype(getScaleX())(*)(cocos2d::CCEGLViewProtocol const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5106c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCEGLViewProtocol::getScaleY() const  -> decltype(getScaleY()) {
	using FunctionType = decltype(getScaleY())(*)(cocos2d::CCEGLViewProtocol const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5106d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCEGLViewProtocol::getSetOfTouchesEndOrCancel(cocos2d::CCSet& p0, int p1, int* p2, float* p3, float* p4, double p5) -> decltype(getSetOfTouchesEndOrCancel(p0, p1, p2, p3, p4, p5)) {
	using FunctionType = decltype(getSetOfTouchesEndOrCancel(p0, p1, p2, p3, p4, p5))(*)(cocos2d::CCEGLViewProtocol*, cocos2d::CCSet&, int, int*, float*, float*, double);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x510400, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5);
}

auto cocos2d::CCEGLViewProtocol::getViewName() -> decltype(getViewName()) {
	using FunctionType = decltype(getViewName())(*)(cocos2d::CCEGLViewProtocol*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x50ff70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCEGLViewProtocol::getViewPortRect() const  -> decltype(getViewPortRect()) {
	using FunctionType = decltype(getViewPortRect())(*)(cocos2d::CCEGLViewProtocol const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5106b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCEGLViewProtocol::updateDesignResolutionSize() -> decltype(updateDesignResolutionSize()) {
	using FunctionType = decltype(updateDesignResolutionSize())(*)(cocos2d::CCEGLViewProtocol*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5106f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
