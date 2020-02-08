add_library(GameSpec
			GameSpec.cpp
			GameGeneralConfig.cpp
			Add.cpp
			Deal.cpp
			Discard.cpp
			Extend.cpp
			ForEach.cpp
			Inparallel.cpp
			Loop.cpp
			Parallelfor.cpp
			Reverse.cpp
			Shuffle.cpp
			BaseRule.cpp
			ControlStructRule.cpp
			InputChoiceRule.cpp
			MessageRule.cpp
)

target_include_directories(GameSpec 
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(GameSpec
	nlohmann_json::nlohmann_json

)
