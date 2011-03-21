#include "Board.h"
#include <CppUTest/TestHarness.h>

TEST_GROUP(BoardTest)
{
    Board * myBoard;
    void setup() {
        myBoard = new Board(3);
    }
    void teardown() {
        delete myBoard;
    }
};

TEST(BoardTest, test)
{
    CHECK_EQUAL(0,0);
}

TEST(BoardTest, testGetSize)
{
    CHECK_EQUAL(3, myBoard->getSize());
}

TEST(BoardTest, testValueOfEmptySpace)
{
    CHECK_EQUAL(0, myBoard->valueOf(0));
}

TEST(BoardTest, testValueOfOccupiedSpace_AND_Place)
{
    myBoard->place(0, 1);
    CHECK_EQUAL(1, myBoard->valueOf(0));
}
