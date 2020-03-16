add_subdirectory(lib)

# Add your test file here
add_executable(runAllTests
    UserTest.cpp
)

# Link the appropriate library
target_link_libraries(runAllTests
        gmock
        gtest
        gtest_main
        user
)

add_test(NAME AllTests COMMAND runAllTests)