#include "FacebookMessage.h"

FacebookMessage::FacebookMessage(const std::string& message, const std::string& from): Message(message, from) {}

std::string FacebookMessage::getType() const
{
    return "facebook";
}

std::shared_ptr<Message> FacebookMessage::clone() const
{
    return std::make_shared<FacebookMessage>(*this);
}
