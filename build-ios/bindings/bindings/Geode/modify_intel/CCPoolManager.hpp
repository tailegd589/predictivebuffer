#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <cocos2d.h>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_purgePoolManager
		#define GEODE_STATICS_purgePoolManager
		GEODE_AS_STATIC_FUNCTION(purgePoolManager) 
	#endif

	#ifndef GEODE_STATICS_sharedPoolManager
		#define GEODE_STATICS_sharedPoolManager
		GEODE_AS_STATIC_FUNCTION(sharedPoolManager) 
	#endif

	#ifndef GEODE_STATICS_addObject
		#define GEODE_STATICS_addObject
		GEODE_AS_STATIC_FUNCTION(addObject) 
	#endif

	#ifndef GEODE_STATICS_finalize
		#define GEODE_STATICS_finalize
		GEODE_AS_STATIC_FUNCTION(finalize) 
	#endif

	#ifndef GEODE_STATICS_getCurReleasePool
		#define GEODE_STATICS_getCurReleasePool
		GEODE_AS_STATIC_FUNCTION(getCurReleasePool) 
	#endif

	#ifndef GEODE_STATICS_pop
		#define GEODE_STATICS_pop
		GEODE_AS_STATIC_FUNCTION(pop) 
	#endif

	#ifndef GEODE_STATICS_push
		#define GEODE_STATICS_push
		GEODE_AS_STATIC_FUNCTION(push) 
	#endif

	#ifndef GEODE_STATICS_removeObject
		#define GEODE_STATICS_removeObject
		GEODE_AS_STATIC_FUNCTION(removeObject) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_purgePoolManager
		#define GEODE_CONCEPT_CHECK_purgePoolManager
		GEODE_CONCEPT_FUNCTION_CHECK(purgePoolManager) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_sharedPoolManager
		#define GEODE_CONCEPT_CHECK_sharedPoolManager
		GEODE_CONCEPT_FUNCTION_CHECK(sharedPoolManager) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_addObject
		#define GEODE_CONCEPT_CHECK_addObject
		GEODE_CONCEPT_FUNCTION_CHECK(addObject) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_finalize
		#define GEODE_CONCEPT_CHECK_finalize
		GEODE_CONCEPT_FUNCTION_CHECK(finalize) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getCurReleasePool
		#define GEODE_CONCEPT_CHECK_getCurReleasePool
		GEODE_CONCEPT_FUNCTION_CHECK(getCurReleasePool) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_pop
		#define GEODE_CONCEPT_CHECK_pop
		GEODE_CONCEPT_FUNCTION_CHECK(pop) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_push
		#define GEODE_CONCEPT_CHECK_push
		GEODE_CONCEPT_FUNCTION_CHECK(push) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_removeObject
		#define GEODE_CONCEPT_CHECK_removeObject
		GEODE_CONCEPT_FUNCTION_CHECK(removeObject) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCPoolManager> : ModifyBase<ModifyDerive<Der, cocos2d::CCPoolManager>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCPoolManager>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCPoolManager>>::ModifyBase;
		using Base = cocos2d::CCPoolManager;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0x3f69f0, Default, cocos2d::CCPoolManager, )
			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0x3f6a40, Default, cocos2d::CCPoolManager)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3f69a0, Default, cocos2d::CCPoolManager, purgePoolManager, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3f68c0, Default, cocos2d::CCPoolManager, sharedPoolManager, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3f6dc0, Default, cocos2d::CCPoolManager, addObject, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3f6b40, Default, cocos2d::CCPoolManager, finalize, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3f6e00, Default, cocos2d::CCPoolManager, getCurReleasePool, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3f6cc0, Default, cocos2d::CCPoolManager, pop, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3f6c10, Default, cocos2d::CCPoolManager, push, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3f6d70, Default, cocos2d::CCPoolManager, removeObject, cocos2d::CCObject*)
		}
	};
}
