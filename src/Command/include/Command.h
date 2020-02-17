#ifndef COMMAND_H
#define COMMAND_H

#include "GameServerConfiguration.h"
#include <string>
#include <vector>

namespace Command {
    std::vector<std::string> getCommandArguments(const std::string&) noexcept;
    GameServerConfiguration::CommandType getCommandType(const std::string&) noexcept;
    std::string getAllCommandDescriptions() noexcept;
    
};

#endif