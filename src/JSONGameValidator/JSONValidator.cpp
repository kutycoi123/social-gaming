#include "JSONGameValidator.h"
#include <sstream>
#include <iterator>
#include <nlohmann/json.hpp>
#include <iostream>


using json = nlohmann::json;

void JSONGAMEValidator::valideGameJson(std::string& jsonString){
  nlohmann::json jsonObject = nlohmann::json::parse(jsonString);
  std::map<std::string, JSONGAMEValidator::GameSpecification>::iterator command;
    size_t jsonGameSpecificationMapSize = jsonGameSpecification.size();
    if(jsonGameSpecificationMapSize!=jsonObject.size())
    {
        throw std::invalid_argument("Game Json specifcation invalid");
    }
    else{
      for(auto& object : jsonObject.items()){
        command = jsonGameSpecification.find(object.key());
        if(command == jsonGameSpecification.end())
        {
          throw std::invalid_argument("Json Game specifcation invalid");
        }
      }
    }
}

void JSONGAMEValidator::validateConfiguration(std::string& jsonObject){
    json a = json::parse(jsonObject);
    std::map<std::string, JSONGAMEValidator::GameConfiguration>::iterator command;
    command = jsonGameConfiguration.find(a.object());

    //command = jsonGameConfiguration.find(a.object());

    if(command == jsonGameConfiguration.end()){
     throw std::invalid_argument("Json Game specifcation invalid");
    }
}

