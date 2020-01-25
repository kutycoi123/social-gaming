#include <vector>
#include <stdint.h>
#include <string>


class ChatRoom{
public:

  ChatRoom(const std::string& roomName, const std::string& id);
  void addPlayers(const std::string &name);
  std::string getRoomName() const;
  void setName(const std::string& name);
  void setId(const std::string& id);
  void increasePlayerCount();
  void decreasePlayerCount();
  int getPlayerCount();
  void removeAllPlayer();

private:
  int _playerCount;
  std::string _id;
  string _roomName;
  string _welcomeMessage;
  list<string> _players;
}
