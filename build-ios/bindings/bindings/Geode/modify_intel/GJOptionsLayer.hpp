#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <Geode/binding/GJOptionsLayer.hpp>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_create
		#define GEODE_STATICS_create
		GEODE_AS_STATIC_FUNCTION(create) 
	#endif

	#ifndef GEODE_STATICS_setupOptions
		#define GEODE_STATICS_setupOptions
		GEODE_AS_STATIC_FUNCTION(setupOptions) 
	#endif

	#ifndef GEODE_STATICS_addGVToggle
		#define GEODE_STATICS_addGVToggle
		GEODE_AS_STATIC_FUNCTION(addGVToggle) 
	#endif

	#ifndef GEODE_STATICS_addToggle
		#define GEODE_STATICS_addToggle
		GEODE_AS_STATIC_FUNCTION(addToggle) 
	#endif

	#ifndef GEODE_STATICS_addToggleInternal
		#define GEODE_STATICS_addToggleInternal
		GEODE_AS_STATIC_FUNCTION(addToggleInternal) 
	#endif

	#ifndef GEODE_STATICS_countForPage
		#define GEODE_STATICS_countForPage
		GEODE_AS_STATIC_FUNCTION(countForPage) 
	#endif

	#ifndef GEODE_STATICS_goToPage
		#define GEODE_STATICS_goToPage
		GEODE_AS_STATIC_FUNCTION(goToPage) 
	#endif

	#ifndef GEODE_STATICS_incrementCountForPage
		#define GEODE_STATICS_incrementCountForPage
		GEODE_AS_STATIC_FUNCTION(incrementCountForPage) 
	#endif

	#ifndef GEODE_STATICS_infoKey
		#define GEODE_STATICS_infoKey
		GEODE_AS_STATIC_FUNCTION(infoKey) 
	#endif

	#ifndef GEODE_STATICS_init
		#define GEODE_STATICS_init
		GEODE_AS_STATIC_FUNCTION(init) 
	#endif

	#ifndef GEODE_STATICS_layerForPage
		#define GEODE_STATICS_layerForPage
		GEODE_AS_STATIC_FUNCTION(layerForPage) 
	#endif

	#ifndef GEODE_STATICS_layerKey
		#define GEODE_STATICS_layerKey
		GEODE_AS_STATIC_FUNCTION(layerKey) 
	#endif

	#ifndef GEODE_STATICS_nextPosition
		#define GEODE_STATICS_nextPosition
		GEODE_AS_STATIC_FUNCTION(nextPosition) 
	#endif

	#ifndef GEODE_STATICS_objectKey
		#define GEODE_STATICS_objectKey
		GEODE_AS_STATIC_FUNCTION(objectKey) 
	#endif

	#ifndef GEODE_STATICS_objectsForPage
		#define GEODE_STATICS_objectsForPage
		GEODE_AS_STATIC_FUNCTION(objectsForPage) 
	#endif

	#ifndef GEODE_STATICS_offsetToNextPage
		#define GEODE_STATICS_offsetToNextPage
		GEODE_AS_STATIC_FUNCTION(offsetToNextPage) 
	#endif

	#ifndef GEODE_STATICS_onInfo
		#define GEODE_STATICS_onInfo
		GEODE_AS_STATIC_FUNCTION(onInfo) 
	#endif

	#ifndef GEODE_STATICS_onNextPage
		#define GEODE_STATICS_onNextPage
		GEODE_AS_STATIC_FUNCTION(onNextPage) 
	#endif

	#ifndef GEODE_STATICS_onPrevPage
		#define GEODE_STATICS_onPrevPage
		GEODE_AS_STATIC_FUNCTION(onPrevPage) 
	#endif

	#ifndef GEODE_STATICS_onToggle
		#define GEODE_STATICS_onToggle
		GEODE_AS_STATIC_FUNCTION(onToggle) 
	#endif

	#ifndef GEODE_STATICS_pageKey
		#define GEODE_STATICS_pageKey
		GEODE_AS_STATIC_FUNCTION(pageKey) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setupOptions
		#define GEODE_CONCEPT_CHECK_setupOptions
		GEODE_CONCEPT_FUNCTION_CHECK(setupOptions) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_didToggleGV
		#define GEODE_CONCEPT_CHECK_didToggleGV
		GEODE_CONCEPT_FUNCTION_CHECK(didToggleGV) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_didToggle
		#define GEODE_CONCEPT_CHECK_didToggle
		GEODE_CONCEPT_FUNCTION_CHECK(didToggle) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_addGVToggle
		#define GEODE_CONCEPT_CHECK_addGVToggle
		GEODE_CONCEPT_FUNCTION_CHECK(addGVToggle) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_addToggle
		#define GEODE_CONCEPT_CHECK_addToggle
		GEODE_CONCEPT_FUNCTION_CHECK(addToggle) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_addToggleInternal
		#define GEODE_CONCEPT_CHECK_addToggleInternal
		GEODE_CONCEPT_FUNCTION_CHECK(addToggleInternal) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_countForPage
		#define GEODE_CONCEPT_CHECK_countForPage
		GEODE_CONCEPT_FUNCTION_CHECK(countForPage) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getToggleButton
		#define GEODE_CONCEPT_CHECK_getToggleButton
		GEODE_CONCEPT_FUNCTION_CHECK(getToggleButton) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_goToPage
		#define GEODE_CONCEPT_CHECK_goToPage
		GEODE_CONCEPT_FUNCTION_CHECK(goToPage) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_incrementCountForPage
		#define GEODE_CONCEPT_CHECK_incrementCountForPage
		GEODE_CONCEPT_FUNCTION_CHECK(incrementCountForPage) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_infoKey
		#define GEODE_CONCEPT_CHECK_infoKey
		GEODE_CONCEPT_FUNCTION_CHECK(infoKey) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_init
		#define GEODE_CONCEPT_CHECK_init
		GEODE_CONCEPT_FUNCTION_CHECK(init) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_layerForPage
		#define GEODE_CONCEPT_CHECK_layerForPage
		GEODE_CONCEPT_FUNCTION_CHECK(layerForPage) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_layerKey
		#define GEODE_CONCEPT_CHECK_layerKey
		GEODE_CONCEPT_FUNCTION_CHECK(layerKey) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_nextPosition
		#define GEODE_CONCEPT_CHECK_nextPosition
		GEODE_CONCEPT_FUNCTION_CHECK(nextPosition) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_objectKey
		#define GEODE_CONCEPT_CHECK_objectKey
		GEODE_CONCEPT_FUNCTION_CHECK(objectKey) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_objectsForPage
		#define GEODE_CONCEPT_CHECK_objectsForPage
		GEODE_CONCEPT_FUNCTION_CHECK(objectsForPage) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_offsetToNextPage
		#define GEODE_CONCEPT_CHECK_offsetToNextPage
		GEODE_CONCEPT_FUNCTION_CHECK(offsetToNextPage) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onInfo
		#define GEODE_CONCEPT_CHECK_onInfo
		GEODE_CONCEPT_FUNCTION_CHECK(onInfo) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onNextPage
		#define GEODE_CONCEPT_CHECK_onNextPage
		GEODE_CONCEPT_FUNCTION_CHECK(onNextPage) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onPrevPage
		#define GEODE_CONCEPT_CHECK_onPrevPage
		GEODE_CONCEPT_FUNCTION_CHECK(onPrevPage) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onToggle
		#define GEODE_CONCEPT_CHECK_onToggle
		GEODE_CONCEPT_FUNCTION_CHECK(onToggle) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_pageKey
		#define GEODE_CONCEPT_CHECK_pageKey
		GEODE_CONCEPT_FUNCTION_CHECK(pageKey) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, GJOptionsLayer> : ModifyBase<ModifyDerive<Der, GJOptionsLayer>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, GJOptionsLayer>>;
		using ModifyBase<ModifyDerive<Der, GJOptionsLayer>>::ModifyBase;
		using Base = GJOptionsLayer;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0x29b6d0, Default, GJOptionsLayer)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x29bb20, Default, GJOptionsLayer, create, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x29c570, Default, GJOptionsLayer, setupOptions, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION_ERROR_INLINE(GJOptionsLayer, didToggleGV, gd::string)
			GEODE_APPLY_MODIFY_FOR_FUNCTION_ERROR_INLINE(GJOptionsLayer, didToggle, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x29c580, Default, GJOptionsLayer, addGVToggle, char const*, char const*, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x29cbb0, Default, GJOptionsLayer, addToggle, char const*, int, bool, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x29c6b0, Default, GJOptionsLayer, addToggleInternal, char const*, int, bool, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x29d4f0, Default, GJOptionsLayer, countForPage, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x29c0d0, Default, GJOptionsLayer, goToPage, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x29d000, Default, GJOptionsLayer, incrementCountForPage, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x29d300, Default, GJOptionsLayer, infoKey, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x29bd70, Default, GJOptionsLayer, init, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x29ccc0, Default, GJOptionsLayer, layerForPage, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x29d630, Default, GJOptionsLayer, layerKey, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x29cbc0, Default, GJOptionsLayer, nextPosition, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x29d610, Default, GJOptionsLayer, objectKey, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x29d120, Default, GJOptionsLayer, objectsForPage, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x29c540, Default, GJOptionsLayer, offsetToNextPage, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x29d320, Default, GJOptionsLayer, onInfo, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x29c0b0, Default, GJOptionsLayer, onNextPage, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x29c090, Default, GJOptionsLayer, onPrevPage, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x29ceb0, Default, GJOptionsLayer, onToggle, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x29d5f0, Default, GJOptionsLayer, pageKey, int)
		}
	};
}
