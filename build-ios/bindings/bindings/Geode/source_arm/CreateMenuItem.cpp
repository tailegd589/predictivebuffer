
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/CreateMenuItem.hpp>
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

auto CreateMenuItem::create(cocos2d::CCNode* normal, cocos2d::CCNode* selected, cocos2d::CCObject* target, cocos2d::SEL_MenuHandler selector) -> decltype(create(normal, selected, target, selector)) {
	using FunctionType = decltype(create(normal, selected, target, selector))(*)(cocos2d::CCNode*, cocos2d::CCNode*, cocos2d::CCObject*, cocos2d::SEL_MenuHandler);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2bf9c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(normal, selected, target, selector);
}

auto CreateMenuItem::init(cocos2d::CCNode* normal, cocos2d::CCNode* selected, cocos2d::CCObject* target, cocos2d::SEL_MenuHandler selector) -> decltype(init(normal, selected, target, selector)) {
	using FunctionType = decltype(init(normal, selected, target, selector))(*)(CreateMenuItem*, cocos2d::CCNode*, cocos2d::CCNode*, cocos2d::CCObject*, cocos2d::SEL_MenuHandler);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4677c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, normal, selected, target, selector);
}
