# -------------------------------------------------------------------
# Declare the dependencies used
# -------------------------------------------------------------------
include(FetchContent)

# Set all downloads to go the vendor library
set(FETCHCONTENT_QUIET FALSE)
set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)

# -------------------------------------------------------------------
# SPDLOG Dependecy
# -------------------------------------------------------------------
message("SPDLOG DEPENDECY START")
set(SPDLOG_BUILD_TESTS
    OFF
    CACHE BOOL "" FORCE)
set(SPDLOG_BUILD_EXAMPLES
    OFF
    CACHE BOOL "" FORCE)
FetchContent_Declare(
  spdlog
  GIT_REPOSITORY https://github.com/gabime/spdlog.git
  GIT_TAG v1.16.0)
FetchContent_MakeAvailable(spdlog)
message("SPDLOG DEPENDECY END")

# -------------------------------------------------------------------
# GLFW Dependecy
# -------------------------------------------------------------------
message("GLFW DEPENDENCY START")
set(GLFW_BUILD_TESTS
    OFF
    CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES
    OFF
    CACHE BOOL "" FORCE)
set(GLFW_BUILD_DOCS
    OFF
    CACHE BOOL "" FORCE)
FetchContent_Declare(
  glfw
  GIT_REPOSITORY https://github.com/glfw/glfw.git
  GIT_TAG 3.3.10)
FetchContent_MakeAvailable(glfw)
message("GLFW DEPENDENCY END")
# -------------------------------------------------------------------
# OpenGL Library Setup
# -------------------------------------------------------------------
find_package(OpenGL REQUIRED)
# -------------------------------------------------------------------
# GLAD Library Setup
# -------------------------------------------------------------------
FetchContent_Declare(
  glad
  GIT_REPOSITORY https://github.com/Dav1dde/glad.git
  GIT_TAG v0.1.36)

FetchContent_MakeAvailable(glad)
# Add your libraries here as such: 1. either with find_package
# find_package(OpenGL REQUIRED) 2. Define from where to take it and use it
# FetchContent_Declare( glfw GIT_REPOSITORY https://github.com/glfw/glfw.git
# GIT_TAG 3.3.9
#
# And then make it available FetchContent_MakeAvailable(glfw)
