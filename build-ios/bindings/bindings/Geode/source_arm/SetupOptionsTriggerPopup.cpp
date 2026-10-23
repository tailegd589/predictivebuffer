
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/SetupOptionsTriggerPopup.hpp>
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

SetupOptionsTriggerPopup::SetupOptionsTriggerPopup() : SetupOptionsTriggerPopup(geode::CutoffConstructor, sizeof(SetupOptionsTriggerPopup)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	geode::DestructorLock::addLock(this);
	SetupOptionsTriggerPopup::~SetupOptionsTriggerPopup();

	using FunctionType = void(*)(SetupOptionsTriggerPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x511fdc, tulip::hook::TulipConvention::Default);
	reinterpret_cast<FunctionType>(func)(this);
}

auto SetupOptionsTriggerPopup::create(GameOptionsTrigger* object, cocos2d::CCArray* objects) -> decltype(create(object, objects)) {
	using FunctionType = decltype(create(object, objects))(*)(GameOptionsTrigger*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51149c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(object, objects);
}

auto SetupOptionsTriggerPopup::onCustomToggleTriggerValue(cocos2d::CCObject* sender) -> decltype(onCustomToggleTriggerValue(sender)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCObject*>::func(&SetupOptionsTriggerPopup::onCustomToggleTriggerValue), this);
	using FunctionType = decltype(onCustomToggleTriggerValue(sender))(*)(SetupOptionsTriggerPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x511f28, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, sender);
}

auto SetupOptionsTriggerPopup::addOption(int property, gd::string label) -> decltype(addOption(property, label)) {
	using FunctionType = decltype(addOption(property, label))(*)(SetupOptionsTriggerPopup*, int, gd::string);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x511cf4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, property, label);
}

auto SetupOptionsTriggerPopup::init(GameOptionsTrigger* object, cocos2d::CCArray* objects) -> decltype(init(object, objects)) {
	using FunctionType = decltype(init(object, objects))(*)(SetupOptionsTriggerPopup*, GameOptionsTrigger*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x511530, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, objects);
}
