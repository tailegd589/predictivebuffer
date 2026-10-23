
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCArray.hpp>
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

auto cocos2d::CCArray::addObjectNew(cocos2d::CCObject* p0) -> decltype(addObjectNew(p0)) {
	using FunctionType = decltype(addObjectNew(p0))(*)(cocos2d::CCArray*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7201e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCArray::fastRemoveObjectAtIndexChild(unsigned int p0) -> decltype(fastRemoveObjectAtIndexChild(p0)) {
	using FunctionType = decltype(fastRemoveObjectAtIndexChild(p0))(*)(cocos2d::CCArray*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7202a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCArray::fastRemoveObjectAtIndexNew(unsigned int p0) -> decltype(fastRemoveObjectAtIndexNew(p0)) {
	using FunctionType = decltype(fastRemoveObjectAtIndexNew(p0))(*)(cocos2d::CCArray*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x720290, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCArray::recreateNewIndexes() -> decltype(recreateNewIndexes()) {
	using FunctionType = decltype(recreateNewIndexes())(*)(cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7201d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCArray::removeObjectAtIndexChild(unsigned int p0, bool p1) -> decltype(removeObjectAtIndexChild(p0, p1)) {
	using FunctionType = decltype(removeObjectAtIndexChild(p0, p1))(*)(cocos2d::CCArray*, unsigned int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x720240, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCArray::stringAtIndex(unsigned int p0) -> decltype(stringAtIndex(p0)) {
	using FunctionType = decltype(stringAtIndex(p0))(*)(cocos2d::CCArray*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x7200a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
