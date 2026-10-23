#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <Geode/binding/OptionsLayer.hpp>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_create
		#define GEODE_STATICS_create
		GEODE_AS_STATIC_FUNCTION(create) 
	#endif

	#ifndef GEODE_STATICS_customSetup
		#define GEODE_STATICS_customSetup
		GEODE_AS_STATIC_FUNCTION(customSetup) 
	#endif

	#ifndef GEODE_STATICS_layerHidden
		#define GEODE_STATICS_layerHidden
		GEODE_AS_STATIC_FUNCTION(layerHidden) 
	#endif

	#ifndef GEODE_STATICS_FLAlert_Clicked
		#define GEODE_STATICS_FLAlert_Clicked
		GEODE_AS_STATIC_FUNCTION(FLAlert_Clicked) 
	#endif

	#ifndef GEODE_STATICS_createToggleButton
		#define GEODE_STATICS_createToggleButton
		GEODE_AS_STATIC_FUNCTION(createToggleButton) 
	#endif

	#ifndef GEODE_STATICS_exitLayer
		#define GEODE_STATICS_exitLayer
		GEODE_AS_STATIC_FUNCTION(exitLayer) 
	#endif

	#ifndef GEODE_STATICS_musicSliderChanged
		#define GEODE_STATICS_musicSliderChanged
		GEODE_AS_STATIC_FUNCTION(musicSliderChanged) 
	#endif

	#ifndef GEODE_STATICS_onAccount
		#define GEODE_STATICS_onAccount
		GEODE_AS_STATIC_FUNCTION(onAccount) 
	#endif

	#ifndef GEODE_STATICS_onHelp
		#define GEODE_STATICS_onHelp
		GEODE_AS_STATIC_FUNCTION(onHelp) 
	#endif

	#ifndef GEODE_STATICS_onMenuMusic
		#define GEODE_STATICS_onMenuMusic
		GEODE_AS_STATIC_FUNCTION(onMenuMusic) 
	#endif

	#ifndef GEODE_STATICS_onOptions
		#define GEODE_STATICS_onOptions
		GEODE_AS_STATIC_FUNCTION(onOptions) 
	#endif

	#ifndef GEODE_STATICS_onProgressBar
		#define GEODE_STATICS_onProgressBar
		GEODE_AS_STATIC_FUNCTION(onProgressBar) 
	#endif

	#ifndef GEODE_STATICS_onRate
		#define GEODE_STATICS_onRate
		GEODE_AS_STATIC_FUNCTION(onRate) 
	#endif

	#ifndef GEODE_STATICS_onRecordReplays
		#define GEODE_STATICS_onRecordReplays
		GEODE_AS_STATIC_FUNCTION(onRecordReplays) 
	#endif

	#ifndef GEODE_STATICS_onSecretVault
		#define GEODE_STATICS_onSecretVault
		GEODE_AS_STATIC_FUNCTION(onSecretVault) 
	#endif

	#ifndef GEODE_STATICS_onSoundtracks
		#define GEODE_STATICS_onSoundtracks
		GEODE_AS_STATIC_FUNCTION(onSoundtracks) 
	#endif

	#ifndef GEODE_STATICS_onSupport
		#define GEODE_STATICS_onSupport
		GEODE_AS_STATIC_FUNCTION(onSupport) 
	#endif

	#ifndef GEODE_STATICS_onVideo
		#define GEODE_STATICS_onVideo
		GEODE_AS_STATIC_FUNCTION(onVideo) 
	#endif

	#ifndef GEODE_STATICS_sfxSliderChanged
		#define GEODE_STATICS_sfxSliderChanged
		GEODE_AS_STATIC_FUNCTION(sfxSliderChanged) 
	#endif

	#ifndef GEODE_STATICS_tryEnableRecord
		#define GEODE_STATICS_tryEnableRecord
		GEODE_AS_STATIC_FUNCTION(tryEnableRecord) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_customSetup
		#define GEODE_CONCEPT_CHECK_customSetup
		GEODE_CONCEPT_FUNCTION_CHECK(customSetup) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_layerHidden
		#define GEODE_CONCEPT_CHECK_layerHidden
		GEODE_CONCEPT_FUNCTION_CHECK(layerHidden) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_FLAlert_Clicked
		#define GEODE_CONCEPT_CHECK_FLAlert_Clicked
		GEODE_CONCEPT_FUNCTION_CHECK(FLAlert_Clicked) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_createToggleButton
		#define GEODE_CONCEPT_CHECK_createToggleButton
		GEODE_CONCEPT_FUNCTION_CHECK(createToggleButton) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_exitLayer
		#define GEODE_CONCEPT_CHECK_exitLayer
		GEODE_CONCEPT_FUNCTION_CHECK(exitLayer) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_musicSliderChanged
		#define GEODE_CONCEPT_CHECK_musicSliderChanged
		GEODE_CONCEPT_FUNCTION_CHECK(musicSliderChanged) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onAccount
		#define GEODE_CONCEPT_CHECK_onAccount
		GEODE_CONCEPT_FUNCTION_CHECK(onAccount) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onHelp
		#define GEODE_CONCEPT_CHECK_onHelp
		GEODE_CONCEPT_FUNCTION_CHECK(onHelp) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onMenuMusic
		#define GEODE_CONCEPT_CHECK_onMenuMusic
		GEODE_CONCEPT_FUNCTION_CHECK(onMenuMusic) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onOptions
		#define GEODE_CONCEPT_CHECK_onOptions
		GEODE_CONCEPT_FUNCTION_CHECK(onOptions) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onProgressBar
		#define GEODE_CONCEPT_CHECK_onProgressBar
		GEODE_CONCEPT_FUNCTION_CHECK(onProgressBar) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onRate
		#define GEODE_CONCEPT_CHECK_onRate
		GEODE_CONCEPT_FUNCTION_CHECK(onRate) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onRecordReplays
		#define GEODE_CONCEPT_CHECK_onRecordReplays
		GEODE_CONCEPT_FUNCTION_CHECK(onRecordReplays) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onSecretVault
		#define GEODE_CONCEPT_CHECK_onSecretVault
		GEODE_CONCEPT_FUNCTION_CHECK(onSecretVault) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onSoundtracks
		#define GEODE_CONCEPT_CHECK_onSoundtracks
		GEODE_CONCEPT_FUNCTION_CHECK(onSoundtracks) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onSupport
		#define GEODE_CONCEPT_CHECK_onSupport
		GEODE_CONCEPT_FUNCTION_CHECK(onSupport) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onVideo
		#define GEODE_CONCEPT_CHECK_onVideo
		GEODE_CONCEPT_FUNCTION_CHECK(onVideo) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_sfxSliderChanged
		#define GEODE_CONCEPT_CHECK_sfxSliderChanged
		GEODE_CONCEPT_FUNCTION_CHECK(sfxSliderChanged) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_tryEnableRecord
		#define GEODE_CONCEPT_CHECK_tryEnableRecord
		GEODE_CONCEPT_FUNCTION_CHECK(tryEnableRecord) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, OptionsLayer> : ModifyBase<ModifyDerive<Der, OptionsLayer>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, OptionsLayer>>;
		using ModifyBase<ModifyDerive<Der, OptionsLayer>>::ModifyBase;
		using Base = OptionsLayer;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x799f80, Default, OptionsLayer, create, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x79a1d0, Default, OptionsLayer, customSetup, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x79b5e0, Default, OptionsLayer, layerHidden, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x79b650, Default, OptionsLayer, FLAlert_Clicked, FLAlertLayer*, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x79acb0, Default, OptionsLayer, createToggleButton, gd::string, cocos2d::SEL_MenuHandler, bool, cocos2d::CCMenu*, cocos2d::CCPoint)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x79b210, Default, OptionsLayer, exitLayer, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x79b120, Default, OptionsLayer, musicSliderChanged, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x79abd0, Default, OptionsLayer, onAccount, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x79abf0, Default, OptionsLayer, onHelp, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x79b1d0, Default, OptionsLayer, onMenuMusic, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x79ac10, Default, OptionsLayer, onOptions, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x79b4f0, Default, OptionsLayer, onProgressBar, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x79ac50, Default, OptionsLayer, onRate, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x79aed0, Default, OptionsLayer, onRecordReplays, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x79af00, Default, OptionsLayer, onSecretVault, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x79ac70, Default, OptionsLayer, onSoundtracks, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x79ac90, Default, OptionsLayer, onSupport, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x79ac30, Default, OptionsLayer, onVideo, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x79b190, Default, OptionsLayer, sfxSliderChanged, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x79b520, Default, OptionsLayer, tryEnableRecord, )
		}
	};
}
