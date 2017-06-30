#include <iostream>
#include "Player.h"

Player::Player(int id)
{
    this->id = id;
}

int Player::getId()
{
    return this->id;
}

void Player::draw(Boneyard* yard)
{
    hand.push_back(yard->draw());
}

void Player::printHand()
{
    std::cout << "Player " << getId() << " hand:" << std::endl;
    for (std::vector<Bone>::iterator i = hand.begin(); i != hand.end(); i++) {
        std::cout << i->getLeft() << "," << i->getRight() << std::endl;
    }
}