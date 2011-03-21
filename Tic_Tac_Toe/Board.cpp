/* 
 * File:   Board.cpp
 * Author: stephenwalker
 * 
 * Created on March 16, 2011, 11:33 AM
 */

#include "Board.h"
#include <Math.h>
#include <iostream>
using namespace std;

Board::Board(int setSize) {
    SIZE = setSize;
    NUM_CELLS = SIZE*SIZE;
    gameBoard = new int[NUM_CELLS];
    for (int position = 0; position < NUM_CELLS; position++)
        gameBoard[position] = 0;
}

Board::Board(const Board& orig) {
}

Board::~Board() {
    delete [] gameBoard;
}

void Board::place(int position, int player) {
    gameBoard[position] = player;
}

int Board::getSize() {
    return SIZE;
}

int Board::getNumCells() {
    return NUM_CELLS;
}

int Board::valueOf(int position) {
    return gameBoard[position];
}

void Board::printBoard() {
    for (int i = 0; i < NUM_CELLS; i++)
    {
        cout <<"[";
        if (valueOf(i) == 1)
            cout << "X";
        else if (valueOf(i) == 0)
            cout << " ";
        else
            cout << "O";
        cout << "]";
        if (i==2 || i ==5 || i == 8)
            cout << endl;
    }
}
