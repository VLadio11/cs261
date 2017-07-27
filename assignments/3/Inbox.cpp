#include "Inbox.h"
#include <iostream>

Inbox::Inbox() {}

Inbox::Inbox(const Inbox& in)
{
    for (auto iterator = in.newMessages.begin(); iterator != in.newMessages.end(); iterator++) {
        this->newMessages.push_back((*iterator)->clone());
    }
    for (auto iterator = in.readMessages.begin(); iterator != in.readMessages.end(); iterator++) {
        this->readMessages.push_back((*iterator)->clone());
    }
}

void Inbox::addNewMessage(std::shared_ptr<Message> msg)
{
    newMessages.emplace_back(msg);
}

bool Inbox::hasNewMessages() const
{
    return !newMessages.empty();
}

void Inbox::readNewMessages()
{
    if (hasNewMessages()) {
        for (auto i = newMessages.begin(); i != newMessages.end(); i++) {
            std::cout << **i << std::endl;
            readMessages.push_back(*i);
        }
        newMessages.clear();
    } else {
        std::cout << "No new messages!" << std::endl;
    }
    return;
}