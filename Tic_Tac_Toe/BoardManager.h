/* 
 * File:   BoardManager.h
 * Author: stephenwalker
 *
 * Created on March 16, 2011, 1:43 PM
 */

#ifndef BOARDMANAGER_H
#define	BOARDMANAGER_H

#include "Board.h"

class BoardManager {
public:
    BoardManager(Board *);
    BoardManager(const BoardManager& orig);
    virtual ~BoardManager();

    bool isValidMove(int);
    bool isEmptySpace(int);

private:
    Board * gameBoard;
    bool EMPTY_SPACE;
    bool WITHIN_RANGE;

    bool isWithinRange(int);
    void displayError();
};

#endif	/* BOARDMANAGER_H */

