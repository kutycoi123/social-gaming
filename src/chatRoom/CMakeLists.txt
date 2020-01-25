add_library(ChatRoom chatRoom.cpp)
target_include_directories(
  chatRoom
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
