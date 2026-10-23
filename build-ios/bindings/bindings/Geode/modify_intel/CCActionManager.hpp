#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <cocos2d.h>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_update
		#define GEODE_STATICS_update
		GEODE_AS_STATIC_FUNCTION(update) 
	#endif

	#ifndef GEODE_STATICS_actionAllocWithHashElement
		#define GEODE_STATICS_actionAllocWithHashElement
		GEODE_AS_STATIC_FUNCTION(actionAllocWithHashElement) 
	#endif

	#ifndef GEODE_STATICS_addAction
		#define GEODE_STATICS_addAction
		GEODE_AS_STATIC_FUNCTION(addAction) 
	#endif

	#ifndef GEODE_STATICS_deleteHashElement
		#define GEODE_STATICS_deleteHashElement
		GEODE_AS_STATIC_FUNCTION(deleteHashElement) 
	#endif

	#ifndef GEODE_STATICS_getActionByTag
		#define GEODE_STATICS_getActionByTag
		GEODE_AS_STATIC_FUNCTION(getActionByTag) 
	#endif

	#ifndef GEODE_STATICS_numberOfRunningActionsInTarget
		#define GEODE_STATICS_numberOfRunningActionsInTarget
		GEODE_AS_STATIC_FUNCTION(numberOfRunningActionsInTarget) 
	#endif

	#ifndef GEODE_STATICS_pauseAllRunningActions
		#define GEODE_STATICS_pauseAllRunningActions
		GEODE_AS_STATIC_FUNCTION(pauseAllRunningActions) 
	#endif

	#ifndef GEODE_STATICS_pauseTarget
		#define GEODE_STATICS_pauseTarget
		GEODE_AS_STATIC_FUNCTION(pauseTarget) 
	#endif

	#ifndef GEODE_STATICS_removeAction
		#define GEODE_STATICS_removeAction
		GEODE_AS_STATIC_FUNCTION(removeAction) 
	#endif

	#ifndef GEODE_STATICS_removeActionAtIndex
		#define GEODE_STATICS_removeActionAtIndex
		GEODE_AS_STATIC_FUNCTION(removeActionAtIndex) 
	#endif

	#ifndef GEODE_STATICS_removeActionByTag
		#define GEODE_STATICS_removeActionByTag
		GEODE_AS_STATIC_FUNCTION(removeActionByTag) 
	#endif

	#ifndef GEODE_STATICS_removeAllActions
		#define GEODE_STATICS_removeAllActions
		GEODE_AS_STATIC_FUNCTION(removeAllActions) 
	#endif

	#ifndef GEODE_STATICS_removeAllActionsFromTarget
		#define GEODE_STATICS_removeAllActionsFromTarget
		GEODE_AS_STATIC_FUNCTION(removeAllActionsFromTarget) 
	#endif

	#ifndef GEODE_STATICS_resumeTarget
		#define GEODE_STATICS_resumeTarget
		GEODE_AS_STATIC_FUNCTION(resumeTarget) 
	#endif

	#ifndef GEODE_STATICS_resumeTargets
		#define GEODE_STATICS_resumeTargets
		GEODE_AS_STATIC_FUNCTION(resumeTargets) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_update
		#define GEODE_CONCEPT_CHECK_update
		GEODE_CONCEPT_FUNCTION_CHECK(update) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_actionAllocWithHashElement
		#define GEODE_CONCEPT_CHECK_actionAllocWithHashElement
		GEODE_CONCEPT_FUNCTION_CHECK(actionAllocWithHashElement) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_addAction
		#define GEODE_CONCEPT_CHECK_addAction
		GEODE_CONCEPT_FUNCTION_CHECK(addAction) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_deleteHashElement
		#define GEODE_CONCEPT_CHECK_deleteHashElement
		GEODE_CONCEPT_FUNCTION_CHECK(deleteHashElement) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getActionByTag
		#define GEODE_CONCEPT_CHECK_getActionByTag
		GEODE_CONCEPT_FUNCTION_CHECK(getActionByTag) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_numberOfRunningActionsInTarget
		#define GEODE_CONCEPT_CHECK_numberOfRunningActionsInTarget
		GEODE_CONCEPT_FUNCTION_CHECK(numberOfRunningActionsInTarget) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_pauseAllRunningActions
		#define GEODE_CONCEPT_CHECK_pauseAllRunningActions
		GEODE_CONCEPT_FUNCTION_CHECK(pauseAllRunningActions) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_pauseTarget
		#define GEODE_CONCEPT_CHECK_pauseTarget
		GEODE_CONCEPT_FUNCTION_CHECK(pauseTarget) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_removeAction
		#define GEODE_CONCEPT_CHECK_removeAction
		GEODE_CONCEPT_FUNCTION_CHECK(removeAction) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_removeActionAtIndex
		#define GEODE_CONCEPT_CHECK_removeActionAtIndex
		GEODE_CONCEPT_FUNCTION_CHECK(removeActionAtIndex) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_removeActionByTag
		#define GEODE_CONCEPT_CHECK_removeActionByTag
		GEODE_CONCEPT_FUNCTION_CHECK(removeActionByTag) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_removeAllActions
		#define GEODE_CONCEPT_CHECK_removeAllActions
		GEODE_CONCEPT_FUNCTION_CHECK(removeAllActions) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_removeAllActionsFromTarget
		#define GEODE_CONCEPT_CHECK_removeAllActionsFromTarget
		GEODE_CONCEPT_FUNCTION_CHECK(removeAllActionsFromTarget) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_resumeTarget
		#define GEODE_CONCEPT_CHECK_resumeTarget
		GEODE_CONCEPT_FUNCTION_CHECK(resumeTarget) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_resumeTargets
		#define GEODE_CONCEPT_CHECK_resumeTargets
		GEODE_CONCEPT_FUNCTION_CHECK(resumeTargets) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCActionManager> : ModifyBase<ModifyDerive<Der, cocos2d::CCActionManager>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCActionManager>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCActionManager>>::ModifyBase;
		using Base = cocos2d::CCActionManager;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0x233710, Default, cocos2d::CCActionManager, )
			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0x233740, Default, cocos2d::CCActionManager)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x234810, Default, cocos2d::CCActionManager, update, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x233980, Default, cocos2d::CCActionManager, actionAllocWithHashElement, cocos2d::_hashElement*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x233d10, Default, cocos2d::CCActionManager, addAction, cocos2d::CCAction*, cocos2d::CCNode*, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x233880, Default, cocos2d::CCActionManager, deleteHashElement, cocos2d::_hashElement*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x234600, Default, cocos2d::CCActionManager, getActionByTag, unsigned int, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x234720, Default, cocos2d::CCActionManager, numberOfRunningActionsInTarget, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x233c10, Default, cocos2d::CCActionManager, pauseAllRunningActions, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x233a50, Default, cocos2d::CCActionManager, pauseTarget, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x2342c0, Default, cocos2d::CCActionManager, removeAction, cocos2d::CCAction*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x2339c0, Default, cocos2d::CCActionManager, removeActionAtIndex, unsigned int, cocos2d::_hashElement*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x234450, Default, cocos2d::CCActionManager, removeActionByTag, unsigned int, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x233790, Default, cocos2d::CCActionManager, removeAllActions, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x234150, Default, cocos2d::CCActionManager, removeAllActionsFromTarget, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x233b30, Default, cocos2d::CCActionManager, resumeTarget, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x233c80, Default, cocos2d::CCActionManager, resumeTargets, cocos2d::CCSet*)
		}
	};
}
