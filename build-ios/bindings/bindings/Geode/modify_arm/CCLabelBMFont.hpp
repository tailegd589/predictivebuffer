#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <cocos2d.h>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_create
		#define GEODE_STATICS_create
		GEODE_AS_STATIC_FUNCTION(create) 
	#endif

	#ifndef GEODE_STATICS_createBatched
		#define GEODE_STATICS_createBatched
		GEODE_AS_STATIC_FUNCTION(createBatched) 
	#endif

	#ifndef GEODE_STATICS_purgeCachedData
		#define GEODE_STATICS_purgeCachedData
		GEODE_AS_STATIC_FUNCTION(purgeCachedData) 
	#endif

	#ifndef GEODE_STATICS_init
		#define GEODE_STATICS_init
		GEODE_AS_STATIC_FUNCTION(init) 
	#endif

	#ifndef GEODE_STATICS_setScaleX
		#define GEODE_STATICS_setScaleX
		GEODE_AS_STATIC_FUNCTION(setScaleX) 
	#endif

	#ifndef GEODE_STATICS_setScaleY
		#define GEODE_STATICS_setScaleY
		GEODE_AS_STATIC_FUNCTION(setScaleY) 
	#endif

	#ifndef GEODE_STATICS_setScale
		#define GEODE_STATICS_setScale
		GEODE_AS_STATIC_FUNCTION(setScale) 
	#endif

	#ifndef GEODE_STATICS_setAnchorPoint
		#define GEODE_STATICS_setAnchorPoint
		GEODE_AS_STATIC_FUNCTION(setAnchorPoint) 
	#endif

	#ifndef GEODE_STATICS_setString
		#define GEODE_STATICS_setString
		GEODE_AS_STATIC_FUNCTION(setString) 
	#endif

	#ifndef GEODE_STATICS_getString
		#define GEODE_STATICS_getString
		GEODE_AS_STATIC_FUNCTION(getString) 
	#endif

	#ifndef GEODE_STATICS_setCString
		#define GEODE_STATICS_setCString
		GEODE_AS_STATIC_FUNCTION(setCString) 
	#endif

	#ifndef GEODE_STATICS_updateLabel
		#define GEODE_STATICS_updateLabel
		GEODE_AS_STATIC_FUNCTION(updateLabel) 
	#endif

	#ifndef GEODE_STATICS_setAlignment
		#define GEODE_STATICS_setAlignment
		GEODE_AS_STATIC_FUNCTION(setAlignment) 
	#endif

	#ifndef GEODE_STATICS_setWidth
		#define GEODE_STATICS_setWidth
		GEODE_AS_STATIC_FUNCTION(setWidth) 
	#endif

	#ifndef GEODE_STATICS_setLineBreakWithoutSpace
		#define GEODE_STATICS_setLineBreakWithoutSpace
		GEODE_AS_STATIC_FUNCTION(setLineBreakWithoutSpace) 
	#endif

	#ifndef GEODE_STATICS_setColor
		#define GEODE_STATICS_setColor
		GEODE_AS_STATIC_FUNCTION(setColor) 
	#endif

	#ifndef GEODE_STATICS_getColor
		#define GEODE_STATICS_getColor
		GEODE_AS_STATIC_FUNCTION(getColor) 
	#endif

	#ifndef GEODE_STATICS_getDisplayedColor
		#define GEODE_STATICS_getDisplayedColor
		GEODE_AS_STATIC_FUNCTION(getDisplayedColor) 
	#endif

	#ifndef GEODE_STATICS_getDisplayedOpacity
		#define GEODE_STATICS_getDisplayedOpacity
		GEODE_AS_STATIC_FUNCTION(getDisplayedOpacity) 
	#endif

	#ifndef GEODE_STATICS_getOpacity
		#define GEODE_STATICS_getOpacity
		GEODE_AS_STATIC_FUNCTION(getOpacity) 
	#endif

	#ifndef GEODE_STATICS_setOpacity
		#define GEODE_STATICS_setOpacity
		GEODE_AS_STATIC_FUNCTION(setOpacity) 
	#endif

	#ifndef GEODE_STATICS_setOpacityModifyRGB
		#define GEODE_STATICS_setOpacityModifyRGB
		GEODE_AS_STATIC_FUNCTION(setOpacityModifyRGB) 
	#endif

	#ifndef GEODE_STATICS_isOpacityModifyRGB
		#define GEODE_STATICS_isOpacityModifyRGB
		GEODE_AS_STATIC_FUNCTION(isOpacityModifyRGB) 
	#endif

	#ifndef GEODE_STATICS_isCascadeColorEnabled
		#define GEODE_STATICS_isCascadeColorEnabled
		GEODE_AS_STATIC_FUNCTION(isCascadeColorEnabled) 
	#endif

	#ifndef GEODE_STATICS_setCascadeColorEnabled
		#define GEODE_STATICS_setCascadeColorEnabled
		GEODE_AS_STATIC_FUNCTION(setCascadeColorEnabled) 
	#endif

	#ifndef GEODE_STATICS_updateDisplayedColor
		#define GEODE_STATICS_updateDisplayedColor
		GEODE_AS_STATIC_FUNCTION(updateDisplayedColor) 
	#endif

	#ifndef GEODE_STATICS_isCascadeOpacityEnabled
		#define GEODE_STATICS_isCascadeOpacityEnabled
		GEODE_AS_STATIC_FUNCTION(isCascadeOpacityEnabled) 
	#endif

	#ifndef GEODE_STATICS_setCascadeOpacityEnabled
		#define GEODE_STATICS_setCascadeOpacityEnabled
		GEODE_AS_STATIC_FUNCTION(setCascadeOpacityEnabled) 
	#endif

	#ifndef GEODE_STATICS_updateDisplayedOpacity
		#define GEODE_STATICS_updateDisplayedOpacity
		GEODE_AS_STATIC_FUNCTION(updateDisplayedOpacity) 
	#endif

	#ifndef GEODE_STATICS_createFontChars
		#define GEODE_STATICS_createFontChars
		GEODE_AS_STATIC_FUNCTION(createFontChars) 
	#endif

	#ifndef GEODE_STATICS_getFntFile
		#define GEODE_STATICS_getFntFile
		GEODE_AS_STATIC_FUNCTION(getFntFile) 
	#endif

	#ifndef GEODE_STATICS_getLetterPosXLeft
		#define GEODE_STATICS_getLetterPosXLeft
		GEODE_AS_STATIC_FUNCTION(getLetterPosXLeft) 
	#endif

	#ifndef GEODE_STATICS_getLetterPosXRight
		#define GEODE_STATICS_getLetterPosXRight
		GEODE_AS_STATIC_FUNCTION(getLetterPosXRight) 
	#endif

	#ifndef GEODE_STATICS_initWithString
		#define GEODE_STATICS_initWithString
		GEODE_AS_STATIC_FUNCTION(initWithString) 
	#endif

	#ifndef GEODE_STATICS_kerningAmountForFirst
		#define GEODE_STATICS_kerningAmountForFirst
		GEODE_AS_STATIC_FUNCTION(kerningAmountForFirst) 
	#endif

	#ifndef GEODE_STATICS_limitLabelWidth
		#define GEODE_STATICS_limitLabelWidth
		GEODE_AS_STATIC_FUNCTION(limitLabelWidth) 
	#endif

	#ifndef GEODE_STATICS_setFntFile
		#define GEODE_STATICS_setFntFile
		GEODE_AS_STATIC_FUNCTION(setFntFile) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_createBatched
		#define GEODE_CONCEPT_CHECK_createBatched
		GEODE_CONCEPT_FUNCTION_CHECK(createBatched) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_purgeCachedData
		#define GEODE_CONCEPT_CHECK_purgeCachedData
		GEODE_CONCEPT_FUNCTION_CHECK(purgeCachedData) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_init
		#define GEODE_CONCEPT_CHECK_init
		GEODE_CONCEPT_FUNCTION_CHECK(init) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setScaleX
		#define GEODE_CONCEPT_CHECK_setScaleX
		GEODE_CONCEPT_FUNCTION_CHECK(setScaleX) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setScaleY
		#define GEODE_CONCEPT_CHECK_setScaleY
		GEODE_CONCEPT_FUNCTION_CHECK(setScaleY) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setScale
		#define GEODE_CONCEPT_CHECK_setScale
		GEODE_CONCEPT_FUNCTION_CHECK(setScale) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setAnchorPoint
		#define GEODE_CONCEPT_CHECK_setAnchorPoint
		GEODE_CONCEPT_FUNCTION_CHECK(setAnchorPoint) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setString
		#define GEODE_CONCEPT_CHECK_setString
		GEODE_CONCEPT_FUNCTION_CHECK(setString) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getString
		#define GEODE_CONCEPT_CHECK_getString
		GEODE_CONCEPT_FUNCTION_CHECK(getString) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setCString
		#define GEODE_CONCEPT_CHECK_setCString
		GEODE_CONCEPT_FUNCTION_CHECK(setCString) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_updateLabel
		#define GEODE_CONCEPT_CHECK_updateLabel
		GEODE_CONCEPT_FUNCTION_CHECK(updateLabel) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setAlignment
		#define GEODE_CONCEPT_CHECK_setAlignment
		GEODE_CONCEPT_FUNCTION_CHECK(setAlignment) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setWidth
		#define GEODE_CONCEPT_CHECK_setWidth
		GEODE_CONCEPT_FUNCTION_CHECK(setWidth) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setLineBreakWithoutSpace
		#define GEODE_CONCEPT_CHECK_setLineBreakWithoutSpace
		GEODE_CONCEPT_FUNCTION_CHECK(setLineBreakWithoutSpace) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setColor
		#define GEODE_CONCEPT_CHECK_setColor
		GEODE_CONCEPT_FUNCTION_CHECK(setColor) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getColor
		#define GEODE_CONCEPT_CHECK_getColor
		GEODE_CONCEPT_FUNCTION_CHECK(getColor) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getDisplayedColor
		#define GEODE_CONCEPT_CHECK_getDisplayedColor
		GEODE_CONCEPT_FUNCTION_CHECK(getDisplayedColor) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getDisplayedOpacity
		#define GEODE_CONCEPT_CHECK_getDisplayedOpacity
		GEODE_CONCEPT_FUNCTION_CHECK(getDisplayedOpacity) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getOpacity
		#define GEODE_CONCEPT_CHECK_getOpacity
		GEODE_CONCEPT_FUNCTION_CHECK(getOpacity) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setOpacity
		#define GEODE_CONCEPT_CHECK_setOpacity
		GEODE_CONCEPT_FUNCTION_CHECK(setOpacity) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setOpacityModifyRGB
		#define GEODE_CONCEPT_CHECK_setOpacityModifyRGB
		GEODE_CONCEPT_FUNCTION_CHECK(setOpacityModifyRGB) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_isOpacityModifyRGB
		#define GEODE_CONCEPT_CHECK_isOpacityModifyRGB
		GEODE_CONCEPT_FUNCTION_CHECK(isOpacityModifyRGB) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_isCascadeColorEnabled
		#define GEODE_CONCEPT_CHECK_isCascadeColorEnabled
		GEODE_CONCEPT_FUNCTION_CHECK(isCascadeColorEnabled) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setCascadeColorEnabled
		#define GEODE_CONCEPT_CHECK_setCascadeColorEnabled
		GEODE_CONCEPT_FUNCTION_CHECK(setCascadeColorEnabled) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_updateDisplayedColor
		#define GEODE_CONCEPT_CHECK_updateDisplayedColor
		GEODE_CONCEPT_FUNCTION_CHECK(updateDisplayedColor) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_isCascadeOpacityEnabled
		#define GEODE_CONCEPT_CHECK_isCascadeOpacityEnabled
		GEODE_CONCEPT_FUNCTION_CHECK(isCascadeOpacityEnabled) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setCascadeOpacityEnabled
		#define GEODE_CONCEPT_CHECK_setCascadeOpacityEnabled
		GEODE_CONCEPT_FUNCTION_CHECK(setCascadeOpacityEnabled) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_updateDisplayedOpacity
		#define GEODE_CONCEPT_CHECK_updateDisplayedOpacity
		GEODE_CONCEPT_FUNCTION_CHECK(updateDisplayedOpacity) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_createFontChars
		#define GEODE_CONCEPT_CHECK_createFontChars
		GEODE_CONCEPT_FUNCTION_CHECK(createFontChars) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getFntFile
		#define GEODE_CONCEPT_CHECK_getFntFile
		GEODE_CONCEPT_FUNCTION_CHECK(getFntFile) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getLetterPosXLeft
		#define GEODE_CONCEPT_CHECK_getLetterPosXLeft
		GEODE_CONCEPT_FUNCTION_CHECK(getLetterPosXLeft) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getLetterPosXRight
		#define GEODE_CONCEPT_CHECK_getLetterPosXRight
		GEODE_CONCEPT_FUNCTION_CHECK(getLetterPosXRight) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_initWithString
		#define GEODE_CONCEPT_CHECK_initWithString
		GEODE_CONCEPT_FUNCTION_CHECK(initWithString) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_kerningAmountForFirst
		#define GEODE_CONCEPT_CHECK_kerningAmountForFirst
		GEODE_CONCEPT_FUNCTION_CHECK(kerningAmountForFirst) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_limitLabelWidth
		#define GEODE_CONCEPT_CHECK_limitLabelWidth
		GEODE_CONCEPT_FUNCTION_CHECK(limitLabelWidth) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setFntFile
		#define GEODE_CONCEPT_CHECK_setFntFile
		GEODE_CONCEPT_FUNCTION_CHECK(setFntFile) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCLabelBMFont> : ModifyBase<ModifyDerive<Der, cocos2d::CCLabelBMFont>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCLabelBMFont>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCLabelBMFont>>::ModifyBase;
		using Base = cocos2d::CCLabelBMFont;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0x504818, Default, cocos2d::CCLabelBMFont, )
			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0x5048f4, Default, cocos2d::CCLabelBMFont)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x5040c4, Default, cocos2d::CCLabelBMFont, create, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x50438c, Default, cocos2d::CCLabelBMFont, create, char const*, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x5042cc, Default, cocos2d::CCLabelBMFont, create, char const*, char const*, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x504148, Default, cocos2d::CCLabelBMFont, create, char const*, char const*, float, cocos2d::CCTextAlignment)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x50420c, Default, cocos2d::CCLabelBMFont, create, char const*, char const*, float, cocos2d::CCTextAlignment, cocos2d::CCPoint)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x504700, Default, cocos2d::CCLabelBMFont, createBatched, char const*, char const*, cocos2d::CCArray*, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x50408c, Default, cocos2d::CCLabelBMFont, purgeCachedData, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x5047c8, Default, cocos2d::CCLabelBMFont, init, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x506b4c, Default, cocos2d::CCLabelBMFont, setScaleX, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x506b78, Default, cocos2d::CCLabelBMFont, setScaleY, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x506b20, Default, cocos2d::CCLabelBMFont, setScale, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x505d34, Default, cocos2d::CCLabelBMFont, setAnchorPoint, cocos2d::CCPoint const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x505308, Default, cocos2d::CCLabelBMFont, setString, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x50532c, Default, cocos2d::CCLabelBMFont, setString, char const*, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x505554, Default, cocos2d::CCLabelBMFont, getString, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x50558c, Default, cocos2d::CCLabelBMFont, setCString, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x505d88, Default, cocos2d::CCLabelBMFont, updateLabel, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x506af0, Default, cocos2d::CCLabelBMFont, setAlignment, cocos2d::CCTextAlignment)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x506b00, Default, cocos2d::CCLabelBMFont, setWidth, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x506b10, Default, cocos2d::CCLabelBMFont, setLineBreakWithoutSpace, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x5053b4, Default, cocos2d::CCLabelBMFont, setString, unsigned short*, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x5055b8, Default, cocos2d::CCLabelBMFont, setColor, cocos2d::ccColor3B const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x505598, Default, cocos2d::CCLabelBMFont, getColor, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x5055a8, Default, cocos2d::CCLabelBMFont, getDisplayedColor, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x50575c, Default, cocos2d::CCLabelBMFont, getDisplayedOpacity, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x50574c, Default, cocos2d::CCLabelBMFont, getOpacity, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x50576c, Default, cocos2d::CCLabelBMFont, setOpacity, unsigned char)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x5058d8, Default, cocos2d::CCLabelBMFont, setOpacityModifyRGB, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x505a38, Default, cocos2d::CCLabelBMFont, isOpacityModifyRGB, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x505cf4, Default, cocos2d::CCLabelBMFont, isCascadeColorEnabled, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x505d04, Default, cocos2d::CCLabelBMFont, setCascadeColorEnabled, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x505b60, Default, cocos2d::CCLabelBMFont, updateDisplayedColor, cocos2d::ccColor3B const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x505d14, Default, cocos2d::CCLabelBMFont, isCascadeOpacityEnabled, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x505d24, Default, cocos2d::CCLabelBMFont, setCascadeOpacityEnabled, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x505a48, Default, cocos2d::CCLabelBMFont, updateDisplayedOpacity, unsigned char)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x504ae0, Default, cocos2d::CCLabelBMFont, createFontChars, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x506c78, Default, cocos2d::CCLabelBMFont, getFntFile, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x5069a8, Default, cocos2d::CCLabelBMFont, getLetterPosXLeft, cocos2d::CCSprite*, float, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x506a4c, Default, cocos2d::CCLabelBMFont, getLetterPosXRight, cocos2d::CCSprite*, float, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x504454, Default, cocos2d::CCLabelBMFont, initWithString, char const*, char const*, float, cocos2d::CCTextAlignment, cocos2d::CCPoint)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x5049c0, Default, cocos2d::CCLabelBMFont, kerningAmountForFirst, unsigned short, unsigned short)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x506c9c, Default, cocos2d::CCLabelBMFont, limitLabelWidth, float, float, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x506ba4, Default, cocos2d::CCLabelBMFont, setFntFile, char const*)
		}
	};
}
