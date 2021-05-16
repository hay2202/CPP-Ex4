
#include "GeneSplicer.hpp"
using namespace std;
using namespace pandemic;

Player& GeneSplicer::discover_cure(Color color){
   if (player_board.station.count(current_city) > 0)       //check if there is a station 
    {
        if (player_board.cure.count(color) > 0)              //check if no cure found yet
        {
            return *this;
        }

        if (my_cards.size() < MIN_CARDS)                            //check if player has at least 5 cards
        {
            throw std::out_of_range{"Not enough cards! \n"};
        }

        auto itr = my_cards.begin();
        for (size_t i = 0; i < MIN_CARDS; i++)
        {
            my_cards.erase(*itr);
        }
        
        player_board.cure.insert(color);
        return *this;
    }
    throw std::out_of_range{"Station doesn't exist! \n"};
        
}

string GeneSplicer::role(){
    return "GeneSplicer";
}