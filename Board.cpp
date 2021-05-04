
#include <iostream>
#include "Board.hpp"

using namespace std;
using namespace pandemic;

    bool Board::is_clean(){
        return true;
    }
    
    void Board ::remove_cures(){}

    void Board::remove_stations(){

    }

    int& Board::operator[] (City city){
        return disease_level[city];
    }

    istream& operator>> (std::istream& is, Board& x){
        return is;
    }

    ostream& pandemic::operator<< (std::ostream& os, const Board& x){
        return os << "this board" << endl;   
    }

    
