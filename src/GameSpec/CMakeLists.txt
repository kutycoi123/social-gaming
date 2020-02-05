
add_subdirectory(include)

add_library(rule
			Rule.cpp
)

target_include_directories(rule 
							PUBLIC
							$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
							$<INSTALL_INTERFACE:include>
)
add_library(gameConfig
			GameConfig.cpp
)

target_include_directories(gameConfig 
							PUBLIC
							$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
							$<INSTALL_INTERFACE:include>
)

target_link_libraries(gameConfig PUBLIC rule)

