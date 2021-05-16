
#include "Researcher.hpp"
using namespace std;
using namespace pandemic;

 Player& Researcher::discover_cure(Color color){
    if (player_board.cure.count(color) > 0)              //check if no cure found yet
    {
        return *this;
    }

    int count=0;
    for (const auto& i : my_cards){                       //check if there is 5 cards same color 
        if (Board::city_by_color[i] == color)
        {
            count++;
        }
    }
    if (count < MIN_CARDS)
    {
        throw std::out_of_range{"Not enough cards! \n"};
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

string Researcher::role(){
    return "Researcher";
}
