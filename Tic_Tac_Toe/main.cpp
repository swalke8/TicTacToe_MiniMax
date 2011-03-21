/* 
 * File:   main.cpp
 * Author: stephenwalker
 *
 * Created on March 15, 2011, 9:37 PM
 */

#include <cstdlib>
#include "Game.h"
#include <CppUTest/CommandLineTestRunner.h>

using namespace std;

/*
 *
 */
int main(int ac, char** av) {

    Game * gameInstance = new Game();
    gameInstance->run();
    return 0;
}

