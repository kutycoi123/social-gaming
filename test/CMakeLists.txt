add_subdirectory(lib)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

# Add your test file here
add_executable(runAllTests
    UserTest.cpp
    UserManager.cpp
)

# Link the appropriate library
target_link_libraries(runAllTests
        gmock
        gtest
        gtest_main
        user
        userManager
)



add_test(NAME AllTests COMMAND runAllTests)