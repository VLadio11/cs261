#include "Boneyard.h"
#include <iostream>

Boneyard::Boneyard()
{
    // Initialize a double-nine set
    for (int i = 0; i < 9; i++) {
        for (int j = i; j < 9; j++) {
            Bone* bone = new Bone(i, j);
            bones.push_back(*bone);
        }
    }
}
