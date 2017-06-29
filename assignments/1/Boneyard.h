#ifndef BONEYARD_H
#define BONEYARD_H
#include "Bone.h"
#include <vector>

class Boneyard {
private:
    std::vector<Bone> bones;
public:
    Boneyard();
    void shuffle();
};

#endif
