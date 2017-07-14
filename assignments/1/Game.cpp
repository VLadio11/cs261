#include "Game.h"
#include <iostream>

Game::Game(int num_of_players)
{
    boneyard = std::make_shared<Boneyard>();
    for (int i = 0; i < num_of_players; i++) {
        players.emplace_back(std::make_shared<Player>(i));
    }
    for (int i = 0; i <= DOMINOES_SET_SIZE; i++) {
        played_rounds[i] = false;
    }
}

void Game::start(int highest_double)
{
    if (highest_double < 0) {
        return;
    } else {
        boneyard->initialize();
        for (int j = 0; j < INITIAL_HAND_SIZE; j++) {
            for (std::vector< std::shared_ptr<Player> >::iterator j = players.begin(); j != players.end(); j++) {
                (*j)->draw(boneyard);
            }
        }
        for (std::vector< std::shared_ptr<Player> >::iterator j = players.begin(); j != players.end(); j++) {
            if ((*j)->hasDouble(highest_double)) {
                std::shared_ptr<Bone> hd_bone = (*j)->getDouble(highest_double);
                field = std::make_shared<Field>(hd_bone);
                played_rounds[highest_double] = true;
                // Continue playing round
                break;
            }
        }
    }
    // If the current round was played, get the highest double for which a round has not yet been played.
    // This *could* potentially be a higher double than the round currently played.
    if (played_rounds[highest_double]) {
        start(getHighestUnplayedRound(played_rounds));
    } else {
        // This handles cases in which none of the players drew the double bone that corresponds
        // to the current round being played. If that happens, we get the next highest double round
        // that has not been played and try that.
        start(getNextHighestUnplayedRound(played_rounds, highest_double));
    }
}

int Game::getHighestUnplayedRound(bool* played)
{
    for (int i = DOMINOES_SET_SIZE; i >= 0; i--) {
        if (played[i] == false) {
            return i;
        }
    }
    return -1;
}

int Game::getNextHighestUnplayedRound(bool* played, int round)
{
    for (int i = round - 1; i >= 0; i--) {
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
