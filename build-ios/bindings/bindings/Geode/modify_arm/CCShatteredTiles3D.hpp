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

	#ifndef GEODE_STATICS_initWithDuration
		#define GEODE_STATICS_initWithDuration
		GEODE_AS_STATIC_FUNCTION(initWithDuration) 
	#endif

	#ifndef GEODE_STATICS_copyWithZone
		#define GEODE_STATICS_copyWithZone
		GEODE_AS_STATIC_FUNCTION(copyWithZone) 
	#endif

	#ifndef GEODE_STATICS_update
		#define GEODE_STATICS_update
		GEODE_AS_STATIC_FUNCTION(update) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_initWithDuration
		#define GEODE_CONCEPT_CHECK_initWithDuration
		GEODE_CONCEPT_FUNCTION_CHECK(initWithDuration) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_copyWithZone
		#define GEODE_CONCEPT_CHECK_copyWithZone
		GEODE_CONCEPT_FUNCTION_CHECK(copyWithZone) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_update
		#define GEODE_CONCEPT_CHECK_update
		GEODE_CONCEPT_FUNCTION_CHECK(update) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCShatteredTiles3D> : ModifyBase<ModifyDerive<Der, cocos2d::CCShatteredTiles3D>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCShatteredTiles3D>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCShatteredTiles3D>>::ModifyBase;
		using Base = cocos2d::CCShatteredTiles3D;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x6bb46c, Default, cocos2d::CCShatteredTiles3D, create, float, cocos2d::CCSize const&, int, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x6bb56c, Default, cocos2d::CCShatteredTiles3D, initWithDuration, float, cocos2d::CCSize const&, int, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x6bb5ac, Default, cocos2d::CCShatteredTiles3D, copyWithZone, cocos2d::CCZone*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x6bb6c4, Default, cocos2d::CCShatteredTiles3D, update, float)
		}
	};
}
