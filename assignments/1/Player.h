#ifndef PLAYER_H
#define PLAYER_H
#include "Bone.h"
#include "Boneyard.h"
#include "Field.h"
#include <vector>
#include <memory>

class Player {
private:
    int id;
    int score;
    bool has_passed;
    std::vector< std::shared_ptr<Bone> > hand;
    struct isDouble {
        int m_value;
        isDouble(int value) : m_value(value) {}
        bool operator()(const std::shared_ptr<Bone> b) const {
            return (b->getLeft() == m_value && b->isDouble());
        }
    };

public:
    Player(int id);
    int getId();
    void setHasPassed(bool flag);
    bool hasPassed();
    void draw(std::shared_ptr<Boneyard> yard);
    void printHand();
    std::shared_ptr<Bone> getDouble(int number);
    bool hasDouble(int number);
    bool play(std::shared_ptr<Field> field);
    int getScore();
    int getCurrentHandTotal();
    void setScore(int s);
    void discardAll();
};

#endif
