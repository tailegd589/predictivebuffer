
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/SetLevelOrderPopup.hpp>
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

auto SetLevelOrderPopup::create(int levelID, int order, int amount) -> decltype(create(levelID, order, amount)) {
	using FunctionType = decltype(create(levelID, order, amount))(*)(int, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2eab0c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(levelID, order, amount);
}

auto SetLevelOrderPopup::init(int levelID, int order, int amount) -> decltype(init(levelID, order, amount)) {
	using FunctionType = decltype(init(levelID, order, amount))(*)(SetLevelOrderPopup*, int, int, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2ebf44, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, levelID, order, amount);
}

auto SetLevelOrderPopup::onOrderButton(cocos2d::CCObject* sender) -> decltype(onOrderButton(sender)) {
	using FunctionType = decltype(onOrderButton(sender))(*)(SetLevelOrderPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2ec270, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}
