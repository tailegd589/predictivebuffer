#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <cocos-ext.h>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_create
		#define GEODE_STATICS_create
		GEODE_AS_STATIC_FUNCTION(create) 
	#endif

	#ifndef GEODE_STATICS_setWraps
		#define GEODE_STATICS_setWraps
		GEODE_AS_STATIC_FUNCTION(setWraps) 
	#endif

	#ifndef GEODE_STATICS_setMinimumValue
		#define GEODE_STATICS_setMinimumValue
		GEODE_AS_STATIC_FUNCTION(setMinimumValue) 
	#endif

	#ifndef GEODE_STATICS_setMaximumValue
		#define GEODE_STATICS_setMaximumValue
		GEODE_AS_STATIC_FUNCTION(setMaximumValue) 
	#endif

	#ifndef GEODE_STATICS_setValue
		#define GEODE_STATICS_setValue
		GEODE_AS_STATIC_FUNCTION(setValue) 
	#endif

	#ifndef GEODE_STATICS_getValue
		#define GEODE_STATICS_getValue
		GEODE_AS_STATIC_FUNCTION(getValue) 
	#endif

	#ifndef GEODE_STATICS_setStepValue
		#define GEODE_STATICS_setStepValue
		GEODE_AS_STATIC_FUNCTION(setStepValue) 
	#endif

	#ifndef GEODE_STATICS_setValueWithSendingEvent
		#define GEODE_STATICS_setValueWithSendingEvent
		GEODE_AS_STATIC_FUNCTION(setValueWithSendingEvent) 
	#endif

	#ifndef GEODE_STATICS_isContinuous
		#define GEODE_STATICS_isContinuous
		GEODE_AS_STATIC_FUNCTION(isContinuous) 
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

	#ifndef GEODE_STATICS_initWithMinusSpriteAndPlusSprite
		#define GEODE_STATICS_initWithMinusSpriteAndPlusSprite
		GEODE_AS_STATIC_FUNCTION(initWithMinusSpriteAndPlusSprite) 
	#endif

	#ifndef GEODE_STATICS_startAutorepeat
		#define GEODE_STATICS_startAutorepeat
		GEODE_AS_STATIC_FUNCTION(startAutorepeat) 
	#endif

	#ifndef GEODE_STATICS_stopAutorepeat
		#define GEODE_STATICS_stopAutorepeat
		GEODE_AS_STATIC_FUNCTION(stopAutorepeat) 
	#endif

	#ifndef GEODE_STATICS_updateLayoutUsingTouchLocation
		#define GEODE_STATICS_updateLayoutUsingTouchLocation
		GEODE_AS_STATIC_FUNCTION(updateLayoutUsingTouchLocation) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setWraps
		#define GEODE_CONCEPT_CHECK_setWraps
		GEODE_CONCEPT_FUNCTION_CHECK(setWraps) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setMinimumValue
		#define GEODE_CONCEPT_CHECK_setMinimumValue
		GEODE_CONCEPT_FUNCTION_CHECK(setMinimumValue) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setMaximumValue
		#define GEODE_CONCEPT_CHECK_setMaximumValue
		GEODE_CONCEPT_FUNCTION_CHECK(setMaximumValue) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setValue
		#define GEODE_CONCEPT_CHECK_setValue
		GEODE_CONCEPT_FUNCTION_CHECK(setValue) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getValue
		#define GEODE_CONCEPT_CHECK_getValue
		GEODE_CONCEPT_FUNCTION_CHECK(getValue) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setStepValue
		#define GEODE_CONCEPT_CHECK_setStepValue
		GEODE_CONCEPT_FUNCTION_CHECK(setStepValue) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setValueWithSendingEvent
		#define GEODE_CONCEPT_CHECK_setValueWithSendingEvent
		GEODE_CONCEPT_FUNCTION_CHECK(setValueWithSendingEvent) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_isContinuous
		#define GEODE_CONCEPT_CHECK_isContinuous
		GEODE_CONCEPT_FUNCTION_CHECK(isContinuous) 
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

	#ifndef GEODE_CONCEPT_CHECK_initWithMinusSpriteAndPlusSprite
		#define GEODE_CONCEPT_CHECK_initWithMinusSpriteAndPlusSprite
		GEODE_CONCEPT_FUNCTION_CHECK(initWithMinusSpriteAndPlusSprite) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_startAutorepeat
		#define GEODE_CONCEPT_CHECK_startAutorepeat
		GEODE_CONCEPT_FUNCTION_CHECK(startAutorepeat) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_stopAutorepeat
		#define GEODE_CONCEPT_CHECK_stopAutorepeat
		GEODE_CONCEPT_FUNCTION_CHECK(stopAutorepeat) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_updateLayoutUsingTouchLocation
		#define GEODE_CONCEPT_CHECK_updateLayoutUsingTouchLocation
		GEODE_CONCEPT_FUNCTION_CHECK(updateLayoutUsingTouchLocation) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::extension::CCControlStepper> : ModifyBase<ModifyDerive<Der, cocos2d::extension::CCControlStepper>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::extension::CCControlStepper>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::extension::CCControlStepper>>::ModifyBase;
		using Base = cocos2d::extension::CCControlStepper;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0x3a3a30, Default, cocos2d::extension::CCControlStepper, )
			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0x3a3ae0, Default, cocos2d::extension::CCControlStepper)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3a4090, Default, cocos2d::extension::CCControlStepper, create, cocos2d::CCSprite*, cocos2d::CCSprite*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3a4190, Default, cocos2d::extension::CCControlStepper, setWraps, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3a4200, Default, cocos2d::extension::CCControlStepper, setMinimumValue, double)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3a4230, Default, cocos2d::extension::CCControlStepper, setMaximumValue, double)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3a4260, Default, cocos2d::extension::CCControlStepper, setValue, double)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3a4280, Default, cocos2d::extension::CCControlStepper, getValue, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3a4290, Default, cocos2d::extension::CCControlStepper, setStepValue, double)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3a42b0, Default, cocos2d::extension::CCControlStepper, setValueWithSendingEvent, double, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3a42a0, Default, cocos2d::extension::CCControlStepper, isContinuous, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3a4410, Default, cocos2d::extension::CCControlStepper, update, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3a4590, Default, cocos2d::extension::CCControlStepper, ccTouchBegan, cocos2d::CCTouch*, cocos2d::CCEvent*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3a4740, Default, cocos2d::extension::CCControlStepper, ccTouchMoved, cocos2d::CCTouch*, cocos2d::CCEvent*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3a4930, Default, cocos2d::extension::CCControlStepper, ccTouchEnded, cocos2d::CCTouch*, cocos2d::CCEvent*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3a3c30, Default, cocos2d::extension::CCControlStepper, initWithMinusSpriteAndPlusSprite, cocos2d::CCSprite*, cocos2d::CCSprite*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3a43c0, Default, cocos2d::extension::CCControlStepper, startAutorepeat, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3a43f0, Default, cocos2d::extension::CCControlStepper, stopAutorepeat, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3a44a0, Default, cocos2d::extension::CCControlStepper, updateLayoutUsingTouchLocation, cocos2d::CCPoint)
		}
	};
}
