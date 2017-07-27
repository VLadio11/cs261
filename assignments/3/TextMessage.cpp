#include "TextMessage.h"

TextMessage::TextMessage(const std::string& message, const std::string& from): Message(message, from) {}

std::string TextMessage::getType() const
{
    return "text";
}

std::shared_ptr<Message> TextMessage::clone() const
{
    return std::make_shared<TextMessage>(*this);
}
