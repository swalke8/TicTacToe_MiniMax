/* 
 * File:   Board.h
 * Author: stephenwalker
 *
 * Created on March 16, 2011, 11:33 AM
 */

#ifndef BOARD_H
#define	BOARD_H

class Board {
public:
    Board(int);
    Board(const Board& orig);
    virtual ~Board();
    void place(int, int);
    int getSize();
    int getNumCells();
    int valueOf(int);
    void printBoard();

private:
    int SIZE;
    int NUM_CELLS;
    int * gameBoard;
};

#endif	/* BOARD_H */

