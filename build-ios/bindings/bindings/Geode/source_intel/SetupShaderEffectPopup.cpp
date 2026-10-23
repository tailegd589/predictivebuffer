
#include <stdexcept>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>
#include <Geode/binding/SetupShaderEffectPopup.hpp>
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

SetupShaderEffectPopup::~SetupShaderEffectPopup() {
	// basically we destruct it once by calling the gd function,
	// then lock it, so that other gd destructors dont get called
	if (!geode::DestructorLock::isLocked(this)) {
		using FunctionType = void(*)(SetupShaderEffectPopup*);
		static auto func = wrapFunction<FunctionType>(base::get() + 0x2c5ac0, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) SetupShaderEffectPopup(geode::CutoffConstructor, sizeof(SetupShaderEffectPopup));
		geode::DestructorLock::addLock(this);
	}
}

auto SetupShaderEffectPopup::create(EffectGameObject* object, cocos2d::CCArray* objects, int id) -> decltype(create(object, objects, id)) {
	using FunctionType = decltype(create(object, objects, id))(*)(EffectGameObject*, cocos2d::CCArray*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2c5ec0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(object, objects, id);
}

auto SetupShaderEffectPopup::toggleGroup(int group, bool visible) -> decltype(toggleGroup(group, visible)) {
	auto self = addresser::thunkAdjust(Resolve<int, bool>::func(&SetupShaderEffectPopup::toggleGroup), this);
	using FunctionType = decltype(toggleGroup(group, visible))(*)(SetupShaderEffectPopup*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2d0980, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, group, visible);
}

auto SetupShaderEffectPopup::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCObject*>::func(&SetupShaderEffectPopup::onClose), this);
	using FunctionType = decltype(onClose(sender))(*)(SetupShaderEffectPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2d09c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, sender);
}

auto SetupShaderEffectPopup::updateDefaultTriggerValues() -> decltype(updateDefaultTriggerValues()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&SetupShaderEffectPopup::updateDefaultTriggerValues), this);
	using FunctionType = decltype(updateDefaultTriggerValues())(*)(SetupShaderEffectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2d0110, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto SetupShaderEffectPopup::valueDidChange(int tag, float value) -> decltype(valueDidChange(tag, value)) {
	auto self = addresser::thunkAdjust(Resolve<int, float>::func(&SetupShaderEffectPopup::valueDidChange), this);
	using FunctionType = decltype(valueDidChange(tag, value))(*)(SetupShaderEffectPopup*, int, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2d0650, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, tag, value);
}

auto SetupShaderEffectPopup::init(EffectGameObject* object, cocos2d::CCArray* objects, int id) -> decltype(init(object, objects, id)) {
	using FunctionType = decltype(init(object, objects, id))(*)(SetupShaderEffectPopup*, EffectGameObject*, cocos2d::CCArray*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2c6110, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, objects, id);
}

auto SetupShaderEffectPopup::onResetColors(cocos2d::CCObject* sender) -> decltype(onResetColors(sender)) {
	using FunctionType = decltype(onResetColors(sender))(*)(SetupShaderEffectPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2d05d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupShaderEffectPopup::onZLayer(cocos2d::CCObject* sender) -> decltype(onZLayer(sender)) {
	using FunctionType = decltype(onZLayer(sender))(*)(SetupShaderEffectPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2d0380, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupShaderEffectPopup::setupBulge() -> decltype(setupBulge()) {
	using FunctionType = decltype(setupBulge())(*)(SetupShaderEffectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2cc6b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupShaderEffectPopup::setupChromatic() -> decltype(setupChromatic()) {
	using FunctionType = decltype(setupChromatic())(*)(SetupShaderEffectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2c9200, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupShaderEffectPopup::setupChromaticGlitch() -> decltype(setupChromaticGlitch()) {
	using FunctionType = decltype(setupChromaticGlitch())(*)(SetupShaderEffectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2c9770, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupShaderEffectPopup::setupColorChange() -> decltype(setupColorChange()) {
	using FunctionType = decltype(setupColorChange())(*)(SetupShaderEffectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2ced30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupShaderEffectPopup::setupGlitch() -> decltype(setupGlitch()) {
	using FunctionType = decltype(setupGlitch())(*)(SetupShaderEffectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2c8b80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupShaderEffectPopup::setupGrayscale() -> decltype(setupGrayscale()) {
	using FunctionType = decltype(setupGrayscale())(*)(SetupShaderEffectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2cdc30, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupShaderEffectPopup::setupHueShift() -> decltype(setupHueShift()) {
	using FunctionType = decltype(setupHueShift())(*)(SetupShaderEffectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2cea20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupShaderEffectPopup::setupInvertColor() -> decltype(setupInvertColor()) {
	using FunctionType = decltype(setupInvertColor())(*)(SetupShaderEffectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2ce3d0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupShaderEffectPopup::setupLensCircle() -> decltype(setupLensCircle()) {
	using FunctionType = decltype(setupLensCircle())(*)(SetupShaderEffectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2ca650, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupShaderEffectPopup::setupMotionBlur() -> decltype(setupMotionBlur()) {
	using FunctionType = decltype(setupMotionBlur())(*)(SetupShaderEffectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2cba80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupShaderEffectPopup::setupPinch() -> decltype(setupPinch()) {
	using FunctionType = decltype(setupPinch())(*)(SetupShaderEffectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2ccfd0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupShaderEffectPopup::setupPixelate() -> decltype(setupPixelate()) {
	using FunctionType = decltype(setupPixelate())(*)(SetupShaderEffectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2c9f90, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupShaderEffectPopup::setupRadialBlur() -> decltype(setupRadialBlur()) {
	using FunctionType = decltype(setupRadialBlur())(*)(SetupShaderEffectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2cafe0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupShaderEffectPopup::setupSepia() -> decltype(setupSepia()) {
	using FunctionType = decltype(setupSepia())(*)(SetupShaderEffectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2ce110, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupShaderEffectPopup::setupShaderTrigger() -> decltype(setupShaderTrigger()) {
	using FunctionType = decltype(setupShaderTrigger())(*)(SetupShaderEffectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2cf860, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupShaderEffectPopup::setupShockLine() -> decltype(setupShockLine()) {
	using FunctionType = decltype(setupShockLine())(*)(SetupShaderEffectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2c7820, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupShaderEffectPopup::setupShockWave() -> decltype(setupShockWave()) {
	using FunctionType = decltype(setupShockWave())(*)(SetupShaderEffectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2c63b0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupShaderEffectPopup::setupSplitScreen() -> decltype(setupSplitScreen()) {
	using FunctionType = decltype(setupSplitScreen())(*)(SetupShaderEffectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2cf3c0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupShaderEffectPopup::updateZLayerButtons() -> decltype(updateZLayerButtons()) {
	using FunctionType = decltype(updateZLayerButtons())(*)(SetupShaderEffectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2d0510, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupShaderEffectPopup::zLayerToString(int zLayer) -> decltype(zLayerToString(zLayer)) {
	using FunctionType = decltype(zLayerToString(zLayer))(*)(SetupShaderEffectPopup*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2d0250, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, zLayer);
}
