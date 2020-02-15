#include<string>
#include<map>

namespace ProcessCommand
{    
    enum CommandType{
        QUIT,
        SHUTDOWN,
        START_GAME,
        CREATE_LOBBY,
        JOIN_LOBBY,
        USERNAME,
        NULL_COMMAND,
    };
    
    static std::map<std::string, CommandType> commands = 
    {
        {"/quit", CommandType::QUIT},
        {"/shutdown", CommandType::SHUTDOWN},
        {"/startgame", CommandType::START_GAME},
        {"/createlobby", CommandType::CREATE_LOBBY},
        {"/joinlobby", CommandType::JOIN_LOBBY},
        {"/username", CommandType::USERNAME}
    };

    CommandType evaluateCommand(std::string&);
};
