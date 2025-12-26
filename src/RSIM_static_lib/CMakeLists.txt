add_library(RSIM_static_lib STATIC RSIM_static_lib.cpp)
target_include_directories(RSIM_static_lib
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)
