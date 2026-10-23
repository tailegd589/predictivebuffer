
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCSequence.hpp>
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

cocos2d::CCSequence::~CCSequence() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCSequence*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x338a90, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCSequence(geode::CutoffConstructor, sizeof(cocos2d::CCSequence));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCSequence::create(cocos2d::CCArray* p0) -> decltype(create(p0)) {
	using FunctionType = decltype(create(p0))(*)(cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x338758, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::CCSequence::createWithTwoActions(cocos2d::CCFiniteTimeAction* p0, cocos2d::CCFiniteTimeAction* p1) -> decltype(createWithTwoActions(p0, p1)) {
	using FunctionType = decltype(createWithTwoActions(p0, p1))(*)(cocos2d::CCFiniteTimeAction*, cocos2d::CCFiniteTimeAction*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x338410, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCSequence::createWithVariableList(cocos2d::CCFiniteTimeAction* p0, va_list p1) -> decltype(createWithVariableList(p0, p1)) {
	using FunctionType = decltype(createWithVariableList(p0, p1))(*)(cocos2d::CCFiniteTimeAction*, va_list);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x338558, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCSequence::copyWithZone(cocos2d::CCZone* p0) -> decltype(copyWithZone(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCZone*>::func(&cocos2d::CCSequence::copyWithZone), this);
	using FunctionType = decltype(copyWithZone(p0))(*)(cocos2d::CCSequence*, cocos2d::CCZone*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x338964, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCSequence::update(float p0) -> decltype(update(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCSequence::update), this);
	using FunctionType = decltype(update(p0))(*)(cocos2d::CCSequence*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x338bf8, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCSequence::startWithTarget(cocos2d::CCNode* p0) -> decltype(startWithTarget(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*>::func(&cocos2d::CCSequence::startWithTarget), this);
	using FunctionType = decltype(startWithTarget(p0))(*)(cocos2d::CCSequence*, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x338b6c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCSequence::stop() -> decltype(stop()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCSequence::stop), this);
	using FunctionType = decltype(stop())(*)(cocos2d::CCSequence*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x338bb4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCSequence::reverse() -> decltype(reverse()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCSequence::reverse), this);
	using FunctionType = decltype(reverse())(*)(cocos2d::CCSequence*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x338d74, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCSequence::initWithTwoActions(cocos2d::CCFiniteTimeAction* p0, cocos2d::CCFiniteTimeAction* p1) -> decltype(initWithTwoActions(p0, p1)) {
	using FunctionType = decltype(initWithTwoActions(p0, p1))(*)(cocos2d::CCSequence*, cocos2d::CCFiniteTimeAction*, cocos2d::CCFiniteTimeAction*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3384cc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}
