add_executable(RSIMapp main.cpp)

target_link_libraries(RSIMapp PRIVATE RSIMCore)
target_include_directories(RSIMapp PUBLIC ${CMAKE_SOURCE_DIR}/src/RSIMCore)
