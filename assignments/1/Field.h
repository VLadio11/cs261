#ifndef FIELD_H
#define FIELD_H
#include <vector>
#include <memory>
#include <unordered_map>
#include "Bone.h"

class Field {
private:
    struct node {
        std::shared_ptr<Bone> bone;
        std::vector< std::shared_ptr<node> > connections;
    };
    std::shared_ptr<node> head;
    void traverse(std::unordered_map< int, std::shared_ptr<Bone> > playable_bones, std::shared_ptr<node> parent, std::shared_ptr<node> child);
    void connect(std::shared_ptr<node> head, std::shared_ptr<Bone> parent, std::shared_ptr<Bone> new_connection);
    void printField(std::shared_ptr<node> head);
public:
    Field(std::shared_ptr<Bone> first_double);
    std::unordered_map< int, std::shared_ptr<Bone> > getPlayableBones();
    void connect(std::shared_ptr<Bone> parent, std::shared_ptr<Bone> new_connection);
    void printField();
};

#endif
