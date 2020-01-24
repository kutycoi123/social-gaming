add_library(owner owner.cpp)
target_include_directories(
    owner
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)