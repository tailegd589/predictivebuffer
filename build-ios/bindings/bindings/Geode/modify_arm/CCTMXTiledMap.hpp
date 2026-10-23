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

	#ifndef GEODE_STATICS_createWithXML
		#define GEODE_STATICS_createWithXML
		GEODE_AS_STATIC_FUNCTION(createWithXML) 
	#endif

	#ifndef GEODE_STATICS_getObjectGroups
		#define GEODE_STATICS_getObjectGroups
		GEODE_AS_STATIC_FUNCTION(getObjectGroups) 
	#endif

	#ifndef GEODE_STATICS_setObjectGroups
		#define GEODE_STATICS_setObjectGroups
		GEODE_AS_STATIC_FUNCTION(setObjectGroups) 
	#endif

	#ifndef GEODE_STATICS_getProperties
		#define GEODE_STATICS_getProperties
		GEODE_AS_STATIC_FUNCTION(getProperties) 
	#endif

	#ifndef GEODE_STATICS_setProperties
		#define GEODE_STATICS_setProperties
		GEODE_AS_STATIC_FUNCTION(setProperties) 
	#endif

	#ifndef GEODE_STATICS_buildWithMapInfo
		#define GEODE_STATICS_buildWithMapInfo
		GEODE_AS_STATIC_FUNCTION(buildWithMapInfo) 
	#endif

	#ifndef GEODE_STATICS_initWithTMXFile
		#define GEODE_STATICS_initWithTMXFile
		GEODE_AS_STATIC_FUNCTION(initWithTMXFile) 
	#endif

	#ifndef GEODE_STATICS_initWithXML
		#define GEODE_STATICS_initWithXML
		GEODE_AS_STATIC_FUNCTION(initWithXML) 
	#endif

	#ifndef GEODE_STATICS_layerNamed
		#define GEODE_STATICS_layerNamed
		GEODE_AS_STATIC_FUNCTION(layerNamed) 
	#endif

	#ifndef GEODE_STATICS_objectGroupNamed
		#define GEODE_STATICS_objectGroupNamed
		GEODE_AS_STATIC_FUNCTION(objectGroupNamed) 
	#endif

	#ifndef GEODE_STATICS_parseLayer
		#define GEODE_STATICS_parseLayer
		GEODE_AS_STATIC_FUNCTION(parseLayer) 
	#endif

	#ifndef GEODE_STATICS_propertiesForGID
		#define GEODE_STATICS_propertiesForGID
		GEODE_AS_STATIC_FUNCTION(propertiesForGID) 
	#endif

	#ifndef GEODE_STATICS_propertyNamed
		#define GEODE_STATICS_propertyNamed
		GEODE_AS_STATIC_FUNCTION(propertyNamed) 
	#endif

	#ifndef GEODE_STATICS_tilesetForLayer
		#define GEODE_STATICS_tilesetForLayer
		GEODE_AS_STATIC_FUNCTION(tilesetForLayer) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_createWithXML
		#define GEODE_CONCEPT_CHECK_createWithXML
		GEODE_CONCEPT_FUNCTION_CHECK(createWithXML) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getObjectGroups
		#define GEODE_CONCEPT_CHECK_getObjectGroups
		GEODE_CONCEPT_FUNCTION_CHECK(getObjectGroups) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setObjectGroups
		#define GEODE_CONCEPT_CHECK_setObjectGroups
		GEODE_CONCEPT_FUNCTION_CHECK(setObjectGroups) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getProperties
		#define GEODE_CONCEPT_CHECK_getProperties
		GEODE_CONCEPT_FUNCTION_CHECK(getProperties) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setProperties
		#define GEODE_CONCEPT_CHECK_setProperties
		GEODE_CONCEPT_FUNCTION_CHECK(setProperties) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_buildWithMapInfo
		#define GEODE_CONCEPT_CHECK_buildWithMapInfo
		GEODE_CONCEPT_FUNCTION_CHECK(buildWithMapInfo) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_initWithTMXFile
		#define GEODE_CONCEPT_CHECK_initWithTMXFile
		GEODE_CONCEPT_FUNCTION_CHECK(initWithTMXFile) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_initWithXML
		#define GEODE_CONCEPT_CHECK_initWithXML
		GEODE_CONCEPT_FUNCTION_CHECK(initWithXML) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_layerNamed
		#define GEODE_CONCEPT_CHECK_layerNamed
		GEODE_CONCEPT_FUNCTION_CHECK(layerNamed) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_objectGroupNamed
		#define GEODE_CONCEPT_CHECK_objectGroupNamed
		GEODE_CONCEPT_FUNCTION_CHECK(objectGroupNamed) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_parseLayer
		#define GEODE_CONCEPT_CHECK_parseLayer
		GEODE_CONCEPT_FUNCTION_CHECK(parseLayer) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_propertiesForGID
		#define GEODE_CONCEPT_CHECK_propertiesForGID
		GEODE_CONCEPT_FUNCTION_CHECK(propertiesForGID) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_propertyNamed
		#define GEODE_CONCEPT_CHECK_propertyNamed
		GEODE_CONCEPT_FUNCTION_CHECK(propertyNamed) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_tilesetForLayer
		#define GEODE_CONCEPT_CHECK_tilesetForLayer
		GEODE_CONCEPT_FUNCTION_CHECK(tilesetForLayer) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCTMXTiledMap> : ModifyBase<ModifyDerive<Der, cocos2d::CCTMXTiledMap>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCTMXTiledMap>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCTMXTiledMap>>::ModifyBase;
		using Base = cocos2d::CCTMXTiledMap;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0x46ee50, Default, cocos2d::CCTMXTiledMap, )
			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0x46eebc, Default, cocos2d::CCTMXTiledMap)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x46e970, Default, cocos2d::CCTMXTiledMap, create, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x46eb48, Default, cocos2d::CCTMXTiledMap, createWithXML, char const*, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x46efbc, Default, cocos2d::CCTMXTiledMap, getObjectGroups, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x46efc4, Default, cocos2d::CCTMXTiledMap, setObjectGroups, cocos2d::CCArray*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x46f000, Default, cocos2d::CCTMXTiledMap, getProperties, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x46f008, Default, cocos2d::CCTMXTiledMap, setProperties, cocos2d::CCDictionary*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x46eca0, Default, cocos2d::CCTMXTiledMap, buildWithMapInfo, cocos2d::CCTMXMapInfo*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x46eadc, Default, cocos2d::CCTMXTiledMap, initWithTMXFile, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x46ec30, Default, cocos2d::CCTMXTiledMap, initWithXML, char const*, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x46f280, Default, cocos2d::CCTMXTiledMap, layerNamed, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x46f334, Default, cocos2d::CCTMXTiledMap, objectGroupNamed, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x46f044, Default, cocos2d::CCTMXTiledMap, parseLayer, cocos2d::CCTMXLayerInfo*, cocos2d::CCTMXMapInfo*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x46f65c, Default, cocos2d::CCTMXTiledMap, propertiesForGID, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x46f558, Default, cocos2d::CCTMXTiledMap, propertyNamed, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x46f170, Default, cocos2d::CCTMXTiledMap, tilesetForLayer, cocos2d::CCTMXLayerInfo*, cocos2d::CCTMXMapInfo*)
		}
	};
}
