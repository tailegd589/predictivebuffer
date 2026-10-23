#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <cocos-ext.h>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_create
		#define GEODE_STATICS_create
		GEODE_AS_STATIC_FUNCTION(create) 
	#endif

	#ifndef GEODE_STATICS_setPosition
		#define GEODE_STATICS_setPosition
		GEODE_AS_STATIC_FUNCTION(setPosition) 
	#endif

	#ifndef GEODE_STATICS_setVisible
		#define GEODE_STATICS_setVisible
		GEODE_AS_STATIC_FUNCTION(setVisible) 
	#endif

	#ifndef GEODE_STATICS_setContentSize
		#define GEODE_STATICS_setContentSize
		GEODE_AS_STATIC_FUNCTION(setContentSize) 
	#endif

	#ifndef GEODE_STATICS_setAnchorPoint
		#define GEODE_STATICS_setAnchorPoint
		GEODE_AS_STATIC_FUNCTION(setAnchorPoint) 
	#endif

	#ifndef GEODE_STATICS_visit
		#define GEODE_STATICS_visit
		GEODE_AS_STATIC_FUNCTION(visit) 
	#endif

	#ifndef GEODE_STATICS_onEnter
		#define GEODE_STATICS_onEnter
		GEODE_AS_STATIC_FUNCTION(onEnter) 
	#endif

	#ifndef GEODE_STATICS_onExit
		#define GEODE_STATICS_onExit
		GEODE_AS_STATIC_FUNCTION(onExit) 
	#endif

	#ifndef GEODE_STATICS_keyboardWillShow
		#define GEODE_STATICS_keyboardWillShow
		GEODE_AS_STATIC_FUNCTION(keyboardWillShow) 
	#endif

	#ifndef GEODE_STATICS_keyboardDidShow
		#define GEODE_STATICS_keyboardDidShow
		GEODE_AS_STATIC_FUNCTION(keyboardDidShow) 
	#endif

	#ifndef GEODE_STATICS_keyboardWillHide
		#define GEODE_STATICS_keyboardWillHide
		GEODE_AS_STATIC_FUNCTION(keyboardWillHide) 
	#endif

	#ifndef GEODE_STATICS_keyboardDidHide
		#define GEODE_STATICS_keyboardDidHide
		GEODE_AS_STATIC_FUNCTION(keyboardDidHide) 
	#endif

	#ifndef GEODE_STATICS_getDelegate
		#define GEODE_STATICS_getDelegate
		GEODE_AS_STATIC_FUNCTION(getDelegate) 
	#endif

	#ifndef GEODE_STATICS_getMaxLength
		#define GEODE_STATICS_getMaxLength
		GEODE_AS_STATIC_FUNCTION(getMaxLength) 
	#endif

	#ifndef GEODE_STATICS_getPlaceHolder
		#define GEODE_STATICS_getPlaceHolder
		GEODE_AS_STATIC_FUNCTION(getPlaceHolder) 
	#endif

	#ifndef GEODE_STATICS_getText
		#define GEODE_STATICS_getText
		GEODE_AS_STATIC_FUNCTION(getText) 
	#endif

	#ifndef GEODE_STATICS_initWithSizeAndBackgroundSprite
		#define GEODE_STATICS_initWithSizeAndBackgroundSprite
		GEODE_AS_STATIC_FUNCTION(initWithSizeAndBackgroundSprite) 
	#endif

	#ifndef GEODE_STATICS_registerScriptEditBoxHandler
		#define GEODE_STATICS_registerScriptEditBoxHandler
		GEODE_AS_STATIC_FUNCTION(registerScriptEditBoxHandler) 
	#endif

	#ifndef GEODE_STATICS_setDelegate
		#define GEODE_STATICS_setDelegate
		GEODE_AS_STATIC_FUNCTION(setDelegate) 
	#endif

	#ifndef GEODE_STATICS_setFont
		#define GEODE_STATICS_setFont
		GEODE_AS_STATIC_FUNCTION(setFont) 
	#endif

	#ifndef GEODE_STATICS_setFontColor
		#define GEODE_STATICS_setFontColor
		GEODE_AS_STATIC_FUNCTION(setFontColor) 
	#endif

	#ifndef GEODE_STATICS_setFontName
		#define GEODE_STATICS_setFontName
		GEODE_AS_STATIC_FUNCTION(setFontName) 
	#endif

	#ifndef GEODE_STATICS_setFontSize
		#define GEODE_STATICS_setFontSize
		GEODE_AS_STATIC_FUNCTION(setFontSize) 
	#endif

	#ifndef GEODE_STATICS_setInputFlag
		#define GEODE_STATICS_setInputFlag
		GEODE_AS_STATIC_FUNCTION(setInputFlag) 
	#endif

	#ifndef GEODE_STATICS_setInputMode
		#define GEODE_STATICS_setInputMode
		GEODE_AS_STATIC_FUNCTION(setInputMode) 
	#endif

	#ifndef GEODE_STATICS_setMaxLength
		#define GEODE_STATICS_setMaxLength
		GEODE_AS_STATIC_FUNCTION(setMaxLength) 
	#endif

	#ifndef GEODE_STATICS_setPlaceHolder
		#define GEODE_STATICS_setPlaceHolder
		GEODE_AS_STATIC_FUNCTION(setPlaceHolder) 
	#endif

	#ifndef GEODE_STATICS_setPlaceholderFont
		#define GEODE_STATICS_setPlaceholderFont
		GEODE_AS_STATIC_FUNCTION(setPlaceholderFont) 
	#endif

	#ifndef GEODE_STATICS_setPlaceholderFontColor
		#define GEODE_STATICS_setPlaceholderFontColor
		GEODE_AS_STATIC_FUNCTION(setPlaceholderFontColor) 
	#endif

	#ifndef GEODE_STATICS_setPlaceholderFontName
		#define GEODE_STATICS_setPlaceholderFontName
		GEODE_AS_STATIC_FUNCTION(setPlaceholderFontName) 
	#endif

	#ifndef GEODE_STATICS_setPlaceholderFontSize
		#define GEODE_STATICS_setPlaceholderFontSize
		GEODE_AS_STATIC_FUNCTION(setPlaceholderFontSize) 
	#endif

	#ifndef GEODE_STATICS_setReturnType
		#define GEODE_STATICS_setReturnType
		GEODE_AS_STATIC_FUNCTION(setReturnType) 
	#endif

	#ifndef GEODE_STATICS_setText
		#define GEODE_STATICS_setText
		GEODE_AS_STATIC_FUNCTION(setText) 
	#endif

	#ifndef GEODE_STATICS_touchDownAction
		#define GEODE_STATICS_touchDownAction
		GEODE_AS_STATIC_FUNCTION(touchDownAction) 
	#endif

	#ifndef GEODE_STATICS_unregisterScriptEditBoxHandler
		#define GEODE_STATICS_unregisterScriptEditBoxHandler
		GEODE_AS_STATIC_FUNCTION(unregisterScriptEditBoxHandler) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setPosition
		#define GEODE_CONCEPT_CHECK_setPosition
		GEODE_CONCEPT_FUNCTION_CHECK(setPosition) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setVisible
		#define GEODE_CONCEPT_CHECK_setVisible
		GEODE_CONCEPT_FUNCTION_CHECK(setVisible) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setContentSize
		#define GEODE_CONCEPT_CHECK_setContentSize
		GEODE_CONCEPT_FUNCTION_CHECK(setContentSize) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setAnchorPoint
		#define GEODE_CONCEPT_CHECK_setAnchorPoint
		GEODE_CONCEPT_FUNCTION_CHECK(setAnchorPoint) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_visit
		#define GEODE_CONCEPT_CHECK_visit
		GEODE_CONCEPT_FUNCTION_CHECK(visit) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onEnter
		#define GEODE_CONCEPT_CHECK_onEnter
		GEODE_CONCEPT_FUNCTION_CHECK(onEnter) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onExit
		#define GEODE_CONCEPT_CHECK_onExit
		GEODE_CONCEPT_FUNCTION_CHECK(onExit) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_keyboardWillShow
		#define GEODE_CONCEPT_CHECK_keyboardWillShow
		GEODE_CONCEPT_FUNCTION_CHECK(keyboardWillShow) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_keyboardDidShow
		#define GEODE_CONCEPT_CHECK_keyboardDidShow
		GEODE_CONCEPT_FUNCTION_CHECK(keyboardDidShow) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_keyboardWillHide
		#define GEODE_CONCEPT_CHECK_keyboardWillHide
		GEODE_CONCEPT_FUNCTION_CHECK(keyboardWillHide) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_keyboardDidHide
		#define GEODE_CONCEPT_CHECK_keyboardDidHide
		GEODE_CONCEPT_FUNCTION_CHECK(keyboardDidHide) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getDelegate
		#define GEODE_CONCEPT_CHECK_getDelegate
		GEODE_CONCEPT_FUNCTION_CHECK(getDelegate) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getMaxLength
		#define GEODE_CONCEPT_CHECK_getMaxLength
		GEODE_CONCEPT_FUNCTION_CHECK(getMaxLength) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getPlaceHolder
		#define GEODE_CONCEPT_CHECK_getPlaceHolder
		GEODE_CONCEPT_FUNCTION_CHECK(getPlaceHolder) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getText
		#define GEODE_CONCEPT_CHECK_getText
		GEODE_CONCEPT_FUNCTION_CHECK(getText) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_initWithSizeAndBackgroundSprite
		#define GEODE_CONCEPT_CHECK_initWithSizeAndBackgroundSprite
		GEODE_CONCEPT_FUNCTION_CHECK(initWithSizeAndBackgroundSprite) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_registerScriptEditBoxHandler
		#define GEODE_CONCEPT_CHECK_registerScriptEditBoxHandler
		GEODE_CONCEPT_FUNCTION_CHECK(registerScriptEditBoxHandler) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setDelegate
		#define GEODE_CONCEPT_CHECK_setDelegate
		GEODE_CONCEPT_FUNCTION_CHECK(setDelegate) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setFont
		#define GEODE_CONCEPT_CHECK_setFont
		GEODE_CONCEPT_FUNCTION_CHECK(setFont) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setFontColor
		#define GEODE_CONCEPT_CHECK_setFontColor
		GEODE_CONCEPT_FUNCTION_CHECK(setFontColor) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setFontName
		#define GEODE_CONCEPT_CHECK_setFontName
		GEODE_CONCEPT_FUNCTION_CHECK(setFontName) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setFontSize
		#define GEODE_CONCEPT_CHECK_setFontSize
		GEODE_CONCEPT_FUNCTION_CHECK(setFontSize) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setInputFlag
		#define GEODE_CONCEPT_CHECK_setInputFlag
		GEODE_CONCEPT_FUNCTION_CHECK(setInputFlag) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setInputMode
		#define GEODE_CONCEPT_CHECK_setInputMode
		GEODE_CONCEPT_FUNCTION_CHECK(setInputMode) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setMaxLength
		#define GEODE_CONCEPT_CHECK_setMaxLength
		GEODE_CONCEPT_FUNCTION_CHECK(setMaxLength) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setPlaceHolder
		#define GEODE_CONCEPT_CHECK_setPlaceHolder
		GEODE_CONCEPT_FUNCTION_CHECK(setPlaceHolder) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setPlaceholderFont
		#define GEODE_CONCEPT_CHECK_setPlaceholderFont
		GEODE_CONCEPT_FUNCTION_CHECK(setPlaceholderFont) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setPlaceholderFontColor
		#define GEODE_CONCEPT_CHECK_setPlaceholderFontColor
		GEODE_CONCEPT_FUNCTION_CHECK(setPlaceholderFontColor) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setPlaceholderFontName
		#define GEODE_CONCEPT_CHECK_setPlaceholderFontName
		GEODE_CONCEPT_FUNCTION_CHECK(setPlaceholderFontName) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setPlaceholderFontSize
		#define GEODE_CONCEPT_CHECK_setPlaceholderFontSize
		GEODE_CONCEPT_FUNCTION_CHECK(setPlaceholderFontSize) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setReturnType
		#define GEODE_CONCEPT_CHECK_setReturnType
		GEODE_CONCEPT_FUNCTION_CHECK(setReturnType) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setText
		#define GEODE_CONCEPT_CHECK_setText
		GEODE_CONCEPT_FUNCTION_CHECK(setText) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_touchDownAction
		#define GEODE_CONCEPT_CHECK_touchDownAction
		GEODE_CONCEPT_FUNCTION_CHECK(touchDownAction) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_unregisterScriptEditBoxHandler
		#define GEODE_CONCEPT_CHECK_unregisterScriptEditBoxHandler
		GEODE_CONCEPT_FUNCTION_CHECK(unregisterScriptEditBoxHandler) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::extension::CCEditBox> : ModifyBase<ModifyDerive<Der, cocos2d::extension::CCEditBox>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::extension::CCEditBox>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::extension::CCEditBox>>::ModifyBase;
		using Base = cocos2d::extension::CCEditBox;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0x40d318, Default, cocos2d::extension::CCEditBox, )
			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0x40d3e0, Default, cocos2d::extension::CCEditBox)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x40d59c, Default, cocos2d::extension::CCEditBox, create, cocos2d::CCSize const&, cocos2d::extension::CCScale9Sprite*, cocos2d::extension::CCScale9Sprite*, cocos2d::extension::CCScale9Sprite*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x40dbd0, Default, cocos2d::extension::CCEditBox, setPosition, cocos2d::CCPoint const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x40dc14, Default, cocos2d::extension::CCEditBox, setVisible, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x40dc58, Default, cocos2d::extension::CCEditBox, setContentSize, cocos2d::CCSize const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x40dc9c, Default, cocos2d::extension::CCEditBox, setAnchorPoint, cocos2d::CCPoint const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x40dce0, Default, cocos2d::extension::CCEditBox, visit, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x40dd1c, Default, cocos2d::extension::CCEditBox, onEnter, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x40dd58, Default, cocos2d::extension::CCEditBox, onExit, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x40dd94, Default, cocos2d::extension::CCEditBox, keyboardWillShow, cocos2d::CCIMEKeyboardNotificationInfo&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x40de70, Default, cocos2d::extension::CCEditBox, keyboardDidShow, cocos2d::CCIMEKeyboardNotificationInfo&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x40de78, Default, cocos2d::extension::CCEditBox, keyboardWillHide, cocos2d::CCIMEKeyboardNotificationInfo&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x40dec8, Default, cocos2d::extension::CCEditBox, keyboardDidHide, cocos2d::CCIMEKeyboardNotificationInfo&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x40d80c, Default, cocos2d::extension::CCEditBox, getDelegate, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x40db94, Default, cocos2d::extension::CCEditBox, getMaxLength, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x40db40, Default, cocos2d::extension::CCEditBox, getPlaceHolder, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x40d860, Default, cocos2d::extension::CCEditBox, getText, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x40d724, Default, cocos2d::extension::CCEditBox, initWithSizeAndBackgroundSprite, cocos2d::CCSize const&, cocos2d::extension::CCScale9Sprite*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x40ded0, Default, cocos2d::extension::CCEditBox, registerScriptEditBoxHandler, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x40d7f8, Default, cocos2d::extension::CCEditBox, setDelegate, cocos2d::extension::CCEditBoxDelegate*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x40d894, Default, cocos2d::extension::CCEditBox, setFont, char const*, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x40d998, Default, cocos2d::extension::CCEditBox, setFontColor, cocos2d::ccColor3B const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x40d8f8, Default, cocos2d::extension::CCEditBox, setFontName, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x40d94c, Default, cocos2d::extension::CCEditBox, setFontSize, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x40db9c, Default, cocos2d::extension::CCEditBox, setInputFlag, cocos2d::extension::EditBoxInputFlag)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x40db5c, Default, cocos2d::extension::CCEditBox, setInputMode, cocos2d::extension::EditBoxInputMode)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x40db78, Default, cocos2d::extension::CCEditBox, setMaxLength, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x40daf4, Default, cocos2d::extension::CCEditBox, setPlaceHolder, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x40d9c0, Default, cocos2d::extension::CCEditBox, setPlaceholderFont, char const*, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x40dacc, Default, cocos2d::extension::CCEditBox, setPlaceholderFontColor, cocos2d::ccColor3B const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x40da24, Default, cocos2d::extension::CCEditBox, setPlaceholderFontName, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x40da7c, Default, cocos2d::extension::CCEditBox, setPlaceholderFontSize, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x40dbb8, Default, cocos2d::extension::CCEditBox, setReturnType, cocos2d::extension::KeyboardReturnType)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x40d814, Default, cocos2d::extension::CCEditBox, setText, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x40d58c, Default, cocos2d::extension::CCEditBox, touchDownAction, cocos2d::CCObject*, cocos2d::extension::CCControlEvent)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x40d4f4, Default, cocos2d::extension::CCEditBox, unregisterScriptEditBoxHandler, )
		}
	};
}
