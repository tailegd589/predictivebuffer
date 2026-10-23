
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/mapping/CCInvocation.hpp>
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

cocos2d::extension::CCInvocation::CCInvocation(cocos2d::CCObject* p0, cocos2d::extension::SEL_CCControlHandler p1, cocos2d::extension::CCControlEvent p2) : cocos2d::extension::CCInvocation(geode::CutoffConstructor, sizeof(cocos2d::extension::CCInvocation)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	cocos2d::extension::CCInvocation::~CCInvocation();

	using FunctionType = void(*)(cocos2d::extension::CCInvocation*, cocos2d::CCObject*, cocos2d::extension::SEL_CCControlHandler, cocos2d::extension::CCControlEvent);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x357300, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto cocos2d::extension::CCInvocation::create(cocos2d::CCObject* p0, cocos2d::extension::SEL_CCControlHandler p1, cocos2d::extension::CCControlEvent p2) -> decltype(create(p0, p1, p2)) {
	using FunctionType = decltype(create(p0, p1, p2))(*)(cocos2d::CCObject*, cocos2d::extension::SEL_CCControlHandler, cocos2d::extension::CCControlEvent);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x35722c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

auto cocos2d::extension::CCInvocation::invoke(cocos2d::CCObject* p0) -> decltype(invoke(p0)) {
	using FunctionType = decltype(invoke(p0))(*)(cocos2d::extension::CCInvocation*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x357350, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, p0);
}
