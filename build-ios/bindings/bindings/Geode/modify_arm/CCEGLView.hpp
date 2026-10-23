#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <cocos2d.h>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_sharedOpenGLView
		#define GEODE_STATICS_sharedOpenGLView
		GEODE_AS_STATIC_FUNCTION(sharedOpenGLView) 
	#endif

	#ifndef GEODE_STATICS_end
		#define GEODE_STATICS_end
		GEODE_AS_STATIC_FUNCTION(end) 
	#endif

	#ifndef GEODE_STATICS_swapBuffers
		#define GEODE_STATICS_swapBuffers
		GEODE_AS_STATIC_FUNCTION(swapBuffers) 
	#endif

	#ifndef GEODE_STATICS_isOpenGLReady
		#define GEODE_STATICS_isOpenGLReady
		GEODE_AS_STATIC_FUNCTION(isOpenGLReady) 
	#endif

	#ifndef GEODE_STATICS_setIMEKeyboardState
		#define GEODE_STATICS_setIMEKeyboardState
		GEODE_AS_STATIC_FUNCTION(setIMEKeyboardState) 
	#endif

	#ifndef GEODE_STATICS_setContentScaleFactor
		#define GEODE_STATICS_setContentScaleFactor
		GEODE_AS_STATIC_FUNCTION(setContentScaleFactor) 
	#endif

	#ifndef GEODE_STATICS_setViewPortInPoints
		#define GEODE_STATICS_setViewPortInPoints
		GEODE_AS_STATIC_FUNCTION(setViewPortInPoints) 
	#endif

	#ifndef GEODE_STATICS_setScissorInPoints
		#define GEODE_STATICS_setScissorInPoints
		GEODE_AS_STATIC_FUNCTION(setScissorInPoints) 
	#endif

	#ifndef GEODE_STATICS_setMultiTouchMask
		#define GEODE_STATICS_setMultiTouchMask
		GEODE_AS_STATIC_FUNCTION(setMultiTouchMask) 
	#endif

	#ifndef GEODE_STATICS_showCursor
		#define GEODE_STATICS_showCursor
		GEODE_AS_STATIC_FUNCTION(showCursor) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_sharedOpenGLView
		#define GEODE_CONCEPT_CHECK_sharedOpenGLView
		GEODE_CONCEPT_FUNCTION_CHECK(sharedOpenGLView) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_end
		#define GEODE_CONCEPT_CHECK_end
		GEODE_CONCEPT_FUNCTION_CHECK(end) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_swapBuffers
		#define GEODE_CONCEPT_CHECK_swapBuffers
		GEODE_CONCEPT_FUNCTION_CHECK(swapBuffers) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_isOpenGLReady
		#define GEODE_CONCEPT_CHECK_isOpenGLReady
		GEODE_CONCEPT_FUNCTION_CHECK(isOpenGLReady) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setIMEKeyboardState
		#define GEODE_CONCEPT_CHECK_setIMEKeyboardState
		GEODE_CONCEPT_FUNCTION_CHECK(setIMEKeyboardState) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setFrameSize
		#define GEODE_CONCEPT_CHECK_setFrameSize
		GEODE_CONCEPT_FUNCTION_CHECK(setFrameSize) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setContentScaleFactor
		#define GEODE_CONCEPT_CHECK_setContentScaleFactor
		GEODE_CONCEPT_FUNCTION_CHECK(setContentScaleFactor) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setViewPortInPoints
		#define GEODE_CONCEPT_CHECK_setViewPortInPoints
		GEODE_CONCEPT_FUNCTION_CHECK(setViewPortInPoints) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setScissorInPoints
		#define GEODE_CONCEPT_CHECK_setScissorInPoints
		GEODE_CONCEPT_FUNCTION_CHECK(setScissorInPoints) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setMultiTouchMask
		#define GEODE_CONCEPT_CHECK_setMultiTouchMask
		GEODE_CONCEPT_FUNCTION_CHECK(setMultiTouchMask) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_showCursor
		#define GEODE_CONCEPT_CHECK_showCursor
		GEODE_CONCEPT_FUNCTION_CHECK(showCursor) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_initGlew
		#define GEODE_CONCEPT_CHECK_initGlew
		GEODE_CONCEPT_FUNCTION_CHECK(initGlew) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onGLFWCharCallback
		#define GEODE_CONCEPT_CHECK_onGLFWCharCallback
		GEODE_CONCEPT_FUNCTION_CHECK(onGLFWCharCallback) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onGLFWCursorEnterFunCallback
		#define GEODE_CONCEPT_CHECK_onGLFWCursorEnterFunCallback
		GEODE_CONCEPT_FUNCTION_CHECK(onGLFWCursorEnterFunCallback) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onGLFWDeviceChangeFunCallback
		#define GEODE_CONCEPT_CHECK_onGLFWDeviceChangeFunCallback
		GEODE_CONCEPT_FUNCTION_CHECK(onGLFWDeviceChangeFunCallback) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onGLFWError
		#define GEODE_CONCEPT_CHECK_onGLFWError
		GEODE_CONCEPT_FUNCTION_CHECK(onGLFWError) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onGLFWframebuffersize
		#define GEODE_CONCEPT_CHECK_onGLFWframebuffersize
		GEODE_CONCEPT_FUNCTION_CHECK(onGLFWframebuffersize) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onGLFWKeyCallback
		#define GEODE_CONCEPT_CHECK_onGLFWKeyCallback
		GEODE_CONCEPT_FUNCTION_CHECK(onGLFWKeyCallback) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onGLFWMouseCallBack
		#define GEODE_CONCEPT_CHECK_onGLFWMouseCallBack
		GEODE_CONCEPT_FUNCTION_CHECK(onGLFWMouseCallBack) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onGLFWMouseMoveCallBack
		#define GEODE_CONCEPT_CHECK_onGLFWMouseMoveCallBack
		GEODE_CONCEPT_FUNCTION_CHECK(onGLFWMouseMoveCallBack) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onGLFWMouseScrollCallback
		#define GEODE_CONCEPT_CHECK_onGLFWMouseScrollCallback
		GEODE_CONCEPT_FUNCTION_CHECK(onGLFWMouseScrollCallback) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onGLFWWindowIconifyFunCallback
		#define GEODE_CONCEPT_CHECK_onGLFWWindowIconifyFunCallback
		GEODE_CONCEPT_FUNCTION_CHECK(onGLFWWindowIconifyFunCallback) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onGLFWWindowPosCallback
		#define GEODE_CONCEPT_CHECK_onGLFWWindowPosCallback
		GEODE_CONCEPT_FUNCTION_CHECK(onGLFWWindowPosCallback) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onGLFWWindowSizeFunCallback
		#define GEODE_CONCEPT_CHECK_onGLFWWindowSizeFunCallback
		GEODE_CONCEPT_FUNCTION_CHECK(onGLFWWindowSizeFunCallback) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_performSafeClipboardPaste
		#define GEODE_CONCEPT_CHECK_performSafeClipboardPaste
		GEODE_CONCEPT_FUNCTION_CHECK(performSafeClipboardPaste) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_pollEvents
		#define GEODE_CONCEPT_CHECK_pollEvents
		GEODE_CONCEPT_FUNCTION_CHECK(pollEvents) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_pumpRawInput
		#define GEODE_CONCEPT_CHECK_pumpRawInput
		GEODE_CONCEPT_FUNCTION_CHECK(pumpRawInput) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setupWindow
		#define GEODE_CONCEPT_CHECK_setupWindow
		GEODE_CONCEPT_FUNCTION_CHECK(setupWindow) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_toggleFullScreen
		#define GEODE_CONCEPT_CHECK_toggleFullScreen
		GEODE_CONCEPT_FUNCTION_CHECK(toggleFullScreen) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_toggleLockCursor
		#define GEODE_CONCEPT_CHECK_toggleLockCursor
		GEODE_CONCEPT_FUNCTION_CHECK(toggleLockCursor) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCEGLView> : ModifyBase<ModifyDerive<Der, cocos2d::CCEGLView>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCEGLView>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCEGLView>>::ModifyBase;
		using Base = cocos2d::CCEGLView;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_CONSTRUCTOR(base::get() + 0x45b284, Default, cocos2d::CCEGLView, )
			GEODE_APPLY_MODIFY_FOR_DESTRUCTOR(base::get() + 0x45b2d4, Default, cocos2d::CCEGLView)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x45b214, Default, cocos2d::CCEGLView, sharedOpenGLView, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x45b358, Default, cocos2d::CCEGLView, end, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x45b3b0, Default, cocos2d::CCEGLView, swapBuffers, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x45b32c, Default, cocos2d::CCEGLView, isOpenGLReady, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x45b3e8, Default, cocos2d::CCEGLView, setIMEKeyboardState, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x45b350, Default, cocos2d::CCEGLView, setContentScaleFactor, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x45b420, Default, cocos2d::CCEGLView, setViewPortInPoints, float, float, float, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x45b4c8, Default, cocos2d::CCEGLView, setScissorInPoints, float, float, float, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x45b570, Default, cocos2d::CCEGLView, setMultiTouchMask, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(base::get() + 0x45b574, Default, cocos2d::CCEGLView, showCursor, bool)
		}
	};
}
