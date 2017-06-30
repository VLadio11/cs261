#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bone.h"
#include "Boneyard.h"
#include "Player.h"

int main(int argc, char** argv) {
    std::srand(std::time(0));
    Player* p1 = new Player(1);
    Boneyard* yard = new Boneyard();
    yard->shuffle();

    yard->printBoneyard();

    p1->draw(yard);
    p1->draw(yard);
    p1->draw(yard);
    p1->printHand();

    delete yard;
    delete p1;
    return 0;
}