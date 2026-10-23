
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/GJPathRewardPopup.hpp>
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

auto GJPathRewardPopup::create(int path) -> decltype(create(path)) {
	using FunctionType = decltype(create(path))(*)(int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2fecc0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(path);
}

auto GJPathRewardPopup::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&GJPathRewardPopup::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(GJPathRewardPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x3035a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto GJPathRewardPopup::closePopup() -> decltype(closePopup()) {
	using FunctionType = decltype(closePopup())(*)(GJPathRewardPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x303540, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto GJPathRewardPopup::init(int path) -> decltype(init(path)) {
	using FunctionType = decltype(init(path))(*)(GJPathRewardPopup*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x302f80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, path);
}

auto GJPathRewardPopup::onClaim(cocos2d::CCObject* sender) -> decltype(onClaim(sender)) {
	using FunctionType = decltype(onClaim(sender))(*)(GJPathRewardPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x303410, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}
