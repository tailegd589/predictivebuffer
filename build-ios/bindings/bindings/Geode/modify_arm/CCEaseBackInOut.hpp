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

	#ifndef GEODE_STATICS_reverse
		#define GEODE_STATICS_reverse
		GEODE_AS_STATIC_FUNCTION(reverse) 
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

	#ifndef GEODE_CONCEPT_CHECK_reverse
		#define GEODE_CONCEPT_CHECK_reverse
		GEODE_CONCEPT_FUNCTION_CHECK(reverse) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCEaseBackInOut> : ModifyBase<ModifyDerive<Der, cocos2d::CCEaseBackInOut>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCEaseBackInOut>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCEaseBackInOut>>::ModifyBase;
		using Base = cocos2d::CCEaseBackInOut;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x46df6c, Default, cocos2d::CCEaseBackInOut, create, cocos2d::CCActionInterval*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x46e014, Default, cocos2d::CCEaseBackInOut, copyWithZone, cocos2d::CCZone*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x46e0fc, Default, cocos2d::CCEaseBackInOut, update, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x46e190, Default, cocos2d::CCEaseBackInOut, reverse, )
		}
	};
}
