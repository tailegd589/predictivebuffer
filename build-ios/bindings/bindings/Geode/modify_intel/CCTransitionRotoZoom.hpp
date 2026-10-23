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

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onEnter
		#define GEODE_CONCEPT_CHECK_onEnter
		GEODE_CONCEPT_FUNCTION_CHECK(onEnter) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCTransitionRotoZoom> : ModifyBase<ModifyDerive<Der, cocos2d::CCTransitionRotoZoom>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCTransitionRotoZoom>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCTransitionRotoZoom>>::ModifyBase;
		using Base = cocos2d::CCTransitionRotoZoom;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0xd4e70, Default, cocos2d::CCTransitionRotoZoom, )
			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0xd4f30, Default, cocos2d::CCTransitionRotoZoom)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xd4eb0, Default, cocos2d::CCTransitionRotoZoom, create, float, cocos2d::CCScene*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xd5020, Default, cocos2d::CCTransitionRotoZoom, onEnter, )
		}
	};
}
