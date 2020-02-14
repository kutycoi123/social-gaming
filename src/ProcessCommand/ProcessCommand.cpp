#include "ProcessCommand.h"
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>


ProcessCommand::CommandType ProcessCommand::evaluateCommand(std::string& message){

    std::map<std::string, ProcessCommand::CommandType>::iterator command;

    command = commands.find(message);
    if(command != commands.end())
    {
        return command->second;
    }
    else
    {
        return CommandType::NULL_COMMAND;
    }
}

std::optional<std::string> ProcessCommand::getCommandDescription(CommandType command){
    auto description = commandDescriptions.find(command);
    if (description == commandDescriptions.end()){
        return std::nullopt;
    }
    return std::optional<std::string>{description->second};
}

std::string ProcessCommand::getAllCommandDescriptions(){
    std::string str{};
    std::for_each(commandDescriptions.begin(), commandDescriptions.end(),
        [&str](const std::pair<ProcessCommand::CommandType, std::string>& pair){str += pair.second;}
    );
    return str;
}