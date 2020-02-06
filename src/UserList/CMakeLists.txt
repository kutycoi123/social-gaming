add_library(userlist 
    UserList.cpp
)

target_link_libraries(userlist
  user
)

target_include_directories(userlist
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)