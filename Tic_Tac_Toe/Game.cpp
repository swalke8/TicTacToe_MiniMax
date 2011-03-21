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
    setupGame();
    executeGame();
}

void Game::promptGameType() {
    gameType = 0;

    cout << "Select a game type: " << endl
            << "1. Human vs. Human" << endl
            << "2. Human vs. Computer" << endl
            << "3. Computer vs. Computer" << endl
            << ": ";
    while (gameType < 1 || gameType > 3)
    {
        cin >> gameType;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            gameType = -1;
        }
    }

    if (gameType == 1)
        createHumanVsHumanGame();
    else if (gameType == 2)
        createHumanVsComputerGame();
    else
        createComputerVsComputerGame();
}

void Game::setupGame() {
    player1->setPlayer(1);
    player2->setPlayer(-1);

    cout << endl << endl;
    gameBoard->printBoard();
    cout << endl << endl;
}

void Game::executeGame() {
    while(!observer->isGameOver())
    {
        playerMove();
        displayBoard();
    }

    gameBoard->printBoard();

    displayWinner();
}

void Game::displayWinner() {
    cout << observer->getWinner() << endl;
}

void Game::playerMove() {
    player1->makeMove();
    if (gameType == 1)
        displayBoard();
    if(!observer->isGameOver())
            player2->makeMove();
}

void Game::displayBoard() {
     gameBoard->printBoard();
     cout << endl << endl;
}

void Game::createHumanVsHumanGame() {
    player1 = new HumanPlayer(gameBoard, manager);
    player2 = new HumanPlayer(gameBoard, manager);
}

void Game::createHumanVsComputerGame() {
    player1 = new HumanPlayer(gameBoard, manager);
    player2 = new MiniMaxComputer(gameBoard);
}

void Game::createComputerVsComputerGame() {
    player1 = new MiniMaxComputer(gameBoard);
    player2 = new MiniMaxComputer(gameBoard);
}
