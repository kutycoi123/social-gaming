add_subdirectory(lib)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

# Add your test file here
add_executable(runAllTests
    UserTest.cpp
    InvitationTest.cpp
    UserManagerTest.cpp
    GameTest.cpp
    GameSessionTest.cpp
)

# Link the appropriate library
target_link_libraries(runAllTests
        gmock
        gtest
        gtest_main
        user
        invitation
        userManager
        game
        gameSession
)

add_custom_command(TARGET runAllTests POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/Games
        ${PROJECT_BINARY_DIR}/../Games
)

add_test(NAME AllTests COMMAND runAllTests)