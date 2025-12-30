# Get the files
file(GLOB_RECURSE SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/RSIM/*.cpp)
file(GLOB_RECURSE HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/RSIM/*.h)
add_library(RSIMCore SHARED ${SOURCE_FILES} ${HEADER_FILES})
# ${CMAKE_CURRENT_SOURCE_DIR}/RSIM.h)

add_library(
  imgui_obj OBJECT
  ${imgui_SOURCE_DIR}/imgui.cpp
  ${imgui_SOURCE_DIR}/imgui_draw.cpp
  ${imgui_SOURCE_DIR}/imgui_tables.cpp
  ${imgui_SOURCE_DIR}/imgui_widgets.cpp
  ${imgui_SOURCE_DIR}/imgui_demo.cpp
  ${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.cpp
  ${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp)

target_include_directories(imgui_obj PUBLIC ${imgui_SOURCE_DIR}
                                            ${imgui_SOURCE_DIR}/backends)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
  target_compile_definitions(RSIMCore PUBLIC RSIM_BUILD_DLL)
endif()
target_compile_definitions(RSIMCore PUBLIC RSIM_ENABLE_ASSERTS)
target_compile_definitions(RSIMCore PUBLIC GLFW_INCLUDE_NONE)
# Use -v to get more build and linking information
# target_compile_options(RSIMCore PUBLIC -v) target_link_options(RSIMCore PUBLIC
# -v)

target_include_directories(RSIMCore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/RSIM)
target_include_directories(RSIMCore PUBLIC ${imgui_SOURCE_DIR}
                                           ${imgui_SOURCE_DIR}/backends)
target_link_libraries(
  RSIMCore PRIVATE OpenGL::GL glfw glad spdlog::spdlog_header_only
                   $<TARGET_OBJECTS:imgui_obj>)
target_link_libraries(
  RSIMCore
  PRIVATE X11
          Xrandr
          Xi
          Xinerama
          Xcursor
          GL
          pthread
          dl
          m)
