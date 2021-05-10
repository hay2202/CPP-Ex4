#pragma once

#include "Player.hpp"

namespace pandemic{
    class Scientist : public Player
    {
        private:
            int num_cards;

        public:
            Scientist(Board& board, City city, int n=4) : Player(board, city), num_cards(n){};
            Player& discover_cure(Color color);
            string role();
    };
};
