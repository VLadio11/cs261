#include "FacebookMessage.h"

FacebookMessage::FacebookMessage(const std::string& message, const std::string& from): Message(message, from) {}

std::string FacebookMessage::getType() const
{
    return "facebook";
}
