#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Boneyard.h"
#include "Player.h"

const int INITIAL_HAND_SIZE = 7;

int main(int argc, char** argv) {
    std::srand(std::time(0));

    Player* p1 = new Player(1);
    Player* p2 = new Player(2);
    Player* p3 = new Player(3);
    Player* p4 = new Player(4);

    Boneyard* yard = new Boneyard();
    yard->shuffle();

    for (int i = 0; i < INITIAL_HAND_SIZE; i++) {
        p1->draw(yard);
        p2->draw(yard);
        p3->draw(yard);
        p4->draw(yard);
    }

    p1->printHand();
    p2->printHand();
    p3->printHand();
    p4->printHand();

    yard->printBoneyard();

    delete yard;
    delete p4;
    delete p3;
    delete p2;
    delete p1;

    return 0;
}