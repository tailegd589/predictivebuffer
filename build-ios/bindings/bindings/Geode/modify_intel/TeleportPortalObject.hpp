#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <Geode/binding/TeleportPortalObject.hpp>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_create
		#define GEODE_STATICS_create
		GEODE_AS_STATIC_FUNCTION(create) 
	#endif

	#ifndef GEODE_STATICS_setPosition
		#define GEODE_STATICS_setPosition
		GEODE_AS_STATIC_FUNCTION(setPosition) 
	#endif

	#ifndef GEODE_STATICS_setRotation
		#define GEODE_STATICS_setRotation
		GEODE_AS_STATIC_FUNCTION(setRotation) 
	#endif

	#ifndef GEODE_STATICS_setStartPos
		#define GEODE_STATICS_setStartPos
		GEODE_AS_STATIC_FUNCTION(setStartPos) 
	#endif

	#ifndef GEODE_STATICS_customObjectSetup
		#define GEODE_STATICS_customObjectSetup
		GEODE_AS_STATIC_FUNCTION(customObjectSetup) 
	#endif

	#ifndef GEODE_STATICS_getSaveString
		#define GEODE_STATICS_getSaveString
		GEODE_AS_STATIC_FUNCTION(getSaveString) 
	#endif

	#ifndef GEODE_STATICS_addToGroup
		#define GEODE_STATICS_addToGroup
		GEODE_AS_STATIC_FUNCTION(addToGroup) 
	#endif

	#ifndef GEODE_STATICS_removeFromGroup
		#define GEODE_STATICS_removeFromGroup
		GEODE_AS_STATIC_FUNCTION(removeFromGroup) 
	#endif

	#ifndef GEODE_STATICS_setRotation2
		#define GEODE_STATICS_setRotation2
		GEODE_AS_STATIC_FUNCTION(setRotation2) 
	#endif

	#ifndef GEODE_STATICS_addToGroup2
		#define GEODE_STATICS_addToGroup2
		GEODE_AS_STATIC_FUNCTION(addToGroup2) 
	#endif

	#ifndef GEODE_STATICS_removeFromGroup2
		#define GEODE_STATICS_removeFromGroup2
		GEODE_AS_STATIC_FUNCTION(removeFromGroup2) 
	#endif

	#ifndef GEODE_STATICS_getTeleportXOff
		#define GEODE_STATICS_getTeleportXOff
		GEODE_AS_STATIC_FUNCTION(getTeleportXOff) 
	#endif

	#ifndef GEODE_STATICS_init
		#define GEODE_STATICS_init
		GEODE_AS_STATIC_FUNCTION(init) 
	#endif

	#ifndef GEODE_STATICS_setPositionOverride
		#define GEODE_STATICS_setPositionOverride
		GEODE_AS_STATIC_FUNCTION(setPositionOverride) 
	#endif

	#ifndef GEODE_STATICS_setStartPosOverride
		#define GEODE_STATICS_setStartPosOverride
		GEODE_AS_STATIC_FUNCTION(setStartPosOverride) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_create
		#define GEODE_CONCEPT_CHECK_create
		GEODE_CONCEPT_FUNCTION_CHECK(create) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setPosition
		#define GEODE_CONCEPT_CHECK_setPosition
		GEODE_CONCEPT_FUNCTION_CHECK(setPosition) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setRotation
		#define GEODE_CONCEPT_CHECK_setRotation
		GEODE_CONCEPT_FUNCTION_CHECK(setRotation) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setStartPos
		#define GEODE_CONCEPT_CHECK_setStartPos
		GEODE_CONCEPT_FUNCTION_CHECK(setStartPos) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_customObjectSetup
		#define GEODE_CONCEPT_CHECK_customObjectSetup
		GEODE_CONCEPT_FUNCTION_CHECK(customObjectSetup) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getSaveString
		#define GEODE_CONCEPT_CHECK_getSaveString
		GEODE_CONCEPT_FUNCTION_CHECK(getSaveString) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_addToGroup
		#define GEODE_CONCEPT_CHECK_addToGroup
		GEODE_CONCEPT_FUNCTION_CHECK(addToGroup) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_removeFromGroup
		#define GEODE_CONCEPT_CHECK_removeFromGroup
		GEODE_CONCEPT_FUNCTION_CHECK(removeFromGroup) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setRotation2
		#define GEODE_CONCEPT_CHECK_setRotation2
		GEODE_CONCEPT_FUNCTION_CHECK(setRotation2) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_addToGroup2
		#define GEODE_CONCEPT_CHECK_addToGroup2
		GEODE_CONCEPT_FUNCTION_CHECK(addToGroup2) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_removeFromGroup2
		#define GEODE_CONCEPT_CHECK_removeFromGroup2
		GEODE_CONCEPT_FUNCTION_CHECK(removeFromGroup2) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getTeleportXOff
		#define GEODE_CONCEPT_CHECK_getTeleportXOff
		GEODE_CONCEPT_FUNCTION_CHECK(getTeleportXOff) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_init
		#define GEODE_CONCEPT_CHECK_init
		GEODE_CONCEPT_FUNCTION_CHECK(init) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setPositionOverride
		#define GEODE_CONCEPT_CHECK_setPositionOverride
		GEODE_CONCEPT_FUNCTION_CHECK(setPositionOverride) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setStartPosOverride
		#define GEODE_CONCEPT_CHECK_setStartPosOverride
		GEODE_CONCEPT_FUNCTION_CHECK(setStartPosOverride) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, TeleportPortalObject> : ModifyBase<ModifyDerive<Der, TeleportPortalObject>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, TeleportPortalObject>>;
		using ModifyBase<ModifyDerive<Der, TeleportPortalObject>>::ModifyBase;
		using Base = TeleportPortalObject;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1bdb40, Default, TeleportPortalObject, create, char const*, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1bdee0, Default, TeleportPortalObject, setPosition, cocos2d::CCPoint const&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1bdf90, Default, TeleportPortalObject, setRotation, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1bdd40, Default, TeleportPortalObject, setStartPos, cocos2d::CCPoint)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1c0740, Default, TeleportPortalObject, customObjectSetup, gd::vector<gd::string>&, gd::vector<void*>&)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1be0e0, Default, TeleportPortalObject, getSaveString, GJBaseGameLayer*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1be020, Default, TeleportPortalObject, addToGroup, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1be080, Default, TeleportPortalObject, removeFromGroup, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1bdff0, Default, TeleportPortalObject, setRotation2, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1be000, Default, TeleportPortalObject, addToGroup2, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1be010, Default, TeleportPortalObject, removeFromGroup2, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1bde10, Default, TeleportPortalObject, getTeleportXOff, cocos2d::CCNode*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1bdca0, Default, TeleportPortalObject, init, char const*, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1bdd30, Default, TeleportPortalObject, setPositionOverride, cocos2d::CCPoint)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1bdd00, Default, TeleportPortalObject, setStartPosOverride, cocos2d::CCPoint)
		}
	};
}
