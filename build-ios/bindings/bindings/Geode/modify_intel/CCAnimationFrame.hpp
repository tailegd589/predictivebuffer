#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <cocos2d.h>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_copyWithZone
		#define GEODE_STATICS_copyWithZone
		GEODE_AS_STATIC_FUNCTION(copyWithZone) 
	#endif

	#ifndef GEODE_STATICS_initWithSpriteFrame
		#define GEODE_STATICS_initWithSpriteFrame
		GEODE_AS_STATIC_FUNCTION(initWithSpriteFrame) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_copyWithZone
		#define GEODE_CONCEPT_CHECK_copyWithZone
		GEODE_CONCEPT_FUNCTION_CHECK(copyWithZone) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_initWithSpriteFrame
		#define GEODE_CONCEPT_CHECK_initWithSpriteFrame
		GEODE_CONCEPT_FUNCTION_CHECK(initWithSpriteFrame) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCAnimationFrame> : ModifyBase<ModifyDerive<Der, cocos2d::CCAnimationFrame>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCAnimationFrame>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCAnimationFrame>>::ModifyBase;
		using Base = cocos2d::CCAnimationFrame;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0x296480, Default, cocos2d::CCAnimationFrame, )
			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0x296550, Default, cocos2d::CCAnimationFrame)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x296640, Default, cocos2d::CCAnimationFrame, copyWithZone, cocos2d::CCZone*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x2964c0, Default, cocos2d::CCAnimationFrame, initWithSpriteFrame, cocos2d::CCSpriteFrame*, float, cocos2d::CCDictionary*)
		}
	};
}
