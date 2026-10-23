
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCActionEase.hpp>
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

cocos2d::CCActionEase::~CCActionEase() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCActionEase*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x46ae68, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCActionEase(geode::CutoffConstructor, sizeof(cocos2d::CCActionEase));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCActionEase::create(cocos2d::CCActionInterval* p0) -> decltype(create(p0)) {
	using FunctionType = decltype(create(p0))(*)(cocos2d::CCActionInterval*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x46ac8c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::CCActionEase::copyWithZone(cocos2d::CCZone* p0) -> decltype(copyWithZone(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCZone*>::func(&cocos2d::CCActionEase::copyWithZone), this);
	using FunctionType = decltype(copyWithZone(p0))(*)(cocos2d::CCActionEase*, cocos2d::CCZone*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x46ad74, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCActionEase::startWithTarget(cocos2d::CCNode* p0) -> decltype(startWithTarget(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*>::func(&cocos2d::CCActionEase::startWithTarget), this);
	using FunctionType = decltype(startWithTarget(p0))(*)(cocos2d::CCActionEase*, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x46af20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCActionEase::stop() -> decltype(stop()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCActionEase::stop), this);
	using FunctionType = decltype(stop())(*)(cocos2d::CCActionEase*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x46af50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCActionEase::update(float p0) -> decltype(update(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCActionEase::update), this);
	using FunctionType = decltype(update(p0))(*)(cocos2d::CCActionEase*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x46af80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCActionEase::reverse() -> decltype(reverse()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCActionEase::reverse), this);
	using FunctionType = decltype(reverse())(*)(cocos2d::CCActionEase*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x46af90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCActionEase::getInnerAction() -> decltype(getInnerAction()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCActionEase::getInnerAction), this);
	using FunctionType = decltype(getInnerAction())(*)(cocos2d::CCActionEase*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x46afb0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCActionEase::initWithAction(cocos2d::CCActionInterval* pAction) -> decltype(initWithAction(pAction)) {
	using FunctionType = decltype(initWithAction(pAction))(*)(cocos2d::CCActionEase*, cocos2d::CCActionInterval*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x46ad34, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, pAction);
}
