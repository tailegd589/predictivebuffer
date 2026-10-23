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

	#ifndef GEODE_STATICS_copyWithZone
		#define GEODE_STATICS_copyWithZone
		GEODE_AS_STATIC_FUNCTION(copyWithZone) 
	#endif

	#ifndef GEODE_STATICS_startWithTarget
		#define GEODE_STATICS_startWithTarget
		GEODE_AS_STATIC_FUNCTION(startWithTarget) 
	#endif

	#ifndef GEODE_STATICS_stop
		#define GEODE_STATICS_stop
		GEODE_AS_STATIC_FUNCTION(stop) 
	#endif

	#ifndef GEODE_STATICS_update
		#define GEODE_STATICS_update
		GEODE_AS_STATIC_FUNCTION(update) 
	#endif

	#ifndef GEODE_STATICS_initWithTarget
		#define GEODE_STATICS_initWithTarget
		GEODE_AS_STATIC_FUNCTION(initWithTarget) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_copyWithZone
		#define GEODE_CONCEPT_CHECK_copyWithZone
		GEODE_CONCEPT_FUNCTION_CHECK(copyWithZone) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_startWithTarget
		#define GEODE_CONCEPT_CHECK_startWithTarget
		GEODE_CONCEPT_FUNCTION_CHECK(startWithTarget) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_stop
		#define GEODE_CONCEPT_CHECK_stop
		GEODE_CONCEPT_FUNCTION_CHECK(stop) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_update
		#define GEODE_CONCEPT_CHECK_update
		GEODE_CONCEPT_FUNCTION_CHECK(update) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_initWithTarget
		#define GEODE_CONCEPT_CHECK_initWithTarget
		GEODE_CONCEPT_FUNCTION_CHECK(initWithTarget) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCTargetedAction> : ModifyBase<ModifyDerive<Der, cocos2d::CCTargetedAction>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCTargetedAction>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCTargetedAction>>::ModifyBase;
		using Base = cocos2d::CCTargetedAction;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0x33eb28, Default, cocos2d::CCTargetedAction, )
			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0x33eb50, Default, cocos2d::CCTargetedAction)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x33ec2c, Default, cocos2d::CCTargetedAction, create, cocos2d::CCNode*, cocos2d::CCFiniteTimeAction*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x33ed3c, Default, cocos2d::CCTargetedAction, copyWithZone, cocos2d::CCZone*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x33ee40, Default, cocos2d::CCTargetedAction, startWithTarget, cocos2d::CCNode*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x33ee78, Default, cocos2d::CCTargetedAction, stop, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x33ee88, Default, cocos2d::CCTargetedAction, update, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x33ecd0, Default, cocos2d::CCTargetedAction, initWithTarget, cocos2d::CCNode*, cocos2d::CCFiniteTimeAction*)
		}
	};
}
