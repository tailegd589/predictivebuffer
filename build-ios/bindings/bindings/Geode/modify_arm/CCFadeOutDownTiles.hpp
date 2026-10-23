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

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_testFunc
		#define GEODE_CONCEPT_CHECK_testFunc
		GEODE_CONCEPT_FUNCTION_CHECK(testFunc) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCFadeOutDownTiles> : ModifyBase<ModifyDerive<Der, cocos2d::CCFadeOutDownTiles>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCFadeOutDownTiles>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCFadeOutDownTiles>>::ModifyBase;
		using Base = cocos2d::CCFadeOutDownTiles;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x6bca54, Default, cocos2d::CCFadeOutDownTiles, create, float, cocos2d::CCSize const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x6bcb34, Default, cocos2d::CCFadeOutDownTiles, testFunc, cocos2d::CCSize const&, float)
		}
	};
}
