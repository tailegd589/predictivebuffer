#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <Geode/binding/LevelPage.hpp>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_create
		#define GEODE_STATICS_create
		GEODE_AS_STATIC_FUNCTION(create) 
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

	#ifndef GEODE_STATICS_registerWithTouchDispatcher
		#define GEODE_STATICS_registerWithTouchDispatcher
		GEODE_AS_STATIC_FUNCTION(registerWithTouchDispatcher) 
	#endif

	#ifndef GEODE_STATICS_dialogClosed
		#define GEODE_STATICS_dialogClosed
		GEODE_AS_STATIC_FUNCTION(dialogClosed) 
	#endif

	#ifndef GEODE_STATICS_addSecretCoin
		#define GEODE_STATICS_addSecretCoin
		GEODE_AS_STATIC_FUNCTION(addSecretCoin) 
	#endif

	#ifndef GEODE_STATICS_addSecretDoor
		#define GEODE_STATICS_addSecretDoor
		GEODE_AS_STATIC_FUNCTION(addSecretDoor) 
	#endif

	#ifndef GEODE_STATICS_init
		#define GEODE_STATICS_init
		GEODE_AS_STATIC_FUNCTION(init) 
	#endif

	#ifndef GEODE_STATICS_onInfo
		#define GEODE_STATICS_onInfo
		GEODE_AS_STATIC_FUNCTION(onInfo) 
	#endif

	#ifndef GEODE_STATICS_onMoreGames
		#define GEODE_STATICS_onMoreGames
		GEODE_AS_STATIC_FUNCTION(onMoreGames) 
	#endif

	#ifndef GEODE_STATICS_onPlay
		#define GEODE_STATICS_onPlay
		GEODE_AS_STATIC_FUNCTION(onPlay) 
	#endif

	#ifndef GEODE_STATICS_onSecretDoor
		#define GEODE_STATICS_onSecretDoor
		GEODE_AS_STATIC_FUNCTION(onSecretDoor) 
	#endif

	#ifndef GEODE_STATICS_onTheTower
		#define GEODE_STATICS_onTheTower
		GEODE_AS_STATIC_FUNCTION(onTheTower) 
	#endif

	#ifndef GEODE_STATICS_playCoinEffect
		#define GEODE_STATICS_playCoinEffect
		GEODE_AS_STATIC_FUNCTION(playCoinEffect) 
	#endif

	#ifndef GEODE_STATICS_playStep2
		#define GEODE_STATICS_playStep2
		GEODE_AS_STATIC_FUNCTION(playStep2) 
	#endif

	#ifndef GEODE_STATICS_playStep3
		#define GEODE_STATICS_playStep3
		GEODE_AS_STATIC_FUNCTION(playStep3) 
	#endif

	#ifndef GEODE_STATICS_updateDynamicPage
		#define GEODE_STATICS_updateDynamicPage
		GEODE_AS_STATIC_FUNCTION(updateDynamicPage) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
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

	#ifndef GEODE_CONCEPT_CHECK_registerWithTouchDispatcher
		#define GEODE_CONCEPT_CHECK_registerWithTouchDispatcher
		GEODE_CONCEPT_FUNCTION_CHECK(registerWithTouchDispatcher) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_dialogClosed
		#define GEODE_CONCEPT_CHECK_dialogClosed
		GEODE_CONCEPT_FUNCTION_CHECK(dialogClosed) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_addSecretCoin
		#define GEODE_CONCEPT_CHECK_addSecretCoin
		GEODE_CONCEPT_FUNCTION_CHECK(addSecretCoin) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_addSecretDoor
		#define GEODE_CONCEPT_CHECK_addSecretDoor
		GEODE_CONCEPT_FUNCTION_CHECK(addSecretDoor) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_init
		#define GEODE_CONCEPT_CHECK_init
		GEODE_CONCEPT_FUNCTION_CHECK(init) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onInfo
		#define GEODE_CONCEPT_CHECK_onInfo
		GEODE_CONCEPT_FUNCTION_CHECK(onInfo) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onMoreGames
		#define GEODE_CONCEPT_CHECK_onMoreGames
		GEODE_CONCEPT_FUNCTION_CHECK(onMoreGames) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onPlay
		#define GEODE_CONCEPT_CHECK_onPlay
		GEODE_CONCEPT_FUNCTION_CHECK(onPlay) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onSecretDoor
		#define GEODE_CONCEPT_CHECK_onSecretDoor
		GEODE_CONCEPT_FUNCTION_CHECK(onSecretDoor) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onTheTower
		#define GEODE_CONCEPT_CHECK_onTheTower
		GEODE_CONCEPT_FUNCTION_CHECK(onTheTower) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_playCoinEffect
		#define GEODE_CONCEPT_CHECK_playCoinEffect
		GEODE_CONCEPT_FUNCTION_CHECK(playCoinEffect) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_playStep2
		#define GEODE_CONCEPT_CHECK_playStep2
		GEODE_CONCEPT_FUNCTION_CHECK(playStep2) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_playStep3
		#define GEODE_CONCEPT_CHECK_playStep3
		GEODE_CONCEPT_FUNCTION_CHECK(playStep3) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_updateDynamicPage
		#define GEODE_CONCEPT_CHECK_updateDynamicPage
		GEODE_CONCEPT_FUNCTION_CHECK(updateDynamicPage) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, LevelPage> : ModifyBase<ModifyDerive<Der, LevelPage>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, LevelPage>>;
		using ModifyBase<ModifyDerive<Der, LevelPage>>::ModifyBase;
		using Base = LevelPage;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0x3a749c, Default, LevelPage)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3a4bcc, Default, LevelPage, create, GJGameLevel*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3a9610, Default, LevelPage, ccTouchBegan, cocos2d::CCTouch*, cocos2d::CCEvent*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3a9710, Default, LevelPage, ccTouchMoved, cocos2d::CCTouch*, cocos2d::CCEvent*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3a9718, Default, LevelPage, ccTouchEnded, cocos2d::CCTouch*, cocos2d::CCEvent*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3a9720, Default, LevelPage, ccTouchCancelled, cocos2d::CCTouch*, cocos2d::CCEvent*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3a973c, Default, LevelPage, registerWithTouchDispatcher, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3a9348, Default, LevelPage, dialogClosed, DialogLayer*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3a6434, Default, LevelPage, addSecretCoin, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3a866c, Default, LevelPage, addSecretDoor, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3a7568, Default, LevelPage, init, GJGameLevel*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3a6fa4, Default, LevelPage, onInfo, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3a87d8, Default, LevelPage, onMoreGames, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3a6c94, Default, LevelPage, onPlay, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3a8c74, Default, LevelPage, onSecretDoor, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3a8120, Default, LevelPage, onTheTower, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3a883c, Default, LevelPage, playCoinEffect, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3a9498, Default, LevelPage, playStep2, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3a955c, Default, LevelPage, playStep3, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3a4e60, Default, LevelPage, updateDynamicPage, GJGameLevel*)
		}
	};
}
