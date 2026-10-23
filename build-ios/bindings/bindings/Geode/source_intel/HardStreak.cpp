
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/HardStreak.hpp>
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

auto HardStreak::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x9cd60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto HardStreak::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&HardStreak::init), this);
	using FunctionType = decltype(init())(*)(HardStreak*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x9ce30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto HardStreak::addPoint(cocos2d::CCPoint point) -> decltype(addPoint(point)) {
	using FunctionType = decltype(addPoint(point))(*)(HardStreak*, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x9d8a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, point);
}

auto HardStreak::clearAboveXPos(float x) -> decltype(clearAboveXPos(x)) {
	using FunctionType = decltype(clearAboveXPos(x))(*)(HardStreak*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x9db20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, x);
}

auto HardStreak::clearBehindXPos(float x) -> decltype(clearBehindXPos(x)) {
	using FunctionType = decltype(clearBehindXPos(x))(*)(HardStreak*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x9da80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, x);
}

auto HardStreak::createDuplicate() -> decltype(createDuplicate()) {
	using FunctionType = decltype(createDuplicate())(*)(HardStreak*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x9dbf0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto HardStreak::firstSetup() -> decltype(firstSetup()) {
	using FunctionType = decltype(firstSetup())(*)(HardStreak*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x9cf10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto HardStreak::normalizeAngle(double angle) -> decltype(normalizeAngle(angle)) {
	using FunctionType = decltype(normalizeAngle(angle))(*)(HardStreak*, double);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x9dbc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, angle);
}

auto HardStreak::quadCornerOffset(cocos2d::CCPoint start, cocos2d::CCPoint end, float width) -> decltype(quadCornerOffset(start, end, width)) {
	using FunctionType = decltype(quadCornerOffset(start, end, width))(*)(HardStreak*, cocos2d::CCPoint, cocos2d::CCPoint, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x9d8e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, start, end, width);
}

auto HardStreak::reset() -> decltype(reset()) {
	using FunctionType = decltype(reset())(*)(HardStreak*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x9d880, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto HardStreak::resumeStroke() -> decltype(resumeStroke()) {
	using FunctionType = decltype(resumeStroke())(*)(HardStreak*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x9d820, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto HardStreak::scheduleAutoUpdate() -> decltype(scheduleAutoUpdate()) {
	using FunctionType = decltype(scheduleAutoUpdate())(*)(HardStreak*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x9cfc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto HardStreak::stopStroke() -> decltype(stopStroke()) {
	using FunctionType = decltype(stopStroke())(*)(HardStreak*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x9d840, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto HardStreak::updateStroke(float dt) -> decltype(updateStroke(dt)) {
	using FunctionType = decltype(updateStroke(dt))(*)(HardStreak*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x9cfe0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt);
}
