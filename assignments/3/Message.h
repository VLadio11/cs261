#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <ostream>

class Message {
protected:
    std::string message_;
    std::string from_;
    virtual std::string getType() const = 0;

public:
    Message(const std::string& message, const std::string& from);
    std::string getMessage() const;
    std::string getFrom() const;
    friend std::ostream& operator<<(std::ostream& os, Message& msg);
};

inline std::ostream& operator<<(std::ostream& os, Message& msg) {
    os << "Platform: " << msg.getType() << std::endl;
    os << "From: " << msg.getFrom() << std::endl;
    os << msg.getMessage() << std::endl;
    return os;
}

#endif