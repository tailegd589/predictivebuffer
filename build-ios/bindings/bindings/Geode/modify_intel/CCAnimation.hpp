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

	#ifndef GEODE_STATICS_createWithSpriteFrames
		#define GEODE_STATICS_createWithSpriteFrames
		GEODE_AS_STATIC_FUNCTION(createWithSpriteFrames) 
	#endif

	#ifndef GEODE_STATICS_copyWithZone
		#define GEODE_STATICS_copyWithZone
		GEODE_AS_STATIC_FUNCTION(copyWithZone) 
	#endif

	#ifndef GEODE_STATICS_getDuration
		#define GEODE_STATICS_getDuration
		GEODE_AS_STATIC_FUNCTION(getDuration) 
	#endif

	#ifndef GEODE_STATICS_addSpriteFrame
		#define GEODE_STATICS_addSpriteFrame
		GEODE_AS_STATIC_FUNCTION(addSpriteFrame) 
	#endif

	#ifndef GEODE_STATICS_addSpriteFrameWithFileName
		#define GEODE_STATICS_addSpriteFrameWithFileName
		GEODE_AS_STATIC_FUNCTION(addSpriteFrameWithFileName) 
	#endif

	#ifndef GEODE_STATICS_addSpriteFrameWithTexture
		#define GEODE_STATICS_addSpriteFrameWithTexture
		GEODE_AS_STATIC_FUNCTION(addSpriteFrameWithTexture) 
	#endif

	#ifndef GEODE_STATICS_init
		#define GEODE_STATICS_init
		GEODE_AS_STATIC_FUNCTION(init) 
	#endif

	#ifndef GEODE_STATICS_initWithAnimationFrames
		#define GEODE_STATICS_initWithAnimationFrames
		GEODE_AS_STATIC_FUNCTION(initWithAnimationFrames) 
	#endif

	#ifndef GEODE_STATICS_initWithSpriteFrames
		#define GEODE_STATICS_initWithSpriteFrames
		GEODE_AS_STATIC_FUNCTION(initWithSpriteFrames) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_createWithSpriteFrames
		#define GEODE_CONCEPT_CHECK_createWithSpriteFrames
		GEODE_CONCEPT_FUNCTION_CHECK(createWithSpriteFrames) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_copyWithZone
		#define GEODE_CONCEPT_CHECK_copyWithZone
		GEODE_CONCEPT_FUNCTION_CHECK(copyWithZone) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getDuration
		#define GEODE_CONCEPT_CHECK_getDuration
		GEODE_CONCEPT_FUNCTION_CHECK(getDuration) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_addSpriteFrame
		#define GEODE_CONCEPT_CHECK_addSpriteFrame
		GEODE_CONCEPT_FUNCTION_CHECK(addSpriteFrame) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_addSpriteFrameWithFileName
		#define GEODE_CONCEPT_CHECK_addSpriteFrameWithFileName
		GEODE_CONCEPT_FUNCTION_CHECK(addSpriteFrameWithFileName) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_addSpriteFrameWithTexture
		#define GEODE_CONCEPT_CHECK_addSpriteFrameWithTexture
		GEODE_CONCEPT_FUNCTION_CHECK(addSpriteFrameWithTexture) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_init
		#define GEODE_CONCEPT_CHECK_init
		GEODE_CONCEPT_FUNCTION_CHECK(init) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_initWithAnimationFrames
		#define GEODE_CONCEPT_CHECK_initWithAnimationFrames
		GEODE_CONCEPT_FUNCTION_CHECK(initWithAnimationFrames) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_initWithSpriteFrames
		#define GEODE_CONCEPT_CHECK_initWithSpriteFrames
		GEODE_CONCEPT_FUNCTION_CHECK(initWithSpriteFrames) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCAnimation> : ModifyBase<ModifyDerive<Der, cocos2d::CCAnimation>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCAnimation>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCAnimation>>::ModifyBase;
		using Base = cocos2d::CCAnimation;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0x296c90, Default, cocos2d::CCAnimation, )
			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0x296ce0, Default, cocos2d::CCAnimation)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x2967a0, Default, cocos2d::CCAnimation, create, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x296ae0, Default, cocos2d::CCAnimation, create, cocos2d::CCArray*, float, unsigned int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x2968e0, Default, cocos2d::CCAnimation, createWithSpriteFrames, cocos2d::CCArray*, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x296f40, Default, cocos2d::CCAnimation, copyWithZone, cocos2d::CCZone*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x296f30, Default, cocos2d::CCAnimation, getDuration, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x296da0, Default, cocos2d::CCAnimation, addSpriteFrame, cocos2d::CCSpriteFrame*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x296e80, Default, cocos2d::CCAnimation, addSpriteFrameWithFileName, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x296f00, Default, cocos2d::CCAnimation, addSpriteFrameWithTexture, cocos2d::CCTexture2D*, cocos2d::CCRect const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x296890, Default, cocos2d::CCAnimation, init, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x296bf0, Default, cocos2d::CCAnimation, initWithAnimationFrames, cocos2d::CCArray*, float, unsigned int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x296970, Default, cocos2d::CCAnimation, initWithSpriteFrames, cocos2d::CCArray*, float)
		}
	};
}
