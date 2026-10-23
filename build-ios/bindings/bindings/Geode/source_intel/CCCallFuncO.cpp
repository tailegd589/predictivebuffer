
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCCallFuncO.hpp>
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

cocos2d::CCCallFuncO::CCCallFuncO() : cocos2d::CCCallFuncO(geode::CutoffConstructor, sizeof(cocos2d::CCCallFuncO)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCCallFuncO::~CCCallFuncO();

	using FunctionType = void(*)(cocos2d::CCCallFuncO*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7ad9b0, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCCallFuncO::~CCCallFuncO() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCCallFuncO*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x7ada10, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCCallFuncO(geode::CutoffConstructor, sizeof(cocos2d::CCCallFuncO));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCCallFuncO::create(cocos2d::CCObject* p0, cocos2d::SEL_MenuHandler p1, cocos2d::CCObject* p2) -> decltype(create(p0, p1, p2)) {
	using FunctionType = decltype(create(p0, p1, p2))(*)(cocos2d::CCObject*, cocos2d::SEL_MenuHandler, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7adb00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

auto cocos2d::CCCallFuncO::copyWithZone(cocos2d::CCZone* p0) -> decltype(copyWithZone(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCZone*>::func(&cocos2d::CCCallFuncO::copyWithZone), this);
	using FunctionType = decltype(copyWithZone(p0))(*)(cocos2d::CCCallFuncO*, cocos2d::CCZone*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7adc50, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCCallFuncO::execute() -> decltype(execute()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCCallFuncO::execute), this);
	using FunctionType = decltype(execute())(*)(cocos2d::CCCallFuncO*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7adac0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCCallFuncO::initWithTarget(cocos2d::CCObject* p0, cocos2d::SEL_MenuHandler p1, cocos2d::CCObject* p2) -> decltype(initWithTarget(p0, p1, p2)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCObject*, cocos2d::SEL_MenuHandler, cocos2d::CCObject*>::func(&cocos2d::CCCallFuncO::initWithTarget), this);
	using FunctionType = decltype(initWithTarget(p0, p1, p2))(*)(cocos2d::CCCallFuncO*, cocos2d::CCObject*, cocos2d::SEL_MenuHandler, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7adbe0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2);
}
