add_library(lobby LobbyInfo.cpp SessionInfo.cpp)
target_include_directories(
  chatRoom
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
