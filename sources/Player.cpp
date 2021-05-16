
#include <iostream>
#include <array>
#include "Player.hpp"
using namespace std;
using namespace pandemic;

Player& Player:: drive(City dest){
    if (current_city == dest)
    {
        throw std::out_of_range{"Can not filying to current city! \n"};
    }
    
    for (auto& i :Board::all_cities[current_city]){
        if (i == dest)
        {
            current_city = dest;
            return *this;
        }
    }
    throw std::out_of_range{"illegal action! \n"};

}

Player& Player::fly_direct(City dest){
    if (current_city == dest)
    {
        throw std::out_of_range{"Can not filying to current city! \n"};
    }
    if (my_cards.count(dest) > 0)
    {
        current_city = dest;
        my_cards.erase(dest);
        return *this;
    }
     throw std::out_of_range{"illegal action! \n"};
}

Player& Player::fly_charter(City dest){
    if (current_city == dest)
    {
        throw std::out_of_range{"Can not filying to current city! \n"};
    }
    if (my_cards.count(current_city) > 0)
    {
        my_cards.erase(current_city);
        current_city = dest;
        return *this;
    }
    throw std::out_of_range{"player doesn't has his current city's card \n"};
    
}

Player& Player::fly_shuttle(City dest){
    if (current_city == dest)
    {
        throw std::out_of_range{"Can not filying to current city! \n"};
    }
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
    if (player_board.station.count(current_city) > 0)       //check if there is a station 
    {
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
        if (count < MIN_CARDS){
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
    throw std::out_of_range{"Station doesn't exist! \n"};       
}

Player& Player::treat(City dest){
    if (player_board.disease_level[dest] > 0 && dest == current_city)
    {
        Color temp = Board::city_by_color.at(dest);
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