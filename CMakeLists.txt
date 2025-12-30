cmake_minimum_required(VERSION 3.25)

project(
  RSIM
  VERSION 0.1.0
  LANGUAGES CXX)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
include(cmake/BuildOptions.cmake)
include(cmake/Dependencies.cmake)

add_subdirectory(src)
# Enable testing add_subdirectory(tests)
