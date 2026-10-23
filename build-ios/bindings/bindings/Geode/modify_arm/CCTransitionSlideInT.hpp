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

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
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


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCTransitionSlideInT> : ModifyBase<ModifyDerive<Der, cocos2d::CCTransitionSlideInT>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCTransitionSlideInT>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCTransitionSlideInT>>::ModifyBase;
		using Base = cocos2d::CCTransitionSlideInT;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0xbd238, Default, cocos2d::CCTransitionSlideInT, )
			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0xbd288, Default, cocos2d::CCTransitionSlideInT)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xbd34c, Default, cocos2d::CCTransitionSlideInT, create, float, cocos2d::CCScene*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xbd3f4, Default, cocos2d::CCTransitionSlideInT, sceneOrder, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xbd3fc, Default, cocos2d::CCTransitionSlideInT, initScenes, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xbd45c, Default, cocos2d::CCTransitionSlideInT, action, )
		}
	};
}
