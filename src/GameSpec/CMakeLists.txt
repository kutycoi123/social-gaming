add_library(GameSpec
			GameSpec.cpp
			GameGeneralConfig.cpp
			Rule.cpp
			Add.cpp
			Deal.cpp
			Discard.cpp
			Extend.cpp
			Foreach.cpp
			Inparallel.cpp
			Loop.cpp
			Parallelfor.cpp
			Reverse.cpp
			Shuffle.cpp
)

target_include_directories(GameSpec 
							PUBLIC
							$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
							$<INSTALL_INTERFACE:include>
)

target_link_libraries(GameSpec
	nlohmann_json::nlohmann_json
)

