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

	#ifndef GEODE_STATICS_initScenes
		#define GEODE_STATICS_initScenes
		GEODE_AS_STATIC_FUNCTION(initScenes) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_initScenes
		#define GEODE_CONCEPT_CHECK_initScenes
		GEODE_CONCEPT_FUNCTION_CHECK(initScenes) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCTransitionMoveInT> : ModifyBase<ModifyDerive<Der, cocos2d::CCTransitionMoveInT>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCTransitionMoveInT>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCTransitionMoveInT>>::ModifyBase;
		using Base = cocos2d::CCTransitionMoveInT;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0xd5b50, Default, cocos2d::CCTransitionMoveInT, )
			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0xd5bb0, Default, cocos2d::CCTransitionMoveInT)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xd5ca0, Default, cocos2d::CCTransitionMoveInT, create, float, cocos2d::CCScene*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xd5d30, Default, cocos2d::CCTransitionMoveInT, initScenes, )
		}
	};
}
