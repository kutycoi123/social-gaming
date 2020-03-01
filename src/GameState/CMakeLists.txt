add_library(gameState
        GameState.cpp
)

set_target_properties(gameState
        PROPERTIES
        LINKER_LANGUAGE CXX
        CXX_STANDARD 17
        PREFIX ""
)

target_include_directories(
        gameState
        PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries (gameState
        gameSpec        
)