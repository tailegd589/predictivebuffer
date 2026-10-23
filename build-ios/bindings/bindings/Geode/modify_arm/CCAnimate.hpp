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

	#ifndef GEODE_STATICS_startWithTarget
		#define GEODE_STATICS_startWithTarget
		GEODE_AS_STATIC_FUNCTION(startWithTarget) 
	#endif

	#ifndef GEODE_STATICS_stop
		#define GEODE_STATICS_stop
		GEODE_AS_STATIC_FUNCTION(stop) 
	#endif

	#ifndef GEODE_STATICS_reverse
		#define GEODE_STATICS_reverse
		GEODE_AS_STATIC_FUNCTION(reverse) 
	#endif

	#ifndef GEODE_STATICS_initWithAnimation
		#define GEODE_STATICS_initWithAnimation
		GEODE_AS_STATIC_FUNCTION(initWithAnimation) 
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

	#ifndef GEODE_CONCEPT_CHECK_startWithTarget
		#define GEODE_CONCEPT_CHECK_startWithTarget
		GEODE_CONCEPT_FUNCTION_CHECK(startWithTarget) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_stop
		#define GEODE_CONCEPT_CHECK_stop
		GEODE_CONCEPT_FUNCTION_CHECK(stop) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_reverse
		#define GEODE_CONCEPT_CHECK_reverse
		GEODE_CONCEPT_FUNCTION_CHECK(reverse) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_initWithAnimation
		#define GEODE_CONCEPT_CHECK_initWithAnimation
		GEODE_CONCEPT_FUNCTION_CHECK(initWithAnimation) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCAnimate> : ModifyBase<ModifyDerive<Der, cocos2d::CCAnimate>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCAnimate>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCAnimate>>::ModifyBase;
		using Base = cocos2d::CCAnimate;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0x33e694, Default, cocos2d::CCAnimate, )
			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0x33e700, Default, cocos2d::CCAnimate)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x33e250, Default, cocos2d::CCAnimate, create, cocos2d::CCAnimation*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x33e58c, Default, cocos2d::CCAnimate, copyWithZone, cocos2d::CCZone*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x33e83c, Default, cocos2d::CCAnimate, update, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x33e784, Default, cocos2d::CCAnimate, startWithTarget, cocos2d::CCNode*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x33e7f0, Default, cocos2d::CCAnimate, stop, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x33ea50, Default, cocos2d::CCAnimate, reverse, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x33e360, Default, cocos2d::CCAnimate, initWithAnimation, cocos2d::CCAnimation*)
		}
	};
}
