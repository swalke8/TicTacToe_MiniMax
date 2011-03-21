/* 
 * File:   Game.h
 * Author: stephenwalker
 *
 * Created on March 17, 2011, 7:14 PM
 */

#ifndef GAME_H
#define	GAME_H

#include "Board.h"
#include "BoardManager.h"
#include "GameObserver.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "MiniMaxComputer.h"

class Game {
public:
    Game();
    Game(const Game& orig);
    virtual ~Game();
    void run();

private:
    Player * player1;
    Player * player2;
    GameObserver * observer;
    Board * gameBoard;
    BoardManager * manager;

    int BOARD_SIZE;

    void promptGameType();
};

#endif	/* GAME_H */

