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

	#ifndef GEODE_STATICS_getTGAInfo
		#define GEODE_STATICS_getTGAInfo
		GEODE_AS_STATIC_FUNCTION(getTGAInfo) 
	#endif

	#ifndef GEODE_STATICS_setTGAInfo
		#define GEODE_STATICS_setTGAInfo
		GEODE_AS_STATIC_FUNCTION(setTGAInfo) 
	#endif

	#ifndef GEODE_STATICS_updateAtlasValues
		#define GEODE_STATICS_updateAtlasValues
		GEODE_AS_STATIC_FUNCTION(updateAtlasValues) 
	#endif

	#ifndef GEODE_STATICS_calculateItemsToRender
		#define GEODE_STATICS_calculateItemsToRender
		GEODE_AS_STATIC_FUNCTION(calculateItemsToRender) 
	#endif

	#ifndef GEODE_STATICS_initWithTileFile
		#define GEODE_STATICS_initWithTileFile
		GEODE_AS_STATIC_FUNCTION(initWithTileFile) 
	#endif

	#ifndef GEODE_STATICS_loadTGAfile
		#define GEODE_STATICS_loadTGAfile
		GEODE_AS_STATIC_FUNCTION(loadTGAfile) 
	#endif

	#ifndef GEODE_STATICS_releaseMap
		#define GEODE_STATICS_releaseMap
		GEODE_AS_STATIC_FUNCTION(releaseMap) 
	#endif

	#ifndef GEODE_STATICS_setTile
		#define GEODE_STATICS_setTile
		GEODE_AS_STATIC_FUNCTION(setTile) 
	#endif

	#ifndef GEODE_STATICS_tileAt
		#define GEODE_STATICS_tileAt
		GEODE_AS_STATIC_FUNCTION(tileAt) 
	#endif

	#ifndef GEODE_STATICS_updateAtlasValueAt
		#define GEODE_STATICS_updateAtlasValueAt
		GEODE_AS_STATIC_FUNCTION(updateAtlasValueAt) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getTGAInfo
		#define GEODE_CONCEPT_CHECK_getTGAInfo
		GEODE_CONCEPT_FUNCTION_CHECK(getTGAInfo) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setTGAInfo
		#define GEODE_CONCEPT_CHECK_setTGAInfo
		GEODE_CONCEPT_FUNCTION_CHECK(setTGAInfo) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_updateAtlasValues
		#define GEODE_CONCEPT_CHECK_updateAtlasValues
		GEODE_CONCEPT_FUNCTION_CHECK(updateAtlasValues) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_calculateItemsToRender
		#define GEODE_CONCEPT_CHECK_calculateItemsToRender
		GEODE_CONCEPT_FUNCTION_CHECK(calculateItemsToRender) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_initWithTileFile
		#define GEODE_CONCEPT_CHECK_initWithTileFile
		GEODE_CONCEPT_FUNCTION_CHECK(initWithTileFile) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_loadTGAfile
		#define GEODE_CONCEPT_CHECK_loadTGAfile
		GEODE_CONCEPT_FUNCTION_CHECK(loadTGAfile) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_releaseMap
		#define GEODE_CONCEPT_CHECK_releaseMap
		GEODE_CONCEPT_FUNCTION_CHECK(releaseMap) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setTile
		#define GEODE_CONCEPT_CHECK_setTile
		GEODE_CONCEPT_FUNCTION_CHECK(setTile) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_tileAt
		#define GEODE_CONCEPT_CHECK_tileAt
		GEODE_CONCEPT_FUNCTION_CHECK(tileAt) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_updateAtlasValueAt
		#define GEODE_CONCEPT_CHECK_updateAtlasValueAt
		GEODE_CONCEPT_FUNCTION_CHECK(updateAtlasValueAt) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCTileMapAtlas> : ModifyBase<ModifyDerive<Der, cocos2d::CCTileMapAtlas>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCTileMapAtlas>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCTileMapAtlas>>::ModifyBase;
		using Base = cocos2d::CCTileMapAtlas;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0x1d674c, Default, cocos2d::CCTileMapAtlas, )
			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0x1d6784, Default, cocos2d::CCTileMapAtlas)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1d61a0, Default, cocos2d::CCTileMapAtlas, create, char const*, char const*, int, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1d6ed0, Default, cocos2d::CCTileMapAtlas, getTGAInfo, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1d6ec8, Default, cocos2d::CCTileMapAtlas, setTGAInfo, cocos2d::sImageTGA*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1d6c8c, Default, cocos2d::CCTileMapAtlas, updateAtlasValues, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1d6604, Default, cocos2d::CCTileMapAtlas, calculateItemsToRender, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1d62ac, Default, cocos2d::CCTileMapAtlas, initWithTileFile, char const*, char const*, int, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1d655c, Default, cocos2d::CCTileMapAtlas, loadTGAfile, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1d6890, Default, cocos2d::CCTileMapAtlas, releaseMap, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1d68cc, Default, cocos2d::CCTileMapAtlas, setTile, cocos2d::ccColor3B const&, cocos2d::CCPoint const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1d6c54, Default, cocos2d::CCTileMapAtlas, tileAt, cocos2d::CCPoint const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1d6a3c, Default, cocos2d::CCTileMapAtlas, updateAtlasValueAt, cocos2d::CCPoint const&, cocos2d::ccColor3B const&, unsigned int)
		}
	};
}
