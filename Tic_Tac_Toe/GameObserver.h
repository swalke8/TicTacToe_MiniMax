/* 
 * File:   GameObserver.h
 * Author: stephenwalker
 *
 * Created on March 16, 2011, 2:40 PM
 */

#ifndef GAMEOBSERVER_H
#define	GAMEOBSERVER_H

#include "Board.h"
#include <string>

using namespace std;

class GameObserver {
public:
    GameObserver(Board *);
    GameObserver(const GameObserver& orig);
    virtual ~GameObserver();

    bool isGameOver();
    string getWinner();
    int getPlayerWinner();

private:
    int player1;
    int player2;
    int winnerValue;
    int boardDimension;
    Board * gameBoard;

    bool boardIsFull();
    bool hasWinner();
    bool isHorizontalWin();
    bool isVerticalWin();
    bool isDiagonalWin();
    bool isWinner(int);
};

#endif	/* GAMEOBSERVER_H */

