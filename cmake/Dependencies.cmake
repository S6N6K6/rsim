# -------------------------------------------------------------------
# Declare the dependencies used
# -------------------------------------------------------------------
include(FetchContent)

# Set all downloads to go the vendor library
set(FETCHCONTENT_QUIET FALSE)
set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)
# Add your libraries here as such:
# 1. either with find_package
# find_package(OpenGL REQUIRED)
# 2. Define from where to take it and use it
# FetchContent_Declare(
#   glfw
#   GIT_REPOSITORY https://github.com/glfw/glfw.git
#   GIT_TAG 3.3.9
#
# And then make it available
# FetchContent_MakeAvailable(glfw)
