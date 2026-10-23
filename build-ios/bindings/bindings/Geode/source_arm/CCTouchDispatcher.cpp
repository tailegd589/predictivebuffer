
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCTouchDispatcher.hpp>
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

cocos2d::CCTouchDispatcher::~CCTouchDispatcher() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCTouchDispatcher*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x42a778, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCTouchDispatcher(geode::CutoffConstructor, sizeof(cocos2d::CCTouchDispatcher));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCTouchDispatcher::touchesBegan(cocos2d::CCSet* p0, cocos2d::CCEvent* p1) -> decltype(touchesBegan(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCSet*, cocos2d::CCEvent*>::func(&cocos2d::CCTouchDispatcher::touchesBegan), this);
	using FunctionType = decltype(touchesBegan(p0, p1))(*)(cocos2d::CCTouchDispatcher*, cocos2d::CCSet*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42b888, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::CCTouchDispatcher::touchesMoved(cocos2d::CCSet* p0, cocos2d::CCEvent* p1) -> decltype(touchesMoved(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCSet*, cocos2d::CCEvent*>::func(&cocos2d::CCTouchDispatcher::touchesMoved), this);
	using FunctionType = decltype(touchesMoved(p0, p1))(*)(cocos2d::CCTouchDispatcher*, cocos2d::CCSet*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42b8bc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::CCTouchDispatcher::touchesEnded(cocos2d::CCSet* p0, cocos2d::CCEvent* p1) -> decltype(touchesEnded(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCSet*, cocos2d::CCEvent*>::func(&cocos2d::CCTouchDispatcher::touchesEnded), this);
	using FunctionType = decltype(touchesEnded(p0, p1))(*)(cocos2d::CCTouchDispatcher*, cocos2d::CCSet*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42b8f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::CCTouchDispatcher::touchesCancelled(cocos2d::CCSet* p0, cocos2d::CCEvent* p1) -> decltype(touchesCancelled(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCSet*, cocos2d::CCEvent*>::func(&cocos2d::CCTouchDispatcher::touchesCancelled), this);
	using FunctionType = decltype(touchesCancelled(p0, p1))(*)(cocos2d::CCTouchDispatcher*, cocos2d::CCSet*, cocos2d::CCEvent*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42b924, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::CCTouchDispatcher::addPrioTargetedDelegate(cocos2d::CCTouchDelegate* p0, int p1, bool p2) -> decltype(addPrioTargetedDelegate(p0, p1, p2)) {
	using FunctionType = decltype(addPrioTargetedDelegate(p0, p1, p2))(*)(cocos2d::CCTouchDispatcher*, cocos2d::CCTouchDelegate*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42a984, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto cocos2d::CCTouchDispatcher::addStandardDelegate(cocos2d::CCTouchDelegate* p0, int p1) -> decltype(addStandardDelegate(p0, p1)) {
	using FunctionType = decltype(addStandardDelegate(p0, p1))(*)(cocos2d::CCTouchDispatcher*, cocos2d::CCTouchDelegate*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42ac20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCTouchDispatcher::addTargetedDelegate(cocos2d::CCTouchDelegate* p0, int p1, bool p2) -> decltype(addTargetedDelegate(p0, p1, p2)) {
	using FunctionType = decltype(addTargetedDelegate(p0, p1, p2))(*)(cocos2d::CCTouchDispatcher*, cocos2d::CCTouchDelegate*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42a99c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto cocos2d::CCTouchDispatcher::decrementForcePrio(int p0) -> decltype(decrementForcePrio(p0)) {
	using FunctionType = decltype(decrementForcePrio(p0))(*)(cocos2d::CCTouchDispatcher*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42a840, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTouchDispatcher::findHandler(cocos2d::CCTouchDelegate* p0) -> decltype(findHandler(p0)) {
	using FunctionType = decltype(findHandler(p0))(*)(cocos2d::CCTouchDispatcher*, cocos2d::CCTouchDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42b000, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTouchDispatcher::findHandler(cocos2d::CCArray* p0, cocos2d::CCTouchDelegate* p1) -> decltype(findHandler(p0, p1)) {
	using FunctionType = decltype(findHandler(p0, p1))(*)(cocos2d::CCTouchDispatcher*, cocos2d::CCArray*, cocos2d::CCTouchDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42af14, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCTouchDispatcher::forceAddHandler(cocos2d::CCTouchHandler* p0, cocos2d::CCArray* p1) -> decltype(forceAddHandler(p0, p1)) {
	using FunctionType = decltype(forceAddHandler(p0, p1))(*)(cocos2d::CCTouchDispatcher*, cocos2d::CCTouchHandler*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42ab4c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCTouchDispatcher::forceRemoveAllDelegates() -> decltype(forceRemoveAllDelegates()) {
	using FunctionType = decltype(forceRemoveAllDelegates())(*)(cocos2d::CCTouchDispatcher*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42af98, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTouchDispatcher::forceRemoveDelegate(cocos2d::CCTouchDelegate* p0) -> decltype(forceRemoveDelegate(p0)) {
	using FunctionType = decltype(forceRemoveDelegate(p0))(*)(cocos2d::CCTouchDispatcher*, cocos2d::CCTouchDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42ad54, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTouchDispatcher::incrementForcePrio(int p0) -> decltype(incrementForcePrio(p0)) {
	using FunctionType = decltype(incrementForcePrio(p0))(*)(cocos2d::CCTouchDispatcher*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42a824, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTouchDispatcher::init() -> decltype(init()) {
	using FunctionType = decltype(init())(*)(cocos2d::CCTouchDispatcher*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42a6f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTouchDispatcher::isDispatchEvents() -> decltype(isDispatchEvents()) {
	using FunctionType = decltype(isDispatchEvents())(*)(cocos2d::CCTouchDispatcher*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42a6e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTouchDispatcher::isUsingForcePrio() -> decltype(isUsingForcePrio()) {
	using FunctionType = decltype(isUsingForcePrio())(*)(cocos2d::CCTouchDispatcher*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42a974, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTouchDispatcher::rearrangeHandlers(cocos2d::CCArray* handlers) -> decltype(rearrangeHandlers(handlers)) {
	using FunctionType = decltype(rearrangeHandlers(handlers))(*)(cocos2d::CCTouchDispatcher*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42b0dc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, handlers);
}

auto cocos2d::CCTouchDispatcher::registerForcePrio(cocos2d::CCObject* p0, int p1) -> decltype(registerForcePrio(p0, p1)) {
	using FunctionType = decltype(registerForcePrio(p0, p1))(*)(cocos2d::CCTouchDispatcher*, cocos2d::CCObject*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42a85c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCTouchDispatcher::removeAllDelegates() -> decltype(removeAllDelegates()) {
	using FunctionType = decltype(removeAllDelegates())(*)(cocos2d::CCTouchDispatcher*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42afc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTouchDispatcher::removeDelegate(cocos2d::CCTouchDelegate* p0) -> decltype(removeDelegate(p0)) {
	using FunctionType = decltype(removeDelegate(p0))(*)(cocos2d::CCTouchDispatcher*, cocos2d::CCTouchDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42ae48, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTouchDispatcher::setDispatchEvents(bool p0) -> decltype(setDispatchEvents(p0)) {
	using FunctionType = decltype(setDispatchEvents(p0))(*)(cocos2d::CCTouchDispatcher*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42a6e8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTouchDispatcher::setPriority(int p1, cocos2d::CCTouchDelegate* p2) -> decltype(setPriority(p1, p2)) {
	using FunctionType = decltype(setPriority(p1, p2))(*)(cocos2d::CCTouchDispatcher*, int, cocos2d::CCTouchDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42b164, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p1, p2);
}

auto cocos2d::CCTouchDispatcher::touches(cocos2d::CCSet* p0, cocos2d::CCEvent* p1, unsigned int p2) -> decltype(touches(p0, p1, p2)) {
	using FunctionType = decltype(touches(p0, p1, p2))(*)(cocos2d::CCTouchDispatcher*, cocos2d::CCSet*, cocos2d::CCEvent*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42b2d4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto cocos2d::CCTouchDispatcher::unregisterForcePrio(cocos2d::CCObject* p0) -> decltype(unregisterForcePrio(p0)) {
	using FunctionType = decltype(unregisterForcePrio(p0))(*)(cocos2d::CCTouchDispatcher*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x42a910, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
