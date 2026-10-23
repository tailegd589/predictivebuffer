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

	#ifndef GEODE_STATICS_init
		#define GEODE_STATICS_init
		GEODE_AS_STATIC_FUNCTION(init) 
	#endif

	#ifndef GEODE_STATICS_initWithNormalImage
		#define GEODE_STATICS_initWithNormalImage
		GEODE_AS_STATIC_FUNCTION(initWithNormalImage) 
	#endif

	#ifndef GEODE_STATICS_setDisabledSpriteFrame
		#define GEODE_STATICS_setDisabledSpriteFrame
		GEODE_AS_STATIC_FUNCTION(setDisabledSpriteFrame) 
	#endif

	#ifndef GEODE_STATICS_setNormalSpriteFrame
		#define GEODE_STATICS_setNormalSpriteFrame
		GEODE_AS_STATIC_FUNCTION(setNormalSpriteFrame) 
	#endif

	#ifndef GEODE_STATICS_setSelectedSpriteFrame
		#define GEODE_STATICS_setSelectedSpriteFrame
		GEODE_AS_STATIC_FUNCTION(setSelectedSpriteFrame) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_init
		#define GEODE_CONCEPT_CHECK_init
		GEODE_CONCEPT_FUNCTION_CHECK(init) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_initWithNormalImage
		#define GEODE_CONCEPT_CHECK_initWithNormalImage
		GEODE_CONCEPT_FUNCTION_CHECK(initWithNormalImage) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setDisabledSpriteFrame
		#define GEODE_CONCEPT_CHECK_setDisabledSpriteFrame
		GEODE_CONCEPT_FUNCTION_CHECK(setDisabledSpriteFrame) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setNormalSpriteFrame
		#define GEODE_CONCEPT_CHECK_setNormalSpriteFrame
		GEODE_CONCEPT_FUNCTION_CHECK(setNormalSpriteFrame) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setSelectedSpriteFrame
		#define GEODE_CONCEPT_CHECK_setSelectedSpriteFrame
		GEODE_CONCEPT_FUNCTION_CHECK(setSelectedSpriteFrame) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCMenuItemImage> : ModifyBase<ModifyDerive<Der, cocos2d::CCMenuItemImage>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCMenuItemImage>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCMenuItemImage>>::ModifyBase;
		using Base = cocos2d::CCMenuItemImage;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x341df4, Default, cocos2d::CCMenuItemImage, create, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x342168, Default, cocos2d::CCMenuItemImage, create, char const*, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x342388, Default, cocos2d::CCMenuItemImage, create, char const*, char const*, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3422d0, Default, cocos2d::CCMenuItemImage, create, char const*, char const*, cocos2d::CCObject*, cocos2d::SEL_MenuHandler)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x34220c, Default, cocos2d::CCMenuItemImage, create, char const*, char const*, char const*, cocos2d::CCObject*, cocos2d::SEL_MenuHandler)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x341f30, Default, cocos2d::CCMenuItemImage, init, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x342018, Default, cocos2d::CCMenuItemImage, initWithNormalImage, char const*, char const*, char const*, cocos2d::CCObject*, cocos2d::SEL_MenuHandler)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x342498, Default, cocos2d::CCMenuItemImage, setDisabledSpriteFrame, cocos2d::CCSpriteFrame*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x342430, Default, cocos2d::CCMenuItemImage, setNormalSpriteFrame, cocos2d::CCSpriteFrame*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x342464, Default, cocos2d::CCMenuItemImage, setSelectedSpriteFrame, cocos2d::CCSpriteFrame*)
		}
	};
}
