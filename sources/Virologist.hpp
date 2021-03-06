#pragma once

#include "Player.hpp"

namespace pandemic{
    class Virologist : public Player
    {
        public:
            Virologist(Board& board, City city) : Player(board, city){};
            Player& treat(City dest) override;
            string role()override;
    };
};