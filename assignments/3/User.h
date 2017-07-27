#ifndef USER_H
#define USER_H

#include <string>
#include <memory>
#include "Inbox.h"

class User {
private:
    std::string name_;
    std::string comm_preference_;
    std::shared_ptr<Inbox> inbox;

public:
    User(const std::string& name, const std::string& comm_preference = "email");
    User(const User& u);
    std::string getName() const;
    std::string getCommPreference() const;
    void sendMessage(std::shared_ptr<User> recipient, const std::string& msg);
    void sendMessage(std::shared_ptr<User> recipient, const std::string& msg, const std::string& type);
    void addNewMessage(std::shared_ptr<Message> msg);
    bool hasNewMessages() const;
    void readNewMessages();
};

#endif