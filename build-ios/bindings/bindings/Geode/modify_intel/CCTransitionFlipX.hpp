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
	struct ModifyDerive<Der, cocos2d::CCTransitionFlipX> : ModifyBase<ModifyDerive<Der, cocos2d::CCTransitionFlipX>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCTransitionFlipX>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCTransitionFlipX>>::ModifyBase;
		using Base = cocos2d::CCTransitionFlipX;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0xd6fa0, Default, cocos2d::CCTransitionFlipX, )
			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0xd6fe0, Default, cocos2d::CCTransitionFlipX)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xd72f0, Default, cocos2d::CCTransitionFlipX, create, float, cocos2d::CCScene*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xd7270, Default, cocos2d::CCTransitionFlipX, create, float, cocos2d::CCScene*, cocos2d::tOrientation)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xd70d0, Default, cocos2d::CCTransitionFlipX, onEnter, )
		}
	};
}
