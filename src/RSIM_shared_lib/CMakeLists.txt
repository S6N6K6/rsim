add_library(RSIM_shared_lib SHARED 
    RSIM_shared_lib.cpp
)

target_include_directories(RSIM_shared_lib
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)
