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

	#ifndef GEODE_STATICS_onEnter
		#define GEODE_STATICS_onEnter
		GEODE_AS_STATIC_FUNCTION(onEnter) 
	#endif

	#ifndef GEODE_STATICS_onExit
		#define GEODE_STATICS_onExit
		GEODE_AS_STATIC_FUNCTION(onExit) 
	#endif

	#ifndef GEODE_STATICS_initWithDuration
		#define GEODE_STATICS_initWithDuration
		GEODE_AS_STATIC_FUNCTION(initWithDuration) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onEnter
		#define GEODE_CONCEPT_CHECK_onEnter
		GEODE_CONCEPT_FUNCTION_CHECK(onEnter) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onExit
		#define GEODE_CONCEPT_CHECK_onExit
		GEODE_CONCEPT_FUNCTION_CHECK(onExit) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_initWithDuration
		#define GEODE_CONCEPT_CHECK_initWithDuration
		GEODE_CONCEPT_FUNCTION_CHECK(initWithDuration) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCTransitionFade> : ModifyBase<ModifyDerive<Der, cocos2d::CCTransitionFade>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCTransitionFade>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCTransitionFade>>::ModifyBase;
		using Base = cocos2d::CCTransitionFade;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0xd8820, Default, cocos2d::CCTransitionFade, )
			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0xd8860, Default, cocos2d::CCTransitionFade)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xd89f0, Default, cocos2d::CCTransitionFade, create, float, cocos2d::CCScene*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xd8950, Default, cocos2d::CCTransitionFade, create, float, cocos2d::CCScene*, cocos2d::ccColor3B const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xd8ae0, Default, cocos2d::CCTransitionFade, onEnter, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xd8c10, Default, cocos2d::CCTransitionFade, onExit, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xd8ac0, Default, cocos2d::CCTransitionFade, initWithDuration, float, cocos2d::CCScene*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xd8a70, Default, cocos2d::CCTransitionFade, initWithDuration, float, cocos2d::CCScene*, cocos2d::ccColor3B const&)
		}
	};
}
