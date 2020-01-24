add_library(User User.cpp)

target_include_directories(
    User
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)