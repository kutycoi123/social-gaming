add_library(gameParser GameParser.cpp)

target_include_directories(gameParser
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(gameParser
  nlohmann_json::nlohmann_json
  GameSpec
)