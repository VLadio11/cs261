#ifndef FACEBOOK_MESSAGE_H
#define FACEBOOK_MESSAGE_H

#include "Message.h"

class FacebookMessage : public Message {
public:
    FacebookMessage(const std::string& message, const std::string& from);
};

#endif