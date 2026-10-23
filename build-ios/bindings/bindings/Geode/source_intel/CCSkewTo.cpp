
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCSkewTo.hpp>
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

cocos2d::CCSkewTo::CCSkewTo() : cocos2d::CCSkewTo(geode::CutoffConstructor, sizeof(cocos2d::CCSkewTo)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCSkewTo::~CCSkewTo();

	using FunctionType = void(*)(cocos2d::CCSkewTo*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3b8950, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCSkewTo::create(float t, float sx, float sy) -> decltype(create(t, sx, sy)) {
	using FunctionType = decltype(create(t, sx, sy))(*)(float, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3b88a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(t, sx, sy);
}

auto cocos2d::CCSkewTo::copyWithZone(cocos2d::CCZone* pZone) -> decltype(copyWithZone(pZone)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCZone*>::func(&cocos2d::CCSkewTo::copyWithZone), this);
	using FunctionType = decltype(copyWithZone(pZone))(*)(cocos2d::CCSkewTo*, cocos2d::CCZone*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3b89d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, pZone);
}

auto cocos2d::CCSkewTo::update(float t) -> decltype(update(t)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCSkewTo::update), this);
	using FunctionType = decltype(update(t))(*)(cocos2d::CCSkewTo*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3b8c00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, t);
}

auto cocos2d::CCSkewTo::startWithTarget(cocos2d::CCNode* pTarget) -> decltype(startWithTarget(pTarget)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*>::func(&cocos2d::CCSkewTo::startWithTarget), this);
	using FunctionType = decltype(startWithTarget(pTarget))(*)(cocos2d::CCSkewTo*, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3b8ab0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, pTarget);
}

auto cocos2d::CCSkewTo::initWithDuration(float t, float sx, float sy) -> decltype(initWithDuration(t, sx, sy)) {
	auto self = addresser::thunkAdjust(Resolve<float, float, float>::func(&cocos2d::CCSkewTo::initWithDuration), this);
	using FunctionType = decltype(initWithDuration(t, sx, sy))(*)(cocos2d::CCSkewTo*, float, float, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3b8990, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, t, sx, sy);
}
