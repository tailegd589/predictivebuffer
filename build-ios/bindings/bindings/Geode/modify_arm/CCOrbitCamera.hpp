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

	#ifndef GEODE_STATICS_update
		#define GEODE_STATICS_update
		GEODE_AS_STATIC_FUNCTION(update) 
	#endif

	#ifndef GEODE_STATICS_startWithTarget
		#define GEODE_STATICS_startWithTarget
		GEODE_AS_STATIC_FUNCTION(startWithTarget) 
	#endif

	#ifndef GEODE_STATICS_initWithDuration
		#define GEODE_STATICS_initWithDuration
		GEODE_AS_STATIC_FUNCTION(initWithDuration) 
	#endif

	#ifndef GEODE_STATICS_sphericalRadius
		#define GEODE_STATICS_sphericalRadius
		GEODE_AS_STATIC_FUNCTION(sphericalRadius) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
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

	#ifndef GEODE_CONCEPT_CHECK_initWithDuration
		#define GEODE_CONCEPT_CHECK_initWithDuration
		GEODE_CONCEPT_FUNCTION_CHECK(initWithDuration) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_sphericalRadius
		#define GEODE_CONCEPT_CHECK_sphericalRadius
		GEODE_CONCEPT_FUNCTION_CHECK(sphericalRadius) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCOrbitCamera> : ModifyBase<ModifyDerive<Der, cocos2d::CCOrbitCamera>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCOrbitCamera>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCOrbitCamera>>::ModifyBase;
		using Base = cocos2d::CCOrbitCamera;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x2f204c, Default, cocos2d::CCOrbitCamera, create, float, float, float, float, float, float, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x2f21c4, Default, cocos2d::CCOrbitCamera, copyWithZone, cocos2d::CCZone*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x2f2568, Default, cocos2d::CCOrbitCamera, update, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x2f22e4, Default, cocos2d::CCOrbitCamera, startWithTarget, cocos2d::CCNode*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x2f2148, Default, cocos2d::CCOrbitCamera, initWithDuration, float, float, float, float, float, float, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x2f2464, Default, cocos2d::CCOrbitCamera, sphericalRadius, float*, float*, float*)
		}
	};
}
