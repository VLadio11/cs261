#ifndef INBOX_H
#define INBOX_H

#include <vector>
#include <memory>
#include "Message.h"

class Inbox {
private:
    std::vector< std::shared_ptr<Message> > newMessages;
    std::vector< std::shared_ptr<Message> > readMessages;
public:
    std::vector< std::shared_ptr<Message> > getNewMessages() const;
    std::vector< std::shared_ptr<Message> > getReadMessages() const;
    void addNewMessage(std::shared_ptr<Message> msg);
};

#endif