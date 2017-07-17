#include "Field.h"

Field::Field(std::shared_ptr<Bone> first_double)
{
    head = std::make_shared<node>();
    head->bone = first_double;
    head->connections = {};
}

std::vector< std::shared_ptr<Bone> > Field::getPlayableBones()
{
    std::vector< std::shared_ptr<Bone> > playable_bones;
    if (head->connections.size() < 4) {
        playable_bones.push_back(head->bone);
    } else {
        // Traverse the tree and add bones when applicable
    }
    return playable_bones;
}
