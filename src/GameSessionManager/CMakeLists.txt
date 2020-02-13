add_library(GameSessionManager
  GameSessionManager.cpp
)

set_target_properties(GameSessionManager
                      PROPERTIES
                      LINKER_LANGUAGE CXX
                      CXX_STANDARD 17
                      PREFIX ""
)

target_include_directories(
    GameSessionManager
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries (GameSessionManager
  networking
  session
)