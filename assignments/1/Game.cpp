#include "Game.h"

Game::Game(int num_of_players)
{
    boneyard = std::make_shared<Boneyard>();
    for (int i = 0; i < num_of_players; i++) {
        players.emplace_back(std::make_shared<Player>(i));
        played_rounds[i] = false;
    }
}

void Game::start()
{
    beginRound();
}

void Game::beginRound()
{
    if (getHighestUnplayedRound(played_rounds) == -1) {
        // Game complete
        return;
    }
    boneyard->initialize();
    for (int i = 0; i < INITIAL_HAND_SIZE; i++) {
        for (std::vector< std::shared_ptr<Player> >::iterator i = players.begin(); i != players.end(); i++) {
            (*i)->draw(boneyard);
        }
    }
    // Psuedo:
    // First, get the highest unplayed round double and check if any players have it. If one does, that player plays the double
    // If no players have the highest unplayed, find the next highest unplayed round and check if any players have that one.
    // If no players have any doubles that have yet to be played, restart the round
    // If there are no more rounds to play, end game. 

    std::shared_ptr<Bone> highest_double = getLargestDouble();
    while (highest_double != nullptr) {
        field = std::make_shared<Field>(highest_double);
        // @todo: Play round
        highest_double = getLargestDouble();
    }

    endRound();
}

int Game::getHighestUnplayedRound(bool* played)
{
    for (int i = 0; i < 9; i++) {
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
