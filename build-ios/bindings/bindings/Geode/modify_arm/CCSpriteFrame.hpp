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

	#ifndef GEODE_STATICS_copyWithZone
		#define GEODE_STATICS_copyWithZone
		GEODE_AS_STATIC_FUNCTION(copyWithZone) 
	#endif

	#ifndef GEODE_STATICS_getOffset
		#define GEODE_STATICS_getOffset
		GEODE_AS_STATIC_FUNCTION(getOffset) 
	#endif

	#ifndef GEODE_STATICS_getOffsetInPixels
		#define GEODE_STATICS_getOffsetInPixels
		GEODE_AS_STATIC_FUNCTION(getOffsetInPixels) 
	#endif

	#ifndef GEODE_STATICS_getTexture
		#define GEODE_STATICS_getTexture
		GEODE_AS_STATIC_FUNCTION(getTexture) 
	#endif

	#ifndef GEODE_STATICS_initWithTexture
		#define GEODE_STATICS_initWithTexture
		GEODE_AS_STATIC_FUNCTION(initWithTexture) 
	#endif

	#ifndef GEODE_STATICS_initWithTextureFilename
		#define GEODE_STATICS_initWithTextureFilename
		GEODE_AS_STATIC_FUNCTION(initWithTextureFilename) 
	#endif

	#ifndef GEODE_STATICS_setOffset
		#define GEODE_STATICS_setOffset
		GEODE_AS_STATIC_FUNCTION(setOffset) 
	#endif

	#ifndef GEODE_STATICS_setOffsetInPixels
		#define GEODE_STATICS_setOffsetInPixels
		GEODE_AS_STATIC_FUNCTION(setOffsetInPixels) 
	#endif

	#ifndef GEODE_STATICS_setRect
		#define GEODE_STATICS_setRect
		GEODE_AS_STATIC_FUNCTION(setRect) 
	#endif

	#ifndef GEODE_STATICS_setRectInPixels
		#define GEODE_STATICS_setRectInPixels
		GEODE_AS_STATIC_FUNCTION(setRectInPixels) 
	#endif

	#ifndef GEODE_STATICS_setTexture
		#define GEODE_STATICS_setTexture
		GEODE_AS_STATIC_FUNCTION(setTexture) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_createWithTexture
		#define GEODE_CONCEPT_CHECK_createWithTexture
		GEODE_CONCEPT_FUNCTION_CHECK(createWithTexture) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_copyWithZone
		#define GEODE_CONCEPT_CHECK_copyWithZone
		GEODE_CONCEPT_FUNCTION_CHECK(copyWithZone) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getOffset
		#define GEODE_CONCEPT_CHECK_getOffset
		GEODE_CONCEPT_FUNCTION_CHECK(getOffset) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getOffsetInPixels
		#define GEODE_CONCEPT_CHECK_getOffsetInPixels
		GEODE_CONCEPT_FUNCTION_CHECK(getOffsetInPixels) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getTexture
		#define GEODE_CONCEPT_CHECK_getTexture
		GEODE_CONCEPT_FUNCTION_CHECK(getTexture) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_initWithTexture
		#define GEODE_CONCEPT_CHECK_initWithTexture
		GEODE_CONCEPT_FUNCTION_CHECK(initWithTexture) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_initWithTextureFilename
		#define GEODE_CONCEPT_CHECK_initWithTextureFilename
		GEODE_CONCEPT_FUNCTION_CHECK(initWithTextureFilename) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setOffset
		#define GEODE_CONCEPT_CHECK_setOffset
		GEODE_CONCEPT_FUNCTION_CHECK(setOffset) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setOffsetInPixels
		#define GEODE_CONCEPT_CHECK_setOffsetInPixels
		GEODE_CONCEPT_FUNCTION_CHECK(setOffsetInPixels) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setRect
		#define GEODE_CONCEPT_CHECK_setRect
		GEODE_CONCEPT_FUNCTION_CHECK(setRect) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setRectInPixels
		#define GEODE_CONCEPT_CHECK_setRectInPixels
		GEODE_CONCEPT_FUNCTION_CHECK(setRectInPixels) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setTexture
		#define GEODE_CONCEPT_CHECK_setTexture
		GEODE_CONCEPT_FUNCTION_CHECK(setTexture) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCSpriteFrame> : ModifyBase<ModifyDerive<Der, cocos2d::CCSpriteFrame>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCSpriteFrame>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCSpriteFrame>>::ModifyBase;
		using Base = cocos2d::CCSpriteFrame;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0x2e3db0, Default, cocos2d::CCSpriteFrame)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x2e3584, Default, cocos2d::CCSpriteFrame, create, char const*, cocos2d::CCRect const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x2e3b48, Default, cocos2d::CCSpriteFrame, create, char const*, cocos2d::CCRect const&, bool, cocos2d::CCPoint const&, cocos2d::CCSize const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x2e3730, Default, cocos2d::CCSpriteFrame, createWithTexture, cocos2d::CCTexture2D*, cocos2d::CCRect const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x2e38dc, Default, cocos2d::CCSpriteFrame, createWithTexture, cocos2d::CCTexture2D*, cocos2d::CCRect const&, bool, cocos2d::CCPoint const&, cocos2d::CCSize const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x2e3f14, Default, cocos2d::CCSpriteFrame, copyWithZone, cocos2d::CCZone*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x2e41ac, Default, cocos2d::CCSpriteFrame, getOffset, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x2e4220, Default, cocos2d::CCSpriteFrame, getOffsetInPixels, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x2e4294, Default, cocos2d::CCSpriteFrame, getTexture, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x2e381c, Default, cocos2d::CCSpriteFrame, initWithTexture, cocos2d::CCTexture2D*, cocos2d::CCRect const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x2e39e8, Default, cocos2d::CCSpriteFrame, initWithTexture, cocos2d::CCTexture2D*, cocos2d::CCRect const&, bool, cocos2d::CCPoint const&, cocos2d::CCSize const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x2e3670, Default, cocos2d::CCSpriteFrame, initWithTextureFilename, char const*, cocos2d::CCRect const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x2e3c54, Default, cocos2d::CCSpriteFrame, initWithTextureFilename, char const*, cocos2d::CCRect const&, bool, cocos2d::CCPoint const&, cocos2d::CCSize const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x2e41b4, Default, cocos2d::CCSpriteFrame, setOffset, cocos2d::CCPoint const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x2e4228, Default, cocos2d::CCSpriteFrame, setOffsetInPixels, cocos2d::CCPoint const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x2e4070, Default, cocos2d::CCSpriteFrame, setRect, cocos2d::CCRect const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x2e410c, Default, cocos2d::CCSpriteFrame, setRectInPixels, cocos2d::CCRect const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x2e402c, Default, cocos2d::CCSpriteFrame, setTexture, cocos2d::CCTexture2D*)
		}
	};
}
