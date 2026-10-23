#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <cocos2d.h>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_getHeight
		#define GEODE_STATICS_getHeight
		GEODE_AS_STATIC_FUNCTION(getHeight) 
	#endif

	#ifndef GEODE_STATICS_getName
		#define GEODE_STATICS_getName
		GEODE_AS_STATIC_FUNCTION(getName) 
	#endif

	#ifndef GEODE_STATICS_getWidth
		#define GEODE_STATICS_getWidth
		GEODE_AS_STATIC_FUNCTION(getWidth) 
	#endif

	#ifndef GEODE_STATICS_initWithFile
		#define GEODE_STATICS_initWithFile
		GEODE_AS_STATIC_FUNCTION(initWithFile) 
	#endif

	#ifndef GEODE_STATICS_loadTexture
		#define GEODE_STATICS_loadTexture
		GEODE_AS_STATIC_FUNCTION(loadTexture) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_getHeight
		#define GEODE_CONCEPT_CHECK_getHeight
		GEODE_CONCEPT_FUNCTION_CHECK(getHeight) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getName
		#define GEODE_CONCEPT_CHECK_getName
		GEODE_CONCEPT_FUNCTION_CHECK(getName) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getWidth
		#define GEODE_CONCEPT_CHECK_getWidth
		GEODE_CONCEPT_FUNCTION_CHECK(getWidth) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_initWithFile
		#define GEODE_CONCEPT_CHECK_initWithFile
		GEODE_CONCEPT_FUNCTION_CHECK(initWithFile) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_loadTexture
		#define GEODE_CONCEPT_CHECK_loadTexture
		GEODE_CONCEPT_FUNCTION_CHECK(loadTexture) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCTextureETC> : ModifyBase<ModifyDerive<Der, cocos2d::CCTextureETC>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCTextureETC>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCTextureETC>>::ModifyBase;
		using Base = cocos2d::CCTextureETC;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0x1b5cdc, Default, cocos2d::CCTextureETC, )
			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0x1b5d04, Default, cocos2d::CCTextureETC)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1b5d38, Default, cocos2d::CCTextureETC, getHeight, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1b5d28, Default, cocos2d::CCTextureETC, getName, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1b5d30, Default, cocos2d::CCTextureETC, getWidth, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1b5d20, Default, cocos2d::CCTextureETC, initWithFile, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1b5d40, Default, cocos2d::CCTextureETC, loadTexture, char const*)
		}
	};
}
