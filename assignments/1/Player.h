#ifndef PLAYER_H
#define PLAYER_H
#include "Bone.h"
#include "Boneyard.h"
#include <vector>
#include <memory>

class Player {
private:
    int id;
    std::vector< std::shared_ptr<Bone> > hand;

public:
    Player();
    Player(int id);
    int getId();
    void draw(Boneyard* yard);
    void printHand();
};

#endif
