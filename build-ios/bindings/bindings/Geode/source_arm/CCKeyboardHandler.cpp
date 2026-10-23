
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCKeyboardHandler.hpp>
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

cocos2d::CCKeyboardHandler::~CCKeyboardHandler() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCKeyboardHandler*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x3afb5c, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) cocos2d::CCKeyboardHandler(geode::CutoffConstructor, sizeof(cocos2d::CCKeyboardHandler));
		geode::DestructorLock::addLock(this);
	}
}

auto cocos2d::CCKeyboardHandler::handlerWithDelegate(cocos2d::CCKeyboardDelegate* p0) -> decltype(handlerWithDelegate(p0)) {
	using FunctionType = decltype(handlerWithDelegate(p0))(*)(cocos2d::CCKeyboardDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3afd24, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::CCKeyboardHandler::initWithDelegate(cocos2d::CCKeyboardDelegate* p0) -> decltype(initWithDelegate(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCKeyboardDelegate*>::func(&cocos2d::CCKeyboardHandler::initWithDelegate), this);
	using FunctionType = decltype(initWithDelegate(p0))(*)(cocos2d::CCKeyboardHandler*, cocos2d::CCKeyboardDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3afcd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCKeyboardHandler::getDelegate() -> decltype(getDelegate()) {
	using FunctionType = decltype(getDelegate())(*)(cocos2d::CCKeyboardHandler*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3afb54, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCKeyboardHandler::setDelegate(cocos2d::CCKeyboardDelegate* p0) -> decltype(setDelegate(p0)) {
	using FunctionType = decltype(setDelegate(p0))(*)(cocos2d::CCKeyboardHandler*, cocos2d::CCKeyboardDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3afc64, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
