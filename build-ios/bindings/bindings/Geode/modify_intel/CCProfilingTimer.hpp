#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <cocos2d.h>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_description
		#define GEODE_STATICS_description
		GEODE_AS_STATIC_FUNCTION(description) 
	#endif

	#ifndef GEODE_STATICS_initWithName
		#define GEODE_STATICS_initWithName
		GEODE_AS_STATIC_FUNCTION(initWithName) 
	#endif

	#ifndef GEODE_STATICS_reset
		#define GEODE_STATICS_reset
		GEODE_AS_STATIC_FUNCTION(reset) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_description
		#define GEODE_CONCEPT_CHECK_description
		GEODE_CONCEPT_FUNCTION_CHECK(description) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_initWithName
		#define GEODE_CONCEPT_CHECK_initWithName
		GEODE_CONCEPT_FUNCTION_CHECK(initWithName) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_reset
		#define GEODE_CONCEPT_CHECK_reset
		GEODE_CONCEPT_FUNCTION_CHECK(reset) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCProfilingTimer> : ModifyBase<ModifyDerive<Der, cocos2d::CCProfilingTimer>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCProfilingTimer>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCProfilingTimer>>::ModifyBase;
		using Base = cocos2d::CCProfilingTimer;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0x4ec4a0, Default, cocos2d::CCProfilingTimer, )
			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0x4ec4f0, Default, cocos2d::CCProfilingTimer)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4ec5b0, Default, cocos2d::CCProfilingTimer, description, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4ec2c0, Default, cocos2d::CCProfilingTimer, initWithName, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4ec620, Default, cocos2d::CCProfilingTimer, reset, )
		}
	};
}
