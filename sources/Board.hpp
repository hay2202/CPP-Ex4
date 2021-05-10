#pragma once

#include <iostream>
#include "City.hpp"
#include "Color.hpp"
#include <map>
#include <set>
#include <vector>

using namespace std;

namespace pandemic{
    class Board{
        private:
            int num;

        public:
            Board();
            static map<City,vector<City>> all_cities;
            static map<City,Color> city_by_color;
            set <City> station;
            set <Color> cure;
            map<City,int> disease_level;
            bool is_clean();
            void remove_cures();
            void remove_stations();
            int& operator[] (City city);
            friend std::ostream& operator<< (std::ostream& os,const Board& x);
            void init_map();
            static string enum_to_string(City c);

    };
};