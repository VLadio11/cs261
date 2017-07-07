#include "Boneyard.h"
#include <iostream>
#include <algorithm>

void Boneyard::initialize()
{
    bones.clear();
    for (int i = 0; i < 9; i++) {
        for (int j = i; j < 9; j++) {
            bones.emplace_back(std::make_shared<Bone>(i, j));
        }
    }
    std::random_shuffle(bones.begin(), bones.end());
}

std::shared_ptr<Bone> Boneyard::draw()
{
    std::shared_ptr<Bone> b = bones.back();
    bones.pop_back();
    return b;
}

void Boneyard::printBoneyard()
{
    std::cout << "Boneyard:" << std::endl;
    for (std::vector< std::shared_ptr<Bone> >::iterator i = bones.begin(); i != bones.end(); i++) {
        std::cout << (*i)->getLeft() << "," << (*i)->getRight() << std::endl;
    }
}
