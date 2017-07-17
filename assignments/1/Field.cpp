#include "Field.h"

Field::Field(std::shared_ptr<Bone> first_double)
{
    head = std::make_shared<node>();
    head->bone = first_double;
    head->connections = {};
}

std::unordered_map< int, std::shared_ptr<Bone> > Field::getPlayableBones()
{
    std::unordered_map< int, std::shared_ptr<Bone> > playable_bones = {};
    if (head->connections.size() < 4) {
        playable_bones.insert({ head->bone->getLeft(), head->bone });
    } else {
        // Traverse the tree to find playable bones
        for (std::vector< std::shared_ptr<node> >::iterator i = head->connections.begin(); i != head->connections.end(); i++) {
            traverse(playable_bones, head, *i);
        }
    }
    return playable_bones;
}

void Field::traverse(
    std::unordered_map< int, std::shared_ptr<Bone> > playable_bones,
    std::shared_ptr<node> parent,
    std::shared_ptr<node> child
) {
    for (std::vector< std::shared_ptr<node> >::iterator i = child->connections.begin(); i != child->connections.end(); i++) {
        traverse(playable_bones, child, *i);
    }
    if (child->bone->isDouble() && child->connections.size() < 3) {
        // This is an unfinished chicken foot, so we push this bone into the playable bones and return immediately
        playable_bones.clear();
        playable_bones.insert({ child->bone->getLeft(), child->bone });
        return;
    }
    if (!child->bone->isDouble() && child->connections.size() < 1) {
        // Check the parent's left and right values to figure out which child value is actually playable.
        // Then, insert the child's bone into playable_bones with the proper playable value as the key
    }
}
