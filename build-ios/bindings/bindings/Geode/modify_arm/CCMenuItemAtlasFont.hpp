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

	#ifndef GEODE_STATICS_initWithString
		#define GEODE_STATICS_initWithString
		GEODE_AS_STATIC_FUNCTION(initWithString) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_initWithString
		#define GEODE_CONCEPT_CHECK_initWithString
		GEODE_CONCEPT_FUNCTION_CHECK(initWithString) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCMenuItemAtlasFont> : ModifyBase<ModifyDerive<Der, cocos2d::CCMenuItemAtlasFont>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCMenuItemAtlasFont>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCMenuItemAtlasFont>>::ModifyBase;
		using Base = cocos2d::CCMenuItemAtlasFont;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x340f10, Default, cocos2d::CCMenuItemAtlasFont, create, char const*, char const*, int, int, char)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x340fd8, Default, cocos2d::CCMenuItemAtlasFont, create, char const*, char const*, int, int, char, cocos2d::CCObject*, cocos2d::SEL_MenuHandler)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3410bc, Default, cocos2d::CCMenuItemAtlasFont, initWithString, char const*, char const*, int, int, char, cocos2d::CCObject*, cocos2d::SEL_MenuHandler)
		}
	};
}
