#include "Scientist.hpp"
using namespace std;
using namespace pandemic;

Player& Scientist::discover_cure(Color color){
    if (player_board.station.count(current_city) > 0)       //check if there is a station 
    {
        if (player_board.cure.count(color) > 0)              //check if no cure found yet
        {
            return *this;
        }

        int count=0;
        for (const auto& i : my_cards){                       //check if there is enough cards same color 
            if (Board::city_by_color[i] == color)
            {
                count++;
            }
        }
        if (count < num_cards){
            throw out_of_range{"Not enough cards! \n"}; 
        }   

        auto itr = my_cards.begin();
        while(count > 0){
            if (Board::city_by_color[*itr] == color)
            {
                my_cards.erase(*itr++);
                count--;
            }
            else{
                itr++;
            }
               
        }
        player_board.cure.insert(color);
        return *this;
         
    }
    throw std::out_of_range{"Station doesn't exist! \n"};
      
}

string Scientist::role(){
    return "Scientist";
}