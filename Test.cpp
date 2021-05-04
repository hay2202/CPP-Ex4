/**
 * AUTHORS: Hay Asa
 * Date: 2021-02
 */

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

#include "doctest.h"
#include <string>
#include <stdexcept>
#include <algorithm>
using namespace std;



TEST_CASE("Board methods tests") {
    Board board; 
    CHECK(board.is_clean());
    board[City::Bogota] = 3;
    CHECK_FALSE(board.is_clean());
    board[City::Bogota] = 0;
    CHECK(board.is_clean());

    board[City::Lima] = 3;
    board[City::StPetersburg] = 2;
    CHECK_FALSE(board.is_clean());
    board[City::Lima] = 0;  
    CHECK_FALSE(board.is_clean()); 
}

TEST_CASE("Player methods tests") {
    Board board; 
    Dispatcher d1(board, City::Tehran);
    CHECK_NOTHROW(d1.drive(City::Baghdad));
    CHECK_NOTHROW(d1.drive(City::Cairo));
    CHECK_THROWS(d1.drive(City::Tehran));

    d1.take_card(City::Bogota).take_card(City::HoChiMinhCity);
    CHECK_NOTHROW(d1.fly_direct(City::Bogota));
    CHECK_THROWS(d1.fly_charter(City::HoChiMinhCity));
    d1.take_card(City::Bogota);
    CHECK_NOTHROW(d1.fly_charter(City::HoChiMinhCity));

    CHECK_NOTHROW(d1.build());
    CHECK_NOTHROW(d1.drive(City::Manila));
    CHECK_NOTHROW(d1.drive(City::Taipei));
    CHECK_THROWS(d1.build());
    d1.take_card(City::Taipei);
    CHECK_NOTHROW(d1.build());

    CHECK_NOTHROW(d1.fly_shuttle(City::HoChiMinhCity));
    CHECK_THROWS(d1.fly_shuttle(City::Paris));
    CHECK_THROWS(d1.treat(City::HoChiMinhCity));
    board[City::HoChiMinhCity] = 4;
    CHECK_NOTHROW(d1.treat(City::HoChiMinhCity));



}

