#include <iostream>
#include "User.h"
#include "FacebookMessage.h"
#include "EmailMessage.h"
#include "TextMessage.h"

User::User(const std::string& name, const std::string& comm_preference): name_(name), comm_preference_(comm_preference) 
{
    inbox = std::make_shared<Inbox>();
}

std::string User::getName() const
{
    return name_;
}

std::string User::getCommPreference() const
{
    return comm_preference_;
}

void User::sendMessage(std::shared_ptr<User> recipient, const std::string& msg)
{
    return sendMessage(recipient, msg, recipient->getCommPreference());
}

void User::sendMessage(std::shared_ptr<User> recipient, const std::string& msg, const std::string& type)
{
    std::shared_ptr<Message> m;
    if (type == "facebook") {
        m = std::make_shared<FacebookMessage>(msg, getName());
    } else if (type == "email") {
        m = std::make_shared<EmailMessage>(msg, getName());
    } else if (type == "text") {
        m = std::make_shared<TextMessage>(msg, getName());
    } else {
        // throw exception?
    }
    return recipient->addNewMessage(m);
}

void User::addNewMessage(std::shared_ptr<Message> msg)
{
    return inbox->addNewMessage(msg);
}

bool User::hasNewMessages() const
{
    return inbox->hasNewMessages();
}

void User::readNewMessages()
{
    std::cout << std::endl;
    std::cout << "*** " << getName() << "'s" << " New Messages ***" << std::endl;
    inbox->readNewMessages();
}
