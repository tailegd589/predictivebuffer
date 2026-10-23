#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <cocos2d.h>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_rectForGID
		#define GEODE_STATICS_rectForGID
		GEODE_AS_STATIC_FUNCTION(rectForGID) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_rectForGID
		#define GEODE_CONCEPT_CHECK_rectForGID
		GEODE_CONCEPT_FUNCTION_CHECK(rectForGID) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCTMXTilesetInfo> : ModifyBase<ModifyDerive<Der, cocos2d::CCTMXTilesetInfo>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCTMXTilesetInfo>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCTMXTilesetInfo>>::ModifyBase;
		using Base = cocos2d::CCTMXTilesetInfo;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0x42bc28, Default, cocos2d::CCTMXTilesetInfo, )
			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0x42bd00, Default, cocos2d::CCTMXTilesetInfo)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x42be34, Default, cocos2d::CCTMXTilesetInfo, rectForGID, unsigned int)
		}
	};
}
