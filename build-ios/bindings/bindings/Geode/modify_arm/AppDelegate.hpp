#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <Geode/binding/AppDelegate.hpp>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_get
		#define GEODE_STATICS_get
		GEODE_AS_STATIC_FUNCTION(get) 
	#endif

	#ifndef GEODE_STATICS_applicationDidFinishLaunching
		#define GEODE_STATICS_applicationDidFinishLaunching
		GEODE_AS_STATIC_FUNCTION(applicationDidFinishLaunching) 
	#endif

	#ifndef GEODE_STATICS_applicationDidEnterBackground
		#define GEODE_STATICS_applicationDidEnterBackground
		GEODE_AS_STATIC_FUNCTION(applicationDidEnterBackground) 
	#endif

	#ifndef GEODE_STATICS_applicationWillEnterForeground
		#define GEODE_STATICS_applicationWillEnterForeground
		GEODE_AS_STATIC_FUNCTION(applicationWillEnterForeground) 
	#endif

	#ifndef GEODE_STATICS_applicationWillBecomeActive
		#define GEODE_STATICS_applicationWillBecomeActive
		GEODE_AS_STATIC_FUNCTION(applicationWillBecomeActive) 
	#endif

	#ifndef GEODE_STATICS_applicationWillResignActive
		#define GEODE_STATICS_applicationWillResignActive
		GEODE_AS_STATIC_FUNCTION(applicationWillResignActive) 
	#endif

	#ifndef GEODE_STATICS_trySaveGame
		#define GEODE_STATICS_trySaveGame
		GEODE_AS_STATIC_FUNCTION(trySaveGame) 
	#endif

	#ifndef GEODE_STATICS_willSwitchToScene
		#define GEODE_STATICS_willSwitchToScene
		GEODE_AS_STATIC_FUNCTION(willSwitchToScene) 
	#endif

	#ifndef GEODE_STATICS_bgScale
		#define GEODE_STATICS_bgScale
		GEODE_AS_STATIC_FUNCTION(bgScale) 
	#endif

	#ifndef GEODE_STATICS_checkSound
		#define GEODE_STATICS_checkSound
		GEODE_AS_STATIC_FUNCTION(checkSound) 
	#endif

	#ifndef GEODE_STATICS_hideLoadingCircle
		#define GEODE_STATICS_hideLoadingCircle
		GEODE_AS_STATIC_FUNCTION(hideLoadingCircle) 
	#endif

	#ifndef GEODE_STATICS_loadingIsFinished
		#define GEODE_STATICS_loadingIsFinished
		GEODE_AS_STATIC_FUNCTION(loadingIsFinished) 
	#endif

	#ifndef GEODE_STATICS_musicTest
		#define GEODE_STATICS_musicTest
		GEODE_AS_STATIC_FUNCTION(musicTest) 
	#endif

	#ifndef GEODE_STATICS_pauseGame
		#define GEODE_STATICS_pauseGame
		GEODE_AS_STATIC_FUNCTION(pauseGame) 
	#endif

	#ifndef GEODE_STATICS_pauseSound
		#define GEODE_STATICS_pauseSound
		GEODE_AS_STATIC_FUNCTION(pauseSound) 
	#endif

	#ifndef GEODE_STATICS_platformShutdown
		#define GEODE_STATICS_platformShutdown
		GEODE_AS_STATIC_FUNCTION(platformShutdown) 
	#endif

	#ifndef GEODE_STATICS_resumeSound
		#define GEODE_STATICS_resumeSound
		GEODE_AS_STATIC_FUNCTION(resumeSound) 
	#endif

	#ifndef GEODE_STATICS_setIdleTimerDisabled
		#define GEODE_STATICS_setIdleTimerDisabled
		GEODE_AS_STATIC_FUNCTION(setIdleTimerDisabled) 
	#endif

	#ifndef GEODE_STATICS_setupGLView
		#define GEODE_STATICS_setupGLView
		GEODE_AS_STATIC_FUNCTION(setupGLView) 
	#endif

	#ifndef GEODE_STATICS_showLoadingCircle
		#define GEODE_STATICS_showLoadingCircle
		GEODE_AS_STATIC_FUNCTION(showLoadingCircle) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_get
		#define GEODE_CONCEPT_CHECK_get
		GEODE_CONCEPT_FUNCTION_CHECK(get) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_applicationDidFinishLaunching
		#define GEODE_CONCEPT_CHECK_applicationDidFinishLaunching
		GEODE_CONCEPT_FUNCTION_CHECK(applicationDidFinishLaunching) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_applicationDidEnterBackground
		#define GEODE_CONCEPT_CHECK_applicationDidEnterBackground
		GEODE_CONCEPT_FUNCTION_CHECK(applicationDidEnterBackground) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_applicationWillEnterForeground
		#define GEODE_CONCEPT_CHECK_applicationWillEnterForeground
		GEODE_CONCEPT_FUNCTION_CHECK(applicationWillEnterForeground) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_applicationWillBecomeActive
		#define GEODE_CONCEPT_CHECK_applicationWillBecomeActive
		GEODE_CONCEPT_FUNCTION_CHECK(applicationWillBecomeActive) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_applicationWillResignActive
		#define GEODE_CONCEPT_CHECK_applicationWillResignActive
		GEODE_CONCEPT_FUNCTION_CHECK(applicationWillResignActive) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_trySaveGame
		#define GEODE_CONCEPT_CHECK_trySaveGame
		GEODE_CONCEPT_FUNCTION_CHECK(trySaveGame) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_willSwitchToScene
		#define GEODE_CONCEPT_CHECK_willSwitchToScene
		GEODE_CONCEPT_FUNCTION_CHECK(willSwitchToScene) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_bgScale
		#define GEODE_CONCEPT_CHECK_bgScale
		GEODE_CONCEPT_FUNCTION_CHECK(bgScale) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_checkSound
		#define GEODE_CONCEPT_CHECK_checkSound
		GEODE_CONCEPT_FUNCTION_CHECK(checkSound) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_hideLoadingCircle
		#define GEODE_CONCEPT_CHECK_hideLoadingCircle
		GEODE_CONCEPT_FUNCTION_CHECK(hideLoadingCircle) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_loadingIsFinished
		#define GEODE_CONCEPT_CHECK_loadingIsFinished
		GEODE_CONCEPT_FUNCTION_CHECK(loadingIsFinished) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_musicTest
		#define GEODE_CONCEPT_CHECK_musicTest
		GEODE_CONCEPT_FUNCTION_CHECK(musicTest) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_pauseGame
		#define GEODE_CONCEPT_CHECK_pauseGame
		GEODE_CONCEPT_FUNCTION_CHECK(pauseGame) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_pauseSound
		#define GEODE_CONCEPT_CHECK_pauseSound
		GEODE_CONCEPT_FUNCTION_CHECK(pauseSound) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_platformShutdown
		#define GEODE_CONCEPT_CHECK_platformShutdown
		GEODE_CONCEPT_FUNCTION_CHECK(platformShutdown) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_resumeSound
		#define GEODE_CONCEPT_CHECK_resumeSound
		GEODE_CONCEPT_FUNCTION_CHECK(resumeSound) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setIdleTimerDisabled
		#define GEODE_CONCEPT_CHECK_setIdleTimerDisabled
		GEODE_CONCEPT_FUNCTION_CHECK(setIdleTimerDisabled) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setupGLView
		#define GEODE_CONCEPT_CHECK_setupGLView
		GEODE_CONCEPT_FUNCTION_CHECK(setupGLView) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_showLoadingCircle
		#define GEODE_CONCEPT_CHECK_showLoadingCircle
		GEODE_CONCEPT_FUNCTION_CHECK(showLoadingCircle) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, AppDelegate> : ModifyBase<ModifyDerive<Der, AppDelegate>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, AppDelegate>>;
		using ModifyBase<ModifyDerive<Der, AppDelegate>>::ModifyBase;
		using Base = AppDelegate;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x57c070, Default, AppDelegate, get, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x57beec, Default, AppDelegate, applicationDidFinishLaunching, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x57c164, Default, AppDelegate, applicationDidEnterBackground, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x57c2b0, Default, AppDelegate, applicationWillEnterForeground, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x57c080, Default, AppDelegate, applicationWillBecomeActive, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x57c094, Default, AppDelegate, applicationWillResignActive, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x57c534, Default, AppDelegate, trySaveGame, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x57c610, Default, AppDelegate, willSwitchToScene, cocos2d::CCScene*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x57c05c, Default, AppDelegate, bgScale, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x57c4bc, Default, AppDelegate, checkSound, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x57c65c, Default, AppDelegate, hideLoadingCircle, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x57c074, Default, AppDelegate, loadingIsFinished, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x57c438, Default, AppDelegate, musicTest, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x57c0fc, Default, AppDelegate, pauseGame, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x57c25c, Default, AppDelegate, pauseSound, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x57be38, Default, AppDelegate, platformShutdown, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x57c39c, Default, AppDelegate, resumeSound, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x57c398, Default, AppDelegate, setIdleTimerDisabled, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x57be3c, Default, AppDelegate, setupGLView, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x57c658, Default, AppDelegate, showLoadingCircle, bool, bool, bool)
		}
	};
}
