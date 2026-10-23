#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <cocos2d.h>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_endElement
		#define GEODE_STATICS_endElement
		GEODE_AS_STATIC_FUNCTION(endElement) 
	#endif

	#ifndef GEODE_STATICS_startElement
		#define GEODE_STATICS_startElement
		GEODE_AS_STATIC_FUNCTION(startElement) 
	#endif

	#ifndef GEODE_STATICS_textHandler
		#define GEODE_STATICS_textHandler
		GEODE_AS_STATIC_FUNCTION(textHandler) 
	#endif

	#ifndef GEODE_STATICS_init
		#define GEODE_STATICS_init
		GEODE_AS_STATIC_FUNCTION(init) 
	#endif

	#ifndef GEODE_STATICS_parse
		#define GEODE_STATICS_parse
		GEODE_AS_STATIC_FUNCTION(parse) 
	#endif

	#ifndef GEODE_STATICS_setDelegator
		#define GEODE_STATICS_setDelegator
		GEODE_AS_STATIC_FUNCTION(setDelegator) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_endElement
		#define GEODE_CONCEPT_CHECK_endElement
		GEODE_CONCEPT_FUNCTION_CHECK(endElement) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_startElement
		#define GEODE_CONCEPT_CHECK_startElement
		GEODE_CONCEPT_FUNCTION_CHECK(startElement) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_textHandler
		#define GEODE_CONCEPT_CHECK_textHandler
		GEODE_CONCEPT_FUNCTION_CHECK(textHandler) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_init
		#define GEODE_CONCEPT_CHECK_init
		GEODE_CONCEPT_FUNCTION_CHECK(init) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_parse
		#define GEODE_CONCEPT_CHECK_parse
		GEODE_CONCEPT_FUNCTION_CHECK(parse) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setDelegator
		#define GEODE_CONCEPT_CHECK_setDelegator
		GEODE_CONCEPT_FUNCTION_CHECK(setDelegator) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCSAXParser> : ModifyBase<ModifyDerive<Der, cocos2d::CCSAXParser>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCSAXParser>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCSAXParser>>::ModifyBase;
		using Base = cocos2d::CCSAXParser;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0x176090, Default, cocos2d::CCSAXParser, )
			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0x1760b0, Default, cocos2d::CCSAXParser)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x175ff0, Default, cocos2d::CCSAXParser, endElement, void*, cocos2d::CC_XML_CHAR const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x175fa0, Default, cocos2d::CCSAXParser, startElement, void*, cocos2d::CC_XML_CHAR const*, cocos2d::CC_XML_CHAR const**)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x176060, Default, cocos2d::CCSAXParser, textHandler, void*, cocos2d::CC_XML_CHAR const*, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1760c0, Default, cocos2d::CCSAXParser, init, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x176170, Default, cocos2d::CCSAXParser, parse, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x1760d0, Default, cocos2d::CCSAXParser, parse, char const*, unsigned int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x176260, Default, cocos2d::CCSAXParser, setDelegator, cocos2d::CCSAXDelegator*)
		}
	};
}
