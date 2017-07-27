#include "Message.h"

Message::Message(const std::string& message, const std::string& from): message_(message), from_(from) {}

std::string Message::getMessage() const
{
    return message_;
}

std::string Message::getFrom() const
{
    return from_;
}
