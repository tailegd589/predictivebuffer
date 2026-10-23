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

	#ifndef GEODE_STATICS_setValue
		#define GEODE_STATICS_setValue
		GEODE_AS_STATIC_FUNCTION(setValue) 
	#endif

	#ifndef GEODE_STATICS_setMinimumValue
		#define GEODE_STATICS_setMinimumValue
		GEODE_AS_STATIC_FUNCTION(setMinimumValue) 
	#endif

	#ifndef GEODE_STATICS_setMaximumValue
		#define GEODE_STATICS_setMaximumValue
		GEODE_AS_STATIC_FUNCTION(setMaximumValue) 
	#endif

	#ifndef GEODE_STATICS_setEnabled
		#define GEODE_STATICS_setEnabled
		GEODE_AS_STATIC_FUNCTION(setEnabled) 
	#endif

	#ifndef GEODE_STATICS_isTouchInside
		#define GEODE_STATICS_isTouchInside
		GEODE_AS_STATIC_FUNCTION(isTouchInside) 
	#endif

	#ifndef GEODE_STATICS_initWithSprites
		#define GEODE_STATICS_initWithSprites
		GEODE_AS_STATIC_FUNCTION(initWithSprites) 
	#endif

	#ifndef GEODE_STATICS_needsLayout
		#define GEODE_STATICS_needsLayout
		GEODE_AS_STATIC_FUNCTION(needsLayout) 
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

	#ifndef GEODE_STATICS_locationFromTouch
		#define GEODE_STATICS_locationFromTouch
		GEODE_AS_STATIC_FUNCTION(locationFromTouch) 
	#endif

	#ifndef GEODE_STATICS_sliderBegan
		#define GEODE_STATICS_sliderBegan
		GEODE_AS_STATIC_FUNCTION(sliderBegan) 
	#endif

	#ifndef GEODE_STATICS_sliderEnded
		#define GEODE_STATICS_sliderEnded
		GEODE_AS_STATIC_FUNCTION(sliderEnded) 
	#endif

	#ifndef GEODE_STATICS_sliderMoved
		#define GEODE_STATICS_sliderMoved
		GEODE_AS_STATIC_FUNCTION(sliderMoved) 
	#endif

	#ifndef GEODE_STATICS_valueForLocation
		#define GEODE_STATICS_valueForLocation
		GEODE_AS_STATIC_FUNCTION(valueForLocation) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setValue
		#define GEODE_CONCEPT_CHECK_setValue
		GEODE_CONCEPT_FUNCTION_CHECK(setValue) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setMinimumValue
		#define GEODE_CONCEPT_CHECK_setMinimumValue
		GEODE_CONCEPT_FUNCTION_CHECK(setMinimumValue) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setMaximumValue
		#define GEODE_CONCEPT_CHECK_setMaximumValue
		GEODE_CONCEPT_FUNCTION_CHECK(setMaximumValue) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setEnabled
		#define GEODE_CONCEPT_CHECK_setEnabled
		GEODE_CONCEPT_FUNCTION_CHECK(setEnabled) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_isTouchInside
		#define GEODE_CONCEPT_CHECK_isTouchInside
		GEODE_CONCEPT_FUNCTION_CHECK(isTouchInside) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_initWithSprites
		#define GEODE_CONCEPT_CHECK_initWithSprites
		GEODE_CONCEPT_FUNCTION_CHECK(initWithSprites) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_needsLayout
		#define GEODE_CONCEPT_CHECK_needsLayout
		GEODE_CONCEPT_FUNCTION_CHECK(needsLayout) 
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

	#ifndef GEODE_CONCEPT_CHECK_locationFromTouch
		#define GEODE_CONCEPT_CHECK_locationFromTouch
		GEODE_CONCEPT_FUNCTION_CHECK(locationFromTouch) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_sliderBegan
		#define GEODE_CONCEPT_CHECK_sliderBegan
		GEODE_CONCEPT_FUNCTION_CHECK(sliderBegan) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_sliderEnded
		#define GEODE_CONCEPT_CHECK_sliderEnded
		GEODE_CONCEPT_FUNCTION_CHECK(sliderEnded) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_sliderMoved
		#define GEODE_CONCEPT_CHECK_sliderMoved
		GEODE_CONCEPT_FUNCTION_CHECK(sliderMoved) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_valueForLocation
		#define GEODE_CONCEPT_CHECK_valueForLocation
		GEODE_CONCEPT_FUNCTION_CHECK(valueForLocation) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::extension::CCControlSlider> : ModifyBase<ModifyDerive<Der, cocos2d::extension::CCControlSlider>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::extension::CCControlSlider>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::extension::CCControlSlider>>::ModifyBase;
		using Base = cocos2d::extension::CCControlSlider;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0x324b38, Default, cocos2d::extension::CCControlSlider, )
			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0x324b90, Default, cocos2d::extension::CCControlSlider)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x324d90, Default, cocos2d::extension::CCControlSlider, create, char const*, char const*, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x324e60, Default, cocos2d::extension::CCControlSlider, create, cocos2d::CCSprite*, cocos2d::CCSprite*, cocos2d::CCSprite*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x325220, Default, cocos2d::extension::CCControlSlider, setValue, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x325274, Default, cocos2d::extension::CCControlSlider, setMinimumValue, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3252a4, Default, cocos2d::extension::CCControlSlider, setMaximumValue, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3251d0, Default, cocos2d::extension::CCControlSlider, setEnabled, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3252d4, Default, cocos2d::extension::CCControlSlider, isTouchInside, cocos2d::CCTouch*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x324f14, Default, cocos2d::extension::CCControlSlider, initWithSprites, cocos2d::CCSprite*, cocos2d::CCSprite*, cocos2d::CCSprite*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3259b4, Default, cocos2d::extension::CCControlSlider, needsLayout, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x325424, Default, cocos2d::extension::CCControlSlider, ccTouchBegan, cocos2d::CCTouch*, cocos2d::CCEvent*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x325654, Default, cocos2d::extension::CCControlSlider, ccTouchMoved, cocos2d::CCTouch*, cocos2d::CCEvent*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3257e8, Default, cocos2d::extension::CCControlSlider, ccTouchEnded, cocos2d::CCTouch*, cocos2d::CCEvent*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x32538c, Default, cocos2d::extension::CCControlSlider, locationFromTouch, cocos2d::CCTouch*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x325594, Default, cocos2d::extension::CCControlSlider, sliderBegan, cocos2d::CCPoint)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3258d4, Default, cocos2d::extension::CCControlSlider, sliderEnded, cocos2d::CCPoint)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x325758, Default, cocos2d::extension::CCControlSlider, sliderMoved, cocos2d::CCPoint)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x325aa8, Default, cocos2d::extension::CCControlSlider, valueForLocation, cocos2d::CCPoint)
		}
	};
}
