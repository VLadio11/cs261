#include "TextMessage.h"

TextMessage::TextMessage(const std::string& message, const std::string& from): Message(message, from) {}

std::string TextMessage::getType() const
{
    return "text";
}
