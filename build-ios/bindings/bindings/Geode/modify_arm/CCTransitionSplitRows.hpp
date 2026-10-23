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

	#ifndef GEODE_STATICS_action
		#define GEODE_STATICS_action
		GEODE_AS_STATIC_FUNCTION(action) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_action
		#define GEODE_CONCEPT_CHECK_action
		GEODE_CONCEPT_FUNCTION_CHECK(action) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCTransitionSplitRows> : ModifyBase<ModifyDerive<Der, cocos2d::CCTransitionSplitRows>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCTransitionSplitRows>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCTransitionSplitRows>>::ModifyBase;
		using Base = cocos2d::CCTransitionSplitRows;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0xc0078, Default, cocos2d::CCTransitionSplitRows, )
			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0xc00c8, Default, cocos2d::CCTransitionSplitRows)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xc01a0, Default, cocos2d::CCTransitionSplitRows, create, float, cocos2d::CCScene*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xc018c, Default, cocos2d::CCTransitionSplitRows, action, )
		}
	};
}
