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
  ${CMAKE_THREAD_LIBS_INIT}
)

install(TARGETS GameServer
  RUNTIME DESTINATION bin
)