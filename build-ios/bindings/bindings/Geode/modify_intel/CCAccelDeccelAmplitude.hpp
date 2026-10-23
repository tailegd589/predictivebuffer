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

	#ifndef GEODE_STATICS_startWithTarget
		#define GEODE_STATICS_startWithTarget
		GEODE_AS_STATIC_FUNCTION(startWithTarget) 
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

	#ifndef GEODE_CONCEPT_CHECK_startWithTarget
		#define GEODE_CONCEPT_CHECK_startWithTarget
		GEODE_CONCEPT_FUNCTION_CHECK(startWithTarget) 
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
	struct ModifyDerive<Der, cocos2d::CCAccelDeccelAmplitude> : ModifyBase<ModifyDerive<Der, cocos2d::CCAccelDeccelAmplitude>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCAccelDeccelAmplitude>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCAccelDeccelAmplitude>>::ModifyBase;
		using Base = cocos2d::CCAccelDeccelAmplitude;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0x20a590, Default, cocos2d::CCAccelDeccelAmplitude)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x20a490, Default, cocos2d::CCAccelDeccelAmplitude, create, cocos2d::CCAction*, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x20a650, Default, cocos2d::CCAccelDeccelAmplitude, startWithTarget, cocos2d::CCNode*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x20a680, Default, cocos2d::CCAccelDeccelAmplitude, update, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x20a6e0, Default, cocos2d::CCAccelDeccelAmplitude, reverse, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x20a550, Default, cocos2d::CCAccelDeccelAmplitude, initWithAction, cocos2d::CCAction*, float)
		}
	};
}
