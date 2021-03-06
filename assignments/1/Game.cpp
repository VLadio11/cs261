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
        for (std::vector< std::shared_ptr<Player> >::iterator i = players.begin(); i != players.end(); i++) {
            (*i)->setHasPassed(false);
        }
        for (int i = 0; i < INITIAL_HAND_SIZE; i++) {
            for (std::vector< std::shared_ptr<Player> >::iterator j = players.begin(); j != players.end(); j++) {
                (*j)->draw(boneyard);
            }
        }
        for (std::vector< std::shared_ptr<Player> >::iterator i = players.begin(); i != players.end(); i++) {
            if ((*i)->hasDouble(highest_double)) {
                std::shared_ptr<Bone> hd_bone = (*i)->getDouble(highest_double);
                field = std::make_shared<Field>(hd_bone);
                std::cout << "Player " << (*i)->getId() << " will begin round " << hd_bone->getLeft() << ":" << hd_bone->getRight() << ". ";
                std::cout << "Round beginning..." << std::endl;
                playRound(i);
                played_rounds[highest_double] = true;
                break;
            }
        }
    }
    // If the current round was played, get the highest double for which a round has not yet been played.
    // This *could* potentially be a higher double than the round currently played.
    if (played_rounds[highest_double]) {
        for (std::vector< std::shared_ptr<Player> >::iterator i = players.begin(); i != players.end(); i++) {
            int current_score = (*i)->getScore();
            int hand_total = (*i)->getCurrentHandTotal();
            (*i)->setScore(current_score + hand_total);
            (*i)->discardAll();
        }
        showScores();
        start(getHighestUnplayedRound(played_rounds));
    } else {
        // This handles cases in which none of the players drew the double bone that corresponds
        // to the current round being played. If that happens, we get the next highest double round
        // that has not been played and try that.
        for (std::vector< std::shared_ptr<Player> >::iterator i = players.begin(); i != players.end(); i++) {
            (*i)->discardAll();
        }
        start(getNextHighestUnplayedRound(played_rounds, highest_double));
    }
}

void Game::playRound(std::vector< std::shared_ptr<Player> >::iterator first_player)
{
    printAllPlayersHands();
    std::vector< std::shared_ptr<Player> >::iterator i = getNextPlayerIterator(first_player);
    while (haveAllPlayersPassed() == false) {
        if ((*i)->play(field)) {
            (*i)->setHasPassed(false);
        } else {
            (*i)->setHasPassed(true);
        }
        i = getNextPlayerIterator(i);
    }
    std::cout << "Round is over... results:" << std::endl;
    field->printField();
    printAllPlayersHands();
    return;
}

std::vector< std::shared_ptr<Player> >::iterator Game::getNextPlayerIterator(std::vector< std::shared_ptr<Player> >::iterator it)
{
    return ((it+1) == players.end()) ? players.begin() : ++it;
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
    return getHighestUnplayedRound(played_rounds);
}

void Game::printAllPlayersHands()
{
    for (std::vector< std::shared_ptr<Player> >::iterator i = players.begin(); i != players.end(); i++) {
        (*i)->printHand();
    }
}

bool Game::haveAllPlayersPassed()
{
    for (std::vector< std::shared_ptr<Player> >::iterator i = players.begin(); i != players.end(); i++) {
        if ((*i)->hasPassed() == false) {
            return false;
        }
    }
    return true;
}

void Game::showScores()
{
    std::cout << std::endl << "*********** Scores ***********" << std::endl;
    for (std::vector< std::shared_ptr<Player> >::iterator i = players.begin(); i != players.end(); i++) {
        std::cout << "Player " << (*i)->getId() << ": " << (*i)->getScore() << std::endl;
    }
    std::cout << "**************************" << std::endl << std::endl;
}
