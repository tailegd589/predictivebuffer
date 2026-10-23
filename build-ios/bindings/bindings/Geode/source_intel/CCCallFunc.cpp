
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCCallFunc.hpp>
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

cocos2d::CCCallFunc::~CCCallFunc() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCCallFunc*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x7ad150, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCCallFunc(geode::CutoffConstructor, sizeof(cocos2d::CCCallFunc));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCCallFunc::create(cocos2d::CCObject* p0, cocos2d::SEL_CallFunc p1) -> decltype(create(p0, p1)) {
	using FunctionType = decltype(create(p0, p1))(*)(cocos2d::CCObject*, cocos2d::SEL_CallFunc);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7ad000, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCCallFunc::copyWithZone(cocos2d::CCZone* p0) -> decltype(copyWithZone(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCZone*>::func(&cocos2d::CCCallFunc::copyWithZone), this);
	using FunctionType = decltype(copyWithZone(p0))(*)(cocos2d::CCCallFunc*, cocos2d::CCZone*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7ad250, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCCallFunc::update(float p0) -> decltype(update(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCCallFunc::update), this);
	using FunctionType = decltype(update(p0))(*)(cocos2d::CCCallFunc*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7ad350, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCCallFunc::initWithTarget(cocos2d::CCObject* p0) -> decltype(initWithTarget(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCObject*>::func(&cocos2d::CCCallFunc::initWithTarget), this);
	using FunctionType = decltype(initWithTarget(p0))(*)(cocos2d::CCCallFunc*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7ad110, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCCallFunc::execute() -> decltype(execute()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCCallFunc::execute), this);
	using FunctionType = decltype(execute())(*)(cocos2d::CCCallFunc*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7ad360, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}
