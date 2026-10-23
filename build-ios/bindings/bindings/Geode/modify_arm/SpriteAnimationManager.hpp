#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <Geode/binding/SpriteAnimationManager.hpp>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_createAnimations
		#define GEODE_STATICS_createAnimations
		GEODE_AS_STATIC_FUNCTION(createAnimations) 
	#endif

	#ifndef GEODE_STATICS_createWithOwner
		#define GEODE_STATICS_createWithOwner
		GEODE_AS_STATIC_FUNCTION(createWithOwner) 
	#endif

	#ifndef GEODE_STATICS_animationFinished
		#define GEODE_STATICS_animationFinished
		GEODE_AS_STATIC_FUNCTION(animationFinished) 
	#endif

	#ifndef GEODE_STATICS_callAnimationFinished
		#define GEODE_STATICS_callAnimationFinished
		GEODE_AS_STATIC_FUNCTION(callAnimationFinished) 
	#endif

	#ifndef GEODE_STATICS_doCleanup
		#define GEODE_STATICS_doCleanup
		GEODE_AS_STATIC_FUNCTION(doCleanup) 
	#endif

	#ifndef GEODE_STATICS_executeAnimation
		#define GEODE_STATICS_executeAnimation
		GEODE_AS_STATIC_FUNCTION(executeAnimation) 
	#endif

	#ifndef GEODE_STATICS_finishAnimation
		#define GEODE_STATICS_finishAnimation
		GEODE_AS_STATIC_FUNCTION(finishAnimation) 
	#endif

	#ifndef GEODE_STATICS_getAnimType
		#define GEODE_STATICS_getAnimType
		GEODE_AS_STATIC_FUNCTION(getAnimType) 
	#endif

	#ifndef GEODE_STATICS_getPrio
		#define GEODE_STATICS_getPrio
		GEODE_AS_STATIC_FUNCTION(getPrio) 
	#endif

	#ifndef GEODE_STATICS_initWithOwner
		#define GEODE_STATICS_initWithOwner
		GEODE_AS_STATIC_FUNCTION(initWithOwner) 
	#endif

	#ifndef GEODE_STATICS_loadAnimations
		#define GEODE_STATICS_loadAnimations
		GEODE_AS_STATIC_FUNCTION(loadAnimations) 
	#endif

	#ifndef GEODE_STATICS_offsetCurrentAnimation
		#define GEODE_STATICS_offsetCurrentAnimation
		GEODE_AS_STATIC_FUNCTION(offsetCurrentAnimation) 
	#endif

	#ifndef GEODE_STATICS_overridePrio
		#define GEODE_STATICS_overridePrio
		GEODE_AS_STATIC_FUNCTION(overridePrio) 
	#endif

	#ifndef GEODE_STATICS_playSound
		#define GEODE_STATICS_playSound
		GEODE_AS_STATIC_FUNCTION(playSound) 
	#endif

	#ifndef GEODE_STATICS_playSoundForAnimation
		#define GEODE_STATICS_playSoundForAnimation
		GEODE_AS_STATIC_FUNCTION(playSoundForAnimation) 
	#endif

	#ifndef GEODE_STATICS_queueAnimation
		#define GEODE_STATICS_queueAnimation
		GEODE_AS_STATIC_FUNCTION(queueAnimation) 
	#endif

	#ifndef GEODE_STATICS_resetAnimState
		#define GEODE_STATICS_resetAnimState
		GEODE_AS_STATIC_FUNCTION(resetAnimState) 
	#endif

	#ifndef GEODE_STATICS_runAnimation
		#define GEODE_STATICS_runAnimation
		GEODE_AS_STATIC_FUNCTION(runAnimation) 
	#endif

	#ifndef GEODE_STATICS_runQueuedAnimation
		#define GEODE_STATICS_runQueuedAnimation
		GEODE_AS_STATIC_FUNCTION(runQueuedAnimation) 
	#endif

	#ifndef GEODE_STATICS_stopAnimations
		#define GEODE_STATICS_stopAnimations
		GEODE_AS_STATIC_FUNCTION(stopAnimations) 
	#endif

	#ifndef GEODE_STATICS_storeAnimation
		#define GEODE_STATICS_storeAnimation
		GEODE_AS_STATIC_FUNCTION(storeAnimation) 
	#endif

	#ifndef GEODE_STATICS_storeSoundForAnimation
		#define GEODE_STATICS_storeSoundForAnimation
		GEODE_AS_STATIC_FUNCTION(storeSoundForAnimation) 
	#endif

	#ifndef GEODE_STATICS_switchToFirstFrameOfAnimation
		#define GEODE_STATICS_switchToFirstFrameOfAnimation
		GEODE_AS_STATIC_FUNCTION(switchToFirstFrameOfAnimation) 
	#endif

	#ifndef GEODE_STATICS_updateAnimationSpeed
		#define GEODE_STATICS_updateAnimationSpeed
		GEODE_AS_STATIC_FUNCTION(updateAnimationSpeed) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_createAnimations
		#define GEODE_CONCEPT_CHECK_createAnimations
		GEODE_CONCEPT_FUNCTION_CHECK(createAnimations) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_createWithOwner
		#define GEODE_CONCEPT_CHECK_createWithOwner
		GEODE_CONCEPT_FUNCTION_CHECK(createWithOwner) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_animationFinished
		#define GEODE_CONCEPT_CHECK_animationFinished
		GEODE_CONCEPT_FUNCTION_CHECK(animationFinished) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_callAnimationFinished
		#define GEODE_CONCEPT_CHECK_callAnimationFinished
		GEODE_CONCEPT_FUNCTION_CHECK(callAnimationFinished) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_doCleanup
		#define GEODE_CONCEPT_CHECK_doCleanup
		GEODE_CONCEPT_FUNCTION_CHECK(doCleanup) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_executeAnimation
		#define GEODE_CONCEPT_CHECK_executeAnimation
		GEODE_CONCEPT_FUNCTION_CHECK(executeAnimation) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_finishAnimation
		#define GEODE_CONCEPT_CHECK_finishAnimation
		GEODE_CONCEPT_FUNCTION_CHECK(finishAnimation) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getAnimType
		#define GEODE_CONCEPT_CHECK_getAnimType
		GEODE_CONCEPT_FUNCTION_CHECK(getAnimType) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getPrio
		#define GEODE_CONCEPT_CHECK_getPrio
		GEODE_CONCEPT_FUNCTION_CHECK(getPrio) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_initWithOwner
		#define GEODE_CONCEPT_CHECK_initWithOwner
		GEODE_CONCEPT_FUNCTION_CHECK(initWithOwner) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_loadAnimations
		#define GEODE_CONCEPT_CHECK_loadAnimations
		GEODE_CONCEPT_FUNCTION_CHECK(loadAnimations) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_offsetCurrentAnimation
		#define GEODE_CONCEPT_CHECK_offsetCurrentAnimation
		GEODE_CONCEPT_FUNCTION_CHECK(offsetCurrentAnimation) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_overridePrio
		#define GEODE_CONCEPT_CHECK_overridePrio
		GEODE_CONCEPT_FUNCTION_CHECK(overridePrio) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_playSound
		#define GEODE_CONCEPT_CHECK_playSound
		GEODE_CONCEPT_FUNCTION_CHECK(playSound) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_playSoundForAnimation
		#define GEODE_CONCEPT_CHECK_playSoundForAnimation
		GEODE_CONCEPT_FUNCTION_CHECK(playSoundForAnimation) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_queueAnimation
		#define GEODE_CONCEPT_CHECK_queueAnimation
		GEODE_CONCEPT_FUNCTION_CHECK(queueAnimation) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_resetAnimState
		#define GEODE_CONCEPT_CHECK_resetAnimState
		GEODE_CONCEPT_FUNCTION_CHECK(resetAnimState) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_runAnimation
		#define GEODE_CONCEPT_CHECK_runAnimation
		GEODE_CONCEPT_FUNCTION_CHECK(runAnimation) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_runQueuedAnimation
		#define GEODE_CONCEPT_CHECK_runQueuedAnimation
		GEODE_CONCEPT_FUNCTION_CHECK(runQueuedAnimation) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_stopAnimations
		#define GEODE_CONCEPT_CHECK_stopAnimations
		GEODE_CONCEPT_FUNCTION_CHECK(stopAnimations) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_storeAnimation
		#define GEODE_CONCEPT_CHECK_storeAnimation
		GEODE_CONCEPT_FUNCTION_CHECK(storeAnimation) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_storeSoundForAnimation
		#define GEODE_CONCEPT_CHECK_storeSoundForAnimation
		GEODE_CONCEPT_FUNCTION_CHECK(storeSoundForAnimation) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_switchToFirstFrameOfAnimation
		#define GEODE_CONCEPT_CHECK_switchToFirstFrameOfAnimation
		GEODE_CONCEPT_FUNCTION_CHECK(switchToFirstFrameOfAnimation) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_updateAnimationSpeed
		#define GEODE_CONCEPT_CHECK_updateAnimationSpeed
		GEODE_CONCEPT_FUNCTION_CHECK(updateAnimationSpeed) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, SpriteAnimationManager> : ModifyBase<ModifyDerive<Der, SpriteAnimationManager>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, SpriteAnimationManager>>;
		using ModifyBase<ModifyDerive<Der, SpriteAnimationManager>>::ModifyBase;
		using Base = SpriteAnimationManager;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0x636e98, Default, SpriteAnimationManager)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x633f14, Default, SpriteAnimationManager, createAnimations, gd::string)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x633c00, Default, SpriteAnimationManager, createWithOwner, CCAnimatedSprite*, gd::string)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x635894, Default, SpriteAnimationManager, animationFinished, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x6369b0, Default, SpriteAnimationManager, callAnimationFinished, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x636e70, Default, SpriteAnimationManager, doCleanup, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x636320, Default, SpriteAnimationManager, executeAnimation, gd::string)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x636ac4, Default, SpriteAnimationManager, finishAnimation, gd::string)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x6366d0, Default, SpriteAnimationManager, getAnimType, gd::string)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x636140, Default, SpriteAnimationManager, getPrio, gd::string)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x633ce8, Default, SpriteAnimationManager, initWithOwner, CCAnimatedSprite*, gd::string)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x634e14, Default, SpriteAnimationManager, loadAnimations, gd::string)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x636bd0, Default, SpriteAnimationManager, offsetCurrentAnimation, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x6366e8, Default, SpriteAnimationManager, overridePrio, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x635dd0, Default, SpriteAnimationManager, playSound, gd::string)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x635bf4, Default, SpriteAnimationManager, playSoundForAnimation, gd::string)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x636168, Default, SpriteAnimationManager, queueAnimation, gd::string)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x636c48, Default, SpriteAnimationManager, resetAnimState, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x635dd4, Default, SpriteAnimationManager, runAnimation, gd::string)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x636798, Default, SpriteAnimationManager, runQueuedAnimation, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x6368e0, Default, SpriteAnimationManager, stopAnimations, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x6358f8, Default, SpriteAnimationManager, storeAnimation, cocos2d::CCAnimate*, cocos2d::CCAnimate*, gd::string, int, spriteMode, cocos2d::CCSpriteFrame*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x635834, Default, SpriteAnimationManager, storeSoundForAnimation, cocos2d::CCString*, gd::string, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x636c80, Default, SpriteAnimationManager, switchToFirstFrameOfAnimation, gd::string)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x635bb0, Default, SpriteAnimationManager, updateAnimationSpeed, float)
		}
	};
}
