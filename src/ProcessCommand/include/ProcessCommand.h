#include<string>
#include<map>
#include <optional>

namespace ProcessCommand
{    
    enum CommandType{
        QUIT,
        SHUTDOWN,
        START_GAME,
        CREATE_LOBBY,
        JOIN_LOBBY,
        USERNAME,
        HELP,
        NULL_COMMAND,
    };
    
    static std::map<std::string, CommandType> commands = 
    {
        {"/quit", CommandType::QUIT},
        {"/shutdown", CommandType::SHUTDOWN},
        {"/startgame", CommandType::START_GAME},
        {"/createlobby", CommandType::CREATE_LOBBY},
        {"/joinlobby", CommandType::JOIN_LOBBY},
        {"/help", CommandType::HELP},
        {"/username", CommandType::USERNAME}
    };

    static std::map<CommandType, std::string> commandDescriptions = 
    {
        { CommandType::QUIT, " /quit: Quits your current game session if you are in one\n"},
        { CommandType::SHUTDOWN, " /shutdown [invite_code]: Shuts down the provided game session if you are the owner\n"},
        { CommandType::START_GAME, " /startgame [invite_code]: Starts the game within the provided game session\n"},
        { CommandType::CREATE_LOBBY, " /createlobby [json_game_config]: Changes the current user's username\n"},
        { CommandType::JOIN_LOBBY, " /joinlobby [invite_code]: Join a game session with the provided invitation code\n"},
        { CommandType::HELP, " /help: Provides a list of valid commands\n"},
        { CommandType::USERNAME, " /user [new_name]: Changes the current user's username\n"}
    };

    CommandType evaluateCommand(std::string&);
    std::optional<std::string> getCommandDescription(CommandType);
    std::string getAllCommandDescriptions();
};
