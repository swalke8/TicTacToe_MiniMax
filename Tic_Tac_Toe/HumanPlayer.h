/* 
 * File:   HumanPlayer.h
 * Author: stephenwalker
 *
 * Created on March 16, 2011, 4:22 PM
 */

#ifndef HUMANPLAYER_H
#define	HUMANPLAYER_H

#include "Player.h"

class HumanPlayer : public Player {
public:
    HumanPlayer(Board *, BoardManager *);
    HumanPlayer(const HumanPlayer& orig);
    virtual ~HumanPlayer();
    void setPlayer(int);
    void makeMove();

private:
    int player;
    int row;
    int column;
    int position;
    Board * gameBoard;
    BoardManager * manager;
    void askForRow();
    void askForColumn();
    void getRow();
    void getColumn();
    void catchBadInput(int &);
    void getPosition();
};

#endif	/* HUMANPLAYER_H */

