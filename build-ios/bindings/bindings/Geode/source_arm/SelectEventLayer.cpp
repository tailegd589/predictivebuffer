
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/SelectEventLayer.hpp>
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

SelectEventLayer::~SelectEventLayer() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(SelectEventLayer*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x4c5780, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) SelectEventLayer(geode::CutoffConstructor, sizeof(SelectEventLayer));
		geode::DestructorLock::addLock(this);
	}
}

auto SelectEventLayer::create(SetupEventLinkPopup* popup, gd::set<int>& eventIDs) -> decltype(create(popup, eventIDs)) {
	using FunctionType = decltype(create(popup, eventIDs))(*)(SetupEventLinkPopup*, gd::set<int>&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c553c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(popup, eventIDs);
}

auto SelectEventLayer::keyBackClicked() -> decltype(keyBackClicked()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&SelectEventLayer::keyBackClicked), this);
	using FunctionType = decltype(keyBackClicked())(*)(SelectEventLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c7764, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto SelectEventLayer::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCObject*>::func(&SelectEventLayer::onClose), this);
	using FunctionType = decltype(onClose(sender))(*)(SelectEventLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c76ac, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, sender);
}

auto SelectEventLayer::onCustomToggleTriggerValue(cocos2d::CCObject* sender) -> decltype(onCustomToggleTriggerValue(sender)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCObject*>::func(&SelectEventLayer::onCustomToggleTriggerValue), this);
	using FunctionType = decltype(onCustomToggleTriggerValue(sender))(*)(SelectEventLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c7478, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, sender);
}

auto SelectEventLayer::addToggle(int id, gd::string info) -> decltype(addToggle(id, info)) {
	using FunctionType = decltype(addToggle(id, info))(*)(SelectEventLayer*, int, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c6f20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, id, info);
}

auto SelectEventLayer::init(SetupEventLinkPopup* popup, gd::set<int>& eventIDs) -> decltype(init(popup, eventIDs)) {
	using FunctionType = decltype(init(popup, eventIDs))(*)(SelectEventLayer*, SetupEventLinkPopup*, gd::set<int>&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c59f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, popup, eventIDs);
}

auto SelectEventLayer::nextPosition() -> decltype(nextPosition()) {
	using FunctionType = decltype(nextPosition())(*)(SelectEventLayer*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c7788, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SelectEventLayer::onInfo(cocos2d::CCObject* sender) -> decltype(onInfo(sender)) {
	using FunctionType = decltype(onInfo(sender))(*)(SelectEventLayer*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x4c7894, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}
