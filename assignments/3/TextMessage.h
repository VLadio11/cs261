#ifndef TEXT_MESSAGE_H
#define TEXT_MESSAGE_H

#include "Message.h"

class TextMessage : public Message {
public:
    TextMessage(const std::string& message, const std::string& from);
    std::string getType() const;
};

#endif