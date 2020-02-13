#include "GameServerConfiguration.h"
#include <unistd.h>
#include <fstream>
#include <iostream>

#pragma region PrivateHelperMethods

static void verifyJSON(const nlohmann::json &configurationFile) noexcept{
    //TODO: add check if field actually exist

    auto port = configurationFile.at("DefaultPort");
	//string to short conversion check
	if(port.get<unsigned short>() != port.get<std::intmax_t>()){
		std::cout << "Port out of range\n";
	    std::exit(-1);
	}

	std::string htmlpath = configurationFile.at("HTML Location");
	//html path check for valid file
	if(access(htmlpath.c_str(), R_OK) == -1){
	    std::cout << "Unable to open HTML index file: " << htmlpath << "\n";
        std::exit(-1);
	}

    //... add more checks
}

#pragma endregion

void GameServerConfiguration::configureServer(const nlohmann::json &configurationFile) noexcept{
    verifyJSON(configurationFile);

    GameServerConfiguration::port.id = configurationFile["DefaultPort"];
    GameServerConfiguration::htmlFile.path = configurationFile["HTML Location"];

    //process configurable commands
}

unsigned short GameServerConfiguration::getPort() noexcept{
    return GameServerConfiguration::port.id;
}

std::string GameServerConfiguration::getHtmlFileContent() noexcept{
    std::ifstream htmlFileStream{GameServerConfiguration::htmlFile.path};

    std::string htmlFileContents{std::istreambuf_iterator<char>(htmlFileStream), std::istreambuf_iterator<char>()};
    
    return htmlFileContents;
}

