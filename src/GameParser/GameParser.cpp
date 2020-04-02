#include "GameParser.h"
#include "GameConfig.h"


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
    
    StateValueMap s;
    std::unordered_map<std::string, std::shared_ptr<StateValue>>  a;
    const std::vector<std::shared_ptr<StateValue>> l;
    for(auto constant : constants.items()){
        if(constant.key() == WEAPONS){
            std::cout << (constant.value().type() == json::value_t::array) << "\n";
            std::cout << constant.value() << "\n";
            gameState.addValue(WEAPONS, StateValueMap(constant.value()), GameState::ValueType::CONSTANT);



            //s = static_cast<StateValueMap>(constant.value().type());
            //std::cout<<constant.value().type_name()<<"\n";

//            for(auto constantValue : constant.value()){
//                //StateValueList(a) = constantValue;
//                std::cout << constantValue << "\n";
//                //a.push_back(constantValue.);
//
//                //gameState.addValue(WEAPONS, StateValueList(), GameState::ValueType::CONSTANT);
//                for(auto r : constantValue.items()){
//                    std::cout << r << "\n";
//                    //gameState.addValue(WEAPONS, s, GameState::ValueType::CONSTANT);
//
//                }
//            }
        }
    }

//    auto perPlayer = gameJson.at(PER_PLAYER).type();
//    auto perAudience = gameJson.at(PER_AUDIENCE).type();

    return gameState;

}
