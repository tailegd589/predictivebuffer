#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <cocos2d.h>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_afterRender
		#define GEODE_STATICS_afterRender
		GEODE_AS_STATIC_FUNCTION(afterRender) 
	#endif

	#ifndef GEODE_STATICS_beforeRender
		#define GEODE_STATICS_beforeRender
		GEODE_AS_STATIC_FUNCTION(beforeRender) 
	#endif

	#ifndef GEODE_STATICS_grab
		#define GEODE_STATICS_grab
		GEODE_AS_STATIC_FUNCTION(grab) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_afterRender
		#define GEODE_CONCEPT_CHECK_afterRender
		GEODE_CONCEPT_FUNCTION_CHECK(afterRender) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_beforeRender
		#define GEODE_CONCEPT_CHECK_beforeRender
		GEODE_CONCEPT_FUNCTION_CHECK(beforeRender) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_grab
		#define GEODE_CONCEPT_CHECK_grab
		GEODE_CONCEPT_FUNCTION_CHECK(grab) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCGrabber> : ModifyBase<ModifyDerive<Der, cocos2d::CCGrabber>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCGrabber>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCGrabber>>::ModifyBase;
		using Base = cocos2d::CCGrabber;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0x522cc8, Default, cocos2d::CCGrabber, )
			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0x522e18, Default, cocos2d::CCGrabber)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x522de8, Default, cocos2d::CCGrabber, afterRender, cocos2d::CCTexture2D*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x522d90, Default, cocos2d::CCGrabber, beforeRender, cocos2d::CCTexture2D*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x522d20, Default, cocos2d::CCGrabber, grab, cocos2d::CCTexture2D*)
		}
	};
}
