
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCDictElement.hpp>
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

cocos2d::CCDictElement::CCDictElement(char const* p0, cocos2d::CCObject* p1) {
	using FunctionType = void(*)(cocos2d::CCDictElement*, char const*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x29cdf8, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

cocos2d::CCDictElement::CCDictElement(intptr_t p0, cocos2d::CCObject* p1) {
	using FunctionType = void(*)(cocos2d::CCDictElement*, intptr_t, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x29ce7c, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

cocos2d::CCDictElement::~CCDictElement() {
	// basically we destruct it once by calling the gd function,
	// then we release the lock because there are no other destructors after this
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCDictElement*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x29ce98, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);
	}
	else {
		geode::DestructorLock::removeLock(this);
	}
}
