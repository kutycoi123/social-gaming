#ifndef GAME_SERVER_CONFIGURATION_H
#define GAME_SERVER_CONFIGURATION_H

#include <string>
#include <nlohmann/json.hpp>

namespace GameServerConfiguration{
    enum CommandType{
        FIRST,
        CREATE_SESSION,
        DISCONNECT,
        HELP,
        JOIN_SESSION,
        LEAVE_SESSION,
        SHUTDOWN,
        START_GAME,
        USERNAME,

        NULL_COMMAND,
        LAST,
    };

    static struct Port {
        unsigned short id = 0;
    } port;

    static struct Path{
        std::string path = "";
    } htmlFile, gameFolder;

    void configureServer(const nlohmann::json &configurationFile) noexcept;
    unsigned short getPort() noexcept;
    std::string getHtmlFileContent() noexcept;
    CommandType string2Command(const std::string&);
    std::string command2Description(const CommandType&);
}

#endif