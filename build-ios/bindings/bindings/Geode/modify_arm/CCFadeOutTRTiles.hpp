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

	#ifndef GEODE_STATICS_update
		#define GEODE_STATICS_update
		GEODE_AS_STATIC_FUNCTION(update) 
	#endif

	#ifndef GEODE_STATICS_turnOffTile
		#define GEODE_STATICS_turnOffTile
		GEODE_AS_STATIC_FUNCTION(turnOffTile) 
	#endif

	#ifndef GEODE_STATICS_turnOnTile
		#define GEODE_STATICS_turnOnTile
		GEODE_AS_STATIC_FUNCTION(turnOnTile) 
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

	#ifndef GEODE_CONCEPT_CHECK_update
		#define GEODE_CONCEPT_CHECK_update
		GEODE_CONCEPT_FUNCTION_CHECK(update) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_turnOffTile
		#define GEODE_CONCEPT_CHECK_turnOffTile
		GEODE_CONCEPT_FUNCTION_CHECK(turnOffTile) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_turnOnTile
		#define GEODE_CONCEPT_CHECK_turnOnTile
		GEODE_CONCEPT_FUNCTION_CHECK(turnOnTile) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCFadeOutTRTiles> : ModifyBase<ModifyDerive<Der, cocos2d::CCFadeOutTRTiles>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCFadeOutTRTiles>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCFadeOutTRTiles>>::ModifyBase;
		using Base = cocos2d::CCFadeOutTRTiles;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x6bc2bc, Default, cocos2d::CCFadeOutTRTiles, create, float, cocos2d::CCSize const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x6bc39c, Default, cocos2d::CCFadeOutTRTiles, testFunc, cocos2d::CCSize const&, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x6bc490, Default, cocos2d::CCFadeOutTRTiles, transformTile, cocos2d::CCPoint const&, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x6bc550, Default, cocos2d::CCFadeOutTRTiles, update, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x6bc464, Default, cocos2d::CCFadeOutTRTiles, turnOffTile, cocos2d::CCPoint const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x6bc424, Default, cocos2d::CCFadeOutTRTiles, turnOnTile, cocos2d::CCPoint const&)
		}
	};
}
