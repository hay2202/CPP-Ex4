#pragma once

#include "Player.hpp"

namespace pandemic{
    class Medic : public Player
    {

        public:
            Medic(Board& board, City city) : Player(board, city){};
            Player& drive(City dest);
            Player& fly_direct(City dest);
            Player& fly_charter(City dest);
            Player& fly_shuttle(City dest);
            Player& treat(City dest);
            string role();
    };
};
