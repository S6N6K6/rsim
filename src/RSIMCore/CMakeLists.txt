# Get the files
file(GLOB SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/RSIM/*.cpp)
file(GLOB HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/RSIM/*.h)
add_library(RSIMCore SHARED ${SOURCE_FILES} ${HEADER_FILES}
                            ${CMAKE_CURRENT_SOURCE_DIR}/RSIM.h)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
  target_compile_definitions(RSIMCore PUBLIC RSIM_BUILD_DLL)
endif()

# Use -v to get more build and linking information
# target_compile_options(RSIM_Core PUBLIC -v) target_link_options(RSIM_Core
# PUBLIC -v)

target_include_directories(RSIMCore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/RSIM)
target_link_libraries(RSIMCore PRIVATE spdlog::spdlog_header_only)
