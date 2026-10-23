#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <Geode/binding/ColorAction2.hpp>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_resetAction
		#define GEODE_STATICS_resetAction
		GEODE_AS_STATIC_FUNCTION(resetAction) 
	#endif

	#ifndef GEODE_STATICS_step
		#define GEODE_STATICS_step
		GEODE_AS_STATIC_FUNCTION(step) 
	#endif

	#ifndef GEODE_STATICS_updateCustomColor
		#define GEODE_STATICS_updateCustomColor
		GEODE_AS_STATIC_FUNCTION(updateCustomColor) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_resetAction
		#define GEODE_CONCEPT_CHECK_resetAction
		GEODE_CONCEPT_FUNCTION_CHECK(resetAction) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_step
		#define GEODE_CONCEPT_CHECK_step
		GEODE_CONCEPT_FUNCTION_CHECK(step) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_updateCustomColor
		#define GEODE_CONCEPT_CHECK_updateCustomColor
		GEODE_CONCEPT_FUNCTION_CHECK(updateCustomColor) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, ColorAction2> : ModifyBase<ModifyDerive<Der, ColorAction2>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, ColorAction2>>;
		using ModifyBase<ModifyDerive<Der, ColorAction2>>::ModifyBase;
		using Base = ColorAction2;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0x4ed610, Default, ColorAction2, cocos2d::ccColor3B, cocos2d::ccColor3B, float, double, bool, int, float, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4ed810, Default, ColorAction2, resetAction, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4ed710, Default, ColorAction2, step, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4ed830, Default, ColorAction2, updateCustomColor, cocos2d::ccColor3B, cocos2d::ccColor3B)
		}
	};
}
