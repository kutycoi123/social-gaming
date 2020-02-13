add_library(GameServerConfiguration
  GameServerConfiguration.cpp
)

set_target_properties(GameServerConfiguration
                      PROPERTIES
                      LINKER_LANGUAGE CXX
                      CXX_STANDARD 17
                      PREFIX ""
)

target_include_directories(GameServerConfiguration
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries (GameServerConfiguration
  nlohmann_json::nlohmann_json
)