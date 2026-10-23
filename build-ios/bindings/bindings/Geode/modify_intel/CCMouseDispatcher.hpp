#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <cocos2d.h>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_addDelegate
		#define GEODE_STATICS_addDelegate
		GEODE_AS_STATIC_FUNCTION(addDelegate) 
	#endif

	#ifndef GEODE_STATICS_dispatchScrollMSG
		#define GEODE_STATICS_dispatchScrollMSG
		GEODE_AS_STATIC_FUNCTION(dispatchScrollMSG) 
	#endif

	#ifndef GEODE_STATICS_forceAddDelegate
		#define GEODE_STATICS_forceAddDelegate
		GEODE_AS_STATIC_FUNCTION(forceAddDelegate) 
	#endif

	#ifndef GEODE_STATICS_forceRemoveDelegate
		#define GEODE_STATICS_forceRemoveDelegate
		GEODE_AS_STATIC_FUNCTION(forceRemoveDelegate) 
	#endif

	#ifndef GEODE_STATICS_removeDelegate
		#define GEODE_STATICS_removeDelegate
		GEODE_AS_STATIC_FUNCTION(removeDelegate) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_addDelegate
		#define GEODE_CONCEPT_CHECK_addDelegate
		GEODE_CONCEPT_FUNCTION_CHECK(addDelegate) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_dispatchScrollMSG
		#define GEODE_CONCEPT_CHECK_dispatchScrollMSG
		GEODE_CONCEPT_FUNCTION_CHECK(dispatchScrollMSG) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_forceAddDelegate
		#define GEODE_CONCEPT_CHECK_forceAddDelegate
		GEODE_CONCEPT_FUNCTION_CHECK(forceAddDelegate) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_forceRemoveDelegate
		#define GEODE_CONCEPT_CHECK_forceRemoveDelegate
		GEODE_CONCEPT_FUNCTION_CHECK(forceRemoveDelegate) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_removeDelegate
		#define GEODE_CONCEPT_CHECK_removeDelegate
		GEODE_CONCEPT_FUNCTION_CHECK(removeDelegate) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCMouseDispatcher> : ModifyBase<ModifyDerive<Der, cocos2d::CCMouseDispatcher>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCMouseDispatcher>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCMouseDispatcher>>::ModifyBase;
		using Base = cocos2d::CCMouseDispatcher;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0x570b50, Default, cocos2d::CCMouseDispatcher, )
			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0x570bc0, Default, cocos2d::CCMouseDispatcher)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x570e20, Default, cocos2d::CCMouseDispatcher, addDelegate, cocos2d::CCMouseDelegate*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x570ea0, Default, cocos2d::CCMouseDispatcher, dispatchScrollMSG, float, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x570e70, Default, cocos2d::CCMouseDispatcher, forceAddDelegate, cocos2d::CCMouseDelegate*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x570d90, Default, cocos2d::CCMouseDispatcher, forceRemoveDelegate, cocos2d::CCMouseDelegate*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x570ce0, Default, cocos2d::CCMouseDispatcher, removeDelegate, cocos2d::CCMouseDelegate*)
		}
	};
}
