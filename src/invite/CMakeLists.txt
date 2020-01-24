add_library(invitation Invitation.cpp)
target_include_directories(
    invitation
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)