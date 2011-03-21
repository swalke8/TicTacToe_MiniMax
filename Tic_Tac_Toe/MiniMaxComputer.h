/* 
 * File:   MiniMaxComputer.h
 * Author: stephenwalker
 *
 * Created on March 17, 2011, 11:06 AM
 */

#ifndef MINIMAXCOMPUTER_H
#define	MINIMAXCOMPUTER_H

#include "Player.h"
#include "Board.h"
#include "BoardManager.h"
#include "GameObserver.h"

class MiniMaxComputer: public Player {
public:
    MiniMaxComputer(Board *);
    MiniMaxComputer(const MiniMaxComputer& orig);
    virtual ~MiniMaxComputer();
    void setPlayer(int);
    void makeMove();

private:
    int player;
    int opponent;
    int position;
    int numCells;
    //int bestPosition;

    Board * gameBoard;
    GameObserver * observer;

    int performMiniMax(int, int);
};

#endif	/* MINIMAXCOMPUTER_H */

