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

	#ifndef GEODE_STATICS_reverse
		#define GEODE_STATICS_reverse
		GEODE_AS_STATIC_FUNCTION(reverse) 
	#endif

	#ifndef GEODE_STATICS_updatePosition
		#define GEODE_STATICS_updatePosition
		GEODE_AS_STATIC_FUNCTION(updatePosition) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_startWithTarget
		#define GEODE_CONCEPT_CHECK_startWithTarget
		GEODE_CONCEPT_FUNCTION_CHECK(startWithTarget) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_reverse
		#define GEODE_CONCEPT_CHECK_reverse
		GEODE_CONCEPT_FUNCTION_CHECK(reverse) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_updatePosition
		#define GEODE_CONCEPT_CHECK_updatePosition
		GEODE_CONCEPT_FUNCTION_CHECK(updatePosition) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCCardinalSplineBy> : ModifyBase<ModifyDerive<Der, cocos2d::CCCardinalSplineBy>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCCardinalSplineBy>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCCardinalSplineBy>>::ModifyBase;
		using Base = cocos2d::CCCardinalSplineBy;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0x26d320, Default, cocos2d::CCCardinalSplineBy, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x26d1f4, Default, cocos2d::CCCardinalSplineBy, create, float, cocos2d::CCPointArray*, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x26d754, Default, cocos2d::CCCardinalSplineBy, startWithTarget, cocos2d::CCNode*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x26d490, Default, cocos2d::CCCardinalSplineBy, reverse, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x26d438, Default, cocos2d::CCCardinalSplineBy, updatePosition, cocos2d::CCPoint&)
		}
	};
}
