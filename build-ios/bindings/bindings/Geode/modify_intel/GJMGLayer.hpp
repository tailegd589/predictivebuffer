#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <Geode/binding/GJMGLayer.hpp>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_create
		#define GEODE_STATICS_create
		GEODE_AS_STATIC_FUNCTION(create) 
	#endif

	#ifndef GEODE_STATICS_defaultYOffsetForBG2
		#define GEODE_STATICS_defaultYOffsetForBG2
		GEODE_AS_STATIC_FUNCTION(defaultYOffsetForBG2) 
	#endif

	#ifndef GEODE_STATICS_draw
		#define GEODE_STATICS_draw
		GEODE_AS_STATIC_FUNCTION(draw) 
	#endif

	#ifndef GEODE_STATICS_showGround
		#define GEODE_STATICS_showGround
		GEODE_AS_STATIC_FUNCTION(showGround) 
	#endif

	#ifndef GEODE_STATICS_deactivateGround
		#define GEODE_STATICS_deactivateGround
		GEODE_AS_STATIC_FUNCTION(deactivateGround) 
	#endif

	#ifndef GEODE_STATICS_init
		#define GEODE_STATICS_init
		GEODE_AS_STATIC_FUNCTION(init) 
	#endif

	#ifndef GEODE_STATICS_loadGroundSprites
		#define GEODE_STATICS_loadGroundSprites
		GEODE_AS_STATIC_FUNCTION(loadGroundSprites) 
	#endif

	#ifndef GEODE_STATICS_scaleGround
		#define GEODE_STATICS_scaleGround
		GEODE_AS_STATIC_FUNCTION(scaleGround) 
	#endif

	#ifndef GEODE_STATICS_toggleVisible01
		#define GEODE_STATICS_toggleVisible01
		GEODE_AS_STATIC_FUNCTION(toggleVisible01) 
	#endif

	#ifndef GEODE_STATICS_toggleVisible02
		#define GEODE_STATICS_toggleVisible02
		GEODE_AS_STATIC_FUNCTION(toggleVisible02) 
	#endif

	#ifndef GEODE_STATICS_updateGroundColor
		#define GEODE_STATICS_updateGroundColor
		GEODE_AS_STATIC_FUNCTION(updateGroundColor) 
	#endif

	#ifndef GEODE_STATICS_updateGroundOpacity
		#define GEODE_STATICS_updateGroundOpacity
		GEODE_AS_STATIC_FUNCTION(updateGroundOpacity) 
	#endif

	#ifndef GEODE_STATICS_updateGroundPos
		#define GEODE_STATICS_updateGroundPos
		GEODE_AS_STATIC_FUNCTION(updateGroundPos) 
	#endif

	#ifndef GEODE_STATICS_updateGroundWidth
		#define GEODE_STATICS_updateGroundWidth
		GEODE_AS_STATIC_FUNCTION(updateGroundWidth) 
	#endif

	#ifndef GEODE_STATICS_updateMG01Blend
		#define GEODE_STATICS_updateMG01Blend
		GEODE_AS_STATIC_FUNCTION(updateMG01Blend) 
	#endif

	#ifndef GEODE_STATICS_updateMG02Blend
		#define GEODE_STATICS_updateMG02Blend
		GEODE_AS_STATIC_FUNCTION(updateMG02Blend) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_defaultYOffsetForBG2
		#define GEODE_CONCEPT_CHECK_defaultYOffsetForBG2
		GEODE_CONCEPT_FUNCTION_CHECK(defaultYOffsetForBG2) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_draw
		#define GEODE_CONCEPT_CHECK_draw
		GEODE_CONCEPT_FUNCTION_CHECK(draw) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_showGround
		#define GEODE_CONCEPT_CHECK_showGround
		GEODE_CONCEPT_FUNCTION_CHECK(showGround) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_deactivateGround
		#define GEODE_CONCEPT_CHECK_deactivateGround
		GEODE_CONCEPT_FUNCTION_CHECK(deactivateGround) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_init
		#define GEODE_CONCEPT_CHECK_init
		GEODE_CONCEPT_FUNCTION_CHECK(init) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_loadGroundSprites
		#define GEODE_CONCEPT_CHECK_loadGroundSprites
		GEODE_CONCEPT_FUNCTION_CHECK(loadGroundSprites) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_scaleGround
		#define GEODE_CONCEPT_CHECK_scaleGround
		GEODE_CONCEPT_FUNCTION_CHECK(scaleGround) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_toggleVisible01
		#define GEODE_CONCEPT_CHECK_toggleVisible01
		GEODE_CONCEPT_FUNCTION_CHECK(toggleVisible01) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_toggleVisible02
		#define GEODE_CONCEPT_CHECK_toggleVisible02
		GEODE_CONCEPT_FUNCTION_CHECK(toggleVisible02) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_updateGroundColor
		#define GEODE_CONCEPT_CHECK_updateGroundColor
		GEODE_CONCEPT_FUNCTION_CHECK(updateGroundColor) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_updateGroundOpacity
		#define GEODE_CONCEPT_CHECK_updateGroundOpacity
		GEODE_CONCEPT_FUNCTION_CHECK(updateGroundOpacity) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_updateGroundPos
		#define GEODE_CONCEPT_CHECK_updateGroundPos
		GEODE_CONCEPT_FUNCTION_CHECK(updateGroundPos) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_updateGroundWidth
		#define GEODE_CONCEPT_CHECK_updateGroundWidth
		GEODE_CONCEPT_FUNCTION_CHECK(updateGroundWidth) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_updateMG01Blend
		#define GEODE_CONCEPT_CHECK_updateMG01Blend
		GEODE_CONCEPT_FUNCTION_CHECK(updateMG01Blend) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_updateMG02Blend
		#define GEODE_CONCEPT_CHECK_updateMG02Blend
		GEODE_CONCEPT_FUNCTION_CHECK(updateMG02Blend) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, GJMGLayer> : ModifyBase<ModifyDerive<Der, GJMGLayer>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, GJMGLayer>>;
		using ModifyBase<ModifyDerive<Der, GJMGLayer>>::ModifyBase;
		using Base = GJMGLayer;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x5ebc50, Default, GJMGLayer, create, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x5ebc30, Default, GJMGLayer, defaultYOffsetForBG2, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x5ec700, Default, GJMGLayer, draw, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x5ec6d0, Default, GJMGLayer, showGround, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x5ec6e0, Default, GJMGLayer, deactivateGround, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x5ebd60, Default, GJMGLayer, init, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x5ec1f0, Default, GJMGLayer, loadGroundSprites, int, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x5ec560, Default, GJMGLayer, scaleGround, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x5ec420, Default, GJMGLayer, toggleVisible01, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x5ec460, Default, GJMGLayer, toggleVisible02, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x5ec390, Default, GJMGLayer, updateGroundColor, cocos2d::ccColor3B, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x5ec4e0, Default, GJMGLayer, updateGroundOpacity, unsigned char, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x5ec490, Default, GJMGLayer, updateGroundPos, cocos2d::CCPoint)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x5ec5f0, Default, GJMGLayer, updateGroundWidth, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x5ec710, Default, GJMGLayer, updateMG01Blend, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x5ec760, Default, GJMGLayer, updateMG02Blend, bool)
		}
	};
}
