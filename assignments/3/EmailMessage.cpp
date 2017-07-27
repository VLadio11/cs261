#include "EmailMessage.h"

EmailMessage::EmailMessage(const std::string& message, const std::string& from): Message(message, from) {}

std::string EmailMessage::getType() const
{
    return "email";
}
