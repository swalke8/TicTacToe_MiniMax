#include "Board.h"
#include "BoardManager.h"
#include <CppUTest/TestHarness.h>

TEST_GROUP(BoardManagerTest)
{
    Board * myBoard;
    BoardManager * manager;

    void setup() {
        myBoard = new Board(3);
        manager = new BoardManager(myBoard);
    }

    void teardown() {
        delete myBoard;
        delete manager;
    }
};

TEST(BoardManagerTest, test)
{
    CHECK_EQUAL(0,0);
}

TEST(BoardManagerTest, testIsValidMoveOnOccupiedSpace)
{
    myBoard->place(0,1);

    CHECK_EQUAL(false, manager->isValidMove(0));
}

TEST(BoardManagerTest, testIsValidMoveWithNegativePosition)
{
    CHECK_EQUAL(false, manager->isValidMove(-1));
}

TEST(BoardManagerTest, testIsValidMoveWithPositionThatIsTooLarge)
{
    CHECK_EQUAL(false, manager->isValidMove(100));
}