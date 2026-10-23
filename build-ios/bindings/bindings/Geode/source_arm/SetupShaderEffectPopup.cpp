
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
		static auto func = wrapFunction<FunctionType>(base::get() + 0x261d84, tulip::hook::TulipConvention::Default);
		reinterpret_cast<FunctionType>(func)(this);

		// we need to construct it back so that it uhhh ummm doesnt crash
		// while going to the child destructors
		auto thing = new (this) SetupShaderEffectPopup(geode::CutoffConstructor, sizeof(SetupShaderEffectPopup));
		geode::DestructorLock::addLock(this);
	}
}

auto SetupShaderEffectPopup::create(EffectGameObject* object, cocos2d::CCArray* objects, int id) -> decltype(create(object, objects, id)) {
	using FunctionType = decltype(create(object, objects, id))(*)(EffectGameObject*, cocos2d::CCArray*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x262018, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(object, objects, id);
}

auto SetupShaderEffectPopup::toggleGroup(int group, bool visible) -> decltype(toggleGroup(group, visible)) {
	auto self = addresser::thunkAdjust(Resolve<int, bool>::func(&SetupShaderEffectPopup::toggleGroup), this);
	using FunctionType = decltype(toggleGroup(group, visible))(*)(SetupShaderEffectPopup*, int, bool);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26bd84, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, group, visible);
}

auto SetupShaderEffectPopup::onClose(cocos2d::CCObject* sender) -> decltype(onClose(sender)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCObject*>::func(&SetupShaderEffectPopup::onClose), this);
	using FunctionType = decltype(onClose(sender))(*)(SetupShaderEffectPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26bdc4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, sender);
}

auto SetupShaderEffectPopup::updateDefaultTriggerValues() -> decltype(updateDefaultTriggerValues()) {
	auto self = addresser::thunkAdjust(Resolve<>::func(&SetupShaderEffectPopup::updateDefaultTriggerValues), this);
	using FunctionType = decltype(updateDefaultTriggerValues())(*)(SetupShaderEffectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26b464, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self);
}

auto SetupShaderEffectPopup::valueDidChange(int tag, float value) -> decltype(valueDidChange(tag, value)) {
	auto self = addresser::thunkAdjust(Resolve<int, float>::func(&SetupShaderEffectPopup::valueDidChange), this);
	using FunctionType = decltype(valueDidChange(tag, value))(*)(SetupShaderEffectPopup*, int, float);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26ba54, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(self, tag, value);
}

auto SetupShaderEffectPopup::init(EffectGameObject* object, cocos2d::CCArray* objects, int id) -> decltype(init(object, objects, id)) {
	using FunctionType = decltype(init(object, objects, id))(*)(SetupShaderEffectPopup*, EffectGameObject*, cocos2d::CCArray*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2621b4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, object, objects, id);
}

auto SetupShaderEffectPopup::onResetColors(cocos2d::CCObject* sender) -> decltype(onResetColors(sender)) {
	using FunctionType = decltype(onResetColors(sender))(*)(SetupShaderEffectPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26b9e0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupShaderEffectPopup::onZLayer(cocos2d::CCObject* sender) -> decltype(onZLayer(sender)) {
	using FunctionType = decltype(onZLayer(sender))(*)(SetupShaderEffectPopup*, cocos2d::CCObject*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26b7a4, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, sender);
}

auto SetupShaderEffectPopup::setupBulge() -> decltype(setupBulge()) {
	using FunctionType = decltype(setupBulge())(*)(SetupShaderEffectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x267d80, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupShaderEffectPopup::setupChromatic() -> decltype(setupChromatic()) {
	using FunctionType = decltype(setupChromatic())(*)(SetupShaderEffectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x264d00, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupShaderEffectPopup::setupChromaticGlitch() -> decltype(setupChromaticGlitch()) {
	using FunctionType = decltype(setupChromaticGlitch())(*)(SetupShaderEffectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26525c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupShaderEffectPopup::setupColorChange() -> decltype(setupColorChange()) {
	using FunctionType = decltype(setupColorChange())(*)(SetupShaderEffectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26a128, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupShaderEffectPopup::setupGlitch() -> decltype(setupGlitch()) {
	using FunctionType = decltype(setupGlitch())(*)(SetupShaderEffectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2646a0, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupShaderEffectPopup::setupGrayscale() -> decltype(setupGrayscale()) {
	using FunctionType = decltype(setupGrayscale())(*)(SetupShaderEffectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x269088, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupShaderEffectPopup::setupHueShift() -> decltype(setupHueShift()) {
	using FunctionType = decltype(setupHueShift())(*)(SetupShaderEffectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x269e20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupShaderEffectPopup::setupInvertColor() -> decltype(setupInvertColor()) {
	using FunctionType = decltype(setupInvertColor())(*)(SetupShaderEffectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x269804, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupShaderEffectPopup::setupLensCircle() -> decltype(setupLensCircle()) {
	using FunctionType = decltype(setupLensCircle())(*)(SetupShaderEffectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x266088, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupShaderEffectPopup::setupMotionBlur() -> decltype(setupMotionBlur()) {
	using FunctionType = decltype(setupMotionBlur())(*)(SetupShaderEffectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26727c, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupShaderEffectPopup::setupPinch() -> decltype(setupPinch()) {
	using FunctionType = decltype(setupPinch())(*)(SetupShaderEffectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2685bc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupShaderEffectPopup::setupPixelate() -> decltype(setupPixelate()) {
	using FunctionType = decltype(setupPixelate())(*)(SetupShaderEffectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x265a08, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupShaderEffectPopup::setupRadialBlur() -> decltype(setupRadialBlur()) {
	using FunctionType = decltype(setupRadialBlur())(*)(SetupShaderEffectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x266918, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupShaderEffectPopup::setupSepia() -> decltype(setupSepia()) {
	using FunctionType = decltype(setupSepia())(*)(SetupShaderEffectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x269518, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupShaderEffectPopup::setupShaderTrigger() -> decltype(setupShaderTrigger()) {
	using FunctionType = decltype(setupShaderTrigger())(*)(SetupShaderEffectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26ac20, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupShaderEffectPopup::setupShockLine() -> decltype(setupShockLine()) {
	using FunctionType = decltype(setupShockLine())(*)(SetupShaderEffectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x2635bc, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupShaderEffectPopup::setupShockWave() -> decltype(setupShockWave()) {
	using FunctionType = decltype(setupShockWave())(*)(SetupShaderEffectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x262418, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupShaderEffectPopup::setupSplitScreen() -> decltype(setupSplitScreen()) {
	using FunctionType = decltype(setupSplitScreen())(*)(SetupShaderEffectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26a770, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupShaderEffectPopup::updateZLayerButtons() -> decltype(updateZLayerButtons()) {
	using FunctionType = decltype(updateZLayerButtons())(*)(SetupShaderEffectPopup*);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26b928, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this);
}

auto SetupShaderEffectPopup::zLayerToString(int zLayer) -> decltype(zLayerToString(zLayer)) {
	using FunctionType = decltype(zLayerToString(zLayer))(*)(SetupShaderEffectPopup*, int);
	static auto func = wrapFunction<FunctionType>(base::get() + 0x26b604, tulip::hook::TulipConvention::Default);
	return reinterpret_cast<FunctionType>(func)(this, zLayer);
}
