#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <Geode/binding/NumberInputLayer.hpp>
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

	#ifndef GEODE_STATICS_registerWithTouchDispatcher
		#define GEODE_STATICS_registerWithTouchDispatcher
		GEODE_AS_STATIC_FUNCTION(registerWithTouchDispatcher) 
	#endif

	#ifndef GEODE_STATICS_keyBackClicked
		#define GEODE_STATICS_keyBackClicked
		GEODE_AS_STATIC_FUNCTION(keyBackClicked) 
	#endif

	#ifndef GEODE_STATICS_deleteLast
		#define GEODE_STATICS_deleteLast
		GEODE_AS_STATIC_FUNCTION(deleteLast) 
	#endif

	#ifndef GEODE_STATICS_inputNumber
		#define GEODE_STATICS_inputNumber
		GEODE_AS_STATIC_FUNCTION(inputNumber) 
	#endif

	#ifndef GEODE_STATICS_onClose
		#define GEODE_STATICS_onClose
		GEODE_AS_STATIC_FUNCTION(onClose) 
	#endif

	#ifndef GEODE_STATICS_onDone
		#define GEODE_STATICS_onDone
		GEODE_AS_STATIC_FUNCTION(onDone) 
	#endif

	#ifndef GEODE_STATICS_onNumber
		#define GEODE_STATICS_onNumber
		GEODE_AS_STATIC_FUNCTION(onNumber) 
	#endif

	#ifndef GEODE_STATICS_updateNumberState
		#define GEODE_STATICS_updateNumberState
		GEODE_AS_STATIC_FUNCTION(updateNumberState) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_init
		#define GEODE_CONCEPT_CHECK_init
		GEODE_CONCEPT_FUNCTION_CHECK(init) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_registerWithTouchDispatcher
		#define GEODE_CONCEPT_CHECK_registerWithTouchDispatcher
		GEODE_CONCEPT_FUNCTION_CHECK(registerWithTouchDispatcher) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_keyBackClicked
		#define GEODE_CONCEPT_CHECK_keyBackClicked
		GEODE_CONCEPT_FUNCTION_CHECK(keyBackClicked) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_deleteLast
		#define GEODE_CONCEPT_CHECK_deleteLast
		GEODE_CONCEPT_FUNCTION_CHECK(deleteLast) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_inputNumber
		#define GEODE_CONCEPT_CHECK_inputNumber
		GEODE_CONCEPT_FUNCTION_CHECK(inputNumber) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onClose
		#define GEODE_CONCEPT_CHECK_onClose
		GEODE_CONCEPT_FUNCTION_CHECK(onClose) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onDone
		#define GEODE_CONCEPT_CHECK_onDone
		GEODE_CONCEPT_FUNCTION_CHECK(onDone) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onNumber
		#define GEODE_CONCEPT_CHECK_onNumber
		GEODE_CONCEPT_FUNCTION_CHECK(onNumber) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_updateNumberState
		#define GEODE_CONCEPT_CHECK_updateNumberState
		GEODE_CONCEPT_FUNCTION_CHECK(updateNumberState) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, NumberInputLayer> : ModifyBase<ModifyDerive<Der, NumberInputLayer>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, NumberInputLayer>>;
		using ModifyBase<ModifyDerive<Der, NumberInputLayer>>::ModifyBase;
		using Base = NumberInputLayer;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4922c0, Default, NumberInputLayer, create, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x492420, Default, NumberInputLayer, init, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x493330, Default, NumberInputLayer, registerWithTouchDispatcher, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4932c0, Default, NumberInputLayer, keyBackClicked, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x492fa0, Default, NumberInputLayer, deleteLast, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4931c0, Default, NumberInputLayer, inputNumber, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x492e40, Default, NumberInputLayer, onClose, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x493170, Default, NumberInputLayer, onDone, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x492e70, Default, NumberInputLayer, onNumber, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x492ef0, Default, NumberInputLayer, updateNumberState, )
		}
	};
}
