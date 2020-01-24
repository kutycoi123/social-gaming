#include "ChatRoom.h"
# include <list>


class ChatRoomInfo{

  public:
  ChatRoom::ChatRoom(const std::string& name, const std::string& id){
    _roomName = name;
    _id = id;
  }

  void ChatRoom::increasePlayerCount() {
    playerCount++;
  }
  void ChatRoom::decreasePlayerCount() {
    playerCount--;
  }

  std::string ChatRoom::getName() const{
    return roomName;
  }

  void ChatRoom::addPlayers(string name){
    players.push_back(name);
  }

  int ChatRoom::getPlayerCount(){
    return players.size();
  }

  void ChatRoom::removeAllPlayer(){
    players.clear();
  }

  std::string ChatRoom::getId(){
    return _id;
  }

  void ChatRoom::setId(const std::string& id){
    _id = id;
  }
