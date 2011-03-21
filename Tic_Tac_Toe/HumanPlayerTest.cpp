#include "HumanPlayer.h"
#include "Board.h"
#include "BoardManager.h"
#include <CppUTest/TestHarness.h>

TEST_GROUP(HumanPlayerTest)
{
    Board * myBoard;
    BoardManager * manager;
    Player * myPlayer;

    void setup() {
        myBoard = new Board(3);
        manager = new BoardManager(myBoard);
        myPlayer = new HumanPlayer(myBoard, manager);
    }

    void teardown() {
        delete myBoard;
        delete manager;
        delete myPlayer;
    }
};

TEST(HumanPlayerTest, test)
{
    CHECK_EQUAL(0,0);
}
