#include "GameParser.h"
#include "GameConfig.h"


namespace Tags{


}
////public methods
GameParser::GameParser(const std::string& path) :
    hasGame(true) 
    {
    nlohmann::json gameJson = fileToJson(path);
    GameSpecification::GameSpec gameSpec(gameJson);
    GameState gameState = createGameState(gameJson); //GameState(gameJson)

    game = std::make_unique<Game> (gameSpec, gameState);
}

std::unique_ptr<Game> GameParser::getGame() noexcept{
    assert(hasGame);
    hasGame = false;
    return std::move(game);
}

nlohmann::json GameParser::fileToJson(const std::string& pathName) {
    std::ifstream jsonStream(pathName);
    nlohmann::json jsonConfig = nlohmann::json::parse(jsonStream);    
    return jsonConfig;
}

GameState  GameParser::createGameState(nlohmann::json gameJson) {

    GameState gameState;
    //TODO parse configurations
    std::vector<std::string> ec_a;
    auto gameConfig = GameConfig();
    auto config = gameJson.at(CONFIGURATION);
    for(auto a: config){
        if(a.at(NAME)){
            gameConfig.setName(a.at(NAME));
        } else if (a.at(AUDIENCE)) {
            gameConfig.setAudience(a.at(AUDIENCE));
        }
        else if (a.at(PLAYER_COUNT)){
            auto playerCount = Configuration::PlayerCount{a.at(PLAYER_COUNT).at(MAX), a.at(PLAYER_COUNT).at(MIN)};
            gameConfig.setPlayerCount(playerCount);
        }
        else if(a.at(SETUP)){
            //using StateValue
        }
    }
    auto variables = gameJson.at(VARIABLES);
    for(auto a : variables){
        if(a.at(WEAPONS)){
            auto b = a.at(WEAPONS);
            for(auto c : b){
                //gameState.addValue(p.at(NAME), p.at(NAME).type());
                //p.at(BEATS);
            }
        }
    }

    auto perPlayer = gameJson.at(PER_PLAYER).type();
    auto perAudience = gameJson.at(PER_AUDIENCE).type();

    return gameState;

}
