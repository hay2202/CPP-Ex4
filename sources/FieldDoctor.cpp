
#include "FieldDoctor.hpp"
using namespace std;
using namespace pandemic;

Player& FieldDoctor::treat(City dest){
    if (dest == current_city)
    {
        Player::treat(dest);
        return *this;
    }  
    if (player_board.disease_level[dest] > 0 )
    {
        for (auto& i : Board::all_cities[current_city]){
            if (dest == i)
            {
                Color temp = Board::city_by_color.at(dest);
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
    throw std::out_of_range{"disease doesn't exist! \n"};    
}

string FieldDoctor::role(){
    return "FieldDoctor";
}
