
#include "GeneSplicer.hpp"
using namespace std;
using namespace pandemic;

Player& GeneSplicer::discover_cure(Color color){
    if (player_board.station.count(current_city) > 0)   //check if there is a station 
    {
        if (player_board.cure.count(color) == 0 && my_cards.size() >= 5){
            for (size_t i = 0; i < 5; i++)
            {
                my_cards.erase(my_cards.begin());
            }
            player_board.cure.insert(color);
        }
        return *this;
    }
     throw std::out_of_range{"illegal action! \n"};
}

string GeneSplicer::role(){
    return "GeneSplicer";
}