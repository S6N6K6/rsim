# -------------------------------------------------------------------
# Global Build Options
# -------------------------------------------------------------------

# Set C++ Standard to be C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(ENABLE_WARNINGS "Enable compiler warnings" ON)
option(ENABLE_SANITIZERS "Enable sanitizers (Clang only)" OFF)
option(ENABLE_LTO "Enable link-time optimization" OFF)

# Default build type for single-config generators
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE
      Release
      CACHE STRING "" FORCE)
endif()

# Check if the generator allows writting the compile_commands.json file
if(CMAKE_GENERATOR MATCHES "Ninja|Makefiles")
  set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
endif()

# -------------------------------------------------------------------
# Platform specific configuration
# -------------------------------------------------------------------
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
  add_compile_definitions(RSIM_PLATFORM_WINDOWS)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
  add_compile_definitions(RSIM_PLATFORM_LINUX)
else()
  message(WARNING "System not supported")
endif()

# -------------------------------------------------------------------
# Compiler specific configuration
# -------------------------------------------------------------------
if(MSVC)
  message(STATUS "Configuration build options for MSVC")

  if(ENABLE_WARNINGS)
    add_compile_options(/W4 /permissive-)
  endif()
  # Use modern MSVC runtime handling
  set(CMAKE_MSVC_RUNTIME_LIBRARY
      "MultiThreaded$<$<CONFIG:Debug>:Debug>"
      CACHE STRING "" FORCE)

elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  message(STATUS "Configuring build options for Clang")

  # Make c++ 23 work
  add_compile_options(-stdlib=libc++)
  add_link_options(-stdlib=libc++)

  if(ENABLE_WARNINGS)
    add_compile_options(-Wall -Wextra -Wpedantic)
  endif()

  if(ENABLE_SANITIZERS)
    add_compile_options(-fsanitize=address,undefined)
    add_link_options(-fsanitize=address,undefined)
  endif()

elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  message(STATUS "Configuring build options for GCC")

  if(ENABLE_WARNINGS)
    add_compile_options(-Wall -Wextra -Wpedantic)
  endif()

else()
  message(WARNING "Unknown compiler: ${CMAKE_CXX_COMPILER_ID}")

endif()

# -------------------------------------------------------------------
# Link-time optimization (cross-compiler)
# -------------------------------------------------------------------
if(ENABLE_LTO)
  include(CheckIPOSupported)
  check_ipo_supported(RESULT ipo_supported OUTPUT ipo_error)

  if(ipo_supported)
    set(CMAKE_INTERPROCEDURAL_OPTIMIZATION ON)
  else()
    message(WARNING "IPO/LTO not supported: ${ipo_error}")
  endif()
endif()
