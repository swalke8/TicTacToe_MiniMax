/* 
 * File:   BoardManager.cpp
 * Author: stephenwalker
 * 
 * Created on March 16, 2011, 1:43 PM
 */

#include "BoardManager.h"
#include <iostream.h>

BoardManager::BoardManager(Board * board): gameBoard(board) {
}

BoardManager::BoardManager(const BoardManager& orig) {
}

BoardManager::~BoardManager() {
}

bool BoardManager::isValidMove(int position) {
    EMPTY_SPACE = isEmptySpace(position);
    WITHIN_RANGE = isWithinRange(position);
    displayError();
    return (EMPTY_SPACE && WITHIN_RANGE);
}

bool BoardManager::isEmptySpace(int position) {
    return gameBoard->valueOf(position) == 0;
}

bool BoardManager::isWithinRange(int position) {
    return (position >= 0 && position < gameBoard->getNumCells());
}

void BoardManager::displayError() {
    if (!EMPTY_SPACE)
        cout << "That position is already occupied!" << endl;
    else if (!WITHIN_RANGE)
        cout << "Please choose a row and column value that is between 1 and "<< gameBoard->getSize() << endl;
}