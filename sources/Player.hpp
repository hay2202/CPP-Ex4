#pragma once

#include <iostream>
#include <map>
using namespace std;

#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include <set>
#include <stdexcept>


namespace pandemic{
    class Player{
        protected:
            Board& player_board;
            City current_city;
            set <City> my_cards;
            

        public:
            Player(Board& board, City city): player_board(board), current_city(city){}
            virtual Player& drive(City dest);
            virtual Player& fly_direct(City dest);
            virtual Player& fly_charter(City dest);
            virtual Player& fly_shuttle(City dest);
            virtual Player& build();
            virtual Player& discover_cure(Color color);
            virtual Player& treat(City dest);
            virtual string role();
            void remove_cards();
            virtual Player& take_card(City city);

    };
};