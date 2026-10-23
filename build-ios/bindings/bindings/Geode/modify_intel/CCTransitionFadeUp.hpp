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

	#ifndef GEODE_STATICS_actionWithSize
		#define GEODE_STATICS_actionWithSize
		GEODE_AS_STATIC_FUNCTION(actionWithSize) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_actionWithSize
		#define GEODE_CONCEPT_CHECK_actionWithSize
		GEODE_CONCEPT_FUNCTION_CHECK(actionWithSize) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCTransitionFadeUp> : ModifyBase<ModifyDerive<Der, cocos2d::CCTransitionFadeUp>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCTransitionFadeUp>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCTransitionFadeUp>>::ModifyBase;
		using Base = cocos2d::CCTransitionFadeUp;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0xd9f60, Default, cocos2d::CCTransitionFadeUp, )
			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0xd9fc0, Default, cocos2d::CCTransitionFadeUp)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xda0b0, Default, cocos2d::CCTransitionFadeUp, create, float, cocos2d::CCScene*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xda140, Default, cocos2d::CCTransitionFadeUp, actionWithSize, cocos2d::CCSize const&)
		}
	};
}
