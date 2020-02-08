add_library(gameEngine gameEngine.cpp)

target_include_directories(
     
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

add_subdirectory(gameConfig)