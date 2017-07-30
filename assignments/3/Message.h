#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <ostream>
#include <memory>

class Message {
protected:
    std::string message_;
    std::string from_;
    virtual std::string getType() const = 0;

public:
    Message(const std::string& message, const std::string& from);
    virtual std::shared_ptr<Message> clone() const = 0;
    std::string getMessage() const;
    std::string getFrom() const;
    friend std::ostream& operator<<(std::ostream& os, Message& msg);
    friend bool operator== (const Message& m1, const Message& m2);
    friend bool operator!= (const Message& m1, const Message& m2);
    Message& operator+= (const Message& rhs);
};

inline std::ostream& operator<<(std::ostream& os, Message& msg) {
    os << "Platform: " << msg.getType() << std::endl;
    os << "From: " << msg.getFrom() << std::endl;
    os << msg.getMessage() << std::endl;
    return os;
}

inline bool operator== (const Message& m1, const Message& m2)
{
    return m1.message_ == m2.message_;
}

inline bool operator!= (const Message& m1, const Message& m2)
{
    return !(m1 == m2);
}

#endif