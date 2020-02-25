#include "GameServerConfiguration.h"
#include <unistd.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>

#pragma region PrivateHelperMethods

namespace ConfigurationCommandTags{
    const std::string PORT = "Default Port";
    const std::string HTML_PAGE = "HTML Location";
    const std::string COMMAND_CONFIGURATION = "Commands Configuration";
    const std::string COMMAND_PREFIX_SYMBOL = "Prefix Symbol";
    const std::string COMMAND_LIST = "Command List";
    const std::string COMMAND_TYPE = "Type";
    const std::string COMMAND_DESCRIPTION = "Description";
    const std::string COMMAND_TRIGGER = "User Commands"; 
}

static std::map<std::string, GameServerConfiguration::CommandType> stringToCommandMap;
static std::map<GameServerConfiguration::CommandType, std::string> commandToDescriptionMap;

static void verifyJSON(const nlohmann::json &configurationFile) noexcept{
    //TODO: add check if field actually exist

    auto port = configurationFile.at(ConfigurationCommandTags::PORT);
	//string to short conversion check
	if(port.get<unsigned short>() != port.get<std::intmax_t>()){
		std::cout << "Port out of range\n";
	    std::exit(-1);
	}

	std::string htmlpath = configurationFile.at(ConfigurationCommandTags::HTML_PAGE);
	//html path check for valid file
	if(access(htmlpath.c_str(), R_OK) == -1){
	    std::cout << "Unable to open HTML index file: " << htmlpath << "\n";
        std::exit(-1);
	}

    //... add more checks
}

static std::optional<GameServerConfiguration::CommandType> string2CommandType(const std::string& commandString){

    if(commandString == "CREATE_SESSION"){
        return GameServerConfiguration::CommandType::CREATE_SESSION;
    }
    else if(commandString == "DISCONNECT"){
        return GameServerConfiguration::CommandType::DISCONNECT;
    } 
    else if(commandString == "HELP"){
        return GameServerConfiguration::CommandType::HELP;        
    }
    else if(commandString == "JOIN_SESSION"){
        return GameServerConfiguration::CommandType::JOIN_SESSION;        
    }
    else if(commandString == "LEAVE_SESSION"){
        return GameServerConfiguration::CommandType::LEAVE_SESSION;
    }
    else if(commandString == "SHUTDOWN"){
        return GameServerConfiguration::CommandType::SHUTDOWN;
    }
    else if(commandString == "START_GAME"){
        return GameServerConfiguration::CommandType::START_GAME;
    }
    else if(commandString == "USERNAME"){
        return GameServerConfiguration::CommandType::USERNAME;
    }
    else{
        return std::nullopt;
    }
}

static void configureCommands(const std::string& commandPrefix, const nlohmann::json& commandList){
    for(auto& command : commandList){
        std::string commandTypeString = command.at(ConfigurationCommandTags::COMMAND_TYPE);
        std::optional<GameServerConfiguration::CommandType> type = string2CommandType(commandTypeString);
        
        if(type != std::nullopt){
            std::string commandDescription = command.at(ConfigurationCommandTags::COMMAND_DESCRIPTION);
            commandToDescriptionMap.insert(std::make_pair(type.value(), commandDescription));

            std::vector<std::string> userCommands = command.at(ConfigurationCommandTags::COMMAND_TRIGGER);

            for(auto& commandString : userCommands){
                stringToCommandMap.insert(std::make_pair(commandPrefix + commandString, type.value()));
            }
        }
    }
}

#pragma endregion

void GameServerConfiguration::configureServer(const nlohmann::json &configurationFile) noexcept{
    verifyJSON(configurationFile);
    GameServerConfiguration::port.id = configurationFile[ConfigurationCommandTags::PORT];
    GameServerConfiguration::htmlFile.path = configurationFile[ConfigurationCommandTags::HTML_PAGE];

    std::string commandPrefix = configurationFile[ConfigurationCommandTags::COMMAND_CONFIGURATION][ConfigurationCommandTags::COMMAND_PREFIX_SYMBOL];
    nlohmann::json commandList = configurationFile[ConfigurationCommandTags::COMMAND_CONFIGURATION][ConfigurationCommandTags::COMMAND_LIST];

    configureCommands(commandPrefix, commandList);
}

unsigned short GameServerConfiguration::getPort() noexcept{
    return GameServerConfiguration::port.id;
}

std::string GameServerConfiguration::getHtmlFileContent() noexcept{
    std::ifstream htmlFileStream{GameServerConfiguration::htmlFile.path};

    std::string htmlFileContents{std::istreambuf_iterator<char>(htmlFileStream), std::istreambuf_iterator<char>()};
    
    return htmlFileContents;
}

GameServerConfiguration::CommandType GameServerConfiguration::string2Command(const std::string& input){
    return stringToCommandMap.at(input);
}

std::string GameServerConfiguration::command2Description(const CommandType& input){
    return commandToDescriptionMap.at(input);
}