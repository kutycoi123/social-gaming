#include "ChatRoom.h"
# include <list>

using namespace std;

class ChatRoomInfo{

  public:
  ChatRoom::ChatRoom(const std::string& name){
    _roomName = name;
  }

  void increasePlayerCount() {
    playerCount++;
  }
  void decreasePlayerCount() {
    playerCount--;
  }

  string getName() const{
    return roomName;
  }

  void addPlayers(string name){

    players.push_back(name);
  }

  int getPlayerCount(){
    return players;
  }

  void removeAllPlayer(){
    players.clear();
  }
