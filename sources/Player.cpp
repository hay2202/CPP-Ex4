
#include <iostream>
#include "Player.hpp"
using namespace std;
using namespace pandemic;

Player& Player:: drive(City dest){
    for (auto& i :player_board.all_cities[current_city]){
        if (i == dest)
        {
            current_city = dest;
            return *this;
        }
    }
    throw std::out_of_range{"illegal action! \n"};

}

Player& Player::fly_direct(City dest){
    if (my_cards.count(dest) > 0)
    {
        current_city = dest;
        my_cards.erase(dest);
        return *this;
    }
     throw std::out_of_range{"illegal action! \n"};
}

Player& Player::fly_charter(City dest){
    if (my_cards.count(current_city) > 0)
    {
        current_city = dest;
        my_cards.erase(current_city);
        return *this;
    }
     throw std::out_of_range{"illegal action! \n"};
}

Player& Player::fly_shuttle(City dest){
    if (player_board.station.count(current_city) > 0) {     //check if there is a station 
        if (player_board.station.count(dest) > 0){
            current_city = dest;
            return *this;
        }
    }  
    throw std::out_of_range{"illegal action! \n"};
}

Player& Player::build(){
    if (my_cards.count(current_city) > 0)
    {
        if (player_board.station.count(current_city) != 1)
        {
            player_board.station.insert(current_city);
            my_cards.erase(current_city);
        }
        return *this;
    }
     throw std::out_of_range{"illegal action! \n"};
}

Player& Player::discover_cure(Color color){
    if (player_board.station.count(current_city) > 0)   //check if there is a station 
    {
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
     throw std::out_of_range{"illegal action! \n"};
}

Player& Player::treat(City dest){
    if (player_board.disease_level[dest] > 0 && dest == current_city)
    {
        Color temp = player_board.city_by_color.at(dest);
       if (player_board.cure.count(temp) > 0)
       {
           player_board.disease_level[dest] = 0;
       }
       else 
       {
            player_board.disease_level[dest]--;
       }
       return *this;
    }
    throw std::out_of_range{"illegal action! \n"};
}

string Player::role(){
    return "Player";
}

void Player::remove_cards(){
    my_cards.clear();
}

Player& Player::take_card(City city){
    if (my_cards.count(city) == 0)
    {
        my_cards.insert(city);
    }
    return *this;
}