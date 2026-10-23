
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/SetupEventLinkPopup.hpp>
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

auto SetupEventLinkPopup::create(EventLinkTrigger* object, cocos2d::CCArray* objects) -> decltype(create(object, objects)) {
	using FunctionType = decltype(create(object, objects))(*)(EventLinkTrigger*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x577380, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(object, objects);
}

auto SetupEventLinkPopup::init(EventLinkTrigger* object, cocos2d::CCArray* objects) -> decltype(init(object, objects)) {
	using FunctionType = decltype(init(object, objects))(*)(SetupEventLinkPopup*, EventLinkTrigger*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x5775b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, objects);
}

auto SetupEventLinkPopup::onSelectEvent(cocos2d::CCObject* sender) -> decltype(onSelectEvent(sender)) {
	using FunctionType = decltype(onSelectEvent(sender))(*)(SetupEventLinkPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x577b20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupEventLinkPopup::updateEventIDs(gd::set<int>& eventIDs) -> decltype(updateEventIDs(eventIDs)) {
	using FunctionType = decltype(updateEventIDs(eventIDs))(*)(SetupEventLinkPopup*, gd::set<int>&);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x577e70, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, eventIDs);
}
