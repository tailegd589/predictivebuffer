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
	struct ModifyDerive<Der, cocos2d::CCSequence> : ModifyBase<ModifyDerive<Der, cocos2d::CCSequence>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCSequence>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCSequence>>::ModifyBase;
		using Base = cocos2d::CCSequence;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0x3b5e80, Default, cocos2d::CCSequence)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3b5ae0, Default, cocos2d::CCSequence, create, cocos2d::CCArray*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3b5630, Default, cocos2d::CCSequence, createWithTwoActions, cocos2d::CCFiniteTimeAction*, cocos2d::CCFiniteTimeAction*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3b5810, Default, cocos2d::CCSequence, createWithVariableList, cocos2d::CCFiniteTimeAction*, va_list)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3b5d30, Default, cocos2d::CCSequence, copyWithZone, cocos2d::CCZone*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3b5ff0, Default, cocos2d::CCSequence, update, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3b5f70, Default, cocos2d::CCSequence, startWithTarget, cocos2d::CCNode*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3b5fb0, Default, cocos2d::CCSequence, stop, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3b6170, Default, cocos2d::CCSequence, reverse, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3b5700, Default, cocos2d::CCSequence, initWithTwoActions, cocos2d::CCFiniteTimeAction*, cocos2d::CCFiniteTimeAction*)
		}
	};
}
