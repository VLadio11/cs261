#include "Inbox.h"

std::vector< std::shared_ptr<Message> > Inbox::getNewMessages() const
{
    return newMessages;
}

std::vector< std::shared_ptr<Message> > Inbox::getReadMessages() const
{
    return readMessages;
}

void Inbox::addNewMessage(std::shared_ptr<Message> msg)
{
    newMessages.emplace_back(msg);
}