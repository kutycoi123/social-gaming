#include "GameParser.h"
#include "GameConfig.h"
#include <algorithm>

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
    auto gameConfig = GameConfig();
    auto config = gameJson.at(CONFIGURATION);

    for(const auto& item : config.items()){
        if(item.key() == NAME){
            gameConfig.setName(item.value());
        }
        else if (item.key() == AUDIENCE) {
            gameConfig.setAudience(item.value());
        }
        else if (item.key() == PLAYER_COUNT){
            auto playerCount = Configuration::PlayerCount{item.value().at(MAX), item.value().at(MIN)};
            gameConfig.setPlayerCount(playerCount);
        }
        else if(item.key() == SETUP){
            Setup setup = item.value();
            gameConfig.setSetup(setup);
        }
    }
    auto constants = gameJson.at(CONSTANTS);
    StateValueMap map1;
    StateValueMap map2;
    StateValueMap map3;
    StateValueMap map4;
    StateValueMap map5;
    StateValueList list1;
    StateValueList list2;
    for(const auto& constant : constants.items()){
        if(constant.key() == WEAPONS){
            for(auto constantValue : constant.value()){
                std::cout << constantValue << "\n";

                for(const auto r : constantValue.items()){

                    auto e = StateValueString(r.value());

                    if(map1.getMap().size() != 2) {
                        map1.addValue(r.key(), e);
                    }
                    else if(map2.getMap().size()!=2){
                        map2.addValue(r.key(), e);
                    }
                    else if(map3.getMap().size()!=2){
                        map3.addValue(r.key(), e);
                    }
                }
            }
        }
    }
    list1.addValue(map1);
    list1.addValue(map2);
    list1.addValue(map3);

    gameState.addValue(WEAPONS, list1, GameState::ValueType::CONSTANT);


    auto variable = gameJson.at(VARIABLES);
    for(const auto& value: variable.items()){
        if(value.key() == WINNERS){
            auto s = value.value();
            list1.addValue(map4);
            gameState.addValue(WINNERS, list1, GameState::ValueType::VARIABLE);
        }
    }

    auto perPlayer = gameJson.at(PER_PLAYER);
    for(const auto& pPlayer : perPlayer.items()){
        if(pPlayer.key() == WINS){
            auto num = static_cast<int>(pPlayer.value());
            gameState.addValue(WINS, StateValueNumber(num), GameState::ValueType::PER_PLAYER);
        }
    }

    auto perAudience = gameJson.at(PER_AUDIENCE);
    for(const auto& pAudience : perPlayer.items()){
        gameState.addValue("",StateValueMap(map5),GameState::ValueType::PER_AUDIENCE);
    }

    return gameState;

}
