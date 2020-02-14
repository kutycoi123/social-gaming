#include "Command.h"
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>

const std::map<std::string, Command::CommandType> Command::stringToCommandMap = 
    {
        {"/disconnect", Command::CommandType::DISCONNECT},
        {"/shutdown", Command::CommandType::SHUTDOWN},
        {"/startgame", Command::CommandType::START_GAME},
        {"/createsession", Command::CommandType::CREATE_SESSION},
        {"/leavesession", Command::CommandType::LEAVE_SESSION},
        {"/joinsession", Command::CommandType::JOIN_SESSION},
        {"/help", Command::CommandType::HELP},
        {"/username", Command::CommandType::USERNAME}
    };

const std::map<Command::CommandType, std::string> Command::commandDescriptions = 
    {
        { Command::CommandType::LEAVE_SESSION, " /leavesession: Leaves your current game session if you are in one\n" },
        { Command::CommandType::DISCONNECT, " /disconnect: Disconnects from the server\n"},
        { Command::CommandType::SHUTDOWN, " /shutdown [invite_code]: Shuts down the provided game session if you are the owner\n"},
        { Command::CommandType::START_GAME, " /startgame [invite_code]: Starts the game within the provided game session\n"},
        { Command::CommandType::CREATE_SESSION, " /createsession [json_game_config]: Changes the current user's username\n"},
        { Command::CommandType::JOIN_SESSION, " /joinsession [invite_code]: Join a game session with the provided invitation code\n"},
        { Command::CommandType::HELP, " /help: Provides a list of valid commands\n"},
        { Command::CommandType::USERNAME, " /user [new_name]: Changes the current user's username\n"}
    };

Command::Command(const std::string& commandString){
    auto originalSplitString = splitCommand(commandString);
    originalCommandString = (originalSplitString.size() > 0) ? originalSplitString[0] : "";
    commandType = evaluateCommand(originalCommandString);
    if (originalSplitString.size() >= 2){
        commandArgument = std::optional<std::string>(originalSplitString[1]);
    } else {
        commandArgument = std::nullopt;
    }
}

Command::CommandType Command::evaluateCommand(std::string& string){
    auto result = stringToCommandMap.find(string);
    return (result == stringToCommandMap.end()) ? NULL_COMMAND : result->second;
}

std::vector<std::string> Command::splitCommand(const std::string& s){
    std::istringstream iss(s);
    std::vector<std::string> results((std::istream_iterator<std::string>(iss)),
                                 std::istream_iterator<std::string>());
    return results;
}

std::optional<std::string> Command::getCommandDescription(Command::CommandType command) const{
    auto description = commandDescriptions.find(command);
    if (description == commandDescriptions.end()){
        return std::nullopt;
    }
    return std::optional<std::string>{description->second};
}

std::string Command::getAllCommandDescriptions() {
    std::string str{};
    std::for_each(commandDescriptions.begin(), commandDescriptions.end(),
        [&str](const std::pair<Command::CommandType, std::string>& pair){str += pair.second;}
    );
    return str;
}

// Note: This may need to eventually return a number of command arguments
std::optional<std::string> Command::getCommandArgument() const {
    return commandArgument;
}

Command::CommandType Command::getCommandType() const {
    return commandType;
}

std::string Command::getCommandAsString() {
    return originalCommandString;
}

bool Command::isFormattedAsACommand(){
    return originalCommandString.find( "/");
}