#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

class Message {
protected:
    std::string message_;
    std::string from_;

public:
    Message(const std::string& message, const std::string& from);
    std::string getMessage() const;
};

#endif