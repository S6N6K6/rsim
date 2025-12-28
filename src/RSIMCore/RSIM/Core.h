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

#include <cstdint>

constexpr std::uint32_t bit(unsigned int pos) noexcept {
  return std::uint32_t{1} << pos;
}

#ifdef RSIM_ENABLE_ASSERTS
  #define RSIM_ASSERT(x, ...)                                                  \
    {                                                                          \
      if (!(x)) {                                                              \
        RSIM_ERROR("Assertion Failed: {0}", __VA_ARGS__);                      \
      }                                                                        \
    }
  #define RSIM_CORE_ASSERT(x, ...)                                             \
    {                                                                          \
      if (!(x)) {                                                              \
        RSIM_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__);                 \
      }                                                                        \
    }
#else
  #define RSIM_ASSERT(x, ...)
  #define RSIM_CORE_ASSERT(x, ...)
#endif
