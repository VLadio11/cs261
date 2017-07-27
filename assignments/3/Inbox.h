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
    void addNewMessage(std::shared_ptr<Message> msg);
    bool hasNewMessages() const;
    void readNewMessages();
};

#endif