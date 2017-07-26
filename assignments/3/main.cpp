#include <iostream>
#include "User.h"

int main(int argc, char** argv) {
    std::cout << "CS 261 - Project 3 - Phil Stephenson" << std::endl;

    User* user1 = new User("Phil");
    std::cout << user1->getName() << ":" << user1->getCommPreference() << std::endl;
    delete user1;

    User* user2 = new User("Jon", "facebook");
    std::cout << user2->getName() << ":" << user2->getCommPreference() << std::endl;
    delete user2;

    return 0;
}