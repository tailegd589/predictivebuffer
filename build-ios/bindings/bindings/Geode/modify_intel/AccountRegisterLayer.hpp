#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <Geode/binding/AccountRegisterLayer.hpp>
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

	#ifndef GEODE_STATICS_FLAlert_Clicked
		#define GEODE_STATICS_FLAlert_Clicked
		GEODE_AS_STATIC_FUNCTION(FLAlert_Clicked) 
	#endif

	#ifndef GEODE_STATICS_textInputOpened
		#define GEODE_STATICS_textInputOpened
		GEODE_AS_STATIC_FUNCTION(textInputOpened) 
	#endif

	#ifndef GEODE_STATICS_textInputClosed
		#define GEODE_STATICS_textInputClosed
		GEODE_AS_STATIC_FUNCTION(textInputClosed) 
	#endif

	#ifndef GEODE_STATICS_textChanged
		#define GEODE_STATICS_textChanged
		GEODE_AS_STATIC_FUNCTION(textChanged) 
	#endif

	#ifndef GEODE_STATICS_textInputShouldOffset
		#define GEODE_STATICS_textInputShouldOffset
		GEODE_AS_STATIC_FUNCTION(textInputShouldOffset) 
	#endif

	#ifndef GEODE_STATICS_textInputReturn
		#define GEODE_STATICS_textInputReturn
		GEODE_AS_STATIC_FUNCTION(textInputReturn) 
	#endif

	#ifndef GEODE_STATICS_allowTextInput
		#define GEODE_STATICS_allowTextInput
		GEODE_AS_STATIC_FUNCTION(allowTextInput) 
	#endif

	#ifndef GEODE_STATICS_registerAccountFinished
		#define GEODE_STATICS_registerAccountFinished
		GEODE_AS_STATIC_FUNCTION(registerAccountFinished) 
	#endif

	#ifndef GEODE_STATICS_registerAccountFailed
		#define GEODE_STATICS_registerAccountFailed
		GEODE_AS_STATIC_FUNCTION(registerAccountFailed) 
	#endif

	#ifndef GEODE_STATICS_createTextBackground
		#define GEODE_STATICS_createTextBackground
		GEODE_AS_STATIC_FUNCTION(createTextBackground) 
	#endif

	#ifndef GEODE_STATICS_createTextInput
		#define GEODE_STATICS_createTextInput
		GEODE_AS_STATIC_FUNCTION(createTextInput) 
	#endif

	#ifndef GEODE_STATICS_createTextLabel
		#define GEODE_STATICS_createTextLabel
		GEODE_AS_STATIC_FUNCTION(createTextLabel) 
	#endif

	#ifndef GEODE_STATICS_disableNodes
		#define GEODE_STATICS_disableNodes
		GEODE_AS_STATIC_FUNCTION(disableNodes) 
	#endif

	#ifndef GEODE_STATICS_hideLoadingUI
		#define GEODE_STATICS_hideLoadingUI
		GEODE_AS_STATIC_FUNCTION(hideLoadingUI) 
	#endif

	#ifndef GEODE_STATICS_onClose
		#define GEODE_STATICS_onClose
		GEODE_AS_STATIC_FUNCTION(onClose) 
	#endif

	#ifndef GEODE_STATICS_onSubmit
		#define GEODE_STATICS_onSubmit
		GEODE_AS_STATIC_FUNCTION(onSubmit) 
	#endif

	#ifndef GEODE_STATICS_resetLabel
		#define GEODE_STATICS_resetLabel
		GEODE_AS_STATIC_FUNCTION(resetLabel) 
	#endif

	#ifndef GEODE_STATICS_resetLabels
		#define GEODE_STATICS_resetLabels
		GEODE_AS_STATIC_FUNCTION(resetLabels) 
	#endif

	#ifndef GEODE_STATICS_showLoadingUI
		#define GEODE_STATICS_showLoadingUI
		GEODE_AS_STATIC_FUNCTION(showLoadingUI) 
	#endif

	#ifndef GEODE_STATICS_toggleUI
		#define GEODE_STATICS_toggleUI
		GEODE_AS_STATIC_FUNCTION(toggleUI) 
	#endif

	#ifndef GEODE_STATICS_updateLabel
		#define GEODE_STATICS_updateLabel
		GEODE_AS_STATIC_FUNCTION(updateLabel) 
	#endif

	#ifndef GEODE_STATICS_validEmail
		#define GEODE_STATICS_validEmail
		GEODE_AS_STATIC_FUNCTION(validEmail) 
	#endif

	#ifndef GEODE_STATICS_validPassword
		#define GEODE_STATICS_validPassword
		GEODE_AS_STATIC_FUNCTION(validPassword) 
	#endif

	#ifndef GEODE_STATICS_validUser
		#define GEODE_STATICS_validUser
		GEODE_AS_STATIC_FUNCTION(validUser) 
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

	#ifndef GEODE_CONCEPT_CHECK_FLAlert_Clicked
		#define GEODE_CONCEPT_CHECK_FLAlert_Clicked
		GEODE_CONCEPT_FUNCTION_CHECK(FLAlert_Clicked) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_textInputOpened
		#define GEODE_CONCEPT_CHECK_textInputOpened
		GEODE_CONCEPT_FUNCTION_CHECK(textInputOpened) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_textInputClosed
		#define GEODE_CONCEPT_CHECK_textInputClosed
		GEODE_CONCEPT_FUNCTION_CHECK(textInputClosed) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_textChanged
		#define GEODE_CONCEPT_CHECK_textChanged
		GEODE_CONCEPT_FUNCTION_CHECK(textChanged) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_textInputShouldOffset
		#define GEODE_CONCEPT_CHECK_textInputShouldOffset
		GEODE_CONCEPT_FUNCTION_CHECK(textInputShouldOffset) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_textInputReturn
		#define GEODE_CONCEPT_CHECK_textInputReturn
		GEODE_CONCEPT_FUNCTION_CHECK(textInputReturn) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_allowTextInput
		#define GEODE_CONCEPT_CHECK_allowTextInput
		GEODE_CONCEPT_FUNCTION_CHECK(allowTextInput) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_registerAccountFinished
		#define GEODE_CONCEPT_CHECK_registerAccountFinished
		GEODE_CONCEPT_FUNCTION_CHECK(registerAccountFinished) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_registerAccountFailed
		#define GEODE_CONCEPT_CHECK_registerAccountFailed
		GEODE_CONCEPT_FUNCTION_CHECK(registerAccountFailed) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_createTextBackground
		#define GEODE_CONCEPT_CHECK_createTextBackground
		GEODE_CONCEPT_FUNCTION_CHECK(createTextBackground) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_createTextInput
		#define GEODE_CONCEPT_CHECK_createTextInput
		GEODE_CONCEPT_FUNCTION_CHECK(createTextInput) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_createTextLabel
		#define GEODE_CONCEPT_CHECK_createTextLabel
		GEODE_CONCEPT_FUNCTION_CHECK(createTextLabel) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_disableNodes
		#define GEODE_CONCEPT_CHECK_disableNodes
		GEODE_CONCEPT_FUNCTION_CHECK(disableNodes) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_hideLoadingUI
		#define GEODE_CONCEPT_CHECK_hideLoadingUI
		GEODE_CONCEPT_FUNCTION_CHECK(hideLoadingUI) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onClose
		#define GEODE_CONCEPT_CHECK_onClose
		GEODE_CONCEPT_FUNCTION_CHECK(onClose) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onSubmit
		#define GEODE_CONCEPT_CHECK_onSubmit
		GEODE_CONCEPT_FUNCTION_CHECK(onSubmit) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_resetLabel
		#define GEODE_CONCEPT_CHECK_resetLabel
		GEODE_CONCEPT_FUNCTION_CHECK(resetLabel) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_resetLabels
		#define GEODE_CONCEPT_CHECK_resetLabels
		GEODE_CONCEPT_FUNCTION_CHECK(resetLabels) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_showLoadingUI
		#define GEODE_CONCEPT_CHECK_showLoadingUI
		GEODE_CONCEPT_FUNCTION_CHECK(showLoadingUI) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_toggleUI
		#define GEODE_CONCEPT_CHECK_toggleUI
		GEODE_CONCEPT_FUNCTION_CHECK(toggleUI) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_updateLabel
		#define GEODE_CONCEPT_CHECK_updateLabel
		GEODE_CONCEPT_FUNCTION_CHECK(updateLabel) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_validEmail
		#define GEODE_CONCEPT_CHECK_validEmail
		GEODE_CONCEPT_FUNCTION_CHECK(validEmail) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_validPassword
		#define GEODE_CONCEPT_CHECK_validPassword
		GEODE_CONCEPT_FUNCTION_CHECK(validPassword) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_validUser
		#define GEODE_CONCEPT_CHECK_validUser
		GEODE_CONCEPT_FUNCTION_CHECK(validUser) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, AccountRegisterLayer> : ModifyBase<ModifyDerive<Der, AccountRegisterLayer>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, AccountRegisterLayer>>;
		using ModifyBase<ModifyDerive<Der, AccountRegisterLayer>>::ModifyBase;
		using Base = AccountRegisterLayer;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0x494fb0, Default, AccountRegisterLayer)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4953d0, Default, AccountRegisterLayer, create, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x495550, Default, AccountRegisterLayer, init, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x497fc0, Default, AccountRegisterLayer, registerWithTouchDispatcher, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x497df0, Default, AccountRegisterLayer, keyBackClicked, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x497920, Default, AccountRegisterLayer, FLAlert_Clicked, FLAlertLayer*, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x498890, Default, AccountRegisterLayer, textInputOpened, CCTextInputNode*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x498000, Default, AccountRegisterLayer, textInputClosed, CCTextInputNode*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4988b0, Default, AccountRegisterLayer, textChanged, CCTextInputNode*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4988d0, Default, AccountRegisterLayer, textInputShouldOffset, CCTextInputNode*, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x498990, Default, AccountRegisterLayer, textInputReturn, CCTextInputNode*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x498a40, Default, AccountRegisterLayer, allowTextInput, CCTextInputNode*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4971e0, Default, AccountRegisterLayer, registerAccountFinished, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x497390, Default, AccountRegisterLayer, registerAccountFailed, AccountError)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x496f40, Default, AccountRegisterLayer, createTextBackground, cocos2d::CCPoint, cocos2d::CCSize)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4970f0, Default, AccountRegisterLayer, createTextInput, cocos2d::CCPoint, cocos2d::CCSize, gd::string, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x497000, Default, AccountRegisterLayer, createTextLabel, cocos2d::CCPoint, gd::string, cocos2d::CCSize)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x497a80, Default, AccountRegisterLayer, disableNodes, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x497640, Default, AccountRegisterLayer, hideLoadingUI, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x496610, Default, AccountRegisterLayer, onClose, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4966a0, Default, AccountRegisterLayer, onSubmit, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x497850, Default, AccountRegisterLayer, resetLabel, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x497730, Default, AccountRegisterLayer, resetLabels, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x497ce0, Default, AccountRegisterLayer, showLoadingUI, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x497f20, Default, AccountRegisterLayer, toggleUI, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x497540, Default, AccountRegisterLayer, updateLabel, AccountError)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x497b50, Default, AccountRegisterLayer, validEmail, gd::string)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x497b20, Default, AccountRegisterLayer, validPassword, gd::string)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x497af0, Default, AccountRegisterLayer, validUser, gd::string)
		}
	};
}
