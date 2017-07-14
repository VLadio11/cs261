#ifndef GAME_H
#define GAME_H
#include <memory>
#include <vector>
#include "Boneyard.h"
#include "Player.h"
#include "Field.h"

const int INITIAL_HAND_SIZE = 7;
static const int DOMINOES_SET_SIZE = 9;

const bool DEBUG = false;

class Game {
private:
    std::vector< std::shared_ptr<Player> > players;
    std::shared_ptr<Boneyard> boneyard;
    std::shared_ptr<Field> field;
    bool played_rounds[DOMINOES_SET_SIZE]; // This will keep track of which double rounds have already been played

    int getHighestUnplayedRound(bool* played);
    int getNextHighestUnplayedRound(bool* played, int round);
    void playRound(int first_player_index);
public:
    Game(int num_of_players);
    void start(int highest_double);
};

#endif
