#ifndef FIELD_H
#define FIELD_H
#include <vector>
#include "Bone.h"

class Field {
private:
    struct node {
        Bone b;
        std::vector<node*> connections;
    };
    node* head;
public:
    Field();
    ~Field();
};

#endif