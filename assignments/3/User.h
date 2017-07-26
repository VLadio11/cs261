#ifndef USER_H
#define USER_H

#include <string>

class User {
public:
    User(const char* name);

private:
    std::string m_name;
    std::string comm_preference;
    User();
};

#endif