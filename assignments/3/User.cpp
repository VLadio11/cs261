#include "User.h"

User::User(const std::string& name, const std::string& comm_preference): name_(name), comm_preference_(comm_preference) {}

std::string User::getName() const
{
    return name_;
}

std::string User::getCommPreference() const
{
    return comm_preference_;
}
