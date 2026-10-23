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

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_initWithDuration
		#define GEODE_CONCEPT_CHECK_initWithDuration
		GEODE_CONCEPT_FUNCTION_CHECK(initWithDuration) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCTransitionSceneOriented> : ModifyBase<ModifyDerive<Der, cocos2d::CCTransitionSceneOriented>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCTransitionSceneOriented>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCTransitionSceneOriented>>::ModifyBase;
		using Base = cocos2d::CCTransitionSceneOriented;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0xbba00, Default, cocos2d::CCTransitionSceneOriented, )
			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0xbba40, Default, cocos2d::CCTransitionSceneOriented)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xbbb04, Default, cocos2d::CCTransitionSceneOriented, create, float, cocos2d::CCScene*, cocos2d::tOrientation)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xbbb8c, Default, cocos2d::CCTransitionSceneOriented, initWithDuration, float, cocos2d::CCScene*, cocos2d::tOrientation)
		}
	};
}
