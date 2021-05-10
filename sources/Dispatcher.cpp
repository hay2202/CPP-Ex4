
#include "Dispatcher.hpp"
using namespace std;
using namespace pandemic;

Player& Dispatcher::fly_direct(City dest){
    if (player_board.station.count(current_city) > 0)
    {
        current_city = dest;
        return *this;
    }
    throw std::out_of_range{"Station doesn't exist! \n"};
}

string Dispatcher::role(){
    return "Dispatcher";
}
