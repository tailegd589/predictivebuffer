#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <Geode/binding/LevelAreaInnerLayer.hpp>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_create
		#define GEODE_STATICS_create
		GEODE_AS_STATIC_FUNCTION(create) 
	#endif

	#ifndef GEODE_STATICS_scene
		#define GEODE_STATICS_scene
		GEODE_AS_STATIC_FUNCTION(scene) 
	#endif

	#ifndef GEODE_STATICS_keyBackClicked
		#define GEODE_STATICS_keyBackClicked
		GEODE_AS_STATIC_FUNCTION(keyBackClicked) 
	#endif

	#ifndef GEODE_STATICS_dialogClosed
		#define GEODE_STATICS_dialogClosed
		GEODE_AS_STATIC_FUNCTION(dialogClosed) 
	#endif

	#ifndef GEODE_STATICS_onExit
		#define GEODE_STATICS_onExit
		GEODE_AS_STATIC_FUNCTION(onExit) 
	#endif

	#ifndef GEODE_STATICS_init
		#define GEODE_STATICS_init
		GEODE_AS_STATIC_FUNCTION(init) 
	#endif

	#ifndef GEODE_STATICS_onBack
		#define GEODE_STATICS_onBack
		GEODE_AS_STATIC_FUNCTION(onBack) 
	#endif

	#ifndef GEODE_STATICS_onDoor
		#define GEODE_STATICS_onDoor
		GEODE_AS_STATIC_FUNCTION(onDoor) 
	#endif

	#ifndef GEODE_STATICS_onInfo
		#define GEODE_STATICS_onInfo
		GEODE_AS_STATIC_FUNCTION(onInfo) 
	#endif

	#ifndef GEODE_STATICS_onNextFloor
		#define GEODE_STATICS_onNextFloor
		GEODE_AS_STATIC_FUNCTION(onNextFloor) 
	#endif

	#ifndef GEODE_STATICS_onOnlineVault
		#define GEODE_STATICS_onOnlineVault
		GEODE_AS_STATIC_FUNCTION(onOnlineVault) 
	#endif

	#ifndef GEODE_STATICS_playStep1
		#define GEODE_STATICS_playStep1
		GEODE_AS_STATIC_FUNCTION(playStep1) 
	#endif

	#ifndef GEODE_STATICS_showFloor1CompleteDialog
		#define GEODE_STATICS_showFloor1CompleteDialog
		GEODE_AS_STATIC_FUNCTION(showFloor1CompleteDialog) 
	#endif

	#ifndef GEODE_STATICS_tryResumeTowerMusic
		#define GEODE_STATICS_tryResumeTowerMusic
		GEODE_AS_STATIC_FUNCTION(tryResumeTowerMusic) 
	#endif

	#ifndef GEODE_STATICS_tryShowAd
		#define GEODE_STATICS_tryShowAd
		GEODE_AS_STATIC_FUNCTION(tryShowAd) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_scene
		#define GEODE_CONCEPT_CHECK_scene
		GEODE_CONCEPT_FUNCTION_CHECK(scene) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_keyBackClicked
		#define GEODE_CONCEPT_CHECK_keyBackClicked
		GEODE_CONCEPT_FUNCTION_CHECK(keyBackClicked) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_dialogClosed
		#define GEODE_CONCEPT_CHECK_dialogClosed
		GEODE_CONCEPT_FUNCTION_CHECK(dialogClosed) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onExit
		#define GEODE_CONCEPT_CHECK_onExit
		GEODE_CONCEPT_FUNCTION_CHECK(onExit) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_init
		#define GEODE_CONCEPT_CHECK_init
		GEODE_CONCEPT_FUNCTION_CHECK(init) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onBack
		#define GEODE_CONCEPT_CHECK_onBack
		GEODE_CONCEPT_FUNCTION_CHECK(onBack) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onDoor
		#define GEODE_CONCEPT_CHECK_onDoor
		GEODE_CONCEPT_FUNCTION_CHECK(onDoor) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onInfo
		#define GEODE_CONCEPT_CHECK_onInfo
		GEODE_CONCEPT_FUNCTION_CHECK(onInfo) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onNextFloor
		#define GEODE_CONCEPT_CHECK_onNextFloor
		GEODE_CONCEPT_FUNCTION_CHECK(onNextFloor) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onOnlineVault
		#define GEODE_CONCEPT_CHECK_onOnlineVault
		GEODE_CONCEPT_FUNCTION_CHECK(onOnlineVault) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_playStep1
		#define GEODE_CONCEPT_CHECK_playStep1
		GEODE_CONCEPT_FUNCTION_CHECK(playStep1) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_showFloor1CompleteDialog
		#define GEODE_CONCEPT_CHECK_showFloor1CompleteDialog
		GEODE_CONCEPT_FUNCTION_CHECK(showFloor1CompleteDialog) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_tryResumeTowerMusic
		#define GEODE_CONCEPT_CHECK_tryResumeTowerMusic
		GEODE_CONCEPT_FUNCTION_CHECK(tryResumeTowerMusic) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_tryShowAd
		#define GEODE_CONCEPT_CHECK_tryShowAd
		GEODE_CONCEPT_FUNCTION_CHECK(tryShowAd) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, LevelAreaInnerLayer> : ModifyBase<ModifyDerive<Der, LevelAreaInnerLayer>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, LevelAreaInnerLayer>>;
		using ModifyBase<ModifyDerive<Der, LevelAreaInnerLayer>>::ModifyBase;
		using Base = LevelAreaInnerLayer;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x21bf58, Default, LevelAreaInnerLayer, create, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x21bd10, Default, LevelAreaInnerLayer, scene, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x21ddb0, Default, LevelAreaInnerLayer, keyBackClicked, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x21db84, Default, LevelAreaInnerLayer, dialogClosed, DialogLayer*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x21dd5c, Default, LevelAreaInnerLayer, onExit, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x21c018, Default, LevelAreaInnerLayer, init, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x21cde4, Default, LevelAreaInnerLayer, onBack, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x21ce34, Default, LevelAreaInnerLayer, onDoor, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x21d0ec, Default, LevelAreaInnerLayer, onInfo, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x21cf68, Default, LevelAreaInnerLayer, onNextFloor, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x21d028, Default, LevelAreaInnerLayer, onOnlineVault, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x21dc9c, Default, LevelAreaInnerLayer, playStep1, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x21d678, Default, LevelAreaInnerLayer, showFloor1CompleteDialog, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x21d05c, Default, LevelAreaInnerLayer, tryResumeTowerMusic, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x21db64, Default, LevelAreaInnerLayer, tryShowAd, )
		}
	};
}
