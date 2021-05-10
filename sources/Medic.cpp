
#include "Medic.hpp"
using namespace std;
using namespace pandemic;

Player& Medic::drive(City dest){
    Player::drive(dest);
    Color temp = player_board.city_by_color[dest];
    if (player_board.cure.count(temp) > 0)
    {
        player_board[dest] = 0;
    }
    return *this;
}

Player& Medic::fly_direct(City dest){
    Player::fly_direct(dest);
    Color temp = player_board.city_by_color[dest];
    if (player_board.cure.count(temp) > 0)
    {
        player_board[dest] = 0;
    }
    return *this;
}

Player& Medic::fly_charter(City dest){
    Player::fly_charter(dest);
    Color temp = player_board.city_by_color[dest];
    if (player_board.cure.count(temp) > 0)
    {
        player_board[dest] = 0;
    }
    return *this;
}

Player& Medic::fly_shuttle(City dest){
    Player::fly_shuttle(dest);
    Color temp = player_board.city_by_color[dest];
    if (player_board.cure.count(temp) > 0)
    {
        player_board[dest] = 0;
    }
    return *this;
}

 Player& Medic::treat(City dest){
    if (player_board.disease_level[dest] > 0 && dest == current_city){
        player_board.disease_level[dest] = 0;
        return *this;
    }
    throw std::out_of_range{"illegal action! \n"};
}

string Medic::role(){
    return "Medic";
}