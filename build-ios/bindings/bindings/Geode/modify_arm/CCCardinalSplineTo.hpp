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

	#ifndef GEODE_STATICS_update
		#define GEODE_STATICS_update
		GEODE_AS_STATIC_FUNCTION(update) 
	#endif

	#ifndef GEODE_STATICS_reverse
		#define GEODE_STATICS_reverse
		GEODE_AS_STATIC_FUNCTION(reverse) 
	#endif

	#ifndef GEODE_STATICS_updatePosition
		#define GEODE_STATICS_updatePosition
		GEODE_AS_STATIC_FUNCTION(updatePosition) 
	#endif

	#ifndef GEODE_STATICS_initWithDuration
		#define GEODE_STATICS_initWithDuration
		GEODE_AS_STATIC_FUNCTION(initWithDuration) 
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

	#ifndef GEODE_CONCEPT_CHECK_update
		#define GEODE_CONCEPT_CHECK_update
		GEODE_CONCEPT_FUNCTION_CHECK(update) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_reverse
		#define GEODE_CONCEPT_CHECK_reverse
		GEODE_CONCEPT_FUNCTION_CHECK(reverse) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_updatePosition
		#define GEODE_CONCEPT_CHECK_updatePosition
		GEODE_CONCEPT_FUNCTION_CHECK(updatePosition) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_initWithDuration
		#define GEODE_CONCEPT_CHECK_initWithDuration
		GEODE_CONCEPT_FUNCTION_CHECK(initWithDuration) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCCardinalSplineTo> : ModifyBase<ModifyDerive<Der, cocos2d::CCCardinalSplineTo>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCCardinalSplineTo>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCCardinalSplineTo>>::ModifyBase;
		using Base = cocos2d::CCCardinalSplineTo;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0x26cbac, Default, cocos2d::CCCardinalSplineTo, )
			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0x26cc68, Default, cocos2d::CCCardinalSplineTo)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x26cab4, Default, cocos2d::CCCardinalSplineTo, create, float, cocos2d::CCPointArray*, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x26cdfc, Default, cocos2d::CCCardinalSplineTo, copyWithZone, cocos2d::CCZone*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x26cd88, Default, cocos2d::CCCardinalSplineTo, startWithTarget, cocos2d::CCNode*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x26cf18, Default, cocos2d::CCCardinalSplineTo, update, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x26d1c8, Default, cocos2d::CCCardinalSplineTo, reverse, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x26d190, Default, cocos2d::CCCardinalSplineTo, updatePosition, cocos2d::CCPoint&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x26cc08, Default, cocos2d::CCCardinalSplineTo, initWithDuration, float, cocos2d::CCPointArray*, float)
		}
	};
}
