
#include "FieldDoctor.hpp"
using namespace std;
using namespace pandemic;

Player& FieldDoctor::treat(City dest){
    if (player_board.disease_level[dest] > 0 )
    {
        for (auto& i : player_board.all_cities[current_city]){
            if (dest == i)
            {
                Color temp = player_board.city_by_color.at(dest);
                if (player_board.cure.count(temp) > 0)
                {
                    player_board.disease_level[dest] = 0;
                }
                else 
                {
                        player_board.disease_level[dest]--;
                }
                return *this;
            }
        }
    }
    throw std::out_of_range{"illegal action! \n"};
}

string FieldDoctor::role(){
    return "FieldDoctor";
}
