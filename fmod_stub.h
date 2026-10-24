// Stub FMOD types for iOS cross-compile
#pragma once
typedef int          FMOD_RESULT;
typedef unsigned int FMOD_DEBUG_FLAGS;
typedef unsigned int FMOD_DEBUG_MODE;
typedef unsigned int FMOD_MEMORY_TYPE;
typedef int  (*FMOD_DEBUG_CALLBACK)(FMOD_DEBUG_FLAGS, const char*, int, const char*, const char*);
typedef void*(*FMOD_MEMORY_ALLOC_CALLBACK)(unsigned int, FMOD_MEMORY_TYPE, const char*);
typedef void*(*FMOD_MEMORY_REALLOC_CALLBACK)(void*, unsigned int, FMOD_MEMORY_TYPE, const char*);
typedef void (*FMOD_MEMORY_FREE_CALLBACK)(void*, FMOD_MEMORY_TYPE, const char*);
