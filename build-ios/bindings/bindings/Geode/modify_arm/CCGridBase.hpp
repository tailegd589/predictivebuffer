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

	#ifndef GEODE_STATICS_blit
		#define GEODE_STATICS_blit
		GEODE_AS_STATIC_FUNCTION(blit) 
	#endif

	#ifndef GEODE_STATICS_reuse
		#define GEODE_STATICS_reuse
		GEODE_AS_STATIC_FUNCTION(reuse) 
	#endif

	#ifndef GEODE_STATICS_calculateVertexPoints
		#define GEODE_STATICS_calculateVertexPoints
		GEODE_AS_STATIC_FUNCTION(calculateVertexPoints) 
	#endif

	#ifndef GEODE_STATICS_afterDraw
		#define GEODE_STATICS_afterDraw
		GEODE_AS_STATIC_FUNCTION(afterDraw) 
	#endif

	#ifndef GEODE_STATICS_beforeDraw
		#define GEODE_STATICS_beforeDraw
		GEODE_AS_STATIC_FUNCTION(beforeDraw) 
	#endif

	#ifndef GEODE_STATICS_initWithSize
		#define GEODE_STATICS_initWithSize
		GEODE_AS_STATIC_FUNCTION(initWithSize) 
	#endif

	#ifndef GEODE_STATICS_set2DProjection
		#define GEODE_STATICS_set2DProjection
		GEODE_AS_STATIC_FUNCTION(set2DProjection) 
	#endif

	#ifndef GEODE_STATICS_setActive
		#define GEODE_STATICS_setActive
		GEODE_AS_STATIC_FUNCTION(setActive) 
	#endif

	#ifndef GEODE_STATICS_setTextureFlipped
		#define GEODE_STATICS_setTextureFlipped
		GEODE_AS_STATIC_FUNCTION(setTextureFlipped) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_blit
		#define GEODE_CONCEPT_CHECK_blit
		GEODE_CONCEPT_FUNCTION_CHECK(blit) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_reuse
		#define GEODE_CONCEPT_CHECK_reuse
		GEODE_CONCEPT_FUNCTION_CHECK(reuse) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_calculateVertexPoints
		#define GEODE_CONCEPT_CHECK_calculateVertexPoints
		GEODE_CONCEPT_FUNCTION_CHECK(calculateVertexPoints) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_afterDraw
		#define GEODE_CONCEPT_CHECK_afterDraw
		GEODE_CONCEPT_FUNCTION_CHECK(afterDraw) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_beforeDraw
		#define GEODE_CONCEPT_CHECK_beforeDraw
		GEODE_CONCEPT_FUNCTION_CHECK(beforeDraw) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_initWithSize
		#define GEODE_CONCEPT_CHECK_initWithSize
		GEODE_CONCEPT_FUNCTION_CHECK(initWithSize) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_set2DProjection
		#define GEODE_CONCEPT_CHECK_set2DProjection
		GEODE_CONCEPT_FUNCTION_CHECK(set2DProjection) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setActive
		#define GEODE_CONCEPT_CHECK_setActive
		GEODE_CONCEPT_FUNCTION_CHECK(setActive) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setTextureFlipped
		#define GEODE_CONCEPT_CHECK_setTextureFlipped
		GEODE_CONCEPT_FUNCTION_CHECK(setTextureFlipped) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCGridBase> : ModifyBase<ModifyDerive<Der, cocos2d::CCGridBase>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCGridBase>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCGridBase>>::ModifyBase;
		using Base = cocos2d::CCGridBase;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0x43edf8, Default, cocos2d::CCGridBase)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x43eab0, Default, cocos2d::CCGridBase, create, cocos2d::CCSize const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x43ec68, Default, cocos2d::CCGridBase, create, cocos2d::CCSize const&, cocos2d::CCTexture2D*, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x43f098, Default, cocos2d::CCGridBase, blit, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x43f09c, Default, cocos2d::CCGridBase, reuse, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x43f0a0, Default, cocos2d::CCGridBase, calculateVertexPoints, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x43efc8, Default, cocos2d::CCGridBase, afterDraw, cocos2d::CCNode*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x43ef94, Default, cocos2d::CCGridBase, beforeDraw, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x43eb74, Default, cocos2d::CCGridBase, initWithSize, cocos2d::CCSize const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x43ed24, Default, cocos2d::CCGridBase, initWithSize, cocos2d::CCSize const&, cocos2d::CCTexture2D*, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x43ef18, Default, cocos2d::CCGridBase, set2DProjection, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x43eed4, Default, cocos2d::CCGridBase, setActive, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x43eef8, Default, cocos2d::CCGridBase, setTextureFlipped, bool)
		}
	};
}
