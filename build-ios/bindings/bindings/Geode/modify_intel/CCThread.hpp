#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <cocos2d.h>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_createAutoreleasePool
		#define GEODE_STATICS_createAutoreleasePool
		GEODE_AS_STATIC_FUNCTION(createAutoreleasePool) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_createAutoreleasePool
		#define GEODE_CONCEPT_CHECK_createAutoreleasePool
		GEODE_CONCEPT_FUNCTION_CHECK(createAutoreleasePool) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCThread> : ModifyBase<ModifyDerive<Der, cocos2d::CCThread>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCThread>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCThread>>::ModifyBase;
		using Base = cocos2d::CCThread;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0x3d97c0, Default, cocos2d::CCThread)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3d97e0, Default, cocos2d::CCThread, createAutoreleasePool, )
		}
	};
}
