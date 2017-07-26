#include <iostream>
#include "User.h"

int main(int argc, char** argv) {
    std::cout << "CS 261 - Project 3 - Phil Stephenson" << std::endl;

    User* user1 = new User("Phil");
    delete user1;

    return 0;
}