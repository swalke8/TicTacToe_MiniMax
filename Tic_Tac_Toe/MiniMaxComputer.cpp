/* 
 * File:   MiniMaxComputer.cpp
 * Author: stephenwalker
 * 
 * Created on March 17, 2011, 11:06 AM
 */

#include "MiniMaxComputer.h"
#include <iostream>

MiniMaxComputer::MiniMaxComputer(Board * board):
gameBoard(board)
{
    numCells = gameBoard->getNumCells();
    observer = new GameObserver(gameBoard);
}

MiniMaxComputer::MiniMaxComputer(const MiniMaxComputer& orig) {
}

MiniMaxComputer::~MiniMaxComputer() {
}

void MiniMaxComputer::setPlayer(int whichPlayer) {
    player = whichPlayer;
    opponent = -player;
}

void MiniMaxComputer::makeMove() {
    int tempValue = 0;
    int ctr = 0;
    int maxValue = 0;
    int bestPosition = 0;
    for (int index = 0; index < numCells; index++)
    {
        if (gameBoard->valueOf(index) == 0)
        {
            gameBoard->place(index, player);
            if (!observer->isGameOver())
            {
                tempValue = performMiniMax(opponent, 0);
                gameBoard->place(index, 0);

                if (tempValue > maxValue || ctr == 0)
                {
                      maxValue = tempValue;
                      bestPosition = index;
                      ctr++;
                }
            }
            else
            {
                bestPosition = index;
                break;
            }
        }
    }
    gameBoard->place(bestPosition, player);
}

int MiniMaxComputer::performMiniMax(int whichPlayer, int value) {
    int outcome = 0;
    int winner = 0;
    int ctr = 0;
    for (int index = 0; index < numCells; index++)
    {
        if (gameBoard->valueOf(index) == 0)
        {
            gameBoard->place(index, whichPlayer);
            if (!observer->isGameOver())
                outcome += performMiniMax(-whichPlayer, value);
            else
            {
                winner = observer->getPlayerWinner();
                if (winner == player)
                    outcome++;
                else if (winner == opponent)
                    outcome--;
            }
            if (outcome > value || ctr == 0)
            {
                 value = outcome;
                 ctr++;
            }
            gameBoard->place(index, 0);
        }
    }
    return value;
}