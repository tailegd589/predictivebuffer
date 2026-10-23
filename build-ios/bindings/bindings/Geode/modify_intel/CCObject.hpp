#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <cocos2d.h>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_createWithCoder
		#define GEODE_STATICS_createWithCoder
		GEODE_AS_STATIC_FUNCTION(createWithCoder) 
	#endif

	#ifndef GEODE_STATICS_getTag
		#define GEODE_STATICS_getTag
		GEODE_AS_STATIC_FUNCTION(getTag) 
	#endif

	#ifndef GEODE_STATICS_isEqual
		#define GEODE_STATICS_isEqual
		GEODE_AS_STATIC_FUNCTION(isEqual) 
	#endif

	#ifndef GEODE_STATICS_acceptVisitor
		#define GEODE_STATICS_acceptVisitor
		GEODE_AS_STATIC_FUNCTION(acceptVisitor) 
	#endif

	#ifndef GEODE_STATICS_encodeWithCoder
		#define GEODE_STATICS_encodeWithCoder
		GEODE_AS_STATIC_FUNCTION(encodeWithCoder) 
	#endif

	#ifndef GEODE_STATICS_canEncode
		#define GEODE_STATICS_canEncode
		GEODE_AS_STATIC_FUNCTION(canEncode) 
	#endif

	#ifndef GEODE_STATICS_setTag
		#define GEODE_STATICS_setTag
		GEODE_AS_STATIC_FUNCTION(setTag) 
	#endif

	#ifndef GEODE_STATICS_autorelease
		#define GEODE_STATICS_autorelease
		GEODE_AS_STATIC_FUNCTION(autorelease) 
	#endif

	#ifndef GEODE_STATICS_isSingleReference
		#define GEODE_STATICS_isSingleReference
		GEODE_AS_STATIC_FUNCTION(isSingleReference) 
	#endif

	#ifndef GEODE_STATICS_release
		#define GEODE_STATICS_release
		GEODE_AS_STATIC_FUNCTION(release) 
	#endif

	#ifndef GEODE_STATICS_retain
		#define GEODE_STATICS_retain
		GEODE_AS_STATIC_FUNCTION(retain) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_createWithCoder
		#define GEODE_CONCEPT_CHECK_createWithCoder
		GEODE_CONCEPT_FUNCTION_CHECK(createWithCoder) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getTag
		#define GEODE_CONCEPT_CHECK_getTag
		GEODE_CONCEPT_FUNCTION_CHECK(getTag) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_isEqual
		#define GEODE_CONCEPT_CHECK_isEqual
		GEODE_CONCEPT_FUNCTION_CHECK(isEqual) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_acceptVisitor
		#define GEODE_CONCEPT_CHECK_acceptVisitor
		GEODE_CONCEPT_FUNCTION_CHECK(acceptVisitor) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_encodeWithCoder
		#define GEODE_CONCEPT_CHECK_encodeWithCoder
		GEODE_CONCEPT_FUNCTION_CHECK(encodeWithCoder) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_canEncode
		#define GEODE_CONCEPT_CHECK_canEncode
		GEODE_CONCEPT_FUNCTION_CHECK(canEncode) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setTag
		#define GEODE_CONCEPT_CHECK_setTag
		GEODE_CONCEPT_FUNCTION_CHECK(setTag) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_autorelease
		#define GEODE_CONCEPT_CHECK_autorelease
		GEODE_CONCEPT_FUNCTION_CHECK(autorelease) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_isSingleReference
		#define GEODE_CONCEPT_CHECK_isSingleReference
		GEODE_CONCEPT_FUNCTION_CHECK(isSingleReference) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_release
		#define GEODE_CONCEPT_CHECK_release
		GEODE_CONCEPT_FUNCTION_CHECK(release) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_retain
		#define GEODE_CONCEPT_CHECK_retain
		GEODE_CONCEPT_FUNCTION_CHECK(retain) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCObject> : ModifyBase<ModifyDerive<Der, cocos2d::CCObject>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCObject>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCObject>>::ModifyBase;
		using Base = cocos2d::CCObject;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0x48a8a0, Default, cocos2d::CCObject, )
			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0x48a940, Default, cocos2d::CCObject)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x48ab90, Default, cocos2d::CCObject, createWithCoder, DS_Dictionary*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x48ab60, Default, cocos2d::CCObject, getTag, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x48ab30, Default, cocos2d::CCObject, isEqual, cocos2d::CCObject const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x48ab40, Default, cocos2d::CCObject, acceptVisitor, cocos2d::CCDataVisitor&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x48ab80, Default, cocos2d::CCObject, encodeWithCoder, DS_Dictionary*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x48aba0, Default, cocos2d::CCObject, canEncode, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x48ab70, Default, cocos2d::CCObject, setTag, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x48aae0, Default, cocos2d::CCObject, autorelease, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x48ab10, Default, cocos2d::CCObject, isSingleReference, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x48aab0, Default, cocos2d::CCObject, release, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x48aad0, Default, cocos2d::CCObject, retain, )
		}
	};
}
