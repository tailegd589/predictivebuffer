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

	#ifndef GEODE_STATICS_createWithTexture
		#define GEODE_STATICS_createWithTexture
		GEODE_AS_STATIC_FUNCTION(createWithTexture) 
	#endif

	#ifndef GEODE_STATICS_addChild
		#define GEODE_STATICS_addChild
		GEODE_AS_STATIC_FUNCTION(addChild) 
	#endif

	#ifndef GEODE_STATICS_removeChild
		#define GEODE_STATICS_removeChild
		GEODE_AS_STATIC_FUNCTION(removeChild) 
	#endif

	#ifndef GEODE_STATICS_reorderChild
		#define GEODE_STATICS_reorderChild
		GEODE_AS_STATIC_FUNCTION(reorderChild) 
	#endif

	#ifndef GEODE_STATICS_removeAllChildrenWithCleanup
		#define GEODE_STATICS_removeAllChildrenWithCleanup
		GEODE_AS_STATIC_FUNCTION(removeAllChildrenWithCleanup) 
	#endif

	#ifndef GEODE_STATICS_draw
		#define GEODE_STATICS_draw
		GEODE_AS_STATIC_FUNCTION(draw) 
	#endif

	#ifndef GEODE_STATICS_getTexture
		#define GEODE_STATICS_getTexture
		GEODE_AS_STATIC_FUNCTION(getTexture) 
	#endif

	#ifndef GEODE_STATICS_setTexture
		#define GEODE_STATICS_setTexture
		GEODE_AS_STATIC_FUNCTION(setTexture) 
	#endif

	#ifndef GEODE_STATICS_setBlendFunc
		#define GEODE_STATICS_setBlendFunc
		GEODE_AS_STATIC_FUNCTION(setBlendFunc) 
	#endif

	#ifndef GEODE_STATICS_getBlendFunc
		#define GEODE_STATICS_getBlendFunc
		GEODE_AS_STATIC_FUNCTION(getBlendFunc) 
	#endif

	#ifndef GEODE_STATICS_visit
		#define GEODE_STATICS_visit
		GEODE_AS_STATIC_FUNCTION(visit) 
	#endif

	#ifndef GEODE_STATICS_addChildHelper
		#define GEODE_STATICS_addChildHelper
		GEODE_AS_STATIC_FUNCTION(addChildHelper) 
	#endif

	#ifndef GEODE_STATICS_disableParticle
		#define GEODE_STATICS_disableParticle
		GEODE_AS_STATIC_FUNCTION(disableParticle) 
	#endif

	#ifndef GEODE_STATICS_getCurrentIndex
		#define GEODE_STATICS_getCurrentIndex
		GEODE_AS_STATIC_FUNCTION(getCurrentIndex) 
	#endif

	#ifndef GEODE_STATICS_increaseAtlasCapacityTo
		#define GEODE_STATICS_increaseAtlasCapacityTo
		GEODE_AS_STATIC_FUNCTION(increaseAtlasCapacityTo) 
	#endif

	#ifndef GEODE_STATICS_initWithFile
		#define GEODE_STATICS_initWithFile
		GEODE_AS_STATIC_FUNCTION(initWithFile) 
	#endif

	#ifndef GEODE_STATICS_initWithTexture
		#define GEODE_STATICS_initWithTexture
		GEODE_AS_STATIC_FUNCTION(initWithTexture) 
	#endif

	#ifndef GEODE_STATICS_insertChild
		#define GEODE_STATICS_insertChild
		GEODE_AS_STATIC_FUNCTION(insertChild) 
	#endif

	#ifndef GEODE_STATICS_removeChildAtIndex
		#define GEODE_STATICS_removeChildAtIndex
		GEODE_AS_STATIC_FUNCTION(removeChildAtIndex) 
	#endif

	#ifndef GEODE_STATICS_searchNewPositionInChildrenForZ
		#define GEODE_STATICS_searchNewPositionInChildrenForZ
		GEODE_AS_STATIC_FUNCTION(searchNewPositionInChildrenForZ) 
	#endif

	#ifndef GEODE_STATICS_updateAllAtlasIndexes
		#define GEODE_STATICS_updateAllAtlasIndexes
		GEODE_AS_STATIC_FUNCTION(updateAllAtlasIndexes) 
	#endif

	#ifndef GEODE_STATICS_updateBlendFunc
		#define GEODE_STATICS_updateBlendFunc
		GEODE_AS_STATIC_FUNCTION(updateBlendFunc) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_createWithTexture
		#define GEODE_CONCEPT_CHECK_createWithTexture
		GEODE_CONCEPT_FUNCTION_CHECK(createWithTexture) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_addChild
		#define GEODE_CONCEPT_CHECK_addChild
		GEODE_CONCEPT_FUNCTION_CHECK(addChild) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_removeChild
		#define GEODE_CONCEPT_CHECK_removeChild
		GEODE_CONCEPT_FUNCTION_CHECK(removeChild) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_reorderChild
		#define GEODE_CONCEPT_CHECK_reorderChild
		GEODE_CONCEPT_FUNCTION_CHECK(reorderChild) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_removeAllChildrenWithCleanup
		#define GEODE_CONCEPT_CHECK_removeAllChildrenWithCleanup
		GEODE_CONCEPT_FUNCTION_CHECK(removeAllChildrenWithCleanup) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_draw
		#define GEODE_CONCEPT_CHECK_draw
		GEODE_CONCEPT_FUNCTION_CHECK(draw) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getTexture
		#define GEODE_CONCEPT_CHECK_getTexture
		GEODE_CONCEPT_FUNCTION_CHECK(getTexture) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setTexture
		#define GEODE_CONCEPT_CHECK_setTexture
		GEODE_CONCEPT_FUNCTION_CHECK(setTexture) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setBlendFunc
		#define GEODE_CONCEPT_CHECK_setBlendFunc
		GEODE_CONCEPT_FUNCTION_CHECK(setBlendFunc) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getBlendFunc
		#define GEODE_CONCEPT_CHECK_getBlendFunc
		GEODE_CONCEPT_FUNCTION_CHECK(getBlendFunc) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_visit
		#define GEODE_CONCEPT_CHECK_visit
		GEODE_CONCEPT_FUNCTION_CHECK(visit) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_addChildHelper
		#define GEODE_CONCEPT_CHECK_addChildHelper
		GEODE_CONCEPT_FUNCTION_CHECK(addChildHelper) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_disableParticle
		#define GEODE_CONCEPT_CHECK_disableParticle
		GEODE_CONCEPT_FUNCTION_CHECK(disableParticle) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getCurrentIndex
		#define GEODE_CONCEPT_CHECK_getCurrentIndex
		GEODE_CONCEPT_FUNCTION_CHECK(getCurrentIndex) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_increaseAtlasCapacityTo
		#define GEODE_CONCEPT_CHECK_increaseAtlasCapacityTo
		GEODE_CONCEPT_FUNCTION_CHECK(increaseAtlasCapacityTo) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_initWithFile
		#define GEODE_CONCEPT_CHECK_initWithFile
		GEODE_CONCEPT_FUNCTION_CHECK(initWithFile) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_initWithTexture
		#define GEODE_CONCEPT_CHECK_initWithTexture
		GEODE_CONCEPT_FUNCTION_CHECK(initWithTexture) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_insertChild
		#define GEODE_CONCEPT_CHECK_insertChild
		GEODE_CONCEPT_FUNCTION_CHECK(insertChild) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_removeChildAtIndex
		#define GEODE_CONCEPT_CHECK_removeChildAtIndex
		GEODE_CONCEPT_FUNCTION_CHECK(removeChildAtIndex) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_searchNewPositionInChildrenForZ
		#define GEODE_CONCEPT_CHECK_searchNewPositionInChildrenForZ
		GEODE_CONCEPT_FUNCTION_CHECK(searchNewPositionInChildrenForZ) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_updateAllAtlasIndexes
		#define GEODE_CONCEPT_CHECK_updateAllAtlasIndexes
		GEODE_CONCEPT_FUNCTION_CHECK(updateAllAtlasIndexes) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_updateBlendFunc
		#define GEODE_CONCEPT_CHECK_updateBlendFunc
		GEODE_CONCEPT_FUNCTION_CHECK(updateBlendFunc) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCParticleBatchNode> : ModifyBase<ModifyDerive<Der, cocos2d::CCParticleBatchNode>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCParticleBatchNode>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCParticleBatchNode>>::ModifyBase;
		using Base = cocos2d::CCParticleBatchNode;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0x3c8820, Default, cocos2d::CCParticleBatchNode, )
			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0x3c88a0, Default, cocos2d::CCParticleBatchNode)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3c8ad0, Default, cocos2d::CCParticleBatchNode, create, char const*, unsigned int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3c8990, Default, cocos2d::CCParticleBatchNode, createWithTexture, cocos2d::CCTexture2D*, unsigned int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3c8c20, Default, cocos2d::CCParticleBatchNode, addChild, cocos2d::CCNode*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3c8c30, Default, cocos2d::CCParticleBatchNode, addChild, cocos2d::CCNode*, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3c8c40, Default, cocos2d::CCParticleBatchNode, addChild, cocos2d::CCNode*, int, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3c9490, Default, cocos2d::CCParticleBatchNode, removeChild, cocos2d::CCNode*, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3c9080, Default, cocos2d::CCParticleBatchNode, reorderChild, cocos2d::CCNode*, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3c95c0, Default, cocos2d::CCParticleBatchNode, removeAllChildrenWithCleanup, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3c9650, Default, cocos2d::CCParticleBatchNode, draw, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3c9830, Default, cocos2d::CCParticleBatchNode, getTexture, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3c9790, Default, cocos2d::CCParticleBatchNode, setTexture, cocos2d::CCTexture2D*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3c9860, Default, cocos2d::CCParticleBatchNode, setBlendFunc, cocos2d::ccBlendFunc)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3c9880, Default, cocos2d::CCParticleBatchNode, getBlendFunc, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3c8bb0, Default, cocos2d::CCParticleBatchNode, visit, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3c8d40, Default, cocos2d::CCParticleBatchNode, addChildHelper, cocos2d::CCParticleSystem*, int, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3c9700, Default, cocos2d::CCParticleBatchNode, disableParticle, unsigned int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3c9320, Default, cocos2d::CCParticleBatchNode, getCurrentIndex, unsigned int*, unsigned int*, cocos2d::CCNode*, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3c96e0, Default, cocos2d::CCParticleBatchNode, increaseAtlasCapacityTo, unsigned int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3c8b70, Default, cocos2d::CCParticleBatchNode, initWithFile, char const*, unsigned int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3c8a10, Default, cocos2d::CCParticleBatchNode, initWithTexture, cocos2d::CCTexture2D*, unsigned int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3c8e80, Default, cocos2d::CCParticleBatchNode, insertChild, cocos2d::CCParticleSystem*, unsigned int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3c9590, Default, cocos2d::CCParticleBatchNode, removeChildAtIndex, unsigned int, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3c9010, Default, cocos2d::CCParticleBatchNode, searchNewPositionInChildrenForZ, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3c9430, Default, cocos2d::CCParticleBatchNode, updateAllAtlasIndexes, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x3c9750, Default, cocos2d::CCParticleBatchNode, updateBlendFunc, )
		}
	};
}
