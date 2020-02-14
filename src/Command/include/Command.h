#ifndef PROCESS_COMMAND_H
#define PROCESS_COMMAND_H

#include <string>
#include <map>
#include <optional>
#include <vector>

class Command {
    public:
        enum CommandType{
            DISCONNECT,
            SHUTDOWN,
            START_GAME,
            CREATE_SESSION,
            JOIN_SESSION,
            LEAVE_SESSION,
            USERNAME,
            HELP,
            NULL_COMMAND,
        };
        Command(const std::string& s);
        bool isCommandArgumentPresent();
        bool isFormattedAsACommand();
        std::optional<std::string> getCommandArgument() const;
        CommandType getCommandType() const;
        std::string getCommandAsString();
        std::optional<std::string> getCommandDescription(CommandType commandType) const;
        static std::string getAllCommandDescriptions();
    private:
        std::vector<std::string> splitCommand(const std::string& s);
        std::string originalCommandString;
        const static std::map<std::string, CommandType> stringToCommandMap;
        const static std::map<CommandType, std::string> commandDescriptions;
        CommandType evaluateCommand(std::string& string);
        CommandType commandType;
        std::optional<std::string> commandArgument;
};

#endif