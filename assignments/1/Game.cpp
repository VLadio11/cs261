#include "Game.h"
#include <iostream>

Game::Game(int num_of_players)
{
    boneyard = std::make_shared<Boneyard>();
    for (int i = 0; i < num_of_players; i++) {
        players.emplace_back(std::make_shared<Player>(i));
    }
    for (int i = 0; i <= 9; i++) {
        played_rounds[i] = false;
    }
}

void Game::start()
{
    beginRound();
}

void Game::beginRound()
{
    boneyard->initialize();
    for (int i = 0; i < INITIAL_HAND_SIZE; i++) {
        for (std::vector< std::shared_ptr<Player> >::iterator i = players.begin(); i != players.end(); i++) {
            (*i)->draw(boneyard);
        }
    }
    for (int i = getHighestUnplayedRound(played_rounds); (i > 0) && !played_rounds[i]; i--) {
        for (std::vector< std::shared_ptr<Player> >::iterator j = players.begin(); j != players.end(); j++) {
            if ((*j)->hasDouble(i)) {
                std::shared_ptr<Bone> highest_double = (*j)->getDouble(i);
                field = std::make_shared<Field>(highest_double);
                played_rounds[i] = true;
                // Continue playing round
                std::cout << "Round " << i << " played" << std::endl;
            }
        }
    }
}

int Game::getHighestUnplayedRound(bool* played)
{
    for (int i = 9; i >= 0; i--) {
        if (played[i] == false) {
            return i;
        }
    }
    return -1;
}

void Game::endRound()
{
    for (std::vector< std::shared_ptr<Player> >::iterator i = players.begin(); i != players.end(); i++) {
        int current_score = (*i)->getScore();
        int hand_total = (*i)->getCurrentHandTotal();
        (*i)->setScore(current_score + hand_total);
        (*i)->discardAll();
    }
}
