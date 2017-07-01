#ifndef BONE_H
#define BONE_H

class Bone {
private:
    int left;
    int right;
public:
    Bone(int left, int right);
    int getLeft();
    int getRight();
    bool isDouble();
};

#endif
