#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <cocos2d.h>
using namespace geode::modifier;
namespace geode::modifier {
    
    

	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCDictElement> : ModifyBase<ModifyDerive<Der, cocos2d::CCDictElement>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCDictElement>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCDictElement>>::ModifyBase;
		using Base = cocos2d::CCDictElement;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0x29cdf8, Default, cocos2d::CCDictElement, char const*, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0x29ce7c, Default, cocos2d::CCDictElement, intptr_t, cocos2d::CCObject*)
			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0x29ce98, Default, cocos2d::CCDictElement)
		}
	};
}
