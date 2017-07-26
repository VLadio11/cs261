#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

class Message {
protected:
    std::string message_;
    std::string type_;
    Message();

public:
    Message(const std::string& message);
    std::string getMessage() const;
};

#endif