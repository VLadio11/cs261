#include <iostream>
#include <memory>
#include "User.h"
#include "Message.h"
#include "TextMessage.h"
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
    baz->readNewMessages();

    std::cout << std::endl;
    std::shared_ptr<Message> msg = std::make_shared<FacebookMessage>("Clone this facebook message", "Phil");
    std::shared_ptr<Message> copy = msg->clone();
    std::cout << *copy << std::endl;

    bar->sendMessage(foo, "Foo: I want to test your copy constructor. Wanna try it? Cool.");
    std::shared_ptr<User> foo_copy = foo;
    foo_copy->readNewMessages();

    std::shared_ptr<Message> m1 = std::make_shared<FacebookMessage>("Is this message identical?", "Bar");
    std::shared_ptr<Message> m2 = std::make_shared<TextMessage>("Is this message identical?", "Foo");
    if (*m1 == *m2) {
        std::cout << "m1 and m2 are equal." << std::endl;
    }

    std::shared_ptr<Message> m3 = std::make_shared<TextMessage>("Let's check inequality...", "Foo");
    if (*m2 != *m3) {
        std::cout << "m2 and m3 are NOT equal." << std::endl;
    }

    // Test binary arithmetic operator overloading
    *m1 += *m2;
    std::cout << *m1 << std::endl;

    return 0;
}