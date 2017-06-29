#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bone.h"
#include "Boneyard.h"
#include "Player.h"

int main(int argc, char** argv) {
    std::srand(std::time(0));
    Boneyard* yard = new Boneyard();
    yard->shuffle();
    delete yard;
    return 0;
}