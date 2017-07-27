#include "Inbox.h"
#include <iostream>

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
        }
    } else {
        std::cout << "No new messages!" << std::endl;
    }
    return;
}