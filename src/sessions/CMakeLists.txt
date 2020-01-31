add_library(session GameSession.cpp GameSessionManager.cpp)
target_include_directories(
  session
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
