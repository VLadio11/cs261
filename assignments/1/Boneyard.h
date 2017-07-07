#ifndef BONEYARD_H
#define BONEYARD_H
#include "Bone.h"
#include <vector>
#include <memory>

class Boneyard {
private:
    std::vector< std::shared_ptr<Bone> > bones;
public:
    void initialize();
    std::shared_ptr<Bone> draw();
    void printBoneyard();
};

#endif
