/* 
 * File:   Player.h
 * Author: stephenwalker
 *
 * Created on March 16, 2011, 4:17 PM
 */

#ifndef PLAYER_H
#define	PLAYER_H

#include "Board.h"
#include "BoardManager.h"

class Player {
public:
    Player();
    Player(const Player& orig);
    virtual ~Player();
    virtual void setPlayer(int) = 0;
    virtual void makeMove() = 0;
private:

};

#endif	/* PLAYER_H */

