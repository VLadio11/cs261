#ifndef PLAYER_H
#define PLAYER_H
#include "Bone.h"
#include "Boneyard.h"
#include <vector>
#include <memory>

class Player {
private:
    int id;
    int score;
    std::vector< std::shared_ptr<Bone> > hand;
    struct isDouble {
        int m_value;
        isDouble(int value) : m_value(value) {}
        bool operator()(const std::shared_ptr<Bone> b) const {
            return (b->getLeft() == m_value && b->isDouble());
        }
    };

public:
    Player();
    Player(int id);
    int getId();
    void draw(std::shared_ptr<Boneyard> yard);
    void printHand();
    std::shared_ptr<Bone> getDouble(int number);
    int getScore();
    int getCurrentHandTotal();
    void setScore(int s);
    void discardAll();
};

#endif
