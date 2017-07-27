#include <iostream>
#include <memory>
#include "User.h"
#include "Message.h"
#include "FacebookMessage.h"

int main(int argc, char** argv) {
    std::cout << "CS 261 - Project 3 - Phil Stephenson" << std::endl;

    std::shared_ptr<User> user1 = std::make_shared<User>("Phil");
    std::cout << user1->getName() << ":" << user1->getCommPreference() << std::endl;

    std::shared_ptr<User> user2 = std::make_shared<User>("Jon", "facebook");
    std::cout << user2->getName() << ":" << user2->getCommPreference() << std::endl;

    user1->sendMessage(user2, "This is an email message!");

    return 0;
}