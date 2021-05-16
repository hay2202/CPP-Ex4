#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

using namespace pandemic;

#include <iostream>
#include <sstream>
using namespace std;

int main(){
    Board board;
    Scientist scientist(board, City::Delhi, 3); 
    FieldDoctor fieldDoctor(board, City::London);

    board[City::Moscow] = 4; // Color::Black
    board[City::Atlanta] = 3; // Color::Blue
    board[City::Bogota] = 1; // Color::Yellow
    board[City::BuenosAires] = 1; // Color::Yellow

    cout << board << endl;

    //scientist take 4 black cards
    scientist.take_card(City::Delhi).take_card(City::Algiers).take_card(City::Istanbul).take_card(City::Cairo);
    scientist.build();  //throw delhi card and build station
    scientist.discover_cure(Color::Black);  //throw all his cards

    scientist.take_card(City::Atlanta).take_card(City::Montreal);   //take 2 blue cards
    try
    {
        scientist.discover_cure(Color::Blue);       //only 2 blue cards
    }
    catch(const std::exception& e)
    {
        cout << "ERROR!\n";
        std::cerr << e.what() << '\n';
    }
    scientist.take_card(City::Washington);
    scientist.discover_cure(Color::Blue);   //throw all his cards
    

    fieldDoctor.drive(City::Essen).drive(City::StPetersburg);   //drive to StPetersburg
    fieldDoctor.treat(City::Moscow);    //treat all disease in Moscow
    try
    {
        fieldDoctor.treat(City::Essen);     //disease doesn't exist
    }
    catch(const std::exception& e)
    {
        cout << "ERROR!\n";
        std::cerr << e.what() << '\n';
    }

    fieldDoctor.take_card(City::Madrid);
    fieldDoctor.fly_direct(City::Madrid).drive(City::SaoPaulo);     //flying to madrid and drice to SaoPaulo
    fieldDoctor.treat(City::Bogota).treat(City::BuenosAires);

    fieldDoctor.take_card(City::SaoPaulo);
    fieldDoctor.fly_charter(City::Atlanta).treat(City::Atlanta);

    cout << boolalpha;
    cout << "\nIs the board free of diseases?:   " << board.is_clean()<< endl;
    cout << endl;
    cout << board;
    

}