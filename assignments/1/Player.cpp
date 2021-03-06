#include <iostream>
#include <algorithm>
#include "Player.h"

Player::Player(int m_id): id(m_id), score(0), has_passed(false) {}

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
    std::cout << "Player " << getId() << " hand: ";
    for (std::vector< std::shared_ptr<Bone> >::iterator i = hand.begin(); i != hand.end(); i++) {
        std::cout << (*i)->getLeft() << "," << (*i)->getRight() << " ";
    }
    std::cout << std::endl;
}

bool Player::play(std::shared_ptr<Field> field)
{
    std::unordered_map< int, std::shared_ptr<Bone> > playable_bones = field->getPlayableBones();
    for (std::vector< std::shared_ptr<Bone> >::iterator i = hand.begin(); i != hand.end(); i++) {
        auto match = playable_bones.find((*i)->getLeft());
        if (match != playable_bones.end()) {
            field->connect(match->second, *i);
            hand.erase(i);
            return true;
        }
        match = playable_bones.find((*i)->getRight());
        if (match != playable_bones.end()) {
            field->connect(match->second, *i);
            hand.erase(i);
            return true;
        }
    }
    return false;
}

std::shared_ptr<Bone> Player::getDouble(int number)
{
    auto iterator = std::find_if(hand.begin(), hand.end(), isDouble(number));
    if (iterator != hand.end()) {
        std::shared_ptr<Bone> result = *iterator;
        hand.erase(iterator);
        return result;
    }
    return nullptr;
}

bool Player::hasDouble(int number)
{
    auto result = std::find_if(hand.begin(), hand.end(), isDouble(number));
    return (result != hand.end()) ? true : false;
}

int Player::getScore()
{
    return score;
}

int Player::getCurrentHandTotal()
{
    int hand_total = 0;
    for (std::vector< std::shared_ptr<Bone> >::iterator i = hand.begin(); i != hand.end(); i++) {
        hand_total = hand_total + (*i)->getLeft() + (*i)->getRight();
    }
    return hand_total;
}

void Player::setScore(int s)
{
    score = s;
}

void Player::discardAll()
{
    hand.clear();
}

void Player::setHasPassed(bool flag)
{
    has_passed = flag;
}

bool Player::hasPassed()
{
    return has_passed;
}
