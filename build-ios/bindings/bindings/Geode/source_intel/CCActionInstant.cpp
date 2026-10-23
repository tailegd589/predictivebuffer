
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCActionInstant.hpp>
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

cocos2d::CCActionInstant::CCActionInstant() : cocos2d::CCActionInstant(geode::CutoffConstructor, sizeof(cocos2d::CCActionInstant)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCActionInstant::~CCActionInstant();

	using FunctionType = void(*)(cocos2d::CCActionInstant*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7ac3a0, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCActionInstant::copyWithZone(cocos2d::CCZone* p0) -> decltype(copyWithZone(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCZone*>::func(&cocos2d::CCActionInstant::copyWithZone), this);
	using FunctionType = decltype(copyWithZone(p0))(*)(cocos2d::CCActionInstant*, cocos2d::CCZone*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7ac400, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCActionInstant::update(float p0) -> decltype(update(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCActionInstant::update), this);
	using FunctionType = decltype(update(p0))(*)(cocos2d::CCActionInstant*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7ac4e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCActionInstant::isDone() -> decltype(isDone()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCActionInstant::isDone), this);
	using FunctionType = decltype(isDone())(*)(cocos2d::CCActionInstant*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7ac4b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCActionInstant::step(float p0) -> decltype(step(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCActionInstant::step), this);
	using FunctionType = decltype(step(p0))(*)(cocos2d::CCActionInstant*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7ac4c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCActionInstant::reverse() -> decltype(reverse()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCActionInstant::reverse), this);
	using FunctionType = decltype(reverse())(*)(cocos2d::CCActionInstant*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7ac4f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}
