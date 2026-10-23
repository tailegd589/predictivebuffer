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

	#ifndef GEODE_STATICS_initWithTarget
		#define GEODE_STATICS_initWithTarget
		GEODE_AS_STATIC_FUNCTION(initWithTarget) 
	#endif

	#ifndef GEODE_STATICS_copyWithZone
		#define GEODE_STATICS_copyWithZone
		GEODE_AS_STATIC_FUNCTION(copyWithZone) 
	#endif

	#ifndef GEODE_STATICS_execute
		#define GEODE_STATICS_execute
		GEODE_AS_STATIC_FUNCTION(execute) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_initWithTarget
		#define GEODE_CONCEPT_CHECK_initWithTarget
		GEODE_CONCEPT_FUNCTION_CHECK(initWithTarget) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_copyWithZone
		#define GEODE_CONCEPT_CHECK_copyWithZone
		GEODE_CONCEPT_FUNCTION_CHECK(copyWithZone) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_execute
		#define GEODE_CONCEPT_CHECK_execute
		GEODE_CONCEPT_FUNCTION_CHECK(execute) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCCallFuncND> : ModifyBase<ModifyDerive<Der, cocos2d::CCCallFuncND>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCCallFuncND>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCCallFuncND>>::ModifyBase;
		using Base = cocos2d::CCCallFuncND;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x7ad690, Default, cocos2d::CCCallFuncND, create, cocos2d::CCObject*, cocos2d::SEL_CallFuncND, void*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x7ad780, Default, cocos2d::CCCallFuncND, initWithTarget, cocos2d::CCObject*, cocos2d::SEL_CallFuncND, void*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x7ad7f0, Default, cocos2d::CCCallFuncND, copyWithZone, cocos2d::CCZone*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x7ad910, Default, cocos2d::CCCallFuncND, execute, )
		}
	};
}
