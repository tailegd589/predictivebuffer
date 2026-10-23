#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <Geode/binding/GJAccountManager.hpp>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_sharedState
		#define GEODE_STATICS_sharedState
		GEODE_AS_STATIC_FUNCTION(sharedState) 
	#endif

	#ifndef GEODE_STATICS_init
		#define GEODE_STATICS_init
		GEODE_AS_STATIC_FUNCTION(init) 
	#endif

	#ifndef GEODE_STATICS_addDLToActive
		#define GEODE_STATICS_addDLToActive
		GEODE_AS_STATIC_FUNCTION(addDLToActive) 
	#endif

	#ifndef GEODE_STATICS_backupAccount
		#define GEODE_STATICS_backupAccount
		GEODE_AS_STATIC_FUNCTION(backupAccount) 
	#endif

	#ifndef GEODE_STATICS_dataLoaded
		#define GEODE_STATICS_dataLoaded
		GEODE_AS_STATIC_FUNCTION(dataLoaded) 
	#endif

	#ifndef GEODE_STATICS_encodeDataTo
		#define GEODE_STATICS_encodeDataTo
		GEODE_AS_STATIC_FUNCTION(encodeDataTo) 
	#endif

	#ifndef GEODE_STATICS_firstSetup
		#define GEODE_STATICS_firstSetup
		GEODE_AS_STATIC_FUNCTION(firstSetup) 
	#endif

	#ifndef GEODE_STATICS_getAccountBackupURL
		#define GEODE_STATICS_getAccountBackupURL
		GEODE_AS_STATIC_FUNCTION(getAccountBackupURL) 
	#endif

	#ifndef GEODE_STATICS_getAccountSyncURL
		#define GEODE_STATICS_getAccountSyncURL
		GEODE_AS_STATIC_FUNCTION(getAccountSyncURL) 
	#endif

	#ifndef GEODE_STATICS_getDLObject
		#define GEODE_STATICS_getDLObject
		GEODE_AS_STATIC_FUNCTION(getDLObject) 
	#endif

	#ifndef GEODE_STATICS_getShaPassword
		#define GEODE_STATICS_getShaPassword
		GEODE_AS_STATIC_FUNCTION(getShaPassword) 
	#endif

	#ifndef GEODE_STATICS_handleIt
		#define GEODE_STATICS_handleIt
		GEODE_AS_STATIC_FUNCTION(handleIt) 
	#endif

	#ifndef GEODE_STATICS_handleItDelayed
		#define GEODE_STATICS_handleItDelayed
		GEODE_AS_STATIC_FUNCTION(handleItDelayed) 
	#endif

	#ifndef GEODE_STATICS_handleItND
		#define GEODE_STATICS_handleItND
		GEODE_AS_STATIC_FUNCTION(handleItND) 
	#endif

	#ifndef GEODE_STATICS_isDLActive
		#define GEODE_STATICS_isDLActive
		GEODE_AS_STATIC_FUNCTION(isDLActive) 
	#endif

	#ifndef GEODE_STATICS_linkToAccount
		#define GEODE_STATICS_linkToAccount
		GEODE_AS_STATIC_FUNCTION(linkToAccount) 
	#endif

	#ifndef GEODE_STATICS_loginAccount
		#define GEODE_STATICS_loginAccount
		GEODE_AS_STATIC_FUNCTION(loginAccount) 
	#endif

	#ifndef GEODE_STATICS_onBackupAccountCompleted
		#define GEODE_STATICS_onBackupAccountCompleted
		GEODE_AS_STATIC_FUNCTION(onBackupAccountCompleted) 
	#endif

	#ifndef GEODE_STATICS_onGetAccountBackupURLCompleted
		#define GEODE_STATICS_onGetAccountBackupURLCompleted
		GEODE_AS_STATIC_FUNCTION(onGetAccountBackupURLCompleted) 
	#endif

	#ifndef GEODE_STATICS_onGetAccountSyncURLCompleted
		#define GEODE_STATICS_onGetAccountSyncURLCompleted
		GEODE_AS_STATIC_FUNCTION(onGetAccountSyncURLCompleted) 
	#endif

	#ifndef GEODE_STATICS_onLoginAccountCompleted
		#define GEODE_STATICS_onLoginAccountCompleted
		GEODE_AS_STATIC_FUNCTION(onLoginAccountCompleted) 
	#endif

	#ifndef GEODE_STATICS_onProcessHttpRequestCompleted
		#define GEODE_STATICS_onProcessHttpRequestCompleted
		GEODE_AS_STATIC_FUNCTION(onProcessHttpRequestCompleted) 
	#endif

	#ifndef GEODE_STATICS_onRegisterAccountCompleted
		#define GEODE_STATICS_onRegisterAccountCompleted
		GEODE_AS_STATIC_FUNCTION(onRegisterAccountCompleted) 
	#endif

	#ifndef GEODE_STATICS_onSyncAccountCompleted
		#define GEODE_STATICS_onSyncAccountCompleted
		GEODE_AS_STATIC_FUNCTION(onSyncAccountCompleted) 
	#endif

	#ifndef GEODE_STATICS_onUpdateAccountSettingsCompleted
		#define GEODE_STATICS_onUpdateAccountSettingsCompleted
		GEODE_AS_STATIC_FUNCTION(onUpdateAccountSettingsCompleted) 
	#endif

	#ifndef GEODE_STATICS_ProcessHttpRequest
		#define GEODE_STATICS_ProcessHttpRequest
		GEODE_AS_STATIC_FUNCTION(ProcessHttpRequest) 
	#endif

	#ifndef GEODE_STATICS_registerAccount
		#define GEODE_STATICS_registerAccount
		GEODE_AS_STATIC_FUNCTION(registerAccount) 
	#endif

	#ifndef GEODE_STATICS_removeDLFromActive
		#define GEODE_STATICS_removeDLFromActive
		GEODE_AS_STATIC_FUNCTION(removeDLFromActive) 
	#endif

	#ifndef GEODE_STATICS_syncAccount
		#define GEODE_STATICS_syncAccount
		GEODE_AS_STATIC_FUNCTION(syncAccount) 
	#endif

	#ifndef GEODE_STATICS_unlinkFromAccount
		#define GEODE_STATICS_unlinkFromAccount
		GEODE_AS_STATIC_FUNCTION(unlinkFromAccount) 
	#endif

	#ifndef GEODE_STATICS_updateAccountSettings
		#define GEODE_STATICS_updateAccountSettings
		GEODE_AS_STATIC_FUNCTION(updateAccountSettings) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_get
		#define GEODE_CONCEPT_CHECK_get
		GEODE_CONCEPT_FUNCTION_CHECK(get) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_sharedState
		#define GEODE_CONCEPT_CHECK_sharedState
		GEODE_CONCEPT_FUNCTION_CHECK(sharedState) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_init
		#define GEODE_CONCEPT_CHECK_init
		GEODE_CONCEPT_FUNCTION_CHECK(init) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_addDLToActive
		#define GEODE_CONCEPT_CHECK_addDLToActive
		GEODE_CONCEPT_FUNCTION_CHECK(addDLToActive) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_backupAccount
		#define GEODE_CONCEPT_CHECK_backupAccount
		GEODE_CONCEPT_FUNCTION_CHECK(backupAccount) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_dataLoaded
		#define GEODE_CONCEPT_CHECK_dataLoaded
		GEODE_CONCEPT_FUNCTION_CHECK(dataLoaded) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_encodeDataTo
		#define GEODE_CONCEPT_CHECK_encodeDataTo
		GEODE_CONCEPT_FUNCTION_CHECK(encodeDataTo) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_firstSetup
		#define GEODE_CONCEPT_CHECK_firstSetup
		GEODE_CONCEPT_FUNCTION_CHECK(firstSetup) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getAccountBackupURL
		#define GEODE_CONCEPT_CHECK_getAccountBackupURL
		GEODE_CONCEPT_FUNCTION_CHECK(getAccountBackupURL) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getAccountSyncURL
		#define GEODE_CONCEPT_CHECK_getAccountSyncURL
		GEODE_CONCEPT_FUNCTION_CHECK(getAccountSyncURL) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getDLObject
		#define GEODE_CONCEPT_CHECK_getDLObject
		GEODE_CONCEPT_FUNCTION_CHECK(getDLObject) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getShaPassword
		#define GEODE_CONCEPT_CHECK_getShaPassword
		GEODE_CONCEPT_FUNCTION_CHECK(getShaPassword) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_handleIt
		#define GEODE_CONCEPT_CHECK_handleIt
		GEODE_CONCEPT_FUNCTION_CHECK(handleIt) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_handleItDelayed
		#define GEODE_CONCEPT_CHECK_handleItDelayed
		GEODE_CONCEPT_FUNCTION_CHECK(handleItDelayed) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_handleItND
		#define GEODE_CONCEPT_CHECK_handleItND
		GEODE_CONCEPT_FUNCTION_CHECK(handleItND) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_isDLActive
		#define GEODE_CONCEPT_CHECK_isDLActive
		GEODE_CONCEPT_FUNCTION_CHECK(isDLActive) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_linkToAccount
		#define GEODE_CONCEPT_CHECK_linkToAccount
		GEODE_CONCEPT_FUNCTION_CHECK(linkToAccount) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_loginAccount
		#define GEODE_CONCEPT_CHECK_loginAccount
		GEODE_CONCEPT_FUNCTION_CHECK(loginAccount) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onBackupAccountCompleted
		#define GEODE_CONCEPT_CHECK_onBackupAccountCompleted
		GEODE_CONCEPT_FUNCTION_CHECK(onBackupAccountCompleted) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onGetAccountBackupURLCompleted
		#define GEODE_CONCEPT_CHECK_onGetAccountBackupURLCompleted
		GEODE_CONCEPT_FUNCTION_CHECK(onGetAccountBackupURLCompleted) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onGetAccountSyncURLCompleted
		#define GEODE_CONCEPT_CHECK_onGetAccountSyncURLCompleted
		GEODE_CONCEPT_FUNCTION_CHECK(onGetAccountSyncURLCompleted) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onLoginAccountCompleted
		#define GEODE_CONCEPT_CHECK_onLoginAccountCompleted
		GEODE_CONCEPT_FUNCTION_CHECK(onLoginAccountCompleted) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onProcessHttpRequestCompleted
		#define GEODE_CONCEPT_CHECK_onProcessHttpRequestCompleted
		GEODE_CONCEPT_FUNCTION_CHECK(onProcessHttpRequestCompleted) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onRegisterAccountCompleted
		#define GEODE_CONCEPT_CHECK_onRegisterAccountCompleted
		GEODE_CONCEPT_FUNCTION_CHECK(onRegisterAccountCompleted) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onSyncAccountCompleted
		#define GEODE_CONCEPT_CHECK_onSyncAccountCompleted
		GEODE_CONCEPT_FUNCTION_CHECK(onSyncAccountCompleted) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onUpdateAccountSettingsCompleted
		#define GEODE_CONCEPT_CHECK_onUpdateAccountSettingsCompleted
		GEODE_CONCEPT_FUNCTION_CHECK(onUpdateAccountSettingsCompleted) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_ProcessHttpRequest
		#define GEODE_CONCEPT_CHECK_ProcessHttpRequest
		GEODE_CONCEPT_FUNCTION_CHECK(ProcessHttpRequest) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_registerAccount
		#define GEODE_CONCEPT_CHECK_registerAccount
		GEODE_CONCEPT_FUNCTION_CHECK(registerAccount) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_removeDLFromActive
		#define GEODE_CONCEPT_CHECK_removeDLFromActive
		GEODE_CONCEPT_FUNCTION_CHECK(removeDLFromActive) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_syncAccount
		#define GEODE_CONCEPT_CHECK_syncAccount
		GEODE_CONCEPT_FUNCTION_CHECK(syncAccount) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_unlinkFromAccount
		#define GEODE_CONCEPT_CHECK_unlinkFromAccount
		GEODE_CONCEPT_FUNCTION_CHECK(unlinkFromAccount) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_updateAccountSettings
		#define GEODE_CONCEPT_CHECK_updateAccountSettings
		GEODE_CONCEPT_FUNCTION_CHECK(updateAccountSettings) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, GJAccountManager> : ModifyBase<ModifyDerive<Der, GJAccountManager>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, GJAccountManager>>;
		using ModifyBase<ModifyDerive<Der, GJAccountManager>>::ModifyBase;
		using Base = GJAccountManager;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_FUNCTION_ERROR_INLINE(GJAccountManager, get, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xcf140, Default, GJAccountManager, sharedState, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xd1bb0, Default, GJAccountManager, init, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xd1cf0, Default, GJAccountManager, addDLToActive, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xd1d20, Default, GJAccountManager, addDLToActive, char const*, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xd2d10, Default, GJAccountManager, backupAccount, gd::string)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xd3fa0, Default, GJAccountManager, dataLoaded, DS_Dictionary*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xd3f40, Default, GJAccountManager, encodeDataTo, DS_Dictionary*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xd3f30, Default, GJAccountManager, firstSetup, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xd29e0, Default, GJAccountManager, getAccountBackupURL, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xd3260, Default, GJAccountManager, getAccountSyncURL, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xd1c10, Default, GJAccountManager, getDLObject, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xd4160, Default, GJAccountManager, getShaPassword, gd::string)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xcf570, Default, GJAccountManager, handleIt, bool, gd::string, gd::string, GJHttpType)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xcfd80, Default, GJAccountManager, handleItDelayed, bool, gd::string, gd::string, GJHttpType)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xcfec0, Default, GJAccountManager, handleItND, cocos2d::CCNode*, void*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xd1bf0, Default, GJAccountManager, isDLActive, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xd3850, Default, GJAccountManager, linkToAccount, gd::string, gd::string, int, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xd21a0, Default, GJAccountManager, loginAccount, gd::string, gd::string)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xd0440, Default, GJAccountManager, onBackupAccountCompleted, gd::string, gd::string)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xd16c0, Default, GJAccountManager, onGetAccountBackupURLCompleted, gd::string, gd::string)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xd18d0, Default, GJAccountManager, onGetAccountSyncURLCompleted, gd::string, gd::string)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xd00a0, Default, GJAccountManager, onLoginAccountCompleted, gd::string, gd::string)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xcf3b0, Default, GJAccountManager, onProcessHttpRequestCompleted, cocos2d::extension::CCHttpClient*, cocos2d::extension::CCHttpResponse*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xcffe0, Default, GJAccountManager, onRegisterAccountCompleted, gd::string, gd::string)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xd0710, Default, GJAccountManager, onSyncAccountCompleted, gd::string, gd::string)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xd1620, Default, GJAccountManager, onUpdateAccountSettingsCompleted, gd::string, gd::string)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xcf210, Default, GJAccountManager, ProcessHttpRequest, gd::string, gd::string, gd::string, GJHttpType)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xd1ef0, Default, GJAccountManager, registerAccount, gd::string, gd::string, gd::string)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xd1e10, Default, GJAccountManager, removeDLFromActive, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xd35a0, Default, GJAccountManager, syncAccount, gd::string)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xd3980, Default, GJAccountManager, unlinkFromAccount, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0xd3a30, Default, GJAccountManager, updateAccountSettings, int, int, int, gd::string, gd::string, gd::string, gd::string, gd::string, gd::string, gd::string)
		}
	};
}
