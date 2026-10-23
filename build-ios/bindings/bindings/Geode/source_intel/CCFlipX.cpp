
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCFlipX.hpp>
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

auto cocos2d::CCFlipX::create(bool p0) -> decltype(create(p0)) {
	using FunctionType = decltype(create(p0))(*)(bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7acad0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::CCFlipX::update(float p0) -> decltype(update(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCFlipX::update), this);
	using FunctionType = decltype(update(p0))(*)(cocos2d::CCFlipX*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7acb40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCFlipX::reverse() -> decltype(reverse()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCFlipX::reverse), this);
	using FunctionType = decltype(reverse())(*)(cocos2d::CCFlipX*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7acb60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCFlipX::copyWithZone(cocos2d::CCZone* p0) -> decltype(copyWithZone(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCZone*>::func(&cocos2d::CCFlipX::copyWithZone), this);
	using FunctionType = decltype(copyWithZone(p0))(*)(cocos2d::CCFlipX*, cocos2d::CCZone*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7acbc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCFlipX::initWithFlipX(bool p0) -> decltype(initWithFlipX(p0)) {
	using FunctionType = decltype(initWithFlipX(p0))(*)(cocos2d::CCFlipX*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7acb30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
