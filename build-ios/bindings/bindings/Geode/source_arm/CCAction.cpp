
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCAction.hpp>
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

cocos2d::CCAction::CCAction() : cocos2d::CCAction(geode::CutoffConstructor, sizeof(cocos2d::CCAction)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::CCAction::~CCAction();

	using FunctionType = void(*)(cocos2d::CCAction*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51d67c, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCAction::~CCAction() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCAction*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x51d6dc, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCAction(geode::CutoffConstructor, sizeof(cocos2d::CCAction));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCAction::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51d71c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto cocos2d::CCAction::copyWithZone(cocos2d::CCZone* p0) -> decltype(copyWithZone(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCZone*>::func(&cocos2d::CCAction::copyWithZone), this);
	using FunctionType = decltype(copyWithZone(p0))(*)(cocos2d::CCAction*, cocos2d::CCZone*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51d7ac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCAction::update(float p0) -> decltype(update(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCAction::update), this);
	using FunctionType = decltype(update(p0))(*)(cocos2d::CCAction*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51d894, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCAction::isDone() -> decltype(isDone()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCAction::isDone), this);
	using FunctionType = decltype(isDone())(*)(cocos2d::CCAction*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51d888, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCAction::startWithTarget(cocos2d::CCNode* p0) -> decltype(startWithTarget(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCNode*>::func(&cocos2d::CCAction::startWithTarget), this);
	using FunctionType = decltype(startWithTarget(p0))(*)(cocos2d::CCAction*, cocos2d::CCNode*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51d878, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCAction::stop() -> decltype(stop()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCAction::stop), this);
	using FunctionType = decltype(stop())(*)(cocos2d::CCAction*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51d880, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCAction::step(float p0) -> decltype(step(p0)) {
	auto self = addresser::thunkAdjust(Resolve<float>::func(&cocos2d::CCAction::step), this);
	using FunctionType = decltype(step(p0))(*)(cocos2d::CCAction*, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51d890, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCAction::description() -> decltype(description()) {
	using FunctionType = decltype(description())(*)(cocos2d::CCAction*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51d780, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
