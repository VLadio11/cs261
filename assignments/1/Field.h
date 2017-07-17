#ifndef FIELD_H
#define FIELD_H
#include <vector>
#include <memory>
#include "Bone.h"

class Field {
private:
    struct node {
        std::shared_ptr<Bone> bone;
        std::vector< std::shared_ptr<node> > connections;
    };
    std::shared_ptr<node> head;
public:
    Field(std::shared_ptr<Bone> first_double);
    std::vector< std::shared_ptr<Bone> > getPlayableBones();
};

#endif