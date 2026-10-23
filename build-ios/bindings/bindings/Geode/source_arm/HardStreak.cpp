
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
	static auto func = wrapFunction<FunctionType>(base::get() + 0x8d808, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto HardStreak::init() -> decltype(init()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&HardStreak::init), this);
	using FunctionType = decltype(init())(*)(HardStreak*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x8d8d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto HardStreak::addPoint(cocos2d::CCPoint point) -> decltype(addPoint(point)) {
	using FunctionType = decltype(addPoint(point))(*)(HardStreak*, cocos2d::CCPoint);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x8e1a4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, point);
}

auto HardStreak::clearAboveXPos(float x) -> decltype(clearAboveXPos(x)) {
	using FunctionType = decltype(clearAboveXPos(x))(*)(HardStreak*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x8e448, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, x);
}

auto HardStreak::clearBehindXPos(float x) -> decltype(clearBehindXPos(x)) {
	using FunctionType = decltype(clearBehindXPos(x))(*)(HardStreak*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x8e3b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, x);
}

auto HardStreak::createDuplicate() -> decltype(createDuplicate()) {
	using FunctionType = decltype(createDuplicate())(*)(HardStreak*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x8e514, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto HardStreak::firstSetup() -> decltype(firstSetup()) {
	using FunctionType = decltype(firstSetup())(*)(HardStreak*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x8d990, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto HardStreak::normalizeAngle(double angle) -> decltype(normalizeAngle(angle)) {
	using FunctionType = decltype(normalizeAngle(angle))(*)(HardStreak*, double);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x8e4e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, angle);
}

auto HardStreak::quadCornerOffset(cocos2d::CCPoint start, cocos2d::CCPoint end, float width) -> decltype(quadCornerOffset(start, end, width)) {
	using FunctionType = decltype(quadCornerOffset(start, end, width))(*)(HardStreak*, cocos2d::CCPoint, cocos2d::CCPoint, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x8e1e4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, start, end, width);
}

auto HardStreak::reset() -> decltype(reset()) {
	using FunctionType = decltype(reset())(*)(HardStreak*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x8e180, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto HardStreak::resumeStroke() -> decltype(resumeStroke()) {
	using FunctionType = decltype(resumeStroke())(*)(HardStreak*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x8e138, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto HardStreak::scheduleAutoUpdate() -> decltype(scheduleAutoUpdate()) {
	using FunctionType = decltype(scheduleAutoUpdate())(*)(HardStreak*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x8da2c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto HardStreak::stopStroke() -> decltype(stopStroke()) {
	using FunctionType = decltype(stopStroke())(*)(HardStreak*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x8e144, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto HardStreak::updateStroke(float dt) -> decltype(updateStroke(dt)) {
	using FunctionType = decltype(updateStroke(dt))(*)(HardStreak*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x8da3c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, dt);
}
