add_executable(GameServer
  GameServer.cpp
)

set_target_properties(GameServer
                      PROPERTIES
                      LINKER_LANGUAGE CXX
                      CXX_STANDARD 17
                      PREFIX ""
)

find_package(Threads REQUIRED)

target_link_libraries(GameServer
  networking
  session
  nlohmann_json::nlohmann_json
  ${CMAKE_THREAD_LIBS_INIT}
)

add_custom_command(TARGET GameServer POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy
                       ${CMAKE_CURRENT_SOURCE_DIR}/ServerProperties.json
                       ${PROJECT_BINARY_DIR}/config/ServerProperties.json
                   )

add_custom_command(TARGET GameServer POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy
                       ${CMAKE_CURRENT_SOURCE_DIR}/webchat.html
                       ${PROJECT_BINARY_DIR}/webchat.html
                   )

install(FILES ServerProperties.json DESTINATION config)

install(TARGETS GameServer
  RUNTIME DESTINATION bin
)

