
#include "Dispatcher.hpp"
using namespace std;
using namespace pandemic;

Player& Dispatcher::fly_direct(City dest){
    if (current_city == dest)
    {
        throw out_of_range{"can't flying to itself!"};
    }
    
    if (player_board.station.count(current_city) > 0)
    {
        current_city = dest;
        return *this;
    }
    Player::fly_direct(dest);
    return *this;
}

string Dispatcher::role(){
    return "Dispatcher";
}
