#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <Geode/binding/CustomSongLayer.hpp>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_create
		#define GEODE_STATICS_create
		GEODE_AS_STATIC_FUNCTION(create) 
	#endif

	#ifndef GEODE_STATICS_keyBackClicked
		#define GEODE_STATICS_keyBackClicked
		GEODE_AS_STATIC_FUNCTION(keyBackClicked) 
	#endif

	#ifndef GEODE_STATICS_show
		#define GEODE_STATICS_show
		GEODE_AS_STATIC_FUNCTION(show) 
	#endif

	#ifndef GEODE_STATICS_textChanged
		#define GEODE_STATICS_textChanged
		GEODE_AS_STATIC_FUNCTION(textChanged) 
	#endif

	#ifndef GEODE_STATICS_textInputOpened
		#define GEODE_STATICS_textInputOpened
		GEODE_AS_STATIC_FUNCTION(textInputOpened) 
	#endif

	#ifndef GEODE_STATICS_textInputClosed
		#define GEODE_STATICS_textInputClosed
		GEODE_AS_STATIC_FUNCTION(textInputClosed) 
	#endif

	#ifndef GEODE_STATICS_textInputShouldOffset
		#define GEODE_STATICS_textInputShouldOffset
		GEODE_AS_STATIC_FUNCTION(textInputShouldOffset) 
	#endif

	#ifndef GEODE_STATICS_textInputReturn
		#define GEODE_STATICS_textInputReturn
		GEODE_AS_STATIC_FUNCTION(textInputReturn) 
	#endif

	#ifndef GEODE_STATICS_dropDownLayerWillClose
		#define GEODE_STATICS_dropDownLayerWillClose
		GEODE_AS_STATIC_FUNCTION(dropDownLayerWillClose) 
	#endif

	#ifndef GEODE_STATICS_musicBrowserClosed
		#define GEODE_STATICS_musicBrowserClosed
		GEODE_AS_STATIC_FUNCTION(musicBrowserClosed) 
	#endif

	#ifndef GEODE_STATICS_init
		#define GEODE_STATICS_init
		GEODE_AS_STATIC_FUNCTION(init) 
	#endif

	#ifndef GEODE_STATICS_onClose
		#define GEODE_STATICS_onClose
		GEODE_AS_STATIC_FUNCTION(onClose) 
	#endif

	#ifndef GEODE_STATICS_onCreateLines
		#define GEODE_STATICS_onCreateLines
		GEODE_AS_STATIC_FUNCTION(onCreateLines) 
	#endif

	#ifndef GEODE_STATICS_onMusicBrowser
		#define GEODE_STATICS_onMusicBrowser
		GEODE_AS_STATIC_FUNCTION(onMusicBrowser) 
	#endif

	#ifndef GEODE_STATICS_onNCSBrowser
		#define GEODE_STATICS_onNCSBrowser
		GEODE_AS_STATIC_FUNCTION(onNCSBrowser) 
	#endif

	#ifndef GEODE_STATICS_onNewgroundsBrowser
		#define GEODE_STATICS_onNewgroundsBrowser
		GEODE_AS_STATIC_FUNCTION(onNewgroundsBrowser) 
	#endif

	#ifndef GEODE_STATICS_onOptions
		#define GEODE_STATICS_onOptions
		GEODE_AS_STATIC_FUNCTION(onOptions) 
	#endif

	#ifndef GEODE_STATICS_onSearch
		#define GEODE_STATICS_onSearch
		GEODE_AS_STATIC_FUNCTION(onSearch) 
	#endif

	#ifndef GEODE_STATICS_onSongBrowser
		#define GEODE_STATICS_onSongBrowser
		GEODE_AS_STATIC_FUNCTION(onSongBrowser) 
	#endif

	#ifndef GEODE_STATICS_showNewgroundsMessage
		#define GEODE_STATICS_showNewgroundsMessage
		GEODE_AS_STATIC_FUNCTION(showNewgroundsMessage) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_keyBackClicked
		#define GEODE_CONCEPT_CHECK_keyBackClicked
		GEODE_CONCEPT_FUNCTION_CHECK(keyBackClicked) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_show
		#define GEODE_CONCEPT_CHECK_show
		GEODE_CONCEPT_FUNCTION_CHECK(show) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_textChanged
		#define GEODE_CONCEPT_CHECK_textChanged
		GEODE_CONCEPT_FUNCTION_CHECK(textChanged) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_textInputOpened
		#define GEODE_CONCEPT_CHECK_textInputOpened
		GEODE_CONCEPT_FUNCTION_CHECK(textInputOpened) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_textInputClosed
		#define GEODE_CONCEPT_CHECK_textInputClosed
		GEODE_CONCEPT_FUNCTION_CHECK(textInputClosed) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_textInputShouldOffset
		#define GEODE_CONCEPT_CHECK_textInputShouldOffset
		GEODE_CONCEPT_FUNCTION_CHECK(textInputShouldOffset) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_textInputReturn
		#define GEODE_CONCEPT_CHECK_textInputReturn
		GEODE_CONCEPT_FUNCTION_CHECK(textInputReturn) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_dropDownLayerWillClose
		#define GEODE_CONCEPT_CHECK_dropDownLayerWillClose
		GEODE_CONCEPT_FUNCTION_CHECK(dropDownLayerWillClose) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_musicBrowserClosed
		#define GEODE_CONCEPT_CHECK_musicBrowserClosed
		GEODE_CONCEPT_FUNCTION_CHECK(musicBrowserClosed) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_init
		#define GEODE_CONCEPT_CHECK_init
		GEODE_CONCEPT_FUNCTION_CHECK(init) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onClose
		#define GEODE_CONCEPT_CHECK_onClose
		GEODE_CONCEPT_FUNCTION_CHECK(onClose) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onCreateLines
		#define GEODE_CONCEPT_CHECK_onCreateLines
		GEODE_CONCEPT_FUNCTION_CHECK(onCreateLines) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onMusicBrowser
		#define GEODE_CONCEPT_CHECK_onMusicBrowser
		GEODE_CONCEPT_FUNCTION_CHECK(onMusicBrowser) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onNCSBrowser
		#define GEODE_CONCEPT_CHECK_onNCSBrowser
		GEODE_CONCEPT_FUNCTION_CHECK(onNCSBrowser) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onNewgroundsBrowser
		#define GEODE_CONCEPT_CHECK_onNewgroundsBrowser
		GEODE_CONCEPT_FUNCTION_CHECK(onNewgroundsBrowser) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onOptions
		#define GEODE_CONCEPT_CHECK_onOptions
		GEODE_CONCEPT_FUNCTION_CHECK(onOptions) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onSearch
		#define GEODE_CONCEPT_CHECK_onSearch
		GEODE_CONCEPT_FUNCTION_CHECK(onSearch) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onSongBrowser
		#define GEODE_CONCEPT_CHECK_onSongBrowser
		GEODE_CONCEPT_FUNCTION_CHECK(onSongBrowser) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_showNewgroundsMessage
		#define GEODE_CONCEPT_CHECK_showNewgroundsMessage
		GEODE_CONCEPT_FUNCTION_CHECK(showNewgroundsMessage) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, CustomSongLayer> : ModifyBase<ModifyDerive<Der, CustomSongLayer>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, CustomSongLayer>>;
		using ModifyBase<ModifyDerive<Der, CustomSongLayer>>::ModifyBase;
		using Base = CustomSongLayer;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1c022c, Default, CustomSongLayer, create, CustomSongDelegate*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1c19d8, Default, CustomSongLayer, keyBackClicked, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1c1ac4, Default, CustomSongLayer, show, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1c14a8, Default, CustomSongLayer, textChanged, CCTextInputNode*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1c1428, Default, CustomSongLayer, textInputOpened, CCTextInputNode*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1c13a8, Default, CustomSongLayer, textInputClosed, CCTextInputNode*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1c14c8, Default, CustomSongLayer, textInputShouldOffset, CCTextInputNode*, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1c1598, Default, CustomSongLayer, textInputReturn, CCTextInputNode*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1c1848, Default, CustomSongLayer, dropDownLayerWillClose, GJDropDownLayer*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1c1910, Default, CustomSongLayer, musicBrowserClosed, MusicBrowser*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1c0348, Default, CustomSongLayer, init, CustomSongDelegate*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1c0ec0, Default, CustomSongLayer, onClose, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1c1018, Default, CustomSongLayer, onCreateLines, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1c0fb4, Default, CustomSongLayer, onMusicBrowser, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1c0f98, Default, CustomSongLayer, onNCSBrowser, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1c0ffc, Default, CustomSongLayer, onNewgroundsBrowser, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1c1054, Default, CustomSongLayer, onOptions, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1c1074, Default, CustomSongLayer, onSearch, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1c0f34, Default, CustomSongLayer, onSongBrowser, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1c11f0, Default, CustomSongLayer, showNewgroundsMessage, )
		}
	};
}
