#ifndef FIELD_H
#define FIELD_H
#include <vector>
#include <list>
#include "Bone.h"

class Field {
private:
    struct node {
        Bone b;
        std::vector<std::list<Bone>> connections;
    };
    node* head;
public:
    Field();
    ~Field();
};

#endif