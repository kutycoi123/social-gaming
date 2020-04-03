#include "GameParser.h"
#include "GameConfig.h"
#include <algorithm>

namespace Tags{


}
////public methods
using json = nlohmann::json;
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

    for(auto item : config.items()){
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
        else if(item == SETUP){
            //using StateValue
        }
    }
    auto constants = gameJson.at(CONSTANTS);
    StateValueMap s1;
    StateValueMap s2;
    StateValueMap s3;
    StateValueList l;
    for(const auto& constant : constants.items()){
        if(constant.key() == WEAPONS){
            for(auto constantValue : constant.value()){
                std::cout << constantValue << "\n";

                for(auto r : constantValue.items()){

                    auto e = StateValueString(r.value());

                    if(s1.getMap().size() != 2) {
                        s1.addValue(r.key(), e);
                    }
                    else if(s2.getMap().size()!=2){
                        s2.addValue(r.key(), e);
                    }
                    else if(s3.getMap().size()!=2){
                        s3.addValue(r.key(), e);
                    }
                }
            }
        }
    }
    l.addValue(s1);
    l.addValue(s2);
    l.addValue(s2);

    gameState.addValue(WEAPONS, l, GameState::ValueType::CONSTANT);
    for (auto value: s1.getMap()) {
        std::cout << value.first << " : " << value.second.get() << "\n";
    }
    for (auto value: s2.getMap()) {
        std::cout << value.first << " : " << value.second.get() << "\n";
    }

    for (auto value: s3.getMap()) {
        std::cout << value.first << " : " << value.second.get() << "\n";
    }


    auto variable = gameJson.at(VARIABLES);
    for(auto value: variable.items()){
        if(value.key() == WINNERS){


        }
    }

    auto perPlayer = gameJson.at(PER_PLAYER);
    for(auto pPlayer : perPlayer.items()){
        if(pPlayer.key() == WINS){



        }
    }

    auto perAudience = gameJson.at(PER_AUDIENCE);
    for(auto pPlayer : perPlayer.items()){
        //gameState.addValue(PER_AUDIENCE, static_cast<StateValueMap>(pPlayer.value()), GameState::ValueType::CONSTANT);


    }

//    auto perPlayer = gameJson.at(PER_PLAYER).type();
//    auto perAudience = gameJson.at(PER_AUDIENCE).type();

    return gameState;

}
