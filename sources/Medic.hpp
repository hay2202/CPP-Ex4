#pragma once

#include "Player.hpp"

namespace pandemic{
    class Medic : public Player
    {

        public:
            Medic(Board& board, City city) : Player(board, city){};
            Player& drive(City dest)override;
            Player& fly_direct(City dest)override;
            Player& fly_charter(City dest)override;
            Player& fly_shuttle(City dest)override;
            Player& treat(City dest)override;
            string role()override;
    };
};
