#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <cocos2d.h>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_convertKeyCode
		#define GEODE_STATICS_convertKeyCode
		GEODE_AS_STATIC_FUNCTION(convertKeyCode) 
	#endif

	#ifndef GEODE_STATICS_addDelegate
		#define GEODE_STATICS_addDelegate
		GEODE_AS_STATIC_FUNCTION(addDelegate) 
	#endif

	#ifndef GEODE_STATICS_dispatchKeyboardMSG
		#define GEODE_STATICS_dispatchKeyboardMSG
		GEODE_AS_STATIC_FUNCTION(dispatchKeyboardMSG) 
	#endif

	#ifndef GEODE_STATICS_forceAddDelegate
		#define GEODE_STATICS_forceAddDelegate
		GEODE_AS_STATIC_FUNCTION(forceAddDelegate) 
	#endif

	#ifndef GEODE_STATICS_forceRemoveDelegate
		#define GEODE_STATICS_forceRemoveDelegate
		GEODE_AS_STATIC_FUNCTION(forceRemoveDelegate) 
	#endif

	#ifndef GEODE_STATICS_keyToString
		#define GEODE_STATICS_keyToString
		GEODE_AS_STATIC_FUNCTION(keyToString) 
	#endif

	#ifndef GEODE_STATICS_removeDelegate
		#define GEODE_STATICS_removeDelegate
		GEODE_AS_STATIC_FUNCTION(removeDelegate) 
	#endif

	#ifndef GEODE_STATICS_updateModifierKeys
		#define GEODE_STATICS_updateModifierKeys
		GEODE_AS_STATIC_FUNCTION(updateModifierKeys) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_convertKeyCode
		#define GEODE_CONCEPT_CHECK_convertKeyCode
		GEODE_CONCEPT_FUNCTION_CHECK(convertKeyCode) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_addDelegate
		#define GEODE_CONCEPT_CHECK_addDelegate
		GEODE_CONCEPT_FUNCTION_CHECK(addDelegate) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_dispatchKeyboardMSG
		#define GEODE_CONCEPT_CHECK_dispatchKeyboardMSG
		GEODE_CONCEPT_FUNCTION_CHECK(dispatchKeyboardMSG) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_forceAddDelegate
		#define GEODE_CONCEPT_CHECK_forceAddDelegate
		GEODE_CONCEPT_FUNCTION_CHECK(forceAddDelegate) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_forceRemoveDelegate
		#define GEODE_CONCEPT_CHECK_forceRemoveDelegate
		GEODE_CONCEPT_FUNCTION_CHECK(forceRemoveDelegate) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_keyToString
		#define GEODE_CONCEPT_CHECK_keyToString
		GEODE_CONCEPT_FUNCTION_CHECK(keyToString) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_removeDelegate
		#define GEODE_CONCEPT_CHECK_removeDelegate
		GEODE_CONCEPT_FUNCTION_CHECK(removeDelegate) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_updateModifierKeys
		#define GEODE_CONCEPT_CHECK_updateModifierKeys
		GEODE_CONCEPT_FUNCTION_CHECK(updateModifierKeys) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCKeyboardDispatcher> : ModifyBase<ModifyDerive<Der, cocos2d::CCKeyboardDispatcher>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCKeyboardDispatcher>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCKeyboardDispatcher>>::ModifyBase;
		using Base = cocos2d::CCKeyboardDispatcher;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0x203250, Default, cocos2d::CCKeyboardDispatcher, )
			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0x2032d0, Default, cocos2d::CCKeyboardDispatcher)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x203870, Default, cocos2d::CCKeyboardDispatcher, convertKeyCode, cocos2d::enumKeyCodes)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x203530, Default, cocos2d::CCKeyboardDispatcher, addDelegate, cocos2d::CCKeyboardDelegate*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x2035b0, Default, cocos2d::CCKeyboardDispatcher, dispatchKeyboardMSG, cocos2d::enumKeyCodes, bool, bool, double)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x203580, Default, cocos2d::CCKeyboardDispatcher, forceAddDelegate, cocos2d::CCKeyboardDelegate*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x2034a0, Default, cocos2d::CCKeyboardDispatcher, forceRemoveDelegate, cocos2d::CCKeyboardDelegate*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x2038c0, Default, cocos2d::CCKeyboardDispatcher, keyToString, cocos2d::enumKeyCodes)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x2033f0, Default, cocos2d::CCKeyboardDispatcher, removeDelegate, cocos2d::CCKeyboardDelegate*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x203890, Default, cocos2d::CCKeyboardDispatcher, updateModifierKeys, bool, bool, bool, bool)
		}
	};
}
