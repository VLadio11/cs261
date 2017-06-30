#ifndef PLAYER_H
#define PLAYER_H
#include "Bone.h"
#include "Boneyard.h"
#include <vector>

class Player {
private:
    int id;
    std::vector<Bone> hand;

public:
    Player();
    Player(int id);
    int getId();
    void draw(Boneyard* yard);
    void printHand();
};

#endif
