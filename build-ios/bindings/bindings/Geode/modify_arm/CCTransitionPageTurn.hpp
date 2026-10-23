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

	#ifndef GEODE_STATICS_initWithDuration
		#define GEODE_STATICS_initWithDuration
		GEODE_AS_STATIC_FUNCTION(initWithDuration) 
	#endif

	#ifndef GEODE_STATICS_onEnter
		#define GEODE_STATICS_onEnter
		GEODE_AS_STATIC_FUNCTION(onEnter) 
	#endif

	#ifndef GEODE_STATICS_sceneOrder
		#define GEODE_STATICS_sceneOrder
		GEODE_AS_STATIC_FUNCTION(sceneOrder) 
	#endif

	#ifndef GEODE_STATICS_actionWithSize
		#define GEODE_STATICS_actionWithSize
		GEODE_AS_STATIC_FUNCTION(actionWithSize) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_initWithDuration
		#define GEODE_CONCEPT_CHECK_initWithDuration
		GEODE_CONCEPT_FUNCTION_CHECK(initWithDuration) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onEnter
		#define GEODE_CONCEPT_CHECK_onEnter
		GEODE_CONCEPT_FUNCTION_CHECK(onEnter) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_sceneOrder
		#define GEODE_CONCEPT_CHECK_sceneOrder
		GEODE_CONCEPT_FUNCTION_CHECK(sceneOrder) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_actionWithSize
		#define GEODE_CONCEPT_CHECK_actionWithSize
		GEODE_CONCEPT_FUNCTION_CHECK(actionWithSize) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCTransitionPageTurn> : ModifyBase<ModifyDerive<Der, cocos2d::CCTransitionPageTurn>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCTransitionPageTurn>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCTransitionPageTurn>>::ModifyBase;
		using Base = cocos2d::CCTransitionPageTurn;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0x358ab4, Default, cocos2d::CCTransitionPageTurn, )
			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0x358af4, Default, cocos2d::CCTransitionPageTurn)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x358b10, Default, cocos2d::CCTransitionPageTurn, create, float, cocos2d::CCScene*, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x358b94, Default, cocos2d::CCTransitionPageTurn, initWithDuration, float, cocos2d::CCScene*, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x358bbc, Default, cocos2d::CCTransitionPageTurn, onEnter, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x358bb0, Default, cocos2d::CCTransitionPageTurn, sceneOrder, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x358cd0, Default, cocos2d::CCTransitionPageTurn, actionWithSize, cocos2d::CCSize const&)
		}
	};
}
