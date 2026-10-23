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

	#ifndef GEODE_STATICS_originalVertex
		#define GEODE_STATICS_originalVertex
		GEODE_AS_STATIC_FUNCTION(originalVertex) 
	#endif

	#ifndef GEODE_STATICS_setVertex
		#define GEODE_STATICS_setVertex
		GEODE_AS_STATIC_FUNCTION(setVertex) 
	#endif

	#ifndef GEODE_STATICS_vertex
		#define GEODE_STATICS_vertex
		GEODE_AS_STATIC_FUNCTION(vertex) 
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

	#ifndef GEODE_CONCEPT_CHECK_originalVertex
		#define GEODE_CONCEPT_CHECK_originalVertex
		GEODE_CONCEPT_FUNCTION_CHECK(originalVertex) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setVertex
		#define GEODE_CONCEPT_CHECK_setVertex
		GEODE_CONCEPT_FUNCTION_CHECK(setVertex) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_vertex
		#define GEODE_CONCEPT_CHECK_vertex
		GEODE_CONCEPT_FUNCTION_CHECK(vertex) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCGrid3D> : ModifyBase<ModifyDerive<Der, cocos2d::CCGrid3D>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCGrid3D>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCGrid3D>>::ModifyBase;
		using Base = cocos2d::CCGrid3D;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0x4e3d00, Default, cocos2d::CCGrid3D, )
			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0x4e3d60, Default, cocos2d::CCGrid3D)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4e3c50, Default, cocos2d::CCGrid3D, create, cocos2d::CCSize const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4e3b30, Default, cocos2d::CCGrid3D, create, cocos2d::CCSize const&, cocos2d::CCTexture2D*, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4e3e50, Default, cocos2d::CCGrid3D, blit, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4e45f0, Default, cocos2d::CCGrid3D, reuse, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4e3ef0, Default, cocos2d::CCGrid3D, calculateVertexPoints, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4e4560, Default, cocos2d::CCGrid3D, originalVertex, cocos2d::CCPoint const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4e45a0, Default, cocos2d::CCGrid3D, setVertex, cocos2d::CCPoint const&, cocos2d::ccVertex3F const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x4e4520, Default, cocos2d::CCGrid3D, vertex, cocos2d::CCPoint const&)
		}
	};
}
