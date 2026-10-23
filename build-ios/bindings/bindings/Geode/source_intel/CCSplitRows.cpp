
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCSplitRows.hpp>
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

auto cocos2d::CCSplitRows::create(float p0, unsigned int p1) -> decltype(create(p0, p1)) {
	using FunctionType = decltype(create(p0, p1))(*)(float, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7b7b00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCSplitRows::initWithDuration(float p0, unsigned int p1) -> decltype(initWithDuration(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<float, unsigned int>::func(&cocos2d::CCSplitRows::initWithDuration), this);
	using FunctionType = decltype(initWithDuration(p0, p1))(*)(cocos2d::CCSplitRows*, float, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7b7bf0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::CCSplitRows::copyWithZone(cocos2d::CCZone* p0) -> decltype(copyWithZone(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCZone*>::func(&cocos2d::CCSplitRows::copyWithZone), this);
	using FunctionType = decltype(copyWithZone(p0))(*)(cocos2d::CCSplitRows*, cocos2d::CCZone*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7b7c40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCSplitRows::update(float p0) -> decltype(update(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCSplitRows::update), this);
	using FunctionType = decltype(update(p0))(*)(cocos2d::CCSplitRows*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7b7db0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCSplitRows::startWithTarget(cocos2d::CCNode* p0) -> decltype(startWithTarget(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*>::func(&cocos2d::CCSplitRows::startWithTarget), this);
	using FunctionType = decltype(startWithTarget(p0))(*)(cocos2d::CCSplitRows*, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7b7d70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}
