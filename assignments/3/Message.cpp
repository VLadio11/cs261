#include "Message.h"

Message::Message(const std::string& message): message_(message) {}

std::string Message::getMessage() const
{
    return message_;
}
