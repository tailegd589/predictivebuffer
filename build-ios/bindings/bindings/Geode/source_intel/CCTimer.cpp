
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCTimer.hpp>
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

cocos2d::CCTimer::CCTimer() : cocos2d::CCTimer(geode::CutoffConstructor, sizeof(cocos2d::CCTimer)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCTimer::~CCTimer();

	using FunctionType = void(*)(cocos2d::CCTimer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x441850, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTimer::timerWithScriptHandler(int p0, float p1) -> decltype(timerWithScriptHandler(p0, p1)) {
	using FunctionType = decltype(timerWithScriptHandler(p0, p1))(*)(int, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x441a20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCTimer::timerWithTarget(cocos2d::CCObject* p0, cocos2d::SEL_SCHEDULE p1) -> decltype(timerWithTarget(p0, p1)) {
	using FunctionType = decltype(timerWithTarget(p0, p1))(*)(cocos2d::CCObject*, cocos2d::SEL_SCHEDULE);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4418a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCTimer::timerWithTarget(cocos2d::CCObject* p0, cocos2d::SEL_SCHEDULE p1, float p2) -> decltype(timerWithTarget(p0, p1, p2)) {
	using FunctionType = decltype(timerWithTarget(p0, p1, p2))(*)(cocos2d::CCObject*, cocos2d::SEL_SCHEDULE, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x441970, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

auto cocos2d::CCTimer::update(float p0) -> decltype(update(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCTimer::update), this);
	using FunctionType = decltype(update(p0))(*)(cocos2d::CCTimer*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x441b00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCTimer::getInterval() const  -> decltype(getInterval()) {
	using FunctionType = decltype(getInterval())(*)(cocos2d::CCTimer const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x441ea0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTimer::getSelector() const  -> decltype(getSelector()) {
	using FunctionType = decltype(getSelector())(*)(cocos2d::CCTimer const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x441ec0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCTimer::initWithScriptHandler(int p0, float p1) -> decltype(initWithScriptHandler(p0, p1)) {
	using FunctionType = decltype(initWithScriptHandler(p0, p1))(*)(cocos2d::CCTimer*, int, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x441ab0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCTimer::initWithTarget(cocos2d::CCObject* p0, cocos2d::SEL_SCHEDULE p1) -> decltype(initWithTarget(p0, p1)) {
	using FunctionType = decltype(initWithTarget(p0, p1))(*)(cocos2d::CCTimer*, cocos2d::CCObject*, cocos2d::SEL_SCHEDULE);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x441ad0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCTimer::initWithTarget(cocos2d::CCObject* p0, cocos2d::SEL_SCHEDULE p1, float p2, unsigned int p3, float p4) -> decltype(initWithTarget(p0, p1, p2, p3, p4)) {
	using FunctionType = decltype(initWithTarget(p0, p1, p2, p3, p4))(*)(cocos2d::CCTimer*, cocos2d::CCObject*, cocos2d::SEL_SCHEDULE, float, unsigned int, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x441930, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4);
}

auto cocos2d::CCTimer::setInterval(float p0) -> decltype(setInterval(p0)) {
	using FunctionType = decltype(setInterval(p0))(*)(cocos2d::CCTimer*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x441eb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
