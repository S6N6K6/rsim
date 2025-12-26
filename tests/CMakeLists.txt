enable_testing()

add_executable(test_example
    test_example.cpp
)

target_link_libraries(test_example
    PRIVATE RSIM_static_lib
)

add_test(NAME ExampleTest COMMAND
test_example)
