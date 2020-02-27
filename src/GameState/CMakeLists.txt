add_library(GameState
        GameState.cpp
        )

set_target_properties(GameState
        PROPERTIES
        LINKER_LANGUAGE CXX
        CXX_STANDARD 17
        PREFIX ""
        )

target_include_directories(
        GameState
        PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries (GameState
#        networking
#        session
        )