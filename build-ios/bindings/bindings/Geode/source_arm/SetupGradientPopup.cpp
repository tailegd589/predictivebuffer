
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/SetupGradientPopup.hpp>
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

SetupGradientPopup::~SetupGradientPopup() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(SetupGradientPopup*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x51ac40, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) SetupGradientPopup(geode::CutoffConstructor, sizeof(SetupGradientPopup));
		geode::DestructorLock::addLock(this);
	}
}

auto SetupGradientPopup::create(GradientTriggerObject* object, cocos2d::CCArray* objects) -> decltype(create(object, objects)) {
	using FunctionType = decltype(create(object, objects))(*)(GradientTriggerObject*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51aed4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(object, objects);
}

auto SetupGradientPopup::determineStartValues() -> decltype(determineStartValues()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&SetupGradientPopup::determineStartValues), this);
	using FunctionType = decltype(determineStartValues())(*)(SetupGradientPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51c6c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto SetupGradientPopup::onPlusButton(cocos2d::CCObject* sender) -> decltype(onPlusButton(sender)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCObject*>::func(&SetupGradientPopup::onPlusButton), this);
	using FunctionType = decltype(onPlusButton(sender))(*)(SetupGradientPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51c7f0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, sender);
}

auto SetupGradientPopup::updateToggleItem(int value, bool toggled) -> decltype(updateToggleItem(value, toggled)) {
	auto self = addresser::thunkAdjust(Resolve<int, bool>::func(&SetupGradientPopup::updateToggleItem), this);
	using FunctionType = decltype(updateToggleItem(value, toggled))(*)(SetupGradientPopup*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51c8a4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, value, toggled);
}

auto SetupGradientPopup::valueDidChange(int tag, float value) -> decltype(valueDidChange(tag, value)) {
	auto self = addresser::thunkAdjust(Resolve<int, float>::func(&SetupGradientPopup::valueDidChange), this);
	using FunctionType = decltype(valueDidChange(tag, value))(*)(SetupGradientPopup*, int, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51ca54, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, tag, value);
}

auto SetupGradientPopup::init(GradientTriggerObject* object, cocos2d::CCArray* objects) -> decltype(init(object, objects)) {
	using FunctionType = decltype(init(object, objects))(*)(SetupGradientPopup*, GradientTriggerObject*, cocos2d::CCArray*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51b06c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, objects);
}

auto SetupGradientPopup::onBlending(cocos2d::CCObject* sender) -> decltype(onBlending(sender)) {
	using FunctionType = decltype(onBlending(sender))(*)(SetupGradientPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51c414, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupGradientPopup::onZLayer(cocos2d::CCObject* sender) -> decltype(onZLayer(sender)) {
	using FunctionType = decltype(onZLayer(sender))(*)(SetupGradientPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51c544, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupGradientPopup::sliderChanged(cocos2d::CCObject* sender) -> decltype(sliderChanged(sender)) {
	using FunctionType = decltype(sliderChanged(sender))(*)(SetupGradientPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51c9b4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupGradientPopup::updateBlending() -> decltype(updateBlending()) {
	using FunctionType = decltype(updateBlending())(*)(SetupGradientPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51c9e4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupGradientPopup::updateBlendingLabel() -> decltype(updateBlendingLabel()) {
	using FunctionType = decltype(updateBlendingLabel())(*)(SetupGradientPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51c360, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupGradientPopup::updateGradientLabels(bool vertex) -> decltype(updateGradientLabels(vertex)) {
	using FunctionType = decltype(updateGradientLabels(vertex))(*)(SetupGradientPopup*, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51c260, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, vertex);
}

auto SetupGradientPopup::updateZLayerButtons() -> decltype(updateZLayerButtons()) {
	using FunctionType = decltype(updateZLayerButtons())(*)(SetupGradientPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x51c630, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}
