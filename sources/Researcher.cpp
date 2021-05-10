
#include "Researcher.hpp"
using namespace std;
using namespace pandemic;

 Player& Researcher::discover_cure(Color color){
        int count=0;
        for (auto& i : my_cards){                       //check if there is 5 cards same color 
            if (player_board.city_by_color[i] == color)
            {
                count++;
            }
        }
        if (count < 5)
        {
            throw std::out_of_range{"illegal action! \n"};
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

string Researcher::role(){
    return "Researcher";
}
