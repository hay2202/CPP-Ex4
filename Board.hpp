#pragma once

#include <iostream>
#include "City.hpp"
#include <map>

using namespace std;

namespace pandemic{
    class Board{
        private:
            int num;
            map<City,int> disease_level;

        public:
            Board() = default;
            bool is_clean();
            void remove_cures();
            void remove_stations();
            int& operator[] (City city);
            friend std::ostream& operator<< (std::ostream& os,const Board& x);

    };
};