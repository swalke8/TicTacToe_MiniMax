/* 
 * File:   Game.cpp
 * Author: stephenwalker
 * 
 * Created on March 17, 2011, 7:14 PM
 */

#include "Game.h"
#include <iostream>

using namespace std;

Game::Game() {
    BOARD_SIZE = 3;
    gameBoard = new Board(BOARD_SIZE);
    manager = new BoardManager(gameBoard);
    observer = new GameObserver(gameBoard);
}

Game::Game(const Game& orig) {
}

Game::~Game() {
}

void Game::run() {
    promptGameType();
}

void Game::promptGameType() {
    int value = 0;

    cout << "Select a game type: " << endl
            << "1. Human vs. Computer" << endl
            << "2. Computer vs. Computer" << endl
            << ": ";
    while (value < 1 || value > 2)
    {
        cin >> value;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            value = -1;
        }
    }

    if (value == 1)
    {
        player1 = new HumanPlayer(gameBoard, manager);
        player2 = new MiniMaxComputer(gameBoard);
    }
    else
    {
        player1 = new MiniMaxComputer(gameBoard);
        player2 = new MiniMaxComputer(gameBoard);
    }

    player1->setPlayer(1);
    player2->setPlayer(-1);

    cout << endl << endl;
    gameBoard->printBoard();
    cout << endl << endl;

    while(true)
    {
        if (!observer->isGameOver())
            player1->makeMove();
        else
            break;
        if(!observer->isGameOver())
            player2->makeMove();
        else
            break;
        gameBoard->printBoard();
        cout << endl << endl;
    }

    gameBoard->printBoard();

    cout << observer->getWinner() << endl;

}

