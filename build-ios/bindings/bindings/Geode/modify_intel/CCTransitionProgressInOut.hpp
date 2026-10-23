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

	#ifndef GEODE_STATICS_sceneOrder
		#define GEODE_STATICS_sceneOrder
		GEODE_AS_STATIC_FUNCTION(sceneOrder) 
	#endif

	#ifndef GEODE_STATICS_setupTransition
		#define GEODE_STATICS_setupTransition
		GEODE_AS_STATIC_FUNCTION(setupTransition) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_progressTimerNodeWithRenderTexture
		#define GEODE_CONCEPT_CHECK_progressTimerNodeWithRenderTexture
		GEODE_CONCEPT_FUNCTION_CHECK(progressTimerNodeWithRenderTexture) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_sceneOrder
		#define GEODE_CONCEPT_CHECK_sceneOrder
		GEODE_CONCEPT_FUNCTION_CHECK(sceneOrder) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setupTransition
		#define GEODE_CONCEPT_CHECK_setupTransition
		GEODE_CONCEPT_FUNCTION_CHECK(setupTransition) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCTransitionProgressInOut> : ModifyBase<ModifyDerive<Der, cocos2d::CCTransitionProgressInOut>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCTransitionProgressInOut>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCTransitionProgressInOut>>::ModifyBase;
		using Base = cocos2d::CCTransitionProgressInOut;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x28dce0, Default, cocos2d::CCTransitionProgressInOut, create, float, cocos2d::CCScene*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x28ddc0, Default, cocos2d::CCTransitionProgressInOut, progressTimerNodeWithRenderTexture, cocos2d::CCRenderTexture*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x28dd80, Default, cocos2d::CCTransitionProgressInOut, sceneOrder, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x28dd90, Default, cocos2d::CCTransitionProgressInOut, setupTransition, )
		}
	};
}
