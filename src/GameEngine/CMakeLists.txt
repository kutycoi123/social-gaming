add_library(gameEngine GameEngine.cpp)

target_include_directories(gameEngine
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(gameEngine
  nlohmann_json::nlohmann_json
  GameSpec
)