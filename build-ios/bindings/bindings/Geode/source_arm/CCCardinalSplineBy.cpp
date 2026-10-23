
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCCardinalSplineBy.hpp>
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

cocos2d::CCCardinalSplineBy::CCCardinalSplineBy() : cocos2d::CCCardinalSplineBy(geode::CutoffConstructor, sizeof(cocos2d::CCCardinalSplineBy)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCCardinalSplineBy::~CCCardinalSplineBy();

	using FunctionType = void(*)(cocos2d::CCCardinalSplineBy*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26d320, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCCardinalSplineBy::create(float p0, cocos2d::CCPointArray* p1, float p2) -> decltype(create(p0, p1, p2)) {
	using FunctionType = decltype(create(p0, p1, p2))(*)(float, cocos2d::CCPointArray*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26d1f4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

auto cocos2d::CCCardinalSplineBy::startWithTarget(cocos2d::CCNode* p0) -> decltype(startWithTarget(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*>::func(&cocos2d::CCCardinalSplineBy::startWithTarget), this);
	using FunctionType = decltype(startWithTarget(p0))(*)(cocos2d::CCCardinalSplineBy*, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26d754, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCCardinalSplineBy::reverse() -> decltype(reverse()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCCardinalSplineBy::reverse), this);
	using FunctionType = decltype(reverse())(*)(cocos2d::CCCardinalSplineBy*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26d490, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCCardinalSplineBy::updatePosition(cocos2d::CCPoint& p0) -> decltype(updatePosition(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCPoint&>::func(&cocos2d::CCCardinalSplineBy::updatePosition), this);
	using FunctionType = decltype(updatePosition(p0))(*)(cocos2d::CCCardinalSplineBy*, cocos2d::CCPoint&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26d438, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}
