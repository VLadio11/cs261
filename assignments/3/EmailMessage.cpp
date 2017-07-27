#include "EmailMessage.h"

EmailMessage::EmailMessage(const std::string& message, const std::string& from): Message(message, from) {}

std::string EmailMessage::getType() const
{
    return "email";
}

std::shared_ptr<Message> EmailMessage::clone() const
{
    return std::make_shared<EmailMessage>(*this);
}
