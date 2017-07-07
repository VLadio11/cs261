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

    // @todo: Find highest double and construct Field

    boneyard->printBoneyard();
    for (std::vector< std::shared_ptr<Player> >::iterator i = players.begin(); i != players.end(); i++) {
        (*i)->printHand();
    }
    return;
}

std::shared_ptr<Bone> getLargestDouble()
{
    return nullptr;
}
