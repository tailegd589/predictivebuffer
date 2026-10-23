
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCTouchHandler.hpp>
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

cocos2d::CCTouchHandler::~CCTouchHandler() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCTouchHandler*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x4812f0, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCTouchHandler(geode::CutoffConstructor, sizeof(cocos2d::CCTouchHandler));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCTouchHandler::handlerWithDelegate(cocos2d::CCTouchDelegate* p0, int p1) -> decltype(handlerWithDelegate(p0, p1)) {
	using FunctionType = decltype(handlerWithDelegate(p0, p1))(*)(cocos2d::CCTouchDelegate*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4811e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCTouchHandler::initWithDelegate(cocos2d::CCTouchDelegate* p0, int p1) -> decltype(initWithDelegate(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCTouchDelegate*, int>::func(&cocos2d::CCTouchHandler::initWithDelegate), this);
	using FunctionType = decltype(initWithDelegate(p0, p1))(*)(cocos2d::CCTouchHandler*, cocos2d::CCTouchDelegate*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x481290, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::CCTouchHandler::getDelegate() -> decltype(getDelegate()) {
	using FunctionType = decltype(getDelegate())(*)(cocos2d::CCTouchHandler*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x481120, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTouchHandler::getEnabledSelectors() -> decltype(getEnabledSelectors()) {
	using FunctionType = decltype(getEnabledSelectors())(*)(cocos2d::CCTouchHandler*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4811c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTouchHandler::getPriority() -> decltype(getPriority()) {
	using FunctionType = decltype(getPriority())(*)(cocos2d::CCTouchHandler*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4811a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTouchHandler::setDelegate(cocos2d::CCTouchDelegate* p0) -> decltype(setDelegate(p0)) {
	using FunctionType = decltype(setDelegate(p0))(*)(cocos2d::CCTouchHandler*, cocos2d::CCTouchDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x481130, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTouchHandler::setEnalbedSelectors(int p0) -> decltype(setEnalbedSelectors(p0)) {
	using FunctionType = decltype(setEnalbedSelectors(p0))(*)(cocos2d::CCTouchHandler*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4811d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCTouchHandler::setPriority(int prio) -> decltype(setPriority(prio)) {
	using FunctionType = decltype(setPriority(prio))(*)(cocos2d::CCTouchHandler*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4811b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, prio);
}
