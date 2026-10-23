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

	#ifndef GEODE_STATICS_addControlPoint
		#define GEODE_STATICS_addControlPoint
		GEODE_AS_STATIC_FUNCTION(addControlPoint) 
	#endif

	#ifndef GEODE_STATICS_count
		#define GEODE_STATICS_count
		GEODE_AS_STATIC_FUNCTION(count) 
	#endif

	#ifndef GEODE_STATICS_getControlPointAtIndex
		#define GEODE_STATICS_getControlPointAtIndex
		GEODE_AS_STATIC_FUNCTION(getControlPointAtIndex) 
	#endif

	#ifndef GEODE_STATICS_getControlPoints
		#define GEODE_STATICS_getControlPoints
		GEODE_AS_STATIC_FUNCTION(getControlPoints) 
	#endif

	#ifndef GEODE_STATICS_initWithCapacity
		#define GEODE_STATICS_initWithCapacity
		GEODE_AS_STATIC_FUNCTION(initWithCapacity) 
	#endif

	#ifndef GEODE_STATICS_insertControlPoint
		#define GEODE_STATICS_insertControlPoint
		GEODE_AS_STATIC_FUNCTION(insertControlPoint) 
	#endif

	#ifndef GEODE_STATICS_removeControlPointAtIndex
		#define GEODE_STATICS_removeControlPointAtIndex
		GEODE_AS_STATIC_FUNCTION(removeControlPointAtIndex) 
	#endif

	#ifndef GEODE_STATICS_replaceControlPoint
		#define GEODE_STATICS_replaceControlPoint
		GEODE_AS_STATIC_FUNCTION(replaceControlPoint) 
	#endif

	#ifndef GEODE_STATICS_reverse
		#define GEODE_STATICS_reverse
		GEODE_AS_STATIC_FUNCTION(reverse) 
	#endif

	#ifndef GEODE_STATICS_reverseInline
		#define GEODE_STATICS_reverseInline
		GEODE_AS_STATIC_FUNCTION(reverseInline) 
	#endif

	#ifndef GEODE_STATICS_setControlPoints
		#define GEODE_STATICS_setControlPoints
		GEODE_AS_STATIC_FUNCTION(setControlPoints) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_copyWithZone
		#define GEODE_CONCEPT_CHECK_copyWithZone
		GEODE_CONCEPT_FUNCTION_CHECK(copyWithZone) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_addControlPoint
		#define GEODE_CONCEPT_CHECK_addControlPoint
		GEODE_CONCEPT_FUNCTION_CHECK(addControlPoint) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_count
		#define GEODE_CONCEPT_CHECK_count
		GEODE_CONCEPT_FUNCTION_CHECK(count) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getControlPointAtIndex
		#define GEODE_CONCEPT_CHECK_getControlPointAtIndex
		GEODE_CONCEPT_FUNCTION_CHECK(getControlPointAtIndex) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getControlPoints
		#define GEODE_CONCEPT_CHECK_getControlPoints
		GEODE_CONCEPT_FUNCTION_CHECK(getControlPoints) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_initWithCapacity
		#define GEODE_CONCEPT_CHECK_initWithCapacity
		GEODE_CONCEPT_FUNCTION_CHECK(initWithCapacity) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_insertControlPoint
		#define GEODE_CONCEPT_CHECK_insertControlPoint
		GEODE_CONCEPT_FUNCTION_CHECK(insertControlPoint) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_removeControlPointAtIndex
		#define GEODE_CONCEPT_CHECK_removeControlPointAtIndex
		GEODE_CONCEPT_FUNCTION_CHECK(removeControlPointAtIndex) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_replaceControlPoint
		#define GEODE_CONCEPT_CHECK_replaceControlPoint
		GEODE_CONCEPT_FUNCTION_CHECK(replaceControlPoint) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_reverse
		#define GEODE_CONCEPT_CHECK_reverse
		GEODE_CONCEPT_FUNCTION_CHECK(reverse) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_reverseInline
		#define GEODE_CONCEPT_CHECK_reverseInline
		GEODE_CONCEPT_FUNCTION_CHECK(reverseInline) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setControlPoints
		#define GEODE_CONCEPT_CHECK_setControlPoints
		GEODE_CONCEPT_FUNCTION_CHECK(setControlPoints) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCPointArray> : ModifyBase<ModifyDerive<Der, cocos2d::CCPointArray>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCPointArray>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCPointArray>>::ModifyBase;
		using Base = cocos2d::CCPointArray;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0x26c2d0, Default, cocos2d::CCPointArray, )
			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0x26c128, Default, cocos2d::CCPointArray)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x26be2c, Default, cocos2d::CCPointArray, create, unsigned int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x26bef0, Default, cocos2d::CCPointArray, copyWithZone, cocos2d::CCZone*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x26c2fc, Default, cocos2d::CCPointArray, addControlPoint, cocos2d::CCPoint)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x26c784, Default, cocos2d::CCPointArray, count, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x26c6a8, Default, cocos2d::CCPointArray, getControlPointAtIndex, unsigned int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x26c2f4, Default, cocos2d::CCPointArray, getControlPoints, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x26bebc, Default, cocos2d::CCPointArray, initWithCapacity, unsigned int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x26c404, Default, cocos2d::CCPointArray, insertControlPoint, cocos2d::CCPoint&, unsigned int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x26c71c, Default, cocos2d::CCPointArray, removeControlPointAtIndex, unsigned int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x26c6e8, Default, cocos2d::CCPointArray, replaceControlPoint, cocos2d::CCPoint&, unsigned int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x26c798, Default, cocos2d::CCPointArray, reverse, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x26c9a8, Default, cocos2d::CCPointArray, reverseInline, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x26c0a4, Default, cocos2d::CCPointArray, setControlPoints, gd::vector<cocos2d::CCPoint*>*)
		}
	};
}
