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

	#ifndef GEODE_STATICS_createWithTotalParticles
		#define GEODE_STATICS_createWithTotalParticles
		GEODE_AS_STATIC_FUNCTION(createWithTotalParticles) 
	#endif

	#ifndef GEODE_STATICS_draw
		#define GEODE_STATICS_draw
		GEODE_AS_STATIC_FUNCTION(draw) 
	#endif

	#ifndef GEODE_STATICS_setBatchNode
		#define GEODE_STATICS_setBatchNode
		GEODE_AS_STATIC_FUNCTION(setBatchNode) 
	#endif

	#ifndef GEODE_STATICS_setTotalParticles
		#define GEODE_STATICS_setTotalParticles
		GEODE_AS_STATIC_FUNCTION(setTotalParticles) 
	#endif

	#ifndef GEODE_STATICS_initWithTotalParticles
		#define GEODE_STATICS_initWithTotalParticles
		GEODE_AS_STATIC_FUNCTION(initWithTotalParticles) 
	#endif

	#ifndef GEODE_STATICS_updateQuadWithParticle
		#define GEODE_STATICS_updateQuadWithParticle
		GEODE_AS_STATIC_FUNCTION(updateQuadWithParticle) 
	#endif

	#ifndef GEODE_STATICS_postStep
		#define GEODE_STATICS_postStep
		GEODE_AS_STATIC_FUNCTION(postStep) 
	#endif

	#ifndef GEODE_STATICS_setTexture
		#define GEODE_STATICS_setTexture
		GEODE_AS_STATIC_FUNCTION(setTexture) 
	#endif

	#ifndef GEODE_STATICS_allocMemory
		#define GEODE_STATICS_allocMemory
		GEODE_AS_STATIC_FUNCTION(allocMemory) 
	#endif

	#ifndef GEODE_STATICS_initIndices
		#define GEODE_STATICS_initIndices
		GEODE_AS_STATIC_FUNCTION(initIndices) 
	#endif

	#ifndef GEODE_STATICS_initTexCoordsWithRect
		#define GEODE_STATICS_initTexCoordsWithRect
		GEODE_AS_STATIC_FUNCTION(initTexCoordsWithRect) 
	#endif

	#ifndef GEODE_STATICS_listenBackToForeground
		#define GEODE_STATICS_listenBackToForeground
		GEODE_AS_STATIC_FUNCTION(listenBackToForeground) 
	#endif

	#ifndef GEODE_STATICS_setDisplayFrame
		#define GEODE_STATICS_setDisplayFrame
		GEODE_AS_STATIC_FUNCTION(setDisplayFrame) 
	#endif

	#ifndef GEODE_STATICS_setTextureWithRect
		#define GEODE_STATICS_setTextureWithRect
		GEODE_AS_STATIC_FUNCTION(setTextureWithRect) 
	#endif

	#ifndef GEODE_STATICS_setupVBOandVAO
		#define GEODE_STATICS_setupVBOandVAO
		GEODE_AS_STATIC_FUNCTION(setupVBOandVAO) 
	#endif

	#ifndef GEODE_STATICS_updateTexCoords
		#define GEODE_STATICS_updateTexCoords
		GEODE_AS_STATIC_FUNCTION(updateTexCoords) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_createWithTotalParticles
		#define GEODE_CONCEPT_CHECK_createWithTotalParticles
		GEODE_CONCEPT_FUNCTION_CHECK(createWithTotalParticles) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_draw
		#define GEODE_CONCEPT_CHECK_draw
		GEODE_CONCEPT_FUNCTION_CHECK(draw) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setBatchNode
		#define GEODE_CONCEPT_CHECK_setBatchNode
		GEODE_CONCEPT_FUNCTION_CHECK(setBatchNode) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setTotalParticles
		#define GEODE_CONCEPT_CHECK_setTotalParticles
		GEODE_CONCEPT_FUNCTION_CHECK(setTotalParticles) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_initWithTotalParticles
		#define GEODE_CONCEPT_CHECK_initWithTotalParticles
		GEODE_CONCEPT_FUNCTION_CHECK(initWithTotalParticles) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_updateQuadWithParticle
		#define GEODE_CONCEPT_CHECK_updateQuadWithParticle
		GEODE_CONCEPT_FUNCTION_CHECK(updateQuadWithParticle) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_postStep
		#define GEODE_CONCEPT_CHECK_postStep
		GEODE_CONCEPT_FUNCTION_CHECK(postStep) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setTexture
		#define GEODE_CONCEPT_CHECK_setTexture
		GEODE_CONCEPT_FUNCTION_CHECK(setTexture) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_allocMemory
		#define GEODE_CONCEPT_CHECK_allocMemory
		GEODE_CONCEPT_FUNCTION_CHECK(allocMemory) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_initIndices
		#define GEODE_CONCEPT_CHECK_initIndices
		GEODE_CONCEPT_FUNCTION_CHECK(initIndices) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_initTexCoordsWithRect
		#define GEODE_CONCEPT_CHECK_initTexCoordsWithRect
		GEODE_CONCEPT_FUNCTION_CHECK(initTexCoordsWithRect) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_listenBackToForeground
		#define GEODE_CONCEPT_CHECK_listenBackToForeground
		GEODE_CONCEPT_FUNCTION_CHECK(listenBackToForeground) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setDisplayFrame
		#define GEODE_CONCEPT_CHECK_setDisplayFrame
		GEODE_CONCEPT_FUNCTION_CHECK(setDisplayFrame) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setTextureWithRect
		#define GEODE_CONCEPT_CHECK_setTextureWithRect
		GEODE_CONCEPT_FUNCTION_CHECK(setTextureWithRect) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setupVBO
		#define GEODE_CONCEPT_CHECK_setupVBO
		GEODE_CONCEPT_FUNCTION_CHECK(setupVBO) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setupVBOandVAO
		#define GEODE_CONCEPT_CHECK_setupVBOandVAO
		GEODE_CONCEPT_FUNCTION_CHECK(setupVBOandVAO) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_updateTexCoords
		#define GEODE_CONCEPT_CHECK_updateTexCoords
		GEODE_CONCEPT_FUNCTION_CHECK(updateTexCoords) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCParticleSystemQuad> : ModifyBase<ModifyDerive<Der, cocos2d::CCParticleSystemQuad>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCParticleSystemQuad>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCParticleSystemQuad>>::ModifyBase;
		using Base = cocos2d::CCParticleSystemQuad;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0x602940, Default, cocos2d::CCParticleSystemQuad, )
			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0x602a40, Default, cocos2d::CCParticleSystemQuad)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x603ed0, Default, cocos2d::CCParticleSystemQuad, create, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x602b20, Default, cocos2d::CCParticleSystemQuad, create, char const*, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x602c00, Default, cocos2d::CCParticleSystemQuad, createWithTotalParticles, unsigned int, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x6034e0, Default, cocos2d::CCParticleSystemQuad, draw, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x603ab0, Default, cocos2d::CCParticleSystemQuad, setBatchNode, cocos2d::CCParticleBatchNode*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x6035b0, Default, cocos2d::CCParticleSystemQuad, setTotalParticles, unsigned int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x602090, Default, cocos2d::CCParticleSystemQuad, initWithTotalParticles, unsigned int, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x603170, Default, cocos2d::CCParticleSystemQuad, updateQuadWithParticle, cocos2d::sCCParticle*, cocos2d::CCPoint const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x603490, Default, cocos2d::CCParticleSystemQuad, postStep, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x602fc0, Default, cocos2d::CCParticleSystemQuad, setTexture, cocos2d::CCTexture2D*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x6023f0, Default, cocos2d::CCParticleSystemQuad, allocMemory, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x6024e0, Default, cocos2d::CCParticleSystemQuad, initIndices, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x602cf0, Default, cocos2d::CCParticleSystemQuad, initTexCoordsWithRect, cocos2d::CCRect const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x603aa0, Default, cocos2d::CCParticleSystemQuad, listenBackToForeground, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x6030e0, Default, cocos2d::CCParticleSystemQuad, setDisplayFrame, cocos2d::CCSpriteFrame*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x602f60, Default, cocos2d::CCParticleSystemQuad, setTextureWithRect, cocos2d::CCTexture2D*, cocos2d::CCRect const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x6027d0, Default, cocos2d::CCParticleSystemQuad, setupVBOandVAO, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x602f40, Default, cocos2d::CCParticleSystemQuad, updateTexCoords, )
		}
	};
}
