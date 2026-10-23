#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <cocos2d.h>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_sharedApplication
		#define GEODE_STATICS_sharedApplication
		GEODE_AS_STATIC_FUNCTION(sharedApplication) 
	#endif

	#ifndef GEODE_STATICS_run
		#define GEODE_STATICS_run
		GEODE_AS_STATIC_FUNCTION(run) 
	#endif

	#ifndef GEODE_STATICS_setAnimationInterval
		#define GEODE_STATICS_setAnimationInterval
		GEODE_AS_STATIC_FUNCTION(setAnimationInterval) 
	#endif

	#ifndef GEODE_STATICS_getCurrentLanguage
		#define GEODE_STATICS_getCurrentLanguage
		GEODE_AS_STATIC_FUNCTION(getCurrentLanguage) 
	#endif

	#ifndef GEODE_STATICS_getTargetPlatform
		#define GEODE_STATICS_getTargetPlatform
		GEODE_AS_STATIC_FUNCTION(getTargetPlatform) 
	#endif

	#ifndef GEODE_STATICS_openURL
		#define GEODE_STATICS_openURL
		GEODE_AS_STATIC_FUNCTION(openURL) 
	#endif

	#ifndef GEODE_STATICS_getResourceRootPath
		#define GEODE_STATICS_getResourceRootPath
		GEODE_AS_STATIC_FUNCTION(getResourceRootPath) 
	#endif

	#ifndef GEODE_STATICS_getStartupScriptFilename
		#define GEODE_STATICS_getStartupScriptFilename
		GEODE_AS_STATIC_FUNCTION(getStartupScriptFilename) 
	#endif

	#ifndef GEODE_STATICS_setResourceRootPath
		#define GEODE_STATICS_setResourceRootPath
		GEODE_AS_STATIC_FUNCTION(setResourceRootPath) 
	#endif

	#ifndef GEODE_STATICS_setStartupScriptFilename
		#define GEODE_STATICS_setStartupScriptFilename
		GEODE_AS_STATIC_FUNCTION(setStartupScriptFilename) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_sharedApplication
		#define GEODE_CONCEPT_CHECK_sharedApplication
		GEODE_CONCEPT_FUNCTION_CHECK(sharedApplication) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_run
		#define GEODE_CONCEPT_CHECK_run
		GEODE_CONCEPT_FUNCTION_CHECK(run) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setAnimationInterval
		#define GEODE_CONCEPT_CHECK_setAnimationInterval
		GEODE_CONCEPT_FUNCTION_CHECK(setAnimationInterval) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getCurrentLanguage
		#define GEODE_CONCEPT_CHECK_getCurrentLanguage
		GEODE_CONCEPT_FUNCTION_CHECK(getCurrentLanguage) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getTargetPlatform
		#define GEODE_CONCEPT_CHECK_getTargetPlatform
		GEODE_CONCEPT_FUNCTION_CHECK(getTargetPlatform) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_openURL
		#define GEODE_CONCEPT_CHECK_openURL
		GEODE_CONCEPT_FUNCTION_CHECK(openURL) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getResourceRootPath
		#define GEODE_CONCEPT_CHECK_getResourceRootPath
		GEODE_CONCEPT_FUNCTION_CHECK(getResourceRootPath) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getStartupScriptFilename
		#define GEODE_CONCEPT_CHECK_getStartupScriptFilename
		GEODE_CONCEPT_FUNCTION_CHECK(getStartupScriptFilename) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getTimeElapsed
		#define GEODE_CONCEPT_CHECK_getTimeElapsed
		GEODE_CONCEPT_FUNCTION_CHECK(getTimeElapsed) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_leftMouseDown
		#define GEODE_CONCEPT_CHECK_leftMouseDown
		GEODE_CONCEPT_FUNCTION_CHECK(leftMouseDown) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_leftMouseUp
		#define GEODE_CONCEPT_CHECK_leftMouseUp
		GEODE_CONCEPT_FUNCTION_CHECK(leftMouseUp) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_logTimeElapsed
		#define GEODE_CONCEPT_CHECK_logTimeElapsed
		GEODE_CONCEPT_FUNCTION_CHECK(logTimeElapsed) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_moveMouse
		#define GEODE_CONCEPT_CHECK_moveMouse
		GEODE_CONCEPT_FUNCTION_CHECK(moveMouse) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_resetForceTimer
		#define GEODE_CONCEPT_CHECK_resetForceTimer
		GEODE_CONCEPT_FUNCTION_CHECK(resetForceTimer) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setResourceRootPath
		#define GEODE_CONCEPT_CHECK_setResourceRootPath
		GEODE_CONCEPT_FUNCTION_CHECK(setResourceRootPath) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setStartupScriptFilename
		#define GEODE_CONCEPT_CHECK_setStartupScriptFilename
		GEODE_CONCEPT_FUNCTION_CHECK(setStartupScriptFilename) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setupVerticalSync
		#define GEODE_CONCEPT_CHECK_setupVerticalSync
		GEODE_CONCEPT_FUNCTION_CHECK(setupVerticalSync) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_shutdownApplication
		#define GEODE_CONCEPT_CHECK_shutdownApplication
		GEODE_CONCEPT_FUNCTION_CHECK(shutdownApplication) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_toggleMouseControl
		#define GEODE_CONCEPT_CHECK_toggleMouseControl
		GEODE_CONCEPT_FUNCTION_CHECK(toggleMouseControl) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_toggleVerticalSync
		#define GEODE_CONCEPT_CHECK_toggleVerticalSync
		GEODE_CONCEPT_FUNCTION_CHECK(toggleVerticalSync) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_updateController
		#define GEODE_CONCEPT_CHECK_updateController
		GEODE_CONCEPT_FUNCTION_CHECK(updateController) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_updateControllerKeys
		#define GEODE_CONCEPT_CHECK_updateControllerKeys
		GEODE_CONCEPT_FUNCTION_CHECK(updateControllerKeys) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_updateMouseControl
		#define GEODE_CONCEPT_CHECK_updateMouseControl
		GEODE_CONCEPT_FUNCTION_CHECK(updateMouseControl) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_updateVerticalSync
		#define GEODE_CONCEPT_CHECK_updateVerticalSync
		GEODE_CONCEPT_FUNCTION_CHECK(updateVerticalSync) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCApplication> : ModifyBase<ModifyDerive<Der, cocos2d::CCApplication>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCApplication>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCApplication>>::ModifyBase;
		using Base = cocos2d::CCApplication;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0x3293f0, Default, cocos2d::CCApplication, )
			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0x329420, Default, cocos2d::CCApplication)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x329520, Default, cocos2d::CCApplication, sharedApplication, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x329490, Default, cocos2d::CCApplication, run, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3294d0, Default, cocos2d::CCApplication, setAnimationInterval, double)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x329530, Default, cocos2d::CCApplication, getCurrentLanguage, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x329510, Default, cocos2d::CCApplication, getTargetPlatform, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x32a230, Default, cocos2d::CCApplication, openURL, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x329b20, Default, cocos2d::CCApplication, getResourceRootPath, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x32a220, Default, cocos2d::CCApplication, getStartupScriptFilename, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x329760, Default, cocos2d::CCApplication, setResourceRootPath, gd::string const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x329b30, Default, cocos2d::CCApplication, setStartupScriptFilename, gd::string const&)
		}
	};
}
