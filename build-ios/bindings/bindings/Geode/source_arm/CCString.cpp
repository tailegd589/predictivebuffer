
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCString.hpp>
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

auto cocos2d::CCString::createWithContentsOfFile(char const* p0) -> decltype(createWithContentsOfFile(p0)) {
	using FunctionType = decltype(createWithContentsOfFile(p0))(*)(char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6b2100, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::CCString::createWithData(unsigned char const* p0, unsigned long p1) -> decltype(createWithData(p0, p1)) {
	using FunctionType = decltype(createWithData(p0, p1))(*)(unsigned char const*, unsigned long);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6b1ec0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCString::copyWithZone(cocos2d::CCZone* p0) -> decltype(copyWithZone(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCZone*>::func(&cocos2d::CCString::copyWithZone), this);
	using FunctionType = decltype(copyWithZone(p0))(*)(cocos2d::CCString*, cocos2d::CCZone*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6b1c7c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCString::isEqual(cocos2d::CCObject const* p0) -> decltype(isEqual(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCObject const*>::func(&cocos2d::CCString::isEqual), this);
	using FunctionType = decltype(isEqual(p0))(*)(cocos2d::CCString*, cocos2d::CCObject const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6b1d7c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCString::acceptVisitor(cocos2d::CCDataVisitor& p0) -> decltype(acceptVisitor(p0)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCDataVisitor&>::func(&cocos2d::CCString::acceptVisitor), this);
	using FunctionType = decltype(acceptVisitor(p0))(*)(cocos2d::CCString*, cocos2d::CCDataVisitor&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6b216c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCString::boolValue() const  -> decltype(boolValue()) {
	using FunctionType = decltype(boolValue())(*)(cocos2d::CCString const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6b1bec, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCString::compare(char const* p0) const  -> decltype(compare(p0)) {
	using FunctionType = decltype(compare(p0))(*)(cocos2d::CCString const *, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6b1c60, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCString::doubleValue() const  -> decltype(doubleValue()) {
	using FunctionType = decltype(doubleValue())(*)(cocos2d::CCString const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6b1bc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCString::floatValue() const  -> decltype(floatValue()) {
	using FunctionType = decltype(floatValue())(*)(cocos2d::CCString const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6b1b80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCString::getCString() const  -> decltype(getCString()) {
	using FunctionType = decltype(getCString())(*)(cocos2d::CCString const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6b1878, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCString::intValue() const  -> decltype(intValue()) {
	using FunctionType = decltype(intValue())(*)(cocos2d::CCString const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6b1b10, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCString::length() const  -> decltype(length()) {
	using FunctionType = decltype(length())(*)(cocos2d::CCString const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6b1b3c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto cocos2d::CCString::uintValue() const  -> decltype(uintValue()) {
	using FunctionType = decltype(uintValue())(*)(cocos2d::CCString const *);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x6b1b54, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
