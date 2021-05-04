#pragma once

#include <iostream>
#include <map>
using namespace std;

#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"

typedef enum Type
{
    researcher,
    scientist,
    fieldDoctor,
    geneSplicer,
    operationsExpert,
    dispatcher,
    medic,
    virologist
} Type;

namespace pandemic{
    class Player{
        protected:
            Board& player_board;
            City current_city;
            map <string, City> my_cards;
            Type type;

        public:
            Player(Board& board, City city): player_board(board), current_city(city){};
            virtual Player& drive(City dest);
            virtual Player& fly_direct(City dest);
            virtual Player& fly_charter(City dest);
            virtual Player& fly_shuttle(City dest);
            virtual Player& build();
            virtual Player& discover_cure(Color color);
            virtual Player& treat(City dest);
            string role();
            void remove_cards();
            virtual Player& take_card(City city);

    };
};