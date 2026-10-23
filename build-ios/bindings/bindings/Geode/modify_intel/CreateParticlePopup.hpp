#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <Geode/binding/CreateParticlePopup.hpp>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_create
		#define GEODE_STATICS_create
		GEODE_AS_STATIC_FUNCTION(create) 
	#endif

	#ifndef GEODE_STATICS_update
		#define GEODE_STATICS_update
		GEODE_AS_STATIC_FUNCTION(update) 
	#endif

	#ifndef GEODE_STATICS_ccTouchBegan
		#define GEODE_STATICS_ccTouchBegan
		GEODE_AS_STATIC_FUNCTION(ccTouchBegan) 
	#endif

	#ifndef GEODE_STATICS_ccTouchMoved
		#define GEODE_STATICS_ccTouchMoved
		GEODE_AS_STATIC_FUNCTION(ccTouchMoved) 
	#endif

	#ifndef GEODE_STATICS_ccTouchEnded
		#define GEODE_STATICS_ccTouchEnded
		GEODE_AS_STATIC_FUNCTION(ccTouchEnded) 
	#endif

	#ifndef GEODE_STATICS_ccTouchCancelled
		#define GEODE_STATICS_ccTouchCancelled
		GEODE_AS_STATIC_FUNCTION(ccTouchCancelled) 
	#endif

	#ifndef GEODE_STATICS_keyBackClicked
		#define GEODE_STATICS_keyBackClicked
		GEODE_AS_STATIC_FUNCTION(keyBackClicked) 
	#endif

	#ifndef GEODE_STATICS_sliderBegan
		#define GEODE_STATICS_sliderBegan
		GEODE_AS_STATIC_FUNCTION(sliderBegan) 
	#endif

	#ifndef GEODE_STATICS_sliderEnded
		#define GEODE_STATICS_sliderEnded
		GEODE_AS_STATIC_FUNCTION(sliderEnded) 
	#endif

	#ifndef GEODE_STATICS_colorSelectClosed
		#define GEODE_STATICS_colorSelectClosed
		GEODE_AS_STATIC_FUNCTION(colorSelectClosed) 
	#endif

	#ifndef GEODE_STATICS_textInputShouldOffset
		#define GEODE_STATICS_textInputShouldOffset
		GEODE_AS_STATIC_FUNCTION(textInputShouldOffset) 
	#endif

	#ifndef GEODE_STATICS_textInputReturn
		#define GEODE_STATICS_textInputReturn
		GEODE_AS_STATIC_FUNCTION(textInputReturn) 
	#endif

	#ifndef GEODE_STATICS_textInputClosed
		#define GEODE_STATICS_textInputClosed
		GEODE_AS_STATIC_FUNCTION(textInputClosed) 
	#endif

	#ifndef GEODE_STATICS_textChanged
		#define GEODE_STATICS_textChanged
		GEODE_AS_STATIC_FUNCTION(textChanged) 
	#endif

	#ifndef GEODE_STATICS_centerAlignParticle
		#define GEODE_STATICS_centerAlignParticle
		GEODE_AS_STATIC_FUNCTION(centerAlignParticle) 
	#endif

	#ifndef GEODE_STATICS_createParticleSlider
		#define GEODE_STATICS_createParticleSlider
		GEODE_AS_STATIC_FUNCTION(createParticleSlider) 
	#endif

	#ifndef GEODE_STATICS_getPage
		#define GEODE_STATICS_getPage
		GEODE_AS_STATIC_FUNCTION(getPage) 
	#endif

	#ifndef GEODE_STATICS_getPageButton
		#define GEODE_STATICS_getPageButton
		GEODE_AS_STATIC_FUNCTION(getPageButton) 
	#endif

	#ifndef GEODE_STATICS_getPageContainer
		#define GEODE_STATICS_getPageContainer
		GEODE_AS_STATIC_FUNCTION(getPageContainer) 
	#endif

	#ifndef GEODE_STATICS_getPageInputNodes
		#define GEODE_STATICS_getPageInputNodes
		GEODE_AS_STATIC_FUNCTION(getPageInputNodes) 
	#endif

	#ifndef GEODE_STATICS_getPageMenu
		#define GEODE_STATICS_getPageMenu
		GEODE_AS_STATIC_FUNCTION(getPageMenu) 
	#endif

	#ifndef GEODE_STATICS_getPageSliders
		#define GEODE_STATICS_getPageSliders
		GEODE_AS_STATIC_FUNCTION(getPageSliders) 
	#endif

	#ifndef GEODE_STATICS_init
		#define GEODE_STATICS_init
		GEODE_AS_STATIC_FUNCTION(init) 
	#endif

	#ifndef GEODE_STATICS_maxSliderValueForType
		#define GEODE_STATICS_maxSliderValueForType
		GEODE_AS_STATIC_FUNCTION(maxSliderValueForType) 
	#endif

	#ifndef GEODE_STATICS_minSliderValueForType
		#define GEODE_STATICS_minSliderValueForType
		GEODE_AS_STATIC_FUNCTION(minSliderValueForType) 
	#endif

	#ifndef GEODE_STATICS_onAnimateActiveOnly
		#define GEODE_STATICS_onAnimateActiveOnly
		GEODE_AS_STATIC_FUNCTION(onAnimateActiveOnly) 
	#endif

	#ifndef GEODE_STATICS_onAnimateOnTrigger
		#define GEODE_STATICS_onAnimateOnTrigger
		GEODE_AS_STATIC_FUNCTION(onAnimateOnTrigger) 
	#endif

	#ifndef GEODE_STATICS_onCalcEmission
		#define GEODE_STATICS_onCalcEmission
		GEODE_AS_STATIC_FUNCTION(onCalcEmission) 
	#endif

	#ifndef GEODE_STATICS_onClose
		#define GEODE_STATICS_onClose
		GEODE_AS_STATIC_FUNCTION(onClose) 
	#endif

	#ifndef GEODE_STATICS_onCopySettings
		#define GEODE_STATICS_onCopySettings
		GEODE_AS_STATIC_FUNCTION(onCopySettings) 
	#endif

	#ifndef GEODE_STATICS_onDuplicateColor
		#define GEODE_STATICS_onDuplicateColor
		GEODE_AS_STATIC_FUNCTION(onDuplicateColor) 
	#endif

	#ifndef GEODE_STATICS_onDurationForever
		#define GEODE_STATICS_onDurationForever
		GEODE_AS_STATIC_FUNCTION(onDurationForever) 
	#endif

	#ifndef GEODE_STATICS_onDynamicColor
		#define GEODE_STATICS_onDynamicColor
		GEODE_AS_STATIC_FUNCTION(onDynamicColor) 
	#endif

	#ifndef GEODE_STATICS_onDynamicRotation
		#define GEODE_STATICS_onDynamicRotation
		GEODE_AS_STATIC_FUNCTION(onDynamicRotation) 
	#endif

	#ifndef GEODE_STATICS_onEmitterMode
		#define GEODE_STATICS_onEmitterMode
		GEODE_AS_STATIC_FUNCTION(onEmitterMode) 
	#endif

	#ifndef GEODE_STATICS_onEndRGBVarSync
		#define GEODE_STATICS_onEndRGBVarSync
		GEODE_AS_STATIC_FUNCTION(onEndRGBVarSync) 
	#endif

	#ifndef GEODE_STATICS_onMaxEmission
		#define GEODE_STATICS_onMaxEmission
		GEODE_AS_STATIC_FUNCTION(onMaxEmission) 
	#endif

	#ifndef GEODE_STATICS_onMode
		#define GEODE_STATICS_onMode
		GEODE_AS_STATIC_FUNCTION(onMode) 
	#endif

	#ifndef GEODE_STATICS_onOrderSensitive
		#define GEODE_STATICS_onOrderSensitive
		GEODE_AS_STATIC_FUNCTION(onOrderSensitive) 
	#endif

	#ifndef GEODE_STATICS_onPage
		#define GEODE_STATICS_onPage
		GEODE_AS_STATIC_FUNCTION(onPage) 
	#endif

	#ifndef GEODE_STATICS_onPasteSettings
		#define GEODE_STATICS_onPasteSettings
		GEODE_AS_STATIC_FUNCTION(onPasteSettings) 
	#endif

	#ifndef GEODE_STATICS_onPosType
		#define GEODE_STATICS_onPosType
		GEODE_AS_STATIC_FUNCTION(onPosType) 
	#endif

	#ifndef GEODE_STATICS_onQuickStart
		#define GEODE_STATICS_onQuickStart
		GEODE_AS_STATIC_FUNCTION(onQuickStart) 
	#endif

	#ifndef GEODE_STATICS_onSelectColor
		#define GEODE_STATICS_onSelectColor
		GEODE_AS_STATIC_FUNCTION(onSelectColor) 
	#endif

	#ifndef GEODE_STATICS_onSelectParticleTexture
		#define GEODE_STATICS_onSelectParticleTexture
		GEODE_AS_STATIC_FUNCTION(onSelectParticleTexture) 
	#endif

	#ifndef GEODE_STATICS_onStartRGBVarSync
		#define GEODE_STATICS_onStartRGBVarSync
		GEODE_AS_STATIC_FUNCTION(onStartRGBVarSync) 
	#endif

	#ifndef GEODE_STATICS_onToggleBlending
		#define GEODE_STATICS_onToggleBlending
		GEODE_AS_STATIC_FUNCTION(onToggleBlending) 
	#endif

	#ifndef GEODE_STATICS_onTogglePerfLog
		#define GEODE_STATICS_onTogglePerfLog
		GEODE_AS_STATIC_FUNCTION(onTogglePerfLog) 
	#endif

	#ifndef GEODE_STATICS_onToggleStartRadiusEqualToEnd
		#define GEODE_STATICS_onToggleStartRadiusEqualToEnd
		GEODE_AS_STATIC_FUNCTION(onToggleStartRadiusEqualToEnd) 
	#endif

	#ifndef GEODE_STATICS_onToggleStartRotationIsDir
		#define GEODE_STATICS_onToggleStartRotationIsDir
		GEODE_AS_STATIC_FUNCTION(onToggleStartRotationIsDir) 
	#endif

	#ifndef GEODE_STATICS_onToggleStartSizeEqualToEnd
		#define GEODE_STATICS_onToggleStartSizeEqualToEnd
		GEODE_AS_STATIC_FUNCTION(onToggleStartSizeEqualToEnd) 
	#endif

	#ifndef GEODE_STATICS_onToggleStartSpinEqualToEnd
		#define GEODE_STATICS_onToggleStartSpinEqualToEnd
		GEODE_AS_STATIC_FUNCTION(onToggleStartSpinEqualToEnd) 
	#endif

	#ifndef GEODE_STATICS_onUniformColor
		#define GEODE_STATICS_onUniformColor
		GEODE_AS_STATIC_FUNCTION(onUniformColor) 
	#endif

	#ifndef GEODE_STATICS_particleValueIsInt
		#define GEODE_STATICS_particleValueIsInt
		GEODE_AS_STATIC_FUNCTION(particleValueIsInt) 
	#endif

	#ifndef GEODE_STATICS_sliderChanged
		#define GEODE_STATICS_sliderChanged
		GEODE_AS_STATIC_FUNCTION(sliderChanged) 
	#endif

	#ifndef GEODE_STATICS_titleForParticleValue
		#define GEODE_STATICS_titleForParticleValue
		GEODE_AS_STATIC_FUNCTION(titleForParticleValue) 
	#endif

	#ifndef GEODE_STATICS_toggleGravityMode
		#define GEODE_STATICS_toggleGravityMode
		GEODE_AS_STATIC_FUNCTION(toggleGravityMode) 
	#endif

	#ifndef GEODE_STATICS_updateColorSprite
		#define GEODE_STATICS_updateColorSprite
		GEODE_AS_STATIC_FUNCTION(updateColorSprite) 
	#endif

	#ifndef GEODE_STATICS_updateInputNodeStringForType
		#define GEODE_STATICS_updateInputNodeStringForType
		GEODE_AS_STATIC_FUNCTION(updateInputNodeStringForType) 
	#endif

	#ifndef GEODE_STATICS_updateParticleValueForType
		#define GEODE_STATICS_updateParticleValueForType
		GEODE_AS_STATIC_FUNCTION(updateParticleValueForType) 
	#endif

	#ifndef GEODE_STATICS_updateSliderForType
		#define GEODE_STATICS_updateSliderForType
		GEODE_AS_STATIC_FUNCTION(updateSliderForType) 
	#endif

	#ifndef GEODE_STATICS_valueForParticleValue
		#define GEODE_STATICS_valueForParticleValue
		GEODE_AS_STATIC_FUNCTION(valueForParticleValue) 
	#endif

	#ifndef GEODE_STATICS_willClose
		#define GEODE_STATICS_willClose
		GEODE_AS_STATIC_FUNCTION(willClose) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_update
		#define GEODE_CONCEPT_CHECK_update
		GEODE_CONCEPT_FUNCTION_CHECK(update) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_ccTouchBegan
		#define GEODE_CONCEPT_CHECK_ccTouchBegan
		GEODE_CONCEPT_FUNCTION_CHECK(ccTouchBegan) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_ccTouchMoved
		#define GEODE_CONCEPT_CHECK_ccTouchMoved
		GEODE_CONCEPT_FUNCTION_CHECK(ccTouchMoved) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_ccTouchEnded
		#define GEODE_CONCEPT_CHECK_ccTouchEnded
		GEODE_CONCEPT_FUNCTION_CHECK(ccTouchEnded) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_ccTouchCancelled
		#define GEODE_CONCEPT_CHECK_ccTouchCancelled
		GEODE_CONCEPT_FUNCTION_CHECK(ccTouchCancelled) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_keyBackClicked
		#define GEODE_CONCEPT_CHECK_keyBackClicked
		GEODE_CONCEPT_FUNCTION_CHECK(keyBackClicked) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_sliderBegan
		#define GEODE_CONCEPT_CHECK_sliderBegan
		GEODE_CONCEPT_FUNCTION_CHECK(sliderBegan) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_sliderEnded
		#define GEODE_CONCEPT_CHECK_sliderEnded
		GEODE_CONCEPT_FUNCTION_CHECK(sliderEnded) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_colorSelectClosed
		#define GEODE_CONCEPT_CHECK_colorSelectClosed
		GEODE_CONCEPT_FUNCTION_CHECK(colorSelectClosed) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_textInputShouldOffset
		#define GEODE_CONCEPT_CHECK_textInputShouldOffset
		GEODE_CONCEPT_FUNCTION_CHECK(textInputShouldOffset) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_textInputReturn
		#define GEODE_CONCEPT_CHECK_textInputReturn
		GEODE_CONCEPT_FUNCTION_CHECK(textInputReturn) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_textInputClosed
		#define GEODE_CONCEPT_CHECK_textInputClosed
		GEODE_CONCEPT_FUNCTION_CHECK(textInputClosed) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_textChanged
		#define GEODE_CONCEPT_CHECK_textChanged
		GEODE_CONCEPT_FUNCTION_CHECK(textChanged) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_centerAlignParticle
		#define GEODE_CONCEPT_CHECK_centerAlignParticle
		GEODE_CONCEPT_FUNCTION_CHECK(centerAlignParticle) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_createParticleSlider
		#define GEODE_CONCEPT_CHECK_createParticleSlider
		GEODE_CONCEPT_FUNCTION_CHECK(createParticleSlider) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getPage
		#define GEODE_CONCEPT_CHECK_getPage
		GEODE_CONCEPT_FUNCTION_CHECK(getPage) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getPageButton
		#define GEODE_CONCEPT_CHECK_getPageButton
		GEODE_CONCEPT_FUNCTION_CHECK(getPageButton) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getPageContainer
		#define GEODE_CONCEPT_CHECK_getPageContainer
		GEODE_CONCEPT_FUNCTION_CHECK(getPageContainer) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getPageInputNodes
		#define GEODE_CONCEPT_CHECK_getPageInputNodes
		GEODE_CONCEPT_FUNCTION_CHECK(getPageInputNodes) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getPageMenu
		#define GEODE_CONCEPT_CHECK_getPageMenu
		GEODE_CONCEPT_FUNCTION_CHECK(getPageMenu) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getPageSliders
		#define GEODE_CONCEPT_CHECK_getPageSliders
		GEODE_CONCEPT_FUNCTION_CHECK(getPageSliders) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_init
		#define GEODE_CONCEPT_CHECK_init
		GEODE_CONCEPT_FUNCTION_CHECK(init) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_maxSliderValueForType
		#define GEODE_CONCEPT_CHECK_maxSliderValueForType
		GEODE_CONCEPT_FUNCTION_CHECK(maxSliderValueForType) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_minSliderValueForType
		#define GEODE_CONCEPT_CHECK_minSliderValueForType
		GEODE_CONCEPT_FUNCTION_CHECK(minSliderValueForType) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onAnimateActiveOnly
		#define GEODE_CONCEPT_CHECK_onAnimateActiveOnly
		GEODE_CONCEPT_FUNCTION_CHECK(onAnimateActiveOnly) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onAnimateOnTrigger
		#define GEODE_CONCEPT_CHECK_onAnimateOnTrigger
		GEODE_CONCEPT_FUNCTION_CHECK(onAnimateOnTrigger) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onCalcEmission
		#define GEODE_CONCEPT_CHECK_onCalcEmission
		GEODE_CONCEPT_FUNCTION_CHECK(onCalcEmission) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onClose
		#define GEODE_CONCEPT_CHECK_onClose
		GEODE_CONCEPT_FUNCTION_CHECK(onClose) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onCopySettings
		#define GEODE_CONCEPT_CHECK_onCopySettings
		GEODE_CONCEPT_FUNCTION_CHECK(onCopySettings) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onDuplicateColor
		#define GEODE_CONCEPT_CHECK_onDuplicateColor
		GEODE_CONCEPT_FUNCTION_CHECK(onDuplicateColor) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onDurationForever
		#define GEODE_CONCEPT_CHECK_onDurationForever
		GEODE_CONCEPT_FUNCTION_CHECK(onDurationForever) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onDynamicColor
		#define GEODE_CONCEPT_CHECK_onDynamicColor
		GEODE_CONCEPT_FUNCTION_CHECK(onDynamicColor) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onDynamicRotation
		#define GEODE_CONCEPT_CHECK_onDynamicRotation
		GEODE_CONCEPT_FUNCTION_CHECK(onDynamicRotation) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onEmitterMode
		#define GEODE_CONCEPT_CHECK_onEmitterMode
		GEODE_CONCEPT_FUNCTION_CHECK(onEmitterMode) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onEndRGBVarSync
		#define GEODE_CONCEPT_CHECK_onEndRGBVarSync
		GEODE_CONCEPT_FUNCTION_CHECK(onEndRGBVarSync) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onMaxEmission
		#define GEODE_CONCEPT_CHECK_onMaxEmission
		GEODE_CONCEPT_FUNCTION_CHECK(onMaxEmission) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onMode
		#define GEODE_CONCEPT_CHECK_onMode
		GEODE_CONCEPT_FUNCTION_CHECK(onMode) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onOrderSensitive
		#define GEODE_CONCEPT_CHECK_onOrderSensitive
		GEODE_CONCEPT_FUNCTION_CHECK(onOrderSensitive) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onPage
		#define GEODE_CONCEPT_CHECK_onPage
		GEODE_CONCEPT_FUNCTION_CHECK(onPage) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onPasteSettings
		#define GEODE_CONCEPT_CHECK_onPasteSettings
		GEODE_CONCEPT_FUNCTION_CHECK(onPasteSettings) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onPosType
		#define GEODE_CONCEPT_CHECK_onPosType
		GEODE_CONCEPT_FUNCTION_CHECK(onPosType) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onQuickStart
		#define GEODE_CONCEPT_CHECK_onQuickStart
		GEODE_CONCEPT_FUNCTION_CHECK(onQuickStart) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onSelectColor
		#define GEODE_CONCEPT_CHECK_onSelectColor
		GEODE_CONCEPT_FUNCTION_CHECK(onSelectColor) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onSelectParticleTexture
		#define GEODE_CONCEPT_CHECK_onSelectParticleTexture
		GEODE_CONCEPT_FUNCTION_CHECK(onSelectParticleTexture) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onStartRGBVarSync
		#define GEODE_CONCEPT_CHECK_onStartRGBVarSync
		GEODE_CONCEPT_FUNCTION_CHECK(onStartRGBVarSync) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onToggleBlending
		#define GEODE_CONCEPT_CHECK_onToggleBlending
		GEODE_CONCEPT_FUNCTION_CHECK(onToggleBlending) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onTogglePerfLog
		#define GEODE_CONCEPT_CHECK_onTogglePerfLog
		GEODE_CONCEPT_FUNCTION_CHECK(onTogglePerfLog) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onToggleStartRadiusEqualToEnd
		#define GEODE_CONCEPT_CHECK_onToggleStartRadiusEqualToEnd
		GEODE_CONCEPT_FUNCTION_CHECK(onToggleStartRadiusEqualToEnd) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onToggleStartRotationIsDir
		#define GEODE_CONCEPT_CHECK_onToggleStartRotationIsDir
		GEODE_CONCEPT_FUNCTION_CHECK(onToggleStartRotationIsDir) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onToggleStartSizeEqualToEnd
		#define GEODE_CONCEPT_CHECK_onToggleStartSizeEqualToEnd
		GEODE_CONCEPT_FUNCTION_CHECK(onToggleStartSizeEqualToEnd) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onToggleStartSpinEqualToEnd
		#define GEODE_CONCEPT_CHECK_onToggleStartSpinEqualToEnd
		GEODE_CONCEPT_FUNCTION_CHECK(onToggleStartSpinEqualToEnd) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onUniformColor
		#define GEODE_CONCEPT_CHECK_onUniformColor
		GEODE_CONCEPT_FUNCTION_CHECK(onUniformColor) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_particleValueIsInt
		#define GEODE_CONCEPT_CHECK_particleValueIsInt
		GEODE_CONCEPT_FUNCTION_CHECK(particleValueIsInt) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_sliderChanged
		#define GEODE_CONCEPT_CHECK_sliderChanged
		GEODE_CONCEPT_FUNCTION_CHECK(sliderChanged) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_titleForParticleValue
		#define GEODE_CONCEPT_CHECK_titleForParticleValue
		GEODE_CONCEPT_FUNCTION_CHECK(titleForParticleValue) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_toggleGravityMode
		#define GEODE_CONCEPT_CHECK_toggleGravityMode
		GEODE_CONCEPT_FUNCTION_CHECK(toggleGravityMode) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_updateColorSprite
		#define GEODE_CONCEPT_CHECK_updateColorSprite
		GEODE_CONCEPT_FUNCTION_CHECK(updateColorSprite) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_updateInputNodeStringForType
		#define GEODE_CONCEPT_CHECK_updateInputNodeStringForType
		GEODE_CONCEPT_FUNCTION_CHECK(updateInputNodeStringForType) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_updateParticleValueForType
		#define GEODE_CONCEPT_CHECK_updateParticleValueForType
		GEODE_CONCEPT_FUNCTION_CHECK(updateParticleValueForType) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_updateSliderForType
		#define GEODE_CONCEPT_CHECK_updateSliderForType
		GEODE_CONCEPT_FUNCTION_CHECK(updateSliderForType) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_valueForParticleValue
		#define GEODE_CONCEPT_CHECK_valueForParticleValue
		GEODE_CONCEPT_FUNCTION_CHECK(valueForParticleValue) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_willClose
		#define GEODE_CONCEPT_CHECK_willClose
		GEODE_CONCEPT_FUNCTION_CHECK(willClose) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, CreateParticlePopup> : ModifyBase<ModifyDerive<Der, CreateParticlePopup>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, CreateParticlePopup>>;
		using ModifyBase<ModifyDerive<Der, CreateParticlePopup>>::ModifyBase;
		using Base = CreateParticlePopup;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x46e820, Default, CreateParticlePopup, create, gd::string)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x46e590, Default, CreateParticlePopup, create, ParticleGameObject*, cocos2d::CCArray*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x46e5b0, Default, CreateParticlePopup, create, ParticleGameObject*, cocos2d::CCArray*, gd::string)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4764f0, Default, CreateParticlePopup, update, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x477120, Default, CreateParticlePopup, ccTouchBegan, cocos2d::CCTouch*, cocos2d::CCEvent*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x477230, Default, CreateParticlePopup, ccTouchMoved, cocos2d::CCTouch*, cocos2d::CCEvent*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x477610, Default, CreateParticlePopup, ccTouchEnded, cocos2d::CCTouch*, cocos2d::CCEvent*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x477660, Default, CreateParticlePopup, ccTouchCancelled, cocos2d::CCTouch*, cocos2d::CCEvent*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x476f80, Default, CreateParticlePopup, keyBackClicked, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x476e40, Default, CreateParticlePopup, sliderBegan, Slider*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x476f20, Default, CreateParticlePopup, sliderEnded, Slider*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x476210, Default, CreateParticlePopup, colorSelectClosed, cocos2d::CCNode*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x476fb0, Default, CreateParticlePopup, textInputShouldOffset, CCTextInputNode*, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x477070, Default, CreateParticlePopup, textInputReturn, CCTextInputNode*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x476710, Default, CreateParticlePopup, textInputClosed, CCTextInputNode*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x476750, Default, CreateParticlePopup, textChanged, CCTextInputNode*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x473470, Default, CreateParticlePopup, centerAlignParticle, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x473bb0, Default, CreateParticlePopup, createParticleSlider, gjParticleValue, int, bool, cocos2d::CCPoint, cocos2d::CCArray*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x473830, Default, CreateParticlePopup, getPage, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x474b70, Default, CreateParticlePopup, getPageButton, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x473850, Default, CreateParticlePopup, getPageContainer, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x473b70, Default, CreateParticlePopup, getPageInputNodes, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x473820, Default, CreateParticlePopup, getPageMenu, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x473b90, Default, CreateParticlePopup, getPageSliders, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x46e8a0, Default, CreateParticlePopup, init, ParticleGameObject*, cocos2d::CCArray*, gd::string)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x476e10, Default, CreateParticlePopup, maxSliderValueForType, gjParticleValue)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x476df0, Default, CreateParticlePopup, minSliderValueForType, gjParticleValue)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4746b0, Default, CreateParticlePopup, onAnimateActiveOnly, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x474620, Default, CreateParticlePopup, onAnimateOnTrigger, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x475450, Default, CreateParticlePopup, onCalcEmission, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x473000, Default, CreateParticlePopup, onClose, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4731d0, Default, CreateParticlePopup, onCopySettings, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x473a40, Default, CreateParticlePopup, onDuplicateColor, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4753b0, Default, CreateParticlePopup, onDurationForever, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4747d0, Default, CreateParticlePopup, onDynamicColor, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4745f0, Default, CreateParticlePopup, onDynamicRotation, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x473870, Default, CreateParticlePopup, onEmitterMode, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x474a10, Default, CreateParticlePopup, onEndRGBVarSync, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x475400, Default, CreateParticlePopup, onMaxEmission, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4733b0, Default, CreateParticlePopup, onMode, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4749b0, Default, CreateParticlePopup, onOrderSensitive, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4735a0, Default, CreateParticlePopup, onPage, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4732f0, Default, CreateParticlePopup, onPasteSettings, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4737a0, Default, CreateParticlePopup, onPosType, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x474740, Default, CreateParticlePopup, onQuickStart, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4734c0, Default, CreateParticlePopup, onSelectColor, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x474a40, Default, CreateParticlePopup, onSelectParticleTexture, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4749e0, Default, CreateParticlePopup, onStartRGBVarSync, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4744e0, Default, CreateParticlePopup, onToggleBlending, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4738f0, Default, CreateParticlePopup, onTogglePerfLog, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x474580, Default, CreateParticlePopup, onToggleStartRadiusEqualToEnd, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4745b0, Default, CreateParticlePopup, onToggleStartRotationIsDir, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x474520, Default, CreateParticlePopup, onToggleStartSizeEqualToEnd, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x474550, Default, CreateParticlePopup, onToggleStartSpinEqualToEnd, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4748d0, Default, CreateParticlePopup, onUniformColor, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x476f60, Default, CreateParticlePopup, particleValueIsInt, gjParticleValue)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4751f0, Default, CreateParticlePopup, sliderChanged, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x474fd0, Default, CreateParticlePopup, titleForParticleValue, gjParticleValue)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x474b90, Default, CreateParticlePopup, toggleGravityMode, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x473950, Default, CreateParticlePopup, updateColorSprite, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x475010, Default, CreateParticlePopup, updateInputNodeStringForType, gjParticleValue)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x475500, Default, CreateParticlePopup, updateParticleValueForType, float, gjParticleValue, cocos2d::CCParticleSystemQuad*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4752e0, Default, CreateParticlePopup, updateSliderForType, gjParticleValue)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x476830, Default, CreateParticlePopup, valueForParticleValue, gjParticleValue)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4761a0, Default, CreateParticlePopup, willClose, )
		}
	};
}
