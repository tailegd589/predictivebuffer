#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <Geode/binding/GJTransformControl.hpp>
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

	#ifndef GEODE_STATICS_ccTouchBegan
		#define GEODE_STATICS_ccTouchBegan
		GEODE_AS_STATIC_FUNCTION(ccTouchBegan) 
	#endif

	#ifndef GEODE_STATICS_ccTouchMoved
		#define GEODE_STATICS_ccTouchMoved
		GEODE_AS_STATIC_FUNCTION(ccTouchMoved) 
	#endif

	#ifndef GEODE_STATICS_ccTouchEnded
		#define GEODE_STATICS_ccTouchEnded
		GEODE_AS_STATIC_FUNCTION(ccTouchEnded) 
	#endif

	#ifndef GEODE_STATICS_ccTouchCancelled
		#define GEODE_STATICS_ccTouchCancelled
		GEODE_AS_STATIC_FUNCTION(ccTouchCancelled) 
	#endif

	#ifndef GEODE_STATICS_applyRotation
		#define GEODE_STATICS_applyRotation
		GEODE_AS_STATIC_FUNCTION(applyRotation) 
	#endif

	#ifndef GEODE_STATICS_calculateRotationOffset
		#define GEODE_STATICS_calculateRotationOffset
		GEODE_AS_STATIC_FUNCTION(calculateRotationOffset) 
	#endif

	#ifndef GEODE_STATICS_finishTouch
		#define GEODE_STATICS_finishTouch
		GEODE_AS_STATIC_FUNCTION(finishTouch) 
	#endif

	#ifndef GEODE_STATICS_loadFromState
		#define GEODE_STATICS_loadFromState
		GEODE_AS_STATIC_FUNCTION(loadFromState) 
	#endif

	#ifndef GEODE_STATICS_loadValues
		#define GEODE_STATICS_loadValues
		GEODE_AS_STATIC_FUNCTION(loadValues) 
	#endif

	#ifndef GEODE_STATICS_logCurrentZeroPos
		#define GEODE_STATICS_logCurrentZeroPos
		GEODE_AS_STATIC_FUNCTION(logCurrentZeroPos) 
	#endif

	#ifndef GEODE_STATICS_onToggleLockScale
		#define GEODE_STATICS_onToggleLockScale
		GEODE_AS_STATIC_FUNCTION(onToggleLockScale) 
	#endif

	#ifndef GEODE_STATICS_refreshControl
		#define GEODE_STATICS_refreshControl
		GEODE_AS_STATIC_FUNCTION(refreshControl) 
	#endif

	#ifndef GEODE_STATICS_saveToState
		#define GEODE_STATICS_saveToState
		GEODE_AS_STATIC_FUNCTION(saveToState) 
	#endif

	#ifndef GEODE_STATICS_scaleButtons
		#define GEODE_STATICS_scaleButtons
		GEODE_AS_STATIC_FUNCTION(scaleButtons) 
	#endif

	#ifndef GEODE_STATICS_spriteByTag
		#define GEODE_STATICS_spriteByTag
		GEODE_AS_STATIC_FUNCTION(spriteByTag) 
	#endif

	#ifndef GEODE_STATICS_updateAnchorSprite
		#define GEODE_STATICS_updateAnchorSprite
		GEODE_AS_STATIC_FUNCTION(updateAnchorSprite) 
	#endif

	#ifndef GEODE_STATICS_updateButtons
		#define GEODE_STATICS_updateButtons
		GEODE_AS_STATIC_FUNCTION(updateButtons) 
	#endif

	#ifndef GEODE_STATICS_updateMinMaxPositions
		#define GEODE_STATICS_updateMinMaxPositions
		GEODE_AS_STATIC_FUNCTION(updateMinMaxPositions) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_init
		#define GEODE_CONCEPT_CHECK_init
		GEODE_CONCEPT_FUNCTION_CHECK(init) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_ccTouchBegan
		#define GEODE_CONCEPT_CHECK_ccTouchBegan
		GEODE_CONCEPT_FUNCTION_CHECK(ccTouchBegan) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_ccTouchMoved
		#define GEODE_CONCEPT_CHECK_ccTouchMoved
		GEODE_CONCEPT_FUNCTION_CHECK(ccTouchMoved) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_ccTouchEnded
		#define GEODE_CONCEPT_CHECK_ccTouchEnded
		GEODE_CONCEPT_FUNCTION_CHECK(ccTouchEnded) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_ccTouchCancelled
		#define GEODE_CONCEPT_CHECK_ccTouchCancelled
		GEODE_CONCEPT_FUNCTION_CHECK(ccTouchCancelled) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_applyRotation
		#define GEODE_CONCEPT_CHECK_applyRotation
		GEODE_CONCEPT_FUNCTION_CHECK(applyRotation) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_calculateRotationOffset
		#define GEODE_CONCEPT_CHECK_calculateRotationOffset
		GEODE_CONCEPT_FUNCTION_CHECK(calculateRotationOffset) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_finishTouch
		#define GEODE_CONCEPT_CHECK_finishTouch
		GEODE_CONCEPT_FUNCTION_CHECK(finishTouch) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_loadFromState
		#define GEODE_CONCEPT_CHECK_loadFromState
		GEODE_CONCEPT_FUNCTION_CHECK(loadFromState) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_loadValues
		#define GEODE_CONCEPT_CHECK_loadValues
		GEODE_CONCEPT_FUNCTION_CHECK(loadValues) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_logCurrentZeroPos
		#define GEODE_CONCEPT_CHECK_logCurrentZeroPos
		GEODE_CONCEPT_FUNCTION_CHECK(logCurrentZeroPos) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onToggleLockScale
		#define GEODE_CONCEPT_CHECK_onToggleLockScale
		GEODE_CONCEPT_FUNCTION_CHECK(onToggleLockScale) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_refreshControl
		#define GEODE_CONCEPT_CHECK_refreshControl
		GEODE_CONCEPT_FUNCTION_CHECK(refreshControl) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_saveToState
		#define GEODE_CONCEPT_CHECK_saveToState
		GEODE_CONCEPT_FUNCTION_CHECK(saveToState) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_scaleButtons
		#define GEODE_CONCEPT_CHECK_scaleButtons
		GEODE_CONCEPT_FUNCTION_CHECK(scaleButtons) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_spriteByTag
		#define GEODE_CONCEPT_CHECK_spriteByTag
		GEODE_CONCEPT_FUNCTION_CHECK(spriteByTag) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_updateAnchorSprite
		#define GEODE_CONCEPT_CHECK_updateAnchorSprite
		GEODE_CONCEPT_FUNCTION_CHECK(updateAnchorSprite) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_updateButtons
		#define GEODE_CONCEPT_CHECK_updateButtons
		GEODE_CONCEPT_FUNCTION_CHECK(updateButtons) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_updateMinMaxPositions
		#define GEODE_CONCEPT_CHECK_updateMinMaxPositions
		GEODE_CONCEPT_FUNCTION_CHECK(updateMinMaxPositions) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, GJTransformControl> : ModifyBase<ModifyDerive<Der, GJTransformControl>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, GJTransformControl>>;
		using ModifyBase<ModifyDerive<Der, GJTransformControl>>::ModifyBase;
		using Base = GJTransformControl;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0x54c50, Default, GJTransformControl, )
			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0x52e60, Default, GJTransformControl)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xbb50, Default, GJTransformControl, create, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x53170, Default, GJTransformControl, init, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x53620, Default, GJTransformControl, ccTouchBegan, cocos2d::CCTouch*, cocos2d::CCEvent*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x53aa0, Default, GJTransformControl, ccTouchMoved, cocos2d::CCTouch*, cocos2d::CCEvent*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x54020, Default, GJTransformControl, ccTouchEnded, cocos2d::CCTouch*, cocos2d::CCEvent*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x54230, Default, GJTransformControl, ccTouchCancelled, cocos2d::CCTouch*, cocos2d::CCEvent*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x40d90, Default, GJTransformControl, applyRotation, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x535d0, Default, GJTransformControl, calculateRotationOffset, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x40440, Default, GJTransformControl, finishTouch, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x53510, Default, GJTransformControl, loadFromState, GJTransformState&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x40c10, Default, GJTransformControl, loadValues, GameObject*, cocos2d::CCArray*, gd::unordered_map<int, GameObjectEditorState>&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x54270, Default, GJTransformControl, logCurrentZeroPos, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x53490, Default, GJTransformControl, onToggleLockScale, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4a630, Default, GJTransformControl, refreshControl, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x40e50, Default, GJTransformControl, saveToState, GJTransformState&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3dcd0, Default, GJTransformControl, scaleButtons, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x534f0, Default, GJTransformControl, spriteByTag, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x403f0, Default, GJTransformControl, updateAnchorSprite, cocos2d::CCPoint)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4ac60, Default, GJTransformControl, updateButtons, bool, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x54280, Default, GJTransformControl, updateMinMaxPositions, )
		}
	};
}
