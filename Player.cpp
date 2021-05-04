
#include <iostream>
#include "Player.hpp"
using namespace std;
using namespace pandemic;

Player& Player:: drive(City dest){
    return *this;

}
Player& Player::fly_direct(City dest){
    return *this;
}
Player& Player::fly_charter(City dest){
    return *this;
}

Player& Player::fly_shuttle(City dest){
    return *this;
}

Player& Player::build(){
    return *this;
}

Player& Player::discover_cure(Color color){
    return *this;
}

Player& Player::treat(City dest){
    return *this;
}
string Player::role(){
    return "demo";
}

void Player::remove_cards(){

}
Player& Player::take_card(City city){
    return *this;
}