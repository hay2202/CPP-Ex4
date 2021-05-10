
#include "Scientist.hpp"
using namespace std;
using namespace pandemic;

Player& Scientist::discover_cure(Color color){
    if (player_board.station.count(current_city) > 0)   //check if there is a station 
    {
        int count=0;
        for (auto& i : my_cards){                       //check if there is 5 cards same color 
            if (player_board.city_by_color[i] == color)
            {
                count++;
            }
        }
        if (count < num_cards)
        {
            throw std::out_of_range{"Not enough cards! \n"};
        }

        if (player_board.cure.count(color) == 0 )           //check if no cure found yet
        {   
            for (auto& i : my_cards){      
                if (count == 0)
                {
                    break;
                }
                      
                if (player_board.city_by_color[i] == color)
                {
                    my_cards.erase(i);
                    count--;
                }
            }
            player_board.cure.insert(color);
        }
        
        return *this;
    }
     throw std::out_of_range{"Station doesn't exist! \n"};
}

string Scientist::role(){
    return "Scientist";
}