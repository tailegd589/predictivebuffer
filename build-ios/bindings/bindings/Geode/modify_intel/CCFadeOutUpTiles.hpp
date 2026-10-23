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

	#ifndef GEODE_STATICS_testFunc
		#define GEODE_STATICS_testFunc
		GEODE_AS_STATIC_FUNCTION(testFunc) 
	#endif

	#ifndef GEODE_STATICS_transformTile
		#define GEODE_STATICS_transformTile
		GEODE_AS_STATIC_FUNCTION(transformTile) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_testFunc
		#define GEODE_CONCEPT_CHECK_testFunc
		GEODE_CONCEPT_FUNCTION_CHECK(testFunc) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_transformTile
		#define GEODE_CONCEPT_CHECK_transformTile
		GEODE_CONCEPT_FUNCTION_CHECK(transformTile) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCFadeOutUpTiles> : ModifyBase<ModifyDerive<Der, cocos2d::CCFadeOutUpTiles>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCFadeOutUpTiles>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCFadeOutUpTiles>>::ModifyBase;
		using Base = cocos2d::CCFadeOutUpTiles;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x7b68e0, Default, cocos2d::CCFadeOutUpTiles, create, float, cocos2d::CCSize const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x7b69c0, Default, cocos2d::CCFadeOutUpTiles, testFunc, cocos2d::CCSize const&, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x7b6a40, Default, cocos2d::CCFadeOutUpTiles, transformTile, cocos2d::CCPoint const&, float)
		}
	};
}
