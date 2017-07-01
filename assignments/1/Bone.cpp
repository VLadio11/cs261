#include "Bone.h"

Bone::Bone(int left, int right)
{
    this->left = left;
    this->right = right;
}

int Bone::getLeft()
{
    return this->left;
}

int Bone::getRight()
{
    return this->right;
}

bool Bone::isDouble()
{
    return this->left == this->right;
}
