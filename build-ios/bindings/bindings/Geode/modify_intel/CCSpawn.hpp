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

	#ifndef GEODE_STATICS_createWithTwoActions
		#define GEODE_STATICS_createWithTwoActions
		GEODE_AS_STATIC_FUNCTION(createWithTwoActions) 
	#endif

	#ifndef GEODE_STATICS_createWithVariableList
		#define GEODE_STATICS_createWithVariableList
		GEODE_AS_STATIC_FUNCTION(createWithVariableList) 
	#endif

	#ifndef GEODE_STATICS_copyWithZone
		#define GEODE_STATICS_copyWithZone
		GEODE_AS_STATIC_FUNCTION(copyWithZone) 
	#endif

	#ifndef GEODE_STATICS_update
		#define GEODE_STATICS_update
		GEODE_AS_STATIC_FUNCTION(update) 
	#endif

	#ifndef GEODE_STATICS_startWithTarget
		#define GEODE_STATICS_startWithTarget
		GEODE_AS_STATIC_FUNCTION(startWithTarget) 
	#endif

	#ifndef GEODE_STATICS_stop
		#define GEODE_STATICS_stop
		GEODE_AS_STATIC_FUNCTION(stop) 
	#endif

	#ifndef GEODE_STATICS_reverse
		#define GEODE_STATICS_reverse
		GEODE_AS_STATIC_FUNCTION(reverse) 
	#endif

	#ifndef GEODE_STATICS_initWithTwoActions
		#define GEODE_STATICS_initWithTwoActions
		GEODE_AS_STATIC_FUNCTION(initWithTwoActions) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_createWithTwoActions
		#define GEODE_CONCEPT_CHECK_createWithTwoActions
		GEODE_CONCEPT_FUNCTION_CHECK(createWithTwoActions) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_createWithVariableList
		#define GEODE_CONCEPT_CHECK_createWithVariableList
		GEODE_CONCEPT_FUNCTION_CHECK(createWithVariableList) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_copyWithZone
		#define GEODE_CONCEPT_CHECK_copyWithZone
		GEODE_CONCEPT_FUNCTION_CHECK(copyWithZone) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_update
		#define GEODE_CONCEPT_CHECK_update
		GEODE_CONCEPT_FUNCTION_CHECK(update) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_startWithTarget
		#define GEODE_CONCEPT_CHECK_startWithTarget
		GEODE_CONCEPT_FUNCTION_CHECK(startWithTarget) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_stop
		#define GEODE_CONCEPT_CHECK_stop
		GEODE_CONCEPT_FUNCTION_CHECK(stop) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_reverse
		#define GEODE_CONCEPT_CHECK_reverse
		GEODE_CONCEPT_FUNCTION_CHECK(reverse) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_initWithTwoActions
		#define GEODE_CONCEPT_CHECK_initWithTwoActions
		GEODE_CONCEPT_FUNCTION_CHECK(initWithTwoActions) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCSpawn> : ModifyBase<ModifyDerive<Der, cocos2d::CCSpawn>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCSpawn>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCSpawn>>::ModifyBase;
		using Base = cocos2d::CCSpawn;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0x3b75a0, Default, cocos2d::CCSpawn)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3b6ef0, Default, cocos2d::CCSpawn, create, cocos2d::CCArray*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3b6e60, Default, cocos2d::CCSpawn, createWithTwoActions, cocos2d::CCFiniteTimeAction*, cocos2d::CCFiniteTimeAction*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3b6c10, Default, cocos2d::CCSpawn, createWithVariableList, cocos2d::CCFiniteTimeAction*, va_list)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3b74a0, Default, cocos2d::CCSpawn, copyWithZone, cocos2d::CCZone*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3b7700, Default, cocos2d::CCSpawn, update, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3b7690, Default, cocos2d::CCSpawn, startWithTarget, cocos2d::CCNode*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3b76d0, Default, cocos2d::CCSpawn, stop, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3b7750, Default, cocos2d::CCSpawn, reverse, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3b70c0, Default, cocos2d::CCSpawn, initWithTwoActions, cocos2d::CCFiniteTimeAction*, cocos2d::CCFiniteTimeAction*)
		}
	};
}
