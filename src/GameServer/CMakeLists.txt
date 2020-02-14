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
  user
  GameSpec
  userlist
  nlohmann_json::nlohmann_json
  command
  GameSessionManager
  ${CMAKE_THREAD_LIBS_INIT}
)

add_custom_command(TARGET GameServer POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy
                       ${CMAKE_CURRENT_SOURCE_DIR}/ServerProperties.json
                       ${PROJECT_BINARY_DIR}/config/ServerProperties.json
                   )

add_custom_command(TARGET GameServer POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy
                       ${CMAKE_CURRENT_SOURCE_DIR}/socialapp.html
                       ${PROJECT_BINARY_DIR}/socialapp.html
                   )

install(FILES ServerProperties.json DESTINATION config)

install(TARGETS GameServer
  RUNTIME DESTINATION bin
)

