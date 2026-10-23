#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <Geode/binding/GJAccountSettingsLayer.hpp>
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

	#ifndef GEODE_STATICS_textInputShouldOffset
		#define GEODE_STATICS_textInputShouldOffset
		GEODE_AS_STATIC_FUNCTION(textInputShouldOffset) 
	#endif

	#ifndef GEODE_STATICS_textInputReturn
		#define GEODE_STATICS_textInputReturn
		GEODE_AS_STATIC_FUNCTION(textInputReturn) 
	#endif

	#ifndef GEODE_STATICS_closeAccInputNodes
		#define GEODE_STATICS_closeAccInputNodes
		GEODE_AS_STATIC_FUNCTION(closeAccInputNodes) 
	#endif

	#ifndef GEODE_STATICS_createToggleButton
		#define GEODE_STATICS_createToggleButton
		GEODE_AS_STATIC_FUNCTION(createToggleButton) 
	#endif

	#ifndef GEODE_STATICS_init
		#define GEODE_STATICS_init
		GEODE_AS_STATIC_FUNCTION(init) 
	#endif

	#ifndef GEODE_STATICS_onClose
		#define GEODE_STATICS_onClose
		GEODE_AS_STATIC_FUNCTION(onClose) 
	#endif

	#ifndef GEODE_STATICS_onCommentSetting
		#define GEODE_STATICS_onCommentSetting
		GEODE_AS_STATIC_FUNCTION(onCommentSetting) 
	#endif

	#ifndef GEODE_STATICS_onFriendRequests
		#define GEODE_STATICS_onFriendRequests
		GEODE_AS_STATIC_FUNCTION(onFriendRequests) 
	#endif

	#ifndef GEODE_STATICS_onMessageSetting
		#define GEODE_STATICS_onMessageSetting
		GEODE_AS_STATIC_FUNCTION(onMessageSetting) 
	#endif

	#ifndef GEODE_STATICS_onUpdate
		#define GEODE_STATICS_onUpdate
		GEODE_AS_STATIC_FUNCTION(onUpdate) 
	#endif

	#ifndef GEODE_STATICS_updateScoreValues
		#define GEODE_STATICS_updateScoreValues
		GEODE_AS_STATIC_FUNCTION(updateScoreValues) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
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

	#ifndef GEODE_CONCEPT_CHECK_closeAccInputNodes
		#define GEODE_CONCEPT_CHECK_closeAccInputNodes
		GEODE_CONCEPT_FUNCTION_CHECK(closeAccInputNodes) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_createToggleButton
		#define GEODE_CONCEPT_CHECK_createToggleButton
		GEODE_CONCEPT_FUNCTION_CHECK(createToggleButton) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_init
		#define GEODE_CONCEPT_CHECK_init
		GEODE_CONCEPT_FUNCTION_CHECK(init) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onClose
		#define GEODE_CONCEPT_CHECK_onClose
		GEODE_CONCEPT_FUNCTION_CHECK(onClose) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onCommentSetting
		#define GEODE_CONCEPT_CHECK_onCommentSetting
		GEODE_CONCEPT_FUNCTION_CHECK(onCommentSetting) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onFriendRequests
		#define GEODE_CONCEPT_CHECK_onFriendRequests
		GEODE_CONCEPT_FUNCTION_CHECK(onFriendRequests) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onMessageSetting
		#define GEODE_CONCEPT_CHECK_onMessageSetting
		GEODE_CONCEPT_FUNCTION_CHECK(onMessageSetting) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onUpdate
		#define GEODE_CONCEPT_CHECK_onUpdate
		GEODE_CONCEPT_FUNCTION_CHECK(onUpdate) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_updateScoreValues
		#define GEODE_CONCEPT_CHECK_updateScoreValues
		GEODE_CONCEPT_FUNCTION_CHECK(updateScoreValues) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, GJAccountSettingsLayer> : ModifyBase<ModifyDerive<Der, GJAccountSettingsLayer>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, GJAccountSettingsLayer>>;
		using ModifyBase<ModifyDerive<Der, GJAccountSettingsLayer>>::ModifyBase;
		using Base = GJAccountSettingsLayer;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0x23e640, Default, GJAccountSettingsLayer)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x23e71c, Default, GJAccountSettingsLayer, create, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x241fe4, Default, GJAccountSettingsLayer, keyBackClicked, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x24110c, Default, GJAccountSettingsLayer, textInputShouldOffset, CCTextInputNode*, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x2411dc, Default, GJAccountSettingsLayer, textInputReturn, CCTextInputNode*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x241294, Default, GJAccountSettingsLayer, closeAccInputNodes, cocos2d::CCArray*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x24054c, Default, GJAccountSettingsLayer, createToggleButton, gd::string, cocos2d::SEL_MenuHandler, bool, cocos2d::CCMenu*, cocos2d::CCPoint, float, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x23e838, Default, GJAccountSettingsLayer, init, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x2408f0, Default, GJAccountSettingsLayer, onClose, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x24085c, Default, GJAccountSettingsLayer, onCommentSetting, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x2407c8, Default, GJAccountSettingsLayer, onFriendRequests, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x240734, Default, GJAccountSettingsLayer, onMessageSetting, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x240938, Default, GJAccountSettingsLayer, onUpdate, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x24187c, Default, GJAccountSettingsLayer, updateScoreValues, )
		}
	};
}
