#include "User.h"
#include "FacebookMessage.h"

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
    if (type == "facebook") {
        std::shared_ptr<FacebookMessage> fb = std::make_shared<FacebookMessage>(msg, recipient->getName());
        recipient->addNewMessage(fb);
    }
    return;
}

void User::addNewMessage(std::shared_ptr<Message> msg)
{
    return inbox->addNewMessage(msg);
}
