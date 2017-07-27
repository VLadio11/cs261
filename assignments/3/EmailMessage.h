#ifndef EMAIL_MESSAGE_H
#define EMAIL_MESSAGE_H

#include "Message.h"

class EmailMessage : public Message {
public:
    EmailMessage(const std::string& message, const std::string& from);
};

#endif