
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCNotificationObserver.hpp>
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

cocos2d::CCNotificationObserver::CCNotificationObserver(cocos2d::CCObject* p0, cocos2d::SEL_CallFuncO p1, char const* p2, cocos2d::CCObject* p3) : cocos2d::CCNotificationObserver(geode::CutoffConstructor, sizeof(cocos2d::CCNotificationObserver)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCNotificationObserver::~CCNotificationObserver();

	using FunctionType = void(*)(cocos2d::CCNotificationObserver*, cocos2d::CCObject*, cocos2d::SEL_CallFuncO, char const*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x287dc0, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3);
}

cocos2d::CCNotificationObserver::~CCNotificationObserver() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCNotificationObserver*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x287f40, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCNotificationObserver(geode::CutoffConstructor, sizeof(cocos2d::CCNotificationObserver));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCNotificationObserver::getTarget() -> decltype(getTarget()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCNotificationObserver::getTarget), this);
	using FunctionType = decltype(getTarget())(*)(cocos2d::CCNotificationObserver*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x288000, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCNotificationObserver::getSelector() -> decltype(getSelector()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCNotificationObserver::getSelector), this);
	using FunctionType = decltype(getSelector())(*)(cocos2d::CCNotificationObserver*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x288010, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCNotificationObserver::getName() -> decltype(getName()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCNotificationObserver::getName), this);
	using FunctionType = decltype(getName())(*)(cocos2d::CCNotificationObserver*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x288020, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCNotificationObserver::getObject() -> decltype(getObject()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCNotificationObserver::getObject), this);
	using FunctionType = decltype(getObject())(*)(cocos2d::CCNotificationObserver*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x288030, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCNotificationObserver::getHandler() -> decltype(getHandler()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCNotificationObserver::getHandler), this);
	using FunctionType = decltype(getHandler())(*)(cocos2d::CCNotificationObserver*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x288040, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCNotificationObserver::setHandler(int p0) -> decltype(setHandler(p0)) {
	auto self = addresser::thunkAdjust(Resolve<int>::func(&cocos2d::CCNotificationObserver::setHandler), this);
	using FunctionType = decltype(setHandler(p0))(*)(cocos2d::CCNotificationObserver*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x288050, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCNotificationObserver::performSelector(cocos2d::CCObject* p0) -> decltype(performSelector(p0)) {
	using FunctionType = decltype(performSelector(p0))(*)(cocos2d::CCNotificationObserver*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x287cd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
