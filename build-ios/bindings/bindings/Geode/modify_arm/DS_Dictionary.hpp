#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <cocos2d.h>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_copyFile
		#define GEODE_STATICS_copyFile
		GEODE_AS_STATIC_FUNCTION(copyFile) 
	#endif

	#ifndef GEODE_STATICS_addBoolValuesToMapForKey
		#define GEODE_STATICS_addBoolValuesToMapForKey
		GEODE_AS_STATIC_FUNCTION(addBoolValuesToMapForKey) 
	#endif

	#ifndef GEODE_STATICS_addBoolValuesToMapForKeySpecial
		#define GEODE_STATICS_addBoolValuesToMapForKeySpecial
		GEODE_AS_STATIC_FUNCTION(addBoolValuesToMapForKeySpecial) 
	#endif

	#ifndef GEODE_STATICS_checkCompatibility
		#define GEODE_STATICS_checkCompatibility
		GEODE_AS_STATIC_FUNCTION(checkCompatibility) 
	#endif

	#ifndef GEODE_STATICS_cleanStringWhiteSpace
		#define GEODE_STATICS_cleanStringWhiteSpace
		GEODE_AS_STATIC_FUNCTION(cleanStringWhiteSpace) 
	#endif

	#ifndef GEODE_STATICS_decodeObjectForKey
		#define GEODE_STATICS_decodeObjectForKey
		GEODE_AS_STATIC_FUNCTION(decodeObjectForKey) 
	#endif

	#ifndef GEODE_STATICS_getAllKeys
		#define GEODE_STATICS_getAllKeys
		GEODE_AS_STATIC_FUNCTION(getAllKeys) 
	#endif

	#ifndef GEODE_STATICS_getArrayForKey
		#define GEODE_STATICS_getArrayForKey
		GEODE_AS_STATIC_FUNCTION(getArrayForKey) 
	#endif

	#ifndef GEODE_STATICS_getBoolForKey
		#define GEODE_STATICS_getBoolForKey
		GEODE_AS_STATIC_FUNCTION(getBoolForKey) 
	#endif

	#ifndef GEODE_STATICS_getDictForKey
		#define GEODE_STATICS_getDictForKey
		GEODE_AS_STATIC_FUNCTION(getDictForKey) 
	#endif

	#ifndef GEODE_STATICS_getFloatForKey
		#define GEODE_STATICS_getFloatForKey
		GEODE_AS_STATIC_FUNCTION(getFloatForKey) 
	#endif

	#ifndef GEODE_STATICS_getIndexOfKey
		#define GEODE_STATICS_getIndexOfKey
		GEODE_AS_STATIC_FUNCTION(getIndexOfKey) 
	#endif

	#ifndef GEODE_STATICS_getIndexOfKeyWithClosestAlphaNumericalMatch
		#define GEODE_STATICS_getIndexOfKeyWithClosestAlphaNumericalMatch
		GEODE_AS_STATIC_FUNCTION(getIndexOfKeyWithClosestAlphaNumericalMatch) 
	#endif

	#ifndef GEODE_STATICS_getIntegerForKey
		#define GEODE_STATICS_getIntegerForKey
		GEODE_AS_STATIC_FUNCTION(getIntegerForKey) 
	#endif

	#ifndef GEODE_STATICS_getKey
		#define GEODE_STATICS_getKey
		GEODE_AS_STATIC_FUNCTION(getKey) 
	#endif

	#ifndef GEODE_STATICS_getNumKeys
		#define GEODE_STATICS_getNumKeys
		GEODE_AS_STATIC_FUNCTION(getNumKeys) 
	#endif

	#ifndef GEODE_STATICS_getObjectForKey
		#define GEODE_STATICS_getObjectForKey
		GEODE_AS_STATIC_FUNCTION(getObjectForKey) 
	#endif

	#ifndef GEODE_STATICS_getRectArrayForKey
		#define GEODE_STATICS_getRectArrayForKey
		GEODE_AS_STATIC_FUNCTION(getRectArrayForKey) 
	#endif

	#ifndef GEODE_STATICS_getRectForKey
		#define GEODE_STATICS_getRectForKey
		GEODE_AS_STATIC_FUNCTION(getRectForKey) 
	#endif

	#ifndef GEODE_STATICS_getStringArrayForKey
		#define GEODE_STATICS_getStringArrayForKey
		GEODE_AS_STATIC_FUNCTION(getStringArrayForKey) 
	#endif

	#ifndef GEODE_STATICS_getStringForKey
		#define GEODE_STATICS_getStringForKey
		GEODE_AS_STATIC_FUNCTION(getStringForKey) 
	#endif

	#ifndef GEODE_STATICS_getVec2ArrayForKey
		#define GEODE_STATICS_getVec2ArrayForKey
		GEODE_AS_STATIC_FUNCTION(getVec2ArrayForKey) 
	#endif

	#ifndef GEODE_STATICS_getVec2ForKey
		#define GEODE_STATICS_getVec2ForKey
		GEODE_AS_STATIC_FUNCTION(getVec2ForKey) 
	#endif

	#ifndef GEODE_STATICS_loadRootSubDictFromCompressedFile
		#define GEODE_STATICS_loadRootSubDictFromCompressedFile
		GEODE_AS_STATIC_FUNCTION(loadRootSubDictFromCompressedFile) 
	#endif

	#ifndef GEODE_STATICS_loadRootSubDictFromFile
		#define GEODE_STATICS_loadRootSubDictFromFile
		GEODE_AS_STATIC_FUNCTION(loadRootSubDictFromFile) 
	#endif

	#ifndef GEODE_STATICS_loadRootSubDictFromString
		#define GEODE_STATICS_loadRootSubDictFromString
		GEODE_AS_STATIC_FUNCTION(loadRootSubDictFromString) 
	#endif

	#ifndef GEODE_STATICS_rectFromString
		#define GEODE_STATICS_rectFromString
		GEODE_AS_STATIC_FUNCTION(rectFromString) 
	#endif

	#ifndef GEODE_STATICS_removeAllKeys
		#define GEODE_STATICS_removeAllKeys
		GEODE_AS_STATIC_FUNCTION(removeAllKeys) 
	#endif

	#ifndef GEODE_STATICS_removeKey
		#define GEODE_STATICS_removeKey
		GEODE_AS_STATIC_FUNCTION(removeKey) 
	#endif

	#ifndef GEODE_STATICS_saveRootSubDictToCompressedFile
		#define GEODE_STATICS_saveRootSubDictToCompressedFile
		GEODE_AS_STATIC_FUNCTION(saveRootSubDictToCompressedFile) 
	#endif

	#ifndef GEODE_STATICS_saveRootSubDictToFile
		#define GEODE_STATICS_saveRootSubDictToFile
		GEODE_AS_STATIC_FUNCTION(saveRootSubDictToFile) 
	#endif

	#ifndef GEODE_STATICS_saveRootSubDictToString
		#define GEODE_STATICS_saveRootSubDictToString
		GEODE_AS_STATIC_FUNCTION(saveRootSubDictToString) 
	#endif

	#ifndef GEODE_STATICS_setArrayForKey
		#define GEODE_STATICS_setArrayForKey
		GEODE_AS_STATIC_FUNCTION(setArrayForKey) 
	#endif

	#ifndef GEODE_STATICS_setBoolForKey
		#define GEODE_STATICS_setBoolForKey
		GEODE_AS_STATIC_FUNCTION(setBoolForKey) 
	#endif

	#ifndef GEODE_STATICS_setBoolMapForKey
		#define GEODE_STATICS_setBoolMapForKey
		GEODE_AS_STATIC_FUNCTION(setBoolMapForKey) 
	#endif

	#ifndef GEODE_STATICS_setDictForKey
		#define GEODE_STATICS_setDictForKey
		GEODE_AS_STATIC_FUNCTION(setDictForKey) 
	#endif

	#ifndef GEODE_STATICS_setFloatForKey
		#define GEODE_STATICS_setFloatForKey
		GEODE_AS_STATIC_FUNCTION(setFloatForKey) 
	#endif

	#ifndef GEODE_STATICS_setIntegerForKey
		#define GEODE_STATICS_setIntegerForKey
		GEODE_AS_STATIC_FUNCTION(setIntegerForKey) 
	#endif

	#ifndef GEODE_STATICS_setObjectForKey
		#define GEODE_STATICS_setObjectForKey
		GEODE_AS_STATIC_FUNCTION(setObjectForKey) 
	#endif

	#ifndef GEODE_STATICS_setRectArrayForKey
		#define GEODE_STATICS_setRectArrayForKey
		GEODE_AS_STATIC_FUNCTION(setRectArrayForKey) 
	#endif

	#ifndef GEODE_STATICS_setRectForKey
		#define GEODE_STATICS_setRectForKey
		GEODE_AS_STATIC_FUNCTION(setRectForKey) 
	#endif

	#ifndef GEODE_STATICS_setStringArrayForKey
		#define GEODE_STATICS_setStringArrayForKey
		GEODE_AS_STATIC_FUNCTION(setStringArrayForKey) 
	#endif

	#ifndef GEODE_STATICS_setStringForKey
		#define GEODE_STATICS_setStringForKey
		GEODE_AS_STATIC_FUNCTION(setStringForKey) 
	#endif

	#ifndef GEODE_STATICS_setSubDictForKey
		#define GEODE_STATICS_setSubDictForKey
		GEODE_AS_STATIC_FUNCTION(setSubDictForKey) 
	#endif

	#ifndef GEODE_STATICS_setVec2ArrayForKey
		#define GEODE_STATICS_setVec2ArrayForKey
		GEODE_AS_STATIC_FUNCTION(setVec2ArrayForKey) 
	#endif

	#ifndef GEODE_STATICS_setVec2ForKey
		#define GEODE_STATICS_setVec2ForKey
		GEODE_AS_STATIC_FUNCTION(setVec2ForKey) 
	#endif

	#ifndef GEODE_STATICS_split
		#define GEODE_STATICS_split
		GEODE_AS_STATIC_FUNCTION(split) 
	#endif

	#ifndef GEODE_STATICS_splitWithForm
		#define GEODE_STATICS_splitWithForm
		GEODE_AS_STATIC_FUNCTION(splitWithForm) 
	#endif

	#ifndef GEODE_STATICS_stepBackToRootSubDict
		#define GEODE_STATICS_stepBackToRootSubDict
		GEODE_AS_STATIC_FUNCTION(stepBackToRootSubDict) 
	#endif

	#ifndef GEODE_STATICS_stepIntoSubDictWithKey
		#define GEODE_STATICS_stepIntoSubDictWithKey
		GEODE_AS_STATIC_FUNCTION(stepIntoSubDictWithKey) 
	#endif

	#ifndef GEODE_STATICS_stepOutOfSubDict
		#define GEODE_STATICS_stepOutOfSubDict
		GEODE_AS_STATIC_FUNCTION(stepOutOfSubDict) 
	#endif

	#ifndef GEODE_STATICS_vec2FromString
		#define GEODE_STATICS_vec2FromString
		GEODE_AS_STATIC_FUNCTION(vec2FromString) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_copyFile
		#define GEODE_CONCEPT_CHECK_copyFile
		GEODE_CONCEPT_FUNCTION_CHECK(copyFile) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_addBoolValuesToMapForKey
		#define GEODE_CONCEPT_CHECK_addBoolValuesToMapForKey
		GEODE_CONCEPT_FUNCTION_CHECK(addBoolValuesToMapForKey) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_addBoolValuesToMapForKeySpecial
		#define GEODE_CONCEPT_CHECK_addBoolValuesToMapForKeySpecial
		GEODE_CONCEPT_FUNCTION_CHECK(addBoolValuesToMapForKeySpecial) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_checkCompatibility
		#define GEODE_CONCEPT_CHECK_checkCompatibility
		GEODE_CONCEPT_FUNCTION_CHECK(checkCompatibility) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_cleanStringWhiteSpace
		#define GEODE_CONCEPT_CHECK_cleanStringWhiteSpace
		GEODE_CONCEPT_FUNCTION_CHECK(cleanStringWhiteSpace) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_decodeObjectForKey
		#define GEODE_CONCEPT_CHECK_decodeObjectForKey
		GEODE_CONCEPT_FUNCTION_CHECK(decodeObjectForKey) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getAllKeys
		#define GEODE_CONCEPT_CHECK_getAllKeys
		GEODE_CONCEPT_FUNCTION_CHECK(getAllKeys) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getArrayForKey
		#define GEODE_CONCEPT_CHECK_getArrayForKey
		GEODE_CONCEPT_FUNCTION_CHECK(getArrayForKey) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getBoolForKey
		#define GEODE_CONCEPT_CHECK_getBoolForKey
		GEODE_CONCEPT_FUNCTION_CHECK(getBoolForKey) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getDictForKey
		#define GEODE_CONCEPT_CHECK_getDictForKey
		GEODE_CONCEPT_FUNCTION_CHECK(getDictForKey) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getFloatForKey
		#define GEODE_CONCEPT_CHECK_getFloatForKey
		GEODE_CONCEPT_FUNCTION_CHECK(getFloatForKey) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getIndexOfKey
		#define GEODE_CONCEPT_CHECK_getIndexOfKey
		GEODE_CONCEPT_FUNCTION_CHECK(getIndexOfKey) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getIndexOfKeyWithClosestAlphaNumericalMatch
		#define GEODE_CONCEPT_CHECK_getIndexOfKeyWithClosestAlphaNumericalMatch
		GEODE_CONCEPT_FUNCTION_CHECK(getIndexOfKeyWithClosestAlphaNumericalMatch) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getIntegerForKey
		#define GEODE_CONCEPT_CHECK_getIntegerForKey
		GEODE_CONCEPT_FUNCTION_CHECK(getIntegerForKey) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getKey
		#define GEODE_CONCEPT_CHECK_getKey
		GEODE_CONCEPT_FUNCTION_CHECK(getKey) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getNumKeys
		#define GEODE_CONCEPT_CHECK_getNumKeys
		GEODE_CONCEPT_FUNCTION_CHECK(getNumKeys) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getObjectForKey
		#define GEODE_CONCEPT_CHECK_getObjectForKey
		GEODE_CONCEPT_FUNCTION_CHECK(getObjectForKey) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getRectArrayForKey
		#define GEODE_CONCEPT_CHECK_getRectArrayForKey
		GEODE_CONCEPT_FUNCTION_CHECK(getRectArrayForKey) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getRectForKey
		#define GEODE_CONCEPT_CHECK_getRectForKey
		GEODE_CONCEPT_FUNCTION_CHECK(getRectForKey) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getStringArrayForKey
		#define GEODE_CONCEPT_CHECK_getStringArrayForKey
		GEODE_CONCEPT_FUNCTION_CHECK(getStringArrayForKey) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getStringForKey
		#define GEODE_CONCEPT_CHECK_getStringForKey
		GEODE_CONCEPT_FUNCTION_CHECK(getStringForKey) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getVec2ArrayForKey
		#define GEODE_CONCEPT_CHECK_getVec2ArrayForKey
		GEODE_CONCEPT_FUNCTION_CHECK(getVec2ArrayForKey) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getVec2ForKey
		#define GEODE_CONCEPT_CHECK_getVec2ForKey
		GEODE_CONCEPT_FUNCTION_CHECK(getVec2ForKey) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_loadRootSubDictFromCompressedFile
		#define GEODE_CONCEPT_CHECK_loadRootSubDictFromCompressedFile
		GEODE_CONCEPT_FUNCTION_CHECK(loadRootSubDictFromCompressedFile) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_loadRootSubDictFromFile
		#define GEODE_CONCEPT_CHECK_loadRootSubDictFromFile
		GEODE_CONCEPT_FUNCTION_CHECK(loadRootSubDictFromFile) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_loadRootSubDictFromString
		#define GEODE_CONCEPT_CHECK_loadRootSubDictFromString
		GEODE_CONCEPT_FUNCTION_CHECK(loadRootSubDictFromString) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_rectFromString
		#define GEODE_CONCEPT_CHECK_rectFromString
		GEODE_CONCEPT_FUNCTION_CHECK(rectFromString) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_removeAllKeys
		#define GEODE_CONCEPT_CHECK_removeAllKeys
		GEODE_CONCEPT_FUNCTION_CHECK(removeAllKeys) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_removeKey
		#define GEODE_CONCEPT_CHECK_removeKey
		GEODE_CONCEPT_FUNCTION_CHECK(removeKey) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_saveRootSubDictToCompressedFile
		#define GEODE_CONCEPT_CHECK_saveRootSubDictToCompressedFile
		GEODE_CONCEPT_FUNCTION_CHECK(saveRootSubDictToCompressedFile) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_saveRootSubDictToFile
		#define GEODE_CONCEPT_CHECK_saveRootSubDictToFile
		GEODE_CONCEPT_FUNCTION_CHECK(saveRootSubDictToFile) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_saveRootSubDictToString
		#define GEODE_CONCEPT_CHECK_saveRootSubDictToString
		GEODE_CONCEPT_FUNCTION_CHECK(saveRootSubDictToString) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setArrayForKey
		#define GEODE_CONCEPT_CHECK_setArrayForKey
		GEODE_CONCEPT_FUNCTION_CHECK(setArrayForKey) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setBoolForKey
		#define GEODE_CONCEPT_CHECK_setBoolForKey
		GEODE_CONCEPT_FUNCTION_CHECK(setBoolForKey) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setBoolMapForKey
		#define GEODE_CONCEPT_CHECK_setBoolMapForKey
		GEODE_CONCEPT_FUNCTION_CHECK(setBoolMapForKey) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setDictForKey
		#define GEODE_CONCEPT_CHECK_setDictForKey
		GEODE_CONCEPT_FUNCTION_CHECK(setDictForKey) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setFloatForKey
		#define GEODE_CONCEPT_CHECK_setFloatForKey
		GEODE_CONCEPT_FUNCTION_CHECK(setFloatForKey) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setIntegerForKey
		#define GEODE_CONCEPT_CHECK_setIntegerForKey
		GEODE_CONCEPT_FUNCTION_CHECK(setIntegerForKey) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setObjectForKey
		#define GEODE_CONCEPT_CHECK_setObjectForKey
		GEODE_CONCEPT_FUNCTION_CHECK(setObjectForKey) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setRectArrayForKey
		#define GEODE_CONCEPT_CHECK_setRectArrayForKey
		GEODE_CONCEPT_FUNCTION_CHECK(setRectArrayForKey) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setRectForKey
		#define GEODE_CONCEPT_CHECK_setRectForKey
		GEODE_CONCEPT_FUNCTION_CHECK(setRectForKey) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setStringArrayForKey
		#define GEODE_CONCEPT_CHECK_setStringArrayForKey
		GEODE_CONCEPT_FUNCTION_CHECK(setStringArrayForKey) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setStringForKey
		#define GEODE_CONCEPT_CHECK_setStringForKey
		GEODE_CONCEPT_FUNCTION_CHECK(setStringForKey) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setSubDictForKey
		#define GEODE_CONCEPT_CHECK_setSubDictForKey
		GEODE_CONCEPT_FUNCTION_CHECK(setSubDictForKey) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setVec2ArrayForKey
		#define GEODE_CONCEPT_CHECK_setVec2ArrayForKey
		GEODE_CONCEPT_FUNCTION_CHECK(setVec2ArrayForKey) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setVec2ForKey
		#define GEODE_CONCEPT_CHECK_setVec2ForKey
		GEODE_CONCEPT_FUNCTION_CHECK(setVec2ForKey) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_split
		#define GEODE_CONCEPT_CHECK_split
		GEODE_CONCEPT_FUNCTION_CHECK(split) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_splitWithForm
		#define GEODE_CONCEPT_CHECK_splitWithForm
		GEODE_CONCEPT_FUNCTION_CHECK(splitWithForm) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_stepBackToRootSubDict
		#define GEODE_CONCEPT_CHECK_stepBackToRootSubDict
		GEODE_CONCEPT_FUNCTION_CHECK(stepBackToRootSubDict) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_stepIntoSubDictWithKey
		#define GEODE_CONCEPT_CHECK_stepIntoSubDictWithKey
		GEODE_CONCEPT_FUNCTION_CHECK(stepIntoSubDictWithKey) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_stepOutOfSubDict
		#define GEODE_CONCEPT_CHECK_stepOutOfSubDict
		GEODE_CONCEPT_FUNCTION_CHECK(stepOutOfSubDict) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_vec2FromString
		#define GEODE_CONCEPT_CHECK_vec2FromString
		GEODE_CONCEPT_FUNCTION_CHECK(vec2FromString) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, DS_Dictionary> : ModifyBase<ModifyDerive<Der, DS_Dictionary>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, DS_Dictionary>>;
		using ModifyBase<ModifyDerive<Der, DS_Dictionary>>::ModifyBase;
		using Base = DS_Dictionary;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0x13f8f8, Default, DS_Dictionary, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1422d0, Default, DS_Dictionary, copyFile, char const*, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1469f0, Default, DS_Dictionary, addBoolValuesToMapForKey, gd::map<gd::string, bool>&, char const*, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1466c8, Default, DS_Dictionary, addBoolValuesToMapForKeySpecial, gd::map<gd::string, bool>&, char const*, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x140980, Default, DS_Dictionary, checkCompatibility, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x13fab4, Default, DS_Dictionary, cleanStringWhiteSpace, gd::string const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x147004, Default, DS_Dictionary, decodeObjectForKey, char const*, bool, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x142bc4, Default, DS_Dictionary, getAllKeys, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x145dfc, Default, DS_Dictionary, getArrayForKey, char const*, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x143204, Default, DS_Dictionary, getBoolForKey, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x146b94, Default, DS_Dictionary, getDictForKey, char const*, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1432fc, Default, DS_Dictionary, getFloatForKey, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x142d20, Default, DS_Dictionary, getIndexOfKey, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x142dd8, Default, DS_Dictionary, getIndexOfKeyWithClosestAlphaNumericalMatch, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1430f8, Default, DS_Dictionary, getIntegerForKey, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x142aa8, Default, DS_Dictionary, getKey, unsigned int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x142a3c, Default, DS_Dictionary, getNumKeys, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x145f64, Default, DS_Dictionary, getObjectForKey, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x143c5c, Default, DS_Dictionary, getRectArrayForKey, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1436d8, Default, DS_Dictionary, getRectForKey, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1438cc, Default, DS_Dictionary, getStringArrayForKey, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x14341c, Default, DS_Dictionary, getStringForKey, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x143aec, Default, DS_Dictionary, getVec2ArrayForKey, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1435a4, Default, DS_Dictionary, getVec2ForKey, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x140cec, Default, DS_Dictionary, loadRootSubDictFromCompressedFile, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1409e0, Default, DS_Dictionary, loadRootSubDictFromFile, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x141010, Default, DS_Dictionary, loadRootSubDictFromString, gd::string const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x140298, Default, DS_Dictionary, rectFromString, gd::string const&, cocos2d::CCRect&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x143054, Default, DS_Dictionary, removeAllKeys, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x142f70, Default, DS_Dictionary, removeKey, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x142e94, Default, DS_Dictionary, removeKey, unsigned int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x141b80, Default, DS_Dictionary, saveRootSubDictToCompressedFile, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1411e0, Default, DS_Dictionary, saveRootSubDictToFile, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x142258, Default, DS_Dictionary, saveRootSubDictToString, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x145a8c, Default, DS_Dictionary, setArrayForKey, char const*, cocos2d::CCArray*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1442d8, Default, DS_Dictionary, setBoolForKey, char const*, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x144380, Default, DS_Dictionary, setBoolForKey, char const*, bool, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1464a0, Default, DS_Dictionary, setBoolMapForKey, char const*, gd::map<gd::string, bool>&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1462ac, Default, DS_Dictionary, setDictForKey, char const*, cocos2d::CCDictionary*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1444c0, Default, DS_Dictionary, setFloatForKey, char const*, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1444c8, Default, DS_Dictionary, setFloatForKey, char const*, float, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x14406c, Default, DS_Dictionary, setIntegerForKey, char const*, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x144074, Default, DS_Dictionary, setIntegerForKey, char const*, int, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x145bc8, Default, DS_Dictionary, setObjectForKey, char const*, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1456f4, Default, DS_Dictionary, setRectArrayForKey, char const*, gd::vector<cocos2d::CCRect> const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1456fc, Default, DS_Dictionary, setRectArrayForKey, char const*, gd::vector<cocos2d::CCRect> const&, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x144e18, Default, DS_Dictionary, setRectForKey, char const*, cocos2d::CCRect const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x144e20, Default, DS_Dictionary, setRectForKey, char const*, cocos2d::CCRect const&, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1451b4, Default, DS_Dictionary, setStringArrayForKey, char const*, gd::vector<gd::string> const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1451bc, Default, DS_Dictionary, setStringArrayForKey, char const*, gd::vector<gd::string> const&, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x144744, Default, DS_Dictionary, setStringForKey, char const*, gd::string const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x14474c, Default, DS_Dictionary, setStringForKey, char const*, gd::string const&, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x143dcc, Default, DS_Dictionary, setSubDictForKey, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x143e70, Default, DS_Dictionary, setSubDictForKey, char const*, bool, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1453ac, Default, DS_Dictionary, setVec2ArrayForKey, char const*, gd::vector<cocos2d::CCPoint> const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1453b4, Default, DS_Dictionary, setVec2ArrayForKey, char const*, gd::vector<cocos2d::CCPoint> const&, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1448d0, Default, DS_Dictionary, setVec2ForKey, char const*, cocos2d::CCPoint const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1448d8, Default, DS_Dictionary, setVec2ForKey, char const*, cocos2d::CCPoint const&, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x13fc24, Default, DS_Dictionary, split, gd::string const&, char const*, gd::vector<gd::string>&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x14002c, Default, DS_Dictionary, splitWithForm, gd::string const&, gd::vector<gd::string>&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x142910, Default, DS_Dictionary, stepBackToRootSubDict, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x14274c, Default, DS_Dictionary, stepIntoSubDictWithKey, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1428f4, Default, DS_Dictionary, stepOutOfSubDict, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x140824, Default, DS_Dictionary, vec2FromString, gd::string const&, cocos2d::CCPoint&)
		}
	};
}
