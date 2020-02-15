#include "JSONGameValidator.h"
#include <sstream>
#include <iterator>
#include <nlohmann/json.hpp>
#include <iostream>


using json = nlohmann::json;

JSONGAMEValidator::StatusCode JSONGAMEValidator::validGameJson(std::string& jsonString){
  nlohmann::json jsonObject = nlohmann::json::parse(jsonString);
  std::map<std::string, JSONGAMEValidator::GameSpecification>::iterator command;
  size_t jsonGameSpecificationMapSize = jsonGameSpecification.size();
    
  if(jsonGameSpecificationMapSize!=jsonObject.size())
  {
    throw std::invalid_argument("Game Json specifcation invalid. Missing Game specification.");
    return StatusCode::INVALID;
  }
  auto key=  std::find_if(jsonObject.items().begin(), jsonObject.items().end(), [](auto& elem){return jsonGameSpecification.find(elem.key()) == jsonGameSpecification.end();});
  if (key == jsonObject.items().begin()){
      throw std::invalid_argument("Game Json specifcation invalid.");
      return StatusCode::INVALID;
  }
  return StatusCode::VALID;
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

