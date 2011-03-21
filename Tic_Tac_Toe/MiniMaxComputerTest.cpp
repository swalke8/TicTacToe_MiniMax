#include "MiniMaxComputer.h"
#include "Board.h"
#include "BoardManager.h"
#include "GameObserver.h"
#include "HumanPlayer.h"
#include <iostream>
#include <CppUTest/TestHarness.h>

TEST_GROUP(MiniMaxComputerTest)
{
    Board * myBoard;
    BoardManager * boardManager;
    MiniMaxComputer * computerPlayer;
    MiniMaxComputer * computerPlayer2;
    HumanPlayer * humanPlayer;
    GameObserver * observer;

    void setup() {
        myBoard = new Board(3);
        boardManager = new BoardManager(myBoard);
        computerPlayer = new MiniMaxComputer(myBoard);
        computerPlayer2 = new MiniMaxComputer(myBoard);
        humanPlayer = new HumanPlayer(myBoard, boardManager);
        observer = new GameObserver(myBoard);
    }

    void teardown() {
        delete myBoard;
        delete boardManager;
        delete humanPlayer;
        delete computerPlayer;
        delete computerPlayer2;
        delete observer;
    }
};

TEST(MiniMaxComputerTest, test)
{
    CHECK_EQUAL(0,0);
}

TEST(MiniMaxComputerTest, testSituationOne)
{
    myBoard->place(0,1);
    myBoard->place(1,1);
    computerPlayer->setPlayer(1);

    computerPlayer->makeMove();

    CHECK_EQUAL(1, myBoard->valueOf(2));
}

TEST(MiniMaxComputerTest, testSituationTwo)
{
    myBoard->place(0,1);
    myBoard->place(3,1);
    computerPlayer->setPlayer(1);

    computerPlayer->makeMove();

    CHECK_EQUAL(1, myBoard->valueOf(6));
}

void printBoard(Board * myBoard) {
    for (int i = 0; i < 9; i++)
    {
        cout <<"[" << myBoard->valueOf(i) << "]";
        if (i==2 || i ==5 || i == 8)
            cout << endl;
    }
}

TEST(MiniMaxComputerTest, testSituationThree)
{
    computerPlayer->setPlayer(1);
    computerPlayer2->setPlayer(-1);

    computerPlayer->makeMove();
    computerPlayer2->makeMove();
    computerPlayer->makeMove();
    computerPlayer2->makeMove();
    computerPlayer->makeMove();
    computerPlayer2->makeMove();
    computerPlayer->makeMove();
    computerPlayer2->makeMove();
    computerPlayer->makeMove();

    CHECK_EQUAL(0,observer->getPlayerWinner());
}

TEST(MiniMaxComputerTest, testAgainstHuman) {
    humanPlayer->setPlayer(1);
    computerPlayer->setPlayer(-1);
    while (!observer->isGameOver())
    {
        humanPlayer->makeMove();
        if (!observer->isGameOver())
            computerPlayer->makeMove();
        printBoard(myBoard);

    }
}