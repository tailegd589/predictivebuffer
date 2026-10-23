#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <cocos2d.h>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_base64DecodeEnc
		#define GEODE_STATICS_base64DecodeEnc
		GEODE_AS_STATIC_FUNCTION(base64DecodeEnc) 
	#endif

	#ifndef GEODE_STATICS_base64EncodeEnc
		#define GEODE_STATICS_base64EncodeEnc
		GEODE_AS_STATIC_FUNCTION(base64EncodeEnc) 
	#endif

	#ifndef GEODE_STATICS_base64URLDecode
		#define GEODE_STATICS_base64URLDecode
		GEODE_AS_STATIC_FUNCTION(base64URLDecode) 
	#endif

	#ifndef GEODE_STATICS_base64URLEncode
		#define GEODE_STATICS_base64URLEncode
		GEODE_AS_STATIC_FUNCTION(base64URLEncode) 
	#endif

	#ifndef GEODE_STATICS_ccDeflateMemory
		#define GEODE_STATICS_ccDeflateMemory
		GEODE_AS_STATIC_FUNCTION(ccDeflateMemory) 
	#endif

	#ifndef GEODE_STATICS_compressString
		#define GEODE_STATICS_compressString
		GEODE_AS_STATIC_FUNCTION(compressString) 
	#endif

	#ifndef GEODE_STATICS_decompressString
		#define GEODE_STATICS_decompressString
		GEODE_AS_STATIC_FUNCTION(decompressString) 
	#endif

	#ifndef GEODE_STATICS_decompressString2
		#define GEODE_STATICS_decompressString2
		GEODE_AS_STATIC_FUNCTION(decompressString2) 
	#endif

	#ifndef GEODE_STATICS_hexToChar
		#define GEODE_STATICS_hexToChar
		GEODE_AS_STATIC_FUNCTION(hexToChar) 
	#endif

	#ifndef GEODE_STATICS_urlDecode
		#define GEODE_STATICS_urlDecode
		GEODE_AS_STATIC_FUNCTION(urlDecode) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_base64DecodeEnc
		#define GEODE_CONCEPT_CHECK_base64DecodeEnc
		GEODE_CONCEPT_FUNCTION_CHECK(base64DecodeEnc) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_base64EncodeEnc
		#define GEODE_CONCEPT_CHECK_base64EncodeEnc
		GEODE_CONCEPT_FUNCTION_CHECK(base64EncodeEnc) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_base64URLDecode
		#define GEODE_CONCEPT_CHECK_base64URLDecode
		GEODE_CONCEPT_FUNCTION_CHECK(base64URLDecode) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_base64URLEncode
		#define GEODE_CONCEPT_CHECK_base64URLEncode
		GEODE_CONCEPT_FUNCTION_CHECK(base64URLEncode) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_ccDeflateMemory
		#define GEODE_CONCEPT_CHECK_ccDeflateMemory
		GEODE_CONCEPT_FUNCTION_CHECK(ccDeflateMemory) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_compressString
		#define GEODE_CONCEPT_CHECK_compressString
		GEODE_CONCEPT_FUNCTION_CHECK(compressString) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_decompressString
		#define GEODE_CONCEPT_CHECK_decompressString
		GEODE_CONCEPT_FUNCTION_CHECK(decompressString) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_decompressString2
		#define GEODE_CONCEPT_CHECK_decompressString2
		GEODE_CONCEPT_FUNCTION_CHECK(decompressString2) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_encryptDecrypt
		#define GEODE_CONCEPT_CHECK_encryptDecrypt
		GEODE_CONCEPT_FUNCTION_CHECK(encryptDecrypt) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_encryptDecryptWKey
		#define GEODE_CONCEPT_CHECK_encryptDecryptWKey
		GEODE_CONCEPT_FUNCTION_CHECK(encryptDecryptWKey) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_hexToChar
		#define GEODE_CONCEPT_CHECK_hexToChar
		GEODE_CONCEPT_FUNCTION_CHECK(hexToChar) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_urlDecode
		#define GEODE_CONCEPT_CHECK_urlDecode
		GEODE_CONCEPT_FUNCTION_CHECK(urlDecode) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::ZipUtils> : ModifyBase<ModifyDerive<Der, cocos2d::ZipUtils>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::ZipUtils>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::ZipUtils>>::ModifyBase;
		using Base = cocos2d::ZipUtils;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1b1a48, Default, cocos2d::ZipUtils, base64DecodeEnc, gd::string const&, gd::string)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1b1cbc, Default, cocos2d::ZipUtils, base64EncodeEnc, gd::string const&, gd::string)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1b1f2c, Default, cocos2d::ZipUtils, base64URLDecode, gd::string const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1b2038, Default, cocos2d::ZipUtils, base64URLEncode, gd::string const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1b136c, Default, cocos2d::ZipUtils, ccDeflateMemory, unsigned char*, unsigned int, unsigned char**)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1b10ac, Default, cocos2d::ZipUtils, compressString, gd::string const&, bool, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1b17c0, Default, cocos2d::ZipUtils, decompressString, gd::string const&, bool, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1b14a0, Default, cocos2d::ZipUtils, decompressString2, unsigned char*, bool, int, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION_ERROR_INLINE(cocos2d::ZipUtils, encryptDecrypt, gd::string const&, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION_ERROR_INLINE(cocos2d::ZipUtils, encryptDecryptWKey, gd::string const&, gd::string)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1b24b0, Default, cocos2d::ZipUtils, hexToChar, gd::string const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1b2144, Default, cocos2d::ZipUtils, urlDecode, gd::string const&)
		}
	};
}
