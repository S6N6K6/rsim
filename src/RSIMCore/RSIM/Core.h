/*
 * Core macros to define the build behavior
 * */
#pragma once

#if defined(RSIM_PLATFORM_WINDOWS)
  #ifdef RSIM_BUILD_DLL
    #define RSIM_API __declspec(dllexport)
  #else
    #define RSIM_API __declspec(dllimport)
  #endif
#elif defined(RSIM_PLATFORM_LINUX)
  #define RSIM_API
#else
  #error RSIM Supports only Windows and Linux
#endif

