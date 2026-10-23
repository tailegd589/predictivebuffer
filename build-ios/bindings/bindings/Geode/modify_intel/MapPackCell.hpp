#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <Geode/binding/MapPackCell.hpp>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_init
		#define GEODE_STATICS_init
		GEODE_AS_STATIC_FUNCTION(init) 
	#endif

	#ifndef GEODE_STATICS_draw
		#define GEODE_STATICS_draw
		GEODE_AS_STATIC_FUNCTION(draw) 
	#endif

	#ifndef GEODE_STATICS_loadFromMapPack
		#define GEODE_STATICS_loadFromMapPack
		GEODE_AS_STATIC_FUNCTION(loadFromMapPack) 
	#endif

	#ifndef GEODE_STATICS_onClaimReward
		#define GEODE_STATICS_onClaimReward
		GEODE_AS_STATIC_FUNCTION(onClaimReward) 
	#endif

	#ifndef GEODE_STATICS_onClick
		#define GEODE_STATICS_onClick
		GEODE_AS_STATIC_FUNCTION(onClick) 
	#endif

	#ifndef GEODE_STATICS_playCompleteEffect
		#define GEODE_STATICS_playCompleteEffect
		GEODE_AS_STATIC_FUNCTION(playCompleteEffect) 
	#endif

	#ifndef GEODE_STATICS_reloadCell
		#define GEODE_STATICS_reloadCell
		GEODE_AS_STATIC_FUNCTION(reloadCell) 
	#endif

	#ifndef GEODE_STATICS_updateBGColor
		#define GEODE_STATICS_updateBGColor
		GEODE_AS_STATIC_FUNCTION(updateBGColor) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_init
		#define GEODE_CONCEPT_CHECK_init
		GEODE_CONCEPT_FUNCTION_CHECK(init) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_draw
		#define GEODE_CONCEPT_CHECK_draw
		GEODE_CONCEPT_FUNCTION_CHECK(draw) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_loadFromMapPack
		#define GEODE_CONCEPT_CHECK_loadFromMapPack
		GEODE_CONCEPT_FUNCTION_CHECK(loadFromMapPack) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onClaimReward
		#define GEODE_CONCEPT_CHECK_onClaimReward
		GEODE_CONCEPT_FUNCTION_CHECK(onClaimReward) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onClick
		#define GEODE_CONCEPT_CHECK_onClick
		GEODE_CONCEPT_FUNCTION_CHECK(onClick) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_playCompleteEffect
		#define GEODE_CONCEPT_CHECK_playCompleteEffect
		GEODE_CONCEPT_FUNCTION_CHECK(playCompleteEffect) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_reloadCell
		#define GEODE_CONCEPT_CHECK_reloadCell
		GEODE_CONCEPT_FUNCTION_CHECK(reloadCell) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_updateBGColor
		#define GEODE_CONCEPT_CHECK_updateBGColor
		GEODE_CONCEPT_FUNCTION_CHECK(updateBGColor) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, MapPackCell> : ModifyBase<ModifyDerive<Der, MapPackCell>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, MapPackCell>>;
		using ModifyBase<ModifyDerive<Der, MapPackCell>>::ModifyBase;
		using Base = MapPackCell;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0x252670, Default, MapPackCell, char const*, float, float)
			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0x252360, Default, MapPackCell)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x252730, Default, MapPackCell, init, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x252be0, Default, MapPackCell, draw, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x244990, Default, MapPackCell, loadFromMapPack, GJMapPack*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x252930, Default, MapPackCell, onClaimReward, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x252780, Default, MapPackCell, onClick, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x2529b0, Default, MapPackCell, playCompleteEffect, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x24e5a0, Default, MapPackCell, reloadCell, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x2454f0, Default, MapPackCell, updateBGColor, int)
		}
	};
}
