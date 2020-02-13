#ifndef GAME_SERVER_CONFIGURATION_H
#define GAME_SERVER_CONFIGURATION_H

#include <string>
#include <nlohmann/json.hpp>

namespace GameServerConfiguration{
    static struct Port {
        unsigned short id;
    } port;

    static struct Path{
        std::string path;
    } htmlFile, gameFolder;

    void configureServer(const nlohmann::json &configurationFile) noexcept;
    unsigned short getPort() noexcept;
    std::string getHtmlFileContent() noexcept;
}

#endif