#include "JSONGameValidator.h"
#include <sstream>
#include <iterator>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

void valideGameJson(std::string& jsonObject){
  json a = json::parse(jsonObject);
  std::map<std::string, JSONGAMEValidator::GameSpecification>::iterator command;
  if(!a.empty())
  {
      command = jsonGameSpecification.find(a.items());
      if(command = jsonGameSpecification.end()){
        throw std::invalid_argument("Json Game specifcation invalid");
      }
  }
  else
  {
    throw std::invalid_argument("json file empty");
  }
}

void validateConfiguration(const nlohmann::json& jsonObject){
    std::map<std::string, JSONGAMEValidator::GameSpecification>::iterator command;
    command = jsonGameConfiguration.find(jsonObject.items());
    
    if(command = jsonGameConfiguration.end()){
     throw std::invalid_argument("Json Game specifcation invalid");
    }
}

