#ifndef GAME_H
#define GAME_H
#include <memory>
#include <vector>
#include "Boneyard.h"
#include "Player.h"
#include "Field.h"

const int INITIAL_HAND_SIZE = 7;

class Game {
private:
    std::vector< std::shared_ptr<Player> > players;
    std::shared_ptr<Boneyard> boneyard;
    std::shared_ptr<Field> field;
    bool played_rounds[9]; // This will keep track of which double rounds have already been played

    int getHighestUnplayedRound(bool* played);
    void beginRound();
    void endRound();
public:
    Game(int num_of_players);
    void start();
};

#endif
