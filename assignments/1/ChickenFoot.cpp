#include <iostream>
#include "Bone.h"
#include "Boneyard.h"
#include "Player.h"

int main(int argc, char** argv) {
    Boneyard* yard = new Boneyard();
    delete yard;
    return 0;
}