#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <cocos2d.h>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_create
		#define GEODE_STATICS_create
		GEODE_AS_STATIC_FUNCTION(create) 
	#endif

	#ifndef GEODE_STATICS_progressTimerNodeWithRenderTexture
		#define GEODE_STATICS_progressTimerNodeWithRenderTexture
		GEODE_AS_STATIC_FUNCTION(progressTimerNodeWithRenderTexture) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_progressTimerNodeWithRenderTexture
		#define GEODE_CONCEPT_CHECK_progressTimerNodeWithRenderTexture
		GEODE_CONCEPT_FUNCTION_CHECK(progressTimerNodeWithRenderTexture) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCTransitionProgressOutIn> : ModifyBase<ModifyDerive<Der, cocos2d::CCTransitionProgressOutIn>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCTransitionProgressOutIn>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCTransitionProgressOutIn>>::ModifyBase;
		using Base = cocos2d::CCTransitionProgressOutIn;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x22ea48, Default, cocos2d::CCTransitionProgressOutIn, create, float, cocos2d::CCScene*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x22eb20, Default, cocos2d::CCTransitionProgressOutIn, progressTimerNodeWithRenderTexture, cocos2d::CCRenderTexture*)
		}
	};
}
