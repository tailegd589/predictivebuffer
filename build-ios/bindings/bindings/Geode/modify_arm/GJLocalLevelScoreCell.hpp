#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <Geode/binding/GJLocalLevelScoreCell.hpp>
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

	#ifndef GEODE_STATICS_loadFromScore
		#define GEODE_STATICS_loadFromScore
		GEODE_AS_STATIC_FUNCTION(loadFromScore) 
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

	#ifndef GEODE_CONCEPT_CHECK_loadFromScore
		#define GEODE_CONCEPT_CHECK_loadFromScore
		GEODE_CONCEPT_FUNCTION_CHECK(loadFromScore) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_updateBGColor
		#define GEODE_CONCEPT_CHECK_updateBGColor
		GEODE_CONCEPT_FUNCTION_CHECK(updateBGColor) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, GJLocalLevelScoreCell> : ModifyBase<ModifyDerive<Der, GJLocalLevelScoreCell>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, GJLocalLevelScoreCell>>;
		using ModifyBase<ModifyDerive<Der, GJLocalLevelScoreCell>>::ModifyBase;
		using Base = GJLocalLevelScoreCell;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0x1fb8cc, Default, GJLocalLevelScoreCell, char const*, float, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1fb910, Default, GJLocalLevelScoreCell, init, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1fb91c, Default, GJLocalLevelScoreCell, draw, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1f22a8, Default, GJLocalLevelScoreCell, loadFromScore, GJLocalScore*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1f251c, Default, GJLocalLevelScoreCell, updateBGColor, int)
		}
	};
}
