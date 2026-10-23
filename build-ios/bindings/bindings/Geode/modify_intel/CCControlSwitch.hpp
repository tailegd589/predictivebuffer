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

	#ifndef GEODE_STATICS_setEnabled
		#define GEODE_STATICS_setEnabled
		GEODE_AS_STATIC_FUNCTION(setEnabled) 
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

	#ifndef GEODE_STATICS_initWithMaskSprite
		#define GEODE_STATICS_initWithMaskSprite
		GEODE_AS_STATIC_FUNCTION(initWithMaskSprite) 
	#endif

	#ifndef GEODE_STATICS_locationFromTouch
		#define GEODE_STATICS_locationFromTouch
		GEODE_AS_STATIC_FUNCTION(locationFromTouch) 
	#endif

	#ifndef GEODE_STATICS_setOn
		#define GEODE_STATICS_setOn
		GEODE_AS_STATIC_FUNCTION(setOn) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setEnabled
		#define GEODE_CONCEPT_CHECK_setEnabled
		GEODE_CONCEPT_FUNCTION_CHECK(setEnabled) 
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

	#ifndef GEODE_CONCEPT_CHECK_initWithMaskSprite
		#define GEODE_CONCEPT_CHECK_initWithMaskSprite
		GEODE_CONCEPT_FUNCTION_CHECK(initWithMaskSprite) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_locationFromTouch
		#define GEODE_CONCEPT_CHECK_locationFromTouch
		GEODE_CONCEPT_FUNCTION_CHECK(locationFromTouch) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setOn
		#define GEODE_CONCEPT_CHECK_setOn
		GEODE_CONCEPT_FUNCTION_CHECK(setOn) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::extension::CCControlSwitch> : ModifyBase<ModifyDerive<Der, cocos2d::extension::CCControlSwitch>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::extension::CCControlSwitch>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::extension::CCControlSwitch>>::ModifyBase;
		using Base = cocos2d::extension::CCControlSwitch;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0x3a8340, Default, cocos2d::extension::CCControlSwitch, )
			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0x3a83d0, Default, cocos2d::extension::CCControlSwitch)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3a88c0, Default, cocos2d::extension::CCControlSwitch, create, cocos2d::CCSprite*, cocos2d::CCSprite*, cocos2d::CCSprite*, cocos2d::CCSprite*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3a89c0, Default, cocos2d::extension::CCControlSwitch, create, cocos2d::CCSprite*, cocos2d::CCSprite*, cocos2d::CCSprite*, cocos2d::CCSprite*, cocos2d::CCLabelTTF*, cocos2d::CCLabelTTF*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3a8c00, Default, cocos2d::extension::CCControlSwitch, setEnabled, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3a8c90, Default, cocos2d::extension::CCControlSwitch, ccTouchBegan, cocos2d::CCTouch*, cocos2d::CCEvent*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3a8d80, Default, cocos2d::extension::CCControlSwitch, ccTouchMoved, cocos2d::CCTouch*, cocos2d::CCEvent*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3a8e50, Default, cocos2d::extension::CCControlSwitch, ccTouchEnded, cocos2d::CCTouch*, cocos2d::CCEvent*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3a8f80, Default, cocos2d::extension::CCControlSwitch, ccTouchCancelled, cocos2d::CCTouch*, cocos2d::CCEvent*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3a86b0, Default, cocos2d::extension::CCControlSwitch, initWithMaskSprite, cocos2d::CCSprite*, cocos2d::CCSprite*, cocos2d::CCSprite*, cocos2d::CCSprite*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3a86d0, Default, cocos2d::extension::CCControlSwitch, initWithMaskSprite, cocos2d::CCSprite*, cocos2d::CCSprite*, cocos2d::CCSprite*, cocos2d::CCSprite*, cocos2d::CCLabelTTF*, cocos2d::CCLabelTTF*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3a8c40, Default, cocos2d::extension::CCControlSwitch, locationFromTouch, cocos2d::CCTouch*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3a8ad0, Default, cocos2d::extension::CCControlSwitch, setOn, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3a8b40, Default, cocos2d::extension::CCControlSwitch, setOn, bool, bool)
		}
	};
}
