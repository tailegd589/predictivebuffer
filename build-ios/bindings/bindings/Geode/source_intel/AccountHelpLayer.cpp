
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/AccountHelpLayer.hpp>
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

AccountHelpLayer::~AccountHelpLayer() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(AccountHelpLayer*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0xcdfc0, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) AccountHelpLayer(geode::CutoffConstructor, sizeof(AccountHelpLayer));
		geode::DestructorLock::addLock(this);
	}
}

auto AccountHelpLayer::create() -> decltype(create()) {
	using FunctionType = decltype(create())(*)();
	static auto func = wrapFunction<FunctionType>(base::get() + 0xcde00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)();
}

auto AccountHelpLayer::customSetup() -> decltype(customSetup()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&AccountHelpLayer::customSetup), this);
	using FunctionType = decltype(customSetup())(*)(AccountHelpLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xce3e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto AccountHelpLayer::layerHidden() -> decltype(layerHidden()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&AccountHelpLayer::layerHidden), this);
	using FunctionType = decltype(layerHidden())(*)(AccountHelpLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xcf080, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto AccountHelpLayer::accountStatusChanged() -> decltype(accountStatusChanged()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&AccountHelpLayer::accountStatusChanged), this);
	using FunctionType = decltype(accountStatusChanged())(*)(AccountHelpLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xcef40, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto AccountHelpLayer::FLAlert_Clicked(FLAlertLayer* layer, bool btn2) -> decltype(FLAlert_Clicked(layer, btn2)) {
	auto self = addresser::thunkAdjust(Resolve<FLAlertLayer*, bool>::func(&AccountHelpLayer::FLAlert_Clicked), this);
	using FunctionType = decltype(FLAlert_Clicked(layer, btn2))(*)(AccountHelpLayer*, FLAlertLayer*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xcef70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, layer, btn2);
}

auto AccountHelpLayer::doUnlink() -> decltype(doUnlink()) {
	using FunctionType = decltype(doUnlink())(*)(AccountHelpLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xcef00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto AccountHelpLayer::exitLayer() -> decltype(exitLayer()) {
	using FunctionType = decltype(exitLayer())(*)(AccountHelpLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xcef30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto AccountHelpLayer::onAccountManagement(cocos2d::CCObject* sender) -> decltype(onAccountManagement(sender)) {
	using FunctionType = decltype(onAccountManagement(sender))(*)(AccountHelpLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xce820, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto AccountHelpLayer::onReLogin(cocos2d::CCObject* sender) -> decltype(onReLogin(sender)) {
	using FunctionType = decltype(onReLogin(sender))(*)(AccountHelpLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xce7c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto AccountHelpLayer::onUnlink(cocos2d::CCObject* sender) -> decltype(onUnlink(sender)) {
	using FunctionType = decltype(onUnlink(sender))(*)(AccountHelpLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xce8f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto AccountHelpLayer::updatePage() -> decltype(updatePage()) {
	using FunctionType = decltype(updatePage())(*)(AccountHelpLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xceaa0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto AccountHelpLayer::verifyUnlink() -> decltype(verifyUnlink()) {
	using FunctionType = decltype(verifyUnlink())(*)(AccountHelpLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0xcedf0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
