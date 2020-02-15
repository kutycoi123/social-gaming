add_library(userlist 
    UserList.cpp
)

target_link_libraries(userlist
    user
    invitation
)

target_include_directories(userlist
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

set_target_properties(userlist
                      PROPERTIES
                      LINKER_LANGUAGE CXX
                      CXX_STANDARD 17
)