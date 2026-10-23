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

	#ifndef GEODE_STATICS_onEnter
		#define GEODE_STATICS_onEnter
		GEODE_AS_STATIC_FUNCTION(onEnter) 
	#endif

	#ifndef GEODE_STATICS_sceneOrder
		#define GEODE_STATICS_sceneOrder
		GEODE_AS_STATIC_FUNCTION(sceneOrder) 
	#endif

	#ifndef GEODE_STATICS_initScenes
		#define GEODE_STATICS_initScenes
		GEODE_AS_STATIC_FUNCTION(initScenes) 
	#endif

	#ifndef GEODE_STATICS_action
		#define GEODE_STATICS_action
		GEODE_AS_STATIC_FUNCTION(action) 
	#endif

	#ifndef GEODE_STATICS_easeActionWithAction
		#define GEODE_STATICS_easeActionWithAction
		GEODE_AS_STATIC_FUNCTION(easeActionWithAction) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onEnter
		#define GEODE_CONCEPT_CHECK_onEnter
		GEODE_CONCEPT_FUNCTION_CHECK(onEnter) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_sceneOrder
		#define GEODE_CONCEPT_CHECK_sceneOrder
		GEODE_CONCEPT_FUNCTION_CHECK(sceneOrder) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_initScenes
		#define GEODE_CONCEPT_CHECK_initScenes
		GEODE_CONCEPT_FUNCTION_CHECK(initScenes) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_action
		#define GEODE_CONCEPT_CHECK_action
		GEODE_CONCEPT_FUNCTION_CHECK(action) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_easeActionWithAction
		#define GEODE_CONCEPT_CHECK_easeActionWithAction
		GEODE_CONCEPT_FUNCTION_CHECK(easeActionWithAction) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCTransitionSlideInL> : ModifyBase<ModifyDerive<Der, cocos2d::CCTransitionSlideInL>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCTransitionSlideInL>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCTransitionSlideInL>>::ModifyBase;
		using Base = cocos2d::CCTransitionSlideInL;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0xd5fd0, Default, cocos2d::CCTransitionSlideInL, )
			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0xd6030, Default, cocos2d::CCTransitionSlideInL)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xd6330, Default, cocos2d::CCTransitionSlideInL, create, float, cocos2d::CCScene*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xd6120, Default, cocos2d::CCTransitionSlideInL, onEnter, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xd6210, Default, cocos2d::CCTransitionSlideInL, sceneOrder, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xd6220, Default, cocos2d::CCTransitionSlideInL, initScenes, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xd6290, Default, cocos2d::CCTransitionSlideInL, action, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xd62f0, Default, cocos2d::CCTransitionSlideInL, easeActionWithAction, cocos2d::CCActionInterval*)
		}
	};
}
