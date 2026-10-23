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

	#ifndef GEODE_STATICS_execute
		#define GEODE_STATICS_execute
		GEODE_AS_STATIC_FUNCTION(execute) 
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

	#ifndef GEODE_CONCEPT_CHECK_execute
		#define GEODE_CONCEPT_CHECK_execute
		GEODE_CONCEPT_FUNCTION_CHECK(execute) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_initWithTarget
		#define GEODE_CONCEPT_CHECK_initWithTarget
		GEODE_CONCEPT_FUNCTION_CHECK(initWithTarget) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCCallFuncO> : ModifyBase<ModifyDerive<Der, cocos2d::CCCallFuncO>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCCallFuncO>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCCallFuncO>>::ModifyBase;
		using Base = cocos2d::CCCallFuncO;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0x7ad9b0, Default, cocos2d::CCCallFuncO, )
			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0x7ada10, Default, cocos2d::CCCallFuncO)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x7adb00, Default, cocos2d::CCCallFuncO, create, cocos2d::CCObject*, cocos2d::SEL_MenuHandler, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x7adc50, Default, cocos2d::CCCallFuncO, copyWithZone, cocos2d::CCZone*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x7adac0, Default, cocos2d::CCCallFuncO, execute, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x7adbe0, Default, cocos2d::CCCallFuncO, initWithTarget, cocos2d::CCObject*, cocos2d::SEL_MenuHandler, cocos2d::CCObject*)
		}
	};
}
