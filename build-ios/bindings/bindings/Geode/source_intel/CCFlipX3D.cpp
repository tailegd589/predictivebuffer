
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCFlipX3D.hpp>
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

auto cocos2d::CCFlipX3D::create(float p0) -> decltype(create(p0)) {
	using FunctionType = decltype(create(p0))(*)(float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x27d540, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::CCFlipX3D::initWithDuration(float p0) -> decltype(initWithDuration(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCFlipX3D::initWithDuration), this);
	using FunctionType = decltype(initWithDuration(p0))(*)(cocos2d::CCFlipX3D*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x27d630, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCFlipX3D::initWithSize(cocos2d::CCSize const& p0, float p1) -> decltype(initWithSize(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCSize const&, float>::func(&cocos2d::CCFlipX3D::initWithSize), this);
	using FunctionType = decltype(initWithSize(p0, p1))(*)(cocos2d::CCFlipX3D*, cocos2d::CCSize const&, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x27d680, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::CCFlipX3D::copyWithZone(cocos2d::CCZone* p0) -> decltype(copyWithZone(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCZone*>::func(&cocos2d::CCFlipX3D::copyWithZone), this);
	using FunctionType = decltype(copyWithZone(p0))(*)(cocos2d::CCFlipX3D*, cocos2d::CCZone*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x27d6b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCFlipX3D::update(float p0) -> decltype(update(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCFlipX3D::update), this);
	using FunctionType = decltype(update(p0))(*)(cocos2d::CCFlipX3D*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x27d7d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}
