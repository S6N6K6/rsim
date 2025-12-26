add_executable(RSIM_app
    main.cpp
)

target_link_libraries(RSIM_app
    PRIVATE RSIM_static_lib RSIM_shared_lib
)
