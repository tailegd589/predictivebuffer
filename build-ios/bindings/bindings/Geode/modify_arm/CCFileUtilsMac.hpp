#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <cocos2d.h>
#include <Geode/cocos/platform/mac/CCFileUtilsMac.h>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_getWritablePath
		#define GEODE_STATICS_getWritablePath
		GEODE_AS_STATIC_FUNCTION(getWritablePath) 
	#endif

	#ifndef GEODE_STATICS_isFileExist
		#define GEODE_STATICS_isFileExist
		GEODE_AS_STATIC_FUNCTION(isFileExist) 
	#endif

	#ifndef GEODE_STATICS_isAbsolutePath
		#define GEODE_STATICS_isAbsolutePath
		GEODE_AS_STATIC_FUNCTION(isAbsolutePath) 
	#endif

	#ifndef GEODE_STATICS_getFullPathForDirectoryAndFilename
		#define GEODE_STATICS_getFullPathForDirectoryAndFilename
		GEODE_AS_STATIC_FUNCTION(getFullPathForDirectoryAndFilename) 
	#endif

	#ifndef GEODE_STATICS_createCCDictionaryWithContentsOfFile
		#define GEODE_STATICS_createCCDictionaryWithContentsOfFile
		GEODE_AS_STATIC_FUNCTION(createCCDictionaryWithContentsOfFile) 
	#endif

	#ifndef GEODE_STATICS_writeToFile
		#define GEODE_STATICS_writeToFile
		GEODE_AS_STATIC_FUNCTION(writeToFile) 
	#endif

	#ifndef GEODE_STATICS_createCCArrayWithContentsOfFile
		#define GEODE_STATICS_createCCArrayWithContentsOfFile
		GEODE_AS_STATIC_FUNCTION(createCCArrayWithContentsOfFile) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_getWritablePath
		#define GEODE_CONCEPT_CHECK_getWritablePath
		GEODE_CONCEPT_FUNCTION_CHECK(getWritablePath) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_isFileExist
		#define GEODE_CONCEPT_CHECK_isFileExist
		GEODE_CONCEPT_FUNCTION_CHECK(isFileExist) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_isAbsolutePath
		#define GEODE_CONCEPT_CHECK_isAbsolutePath
		GEODE_CONCEPT_FUNCTION_CHECK(isAbsolutePath) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getFullPathForDirectoryAndFilename
		#define GEODE_CONCEPT_CHECK_getFullPathForDirectoryAndFilename
		GEODE_CONCEPT_FUNCTION_CHECK(getFullPathForDirectoryAndFilename) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_createCCDictionaryWithContentsOfFile
		#define GEODE_CONCEPT_CHECK_createCCDictionaryWithContentsOfFile
		GEODE_CONCEPT_FUNCTION_CHECK(createCCDictionaryWithContentsOfFile) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_writeToFile
		#define GEODE_CONCEPT_CHECK_writeToFile
		GEODE_CONCEPT_FUNCTION_CHECK(writeToFile) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_createCCArrayWithContentsOfFile
		#define GEODE_CONCEPT_CHECK_createCCArrayWithContentsOfFile
		GEODE_CONCEPT_FUNCTION_CHECK(createCCArrayWithContentsOfFile) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCFileUtilsMac> : ModifyBase<ModifyDerive<Der, cocos2d::CCFileUtilsMac>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCFileUtilsMac>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCFileUtilsMac>>::ModifyBase;
		using Base = cocos2d::CCFileUtilsMac;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x531bb4, Default, cocos2d::CCFileUtilsMac, getWritablePath, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x531c98, Default, cocos2d::CCFileUtilsMac, isFileExist, gd::string const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x532270, Default, cocos2d::CCFileUtilsMac, isAbsolutePath, gd::string const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x532014, Default, cocos2d::CCFileUtilsMac, getFullPathForDirectoryAndFilename, gd::string const&, gd::string const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x53229c, Default, cocos2d::CCFileUtilsMac, createCCDictionaryWithContentsOfFile, gd::string const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x532b8c, Default, cocos2d::CCFileUtilsMac, writeToFile, cocos2d::CCDictionary*, gd::string const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x532d7c, Default, cocos2d::CCFileUtilsMac, createCCArrayWithContentsOfFile, gd::string const&)
		}
	};
}
