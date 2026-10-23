#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <cocos2d.h>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_addObject
		#define GEODE_STATICS_addObject
		GEODE_AS_STATIC_FUNCTION(addObject) 
	#endif

	#ifndef GEODE_STATICS_clear
		#define GEODE_STATICS_clear
		GEODE_AS_STATIC_FUNCTION(clear) 
	#endif

	#ifndef GEODE_STATICS_removeObject
		#define GEODE_STATICS_removeObject
		GEODE_AS_STATIC_FUNCTION(removeObject) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_addObject
		#define GEODE_CONCEPT_CHECK_addObject
		GEODE_CONCEPT_FUNCTION_CHECK(addObject) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_clear
		#define GEODE_CONCEPT_CHECK_clear
		GEODE_CONCEPT_FUNCTION_CHECK(clear) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_removeObject
		#define GEODE_CONCEPT_CHECK_removeObject
		GEODE_CONCEPT_FUNCTION_CHECK(removeObject) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCAutoreleasePool> : ModifyBase<ModifyDerive<Der, cocos2d::CCAutoreleasePool>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCAutoreleasePool>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCAutoreleasePool>>::ModifyBase;
		using Base = cocos2d::CCAutoreleasePool;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0x3f6690, Default, cocos2d::CCAutoreleasePool, )
			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0x3f6710, Default, cocos2d::CCAutoreleasePool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3f67d0, Default, cocos2d::CCAutoreleasePool, addObject, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3f6850, Default, cocos2d::CCAutoreleasePool, clear, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3f6800, Default, cocos2d::CCAutoreleasePool, removeObject, cocos2d::CCObject*)
		}
	};
}
