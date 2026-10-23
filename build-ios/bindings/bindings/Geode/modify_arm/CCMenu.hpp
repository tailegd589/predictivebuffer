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

	#ifndef GEODE_STATICS_createWithArray
		#define GEODE_STATICS_createWithArray
		GEODE_AS_STATIC_FUNCTION(createWithArray) 
	#endif

	#ifndef GEODE_STATICS_createWithItem
		#define GEODE_STATICS_createWithItem
		GEODE_AS_STATIC_FUNCTION(createWithItem) 
	#endif

	#ifndef GEODE_STATICS_createWithItems
		#define GEODE_STATICS_createWithItems
		GEODE_AS_STATIC_FUNCTION(createWithItems) 
	#endif

	#ifndef GEODE_STATICS_init
		#define GEODE_STATICS_init
		GEODE_AS_STATIC_FUNCTION(init) 
	#endif

	#ifndef GEODE_STATICS_addChild
		#define GEODE_STATICS_addChild
		GEODE_AS_STATIC_FUNCTION(addChild) 
	#endif

	#ifndef GEODE_STATICS_removeChild
		#define GEODE_STATICS_removeChild
		GEODE_AS_STATIC_FUNCTION(removeChild) 
	#endif

	#ifndef GEODE_STATICS_onExit
		#define GEODE_STATICS_onExit
		GEODE_AS_STATIC_FUNCTION(onExit) 
	#endif

	#ifndef GEODE_STATICS_registerWithTouchDispatcher
		#define GEODE_STATICS_registerWithTouchDispatcher
		GEODE_AS_STATIC_FUNCTION(registerWithTouchDispatcher) 
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

	#ifndef GEODE_STATICS_alignItemsHorizontally
		#define GEODE_STATICS_alignItemsHorizontally
		GEODE_AS_STATIC_FUNCTION(alignItemsHorizontally) 
	#endif

	#ifndef GEODE_STATICS_alignItemsHorizontallyWithPadding
		#define GEODE_STATICS_alignItemsHorizontallyWithPadding
		GEODE_AS_STATIC_FUNCTION(alignItemsHorizontallyWithPadding) 
	#endif

	#ifndef GEODE_STATICS_alignItemsInColumns
		#define GEODE_STATICS_alignItemsInColumns
		GEODE_AS_STATIC_FUNCTION(alignItemsInColumns) 
	#endif

	#ifndef GEODE_STATICS_alignItemsInColumnsWithArray
		#define GEODE_STATICS_alignItemsInColumnsWithArray
		GEODE_AS_STATIC_FUNCTION(alignItemsInColumnsWithArray) 
	#endif

	#ifndef GEODE_STATICS_alignItemsInRows
		#define GEODE_STATICS_alignItemsInRows
		GEODE_AS_STATIC_FUNCTION(alignItemsInRows) 
	#endif

	#ifndef GEODE_STATICS_alignItemsInRowsWithArray
		#define GEODE_STATICS_alignItemsInRowsWithArray
		GEODE_AS_STATIC_FUNCTION(alignItemsInRowsWithArray) 
	#endif

	#ifndef GEODE_STATICS_alignItemsVertically
		#define GEODE_STATICS_alignItemsVertically
		GEODE_AS_STATIC_FUNCTION(alignItemsVertically) 
	#endif

	#ifndef GEODE_STATICS_alignItemsVerticallyWithPadding
		#define GEODE_STATICS_alignItemsVerticallyWithPadding
		GEODE_AS_STATIC_FUNCTION(alignItemsVerticallyWithPadding) 
	#endif

	#ifndef GEODE_STATICS_giveMenuTouchPriority
		#define GEODE_STATICS_giveMenuTouchPriority
		GEODE_AS_STATIC_FUNCTION(giveMenuTouchPriority) 
	#endif

	#ifndef GEODE_STATICS_initWithArray
		#define GEODE_STATICS_initWithArray
		GEODE_AS_STATIC_FUNCTION(initWithArray) 
	#endif

	#ifndef GEODE_STATICS_itemForTouch
		#define GEODE_STATICS_itemForTouch
		GEODE_AS_STATIC_FUNCTION(itemForTouch) 
	#endif

	#ifndef GEODE_STATICS_setHandlerPriority
		#define GEODE_STATICS_setHandlerPriority
		GEODE_AS_STATIC_FUNCTION(setHandlerPriority) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_createWithArray
		#define GEODE_CONCEPT_CHECK_createWithArray
		GEODE_CONCEPT_FUNCTION_CHECK(createWithArray) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_createWithItem
		#define GEODE_CONCEPT_CHECK_createWithItem
		GEODE_CONCEPT_FUNCTION_CHECK(createWithItem) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_createWithItems
		#define GEODE_CONCEPT_CHECK_createWithItems
		GEODE_CONCEPT_FUNCTION_CHECK(createWithItems) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_init
		#define GEODE_CONCEPT_CHECK_init
		GEODE_CONCEPT_FUNCTION_CHECK(init) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_addChild
		#define GEODE_CONCEPT_CHECK_addChild
		GEODE_CONCEPT_FUNCTION_CHECK(addChild) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_removeChild
		#define GEODE_CONCEPT_CHECK_removeChild
		GEODE_CONCEPT_FUNCTION_CHECK(removeChild) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onExit
		#define GEODE_CONCEPT_CHECK_onExit
		GEODE_CONCEPT_FUNCTION_CHECK(onExit) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_registerWithTouchDispatcher
		#define GEODE_CONCEPT_CHECK_registerWithTouchDispatcher
		GEODE_CONCEPT_FUNCTION_CHECK(registerWithTouchDispatcher) 
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

	#ifndef GEODE_CONCEPT_CHECK_alignItemsHorizontally
		#define GEODE_CONCEPT_CHECK_alignItemsHorizontally
		GEODE_CONCEPT_FUNCTION_CHECK(alignItemsHorizontally) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_alignItemsHorizontallyWithPadding
		#define GEODE_CONCEPT_CHECK_alignItemsHorizontallyWithPadding
		GEODE_CONCEPT_FUNCTION_CHECK(alignItemsHorizontallyWithPadding) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_alignItemsInColumns
		#define GEODE_CONCEPT_CHECK_alignItemsInColumns
		GEODE_CONCEPT_FUNCTION_CHECK(alignItemsInColumns) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_alignItemsInColumnsWithArray
		#define GEODE_CONCEPT_CHECK_alignItemsInColumnsWithArray
		GEODE_CONCEPT_FUNCTION_CHECK(alignItemsInColumnsWithArray) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_alignItemsInRows
		#define GEODE_CONCEPT_CHECK_alignItemsInRows
		GEODE_CONCEPT_FUNCTION_CHECK(alignItemsInRows) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_alignItemsInRowsWithArray
		#define GEODE_CONCEPT_CHECK_alignItemsInRowsWithArray
		GEODE_CONCEPT_FUNCTION_CHECK(alignItemsInRowsWithArray) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_alignItemsVertically
		#define GEODE_CONCEPT_CHECK_alignItemsVertically
		GEODE_CONCEPT_FUNCTION_CHECK(alignItemsVertically) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_alignItemsVerticallyWithPadding
		#define GEODE_CONCEPT_CHECK_alignItemsVerticallyWithPadding
		GEODE_CONCEPT_FUNCTION_CHECK(alignItemsVerticallyWithPadding) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_giveMenuTouchPriority
		#define GEODE_CONCEPT_CHECK_giveMenuTouchPriority
		GEODE_CONCEPT_FUNCTION_CHECK(giveMenuTouchPriority) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_initWithArray
		#define GEODE_CONCEPT_CHECK_initWithArray
		GEODE_CONCEPT_FUNCTION_CHECK(initWithArray) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_itemForTouch
		#define GEODE_CONCEPT_CHECK_itemForTouch
		GEODE_CONCEPT_FUNCTION_CHECK(itemForTouch) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setHandlerPriority
		#define GEODE_CONCEPT_CHECK_setHandlerPriority
		GEODE_CONCEPT_FUNCTION_CHECK(setHandlerPriority) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCMenu> : ModifyBase<ModifyDerive<Der, cocos2d::CCMenu>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCMenu>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCMenu>>::ModifyBase;
		using Base = cocos2d::CCMenu;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x69b524, Default, cocos2d::CCMenu, create, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x69b67c, Default, cocos2d::CCMenu, createWithArray, cocos2d::CCArray*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x69b8c8, Default, cocos2d::CCMenu, createWithItem, cocos2d::CCMenuItem*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x69b570, Default, cocos2d::CCMenu, createWithItems, cocos2d::CCMenuItem*, va_list)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x69b8e8, Default, cocos2d::CCMenu, init, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x69b8f0, Default, cocos2d::CCMenu, addChild, cocos2d::CCNode*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x69b8f4, Default, cocos2d::CCMenu, addChild, cocos2d::CCNode*, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x69b8f8, Default, cocos2d::CCMenu, addChild, cocos2d::CCNode*, int, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x69b948, Default, cocos2d::CCMenu, removeChild, cocos2d::CCNode*, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x69b8fc, Default, cocos2d::CCMenu, onExit, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x69baa4, Default, cocos2d::CCMenu, registerWithTouchDispatcher, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x69baf4, Default, cocos2d::CCMenu, ccTouchBegan, cocos2d::CCTouch*, cocos2d::CCEvent*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x69bdcc, Default, cocos2d::CCMenu, ccTouchMoved, cocos2d::CCTouch*, cocos2d::CCEvent*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x69bcdc, Default, cocos2d::CCMenu, ccTouchEnded, cocos2d::CCTouch*, cocos2d::CCEvent*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x69bd64, Default, cocos2d::CCMenu, ccTouchCancelled, cocos2d::CCTouch*, cocos2d::CCEvent*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x69c100, Default, cocos2d::CCMenu, alignItemsHorizontally, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x69c108, Default, cocos2d::CCMenu, alignItemsHorizontallyWithPadding, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x69c328, Default, cocos2d::CCMenu, alignItemsInColumns, unsigned int, va_list)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x69c3dc, Default, cocos2d::CCMenu, alignItemsInColumnsWithArray, cocos2d::CCArray*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x69c838, Default, cocos2d::CCMenu, alignItemsInRows, unsigned int, va_list)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x69c8ec, Default, cocos2d::CCMenu, alignItemsInRowsWithArray, cocos2d::CCArray*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x69bf00, Default, cocos2d::CCMenu, alignItemsVertically, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x69bf08, Default, cocos2d::CCMenu, alignItemsVerticallyWithPadding, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x69b9dc, Default, cocos2d::CCMenu, giveMenuTouchPriority, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x69b734, Default, cocos2d::CCMenu, initWithArray, cocos2d::CCArray*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x69bbc4, Default, cocos2d::CCMenu, itemForTouch, cocos2d::CCTouch*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x69ce24, Default, cocos2d::CCMenu, itemForTouch, cocos2d::CCTouch*, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x69ba6c, Default, cocos2d::CCMenu, setHandlerPriority, int)
		}
	};
}
