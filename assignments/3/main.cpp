#include <iostream>
#include <memory>
#include "User.h"
#include "Message.h"
#include "FacebookMessage.h"

int main(int argc, char** argv) {
    std::cout << "CS 261 - Project 3 - Phil Stephenson" << std::endl;

    std::shared_ptr<User> foo = std::make_shared<User>("Foo", "email");
    std::shared_ptr<User> bar = std::make_shared<User>("Bar", "facebook");
    std::shared_ptr<User> baz = std::make_shared<User>("Baz", "text");

    foo->sendMessage(bar, "Hi Bar!");
    baz->sendMessage(bar, "Hey Bar, its Baz here... how are you?", "email");
    bar->readNewMessages();
    bar->readNewMessages(); // Show show 'No new messages!' since we just read them

    return 0;
}