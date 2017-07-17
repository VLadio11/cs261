#include "Boneyard.h"
#include "Game.h"
#include <iostream>
#include <algorithm>

void Boneyard::initialize()
{
    bones.clear();
    for (int i = 0; i <= DOMINOES_SET_SIZE; i++) {
        for (int j = i; j <= DOMINOES_SET_SIZE; j++) {
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
    std::cout << std::endl;
    std::cout << "Boneyard:" << std::endl;
    for (std::vector< std::shared_ptr<Bone> >::iterator i = bones.begin(); i != bones.end(); i++) {
        std::cout << (*i)->getLeft() << "," << (*i)->getRight() << " ";
        unsigned int index = i - bones.begin();
        if (index > 0 && (index + 1) % 5 == 0) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}
