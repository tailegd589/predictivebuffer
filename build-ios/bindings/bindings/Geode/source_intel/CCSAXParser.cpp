
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCSAXParser.hpp>
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

cocos2d::CCSAXParser::CCSAXParser() {
	using FunctionType = void(*)(cocos2d::CCSAXParser*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x176090, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCSAXParser::~CCSAXParser() {
	// basically we destruct it once by calling the gd function,
	// then we release the lock because there are no other destructors after this
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(cocos2d::CCSAXParser*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x1760b0, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);
	}
	else {
		geode::DestructorLock::removeLock(this);
	}
}

auto cocos2d::CCSAXParser::endElement(void* p0, cocos2d::CC_XML_CHAR const* p1) -> decltype(endElement(p0, p1)) {
	using FunctionType = decltype(endElement(p0, p1))(*)(void*, cocos2d::CC_XML_CHAR const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x175ff0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::CCSAXParser::startElement(void* p0, cocos2d::CC_XML_CHAR const* p1, cocos2d::CC_XML_CHAR const** p2) -> decltype(startElement(p0, p1, p2)) {
	using FunctionType = decltype(startElement(p0, p1, p2))(*)(void*, cocos2d::CC_XML_CHAR const*, cocos2d::CC_XML_CHAR const**);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x175fa0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

auto cocos2d::CCSAXParser::textHandler(void* p0, cocos2d::CC_XML_CHAR const* p1, int p2) -> decltype(textHandler(p0, p1, p2)) {
	using FunctionType = decltype(textHandler(p0, p1, p2))(*)(void*, cocos2d::CC_XML_CHAR const*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x176060, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

auto cocos2d::CCSAXParser::init(char const* p0) -> decltype(init(p0)) {
	using FunctionType = decltype(init(p0))(*)(cocos2d::CCSAXParser*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1760c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCSAXParser::parse(char const* p0) -> decltype(parse(p0)) {
	using FunctionType = decltype(parse(p0))(*)(cocos2d::CCSAXParser*, char const*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x176170, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCSAXParser::parse(char const* p0, unsigned int p1) -> decltype(parse(p0, p1)) {
	using FunctionType = decltype(parse(p0, p1))(*)(cocos2d::CCSAXParser*, char const*, unsigned int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x1760d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCSAXParser::setDelegator(cocos2d::CCSAXDelegator* p0) -> decltype(setDelegator(p0)) {
	using FunctionType = decltype(setDelegator(p0))(*)(cocos2d::CCSAXParser*, cocos2d::CCSAXDelegator*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x176260, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
