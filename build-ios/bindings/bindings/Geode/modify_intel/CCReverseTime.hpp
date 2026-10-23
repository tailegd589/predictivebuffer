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

	#ifndef GEODE_STATICS_reverse
		#define GEODE_STATICS_reverse
		GEODE_AS_STATIC_FUNCTION(reverse) 
	#endif

	#ifndef GEODE_STATICS_initWithAction
		#define GEODE_STATICS_initWithAction
		GEODE_AS_STATIC_FUNCTION(initWithAction) 
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

	#ifndef GEODE_CONCEPT_CHECK_reverse
		#define GEODE_CONCEPT_CHECK_reverse
		GEODE_CONCEPT_FUNCTION_CHECK(reverse) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_initWithAction
		#define GEODE_CONCEPT_CHECK_initWithAction
		GEODE_CONCEPT_FUNCTION_CHECK(initWithAction) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCReverseTime> : ModifyBase<ModifyDerive<Der, cocos2d::CCReverseTime>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCReverseTime>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCReverseTime>>::ModifyBase;
		using Base = cocos2d::CCReverseTime;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0x3bbfc0, Default, cocos2d::CCReverseTime, )
			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0x3bbff0, Default, cocos2d::CCReverseTime)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3bbd80, Default, cocos2d::CCReverseTime, create, cocos2d::CCFiniteTimeAction*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3bbea0, Default, cocos2d::CCReverseTime, copyWithZone, cocos2d::CCZone*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3bc0b0, Default, cocos2d::CCReverseTime, startWithTarget, cocos2d::CCNode*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3bc0f0, Default, cocos2d::CCReverseTime, stop, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3bc120, Default, cocos2d::CCReverseTime, update, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3bc150, Default, cocos2d::CCReverseTime, reverse, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3bbe40, Default, cocos2d::CCReverseTime, initWithAction, cocos2d::CCFiniteTimeAction*)
		}
	};
}
