#include "Server.h"

#include <nlohmann/json.hpp>
#include <iostream>
#include <string>

int main(int argc, const char* argv[]){

	std::cout << "Hello World!\n";


	nlohmann::json j =
    {
        {"pi", 3.141},
        {"happy", true},
        {"name", "Niels"},
        {"nothing", nullptr},
        {
            "answer", {
                {"everything", 42}
            }
        },
        {"list", {1, 0, 2}},
        {
            "object", {
                {"currency", "USD"},
                {"value", 42.99}
            }
        }
    };
	//Read Json
	

	//Configure Server


	//Select game and prepare lobby
	//Until "Start"
	//Wait until End signal
	//reselect game

	return 0;
}