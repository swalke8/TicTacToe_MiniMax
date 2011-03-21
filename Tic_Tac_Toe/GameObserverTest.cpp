#include "Board.h"
#include "GameObserver.h"
#include <CppUTest/TestHarness.h>

TEST_GROUP(GameObserverTest)
{
    Board * myBoard;
    GameObserver * observer;

    void setup() {
        myBoard = new Board(3);
        observer = new GameObserver(myBoard);
    }

    void teardown() {
        delete myBoard;
        delete observer;
    }
};

TEST(GameObserverTest, test)
{
    CHECK_EQUAL(0,0);
}

TEST(GameObserverTest, testHasWinnerWithNoWinner)
{
    CHECK_EQUAL(false, observer->isGameOver());
}

TEST(GameObserverTest, testHasWinnerWithHorizontalWin)
{
    myBoard->place(0,1);
    myBoard->place(1,1);
    myBoard->place(2,1);
    
    CHECK_EQUAL(true, observer->isGameOver());
}

TEST(GameObserverTest, testHasWinnerWithHorizontalWin2)
{
    myBoard->place(3,1);
    myBoard->place(4,1);
    myBoard->place(5,1);

    CHECK_EQUAL(true, observer->isGameOver());
}

TEST(GameObserverTest, testHasWinnerWithHorizontalWin3)
{
    myBoard->place(6,1);
    myBoard->place(7,1);
    myBoard->place(8,1);

    CHECK_EQUAL(true, observer->isGameOver());
}

TEST(GameObserverTest, testHasWinnerWithVerticalWin)
{
    myBoard->place(0,1);
    myBoard->place(3,1);
    myBoard->place(6,1);

    CHECK_EQUAL(true, observer->isGameOver());
}

TEST(GameObserverTest, testHasWinnerWithVerticalWin2)
{
    myBoard->place(1,1);
    myBoard->place(4,1);
    myBoard->place(7,1);

    CHECK_EQUAL(true, observer->isGameOver());
}

TEST(GameObserverTest, testHasWinnerWithVerticalWin3)
{
    myBoard->place(2,1);
    myBoard->place(5,1);
    myBoard->place(8,1);

    CHECK_EQUAL(true, observer->isGameOver());
}

TEST(GameObserverTest, testHasWinnerWithDiagonalWinnerLeftToRight)
{
    myBoard->place(0,1);
    myBoard->place(4,1);
    myBoard->place(8,1);

    CHECK_EQUAL(true, observer->isGameOver());
}

TEST(GameObserverTest, testHasWinnerWithDiagonalWinnerRightToLeft)
{
    myBoard->place(2,1);
    myBoard->place(4,1);
    myBoard->place(6,1);

    CHECK_EQUAL(true, observer->isGameOver());
}

TEST(GameObserverTest, testBoardIsFull)
{
    for (int i = 0; i < 9; i++)
        myBoard->place(i, 1);

    CHECK_EQUAL(true, observer->isGameOver());
}

TEST(GameObserverTest, testGetWinnerPlayer1)
{
    myBoard->place(0,1);
    myBoard->place(1,1);
    myBoard->place(2,1);

    CHECK_EQUAL("Player 1 has won!", observer->getWinner());
}