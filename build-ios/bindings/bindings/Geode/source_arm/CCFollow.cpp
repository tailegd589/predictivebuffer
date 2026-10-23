
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCFollow.hpp>
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

cocos2d::CCFollow::~CCFollow() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCFollow*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x51dd34, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCFollow(geode::CutoffConstructor, sizeof(cocos2d::CCFollow));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCFollow::create(cocos2d::CCNode* p0, cocos2d::CCRect const& p1) -> decltype(create(p0, p1)) {
	using FunctionType = decltype(create(p0, p1))(*)(cocos2d::CCNode*, cocos2d::CCRect const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51de10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCFollow::copyWithZone(cocos2d::CCZone* p0) -> decltype(copyWithZone(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCZone*>::func(&cocos2d::CCFollow::copyWithZone), this);
	using FunctionType = decltype(copyWithZone(p0))(*)(cocos2d::CCFollow*, cocos2d::CCZone*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51e024, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCFollow::step(float p0) -> decltype(step(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCFollow::step), this);
	using FunctionType = decltype(step(p0))(*)(cocos2d::CCFollow*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51e1d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCFollow::isDone() -> decltype(isDone()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCFollow::isDone), this);
	using FunctionType = decltype(isDone())(*)(cocos2d::CCFollow*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51e2a8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCFollow::stop() -> decltype(stop()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCFollow::stop), this);
	using FunctionType = decltype(stop())(*)(cocos2d::CCFollow*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51e2cc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCFollow::initWithTarget(cocos2d::CCNode* p0, cocos2d::CCRect const& p1) -> decltype(initWithTarget(p0, p1)) {
	using FunctionType = decltype(initWithTarget(p0, p1))(*)(cocos2d::CCFollow*, cocos2d::CCNode*, cocos2d::CCRect const&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51ded4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}
