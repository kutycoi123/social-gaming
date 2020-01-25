find_package(nlohmann_json 3.2.0 REQUIRED)
add_library(owner owner.cpp)

target_link_libraries(owner PRIVATE nlohmann_json::nlohmann_json)
target_include_directories(owner PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)