#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Game.h"

const int NUM_OF_PLAYERS = 4;

int main(int argc, char** argv) {
    std::cout << "CS 261 - Project 1 - Phil Stephenson" << std::endl;

    std::srand(std::time(0));

    Game* chickenfoot = new Game(NUM_OF_PLAYERS);
    std::cout << "A game of ChickenFoot is beginning!" << std::endl;
    chickenfoot->start(DOMINOES_SET_SIZE);

    delete chickenfoot;

    return 0;
}