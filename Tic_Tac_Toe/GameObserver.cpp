/* 
 * File:   GameObserver.cpp
 * Author: stephenwalker
 * 
 * Created on March 16, 2011, 2:40 PM
 */

#include "GameObserver.h"
#include <stdlib.h>
#include <iostream>

GameObserver::GameObserver(Board * board) : gameBoard(board) {
    player1 = 1;
    player2 = -1;
    winnerValue = 0;
    boardDimension = gameBoard->getSize();
}

GameObserver::GameObserver(const GameObserver& orig) {
}

GameObserver::~GameObserver() {
}

int GameObserver::getPlayerWinner() {
    return winnerValue /= boardDimension;
}

string GameObserver::getWinner()
{
    if (isGameOver())
    {
        winnerValue = getPlayerWinner();

        if (winnerValue==player1)
            return "Player 1 has won!";
        else if (winnerValue==player2)
            return "Player 2 has won!";
        else
            return "Cats game!";
    }
    else
        return "There is no winner!";
}

bool GameObserver::isGameOver() {
    return (hasWinner() || boardIsFull());
}

bool GameObserver::boardIsFull() {
    int value = 0;
    int numCells = gameBoard->getNumCells();

    for (int position = 0; position < numCells; position++)
    {
        value += abs(gameBoard->valueOf(position));
    }

    return value == numCells;
}


bool GameObserver::hasWinner() {

    return (isHorizontalWin()
              || isVerticalWin()
              || isDiagonalWin());
    
}

bool GameObserver::isHorizontalWin() {

    int rowValue;

    for (int row = 0; row < boardDimension; row++)
    {
        rowValue = 0;

        for (int rowIndex = 0; rowIndex < boardDimension; rowIndex++)
            rowValue += gameBoard->valueOf(row*boardDimension + rowIndex);

        if (isWinner(rowValue))
            return true;
    }
    return false;
}

bool GameObserver::isVerticalWin() {

    int columnValue;

    for (int column = 0; column < boardDimension; column++)
    {
        columnValue = 0;

        for (int columnIndex = 0; columnIndex < boardDimension; columnIndex++)
            columnValue += gameBoard->valueOf(column + columnIndex*boardDimension);

        if (isWinner(columnValue))
            return true;
    }
    return false;
}

bool GameObserver::isDiagonalWin() {

    int diagonalValueLeftToRight = 0;
    int diagonalValueRightToLeft = 0;

    for (int index = 0; index < boardDimension; index ++)
    {
        diagonalValueLeftToRight += gameBoard->valueOf(index+index*boardDimension);
        diagonalValueRightToLeft += gameBoard->valueOf(boardDimension-index-1 + index*boardDimension);
    }

    if (isWinner(diagonalValueLeftToRight))
        return true;

    else if (isWinner(diagonalValueRightToLeft))
        return true;
    else
        return false;
}

bool GameObserver::isWinner(int value) {
    if (abs(value) == boardDimension)
    {
        winnerValue = value;
        return true;
    }

    return false;
}

/*
 bool GameObserver::hasWinner() {
    int rowValue;
    int columnValue;
    int diagonalValueLeftToRight = 0;
    int diagonalValueRightToLeft = 0;

    for (int index = 0; index < boardDimension; index++)
    {
        rowValue = 0;
        columnValue = 0;

        for (int index2 = 0; index2 < boardDimension; index2++)
        {
            rowValue += gameBoard->valueOf(index*boardDimension + index2);
            columnValue += gameBoard->valueOf(index + index2*boardDimension);
        }

        if (abs(rowValue) == boardDimension)
        {
            winnerValue = rowValue;
            return true;
        }
        else if (abs(columnValue) == boardDimension)
        {
            winnerValue = columnValue;
            return true;
        }

        diagonalValueLeftToRight += gameBoard->valueOf(index+index*boardDimension);
        diagonalValueRightToLeft += gameBoard->valueOf(boardDimension-index-1 + index*boardDimension);       
    }

    if (abs(diagonalValueLeftToRight) == boardDimension)
    {
        winnerValue = diagonalValueLeftToRight;
        return true;
    }
    else if (abs(diagonalValueRightToLeft) == boardDimension)
    {
        winnerValue = diagonalValueRightToLeft;
        return true;
    }
    return false;
}
 */