// Stub FMOD types for iOS cross-compile — resolved at runtime by GD
#pragma once
#ifndef FMOD_RESULT
typedef int FMOD_RESULT;
#endif
#ifndef FMOD_DEBUG_MODE
typedef unsigned int FMOD_DEBUG_MODE;
#endif
#ifndef FMOD_DEBUG_FLAGS
typedef unsigned int FMOD_DEBUG_FLAGS;
#endif
typedef int (*FMOD_DEBUG_CALLBACK)(FMOD_DEBUG_FLAGS,const char*,int,const char*,const char*);
typedef void* (*FMOD_MEMORY_ALLOC_CALLBACK)(unsigned int,FMOD_MEMORY_TYPE,const char*);
typedef void* (*FMOD_MEMORY_REALLOC_CALLBACK)(void*,unsigned int,FMOD_MEMORY_TYPE,const char*);
typedef void  (*FMOD_MEMORY_FREE_CALLBACK)(void*,FMOD_MEMORY_TYPE,const char*);
#ifndef FMOD_MEMORY_TYPE
typedef unsigned int FMOD_MEMORY_TYPE;
#endif
