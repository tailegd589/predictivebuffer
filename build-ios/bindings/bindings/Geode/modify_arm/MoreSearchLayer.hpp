#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <Geode/binding/MoreSearchLayer.hpp>
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

	#ifndef GEODE_STATICS_keyBackClicked
		#define GEODE_STATICS_keyBackClicked
		GEODE_AS_STATIC_FUNCTION(keyBackClicked) 
	#endif

	#ifndef GEODE_STATICS_textInputShouldOffset
		#define GEODE_STATICS_textInputShouldOffset
		GEODE_AS_STATIC_FUNCTION(textInputShouldOffset) 
	#endif

	#ifndef GEODE_STATICS_textInputReturn
		#define GEODE_STATICS_textInputReturn
		GEODE_AS_STATIC_FUNCTION(textInputReturn) 
	#endif

	#ifndef GEODE_STATICS_audioNext
		#define GEODE_STATICS_audioNext
		GEODE_AS_STATIC_FUNCTION(audioNext) 
	#endif

	#ifndef GEODE_STATICS_audioPrevious
		#define GEODE_STATICS_audioPrevious
		GEODE_AS_STATIC_FUNCTION(audioPrevious) 
	#endif

	#ifndef GEODE_STATICS_createToggleButton
		#define GEODE_STATICS_createToggleButton
		GEODE_AS_STATIC_FUNCTION(createToggleButton) 
	#endif

	#ifndef GEODE_STATICS_onClose
		#define GEODE_STATICS_onClose
		GEODE_AS_STATIC_FUNCTION(onClose) 
	#endif

	#ifndef GEODE_STATICS_onCoins
		#define GEODE_STATICS_onCoins
		GEODE_AS_STATIC_FUNCTION(onCoins) 
	#endif

	#ifndef GEODE_STATICS_onCompleted
		#define GEODE_STATICS_onCompleted
		GEODE_AS_STATIC_FUNCTION(onCompleted) 
	#endif

	#ifndef GEODE_STATICS_onEpic
		#define GEODE_STATICS_onEpic
		GEODE_AS_STATIC_FUNCTION(onEpic) 
	#endif

	#ifndef GEODE_STATICS_onFeatured
		#define GEODE_STATICS_onFeatured
		GEODE_AS_STATIC_FUNCTION(onFeatured) 
	#endif

	#ifndef GEODE_STATICS_onFollowed
		#define GEODE_STATICS_onFollowed
		GEODE_AS_STATIC_FUNCTION(onFollowed) 
	#endif

	#ifndef GEODE_STATICS_onFriends
		#define GEODE_STATICS_onFriends
		GEODE_AS_STATIC_FUNCTION(onFriends) 
	#endif

	#ifndef GEODE_STATICS_onInfo
		#define GEODE_STATICS_onInfo
		GEODE_AS_STATIC_FUNCTION(onInfo) 
	#endif

	#ifndef GEODE_STATICS_onLegendary
		#define GEODE_STATICS_onLegendary
		GEODE_AS_STATIC_FUNCTION(onLegendary) 
	#endif

	#ifndef GEODE_STATICS_onMythic
		#define GEODE_STATICS_onMythic
		GEODE_AS_STATIC_FUNCTION(onMythic) 
	#endif

	#ifndef GEODE_STATICS_onNoStar
		#define GEODE_STATICS_onNoStar
		GEODE_AS_STATIC_FUNCTION(onNoStar) 
	#endif

	#ifndef GEODE_STATICS_onOriginal
		#define GEODE_STATICS_onOriginal
		GEODE_AS_STATIC_FUNCTION(onOriginal) 
	#endif

	#ifndef GEODE_STATICS_onSongFilter
		#define GEODE_STATICS_onSongFilter
		GEODE_AS_STATIC_FUNCTION(onSongFilter) 
	#endif

	#ifndef GEODE_STATICS_onSongMode
		#define GEODE_STATICS_onSongMode
		GEODE_AS_STATIC_FUNCTION(onSongMode) 
	#endif

	#ifndef GEODE_STATICS_onTwoPlayer
		#define GEODE_STATICS_onTwoPlayer
		GEODE_AS_STATIC_FUNCTION(onTwoPlayer) 
	#endif

	#ifndef GEODE_STATICS_onUncompleted
		#define GEODE_STATICS_onUncompleted
		GEODE_AS_STATIC_FUNCTION(onUncompleted) 
	#endif

	#ifndef GEODE_STATICS_selectSong
		#define GEODE_STATICS_selectSong
		GEODE_AS_STATIC_FUNCTION(selectSong) 
	#endif

	#ifndef GEODE_STATICS_toggleSongNodes
		#define GEODE_STATICS_toggleSongNodes
		GEODE_AS_STATIC_FUNCTION(toggleSongNodes) 
	#endif

	#ifndef GEODE_STATICS_updateAudioLabel
		#define GEODE_STATICS_updateAudioLabel
		GEODE_AS_STATIC_FUNCTION(updateAudioLabel) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_init
		#define GEODE_CONCEPT_CHECK_init
		GEODE_CONCEPT_FUNCTION_CHECK(init) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_keyBackClicked
		#define GEODE_CONCEPT_CHECK_keyBackClicked
		GEODE_CONCEPT_FUNCTION_CHECK(keyBackClicked) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_textInputShouldOffset
		#define GEODE_CONCEPT_CHECK_textInputShouldOffset
		GEODE_CONCEPT_FUNCTION_CHECK(textInputShouldOffset) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_textInputReturn
		#define GEODE_CONCEPT_CHECK_textInputReturn
		GEODE_CONCEPT_FUNCTION_CHECK(textInputReturn) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_audioNext
		#define GEODE_CONCEPT_CHECK_audioNext
		GEODE_CONCEPT_FUNCTION_CHECK(audioNext) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_audioPrevious
		#define GEODE_CONCEPT_CHECK_audioPrevious
		GEODE_CONCEPT_FUNCTION_CHECK(audioPrevious) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_createToggleButton
		#define GEODE_CONCEPT_CHECK_createToggleButton
		GEODE_CONCEPT_FUNCTION_CHECK(createToggleButton) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onClose
		#define GEODE_CONCEPT_CHECK_onClose
		GEODE_CONCEPT_FUNCTION_CHECK(onClose) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onCoins
		#define GEODE_CONCEPT_CHECK_onCoins
		GEODE_CONCEPT_FUNCTION_CHECK(onCoins) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onCompleted
		#define GEODE_CONCEPT_CHECK_onCompleted
		GEODE_CONCEPT_FUNCTION_CHECK(onCompleted) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onEpic
		#define GEODE_CONCEPT_CHECK_onEpic
		GEODE_CONCEPT_FUNCTION_CHECK(onEpic) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onFeatured
		#define GEODE_CONCEPT_CHECK_onFeatured
		GEODE_CONCEPT_FUNCTION_CHECK(onFeatured) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onFollowed
		#define GEODE_CONCEPT_CHECK_onFollowed
		GEODE_CONCEPT_FUNCTION_CHECK(onFollowed) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onFriends
		#define GEODE_CONCEPT_CHECK_onFriends
		GEODE_CONCEPT_FUNCTION_CHECK(onFriends) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onInfo
		#define GEODE_CONCEPT_CHECK_onInfo
		GEODE_CONCEPT_FUNCTION_CHECK(onInfo) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onLegendary
		#define GEODE_CONCEPT_CHECK_onLegendary
		GEODE_CONCEPT_FUNCTION_CHECK(onLegendary) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onMythic
		#define GEODE_CONCEPT_CHECK_onMythic
		GEODE_CONCEPT_FUNCTION_CHECK(onMythic) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onNoStar
		#define GEODE_CONCEPT_CHECK_onNoStar
		GEODE_CONCEPT_FUNCTION_CHECK(onNoStar) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onOriginal
		#define GEODE_CONCEPT_CHECK_onOriginal
		GEODE_CONCEPT_FUNCTION_CHECK(onOriginal) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onSongFilter
		#define GEODE_CONCEPT_CHECK_onSongFilter
		GEODE_CONCEPT_FUNCTION_CHECK(onSongFilter) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onSongMode
		#define GEODE_CONCEPT_CHECK_onSongMode
		GEODE_CONCEPT_FUNCTION_CHECK(onSongMode) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onTwoPlayer
		#define GEODE_CONCEPT_CHECK_onTwoPlayer
		GEODE_CONCEPT_FUNCTION_CHECK(onTwoPlayer) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onUncompleted
		#define GEODE_CONCEPT_CHECK_onUncompleted
		GEODE_CONCEPT_FUNCTION_CHECK(onUncompleted) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_selectSong
		#define GEODE_CONCEPT_CHECK_selectSong
		GEODE_CONCEPT_FUNCTION_CHECK(selectSong) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_toggleSongNodes
		#define GEODE_CONCEPT_CHECK_toggleSongNodes
		GEODE_CONCEPT_FUNCTION_CHECK(toggleSongNodes) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_updateAudioLabel
		#define GEODE_CONCEPT_CHECK_updateAudioLabel
		GEODE_CONCEPT_FUNCTION_CHECK(updateAudioLabel) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, MoreSearchLayer> : ModifyBase<ModifyDerive<Der, MoreSearchLayer>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, MoreSearchLayer>>;
		using ModifyBase<ModifyDerive<Der, MoreSearchLayer>>::ModifyBase;
		using Base = MoreSearchLayer;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0x54ff40, Default, MoreSearchLayer)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x54edb0, Default, MoreSearchLayer, create, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x550180, Default, MoreSearchLayer, init, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x55218c, Default, MoreSearchLayer, keyBackClicked, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x552004, Default, MoreSearchLayer, textInputShouldOffset, CCTextInputNode*, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x5520d4, Default, MoreSearchLayer, textInputReturn, CCTextInputNode*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x551bb0, Default, MoreSearchLayer, audioNext, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x551b3c, Default, MoreSearchLayer, audioPrevious, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x551424, Default, MoreSearchLayer, createToggleButton, gd::string, cocos2d::SEL_MenuHandler, bool, cocos2d::CCMenu*, cocos2d::CCPoint)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x551340, Default, MoreSearchLayer, onClose, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x55175c, Default, MoreSearchLayer, onCoins, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x5516dc, Default, MoreSearchLayer, onCompleted, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x55192c, Default, MoreSearchLayer, onEpic, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x5518ec, Default, MoreSearchLayer, onFeatured, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x551cf4, Default, MoreSearchLayer, onFollowed, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x551d34, Default, MoreSearchLayer, onFriends, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x551c18, Default, MoreSearchLayer, onInfo, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x55196c, Default, MoreSearchLayer, onLegendary, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x5519ac, Default, MoreSearchLayer, onMythic, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x5518ac, Default, MoreSearchLayer, onNoStar, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x55171c, Default, MoreSearchLayer, onOriginal, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x5517dc, Default, MoreSearchLayer, onSongFilter, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x5519ec, Default, MoreSearchLayer, onSongMode, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x55179c, Default, MoreSearchLayer, onTwoPlayer, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x55169c, Default, MoreSearchLayer, onUncompleted, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x551e6c, Default, MoreSearchLayer, selectSong, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x551d74, Default, MoreSearchLayer, toggleSongNodes, bool, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x551eb4, Default, MoreSearchLayer, updateAudioLabel, )
		}
	};
}
