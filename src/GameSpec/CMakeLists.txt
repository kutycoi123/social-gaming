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
			InputChoice.cpp
			Message.cpp
			Timer.cpp
			Sort.cpp
			Scores.cpp
			InputVote.cpp
			InputText.cpp
			GlobalMessage.cpp
)

set_target_properties(GameSpec
                      PROPERTIES
                      LINKER_LANGUAGE CXX
                      CXX_STANDARD 17
                      PREFIX ""
)

target_include_directories(GameSpec 
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(GameSpec
	GameState
	nlohmann_json::nlohmann_json
)
