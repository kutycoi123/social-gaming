#include "ProcessCommand.h"
#include <vector>
#include <sstream>
#include <iterator>


ProcessCommand::CommandType ProcessCommand::evaluateCommand(std::string& message){

    std::map<std::string, ProcessCommand::CommandType>::iterator command;

    command = commands.find(message);
    if(command != commands.end())
    {
        return userCommand = command->second;
    }
    else
    {
        return userCommand = CommandType::NULL_COMMAND;
    }
}

