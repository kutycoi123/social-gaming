# CMPT373 - Team Donair

Discord Invite: https://discord.gg/UnsuDv

## How to build and use project
- ## Prerequisites

  - Boost 1.68
  - Ncurses
  - CMake
  - C++17

- ## Building

  - Download the repository, extract the folder to a location you have access to

  - Create a build folder

    - ```
      mkdir build
      cd build
      ```

  - Cmake to the location of the repository folder

    - ```
      sudo cmake PATH_TO_REPOSITORY_FOLDER
      
      Ex.
      sudo cmake /mnt/d/Dropbox/Dropbox/Courses/SPRING2020/CMPT373/social-gaming
      ```

  - Final step

    - ```
      sudo make GameServer
      ```

- ## Using

  - Go to the directory of where you built the project

    - ```
      ./bin/GameServer
      ```

  - Open the .html file and connect using "localhost:4000" or "localhost:4000"

## Project Structure

- ## src/

  - Contains source code and header files that are for internal use

- ## include/

  - Headers that are exposed publicly

- ## lib/

  - Third party libraries

- ## test/

  - Unit testing

## Team Members
- Phan Bui
- Daniel Jui-Che Lin
- Hunsar Sekhon
- Joshua Deans
- Jimmy Zhong
- Matthew Zegar
- Lam Nguyen
- Yuheng Wu

## Build Requirements for Networking Libaries
- C++17 or newer
- Boost >= 1.66 and < 1.72
- CMake >= 3.12
- NCurses (only tested with 6.1)
