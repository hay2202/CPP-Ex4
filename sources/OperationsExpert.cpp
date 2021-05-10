
#include "OperationsExpert.hpp"
using namespace std;
using namespace pandemic;

Player& OperationsExpert::build(){
    if (player_board.station.count(current_city) < 1)
    {
        player_board.station.insert(current_city);
    }
    return *this;
}

string OperationsExpert::role(){
    return "OperationsExpert";
}