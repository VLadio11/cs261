#include <iostream>
#include <algorithm>
#include "Player.h"

Player::Player(int id)
{
    this->id = id;
}

int Player::getId()
{
    return this->id;
}

void Player::draw(std::shared_ptr<Boneyard> yard)
{
    hand.push_back(yard->draw());
}

void Player::printHand()
{
    std::cout << "Player " << getId() << " hand:" << std::endl;
    for (std::vector< std::shared_ptr<Bone> >::iterator i = hand.begin(); i != hand.end(); i++) {
        std::cout << (*i)->getLeft() << "," << (*i)->getRight() << std::endl;
    }
}

std::shared_ptr<Bone> Player::getDouble(int number)
{
    auto result = std::find_if(hand.begin(), hand.end(), isDouble(number));
    if (result != hand.end()) {
        hand.erase(std::remove_if(hand.begin(), hand.end(), isDouble(number)), hand.end());
        return *result;
    }
    return nullptr;
};
