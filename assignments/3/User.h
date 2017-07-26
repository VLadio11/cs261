#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    std::string name_;
    std::string comm_preference_;
    User();

public:
    User(const std::string& name, const std::string& comm_preference = "email");
    std::string getName() const;
    std::string getCommPreference() const;
};

#endif