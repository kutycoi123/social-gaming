#include <vector>
#include <stdint.h>
#include <string>

using namespace std;

class ChatRoom{
public:

  ChatRoom(const std::string& name);;
  void addPlayers(const std::string &name);
  string getRoomName() const;
  void increasePlayerCount();
  void decreasePlayerCount();
  int getPlayerCount();
  void removeAllPlayer();
  void leaveChat(std::string &name);

private:
  int _playerCount;
  string _roomName;
  string _welcomeMessage;
  list<string> players;
}
