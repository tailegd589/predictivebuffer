#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <cocos2d.h>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_create
		#define GEODE_STATICS_create
		GEODE_AS_STATIC_FUNCTION(create) 
	#endif

	#ifndef GEODE_STATICS_addChild
		#define GEODE_STATICS_addChild
		GEODE_AS_STATIC_FUNCTION(addChild) 
	#endif

	#ifndef GEODE_STATICS_removeChild
		#define GEODE_STATICS_removeChild
		GEODE_AS_STATIC_FUNCTION(removeChild) 
	#endif

	#ifndef GEODE_STATICS_removeAllChildrenWithCleanup
		#define GEODE_STATICS_removeAllChildrenWithCleanup
		GEODE_AS_STATIC_FUNCTION(removeAllChildrenWithCleanup) 
	#endif

	#ifndef GEODE_STATICS_visit
		#define GEODE_STATICS_visit
		GEODE_AS_STATIC_FUNCTION(visit) 
	#endif

	#ifndef GEODE_STATICS_absolutePosition
		#define GEODE_STATICS_absolutePosition
		GEODE_AS_STATIC_FUNCTION(absolutePosition) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_addChild
		#define GEODE_CONCEPT_CHECK_addChild
		GEODE_CONCEPT_FUNCTION_CHECK(addChild) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_removeChild
		#define GEODE_CONCEPT_CHECK_removeChild
		GEODE_CONCEPT_FUNCTION_CHECK(removeChild) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_removeAllChildrenWithCleanup
		#define GEODE_CONCEPT_CHECK_removeAllChildrenWithCleanup
		GEODE_CONCEPT_FUNCTION_CHECK(removeAllChildrenWithCleanup) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_visit
		#define GEODE_CONCEPT_CHECK_visit
		GEODE_CONCEPT_FUNCTION_CHECK(visit) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_absolutePosition
		#define GEODE_CONCEPT_CHECK_absolutePosition
		GEODE_CONCEPT_FUNCTION_CHECK(absolutePosition) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCParallaxNode> : ModifyBase<ModifyDerive<Der, cocos2d::CCParallaxNode>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCParallaxNode>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCParallaxNode>>::ModifyBase;
		using Base = cocos2d::CCParallaxNode;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0x4ae6f0, Default, cocos2d::CCParallaxNode, )
			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0x4ae7f0, Default, cocos2d::CCParallaxNode)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4ae8e0, Default, cocos2d::CCParallaxNode, create, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4ae9b0, Default, cocos2d::CCParallaxNode, addChild, cocos2d::CCNode*, unsigned int, cocos2d::CCPoint const&, cocos2d::CCPoint const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4ae9a0, Default, cocos2d::CCParallaxNode, addChild, cocos2d::CCNode*, unsigned int, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4aeb70, Default, cocos2d::CCParallaxNode, removeChild, cocos2d::CCNode*, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4aebf0, Default, cocos2d::CCParallaxNode, removeAllChildrenWithCleanup, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4aecb0, Default, cocos2d::CCParallaxNode, visit, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4aec20, Default, cocos2d::CCParallaxNode, absolutePosition, )
		}
	};
}
