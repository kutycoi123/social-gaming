#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Game.h"

class GameTest : public testing::Test {
public:
    Game* game;

    GameTest() {
        game = new Game(GameSpecification::GameSpec("../TestGames/Test.json"), GameState());
    }

    ~GameTest() {
        delete game;
    }
};

TEST_F(GameTest, isGameStarted) {
    EXPECT_FALSE(game->isStarted());

    std::list<std::weak_ptr<User>> users;
    game->startGame(users, users);

    EXPECT_TRUE(game->isStarted());
}

TEST_F(GameTest, startGame) {
    std::list<std::weak_ptr<User>> users;
    game->startGame(users, users);

    EXPECT_TRUE(game->isStarted());
}

TEST_F(GameTest, endGame) {
    std::list<std::weak_ptr<User>> users;
    game->startGame(users, users);
    game->endGame();

    EXPECT_FALSE(game->isStarted());
}

TEST_F(GameTest, addMessages) {
    std::string message = "TestMessage";
    game->addMessages(message);
    std::list<std::string> messages = game->updateAndGetAllMessages();
    EXPECT_EQ(messages.front(), message);
}

TEST_F(GameTest, updateAndGetAllMessages) {
    std::string message1 = "TestMessage1";
    std::string message2 = "TestMessage2";
    std::string message3 = "TestMessage3";

    game->addMessages(message1);
    game->addMessages(message2);

    std::list<std::string> messages = game->updateAndGetAllMessages();
    EXPECT_EQ(messages.size(), 2);
    EXPECT_EQ(messages.front(), message1);
    EXPECT_EQ(messages.back(), message2);

    game->addMessages(message3);

    messages = game->updateAndGetAllMessages();
    EXPECT_EQ(messages.size(), 1);
    EXPECT_EQ(messages.front(), message3);
}

TEST_F(GameTest, gameTick) {
    // TODO: Update test once able to
    game->gameTick();
    EXPECT_FALSE(game->isStarted());
}