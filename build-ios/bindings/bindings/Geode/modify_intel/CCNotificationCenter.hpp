#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <cocos2d.h>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_purgeNotificationCenter
		#define GEODE_STATICS_purgeNotificationCenter
		GEODE_AS_STATIC_FUNCTION(purgeNotificationCenter) 
	#endif

	#ifndef GEODE_STATICS_sharedNotificationCenter
		#define GEODE_STATICS_sharedNotificationCenter
		GEODE_AS_STATIC_FUNCTION(sharedNotificationCenter) 
	#endif

	#ifndef GEODE_STATICS_addObserver
		#define GEODE_STATICS_addObserver
		GEODE_AS_STATIC_FUNCTION(addObserver) 
	#endif

	#ifndef GEODE_STATICS_getObserverHandlerByName
		#define GEODE_STATICS_getObserverHandlerByName
		GEODE_AS_STATIC_FUNCTION(getObserverHandlerByName) 
	#endif

	#ifndef GEODE_STATICS_observerExisted
		#define GEODE_STATICS_observerExisted
		GEODE_AS_STATIC_FUNCTION(observerExisted) 
	#endif

	#ifndef GEODE_STATICS_postNotification
		#define GEODE_STATICS_postNotification
		GEODE_AS_STATIC_FUNCTION(postNotification) 
	#endif

	#ifndef GEODE_STATICS_registerScriptObserver
		#define GEODE_STATICS_registerScriptObserver
		GEODE_AS_STATIC_FUNCTION(registerScriptObserver) 
	#endif

	#ifndef GEODE_STATICS_removeAllObservers
		#define GEODE_STATICS_removeAllObservers
		GEODE_AS_STATIC_FUNCTION(removeAllObservers) 
	#endif

	#ifndef GEODE_STATICS_removeObserver
		#define GEODE_STATICS_removeObserver
		GEODE_AS_STATIC_FUNCTION(removeObserver) 
	#endif

	#ifndef GEODE_STATICS_unregisterScriptObserver
		#define GEODE_STATICS_unregisterScriptObserver
		GEODE_AS_STATIC_FUNCTION(unregisterScriptObserver) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_purgeNotificationCenter
		#define GEODE_CONCEPT_CHECK_purgeNotificationCenter
		GEODE_CONCEPT_FUNCTION_CHECK(purgeNotificationCenter) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_sharedNotificationCenter
		#define GEODE_CONCEPT_CHECK_sharedNotificationCenter
		GEODE_CONCEPT_FUNCTION_CHECK(sharedNotificationCenter) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_addObserver
		#define GEODE_CONCEPT_CHECK_addObserver
		GEODE_CONCEPT_FUNCTION_CHECK(addObserver) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getObserverHandlerByName
		#define GEODE_CONCEPT_CHECK_getObserverHandlerByName
		GEODE_CONCEPT_FUNCTION_CHECK(getObserverHandlerByName) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_observerExisted
		#define GEODE_CONCEPT_CHECK_observerExisted
		GEODE_CONCEPT_FUNCTION_CHECK(observerExisted) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_postNotification
		#define GEODE_CONCEPT_CHECK_postNotification
		GEODE_CONCEPT_FUNCTION_CHECK(postNotification) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_registerScriptObserver
		#define GEODE_CONCEPT_CHECK_registerScriptObserver
		GEODE_CONCEPT_FUNCTION_CHECK(registerScriptObserver) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_removeAllObservers
		#define GEODE_CONCEPT_CHECK_removeAllObservers
		GEODE_CONCEPT_FUNCTION_CHECK(removeAllObservers) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_removeObserver
		#define GEODE_CONCEPT_CHECK_removeObserver
		GEODE_CONCEPT_FUNCTION_CHECK(removeObserver) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_unregisterScriptObserver
		#define GEODE_CONCEPT_CHECK_unregisterScriptObserver
		GEODE_CONCEPT_FUNCTION_CHECK(unregisterScriptObserver) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCNotificationCenter> : ModifyBase<ModifyDerive<Der, cocos2d::CCNotificationCenter>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCNotificationCenter>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCNotificationCenter>>::ModifyBase;
		using Base = cocos2d::CCNotificationCenter;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0x2874c0, Default, cocos2d::CCNotificationCenter, )
			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0x287560, Default, cocos2d::CCNotificationCenter)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x2876b0, Default, cocos2d::CCNotificationCenter, purgeNotificationCenter, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x287620, Default, cocos2d::CCNotificationCenter, sharedNotificationCenter, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x287770, Default, cocos2d::CCNotificationCenter, addObserver, cocos2d::CCObject*, cocos2d::SEL_CallFuncO, char const*, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x287d30, Default, cocos2d::CCNotificationCenter, getObserverHandlerByName, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x2876e0, Default, cocos2d::CCNotificationCenter, observerExisted, cocos2d::CCObject*, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x287d20, Default, cocos2d::CCNotificationCenter, postNotification, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x287b80, Default, cocos2d::CCNotificationCenter, postNotification, char const*, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x2879f0, Default, cocos2d::CCNotificationCenter, registerScriptObserver, cocos2d::CCObject*, int, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x287940, Default, cocos2d::CCNotificationCenter, removeAllObservers, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x287880, Default, cocos2d::CCNotificationCenter, removeObserver, cocos2d::CCObject*, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x287ae0, Default, cocos2d::CCNotificationCenter, unregisterScriptObserver, cocos2d::CCObject*, char const*)
		}
	};
}
