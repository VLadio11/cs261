#include "Game.h"

Game::Game(int num_of_players)
{
    boneyard = std::make_shared<Boneyard>();
    for (int i = 0; i < num_of_players; i++) {
        players.emplace_back(std::make_shared<Player>(i));
    }
}

void Game::start()
{
    boneyard->shuffle();
    for (int i = 0; i < INITIAL_HAND_SIZE; i++) {
        for (std::vector< std::shared_ptr<Player> >::iterator i = players.begin(); i != players.end(); i++) {
            (*i)->draw(boneyard);
        }
    }

    std::shared_ptr<Bone> highest_double = getLargestDouble();
    while (highest_double != nullptr) {
        field = std::make_shared<Field>(highest_double);
        // @todo: Play round
        highest_double = getLargestDouble();
    }

    boneyard->printBoneyard();
    for (std::vector< std::shared_ptr<Player> >::iterator i = players.begin(); i != players.end(); i++) {
        (*i)->printHand();
    }
    return;
}

std::shared_ptr<Bone> Game::getLargestDouble()
{
    for (int i = 0; i < 9; i++) {
        for (std::vector< std::shared_ptr<Player> >::iterator it = players.begin(); it != players.end(); it++) {
            std::shared_ptr<Bone> b = (*it)->getDouble(i);
            if (b != nullptr) {
                return b;
            }
        }
    }
    return nullptr;
}
