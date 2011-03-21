/* 
 * File:   HumanPlayer.cpp
 * Author: stephenwalker
 * 
 * Created on March 16, 2011, 4:22 PM
 */

#include "HumanPlayer.h"
#include <iostream>
using namespace std;

HumanPlayer::HumanPlayer(Board * board, BoardManager * boardManager):
gameBoard(board),
manager(boardManager)
{
}

HumanPlayer::HumanPlayer(const HumanPlayer& orig) {
}

HumanPlayer::~HumanPlayer() {
}

void HumanPlayer::setPlayer(int whichPlayer) {
    player = whichPlayer;
}

void HumanPlayer::makeMove() {
    do {
         askForRow();
         getRow();
         askForColumn();
         getColumn();
         getPosition();
    } while (!manager->isValidMove(position));
    gameBoard->place(position, player);
}

void HumanPlayer::askForRow() {
    cout << "Input a row value: ";
}

void HumanPlayer::askForColumn() {
    cout << "Input a column value: ";
}

void HumanPlayer::getRow() {
    catchBadInput(row);
}

void HumanPlayer::getColumn() {
    catchBadInput(column);
}

void HumanPlayer::catchBadInput(int & value) {
    cin >> value;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        value = -1;
    }
}

void HumanPlayer::getPosition() {
    position = (row-1)*3+(column-1);
}