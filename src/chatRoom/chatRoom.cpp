#include "ChatRoom.h"
#include <list>


  ChatRoom::ChatRoom(const std::string& name, const std::string& id){
    _roomName = name;
    _id = id;
  }

  void ChatRoom::increasePlayerCount() {
    _playerCount++;
  }
  void ChatRoom::decreasePlayerCount() {
    _playerCount--;
  }

  std::string ChatRoom::getRoomName() const{
    return _roomName;
  }

  void ChatRoom::addPlayers(string name){
    _players.push_back(name);
    increasePlayerCount();
  }

  int ChatRoom::getPlayerCount(){
    return _players.size();
  }

  void ChatRoom::removeAllPlayer(){
    _players.clear();
    _playerCount = _players.size();
  }

  std::string ChatRoom::getId(){
    return _id;
  }

  void ChatRoom::setId(const std::string& id){
    _id = id;
  }
