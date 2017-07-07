#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Game.h"

int main(int argc, char** argv) {
    std::cout << "CS 261 - Project 1 - Phil Stephenson" << std::endl;

    std::srand(std::time(0));

    Game* chickenfoot = new Game(4);
    chickenfoot->start();

    delete chickenfoot;

    return 0;
}