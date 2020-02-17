#include "Command.h"
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <iostream>

static std::vector<std::string> splitCommand(const std::string& command){
    std::istringstream iss(command);
    std::vector<std::string> results((std::istream_iterator<std::string>(iss)),
                                 std::istream_iterator<std::string>());
    return results;
}

std::string Command::getAllCommandDescriptions() noexcept{
    std::string str = "";
    
    //is there a better way?
    for(int index = GameServerConfiguration::CommandType::FIRST; index < GameServerConfiguration::CommandType::LAST; index++){
        try{
            str += GameServerConfiguration::command2Description(static_cast<GameServerConfiguration::CommandType> (index)) + "\n";
        } catch (...){
            //do nothing
        } 
    }

    return str;
}

std::vector<std::string> Command::getCommandArguments(const std::string& command) noexcept {
    //TODO: make this more intelligent
    //all this does right now is split commands based on whitespace and remove the command at the 0th position 
    std::vector<std::string> commandParts = splitCommand(command);
    commandParts.erase(commandParts.begin());
    return commandParts;
}

GameServerConfiguration::CommandType Command::getCommandType(const std::string& command) noexcept{
    std::vector<std::string> commandParts = splitCommand(command);

    std::string commandWithoutParameters = commandParts.at(0);

    try{
        return GameServerConfiguration::string2Command(commandWithoutParameters);
    }
    catch (...){    
        return GameServerConfiguration::CommandType::NULL_COMMAND;
    }
    
}

