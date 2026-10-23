
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCIMEDelegate.hpp>
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

cocos2d::CCIMEDelegate::CCIMEDelegate() {
	using FunctionType = void(*)(cocos2d::CCIMEDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x41be44, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCIMEDelegate::~CCIMEDelegate() {
	// basically we destruct it once by calling the gd function,
	// then we release the lock because there are no other destructors after this
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCIMEDelegate*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x41c054, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);
	}
	else {
		geode::DestructorLock::removeLock(this);
	}
}

auto cocos2d::CCIMEDelegate::attachWithIME() -> decltype(attachWithIME()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCIMEDelegate::attachWithIME), this);
	using FunctionType = decltype(attachWithIME())(*)(cocos2d::CCIMEDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x41c1bc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto cocos2d::CCIMEDelegate::detachWithIME() -> decltype(detachWithIME()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&cocos2d::CCIMEDelegate::detachWithIME), this);
	using FunctionType = decltype(detachWithIME())(*)(cocos2d::CCIMEDelegate*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x41c3f4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}
